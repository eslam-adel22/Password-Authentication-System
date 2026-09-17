/*
 * DIO_PRIVATE.h
 *
 *  Created on: Aug 28, 2026
 *      Author: tisla
 */

#ifndef INCLUDE_MCAL_DIO_DIO_PRIVATE_H_
#define INCLUDE_MCAL_DIO_DIO_PRIVATE_H_

typedef enum{
	PORTA = 0,
	PORTB,
	PORTC,
	PORTD
}DIO_PORTS;

typedef enum{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_PINS;

typedef enum{
	DIO_INPUT = 0,
	DIO_OUTPUT
}PIN_DIRECTION;

typedef enum{
	DIO_LOW = 0,
	DIO_HIGH
}PIN_STATUS;

typedef enum{
	DIO_FLOATING = 0,
	DIO_PULLUP
}PIN_INPUT_MODE;

#endif /* INCLUDE_MCAL_DIO_DIO_PRIVATE_H_ */
