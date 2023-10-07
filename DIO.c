
/*
 * DIO.c
 *
 *      Created on: ???/???/????
 *      Author: waleed
 */

#include "Dio_MemMap.h" /* Include the memory map for DIO */
#include "DIO.h" /* Include the DIO header file */

void Dio_Init(void)
{
    SYSCTL_RCGCGPIO_R |= 0x20U;          /* Enable Clock on PORTF */
    GPIO_PORTF_LOCK_R = 0x4C4F434BU;     /* Unlock the register to enable accessing */
    GPIO_PORTF_CR_R = 0xFFU;             /* Enable write access to the commit register */
    GPIO_PORTF_DEN_R = 0xFFU;            /* Enable digital functionality for all pins */
    GPIO_PORTF_DIR_R = 0xFFU;            /* Set all pins as outputs */
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    u8 Port = (u8)(ChannelId / 8U);            /* Calculate the port number */
    u8 pin = (u8)(ChannelId % 8U);             /* Calculate the pin number */

    switch (Port)
    {
        case 0U:
            INSERT_BIT(GPIO_PORTA_DATA_R, pin, Level); /* Write the level to the specified pin in Port A */
            break;
        case 1U:
            INSERT_BIT(GPIO_PORTB_DATA_R, pin, Level); /* Write the level to the specified pin in Port B */
            break;
        case 2U:
            INSERT_BIT(GPIO_PORTC_DATA_R, pin, Level); /* Write the level to the specified pin in Port C */
            break;
        case 3U:
            INSERT_BIT(GPIO_PORTD_DATA_R, pin, Level); /* Write the level to the specified pin in Port D */
            break;
        case 4U:
            INSERT_BIT(GPIO_PORTE_DATA_R, pin, Level); /* Write the level to the specified pin in Port E */
            break;
        case 5U:
            INSERT_BIT(GPIO_PORTF_DATA_R, pin, Level); /* Write the level to the specified pin in Port F */
            break;
        default:
            /* Handle error or provide appropriate default behavior */
            break;
    }
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    u8 Port = (u8)(ChannelId / 8U);            /* Calculate the port number */
    u8 pin =  (u8)(ChannelId % 8U);             /* Calculate the pin number */
    u8 Level = 0U;

    switch (Port)
    {
        case 0U:
            Level = GET_BIT(GPIO_PORTA_DATA_R, pin); /* Read the level of the specified pin in Port A */
            break;
        case 1U:
            Level = GET_BIT(GPIO_PORTB_DATA_R, pin); /* Read the level of the specified pin in Port B */
            break;
        case 2U:
            Level = GET_BIT(GPIO_PORTC_DATA_R, pin); /* Read the level of the specified pin in Port C */
            break;
        case 3U:
            Level = GET_BIT(GPIO_PORTD_DATA_R, pin); /* Read the level of the specified pin in Port D */
            break;
        case 4U:
            Level = GET_BIT(GPIO_PORTE_DATA_R, pin); /* Read the level of the specified pin in Port E */
            break;
        case 5U:
            Level = GET_BIT(GPIO_PORTF_DATA_R, pin); /* Read the level of the specified pin in Port F */
            break;
        default:
            /* Handle error or provide appropriate default behavior */
            break;
    }

    return Level;
}



