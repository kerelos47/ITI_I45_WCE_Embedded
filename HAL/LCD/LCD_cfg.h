/*
 * LCD_cfg.h
 *
 *  Created on: Feb 14, 2025
 *      Author: kerel
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_



#define FOUR_BITS_MODE 4
#define EIGHT_BITS_MODE 8

#define BITS_DATA_MODE FOUR_BITS_MODE

#if		BITS_DATA_MODE == EIGHT_BITS_MODE

#define DB7_PIN PIN7
#define DB6_PIN PIN6
#define DB5_PIN PIN5
#define DB4_PIN PIN4
#define DB3_PIN PIN3
#define DB2_PIN PIN2
#define DB1_PIN PIN1
#define DB0_PIN PIN0

#elif	BITS_DATA_MODE == FOUR_BITS_MODE

#define DB7_PIN PIN7
#define DB6_PIN PIN6
#define DB5_PIN PIN5
#define DB4_PIN PIN4

#else
#warning "LCD mode is not correct"
#endif

#define E_PIN PIN8
#define RS_PIN PIN9


#endif /* HAL_LCD_LCD_CFG_H_ */
