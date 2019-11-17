/**
 * @file
 * @brief A library for saving battery using sleep.
 */



#ifndef SLEEP_H_
#define SLEEP_H_

/**
* @brief Initialize sleep. Set sleep mode to be idle.
*/
void sleep_init();

/**
* @brief Make cpu sleep until next interrupt.
*/
void sleep_now();



#endif /* SLEEP_H_ */