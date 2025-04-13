/*
 * EXI_private.h
 *
 *  Created on: Apr 12, 2025
 *      Author: kerel
 */

#ifndef MCAL_EXI_EXI_PRIVATE_H_
#define MCAL_EXI_EXI_PRIVATE_H_



#define cli()  __asm__ __volatile__ ("cli" ::: "memory")
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")



#define INT0_vect	__vector_1
#define INT1_vect	__vector_2
#define INT2_vect	__vector_3

#define ISR(vector)\
	void vector (void) __attribute__ ((signal)) ; \
    void vector (void)

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

#endif /* MCAL_EXI_EXI_PRIVATE_H_ */
