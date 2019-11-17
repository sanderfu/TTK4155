#ifndef UART_H_
#define UART_H_
#include <stdio.h>
#include <avr/io.h>

/**
 * @brief Initialize UART module.
 *
 * @param[in] ubrr Baud rate
 */
void USART_init(unsigned int ubrr);

/**
 * @brief Send a character over UART
 *
 * @param[in] data Character to send.
 */
void USART_transmitChar(unsigned char data);

/**
 * @brief Receive a character over UART.
 */
unsigned char USART_receiveChar( void );

extern FILE *uart;

#endif