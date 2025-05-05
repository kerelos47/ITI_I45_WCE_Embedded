/*
 * scheduler_test.c
 *
 *  Created on: Apr 22, 2025
 *      Author: kerel
 */


#include "DIO_interface.h"
#include "../MCAL/Timer/Timer_private.h"

#include "../MCAL/Timer/Timer_interface.h"

uint64 tick_time = 0;

uint8 yellow_led_flag = 0;

#define TASK1_OFFSET 1
#define TASK2_OFFSET 2
#define TASK3_OFFSET 3

#define TASK1_PERODICITY 1
#define TASK2_PERODICITY 2
#define TASK3_PERODICITY 3

void task1() {
	tick_time++;
//	TCNT0 = 130;

}

void green_led()
{
	CLEAR_BIT(PORTA,2);
	SET_BIT(PORTA,0);
}

void yellow_led_blink()
{
	if(yellow_led_flag == 1)
	{
		TOGGLE_BIT(PORTA,1);
	}
}

void yellow_led_on()
{

	yellow_led_flag = 1;
}

void yellow_led_off()
{
	yellow_led_flag = 0;

}


void red_led()
{
	CLEAR_BIT(PORTA,0);
	CLEAR_BIT(PORTA,1);
	SET_BIT(PORTA,2);
}

typedef struct Task_StrConfg {
	int offset;
	int perodicity;
	void (*task_ptr)();

} Task_StrConfg;

Task_StrConfg TASK_QUEUE[5] =
{
		{0,		15000,	green_led},

		{5000,	15000,	yellow_led_on},
		{10000,	15000,	yellow_led_off},
		{0,		50,		yellow_led_blink},

		{10000,	15000,	red_led}

};

void Schdualer() {
	uint8 i = 0;
	for (i = 0; i < 5; i++) {
		if (TASK_QUEUE[i].offset == 0) {
			TASK_QUEUE[i].task_ptr();
			TASK_QUEUE[i].offset = TASK_QUEUE[i].perodicity - 1;
		} else {
			TASK_QUEUE[i].offset--;
		}
	}
}

int main(void) {
	DIO_initpin(PA0, OUTPUT);
	DIO_initpin(PA1, OUTPUT);
	DIO_initpin(PA2, OUTPUT);

	OCR0 = 124;
	Timer0_Init();
	Timer0_OCM_Enable();
	Timer0_Config(Timer0_CTC, Timer_Prescaler64);
	Timer0_SetCallBack(Schdualer);

	while (1) {


	}

}
