/*
 * encoder.h
 *
 * Created: 01.11.2019 13:42:36
 *  Author: sanderfu
 */ 


#ifndef ENCODER_H_
#define ENCODER_H_

#include <avr/io.h>
int16_t encoder_value;
int16_t converted_encoderValue;
void encoder_readValues();
void encoder_init();


#endif /* ENCODER_H_ */