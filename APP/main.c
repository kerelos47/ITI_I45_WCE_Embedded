/*
 * main.c
 *
 *  Created on: Feb 8, 2025
 *      Author: kerel
 */


#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include <util/delay.h>

int main()
{
	float64 num = -123.12 ;
	_delay_ms(100);
	DIO_init();
	LCD_init();
	KEYPAD_init();
	int keypad_flag = 0;



	//LCD_write_num(KEYPAD_get_key()-'0');
	//LCD_go_to(1, 3);
	//LCD_write_f_num(num,2);
//	LCD_go_to(1, 3);
	LCD_write_f_num(num,2);

//	LCD_write_string("Hi");

	while(1)
	{


	}

/*	while(1)
	{
		//LCD_go_to(0, 0);
		if(KEYPAD_get_key()!=' ')
		{
			if(keypad_flag == 1)
			{
				LCD_write_char(KEYPAD_get_key());
			}
			keypad_flag=0;

		}
		else
		{
			keypad_flag = 1;
		}

	}

*/


}

/*
#define UP_SW PIN8
#define DOWN_SW PIN9

#define PRESSED 0

#define UP_MODE 0
#define DOWN_MODE 1

int positive_mod(int a, int b);


int main()
{
	uint8 MODE_SW_flag = 0;
	uint8 mode =  UP_MODE;

	uint8 i =0;

 	//LEDs App
	// LEDs 0:7 , UP sw 8 , Down sw 9
	DIO_init();
	while(1)
	{

		if(DIO_readpin(UP_SW)==PRESSED)
		{

			if(MODE_SW_flag == 0)
			{
				// Do something once when click
				TOGGLE_BIT(mode,0);

			}
			MODE_SW_flag = 1;

		}
		else
		{
			MODE_SW_flag = 0;
		}

		if(mode == UP_MODE)
		{

				DIO_writepin(i,1);
				DIO_writepin(positive_mod(i-1, 8),0);

				i++;
				i = positive_mod(i, 8);

		}

		if(mode == DOWN_MODE)
		{
				i--;
				i = positive_mod(i, 8);

				DIO_writepin(i,1);
				DIO_writepin(positive_mod(i+1, 8),0);

		}
		_delay_ms(250);




	}
}

int positive_mod(int a, int b) {
    return ((a % b) + b) % b;
}


//

*/





