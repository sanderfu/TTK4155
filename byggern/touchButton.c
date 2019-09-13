
#include "touchButton.h"
#include "adc.h"

void touchButton_init() {
	DDRB &= ~(1 << BUTTON_LEFT | 1 << BUTTON_RIGHT);
}
touchButton_readButtons(buttonValues_t * buttons) {
	buttons->left_button = !!(BUTTON_LEFT);
	buttons->right_button = !!(BUTTON_RIGHT);
}
