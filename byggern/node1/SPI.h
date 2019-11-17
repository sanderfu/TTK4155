/**
 * @file
 * @brief SPI Interface
 */


#ifndef SPI_H_
#define SPI_H_

///////////////////////////////////////////////
// Includes
///////////////////////////////////////////////

#include <avr/io.h>

///////////////////////////////////////////////
// Function Declarations
///////////////////////////////////////////////

/**
 * @brief Initialize the SPI interface
 * 
 */
void SPI_masterInit(void);

/**
 * @brief Write to slave
 * 
 * @param[in] cData The data to write
 */
void SPI_masterWrite(char cData);

/**
 * @brief Chip Select
 * 
 * @param[in] pin The pin to set
 * @param[in] setHigh Decide if the pin should be set high or low
 */
void SPI_setChipSelect(uint8_t pin, uint8_t setHigh );

/**
 * @brief Read from slave
 * 
 * @param[out] cData The data from the slave
 */
uint8_t SPI_masterRead();

#endif /* SPI_H_ */