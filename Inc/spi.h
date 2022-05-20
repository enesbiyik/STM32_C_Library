/*
 * spi.h
 *
 *  Created on: 17 May 2022
 *      Author: enesb
 */

#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>
#include "stm32f407xx.h"


#define SPI_MODE_SLAVE	0
#define SPI_MODE_MASTER	1

#define SPI_DIRECTION_2LINES		0
#define SPI_DIRECTION_2LINES_RXONLY	1
#define SPI_DIRECTION_1LINE			2

#define SPI_DATASIZE_8BIT	0
#define SPI_DATASIZE_16BIT	1

#define SPI_BAUDRATEPRESCALER_2		0
#define SPI_BAUDRATEPRESCALER_4		1
#define SPI_BAUDRATEPRESCALER_8		2
#define SPI_BAUDRATEPRESCALER_16	3
#define SPI_BAUDRATEPRESCALER_32	4
#define SPI_BAUDRATEPRESCALER_64	5
#define SPI_BAUDRATEPRESCALER_128	6
#define SPI_BAUDRATEPRESCALER_256	7

#define SPI_PHASE_1EDGE		0
#define SPI_PHASE_2EDGE		1

#define SPI_POLARITY_LOW	0
#define SPI_POLARITY_HIGH	1

#define SPI_SSM_DISABLE		0
#define SPI_SSM_ENABLE 		1

#define SPI_FIRSTBIT_MSB	0
#define SPI_FIRSTBIT_LSB	1

typedef struct{
	uint32_t Mode;
	uint32_t Direction;
	uint32_t DataSize;
	uint32_t CLKPolarity;
	uint32_t CLKPhase;
	uint32_t NSS;
	uint32_t BaudRatePrescaler;
	uint32_t FirstBit;
	uint32_t TIMode;
	uint32_t CRCCalculation;
	uint32_t CRCPolynomial;
}SPI_Pin_Config;

typedef struct{
	SPI_RegDef_t* pSPIx;
	SPI_Pin_Config config;
}SPI_Handle_t;

typedef enum SPI_CR1_BITS{CPHA, CPOL, MSTR, BR, SPE=6, LSB_FIRST, SSI,\
	SSM, RX_ONLY, DFF, CRC_NEXT, CRC_EN, BIDI_OE, BIDI_MODE}SPI_CR1_BITS;

typedef enum SPI_CR2_BITS{RXDMAEN, TXDMAEN, SSOE, FRF=4, ERRIE, RXNEIE, XEIE}SPI_CR2_BITS;

typedef enum SPI_BR_BITS{RXNE, TXE, CHSIDE, UDR, CRC_ERR, MODF, OVR,\
	BSY, FRE}SPI_BR_BITS;

void spi_init(SPI_Handle_t* handle);
void spi_write(SPI_Handle_t* handle, uint8_t* data, uint32_t len);
uint8_t spi_read(SPI_Handle_t* handle);

#endif /* SPI_H_ */
