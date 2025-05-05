/*
 * EXTI_register.h
 *
 *  Created on: May 5, 2025
 *      Author: kerel
 */

#ifndef MCAL_EXTI_EXTI_REGISTER_H_
#define MCAL_EXTI_EXTI_REGISTER_H_


#define GICR_Register    *((volatile uint8*)0x5B)
#define GIFR_Register    *((volatile uint8*)0x5A)
#define MCUCR_Register   *((volatile uint8*)0x55)
#define MCUCSR_Register  *((volatile uint8*)0x54)


#endif /* MCAL_EXTI_EXTI_REGISTER_H_ */
