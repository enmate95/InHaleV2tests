/*
 * ADC.h
 *
 *  Created on: May 29, 2020
 *      Author: mate_pc
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

class Adc {
	public:
		Adc(ADC_HandleTypeDef* handler) :handler(handler) {}
		~Adc() = default;
		uint32_t startConversion(uint32_t channel);
	private:
		ADC_HandleTypeDef* handler;
};


#endif /* ADC_H_ */
