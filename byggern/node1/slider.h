#ifndef SLIDER_H_
#define SLIDER_H_
#include <avr/io.h>

typedef struct {
	uint8_t left_pos;
	uint8_t right_pos;
} slider_position_t;

//Read the slider position from the P1000 board
void slider_readPosition();

//Send the slider position over CAN
void slider_sendPositionOverCAN();

slider_position_t slider_pos;

#endif