#define LEFT_POS_CHANNEL 2
#define RIGHT_POS_CHANNEL 3
#include "slider.h"
#include "adc.h"
void slider_readPosition(slider_position_t * pos) {
	pos->left_pos = readAdc(LEFT_POS_CHANNEL);
	pos->right_pos = readAdc(RIGHT_POS_CHANNEL);
}