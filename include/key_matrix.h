#ifndef KEY_MATRIX_H
#define KEY_MATRIX_H
/*
In setup:
    DDRD = 0x0F;    //0b00001111
    DDRB = 0x07;    //0b00000111
    PORTD = 0xF0;   //0b11110000
*/

#include<Arduino.h>
#define R1 0xFE
#define R2 0xFD
#define R3 0xFB
#define R4 0xF7
#define C1 0xE0
#define C2 0xD0
#define C3 0xB0
#define C4 0x70

int pressed_button();

int chosen_button();

#endif