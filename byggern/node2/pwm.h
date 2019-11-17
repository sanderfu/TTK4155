/**
 * @file
 * @brief A library for generating a pwm-signal on Node 2.
 */


#ifndef PWM_H_
#define PWM_H_
#include <avr/io.h>


void pwm_init();

void pwm_setPulseWidth(float width_ms); 

#endif /* PWM_H_ */