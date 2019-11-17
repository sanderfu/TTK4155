/*
 * IR.h
 *
 * Created: 25.10.2019 11:44:45
 *  Author: haavaei
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