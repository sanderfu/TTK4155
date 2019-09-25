/*
 * SPI.c
 *
 * Created: 25.09.2019 09:44:52
 *  Author: sanderfu
 */ 


#include "SPI.h"

void SPI_MasterInit(void)
{
	//select slave output
	DDRB |= (1 << PB4);
	/* Set MOSI and SCK output, all others input */
	DDRB |= (1 << PB5) | (1 << PB7);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void SPI_MasterTransmit(char cData)
{
	//select slave low
	PORTB |= (0 << PB4);
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while (!(SPSR & (1<<SPIF)));
	//select slave high
	PORTB |= (1 << PB4);
}
