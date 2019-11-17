/*
 * touchbutton.h
 *
 * Created: 06.11.2019 15:45:32
 *  Author: torsteoe
 */ 


#ifndef TOUCHBUTTON_H_
#define TOUCHBUTTON_H_
#include <avr/io.h>

typedef struct {
	uint8_t left_button;
	uint8_t right_button;
} buttonValues_t;
buttonValues_t buttons;



#endif /* TOUCHBUTTON_H_ */