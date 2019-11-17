#ifndef PWM_H_
#define PWM_H_
#include <avr/io.h> 

//Initialize PWM
void pwm_init();

//Set PWM frequency
void pwm_setFreq(uint32_t freq);

//Test function to verify that PWM is functioning correctly
void pwm_testPlayNote();
#endif
