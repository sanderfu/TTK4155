/**
 * @file
 * @brief A library for reading analog values on Node 2.
 */


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
#include <stdint.h>

/**
 * @brief Initialize ADC module
 */
void ADC_init();

/**
 * @brief Send a character over UART
 *
 * @param[out] Value between 0 and 1024 representing [0-5V].
 */
uint16_t ADC_read();
int adc_0;


#endif /* ADC_H_ */