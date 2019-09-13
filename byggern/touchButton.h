
#define BUTTON_LEFT (PINB & (1 << PB0))
#define BUTTON_RIGHT (PINB & (1 << PB1))

#include <avr/io.h>

typedef struct {
	uint8_t left_button;
	uint8_t right_button;
} buttonValues_t;

void touchButton_init();
void touchButton_readButtons(buttonValues_t * buttons);