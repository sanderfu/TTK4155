
#include "touchButton.h"
#include "adc.h"

touchButton_readButtons(buttonValues_t * buttons) {
	buttons->left_button = !!(BUTTON_LEFT);
	buttons->right_button = !!(BUTTON_RIGHT);
}