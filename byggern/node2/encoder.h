/**
 * @file
 * @brief A library for reading encoder values on Node 2.
 */



#ifndef ENCODER_H_
#define ENCODER_H_

#include <avr/io.h>
volatile int16_t encoder_value;
volatile int16_t converted_encoderValue;


/**
 * @brief Read encoder values and convert them to appropriate values between -100 and 100.
 */
void encoder_readValues();

/**
 * @brief Initialize encoder module
 */
void encoder_init();

volatile int encoder_maxValue;
#endif /* ENCODER_H_ */