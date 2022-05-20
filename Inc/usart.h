/*
 * usart.h
 *
 *  Created on: Apr 25, 2022
 *      Author: enesb
 */

#ifndef USART_H_
#define USART_H_

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "stm32f407xx.h"

#define	USART_8_BIT	0
#define USART_9_BIT	1

#define STOP_BIT_1		0
#define STOP_BIT_0_5	1
#define STOP_BIT_2		2
#define STOP_BIT_1_5	3

typedef enum{DISABLE_RX, DISABLE_TX, DISABLE_BOTH}disableTypes;

typedef struct{
	uint32_t word_length;
	uint32_t stop_bit;
	uint32_t baudrate;
}Usart_Pin_Config;

typedef struct{
	USART_RegDef_t* USARTx;
	Usart_Pin_Config config;
}USART_Handle_t;

void usart_init(USART_Handle_t* handle);
void usart_write(USART_Handle_t* handle,char* data);
char usart_read(USART_Handle_t* handle);
void usart_disable(USART_Handle_t* handle, disableTypes type);

#endif /* USART_H_ */
