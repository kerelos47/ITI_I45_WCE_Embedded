/*
 * EXTI_test.c
 *
 *  Created on: May 5, 2025
 *      Author: kerel
 */

#include "DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"


#define ISR(vector)\
	void vector (void) __attribute__ ((signal)) ; \
    void vector (void)


#define INT0_vect	__vector_1
#define INT1_vect	__vector_2
#define INT2_vect	__vector_3



//#include <util/delay.h>
void toogle_led1();
void toogle_led2();

int main() {

	DIO_initpin(PD2, INPUT_PULLUP);
	DIO_initpin(PD3, INPUT_PULLUP);
	DIO_initpin(PB0, OUTPUT);
	DIO_initpin(PB1, OUTPUT);

	EXTI_INIT(EXTI_0, ANY_CHANGE);
	EXTI_INIT(EXTI_1, ANY_CHANGE);

	EXTI_Enable(EXTI_0);
	EXTI_Enable(EXTI_1);


//	EXI_SetCallBack(toogle_,EXI_INT0);
//	EXI_SetCallBack(toogle_,EXI_INT1);
//	EXI_SetCallBack(toogle_,EXI_INT2);

	while (1)
		;
}

void toogle_led1() {
	DIO_writepin(PB0, !DIO_readpin(PB0));
}

void toogle_led2() {
	DIO_writepin(PB1, !DIO_readpin(PB1));
}

ISR(INT0_vect)
{
	toogle_led1();
}

ISR(INT1_vect)
{
	toogle_led2();

}


