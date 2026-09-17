/*
 * KPD_INTERFACE.h
 *
 *  Created on: Sep 10, 2026
 *      Author: tisla
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

#include "KPD_PRIVATE.h"
#include "KPD_CONFIG.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"


void KPD_Init();
void KPD_ReadKPDValue(u8 *KPD_Value);

#endif /* HAL_KPD_KPD_INTERFACE_H_ */
