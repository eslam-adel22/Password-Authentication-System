/*
 * BUZZER_INTERFACE.h
 *
 *  Created on: Aug 28, 2026
 *      Author: tisla
 */

#ifndef INCLUDE_HAL_BUZZER_BUZZER_INTERFACE_H_
#define INCLUDE_HAL_BUZZER_BUZZER_INTERFACE_H_

#include "../../COMMON/BIT_MATH.h"
#include "../../COMMON/DEFINITION.h"

#include "../../MCAL/DIO/DIO_INTERFACE.h"

void BUZ_Init(u8 BUZZER_PORT , u8 BUZZER_PIN);
void BUZ_ON(u8 BUZZER_PORT , u8 BUZZER_PIN);
void BUZ_OFF(u8 BUZZER_PORT , u8 BUZZER_PIN);
void BUZ_TOGGLE(u8 BUZZER_PORT , u8 BUZZER_PIN);

#endif /* INCLUDE_HAL_BUZZER_BUZZER_INTERFACE_H_ */
