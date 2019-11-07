/*
 * encoder.h
 *
 * Created: 01.11.2019 13:42:36
 *  Author: sanderfu
 */ 


#ifndef ENCODER_H_
#define ENCODER_H_

#include <avr/io.h>
volatile int16_t encoder_value;
volatile int16_t converted_encoderValue;
void encoder_readValues();
void encoder_init();

volatile int encoder_maxValue;
#endif /* ENCODER_H_ */