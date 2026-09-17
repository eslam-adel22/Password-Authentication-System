/*
 * DIO_INTERFACE.h
 *
 *  Created on: Aug 28, 2026
 *      Author: tisla
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"

#include "../ATmega32_Registers.h"

#include "../../COMMON/BIT_MATH.h"
#include "../../COMMON/DEFINITION.h"
#include "../../COMMON/STD_TYPES.h"


void DIO_SetPortDirection(DIO_PORTS PORT, u8 PORT_DIRECTION);
void DIO_SetPortValue(DIO_PORTS PORT, u8 PORT_VALUE);

void DIO_SetPinDirection(DIO_PORTS PORT , DIO_PINS PIN , PIN_DIRECTION PIN_DIRECTION);
void DIO_SetPinValue(DIO_PORTS PORT , DIO_PINS PIN , PIN_STATUS PIN_VALUE);

u8 DIO_ReadPortValue(DIO_PORTS PORT);
u8 DIO_ReadPinValue(DIO_PORTS PORT , DIO_PINS PIN);

void DIO_SetPinInputMode(DIO_PORTS PORT , DIO_PINS PIN , PIN_INPUT_MODE PULLUP_STATE);
void DIO_SetPortInputMode(DIO_PORTS PORT , PIN_INPUT_MODE PULLUP_STATE);

void DIO_TogglePinValue(DIO_PORTS PORT , DIO_PINS PIN);

#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
