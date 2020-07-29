#ifndef GETTING_INPUT_H
#define GETTING_INPUT_H
#include "key_matrix.h"
#include "LCD.h"

int get_integer(int order, LiquidCrystal_I2C* lcd);

int input_value(LiquidCrystal_I2C* lcd);
#endif