/**
 * @file
 * @brief USART interface
 */

#ifndef UART_H_
#define UART_H_

///////////////////////////////////////////////
// Includes
///////////////////////////////////////////////
#include <stdio.h>
#include <avr/io.h>

///////////////////////////////////////////////
// Function declarations
///////////////////////////////////////////////

/**
 * @brief Initialize the usart interface
 * 
 * @param[in] ubrr Communication speed
 */
void USART_init(unsigned int ubrr);

/**
 * @brief Transmit a char over usart
 * 
 * @param[in] data Char to send over usart
 */
void USART_transmitChar(unsigned char data);

/**
 * @brief Receive char from usart
 * 
 * @param[out] char Character read over usart
 */
unsigned char USART_receiveChar( void );

extern FILE *uart;

#endif