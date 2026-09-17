/*
 * LED_INTERFACE.h
 *
 *  Created on: Aug 28, 2026
 *      Author: tisla
 */

#ifndef INCLUDE_HAL_LED_LED_INTERFACE_H_
#define INCLUDE_HAL_LED_LED_INTERFACE_H_

#include "LED_PRIVATE.h"
#include "LED_CONFIG.h"

#include "../../MCAL/DIO/DIO_INTERFACE.h"


void LED_Init(u8 LED_PORT , u8 LED_PIN);
void LED_ON(u8 LED_PORT , u8 LED_PIN , u8 LED_TYPE);
void LED_OFF(u8 LED_PORT , u8 LED_PIN , u8 LED_TYPE);
void LED_Toggle(u8 LED_PORT , u8 LED_PIN);

#endif /* INCLUDE_HAL_LED_LED_INTERFACE_H_ */
