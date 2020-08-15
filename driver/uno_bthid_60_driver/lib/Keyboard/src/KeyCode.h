/*
 * File: KeyCode.h
 * Project: uno_bthid_60
 * Author: Campbell He
 * Description:
 * bluetooth HID keyboard code
*/

#pragma once

#ifndef KEY_CODE_H_
#define KEY_CODE_H_

#define KEY_NULL 0x00

#define KEY_A 0x04
#define KEY_B 0x05
#define KEY_C 0x06
#define KEY_D 0x07
#define KEY_E 0x08
#define KEY_F 0x09
#define KEY_G 0x0A
#define KEY_H 0x0B
#define KEY_I 0x0C
#define KEY_J 0x0D
#define KEY_K 0x0E
#define KEY_L 0x0F
#define KEY_M 0x10
#define KEY_N 0x11
#define KEY_O 0x12
#define KEY_P 0x13
#define KEY_Q 0x14
#define KEY_R 0x15
#define KEY_S 0x16
#define KEY_T 0x17
#define KEY_U 0x18
#define KEY_V 0x19
#define KEY_W 0x1A
#define KEY_X 0x1B
#define KEY_Y 0x1C
#define KEY_Z 0x1D

#define KEY_1 0x1E
#define KEY_2 0x1F
#define KEY_3 0x20
#define KEY_4 0x21
#define KEY_5 0x22
#define KEY_6 0x23
#define KEY_7 0x24
#define KEY_8 0x25
#define KEY_9 0x26
#define KEY_0 0x27

#define KEY_Enter 0x28
#define KEY_Esc 0x29
#define KEY_Delete 0x2A
#define KEY_Tab 0x2B
#define KEY_Space 0x2C
#define KEY_minus 0x2D
#define KEY_add 0x2E
#define KEY_lbrack 0x2F
#define KEY_rbrack 0x30
#define KEY_backslash 0x31

