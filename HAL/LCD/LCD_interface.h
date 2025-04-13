/*
 * LCD_interface.h
 *
 *  Created on: Feb 14, 2025
 *      Author: kerel
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

void LCD_write_command(uint8 command);
void LCD_write_char(uint8 data);
void LCD_write_string(const char* pcStr);
void LCD_write_num(sint32 num);
void LCD_write_f_num(float64 num, uint8 decimal_point);
void LCD_go_to(uint8 row, uint8 col);
void LCD_write_string_pos(const char* pcStr,uint8 row, uint8 col);
void LCD_init();
void LCD_clear();




#endif /* HAL_LCD_LCD_INTERFACE_H_ */
