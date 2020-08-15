/*
 * File: Key.h
 * Project: uno_bthid_60
 * Author: Campbell He
 * Description:
 * Abstraction of a keyboard key
 * Based on Arduino Keypad, which can be found here found here
 *  [[Arduino Playground]](http://playground.arduino.cc/Code/Keypad)
*/

#pragma once

#ifndef KEY_H_
#define KEY_H_

#include <Arduino.h>
#include "KeyCode.h"

typedef enum
{
    IDLE,
    PRESSED,
    HOLD,
    RELEASED
} KeyState;

class Key
{
private:
    byte kcode; // 0x00 - 0xFF HID code
    KeyState kstate;
    bool stateChanged;

public:
    Key();
    Key(byte code);
    ~Key() = default;
    byte get_code();
    KeyState get_state();
    bool get_state_changed();
    void set_code(byte code);
    void set_state(KeyState state);
    void set_state_changed(bool state_changed);
    void update(byte code, KeyState state, bool state_changed);
};

#endif