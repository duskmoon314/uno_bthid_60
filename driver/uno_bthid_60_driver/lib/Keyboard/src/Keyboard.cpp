#include "Keyboard.h"

Keyboard::Keyboard(byte *keymap, byte *keymap_FN, byte *row_pin, byte *col_pin, byte num_row, byte num_col)
{
    rowPins = row_pin;
    columnPins = col_pin;
    size.rows = num_row;
    size.columns = num_col;

    bitMap = new unsigned int[num_row];

    set_keymap(keymap);
    set_keymap_FN(keymap_FN);

    set_debounce_time(10);
    set_hold_time(500);

    startTime = 0;
}

void Keyboard::set_keymap(byte *keymap)
{
    keyMap = keymap;
}

void Keyboard::set_keymap_FN(byte *keymap_FN)
{
    keyMap_FN = keymap_FN;
}

bool Keyboard::get_keys()
{
    // bool keyActivity = false;

    if ((millis() - startTime) > debounceTime)
    {
        scan_keys();
        // keyActivity = update_active_list();
        update_active_list();
        startTime = millis();
    }

    // return keyActivity;
    return true;
}

void Keyboard::scan_keys()
{
    for (byte r = 0; r < size.rows; ++r)
    {
        pin_mode(rowPins[r], INPUT_PULLUP);
    }

    for (byte c = 0; c < size.columns; ++c)
    {
        pin_mode(columnPins[c], OUTPUT);
        pin_write(columnPins[c], LOW); // Pull down to scan

        for (byte r = 0; r < size.rows; ++r)
        {
            bitWrite(bitMap[r], c, !pin_read(rowPins[r]));
        }

        pin_write(columnPins[c], HIGH);
        pin_mode(columnPins[c], INPUT);
    }
}

void Keyboard::set_state(byte key_code, bool button)
{
    switch (key_code)
    {
    case KEY_LeftControl:
        bitSet(state, 0);
        controlKeys[0].update(KEY_LeftControl, IDLE, false);
        next_control_key_state(0, button);
        break;
    case KEY_LeftShift:
        bitSet(state, 1);
        controlKeys[1].update(KEY_LeftShift, IDLE, false);
        next_control_key_state(1, button);
        break;
    case KEY_LeftAlt:
        bitSet(state, 2);
        controlKeys[2].update(KEY_LeftAlt, IDLE, false);
        next_control_key_state(2, button);
        break;
    case KEY_LeftGUI:
        bitSet(state, 3);
        controlKeys[3].update(KEY_LeftGUI, IDLE, false);
        next_control_key_state(3, button);
        break;
    case KEY_RightControl:
        bitSet(state, 4);
        controlKeys[4].update(KEY_RightControl, IDLE, false);
        next_control_key_state(4, button);
        break;
    case KEY_RightShift:
        bitSet(state, 5);
        controlKeys[5].update(KEY_RightShift, IDLE, false);
        next_control_key_state(5, button);
        break;
    case KEY_RightAlt:
        bitSet(state, 6);
        controlKeys[6].update(KEY_RightAlt, IDLE, false);
        next_control_key_state(6, button);
        break;
    case KEY_RightGUI:
        bitSet(state, 7);
        controlKeys[7].update(KEY_RightGUI, IDLE, false);
        next_control_key_state(7, button);
        break;
    case KEY_FUN:
        FN = true;
        controlKeys[8].update(KEY_FUN, IDLE, false);
        next_control_key_state(8, button);
        break;

    default:
        break;
    }
}

byte *Keyboard::get_data_pack()
{
    dataPack[4] = state;
    dataPack[6] = keys[0].get_state() ? keys[0].get_code() : KEY_NULL;
    dataPack[7] = keys[0].get_state() ? keys[1].get_code() : KEY_NULL;
    dataPack[8] = keys[0].get_state() ? keys[2].get_code() : KEY_NULL;
    dataPack[9] = keys[0].get_state() ? keys[3].get_code() : KEY_NULL;
    dataPack[10] = keys[0].get_state() ? keys[4].get_code() : KEY_NULL;
    dataPack[11] = keys[0].get_state() ? keys[5].get_code() : KEY_NULL;
    return dataPack;
}

