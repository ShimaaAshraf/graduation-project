
#define F_CPU	8000000
#include <util/delay.h>
#include "UART.h"
#include "SPI.h"

int main(void)
{
	UART_Init();
	SPI_Master_Init();
	SPI_Master_Init_Trans();
	_delay_ms(1000);
    while(1)
    {
		SPI_Transiver(UART_Rx());
    }
}