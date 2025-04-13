/*
 * mep_map.h
 *
 *  Created on: Feb 8, 2025
 *      Author: kerel
 */

#ifndef MEM_MAP_H_
#define MEM_MAP_H_

#include "std_types.h"

// PORTA Registers
#define PINA    *((volatile uint8*)0x39)
#define DDRA    *((volatile uint8*)0x3A)
#define PORTA   *((volatile uint8*)0x3B)

// PORTB Registers
#define PINB    *((volatile uint8*)0x36)
#define DDRB    *((volatile uint8*)0x37)
#define PORTB   *((volatile uint8*)0x38)

// PORTC Registers
#define PINC    *((volatile uint8*)0x33)
#define DDRC    *((volatile uint8*)0x34)
#define PORTC   *((volatile uint8*)0x35)

// PORTD Registers
#define PIND    *((volatile uint8*)0x30)
#define DDRD    *((volatile uint8*)0x31)
#define PORTD   *((volatile uint8*)0x32)

// Timer/Counter 0
#define TCCR0   *((volatile uint8*)0x53)
#define TCNT0   *((volatile uint8*)0x52)
#define OCR0    *((volatile uint8*)0x5C)
#define TIMSK   *((volatile uint8*)0x59)
#define TIFR    *((volatile uint8*)0x58)

// Timer/Counter 1
#define TCCR1A  *((volatile uint8*)0x4F)
#define TCCR1B  *((volatile uint8*)0x4E)
#define TCNT1H  *((volatile uint8*)0x4D)
#define TCNT1L  *((volatile uint8*)0x4C)
#define OCR1AH  *((volatile uint8*)0x4B)
#define OCR1AL  *((volatile uint8*)0x4A)
#define OCR1BH  *((volatile uint8*)0x49)
#define OCR1BL  *((volatile uint8*)0x48)
#define ICR1H   *((volatile uint8*)0x47)
#define ICR1L   *((volatile uint8*)0x46)

// Timer/Counter 2
#define TCCR2   *((volatile uint8*)0x45)
#define TCNT2   *((volatile uint8*)0x44)
#define OCR2    *((volatile uint8*)0x43)

// Interrupts
#define SREG    *((volatile uint8*)0x5F)
#define GICR    *((volatile uint8*)0x5B)
#define GIFR    *((volatile uint8*)0x5A)
#define MCUCR   *((volatile uint8*)0x55)
#define MCUCSR  *((volatile uint8*)0x54)

// ADC
#define ADMUX   *((volatile uint8*)0x27)
#define ADCSRA  *((volatile uint8*)0x26)
#define ADCH    *((volatile uint8*)0x25)
#define ADCL    *((volatile uint8*)0x24)

// USART
#define UDR     *((volatile uint8*)0x2C)
#define UCSRA   *((volatile uint8*)0x2B)
#define UCSRB   *((volatile uint8*)0x2A)
#define UBRRL   *((volatile uint8*)0x29)
#define UBRRH   *((volatile uint8*)0x40)
#define UCSRC   *((volatile uint8*)0x40)  // Shared with UBRRH, depends on URSEL bit

// SPI
#define SPCR    *((volatile uint8*)0x2D)
#define SPSR    *((volatile uint8*)0x2E)
#define SPDR    *((volatile uint8*)0x2F)

// TWI (I2C)
#define TWBR    *((volatile uint8*)0x20)
#define TWSR    *((volatile uint8*)0x21)
#define TWAR    *((volatile uint8*)0x22)
#define TWDR    *((volatile uint8*)0x23)
#define TWCR    *((volatile uint8*)0x56)



#endif
