/*
In setup:
    DDRD = 0x0F;    //0b00001111
    DDRB = 0x07;    //0b00000111
    PORTD = 0xF0;   //0b11110000
*/

#include "key_matrix.h"

int pressed_button()
{
    PORTD = R1;
    _delay_us(10);
    switch(PIND & 0xF0)
    {
      case C1: return 1;
      case C2: return 2;
      case C3: return 3;
      case C4: return 4;           
    }
    
    PORTD = R2;
    _delay_us(10);
    switch(PIND & 0xF0)
    {
      case C1: return 5;
      case C2: return 6;
      case C3: return 7;
      case C4: return 8;           
    }
    
    PORTD = R3;
    _delay_us(10);
    switch(PIND & 0xF0)
    {
      case C1: return 9;
      case C2: return 10;
      case C3: return 11;
      case C4: return 12;           
    }

    PORTD = R4;
    _delay_us(10);
    switch(PIND & 0xF0)
    {
      case C1: return 13;
      case C2: return 14;
      case C3: return 15;
      case C4: return 16;           
    }
    return 0;
}

int chosen_button()
{
  int button = pressed_button();
  while(pressed_button() == button){}
  _delay_ms(20);
  return button;
}