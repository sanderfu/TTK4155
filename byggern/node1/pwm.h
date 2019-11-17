/**
 * @file
 * @brief PWM interface
 */

#ifndef PWM_H_
#define PWM_H_

///////////////////////////////////////////////
// Includes
///////////////////////////////////////////////
#include <avr/io.h> 

///////////////////////////////////////////////
// Function declarations
///////////////////////////////////////////////

/**
 * @brief Initialize the pwm interface
 * 
 */
void pwm_init();

/**
 * @brief Set the pwm frequency
 * 
 * @param[in] freq The wanted frequency
 */
void pwm_setFreq(uint32_t freq);

/**
 * @brief Test function
 * 
 */
void pwm_testPlayNote();
#endif
