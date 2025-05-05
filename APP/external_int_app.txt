/*
 * external_int_app.c
 *
 *  Created on: Apr 13, 2025
 *      Author: kerel
 */

#include "DIO_interface.h"
#include "EXI_interface.h"
#include <util/delay.h>
void toogle_();

int main()
{

	DIO_initpin(PD2,INPUT_PULLUP);
	DIO_initpin(PD3,INPUT_PULLUP);
	DIO_initpin(PB2,INPUT_PULLUP);
	DIO_initpin(PB0,OUTPUT);

	EXI_Enable(EXI_INT0,EXI_ANY_LOGICAL_CHANGE);
	EXI_Enable(EXI_INT1,EXI_FALLING_EDGE);
	EXI_Enable(EXI_INT2,EXI_FALLING_EDGE);

	EXI_SetCallBack(toogle_,EXI_INT0);
	EXI_SetCallBack(toogle_,EXI_INT1);
	EXI_SetCallBack(toogle_,EXI_INT2);

	while(1);
}

void toogle_()
{
	DIO_writepin(PB0,!DIO_readpin(PB0));
}
