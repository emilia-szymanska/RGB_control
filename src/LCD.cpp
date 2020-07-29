#include "LCD.h"

void set_lcd(LiquidCrystal_I2C* lcd)
{
    lcd->clear();
    lcd->setCursor(0,0);
    lcd->print("Press the button");
    lcd->setCursor(0,1);
    lcd->print("S4-R S8-G S12-B");  
    lcd->noCursor();
}