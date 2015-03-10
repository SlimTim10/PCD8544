#ifndef PCD8544_H
#define PCD8544_H

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

	struct lcd_pins {
		uint8_t res;
		uint8_t sce;
		uint8_t dc;
		uint8_t sdin;
		uint8_t sclk;
	};

	void lcd_contrast(uint8_t);
	void lcd_setpos(uint8_t, uint8_t);
	void lcd_clear(void);
	void lcd_print(char *);
	void lcd_printat(char *, uint8_t, uint8_t);
	void lcd_printwrap(char const *, uint8_t, uint8_t);
	void lcd_init(struct lcd_pins *);

#ifdef __cplusplus
}
#endif

#endif
