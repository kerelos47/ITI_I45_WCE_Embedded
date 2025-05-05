/*
 * GI_program.c
 *
 *  Created on: May 5, 2025
 *      Author: kerel
 */
#include "GI_interface.h"
#include "GI_register.h"

void General_Inrerupt_Enable()
{
	SET_BIT(SREG_Register,7);
}

void General_Inrerupt_Disable()
{
	SET_BIT(SREG_Register,7);
}
