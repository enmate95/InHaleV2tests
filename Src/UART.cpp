#include "UART.h"

uartDMA::uartDMA(UART_HandleTypeDef* handler): handler(handler) {
	handler->Instance->CR1 |= UART_IT_IDLE;
	HAL_UART_Receive_DMA(handler,rawDMABuffer,sizeof(rawDMABuffer));
}


bool uartDMA::Send(uint8_t* data,uint16_t dataSize) {
	if(HAL_UART_Transmit_DMA(handler,data,dataSize) != HAL_OK)
		return false;
	return true;
}


bool uartDMA::uartHandleFLags() {
	uint32_t flags = handler->Instance->SR;
	if((flags & UART_FLAG_IDLE) == UART_FLAG_IDLE) {
		uint8_t data = (uint8_t) handler->Instance->DR;
		return true;
	}
	return false;
}


void uartDMA::clearBuffer() {
	for(int i = 0; i < sizeof(rawDMABuffer); i++)
		rawDMABuffer[i] = 0;
}

bool uartDMA::copyBuffer(uint8_t* copyTo,uint16_t copyToSize) {
	static uint32_t length = 0;
	if(!uartHandleFLags())			//true if idle flag IT was happend
		return false;

	HAL_UART_DMAPause(handler);
	length = (uint32_t)sizeof(rawDMABuffer)-handler->hdmarx->Instance->NDTR;
	if(length > 0 && length < copyToSize) {		//if something was received and there is enough space for copy
		for(int i = 0; i < copyToSize; i++) {
			copyTo[i] = rawDMABuffer[i];
		}
		HAL_UART_DMAResume(handler);
		HAL_UART_DMAStop(handler);
		clearBuffer();
		HAL_UART_Receive_DMA(handler,rawDMABuffer,sizeof(rawDMABuffer));
		return true;
	}
	HAL_UART_DMAResume(handler);
	return false;
}
