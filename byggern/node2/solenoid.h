/*
 * solenoid.h
 *
 * Created: 06.11.2019 15:46:06
 *  Author: torsteoe
 */ 


#ifndef SOLENOID_H_
#define SOLENOID_H_

volatile uint8_t shooting;
/**
* @brief Initialize solenoid module
*/
void solenoid_init();

/**
* @brief Set solenoid pulse, hold PE5 high for a fixed duration of time.
*/
void solenoid_setPulse();



#endif /* SOLENOID_H_ */