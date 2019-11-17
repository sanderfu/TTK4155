/**
 * @file
 * @brief A library for storing the slider values on node 2.
 */

#ifndef SLIDER_H_
#define SLIDER_H_
#include <avr/io.h>
#include "CAN.h"
typedef struct {
	int32_t left_pos;
	int32_t right_pos;
} slider_position_t;
volatile slider_position_t slider_pos;

void slider_readPositionOverCAN(CAN_message_t mess);





#endif /* SLIDER_H_ */