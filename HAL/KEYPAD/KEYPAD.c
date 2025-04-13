/*
 * KEYPAD.c
 *
 *  Created on: Feb 14, 2025
 *      Author: kerel
 */
#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_cfg.h"

extern const uint8 ROW[NUM_OF_ROWS];
extern const uint8 COL[NUM_OF_COLS];
extern const uint8 KEYS[NUM_OF_ROWS][NUM_OF_COLS];

void  KEYPAD_init()
{
	for(int row_index=0; row_index<NUM_OF_ROWS ; row_index++)
	{
		DIO_writepin(ROW[row_index],HIGH);

	}

}

uint8 KEYPAD_get_key()
{
	uint8 pressed_key = 0;
	for(int row_index=0; row_index<NUM_OF_ROWS ; row_index++)
	{
		DIO_writepin(ROW[row_index],LOW);
		for(int col_index=0; col_index<NUM_OF_COLS ; col_index++)
		{
			if(DIO_readpin(COL[col_index]) == 0)
			{
				pressed_key =  KEYS[row_index][col_index];
			}
		}
		DIO_writepin(ROW[row_index],HIGH);
	}

	return pressed_key;
}


