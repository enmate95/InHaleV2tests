/*
 * CHARGER.cpp
 *
 *  Created on: May 29, 2020
 *      Author: mate_pc
 */
#include "CHARGER.h"

void Charger::enableCharge() {
	//EN_CHARGE
}

void Charger::disableCharge() {
	//~EN_CHARGE
}

void Charger::enableMeasurements() {
	//EN_MEAS(VBAT,VBAT_MID1/2)
}

void Charger::disableMeasurements() {
	//~EN_M
}

ChargerData_t* Charger::getChargerData() {
	//Get meas Signals error and voltages
}

float Charger::getVBAT() {
	//for signalling PID
}

bool Charger::test() {
	//for testing all measurmenets in init state
}

bool Charger::MeasureData() {
	//fill up Data structure
}

