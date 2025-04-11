/*
 * DIO.c
 *
 *  Created on: Feb 8, 2025
 *      Author: kerel
 */
#include "DIO_interface.h"
#include "DIO_private.h"

extern const DioDirection_Type config_pins[NUM_OF_PINS];

void DIO_initpin (DioPin_Type pin,DioDirection_Type direction)
{
	uint8 port = pin / 8;
	pin = pin % 8;

	switch(direction)
	{
		case INPUT_PULLUP :
			switch(port)
			{
				case PA:
					CLEAR_BIT(DDRA,pin);
					SET_BIT(PORTA,pin);
					break;
				case PB:
					CLEAR_BIT(DDRB,pin);
					SET_BIT(PORTB,pin);
					break;
				case PC:
					CLEAR_BIT(DDRC,pin);
					SET_BIT(PORTC,pin);
					break;
				case PD:
					CLEAR_BIT(DDRD,pin);
					SET_BIT(PORTD,pin);
					break;
			}
			break;
			case INPUT_FLOATING :
				switch(port)
				{
					case PA:
						CLEAR_BIT(DDRA,pin);
						CLEAR_BIT(PORTA,pin);
						break;
					case PB:
						CLEAR_BIT(DDRB,pin);
						CLEAR_BIT(PORTB,pin);
						break;
					case PC:
						CLEAR_BIT(DDRC,pin);
						CLEAR_BIT(PORTC,pin);
						break;
					case PD:
						CLEAR_BIT(DDRD,pin);
						CLEAR_BIT(PORTD,pin);
						break;
				}
				break;

				case OUTPUT :
					switch(port)
					{
						case PA:
							SET_BIT(DDRA,pin);
							CLEAR_BIT(PORTA,pin);
							break;
						case PB:
							SET_BIT(DDRB,pin);
							CLEAR_BIT(PORTB,pin);
							break;
						case PC:
							SET_BIT(DDRC,pin);
							CLEAR_BIT(PORTC,pin);
							break;
						case PD:
							SET_BIT(DDRD,pin);
							CLEAR_BIT(PORTD,pin);
							break;
					}
					break;


	}
}


void DIO_writepin (DioPin_Type pin,DioValue_Type value)
{
	uint8 port = pin / 8;
	pin = pin % 8;

	switch(value)
	{
		case LOW :
			switch(port)
			{
				case PA:
					CLEAR_BIT(PORTA,pin);
					break;
				case PB:
					CLEAR_BIT(PORTB,pin);
					break;
				case PC:
					CLEAR_BIT(PORTC,pin);
					break;
				case PD:
					CLEAR_BIT(PORTD,pin);
					break;
			}
			break;
			case HIGH :
				switch(port)
				{
					case PA:
						SET_BIT(PORTA,pin);
						break;
					case PB:
						SET_BIT(PORTB,pin);
						break;
					case PC:
						SET_BIT(PORTC,pin);
						break;
					case PD:
						SET_BIT(PORTD,pin);
						break;
				}
				break;

   }
}

void DIO_writeport (DioPort_Type port,uint8 value)
{		
	switch(port)
	{
		case PA:
			PORTA = value;
			break;
		case PB:
			PORTB = value;
			break;
		case PC:
			PORTC = value;
			break;
		case PD:
			PORTD = value;
			break;
	}
}

DioValue_Type DIO_readpin (DioPin_Type pin)
{
	uint8 port = pin / 8;
	pin = pin % 8;

	DioValue_Type pin_level=LOW;
			switch(port)
			{
				case PA:
					pin_level=GET_BIT(PINA,pin);
					break;
				case PB:
					pin_level=GET_BIT(PINB,pin);
					break;
				case PC:
					pin_level=GET_BIT(PINC,pin);
					break;
				case PD:
					pin_level=GET_BIT(PIND,pin);
					break;
			}

			return pin_level;

}

void DIO_init (void)
{
	int i=0;
	for(i=0; i<NUM_OF_PINS ; i++)
	{
		DIO_initpin(i,config_pins[i]);
	}
}
