/*
 * LCD_CONFIG.h
 *
 *  Created on: Sep 9, 2026
 *      Author: tisla
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
#include "../../MCAL/DIO/DIO_INTERFACE.h"

#define LCD_Mode 			LCD_8BitMode
#define LCD_EntryMode		LCD_RightNoShift
#define LCD_DisplayOnOff	LCD_BlinkingOn
#define LCD_FunctionSet		LCD_8Bit2Line5x8F


#define LCD_RSPin		PIN0
#define LCD_RSPort		PORTA

#define LCD_RWPin		PIN1
#define LCD_RWPort		PORTA

#define LCD_EPin		PIN2
#define LCD_EPort		PORTA


#if LCD_Mode == LCD_8BitMode
	#define LCD_DataPort	PORTC
#elif LCD_Mode == LCD_4BitMode
	#define LCD_D4Pin		PIN4
	#define LCD_D4Port		PORTC
	#define LCD_D5Pin		PIN5
	#define LCD_D5Port		PORTC
	#define LCD_D6Pin		PIN6
	#define LCD_D6Port		PORTC
	#define LCD_D7Pin		PIN7
	#define LCD_D7Port		PORTC
#else
#error "Invalid LCD Mode"
#endif


#endif /* HAL_LCD_LCD_CONFIG_H_ */
