/*
 * KPD_PROGRAM.c
 *
 *  Created on: Sep 10, 2026
 *      Author: tisla
 */

#include "KPD_INTERFACE.h"
#include <util/delay.h>

void KPD_Init()
{
	u8 KPD_RPorts[KPD_ROWNO] = KPD_RPortConfigured;
	u8 KPD_RPins[KPD_ROWNO] = KPD_RPinConfigured;

	u8 KPD_CPorts[KPD_COLNO] = KPD_CPortConfigured;
	u8 KPD_CPins[KPD_COLNO] = KPD_CPinConfigured;

	for(u8 RIndex = 0; RIndex < KPD_ROWNO; RIndex++)
	{
		DIO_SetPinDirection(KPD_RPorts[RIndex], KPD_RPins[RIndex], DIO_INPUT);
		DIO_SetPinInputMode(KPD_RPorts[RIndex], KPD_RPins[RIndex], ENABLE);
	}
	for(u8 CIndex = 0; CIndex < KPD_COLNO; CIndex++)
	{
		DIO_SetPinDirection(KPD_CPorts[CIndex], KPD_CPins[CIndex], DIO_OUTPUT);
		DIO_SetPinValue(KPD_CPorts[CIndex], KPD_CPins[CIndex], DIO_HIGH);
	}
}

void KPD_ReadKPDValue(u8 *KPD_Value)
{
	u8 KPD_Values[KPD_ROWNO][KPD_COLNO] = KPD_ValuesConfigured;

	u8 KPD_RPorts[KPD_ROWNO] = KPD_RPortConfigured;
	u8 KPD_RPins[KPD_ROWNO] = KPD_RPinConfigured;

	u8 KPD_CPorts[KPD_COLNO] = KPD_CPortConfigured;
	u8 KPD_CPins[KPD_COLNO] = KPD_CPinConfigured;

	*KPD_Value = KPD_BtnValueNotPressed;
	u8 IsBtnPressed = KPD_BtnStateNotPressed;

	for(u8 C = 0; C < KPD_COLNO; C++)
	{
		DIO_SetPinValue(KPD_CPorts[C], KPD_CPins[C], DIO_LOW);
		for(u8 R = 0; R < KPD_ROWNO; R++)
		{
			IsBtnPressed = DIO_ReadPinValue(KPD_RPorts[R], KPD_RPins[R]);
			if(IsBtnPressed == KPD_BtnStatePressed)
			{
				_delay_ms(100);
				IsBtnPressed = DIO_ReadPinValue(KPD_RPorts[R], KPD_RPins[R]);
				if(IsBtnPressed == KPD_BtnStatePressed)
				{
					*KPD_Value = KPD_Values[R][C];
									return;
				}
			}
		}
		DIO_SetPinValue(KPD_CPorts[C], KPD_CPins[C], DIO_HIGH);
	}
}
