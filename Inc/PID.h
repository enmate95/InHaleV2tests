/*
 * PID.h
 *
 *  Created on: May 29, 2020
 *      Author: mate_pc
 */

#ifndef PID_H_
#define PID_H_

#include <stdint.h>

class PID {
	//constructors and destructors
	public:
		PID(): PID(1,0,0){}
		PID(float kp, float ki, float kd): kp(kp), ki(ki), kd(kd) {}
		~PID() = default;
	//properties
	public:
		void setKp(float kp) {this->kp = kp;}
		void setKi(float ki) {this->ki = ki;}
		void setKd(float kd) {this->kd = kd;}
		void setMax(float max) {this->max = max;}
		void setMin(float min) {this->min = min;}
		uint16_t run(float signal, uint32_t timeStamp);
		void changeSetpoint(float setpoint) {this->setpoint = setpoint;}
	//interfaces
	public:
		void Enable();
		void Disable();

	private:
		bool enable = false;
		float kp;
		float ki;
		float kd;
		float setpoint = 0;
		float signal = 0;
		float dt = 0;
		float max = 0;
		float min = 0;
};




#endif /* PID_H_ */
