#include <avr/io.h>

typedef struct {
	int8_t x_pos;
	int8_t y_pos;
} position_t;

typedef enum DIRECTION {
	LEFT, 
	RIGHT, 
	UP, 
	DOWN, 
	NEUTRAL
} DIRECTION_t ;
	
void setPosition(position_t * pos);
DIRECTION_t getDirection(position_t * pos);
void printDirection(DIRECTION_t dir);