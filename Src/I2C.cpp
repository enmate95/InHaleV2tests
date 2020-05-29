#include "I2C.h"
#include "stm32f4xx_hal.h"


I2C::I2C(I2C_HandleTypeDef* handler): handler(handler){}


bool I2C::writeRegister(uint16_t address, uint16_t regAddress, uint8_t* data,uint16_t dataSize,uint32_t timeout) {
	if(HAL_I2C_Mem_Write(handler,address,regAddress,sizeof(uint16_t),data,dataSize,timeout) != HAL_OK)
		return false;
	return true;
}

bool I2C::readRegister(uint16_t address, uint16_t regAddress, uint8_t* data,uint16_t dataSize,uint32_t timeout) {
	if(HAL_I2C_Mem_Read(handler,address,regAddress,sizeof(uint16_t),data,dataSize,timeout) != HAL_OK)
		return false;
	return true;
}
