#include <avr/io.h>
typedef struct {
	uint8_t left_pos;
	uint8_t right_pos;
} slider_position_t;
void slider_readPosition(slider_position_t * pos);