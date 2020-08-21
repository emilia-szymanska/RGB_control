# RGB_control

## Used devices
* Arduino Nano
* Liquid-crystal display
* RGB LED
* Matrix of switches
* Green, blue and red LEDs

## Hardware connection
* A0 - blue RGB LED leg 
* A1 - green RGB LED leg 
* A2 - red RGB LED leg 
* PD0:7 - 1:8 matrix of switches pins
* LCD legs - as specified in _LiquidCrystal_I2C.h_
* PB0 - red LED 
* PB1 - green LED
* PB2 - blue LED

## Description

This program is responsible for managing a RGB LED using Arduino Nano. LCD displays the message given below:
```
Press the button
S4-R S8-G S12-B
```
By pressing S4 button you can set the value of red component of RGB LED, by pressing S8 - green component, S12 - blue component. When you press any of these buttons, the LCD will change its content:
```
Set value ...
S13-OK S15-NOK
```
The proper LED will be lit to indicate which component of RGB LED is being set. Set the value using switches S1 (1), S2 (2), S3 (3), S5 (4), S6 (5), S7 (6), S9 (7), S10 (8), S11 (9) and S14 (0). If you make a mistake while typing the 3-digit value, you can move the cursor back and correct the value.
Press S13 if the value is ready to be applied to RGB LED or S15 if you want to move back to the previous display content.

## Author
* **Emilia Szymańska**
