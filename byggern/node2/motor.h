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

void motor_set(uint8_t dir) ;
void motor_setSpeed(uint8_t speed);
void motor_control();
void motor_setDirection(uint8_t dir);
void motor_moveUntilEdge(uint8_t dir);
#endif /* MOTOR_H_ */