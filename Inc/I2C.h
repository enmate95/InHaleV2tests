#ifndef I2C_H
#define I2C_H

#include <stdint.h>
#include "stm32f4xx_hal.h"

class I2C {
	//constructors and destructors
	public:
		I2C(I2C_HandleTypeDef* handler);
		~I2C() = default;
	//interfaces
	public:
		bool writeRegister(uint16_t address, uint16_t regAddress, uint8_t* data,uint16_t dataSize,uint32_t timeout);
		bool readRegister(uint16_t address, uint16_t regAddress, uint8_t* data,uint16_t dataSize,uint32_t timeout);
	private:
		I2C_HandleTypeDef *handler = nullptr;
};

#endif
