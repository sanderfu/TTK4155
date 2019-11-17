/**
 * @file
 * @brief A library for interfacing with the solenoid on node 2.
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