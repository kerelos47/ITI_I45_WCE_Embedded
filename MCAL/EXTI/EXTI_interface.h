/*
 * EXTI_interface.h
 *
 *  Created on: May 5, 2025
 *      Author: kerel
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "std_types.h"
#include "utils.h"

#define EXTI_2	2
#define EXTI_1	1
#define EXTI_0	0

#define LOW_LEVEL		0
#define ANY_CHANGE		1
#define FALLING_EDGE	2
#define RAISING_EDGE	3

/* GICR */
#define INT1    7
#define INT0    6
#define INT2    5
#define IVSEL   1
#define IVCE    0

/* GIFR */
#define INTF1   7
#define INTF0   6
#define INTF2   5

/* MCUCR */
#define SE      7
#define SM2     6
#define SM1     5
#define SM0     4
#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0

/* MCUCSR */
#define JTD     7
#define ISC2    6
/* bit 5 reserved */
#define JTRF    4
#define WDRF    3
#define BORF    2
#define EXTRF   1
#define PORF    0


void EXTI_INIT(uint8 EXTINum, uint8 EXTI_SC);
void EXTI_Enable(uint8 EXINum);
void EXTI_Disable(uint8 EXINum);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
