/*
 * slider.h
 *
 * Created: 01.11.2019 10:48:23
 *  Author: sanderfu
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




#endif /* SLIDER_H_ */