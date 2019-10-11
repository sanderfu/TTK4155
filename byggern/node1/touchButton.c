
#include "touchButton.h"
#include "adc.h"

void touchButton_init() {
	DDRB &= ~(1 << BUTTON_LEFT | 1 << BUTTON_RIGHT);
}
void touchButton_readButtons() {
	buttons.left_button = !!(BUTTON_LEFT);
	buttons.right_button = !!(BUTTON_RIGHT);
}
