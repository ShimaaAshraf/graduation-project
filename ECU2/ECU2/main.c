
#define F_CPU	8000000
#include <util/delay.h>
#include "SPI.h"
#include "LED0.h"
#include "LED1.h"

int main(void)
{
	LED0_Init();
	LED1_Init();
	SPI_Slave_Init();
    while(1)
    {
		switch(SPI_Transiver(1))
		{
			case '1':
			LED0_ON();
			break;
			
			case '2':
			LED0_OFF();
			break;
			
			case '3':
			LED1_ON();
			break;
			
			case '4':
			LED1_OFF();
			break;
		}
    }
}