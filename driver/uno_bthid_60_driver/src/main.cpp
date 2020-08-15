#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Keyboard.h>

byte rows[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
const int rowCount = 9;

byte cols[] = {9, 10, 11, 12, 13, A0, A1, A2};
const int colCount = 8;

byte KeyMatrix_0[9][8] = {
    {KEY_Esc, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7},
    {KEY_Tab, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U},
    {KEY_CapsLock, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J},
    {KEY_LeftShift, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M},
    {KEY_LeftControl, KEY_LeftGUI, KEY_LeftAlt, KEY_Space, KEY_RightAlt, KEY_RightGUI, KEY_FUN, KEY_RightControl},
    {KEY_8, KEY_9, KEY_0, KEY_minus, KEY_add, KEY_Delete, KEY_NULL, KEY_NULL},
    {KEY_I, KEY_O, KEY_P, KEY_lbrack, KEY_rbrack, KEY_backslash, KEY_NULL, KEY_NULL},
    {KEY_K, KEY_L, KEY_semicolon, KEY_quotation, KEY_Enter, KEY_NULL, KEY_NULL, KEY_NULL},
    {KEY_comma, KEY_dot, KEY_slash, KEY_RightShift, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL}};

byte KeyMatrix_1[9][8] = {
    {KEY_tilde, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7},
    {KEY_NULL, KEY_NULL, KEY_UpArrow, KEY_Mute, KEY_Volume_DOWN, KEY_Volume_UP, KEY_NULL, KEY_NULL},
    {KEY_NULL, KEY_LeftArrow, KEY_DownArrow, KEY_RightArrow, KEY_NULL, KEY_NULL, KEY_NULL, KEY_LeftArrow},
    {KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL},
    {KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_FUN, KEY_NULL},
    {KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, KEY_DeleteForward, KEY_NULL, KEY_NULL},
    {KEY_UpArrow, KEY_NULL, KEY_PrintScreen, KEY_Home, KEY_End, KEY_NULL, KEY_NULL, KEY_NULL},
    {KEY_DownArrow, KEY_RightArrow, KEY_PageUp, KEY_PageDown, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL},
    {KEY_NULL, KEY_Insert, KEY_DeleteForward, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL}};

SoftwareSerial bthid(A3, A4);
Keyboard board(makeKeymap(KeyMatrix_0), makeKeymap(KeyMatrix_1), rows, cols, 9, 8);

void setup()
{
  // Use Serial to debug
  // Serial.begin(9600);
  bthid.begin(9600);
}

void loop()
{
  if (board.get_keys())
  {
    bthid.write(board.get_data_pack(), 12);
  }
}
