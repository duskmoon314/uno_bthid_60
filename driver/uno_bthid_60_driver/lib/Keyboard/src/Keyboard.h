/*
 * File: Keybard.h
 * Project: uno_bthid_60
 * Author: Campbell He
 * Description:
 * Abstraction of a keyboard
 * Get data_pack in bluetooth HID format
 * Based on Arduino Keypad, which can be found here found here
 *  [[Arduino Playground]](http://playground.arduino.cc/Code/Keypad)
*/

#pragma once

#include <Arduino.h>
#include "Key.h"

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#define makeKeymap(x) ((byte *)x)

#define ACTIVE_MAX 6
#define CONTROL_KEY_NUM 9

typedef struct
{
    byte rows;
    byte columns;
} KeyboardSize;

class Keyboard
{
private:
    byte *rowPins;
    byte *columnPins;
    byte *keyMap;
    byte *keyMap_FN;
    KeyboardSize size;
    unsigned long startTime;
    unsigned int debounceTime;
    unsigned int holdTime;
    bool FN;

    Key keys[ACTIVE_MAX];

    // KEY_LeftControl 0xE0
    // KEY_LeftShift 0xE1
    // KEY_LeftAlt 0xE2
    // KEY_LeftGUI 0xE3
    // KEY_RightControl 0xE4
    // KEY_RightShift 0xE5
    // KEY_RightAlt 0xE6
    // KEY_RightGUI 0xE7
    // KEY_FUN 0xFF
    Key controlKeys[CONTROL_KEY_NUM];

    byte state = 0;
    byte dataPack[12] = {
        0x0C,
        0x00,
        0xA1,
        0x01,
        0x00,
        0x00,
        KEY_NULL,
        KEY_NULL,
        KEY_NULL,
        KEY_NULL,
        KEY_NULL,
        KEY_NULL,
    };

    unsigned int *bitMap;
    unsigned long holdTimer;

    void scan_keys();
    bool update_active_list();

    void next_key_state(byte idx, bool button);
    void next_control_key_state(byte idx, bool button);
    void transition_to(byte idx, KeyState nextState);

public:
    Keyboard(byte *keymap, byte *keymap_FN, byte *row_pin, byte *col_pin, byte num_row, byte num_col);
    ~Keyboard() = default;

    void pin_mode(byte pin, byte mode) { pinMode(pin, mode); }
    void pin_write(byte pin, byte level) { digitalWrite(pin, level); }
    int pin_read(byte pin) { return digitalRead(pin); }

    byte *get_data_pack();
    bool get_keys();

    void set_state(byte key_code, bool button);
    void set_keymap(byte *keymap);
    void set_keymap_FN(byte *keymap_FN);
    void set_debounce_time(unsigned int);
    void set_hold_time(unsigned int);

    bool is_pressed(byte key_code);
    int find_key(byte key_code);
    int find_control_key(byte key_code);
};

#endif
