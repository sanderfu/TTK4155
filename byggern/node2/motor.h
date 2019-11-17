/**
 * @file
 * @brief A library for interfacing with the motor on Node 2.
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include <avr/io.h>

/**
 * @brief Initiate motor module 
 */
void motor_init();

/**
 * @brief Turn on motor
 */
void motor_enable();

/**
 * @brief Turn off motor
 */
void motor_disable();


/**
 * @brief Set speed of motor.
 * @param speed digital value from 0 to 255.
 */
void motor_setSpeed(uint8_t speed);

/**
 * @brief Control motor speed with PID-regulator, using slider right as reference.
 */
void motor_control();

/**
 * @brief Set direction of motor
 * @param dir 0 for left, 1 for right.
 */
void motor_setDirection(uint8_t dir);


/**
 * @brief Calibrate motor, move until motor reaches both walls, reset encoder and set max value for encoder.
 */
void motor_calibrate();

#endif /* MOTOR_H_ */