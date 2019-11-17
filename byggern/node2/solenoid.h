/**
 * @file
 * @brief A library for interfacing with the solenoid on node 2.
 */


#ifndef SOLENOID_H_
#define SOLENOID_H_

volatile uint8_t shooting;
void solenoid_init();
void solenoid_setPulse();



#endif /* SOLENOID_H_ */