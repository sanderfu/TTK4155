/**
 * @file
 * @brief Sleep interface
 */

#ifndef SLEEP_H_
#define SLEEP_H_

///////////////////////////////////////////////
// Function declarations
///////////////////////////////////////////////

/**
 * @brief Initialize the sleep interface
 * 
 */
void sleep_init();

/**
 * @brief Put the MCU to sleep
 * 
 */
void sleep_now();


#endif /* SLEEP_H_ */