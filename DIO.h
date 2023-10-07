
/*
 * DIO.c
 *
 *      Created on: ???/???/????
 *      Author: waleed
 */


#ifndef DIO_DIO_H_
#define DIO_DIO_H_

#include "STD_TYPE.h" /* Include the standard type definitions */
#include "BIT_MATH.h" /* Include the bit manipulation macros */

typedef u8 Dio_ChannelType; /* Define the type for Dio channel */

enum level
{
    LOW = 0U, /* Enumeration for LOW level */
    HIGH      /* Enumeration for HIGH level */
};

#define Dio_ChannelType u16    /* Redefine Dio_ChannelType as uint16_t */
#define Dio_LevelType   u16    /* Define the type for Dio level */

void Dio_Init(void); /* Function to initialize the Dio module */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level); /* Function to write to a specific Dio channel */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId); /* Function to read from a specific Dio channel */

#endif /* DIO_DIO_H_ */
