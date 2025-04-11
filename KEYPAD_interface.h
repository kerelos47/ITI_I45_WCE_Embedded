/**
 * @file keypad.h
 * @author Belal Elgendy
 * @brief keypad header file
 * @version 0.1
 * @date 17-06-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "DIO_interface.h"

/* keypad connections */              
/* columns defined as INPULLUP in DIO_cfg.c file */
#define FIRST_INPUT PINA0
/* rows (output) */
#define FIRST_OUTPUT PINA4

/* number of rows and cols */
#define ROW 4
#define COL 4

#define NO_KEY '!'

/**
 * @brief Init Keypad OUTPUT PINS
 * 
 * @return void 
 */
extern void KEYPAD_init(void); 

/**
 * @brief get the pressed key from keypad
 * 
 * @return u8 pressed key or NO_KEY ('.') if no button pressed 
 */
extern u8 KEYPAD_getKey(void);

#endif /* KEYPAD_H_ */