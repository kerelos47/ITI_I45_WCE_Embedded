/*
 * LCD.c
 *
 *  Created on: Feb 14, 2025
 *      Author: kerel
 */
#include <util/delay.h>
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_cfg.h"
#include "LCD_private.h"
#include "utils.h"

void LCD_write_command(uint8 command) {
	DIO_writepin(RS_PIN, LOW);

#if		BITS_DATA_MODE == EIGHT_BITS_MODE
	DIO_writepin(DB7_PIN,GET_BIT(command,7));
	DIO_writepin(DB6_PIN,GET_BIT(command,6));
	DIO_writepin(DB5_PIN,GET_BIT(command,5));
	DIO_writepin(DB4_PIN,GET_BIT(command,4));
	DIO_writepin(DB3_PIN,GET_BIT(command,3));
	DIO_writepin(DB2_PIN,GET_BIT(command,2));
	DIO_writepin(DB1_PIN,GET_BIT(command,1));
	DIO_writepin(DB0_PIN,GET_BIT(command,0));
	DIO_writepin(E_PIN,HIGH);
	_delay_ms(1);
	DIO_writepin(E_PIN,LOW);
#elif	BITS_DATA_MODE == FOUR_BITS_MODE

	DIO_writepin(DB7_PIN, GET_BIT(command, 7));
	DIO_writepin(DB6_PIN, GET_BIT(command, 6));
	DIO_writepin(DB5_PIN, GET_BIT(command, 5));
	DIO_writepin(DB4_PIN, GET_BIT(command, 4));

	DIO_writepin(E_PIN, HIGH);
	_delay_ms(1);
	DIO_writepin(E_PIN, LOW);
	_delay_ms(1);

	// Handle Function Set in 4-bit Mode , refer to Data sheet
	//0b00101000
	/*
	 if(command>>4 == 0b0011)
	 {
	 DIO_writepin(DB7_PIN,GET_BIT(command,7));
	 DIO_writepin(DB6_PIN,GET_BIT(command,6));
	 DIO_writepin(DB5_PIN,GET_BIT(command,5));
	 DIO_writepin(DB4_PIN,GET_BIT(command,4));

	 DIO_writepin(E_PIN,HIGH);
	 _delay_ms(1);
	 DIO_writepin(E_PIN,LOW);
	 _delay_ms(1);
	 }
	 */

	DIO_writepin(DB7_PIN, GET_BIT(command, 3));
	DIO_writepin(DB6_PIN, GET_BIT(command, 2));
	DIO_writepin(DB5_PIN, GET_BIT(command, 1));
	DIO_writepin(DB4_PIN, GET_BIT(command, 0));

	DIO_writepin(E_PIN, HIGH);
	_delay_ms(1);
	DIO_writepin(E_PIN, LOW);
	_delay_ms(1);

#else
#warning "LCD mode is not correct"
#endif

}

void LCD_write_char(uint8 data) {
	DIO_writepin(RS_PIN, HIGH);

#if		BITS_DATA_MODE == EIGHT_BITS_MODE
	DIO_writepin(DB7_PIN,GET_BIT(data,7));
	DIO_writepin(DB6_PIN,GET_BIT(data,6));
	DIO_writepin(DB5_PIN,GET_BIT(data,5));
	DIO_writepin(DB4_PIN,GET_BIT(data,4));
	DIO_writepin(DB3_PIN,GET_BIT(data,3));
	DIO_writepin(DB2_PIN,GET_BIT(data,2));
	DIO_writepin(DB1_PIN,GET_BIT(data,1));
	DIO_writepin(DB0_PIN,GET_BIT(data,0));
	DIO_writepin(E_PIN,HIGH);
	_delay_ms(1);
	DIO_writepin(E_PIN,LOW);
#elif	BITS_DATA_MODE == FOUR_BITS_MODE
	DIO_writepin(DB7_PIN, GET_BIT(data, 7));
	DIO_writepin(DB6_PIN, GET_BIT(data, 6));
	DIO_writepin(DB5_PIN, GET_BIT(data, 5));
	DIO_writepin(DB4_PIN, GET_BIT(data, 4));

	DIO_writepin(E_PIN, HIGH);
	_delay_ms(1);
	DIO_writepin(E_PIN, LOW);
	_delay_ms(1);

	DIO_writepin(DB7_PIN, GET_BIT(data, 3));
	DIO_writepin(DB6_PIN, GET_BIT(data, 2));
	DIO_writepin(DB5_PIN, GET_BIT(data, 1));
	DIO_writepin(DB4_PIN, GET_BIT(data, 0));

	DIO_writepin(E_PIN, HIGH);
	_delay_ms(1);
	DIO_writepin(E_PIN, LOW);
	_delay_ms(1);

#else
#warning "LCD mode is not correct"
#endif

}

