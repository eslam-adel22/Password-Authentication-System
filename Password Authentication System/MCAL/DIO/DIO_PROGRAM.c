/*
 * DIO_PROGRAM.c
 *
 *  Created on: Aug 28, 2026
 *      Author: tisla
 */


#include "DIO_INTERFACE.h"

// DDR
// PORT
// PIN

void DIO_SetPortDirection(DIO_PORTS PORT, u8 PORT_DIRECTION)
{
	switch(PORT)
	{
	case PORTA: DDRA_REG=PORT_DIRECTION; break;
	case PORTB: DDRB_REG=PORT_DIRECTION; break;
	case PORTC: DDRC_REG=PORT_DIRECTION; break;
	case PORTD: DDRD_REG=PORT_DIRECTION; break;
	default: break;
	}
}
void DIO_SetPortValue(DIO_PORTS PORT, u8 PORT_VALUE)
{
	switch(PORT)
	{
	case PORTA: PORTA_REG=PORT_VALUE; break;
	case PORTB: PORTB_REG=PORT_VALUE; break;
	case PORTC: PORTC_REG=PORT_VALUE; break;
	case PORTD: PORTD_REG=PORT_VALUE; break;
	default: break;
	}
}
void DIO_SetPinDirection(DIO_PORTS PORT , DIO_PINS PIN , PIN_DIRECTION PIN_DIRECTION)
{
	if(PIN <= PIN7)
	{
		if(PIN_DIRECTION == DIO_INPUT)
		{
			switch(PORT)
			{
			case PORTA: CLR_BIT(DDRA_REG,PIN); break;
			case PORTB: CLR_BIT(DDRB_REG,PIN); break;
			case PORTC: CLR_BIT(DDRC_REG,PIN); break;
			case PORTD: CLR_BIT(DDRD_REG,PIN); break;
			default: break;
			}
		}
		else if (PIN_DIRECTION == DIO_OUTPUT)
		{
			switch(PORT)
			{
			case PORTA: SET_BIT(DDRA_REG,PIN); break;
			case PORTB: SET_BIT(DDRB_REG,PIN); break;
			case PORTC: SET_BIT(DDRC_REG,PIN); break;
			case PORTD: SET_BIT(DDRD_REG,PIN); break;
			default: break;
			}
		}
		else
		{

		}
	}
	else
	{

	}
}

void DIO_SetPinValue(DIO_PORTS PORT , DIO_PINS PIN , PIN_STATUS PIN_VALUE)
{
	if(PIN <= PIN7)
	{
		if(PIN_VALUE == DIO_LOW)
		{
			switch(PORT)
			{
			case PORTA: CLR_BIT(PORTA_REG,PIN); break;
			case PORTB: CLR_BIT(PORTB_REG,PIN); break;
			case PORTC: CLR_BIT(PORTC_REG,PIN); break;
			case PORTD: CLR_BIT(PORTD_REG,PIN); break;
			default: break;
			}
		}
		else if (PIN_VALUE == DIO_HIGH)
		{
			switch(PORT)
			{
			case PORTA: SET_BIT(PORTA_REG,PIN); break;
			case PORTB: SET_BIT(PORTB_REG,PIN); break;
			case PORTC: SET_BIT(PORTC_REG,PIN); break;
			case PORTD: SET_BIT(PORTD_REG,PIN); break;
			default: break;
			}
		}
		else
		{
		}
	}
}

u8 DIO_ReadPortValue(DIO_PORTS PORT)
{
	u8 InputState = 0 ;
	switch(PORT)
	{
	case PORTA: InputState=PINA_REG; break;
	case PORTB: InputState=PINB_REG; break;
	case PORTC: InputState=PINC_REG; break;
	case PORTD: InputState=PIND_REG; break;
	default: break;
	}


	return InputState;
}

u8 DIO_ReadPinValue(DIO_PORTS PORT , DIO_PINS PIN)
{
	u8 InputState = 0xFF;
	if(PIN <= PIN7)
	{
		switch(PORT)
		{
		case PORTA: InputState=READ_BIT(PINA_REG,PIN); break;
		case PORTB: InputState=READ_BIT(PINB_REG,PIN); break;
		case PORTC: InputState=READ_BIT(PINC_REG,PIN); break;
		case PORTD: InputState=READ_BIT(PIND_REG,PIN); break;
		default: break;
		}
	}
	return InputState;
}

void DIO_SetPinInputMode(DIO_PORTS PORT , DIO_PINS PIN , PIN_INPUT_MODE PULLUP_STATE)
{
	DIO_SetPinValue(PORT , PIN , PULLUP_STATE);
}

void DIO_TogglePinValue(DIO_PORTS PORT , DIO_PINS PIN)
{
	switch(PORT)
	{
	case PORTA: TOGGLE_BIT(PORTA_REG,PIN); break;
	case PORTB: TOGGLE_BIT(PORTB_REG,PIN); break;
	case PORTC: TOGGLE_BIT(PORTC_REG,PIN); break;
	case PORTD: TOGGLE_BIT(PORTD_REG,PIN); break;
	default: break;
	}
}
