/*
 * solenoid.h
 *
 * Created: 06.11.2019 15:46:06
 *  Author: torsteoe
 */ 


#ifndef SOLENOID_H_
#define SOLENOID_H_

volatile uint8_t shooting;
void solenoid_init();
void solenoid_setPulse();



#endif /* SOLENOID_H_ */