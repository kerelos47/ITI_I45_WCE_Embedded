/*
 * EXTI_program.c
 *
 *  Created on: May 5, 2025
 *      Author: kerel
 */

#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "GI_interface.h"

void EXTI_INIT(uint8 EXTINum, uint8 EXTI_SC) {

	General_Inrerupt_Enable();

	switch (EXTINum) {
	case EXTI_0:
		WRITE_BIT(MCUCR_Register, 0, GET_BIT(EXTI_SC, 0));
		WRITE_BIT(MCUCR_Register, 1, GET_BIT(EXTI_SC, 1));
		break;
	case EXTI_1:
		WRITE_BIT(MCUCR_Register, 2, GET_BIT(EXTI_SC, 0));
		WRITE_BIT(MCUCR_Register, 3, GET_BIT(EXTI_SC, 1));
		break;
	case EXTI_2:
		SET_BIT(GICR_Register, INT2);
		WRITE_BIT(MCUCSR_Register, 6, GET_BIT(EXTI_SC, 0));
		break;
	}

}

void EXTI_Enable(uint8 EXINum) {



	switch (EXINum) {
	case EXTI_0:
		SET_BIT(GICR_Register, INT0);
		break;
	case EXTI_1:
		SET_BIT(GICR_Register, INT1);
		break;
	case EXTI_2:
		SET_BIT(GICR_Register, INT2);
		break;
	}

}

void EXTI_Disable(uint8 EXINum) {

	switch (EXINum) {
	case EXTI_0:
		CLEAR_BIT(GICR_Register, INT0);
		break;
	case EXTI_1:
		CLEAR_BIT(GICR_Register, INT1);
		break;
	case EXTI_2:
		CLEAR_BIT(GICR_Register, INT2);
		break;
	}

}
