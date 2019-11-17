/**
 * @file
 * @brief A library for reading analog values on Node 2.
 */


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
#include <stdint.h>

void ADC_init();

uint16_t ADC_read();
int adc_0;


#endif /* ADC_H_ */