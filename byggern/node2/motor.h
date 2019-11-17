/*
 * motor.h
 *
 * Created: 01.11.2019 13:25:45
 *  Author: sanderfu
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include <avr/io.h>
void motor_init();

void motor_enable();
void motor_disable();

void motor_setSpeed(uint8_t speed);

//PID-control of motor, reference point chosen by slider input.
void motor_control();
void motor_setDirection(uint8_t dir);

//Calibrate motor, move until motor reaches both walls, set max value.
void motor_calibrate();
#endif /* MOTOR_H_ */