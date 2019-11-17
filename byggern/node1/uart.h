#ifndef UART_H_
#define UART_H_
#include <stdio.h>
#include <avr/io.h>

//Initialize USART
void USART_init(unsigned int ubrr);

//Transmit a char over USART
void USART_transmitChar(unsigned char data);

//Rescieve a char over usart
unsigned char USART_receiveChar( void );

extern FILE *uart;

#endif