/*
 * CHARGER.h
 *
 *  Created on: May 29, 2020
 *      Author: mate_pc
 */

#ifndef CHARGER_H_
#define CHARGER_H_

#include "ERROR.h"
#include "I2C.h"
#include "stm32f4xx_hal.h"

enum class ChargerSignals{
	NO_SIGNAL = 0x00,
	CHARGING = 0x01,
	CHARGING_DONE = 0x02,
	VBAT_LOW = 0x04,
	VUSB_APPLIED = 0x08
};

typedef struct {
	ChargerSignals signals;
	uint8_t numOfCells;
	float vbat;
	float vbatMid1;
	float vbatMid2;
	float vusb;
	errorType error = errorType::NO_ERROR;
}ChargerData_t;

class Charger {
	//constructors and destructors
	public:
		Charger(I2C i2c,Adc adc) : i2c(i2c), adc(adc) {};
		~Charger() = default;

	//interface
	public:
		void enableCharge();				//EN_CHARGE
		void disableCharge();				//~EN_CHARGE
		void enableMeasurements();			//EN_MEAS(VBAT,VBAT_MID1/2)
		void disableMeasurements();			//~EN_M
		ChargerData_t* getChargerData();	//Get meas Signals error and voltages
		float getVBAT();					//for signalling PID
		bool test();						//for testing all measurmenets in init state
		bool MeasureData();					//fill up Data structure

	private:
		ChargerData_t Data;
		I2C i2c;
		Adc adc;
};










#endif /* CHARGER_H_ */
