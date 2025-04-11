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
