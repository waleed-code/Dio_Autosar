/*
 * Port.c
 *
 *      Created on: ???/???/????
 *      Author: waleed
 */

#include "Dio_MemMap.h" /* Include the memory map for DIO */
#include "Port.h" /* Include the Port header file */

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    switch (PortId)
    {
        case 0:
            GPIO_PORTA_DATA_R = Level; /* Write the level to Port A */
            break;
        case 1:
            GPIO_PORTB_DATA_R = Level; /* Write the level to Port B */
            break;
        case 2:
            GPIO_PORTC_DATA_R = Level; /* Write the level to Port C */
            break;
        case 3:
            GPIO_PORTD_DATA_R = Level; /* Write the level to Port D */
            break;
        case 4:
            GPIO_PORTE_DATA_R = Level; /* Write the level to Port E */
            break;
        case 5:
            GPIO_PORTF_DATA_R = Level; /* Write the level to Port F */
            break;
        default:
            /* Handle error or provide appropriate default behavior */
            break;
    }
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    u8 Level = 0;
    switch (PortId)
    {
        case 0:
            Level = GPIO_PORTA_DATA_R; /* Read the level from Port A */
            break;
        case 1:
            Level = GPIO_PORTB_DATA_R; /* Read the level from Port B */
            break;
        case 2:
            Level = GPIO_PORTC_DATA_R; /* Read the level from Port C */
            break;
        case 3:
            Level = GPIO_PORTD_DATA_R; /* Read the level from Port D */
            break;
        case 4:
            Level = GPIO_PORTE_DATA_R; /* Read the level from Port E */
            break;
        case 5:
            Level = GPIO_PORTF_DATA_R; /* Read the level from Port F */
            break;
        default:
            /* Handle error or provide appropriate default behavior */
            break;
    }
    return Level;
}