void LCD_write_f_num(float64 f_num, uint8 decimal_point) {
	uint8 num_digits[10] = { 0 };
	uint8 i = 0;
	uint8 num_is_neg = 0;
	sint64 num = 0;

	for (uint8 i = 0; i < decimal_point; i++) {
		f_num *= 10;
	}

	num = (sint32) f_num;

	if (num < 0) {
		num *= -1;
		num_is_neg = 1;
	}

	while (num != 0) {
		num_digits[i] = (num % 10) + '0';
		num /= 10;
		i++;

		if (i == decimal_point && decimal_point != 0) {
			num_digits[i] = '.';
			i++;
		}
	}

	if (num_is_neg == 1) {
		LCD_write_char('-');
	}

	while (i > 0) {
		i--;
		LCD_write_char(num_digits[i]);
	}

}

void LCD_write_string(const char* pcStr) {
	int i = 0;
	while (pcStr[i] != '\0') {
		LCD_write_char(pcStr[i]);
		i++;
	}
}

void LCD_write_num(sint32 num) {
	uint8 num_digits[10] = { 0 };
	uint8 i = 0;
	uint8 num_is_neg = 0;

	if (num == 0) {
		LCD_write_char('0');
	}

	if (num < 0) {
		num *= -1;
		num_is_neg = 1;
	}

	while (num != 0) {
		num_digits[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}

	if (num_is_neg == 1) {
		LCD_write_char('-');
	}

	while (i > 0) {
		i--;
		LCD_write_char(num_digits[i]);
	}

}

void LCD_go_to(uint8 row, uint8 col) {

	/*
	 * 0x00		0x0F
	 * 0x40		0x4F
	 */
	uint8 Adress = (row * 0x40 + col);

	LCD_write_command(Adress + 128); // Add 128 to set the bit 7

}

void LCD_write_string_pos(const char* pcStr, uint8 row, uint8 col) {
	LCD_go_to(row, col);
	LCD_write_string(pcStr);

}

void LCD_init() {

	_delay_ms(35);
//	LCD_write_command(0x33);
//	LCD_write_command(0x32);
//	LCD_write_command(0x28);
	/* Function Set
	 * 0 0 1 DL N F X X
	 * DL=	0: 4-bit mode		| 1: 8-bit mode
	 * N=	0: 1 line display	| 1: 2 line display
	 * F=	0: 5x7 dots font	| 1: 5x10 dots font
	 */
#if		BITS_DATA_MODE == EIGHT_BITS_MODE
	LCD_write_command(0b00111000);

#elif	BITS_DATA_MODE == FOUR_BITS_MODE

	DIO_writepin(DB7_PIN, 0);
	DIO_writepin(DB6_PIN, 0);
	DIO_writepin(DB5_PIN, 1);
	DIO_writepin(DB4_PIN, 0);

	DIO_writepin(E_PIN, HIGH);
	_delay_ms(1);
	DIO_writepin(E_PIN, LOW);
	_delay_ms(1);

	LCD_write_command(0b00101000);
#else
#warning "LCD mode is not correct"
#endif

	_delay_ms(1);

	/* Display ON/OFF Control
	 * 0 0 0 0 1 D C B
	 * D=	0: display off		| 1: display on
	 * C=	0: cursor off		| 1: cursor on
	 * F=	0: cursor blink off	| 1: cursor blink on
	 */
	LCD_write_command(0b00001100);
	_delay_ms(1);

	/* Display Clear
	 * 0x01
	 */
	LCD_write_command(0x01);
	_delay_ms(2);

	/* Entry Mode Set
	 * 0 0 0 0 0 1 I/D SH
	 * Sets the move direction of cursor and display.
	 * I/D=	0: decreases the DDR RAM Add. by 1	| 1: increases the DDR RAM Add. by 1
	 * S= 0: the display does not shift
	 */
	LCD_write_command(0b00000110);
	_delay_ms(15);

}

void LCD_clear() {
	LCD_write_command(0x01);

}