bool Keyboard::update_active_list()
{
    bool anyActivity = false;

    for (byte i = 0; i < ACTIVE_MAX; ++i)
    {
        if (keys[i].get_state() == IDLE)
        {
            keys[i].update(KEY_NULL, IDLE, false);
        }
    }

    for (byte i = 0; i < CONTROL_KEY_NUM; ++i)
    {
        if (controlKeys[i].get_state() == IDLE)
        {
            controlKeys[i].update(KEY_NULL, IDLE, false);
            if (i != 8)
            {
                bitClear(state, i);
            }
            else
            {
                FN = false;
            }
        }
    }

    for (byte r = 0; r < size.rows; ++r)
    {
        for (byte c = 0; c < size.columns; ++c)
        {
            bool button = bitRead(bitMap[r], c);
            byte keyCode = FN ? keyMap_FN[r * size.columns + c] : keyMap[r * size.columns + c];
            int idx = find_key(keyCode);
            int control_idx = find_control_key(keyCode);

            if (idx > -1)
            {
                next_key_state(idx, button);
            }
            if (control_idx > -1)
            {
                next_control_key_state(control_idx, button);
            }

            if (keyCode >= KEY_LeftControl)
            {
                if ((control_idx == -1) && button)
                {
                    set_state(keyCode, button);
                }
            }
            else
            {
                if ((idx == -1) && button)
                {
                    for (byte i = 0; i < ACTIVE_MAX; ++i)
                    {
                        if (keys[i].get_code() == KEY_NULL)
                        {
                            keys[i].update(keyCode, IDLE, false);
                            next_key_state(i, button);
                            break;
                        }
                    }
                }
            }
        }
    }

    for (byte i = 0; i < ACTIVE_MAX; ++i)
    {
        if (keys[i].get_state_changed())
            anyActivity = true;
    }

    for (byte i = 0; i < CONTROL_KEY_NUM; ++i)
    {
        if (controlKeys[i].get_state_changed())
            anyActivity = true;
    }

    return anyActivity;
}

void Keyboard::next_key_state(byte idx, bool button)
{
    keys[idx].set_state_changed(false);

    switch (keys[idx].get_state())
    {
    case IDLE:
        if (button)
        {
            transition_to(idx, PRESSED);
            holdTimer = millis();
        }
        break;
    case PRESSED:
        if ((millis() - holdTimer) > holdTime)
        {
            transition_to(idx, HOLD);
        }
        else if (!button)
        {
            transition_to(idx, RELEASED);
        }
        break;
    case HOLD:
        if (!button)
        {
            transition_to(idx, RELEASED);
        }
        break;
    case RELEASED:
        transition_to(idx, IDLE);
        break;
    }
}

void Keyboard::next_control_key_state(byte idx, bool button)
{
    controlKeys[idx].set_state_changed(false);

    switch (controlKeys[idx].get_state())
    {
    case IDLE:
        if (button)
        {
            controlKeys[idx].set_state(PRESSED);
            holdTimer = millis();
        }
        break;
    case PRESSED:
        if ((millis() - holdTimer) > holdTime)
        {
            controlKeys[idx].set_state(HOLD);
        }
        else if (!button)
        {
            controlKeys[idx].set_state(RELEASED);
        }
        break;
    case HOLD:
        if (!button)
        {
            controlKeys[idx].set_state(RELEASED);
        }
        break;
    case RELEASED:
        controlKeys[idx].set_state(IDLE);
        break;
    }
}

bool Keyboard::is_pressed(byte keyCode)
{
    for (byte i = 0; i < ACTIVE_MAX; ++i)
    {
        if (keys[i].get_code() == keyCode)
        {
            if ((keys[i].get_state() == PRESSED) && keys[i].get_state_changed())
                return true;
        }
    }
    for (byte i = 0; i < CONTROL_KEY_NUM; ++i)
    {
        if (controlKeys[i].get_code() == keyCode)
        {
            if (controlKeys[i].get_state() == PRESSED && controlKeys[i].get_state_changed())
                return true;
        }
    }

    return false;
}

int Keyboard::find_key(byte keyCode)
{
    for (byte i = 0; i < ACTIVE_MAX; ++i)
    {
        if (!keyCode)
            break;
        if (keys[i].get_code() == keyCode)
        {
            return i;
        }
    }
    return -1;
}

int Keyboard::find_control_key(byte keyCode)
{
    for (byte i = 0; i < CONTROL_KEY_NUM; ++i)
    {
        if (!keyCode)
            break;
        if (controlKeys[i].get_code() == keyCode)
        {
            return i;
        }
    }
    return -1;
}

void Keyboard::set_debounce_time(unsigned int debounce)
{
    debounce < 1 ? debounceTime = 1 : debounceTime = debounce;
}

void Keyboard::set_hold_time(unsigned int hold)
{
    holdTime = hold;
}

void Keyboard::transition_to(byte idx, KeyState next_state)
{
    keys[idx].set_state(next_state);
}