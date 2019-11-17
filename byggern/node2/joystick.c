/*
 * joystick.c
 *
 * Created: 11.10.2019 15:39:00
 *  Author: torsteoe
 */ 
#include "joystick.h"
#include "CAN.h"
#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TWI_Master.h"


void joystick_setServo() {
	
		//Transform value to [2.1-0.9]
		float var = 3-(((float)joystick_pos.x_pos+100.0)/200.0*(2.1-0.9)+0.9);
		pwm_setPulseWidth(var);
	
}
