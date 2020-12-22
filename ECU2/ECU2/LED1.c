#include "LED1.h"

void LED1_Init()
{
	DIO_SetPinDir(DIO_PORTC, DIO_PIN7, DIO_PIN_OUTPUT);
}

void LED1_ON()
{
	DIO_SetPinVal(DIO_PORTC, DIO_PIN7, DIO_PIN_HIGH);
}

void LED1_OFF()
{
	DIO_SetPinVal(DIO_PORTC, DIO_PIN7, DIO_PIN_LOW);
}

void LED1_TOGGLE()
{
	DIO_TogglePin(DIO_PORTC, DIO_PIN7);
}
