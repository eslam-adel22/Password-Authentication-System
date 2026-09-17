/*
 * LED_PROGRAM.c
 *
 *  Created on: Aug 28, 2026
 *      Author: tisla
 */

#include "LED_INTERFACE.h"

void LED_Init(u8 LED_PORT , u8 LED_PIN)
{
	DIO_SetPinDirection(LED_PORT , LED_PIN , DIO_OUTPUT);
}

void LED_ON(u8 LED_PORT , u8 LED_PIN , u8 LED_TYPE)
{
	if(LED_TYPE == LED_SOURCE)
	{
		DIO_SetPinValue(LED_PORT , LED_PIN , DIO_HIGH);
	}
	else if(LED_TYPE == LED_SINK)
	{
		DIO_SetPinValue(LED_PORT , LED_PIN , DIO_LOW);
	}
}

void LED_OFF(u8 LED_PORT , u8 LED_PIN , u8 LED_TYPE)
{
	if(LED_TYPE == LED_SOURCE)
	{
		DIO_SetPinValue(LED_PORT , LED_PIN , DIO_LOW);
	}
	else if(LED_TYPE == LED_SINK)
	{
		DIO_SetPinValue(LED_PORT , LED_PIN , DIO_HIGH);
	}
}

void LED_Toggle(u8 LED_PORT , u8 LED_PIN)
{
	DIO_TogglePinValue(LED_PORT , LED_PIN);
}
