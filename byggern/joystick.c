#include "joystick.h"
#include "adc.h"
#define X_POS_CHANNEL 0
#define Y_POS_CHANNEL 1


void setPosition(position_t * pos) {
	uint8_t x_pos = readAdc(X_POS_CHANNEL);
	uint8_t y_pos = readAdc(Y_POS_CHANNEL);
	pos->x_pos = ((x_pos -126)*100)/(256/2);
	pos->y_pos = ((y_pos -126)*100)/(256/2);
}
