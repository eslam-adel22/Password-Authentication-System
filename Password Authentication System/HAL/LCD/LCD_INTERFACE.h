/*
 * LCD_INTERFACE.h
 *
 *  Created on: Sep 9, 2026
 *      Author: tisla
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "LCD_PRIVATE.h"
#include "LCD_CONFIG.h"

void LCD_Init();
void LCD_SendInstruction(u8 Instruction);
void LCD_WriteCharacter(u8 Character);
void LCD_WriteString(u8 *String);
void LCD_WriteNumber(u32 Number);
void LCD_MoveTo(u8 LineNo , u8 DigitNo);
void LCD_StoreSpecialCharacter(u8 *SpecialCharacter , u8 LocationNo);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
