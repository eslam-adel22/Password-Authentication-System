/*
 * KPD_CONFIG.h
 *
 *  Created on: Sep 10, 2026
 *      Author: tisla
 */

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

#define KPD_COLNO  4
#define KPD_ROWNO  4

#define KPD_R0PIN   PIN4
#define KPD_R0PORT  PORTD

#define KPD_R1PIN   PIN5
#define KPD_R1PORT  PORTD

#define KPD_R2PIN   PIN6
#define KPD_R2PORT  PORTD

#define KPD_R3PIN   PIN7
#define KPD_R3PORT  PORTD

#define KPD_RPortConfigured		{KPD_R0PORT, KPD_R1PORT, KPD_R2PORT, KPD_R3PORT}
#define KPD_RPinConfigured		{KPD_R0PIN, KPD_R1PIN, KPD_R2PIN, KPD_R3PIN}

#define KPD_C0PIN   PIN3
#define KPD_C0PORT  PORTD

#define KPD_C1PIN   PIN2
#define KPD_C1PORT  PORTD

#define KPD_C2PIN   PIN1
#define KPD_C2PORT  PORTD

#define KPD_C3PIN   PIN0
#define KPD_C3PORT  PORTD

#define KPD_CPortConfigured		{KPD_C0PORT, KPD_C1PORT, KPD_C2PORT, KPD_C3PORT}
#define KPD_CPinConfigured		{KPD_C0PIN, KPD_C1PIN, KPD_C2PIN, KPD_C3PIN}


#define KPD_ValuesConfigured	{	{'1','2','3','+'},\
									{'4','5','6','-'},\
									{'7','8','9','*'},\
									{'C','0','E','/'}}

#endif /* HAL_KPD_KPD_CONFIG_H_ */
