/*
 * LCD_PRIVATE.h
 *
 *  Created on: Sep 9, 2026
 *      Author: tisla
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

// Set LCD Mode
#define LCD_4BitMode      	1
#define LCD_8BitMode      	2

// Clear Display
#define LCD_ClearDisplay    0x01

// Return Home
#define LCD_ReturnHome      0x02

// Entry Mode Set
#define LCD_LeftNoShift		0x04
#define LCD_LeftWithShift	0x05
#define LCD_RightNoShift	0x06
#define LCD_RightWithShift	0x07

// Display ON/OFF
#define LCD_DisplayOff		0x08
#define LCD_DisplayOn		0x0C
#define LCD_CursorOn		0x0E
#define LCD_BlinkingOn		0x0F

// Function Set

// 8-Bit
#define LCD_8Bit2Line5x11F	0x3C
#define LCD_8Bit2Line5x8F	0x38
#define LCD_8Bit1Line5x11F	0x34
#define LCD_8Bit1Line5x8F	0x30

// 4-Bit
#define LCD_4Bit2Line5x11F	0x2C
#define LCD_4Bit2Line5x8F	0x28
#define LCD_4Bit1Line5x11F	0x24
#define LCD_4Bit1Line5x8F	0x20

// Set CGRAM
#define LCD_SetCGRAMCommand 0x40

// Set DDRAM
#define LCD_SetDDRAMCommand 0x80

#define LCD_Line1  0
#define LCD_Line2  1

#define LCD_AdressLine1  0x00
#define LCD_AdressLine2  0x40

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
