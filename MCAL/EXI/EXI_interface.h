/*
 * EXI_interface.h
 *
 *  Created on: Apr 12, 2025
 *      Author: kerel
 */

#ifndef MCAL_EXI_EXI_INTERFACE_H_
#define MCAL_EXI_EXI_INTERFACE_H_
/*
 */
#include "std_types.h"
#include "utils.h"
#include "mem_map.h"



#define EXI_INT0	0
#define EXI_INT1	1
#define EXI_INT2	2

#define EXI_LOW_LEVEL			0
#define EXI_ANY_LOGICAL_CHANGE	1
#define EXI_FALLING_EDGE		2
#define EXI_RAISING_EDGE		3

void EXI_Enable(uint8 EXINum, uint8 EdgeIntSource);

void EXI_Disable(uint8 EXINum);

void EXI_SetCallBack(void (*pfun)(void), uint8 EXINum);

#endif /* MCAL_EXI_EXI_INTERFACE_H_ */
