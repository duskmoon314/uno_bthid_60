#include "Key.h"

Key::Key()
{
    kcode = KEY_NULL;
    kstate = IDLE;
    stateChanged = false;
}

Key::Key(byte code)
{
    kcode = code;
    kstate = IDLE;
    stateChanged = false;
}

byte Key::get_code()
{
    return kcode;
}

KeyState Key::get_state()
{
    return kstate;
}

bool Key::get_state_changed()
{
    return stateChanged;
}

void Key::set_code(byte code)
{
    kcode = code;
}

void Key::set_state(KeyState state)
{
    kstate = state;
    stateChanged = true;
}

void Key::set_state_changed(bool state_changed)
{
    stateChanged = state_changed;
}

void Key::update(byte code, KeyState state, bool state_changed)
{
    kcode = code;
    kstate = state;
    stateChanged = state_changed;
}