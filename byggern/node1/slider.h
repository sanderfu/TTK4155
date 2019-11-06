#ifndef SLIDER_H_
#define SLIDER_H_
#include <avr/io.h>

typedef struct {
	uint8_t left_pos;
	uint8_t right_pos;
} slider_position_t;
void slider_readPosition();
void slider_sendPositionOverCAN();

slider_position_t slider_pos;

#endif