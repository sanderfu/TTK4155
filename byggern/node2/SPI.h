/*
 * SPI.h
 *
 * Created: 25.09.2019 09:45:23
 *  Author: sanderfu
 */ 


#ifndef SPI_H_
#define SPI_H_
#include <avr/io.h>

/**
* @brief Initialize node 2 as a SPI master.
 */
void SPI_masterInit(void);

/**
* @brief Write over SPI from master to slave.
*
* @param[in] cdata Data to write
 */
void SPI_masterWrite(char cData);

/**
* @brief Set pulse width of pwm signal.
*
* @param[in] pin Pin to set 
* @param[in] setHigh 1 to set High, 0 to set low.
 */

void SPI_setChipSelect(uint8_t pin, uint8_t setHigh );

/**
* @brief Read from slave as master.
 */
uint8_t SPI_masterRead();

#endif /* SPI_H_ */