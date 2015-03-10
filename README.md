# PCD8544

## Description

A library for the Arduino to interface with the Philips PCD8544 LCD controller/driver (commonly found on Nokia 5110 and Nokia 3310 LCDs).

![alt text](http://i.imgur.com/5RMZ97Z.gif "PCD8544")

## Functions

TODO

## Example

```C
#include "PCD8544.h"
#include "font.h"

struct lcd_pins lcd;

void setup() {
	/* Set the pins connecting to the LCD */
	lcd.res = 6;
	lcd.sce = 7;
	lcd.dc = 5;
	lcd.sdin = 4;
	lcd.sclk = 8;

	lcd_init(&lcd);				/* Initialize the LCD with the pins */
	lcd_contrast(0x24);			/* Set the contrast */
}

void loop() {
	lcd_clear();
	lcd_print("Welcome to Icewire Makerspace!");
	delay(1000);
	lcd_clear();
	lcd_printat("Welcome to Icewire Makerspace!", 0, 1);
	delay(1000);
	lcd_clear();
	lcd_printwrap("Welcome to Icewire Makerspace!", 0, 2);
	delay(1000);
}
```