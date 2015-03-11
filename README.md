# PCD8544

## Description

A library for the Arduino to interface with the Philips PCD8544 LCD controller/driver (commonly found on Nokia 5110 and Nokia 3310 LCDs).

## Functions

#### Initialize the LCD

```C
void lcd_init(struct lcd_pins *p)
```

| Parameter | Description |
| :--- | :--- |
| p | the pins connected to the LCD |

```
struct lcd_pins {
	uint8_t res;
	uint8_t sce;
	uint8_t dc;
	uint8_t sdin;
	uint8_t sclk;
};
```

<br>

#### Set the contrast of the LCD

```C
void lcd_contrast(uint8_t vop)
```

| Parameter | Description |
| :--- | :--- |
| vop | operation voltage |

<br>

#### Set the position of the cursor

```C
void lcd_setpos(uint8_t x, uint8_t y)
```

| Parameter | Description |
| :--- | :--- |
| x | Horizontal position (0 <= x <= 83) |
| y | Vertical position (0 <= y <= 5) |

<br>

#### Clear the LCD

```C
void lcd_clear(void)
```

<br>

#### Write a string to the LCD, starting at the current cursor position

```C
void lcd_print(const char *str)
```

| Parameter | Description |
| :--- | :--- |
| str | the string to write |

<br>

#### Write a string to the LCD, starting at the specified location

```C
void lcd_printat(const char *str, uint8_t x, uint8_t y)
```

| Parameter | Description |
| :--- | :--- |
| str | the string to write |
| x | Horizontal position (0 <= x <= 83) |
| y | Vertical position (0 <= y <= 5) |

<br>

#### Write a string to the LCD with word wrapping, starting at the specified location

```C
void lcd_printwrap(const char *str, uint8_t xpos, uint8_t ypos)
```

| Parameter | Description |
| :--- | :--- |
| str | the string to write |
| x | Horizontal position (0 <= x <= 83) |
| y | Vertical position (0 <= y <= 5) |

<br>

#### Write a string to the LCD in the style of `printf`, starting at the current cursor position

```C
void lcd_printf(const char *format, ...)
```

Read about [`printf`](http://en.cppreference.com/w/c/io/fprintf).

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

![alt text](http://i.imgur.com/5RMZ97Z.gif "PCD8544")