#define KEY_semicolon 0x33
#define KEY_quotation 0x34
#define KEY_tilde 0x35
#define KEY_comma 0x36
#define KEY_dot 0x37
#define KEY_slash 0x38
#define KEY_CapsLock 0x39
#define KEY_F1 0x3A
#define KEY_F2 0x3B
#define KEY_F3 0x3C
#define KEY_F4 0x3D
#define KEY_F5 0x3E
#define KEY_F6 0x3F
#define KEY_F7 0x40
#define KEY_F8 0x41
#define KEY_F9 0x42
#define KEY_F10 0x43
#define KEY_F11 0x44
#define KEY_F12 0x45
#define KEY_PrintScreen 0x46
#define KEY_ScrollLock 0x47
#define KEY_Pause 0x48
#define KEY_Insert 0x49
#define KEY_Home 0x4A
#define KEY_PageUp 0x4B
#define KEY_DeleteForward 0x4C
#define KEY_End 0x4D
#define KEY_PageDown 0x4E
#define KEY_RightArrow 0x4F
#define KEY_LeftArrow 0x50
#define KEY_DownArrow 0x51
#define KEY_UpArrow 0x52
#define KEY_NumLock 0x53
// #define KEY_ 0x54
// #define KEY_ 0x55
// #define KEY_ 0x56
// #define KEY_ 0x57
// #define KEY_ 0x58
// #define KEY_ 0x59
// #define KEY_ 0x5A
// #define KEY_ 0x5B
// #define KEY_ 0x5C
// #define KEY_ 0x5D
// #define KEY_ 0x5E
// #define KEY_ 0x5F
// #define KEY_ 0x60
// #define KEY_ 0x61
// #define KEY_ 0x62
// #define KEY_ 0x63
// #define KEY_ 0x64
// #define KEY_ 0x65
// #define KEY_ 0x66
// #define KEY_ 0x67
// #define KEY_ 0x68
// #define KEY_ 0x69
// #define KEY_ 0x6A
// #define KEY_ 0x6B
// #define KEY_ 0x6C
// #define KEY_ 0x6D
// #define KEY_ 0x6E
// #define KEY_ 0x6F
// #define KEY_ 0x70
// #define KEY_ 0x71
// #define KEY_ 0x72
// #define KEY_ 0x73
// #define KEY_ 0x74
// #define KEY_ 0x75
// #define KEY_ 0x76
// #define KEY_ 0x77
// #define KEY_ 0x78
// #define KEY_ 0x79
// #define KEY_ 0x7A
// #define KEY_ 0x7B
// #define KEY_ 0x7C
// #define KEY_ 0x7D
// #define KEY_ 0x7E
#define KEY_Mute 0x7F
#define KEY_Volume_UP 0x80
#define KEY_Volume_DOWN 0x81
// #define KEY_ 0x82
// #define KEY_ 0x83
// #define KEY_ 0x84
// #define KEY_ 0x85
// #define KEY_ 0x86
// #define KEY_ 0x87
// #define KEY_ 0x88
// #define KEY_ 0x89
// #define KEY_ 0x8A
// #define KEY_ 0x8B
// #define KEY_ 0x8C
// #define KEY_ 0x8D
// #define KEY_ 0x8E
// #define KEY_ 0x8F
// #define KEY_ 0x90
// #define KEY_ 0x91
// #define KEY_ 0x92
// #define KEY_ 0x93
// #define KEY_ 0x94
// #define KEY_ 0x95
// #define KEY_ 0x96
// #define KEY_ 0x97
// #define KEY_ 0x98
// #define KEY_ 0x99
// #define KEY_ 0x9A
// #define KEY_ 0x9B
// #define KEY_ 0x9C
// #define KEY_ 0x9D
// #define KEY_ 0x9E
// #define KEY_ 0x9F
// #define KEY_ 0xA0
// #define KEY_ 0xA1
// #define KEY_ 0xA2
// #define KEY_ 0xA3
// #define KEY_ 0xA4
// #define KEY_ 0xA5
// #define KEY_ 0xA6
// #define KEY_ 0xA7
// #define KEY_ 0xA8
// #define KEY_ 0xA9
// #define KEY_ 0xAA
// #define KEY_ 0xAB
// #define KEY_ 0xAC
// #define KEY_ 0xAD
// #define KEY_ 0xAE
// #define KEY_ 0xAF
// #define KEY_ 0xB0
// #define KEY_ 0xB1
// #define KEY_ 0xB2
// #define KEY_ 0xB3
// #define KEY_ 0xB4
// #define KEY_ 0xB5
// #define KEY_ 0xB6
// #define KEY_ 0xB7
// #define KEY_ 0xB8
// #define KEY_ 0xB9
// #define KEY_ 0xBA
// #define KEY_ 0xBB
// #define KEY_ 0xBC
// #define KEY_ 0xBD
// #define KEY_ 0xBE
// #define KEY_ 0xBF
// #define KEY_ 0xC0
// #define KEY_ 0xC1
// #define KEY_ 0xC2
// #define KEY_ 0xC3
// #define KEY_ 0xC4
// #define KEY_ 0xC5
// #define KEY_ 0xC6
// #define KEY_ 0xC7
// #define KEY_ 0xC8
// #define KEY_ 0xC9
// #define KEY_ 0xCA
// #define KEY_ 0xCB
// #define KEY_ 0xCC
// #define KEY_ 0xCD
// #define KEY_ 0xCE
// #define KEY_ 0xCF
// #define KEY_ 0xD0
// #define KEY_ 0xD1
// #define KEY_ 0xD2
// #define KEY_ 0xD3
// #define KEY_ 0xD4
// #define KEY_ 0xD5
// #define KEY_ 0xD6
// #define KEY_ 0xD7
// #define KEY_ 0xD8
// #define KEY_ 0xD9
// #define KEY_ 0xDA
// #define KEY_ 0xDB
// #define KEY_ 0xDC
// #define KEY_ 0xDD
// #define KEY_ 0xDE
// #define KEY_ 0xDF
#define KEY_LeftControl 0xE0
#define KEY_LeftShift 0xE1
#define KEY_LeftAlt 0xE2
#define KEY_LeftGUI 0xE3
#define KEY_RightControl 0xE4
#define KEY_RightShift 0xE5
#define KEY_RightAlt 0xE6
#define KEY_RightGUI 0xE7
// #define KEY_ 0xE8
// #define KEY_ 0xE9
// #define KEY_ 0xEA
// #define KEY_ 0xEB
// #define KEY_ 0xEC
// #define KEY_ 0xED
// #define KEY_ 0xEE
// #define KEY_ 0xEF
// #define KEY_ 0xF0
// #define KEY_ 0xF1
// #define KEY_ 0xF2
// #define KEY_ 0xF3
// #define KEY_ 0xF4
// #define KEY_ 0xF5
// #define KEY_ 0xF6
// #define KEY_ 0xF7
// #define KEY_ 0xF8
// #define KEY_ 0xF9
// #define KEY_ 0xFA
// #define KEY_ 0xFB
// #define KEY_ 0xFC
// #define KEY_ 0xFD
// #define KEY_ 0xFE
#define KEY_FUN 0xFF

#endif