/*
 * EXTI_test.c
 *
 *  Created on: May 5, 2025
 *      Author: kerel
 */

#include "DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
//#include <util/delay.h>
void toogle_();

int main() {

	DIO_initpin(PD2, INPUT_PULLUP);
	DIO_initpin(PD3, INPUT_PULLUP);
	DIO_initpin(PB2, INPUT_PULLUP);
	DIO_initpin(PB0, OUTPUT);

	EXTI_INIT(EXTI_0, ANY_CHANGE);
	EXTI_INIT(EXTI_1, FALLING_EDGE);
	EXTI_INIT(EXTI_2, FALLING_EDGE);

	EXTI_Enable(EXTI_0);
	EXTI_Enable(EXTI_1);
	EXTI_Enable(EXTI_2);

//	EXI_SetCallBack(toogle_,EXI_INT0);
//	EXI_SetCallBack(toogle_,EXI_INT1);
//	EXI_SetCallBack(toogle_,EXI_INT2);

	while (1)
		;
}

void toogle_() {
	DIO_writepin(PB0, !DIO_readpin(PB0));
}
