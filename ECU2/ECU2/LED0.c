#include "LED0.h"

void LED0_Init()
{
	DIO_SetPinDir(DIO_PORTC, DIO_PIN2, DIO_PIN_OUTPUT);
}

void LED0_ON()
{
	DIO_SetPinVal(DIO_PORTC, DIO_PIN2, DIO_PIN_HIGH);
}

void LED0_OFF()
{
	DIO_SetPinVal(DIO_PORTC, DIO_PIN2, DIO_PIN_LOW);
}

void LED0_TOGGLE()
{
	DIO_TogglePin(DIO_PORTC, DIO_PIN2);
}
