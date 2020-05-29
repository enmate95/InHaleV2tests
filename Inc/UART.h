#ifndef UART_H
#define UART_H

#include <stdint.h>
#include "stm32f4xx_hal.h"
#define RAW_SIZE 100


class uartDMA {
	//constructors and destructors
	public:
		uartDMA(UART_HandleTypeDef* handler);
		~uartDMA() = default;
	//interfaces
	public:
		bool Send(uint8_t* data,uint16_t dataSize);
		bool copyBuffer(uint8_t* copyTo,uint16_t copyToSize);
	private:
		void clearBuffer();
		bool uartHandleFLags();
		uint8_t rawDMABuffer[RAW_SIZE];
		UART_HandleTypeDef *handler = nullptr;
};











#endif
