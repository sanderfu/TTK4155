/*
 * test.h
 *
 * Created: 20.09.2019 14:29:30
 *  Author: torsteoe
 */ 


#ifndef TEST_H_
#define TEST_H_

#include "joystick.h"
#include "slider.h"
#include "touchButton.h"

//Test that SRAM is functioning correctly
void test_SRAM(void);

//Test output Controllers
void test_outputControllers(joystick_position_t joystick_pos, slider_position_t slider_pos, buttonValues_t buttons);

//Test menu reset
void test_resetMenu();

#endif /* TEST_H_ */