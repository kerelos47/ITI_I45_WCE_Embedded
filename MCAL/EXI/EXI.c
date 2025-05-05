/*
 * EXI.c
 *
 *  Created on: Apr 12, 2025
 *      Author: kerel
 */
#include <EXI/EXI_interface.h>
#include <EXI/EXI_private.h>

#include "GI_interface.h"

static void (*ApfuncEXTINT[3])(void);

void EXI_Enable(uint8 EXINum, uint8 EdgeIntSource) {

	switch (EXINum) {
	case EXI_INT0:

		SET_BIT(GICR, INT0);
		WRITE_BIT(MCUCR, 0, GET_BIT(EdgeIntSource,0));
		WRITE_BIT(MCUCR, 1, GET_BIT(EdgeIntSource,1));
		break;
	case EXI_INT1:
		SET_BIT(GICR, INT1);
		WRITE_BIT(MCUCR, 2, GET_BIT(EdgeIntSource,0));
		WRITE_BIT(MCUCR, 3, GET_BIT(EdgeIntSource,1));
		break;
	case EXI_INT2:
		SET_BIT(GICR, INT2);
		WRITE_BIT(MCUCSR, 6, GET_BIT(EdgeIntSource,0));
		break;
	}

	General_Inrerupt_Enable();
}

void EXI_Disable(uint8 EXINum) {

	switch (EXINum) {
	case EXI_INT0:
		CLEAR_BIT(GICR, INT0);
		break;
	case EXI_INT1:
		CLEAR_BIT(GICR, INT1);
		break;
	case EXI_INT2:
		CLEAR_BIT(GICR, INT2);
		break;
	}

}

void EXI_SetCallBack(void (*pfun)(void), uint8 EXINum) {

	ApfuncEXTINT[EXINum] = pfun;

}

ISR(INT0_vect) {
	ApfuncEXTINT[EXI_INT0]();
}

ISR(INT1_vect) {
	ApfuncEXTINT[EXI_INT1]();
}

ISR(INT2_vect) {
	ApfuncEXTINT[EXI_INT2]();
}

