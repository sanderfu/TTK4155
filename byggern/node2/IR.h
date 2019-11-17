/**
 * @file
 * @brief A library for reading analog IR-values on Node 2.
 */



#ifndef IR_H_
#define IR_H_
#include <stdlib.h>
#include <avr/io.h>

/**
 * @brief Read analog value from IR and update score if analog value is below a certain threshold.
 */
void IR_detectGoal();



#endif /* IR_H_ */