/*
 * Port.h
 *
 *      Created on: ???/???/????
 *      Author: waleed
 */

#ifndef PORT_PORT_H_
#define PORT_PORT_H_


#include "STD_TYPE.h" /* Include the standard type definitions */
#include "BIT_MATH.h" /* Include the bit manipulation macros */

#define Dio_PortLevelType  u16   /* Redefine Dio_PortLevelType as uint16_t */
#define Dio_PortType       u16   /* Define the type forDio_PortType */

void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level); /* Function to write to a specific Dio Port */
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId);              /* Function to read from a specific Dio Port */


#endif /* PORT_PORT_H_ */
