#ifndef PWM_H_
#define PWM_H_
#include <avr/io.h> 
void pwm_init();
void pwm_setFreq(uint32_t freq);
void pwm_testPlayNote();
#endif
