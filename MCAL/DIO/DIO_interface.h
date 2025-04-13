/*
 * DIO_interface.h
 *
 *  Created on: Feb 8, 2025
 *      Author: kerel
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
/*
*/
#include "std_types.h"
#include "utils.h"
#include "mem_map.h"

typedef enum
{
	PA=0,
	PB,
	PC,
	PD
}DioPort_Type;

///////////////////////////////
// Port A
#define PA0 PIN0
#define PA1 PIN1
#define PA2 PIN2
#define PA3 PIN3
#define PA4 PIN4
#define PA5 PIN5
#define PA6 PIN6
#define PA7 PIN7

// Port B
#define PB0 PIN8
#define PB1 PIN9
#define PB2 PIN10
#define PB3 PIN11
#define PB4 PIN12
#define PB5 PIN13
#define PB6 PIN14
#define PB7 PIN15

// Port C
#define PC0 PIN16
#define PC1 PIN17
#define PC2 PIN18
#define PC3 PIN19
#define PC4 PIN20
#define PC5 PIN21
#define PC6 PIN22
#define PC7 PIN23

// Port D
#define PD0 PIN24
#define PD1 PIN25
#define PD2 PIN26
#define PD3 PIN27
#define PD4 PIN28
#define PD5 PIN29
#define PD6 PIN30
#define PD7 PIN31
///////////////////////////////



typedef enum
{
	PIN0=0,
	PIN1	,
	PIN2	,
	PIN3	,
	PIN4	,
	PIN5	,
	PIN6	,
	PIN7	,
	PIN8	,
	PIN9	,
	PIN10	,
	PIN11	,
	PIN12	,
	PIN13	,
	PIN14	,
	PIN15	,
	PIN16	,
	PIN17	,
	PIN18	,
	PIN19	,
	PIN20	,
	PIN21	,
	PIN22	,
	PIN23	,
	PIN24	,
	PIN25	,
	PIN26	,
	PIN27	,
	PIN28	,
	PIN29	,
	PIN30	,
	PIN31	,
}DioPin_Type;

typedef enum
{
	INPUT_PULLUP=0,
	INPUT_FLOATING,
	OUTPUT
}DioDirection_Type;

typedef enum
{
	LOW=0,
	HIGH

}DioValue_Type;



extern void DIO_initpin (DioPin_Type pin,DioDirection_Type direction);
extern void DIO_writepin (DioPin_Type pin,DioValue_Type value);
extern void DIO_writeport (DioPort_Type port,uint8 value);
extern DioValue_Type DIO_readpin (DioPin_Type pin);
extern void DIO_init (void);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
