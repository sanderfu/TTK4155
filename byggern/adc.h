#ifndef ADC_H_
#define ADC_H_

#include <stdlib.h>
#include <avr/io.h>

void adcInit(void);
 
uint8_t readAdc(uint8_t channel);

#endif