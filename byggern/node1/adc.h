/**
 * @file
 * @brief ADC Interface
 */


#ifndef ADC_H_
#define ADC_H_

///////////////////////////////////////////////
// Includes
///////////////////////////////////////////////

#include <stdlib.h>
#include <avr/io.h>

///////////////////////////////////////////////
// Function declarations
///////////////////////////////////////////////

/**
 * @brief Initialize the ADC
 */
void adcInit(void);

/**
 * @brief Read the ADC value
 * 
 * @param[out] value ADC Channel value
 * @param[in] channel ADC Channel to read
 */
uint8_t readAdc(uint8_t channel);

#endif