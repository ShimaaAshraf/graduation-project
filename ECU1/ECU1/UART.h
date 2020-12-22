/*
 * UART.h
 *
 * Created: 27/11/2020 06:23:00 م
 *  Author: Ali
 */ 


#ifndef UART_H_
#define UART_H_

#include "ATmega_Registers.h"
#include "BIT_MATH.h"


void UART_Init(void);

void UART_Tx(uint8 data);

void UART_TxString(uint8* str);

uint8 UART_Rx(void);



#endif /* UART_H_ */