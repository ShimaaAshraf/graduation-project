/*
 * SPI.c
 *
 * Created: 28/11/2020 08:21:24 م
 *  Author: Ali
 */ 

#include "SPI.h"



void SPI_Master_Init(void)
{
	DIO_SetPinDir(DIO_PORTB , DIO_PIN4 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTB , DIO_PIN5 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTB , DIO_PIN6 , DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTB , DIO_PIN7 , DIO_PIN_OUTPUT);
	
	SPI->SPCR = 0x53 ;
	
}

void SPI_Slave_Init(void)
{
	DIO_SetPinDir(DIO_PORTB , DIO_PIN4 , DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTB , DIO_PIN5 , DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTB , DIO_PIN6 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTB , DIO_PIN7 , DIO_PIN_INPUT);
	
	SPI->SPCR = 0x40 ;
}

void SPI_Master_Init_Trans(void)
{
	DIO_SetPinVal(DIO_PORTB , DIO_PIN4 , DIO_PIN_LOW);
}

void SPI_Master_Ter_Trans(void)
{
	DIO_SetPinVal(DIO_PORTB , DIO_PIN4 , DIO_PIN_HIGH);
}

uint8 SPI_Transiver(uint8 data)
{
	uint8 rec_data = 0;
	
	SPI->SPDR = data;
	
	while(GET_BIT(SPI->SPSR , 7) == 0);
	
	rec_data = SPI->SPDR ;
	
	return rec_data;
}