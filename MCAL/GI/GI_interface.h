/*
 * GI_interface.h
 *
 *  Created on: May 5, 2025
 *      Author: kerel
 */

#ifndef MCAL_GI_GI_INTERFACE_H_
#define MCAL_GI_GI_INTERFACE_H_

#include "std_types.h"
#include "utils.h"


#define cli()  __asm__ __volatile__ ("cli" ::: "memory")
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")



#endif /* MCAL_GI_GI_INTERFACE_H_ */
