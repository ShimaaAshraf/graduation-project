/*
 * UART.c
 *
 * Created: 27/11/2020 06:23:16 م
 *  Author: Ali
 */ 

#include "UART.h"
#include "DIO.h"


#define FREQ    80000
#define Desired_BR  96


void UART_Init(void)
{
	uint32 BR_Value = 0;
	
	DIO_SetPinDir(DIO_PORTD , DIO_PIN1 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTD , DIO_PIN0 , DIO_PIN_INPUT);
	
	BR_Value = ((FREQ) / (16 * Desired_BR)) - 1;
	
	UBRRL = BR_Value ;
	
	SET_BIT(UCSRB , 3);
	SET_BIT(UCSRB , 4);
	
	UCSRC = 0x86;
	
}

void UART_Tx(uint8 data)
{
	UDR = data;
	
	while(GET_BIT(UCSRA , 5) == 0);
	
}

void UART_TxString(uint8* str)
{
	uint8 i = 0;
	
	while(str[i] != '\0')
	{
		UART_Tx(str[i]);
		i++;
	}
}

uint8 UART_Rx(void)
{
	
	while(GET_BIT(UCSRA , 7) == 0);
	
	return UDR;
}
