
#include "uart.h"
FILE *uart ;
void USART_init(unsigned int ubrr) {
	
	UBRR0H = (unsigned char) (ubrr >> 8);
	UBRR0L = (unsigned char) (ubrr);
	
	/*Enable receiver and transmitter*/
	
	UCSR0B = ((1<<RXEN0) | (1 <<TXEN0));
	
	/* SET FRAME FORMAT: 8data, 2 stop bit */
	
	
	UCSR0C = ((1<<USBS0) | (3<<UCSZ00));
	
	uart = fdevopen(&USART_transmitChar, &USART_receiveChar);
	//printf("uart setup finished\n\r");
}

void USART_transmitChar(unsigned char data) {
	/* wait for empty transmit buffer */
	while ( ! ( UCSR0A & (1<<UDRE0)))
		;
		
	/* Put data in buffer, send data */
	UDR0 = data;
}

unsigned char USART_receiveChar( void ) {
	/* wait for data to be received*/
	while ( !(UCSR0A & (1<<RXC0) ) ) 
		;
	
	return UDR0;
}