/**
 * @file
 * @brief A library for using the UART-interface on Node 2.
 */

#ifndef UART_H_
#define UART_H_
#include <stdio.h>
#include <avr/io.h>

void USART_init(unsigned int ubrr);

void USART_transmitChar(unsigned char data);

unsigned char USART_receiveChar( void );

extern FILE *uart;

#endif