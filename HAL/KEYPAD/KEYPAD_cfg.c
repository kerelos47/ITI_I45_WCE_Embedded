/*
 * KEYPAD_cfg.c
 *
 *  Created on: Feb 14, 2025
 *      Author: kerel
 */
#include "DIO_interface.h"
#include "KEYPAD_cfg.h"
const uint8 ROW[NUM_OF_ROWS]=
{
		ROW_1,
		ROW_2,
		ROW_3,
		ROW_4
};

const uint8 COL[NUM_OF_ROWS]=
{
		COL_1,
		COL_2,
		COL_3,
		COL_4
};

const uint8 KEYS[NUM_OF_ROWS][NUM_OF_COLS]=
{
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'*','0','#','D'}
};
