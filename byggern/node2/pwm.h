/**
 * @file
 * @brief A library for generating a pwm-signal on Node 2.
 */


#ifndef PWM_H_
#define PWM_H_
#include <avr/io.h>

/**
* @brief Initialize pwm module.
*/
void pwm_init();

/**
* @brief Set pulse width of pwm signal.
*
* @param[in] width of pulse in ms.
*/
void pwm_setPulseWidth(float width_ms); 

#endif /* PWM_H_ */