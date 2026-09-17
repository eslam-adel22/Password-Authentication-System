/*
 * main.c
 *
 *  Created on: Aug 31, 2026
 *      Author: tisla
 */

#include "COMMON/STD_TYPES.h"
#include "MCAL/DIO/DIO_INTERFACE.h"
#include <util/delay.h>

#include "HAL/BUZZER/BUZZER_INTERFACE.h"
#include "HAL/LED/LED_INTERFACE.h"
#include "HAL/KPD/KPD_INTERFACE.h"
#include "HAL/LCD/LCD_INTERFACE.h"

#define PASSWORD_LENGTH		4
#define MAX_ATTEMPTS      	3

int main(void)
{
    u8 KPD_Value = KPD_BtnValueNotPressed;
    u8 Real_Password[PASSWORD_LENGTH] = {'1', '2', '3', '4'};
    u8 Entered_Password[PASSWORD_LENGTH];

    u8 Index = 0;
    u8 IsCorrect = 1;
    u8 Attempts = 0;
    u8 Is_Locked = 0;

    LCD_Init();
    KPD_Init();
    LED_Init(PORTA, PIN3); // Green LED
    LED_Init(PORTA, PIN4); // Red LED
    BUZ_Init(PORTA, PIN7); // Buzzer

    u8 *ready = (u8 *) "System Ready...";
    LCD_WriteString(ready);
    _delay_ms(2000);
    LCD_SendInstruction(LCD_ClearDisplay);
    _delay_ms(2);

    u8 *string = (u8 *) "Enter Password:";
    LCD_WriteString(string);
    LCD_MoveTo(LCD_Line2, 0);

    while (1)
    {
        if (Is_Locked == 1)
        {
            BUZ_ON(PORTA, PIN7);
            LED_ON(PORTA, PIN4, LED_SOURCE);
            _delay_ms(80);

            BUZ_OFF(PORTA, PIN7);
            LED_OFF(PORTA, PIN4, LED_SOURCE);
            _delay_ms(80);

            KPD_ReadKPDValue(&KPD_Value);
            if (KPD_Value == 'C')
            {
                Is_Locked = 0;
                Attempts = 0;
                Index = 0;

                LED_OFF(PORTA, PIN4, LED_SOURCE);
                BUZ_OFF(PORTA, PIN7);

                LCD_SendInstruction(LCD_ClearDisplay);
                _delay_ms(2);
                LCD_WriteString(string);
                LCD_MoveTo(LCD_Line2, 0);
            }
        }
        else
        {
            KPD_ReadKPDValue(&KPD_Value);

            if (KPD_Value != KPD_BtnValueNotPressed)
            {
                if (KPD_Value == 'E')
                {
                    LCD_SendInstruction(LCD_ClearDisplay);
                    _delay_ms(2);

                    if (Index == PASSWORD_LENGTH)
                    {
                        IsCorrect = 1;
                        for (u8 i = 0; i < PASSWORD_LENGTH; i++)
                        {
                            if (Entered_Password[i] != Real_Password[i])
                            {
                                IsCorrect = 0;
                                break;
                            }
                        }

                        if (IsCorrect == 1)
                        {
                            LCD_WriteString((u8 *)"Correct Password");
                            LED_ON(PORTA, PIN3, LED_SOURCE); // Green LED
                            _delay_ms(2000);
                            LED_OFF(PORTA, PIN3, LED_SOURCE);

                            Attempts = 0;
                            Index = 0;
                        }
                        else
                        {
                            Attempts++;

                            if (Attempts >= MAX_ATTEMPTS)
                            {
                                Is_Locked = 1;
                                LCD_WriteString((u8 *)"System Locked!");
                                LCD_MoveTo(LCD_Line2, 0);
                                LCD_WriteString((u8 *)"Press C to Reset");
                            }
                            else
                            {
                                LCD_WriteString((u8 *)"Wrong Password!");
                                LCD_MoveTo(LCD_Line2, 0);
                                LCD_WriteString((u8 *)"Rem Attempts: ");
                                LCD_WriteCharacter('0' + (MAX_ATTEMPTS - Attempts));
                                _delay_ms(2000);
                                Index = 0;
                            }
                        }
                    }
                    else
                    {
                        LCD_WriteString((u8 *)"Incomplete Pass");
                        _delay_ms(1500);
                        Index = 0;
                    }

                    if (Is_Locked == 0)
                    {
                        LCD_SendInstruction(LCD_ClearDisplay);
                        _delay_ms(2);
                        LCD_WriteString(string);
                        LCD_MoveTo(LCD_Line2, 0);
                    }
                }
                else if (KPD_Value == 'C')
                {
                    Index = 0;
                    LCD_SendInstruction(LCD_ClearDisplay);
                    _delay_ms(2);
                    LCD_WriteString(string);
                    LCD_MoveTo(LCD_Line2, 0);
                }
                else
                {
                    if (Index < PASSWORD_LENGTH)
                    {
                        Entered_Password[Index] = KPD_Value;
                        Index++;
                        LCD_WriteCharacter('*');
                    }
                }


            }
        }
    }

    return 0;
}
