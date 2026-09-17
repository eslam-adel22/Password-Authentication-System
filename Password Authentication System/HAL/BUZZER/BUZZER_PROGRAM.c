/*
 * BUZZER_PROGRAM.c
 *
 *  Created on: Aug 28, 2026
 *      Author: tisla
 */

#include "BUZZER_INTERFACE.h"

void BUZ_Init(u8 BUZZER_PORT , u8 BUZZER_PIN)
{
	DIO_SetPinDirection(BUZZER_PORT , BUZZER_PIN , DIO_OUTPUT);
}
void BUZ_ON(u8 BUZZER_PORT , u8 BUZZER_PIN)
{
	DIO_SetPinValue(BUZZER_PORT , BUZZER_PIN , DIO_HIGH);
}
void BUZ_OFF(u8 BUZZER_PORT , u8 BUZZER_PIN)
{
	DIO_SetPinValue(BUZZER_PORT , BUZZER_PIN , DIO_LOW);
}
void BUZ_TOGGLE(u8 BUZZER_PORT , u8 BUZZER_PIN)
{
	DIO_TogglePinValue(BUZZER_PORT , BUZZER_PIN);
}
