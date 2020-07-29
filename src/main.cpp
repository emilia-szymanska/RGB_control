#include<Arduino.h>
#include "getting_input.h"

LiquidCrystal_I2C lcd(PCF8574_ADDR_A21_A11_A01, 4, 5, 6, 16, 11, 12, 13, 14, POSITIVE);

#define sbi(port, pin) (port) |= _BV(pin)
#define cbi(port, pin) (port) &= ~_BV(pin)
#define tbi(port, pin) (port) ^= _BV(pin)

#define red A2
#define green A1
#define blue A0

void setup()
  {
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, 0);

    lcd.begin(16,2);
    lcd.backlight();
    set_lcd(&lcd);
    DDRD = 0x0F;    //0b00001111
    DDRB = 0x07;    //0b00000111
    PORTD = 0xF0;   //0b11110000
}

int main()
{
    init();
    setup();
    int button, input;
    while(1)
    {
      button = chosen_button();
      if(button == 4)                 //R
      {
        sbi(PORTB, 0);
        input = input_value(&lcd);
        analogWrite(red, input);
        cbi(PORTB, 0);
      }
      if(button == 8)                 //G
      {
        sbi(PORTB, 1);
        input = input_value(&lcd);
        analogWrite(green, input);
        cbi(PORTB, 1);
      }
      if(button == 12)                //B
      {
        sbi(PORTB, 2);
        input = input_value(&lcd);
        analogWrite(blue, input);
        cbi(PORTB, 2);
      }            
    }
}
