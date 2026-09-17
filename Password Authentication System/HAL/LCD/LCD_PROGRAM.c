/*
 * LCD_PROGRAM.c
 *
 *  Created on: Sep 9, 2026
 *      Author: tisla
 */

#include "LCD_INTERFACE.h"
#include "LCD_CONFIG.h"
#include <util/delay.h>

void LCD_Init()
{
#if LCD_Mode == LCD_8BitMode
	DIO_SetPinDirection(LCD_RSPort , LCD_RSPin , DIO_OUTPUT);
	DIO_SetPinDirection(LCD_RWPort , LCD_RWPin , DIO_OUTPUT);
	DIO_SetPinDirection(LCD_EPort , LCD_EPin , DIO_OUTPUT);
	DIO_SetPortDirection(LCD_DataPort , 0xFF);

	_delay_ms(35);
	LCD_SendInstruction(LCD_FunctionSet);
	_delay_ms(1);
	LCD_SendInstruction(LCD_DisplayOnOff);
	_delay_ms(1);
	LCD_SendInstruction(LCD_ClearDisplay);
	_delay_ms(2);
	LCD_SendInstruction(LCD_EntryMode);

#elif LCD_Mode == LCD_4BitMode

#else
#error "Invalid LCD Mode"
#endif
}

void LCD_SendInstruction(u8 Instruction)
{
#if LCD_Mode == LCD_8BitMode
	DIO_SetPinValue(LCD_RSPort , LCD_RSPin , DIO_LOW);
	DIO_SetPinValue(LCD_RWPort , LCD_RWPin , DIO_LOW);

	DIO_SetPortValue(LCD_DataPort , Instruction);

	DIO_SetPinValue(LCD_EPort , LCD_EPin , DIO_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EPort , LCD_EPin , DIO_LOW);
#elif LCD_Mode == LCD_4BitMode


#else
#error "Invalid LCD Mode"
#endif
}

void LCD_WriteCharacter(u8 Character)
{
#if LCD_Mode == LCD_8BitMode
	DIO_SetPinValue(LCD_RSPort , LCD_RSPin , DIO_HIGH);
	DIO_SetPinValue(LCD_RWPort , LCD_RWPin , DIO_LOW);

	DIO_SetPortValue(LCD_DataPort , Character);

	DIO_SetPinValue(LCD_EPort , LCD_EPin , DIO_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EPort , LCD_EPin , DIO_LOW);
#elif LCD_Mode == LCD_4BitMode

#else
#error "Invalid LCD Mode"
#endif
}

void LCD_WriteString(u8 *String)
{
	if(String != NULL)
	{
		u8 Index = 0;
		while(String[Index] != '\0')
		{
			LCD_WriteCharacter(String[Index]);
			Index++;
		}
	}
}

void LCD_WriteNumber(u32 Number)
{
	u8 NumberDigits[10] = {0};
	u8 Index = 0;
	s8 Counter  = 0;
	if(Number == 0)
	{
		LCD_WriteCharacter('0');
		return;
	}
	if(Number < 0)
	{
		LCD_WriteCharacter('-');
		Number = Number * -1;
	}
	while(Number != 0)
	{
		NumberDigits[Index] = (Number % 10) + '0';
		Number = Number / 10;
		Index++;
	}
	for(Counter = Index - 1 ; Counter >= 0 ; Counter--)
	{
		LCD_WriteCharacter(NumberDigits[Counter]);
	}

}

void LCD_MoveTo(u8 LineNo , u8 DigitNo)
{
	u8 DDRAM_ADRESS = 0;
	switch(LineNo)
	{
	case LCD_Line1: DDRAM_ADRESS = LCD_AdressLine1 + DigitNo; break;
	case LCD_Line2: DDRAM_ADRESS = LCD_AdressLine2 + DigitNo; break;
	default: return;
	}
	LCD_SendInstruction(LCD_SetDDRAMCommand | DDRAM_ADRESS);
}

void LCD_StoreSpecialCharacter(u8 *SpecialCharacter , u8 LocationNo)
{
	u8 LocationCGRAMAdress = LocationNo * 8;
	LCD_SendInstruction(LCD_SetCGRAMCommand | LocationCGRAMAdress);

	for(u8 Index = 0; Index < 8; Index++)
	{
		LCD_WriteCharacter(SpecialCharacter[Index]);
	}
	LCD_MoveTo(LCD_Line1 , 0); //LCD_SendInstruction(LCD_SetDDRAMCommand | 0x00);
}


