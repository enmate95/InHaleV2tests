/*
 * PID.cpp
 *
 *  Created on: May 29, 2020
 *      Author: mate_pc
 */
#include "PID.h"


uint16_t PID::run(float signal, uint32_t timeStamp) {

	static volatile float error = 0;
	static volatile float last_error = 0;
	static volatile float control_signal = 0;
	static volatile float integral = 0;
	static volatile float derivative = 0;
	static uint16_t duty_cycle = 0;

	dt = timeStamp - dt;

	if(enable) {
		error = setpoint - signal;
		integral = integral + error * dt;
		derivative = (error - last_error) / dt;
		control_signal = kp * error + ki * integral + kd * derivative;

		if(control_signal > max){
			control_signal = max;
		}
		else if(control_signal < min){
			control_signal = min;
		}

		duty_cycle = (uint16_t)control_signal;
		last_error = error;
		return duty_cycle;
	}
	return 0;
}

void PID::Enable() {
	enable = true;
}

void PID::Disable() {
	enable = false;
}


