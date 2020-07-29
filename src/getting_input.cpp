#include "getting_input.h"

int get_integer(int order, LiquidCrystal_I2C* lcd)
{
    int keys[17] = {0, 1, 2, 3, -1, 
                       4, 5, 6, -1, 
                       7, 8, 9, -1, 
                      -1, 0, -1, -1};
    int button = chosen_button();
    while(button==0 || button==4 || button==8 || button==12 || button==13 || button==15 || button==16)
    {
      if(button == 15)
      {
        set_lcd(lcd);
        return -2;
      }
      if(button == 16 && order != 0) return -3;
      button = chosen_button();
    }
    return keys[button];
}

int input_value(LiquidCrystal_I2C* lcd)
{
    int value[3] = {0, 0, 0};               
    lcd->clear();
    lcd->setCursor(0,0);
    lcd->print("Set value");
    lcd->setCursor(0,1);
    lcd->print("S13-OK S15-NOK");
    lcd->setCursor(13,0);
    lcd->cursor();
    
    
    int i = 0;
    while(i<3)
    {
      value[i] = get_integer(i, lcd);
      if(value[i] == -2) return -2;
      if(value[i] == -3)
      {
        lcd->setCursor(13+i-1,0);
        i-=2;
      }
      else
      {
        lcd->print(value[i]);
        _delay_ms(300); 
      }
      i++;
    }

    int button = chosen_button();
    while(button!=13 && button!=15)
    {
      button = chosen_button();
    }
    set_lcd(lcd);
    _delay_ms(300);
    if(button == 13) return value[0]*100+value[1]*10+value[2];
    else return -2;
  }