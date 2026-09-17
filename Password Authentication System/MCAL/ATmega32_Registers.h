/*
 * ATmega32_Registers.H
 *
 *  Created on: Aug 29, 2026
 *      Author: tisla
 */

#ifndef MCAL_DIO_ATMEGA32_REGISTERS_H_
#define MCAL_DIO_ATMEGA32_REGISTERS_H_

// we write here the address of the register

#define S_REG		(*(volatile u8 *) 0x5F)

/// A
#define PORTA_REG   (*(volatile u8 *) 0x3B)
#define DDRA_REG    (*(volatile u8 *) 0x3A)
#define PINA_REG    (*(volatile u8 *) 0x39)

/// B
#define PORTB_REG   (*(volatile u8 *) 0x38)
#define DDRB_REG    (*(volatile u8 *) 0x37)
#define PINB_REG    (*(volatile u8 *) 0x36)

/// C
#define PORTC_REG   (*(volatile u8 *) 0x35)
#define DDRC_REG    (*(volatile u8 *) 0x34)
#define PINC_REG    (*(volatile u8 *) 0x33)

/// D
#define PORTD_REG   (*(volatile u8 *) 0x32)
#define DDRD_REG    (*(volatile u8 *) 0x31)
#define PIND_REG    (*(volatile u8 *) 0x30)


#endif /* MCAL_DIO_ATMEGA32_REGISTERS_H_ */
