/*
 * pwm.h
 *
 * Created: 18.10.2019 08:51:34
 *  Author: torsteoe
 */ 


#ifndef PWM_H_
#define PWM_H_
#include <avr/io.h>


void pwm_init();
void pwm_setPulseWidth(float width_ms);

#endif /* PWM_H_ */