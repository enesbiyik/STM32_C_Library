/*
 * usart.c
 *
 *  Created on: Apr 25, 2022
 *      Author: enesb
 */
#include "usart.h"

static void usart_clock_en_di(USART_RegDef_t* USARTx);

void usart_init(USART_Handle_t* handle){
	usart_clock_en_di(handle->USARTx);

	//USART Enable
	handle->USARTx->CR1 = (1U << 13);

	//Word Length
	handle->USARTx->CR1 &= ~(handle->config.word_length << 12);
	handle->USARTx->CR1 |= (handle->config.word_length << 12);

	//Stop bit Configuration
	handle->USARTx->CR2 &= ~(0b11 << 12);
	handle->USARTx->CR2 |= (handle->config.stop_bit << 12);

	//9600 Baudrate
	handle->USARTx->BRR =  0x683;

	//Transmitter Enable
	handle->USARTx->CR1 |= (1U << 3);

	//Receiver Enable
	handle->USARTx->CR1 |= (1U << 2);
}

void usart_write(USART_Handle_t* handle,char* data){

	int n=strlen(data);
	for(int i=0; i<n; i++){
		while(!(USART2->SR &(1U <<7)))
				;
		handle->USARTx->DR = (*(data+i) & 0xFF);
	}

}
char usart_read(USART_Handle_t* handle){
	while((!handle->USARTx->SR &(1U << 5)))
			;
		return handle->USARTx->DR;
}

void usart_disable(USART_Handle_t* handle, disableTypes type){
	switch (type){
		case DISABLE_RX:
			handle->USARTx->CR1 &= ~(1U << 2); //Receiver Disable
			break;
		case DISABLE_TX:
			handle->USARTx->CR1 &= ~(1U << 3); //Transmitter Disable
			break;
		case DISABLE_BOTH:
			handle->USARTx->CR1 &= ~(1U << 3); //Transmitter Disable
			handle->USARTx->CR1 &= ~(1U << 2); //Receiver Disable
			break;
	}

}

static void usart_clock_en_di(USART_RegDef_t* USARTx ){
		if(USARTx == USART1)
			USART1_CLOCK_EN();
		else if(USARTx == USART2)
			USART2_CLOCK_EN();
		else if(USARTx == USART3)
			USART3_CLOCK_EN();
		else if(USARTx == USART4)
			USART4_CLOCK_EN();
		else if(USARTx == USART5)
			USART5_CLOCK_EN();
		else if(USARTx == USART6)
			USART6_CLOCK_EN();
}
