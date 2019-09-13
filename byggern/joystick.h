#include <avr/io.h>

typedef struct {
	int8_t x_pos;
	int8_t y_pos;
} position_t;

void setPosition(position_t * pos);