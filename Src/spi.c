/*
 * spi.c
 *
 *  Created on: 17 May 2022
 *      Author: enesb
 */

#include "spi.h"

static void spi_clock_enable(SPI_RegDef_t* pSPIx);

void spi_init(SPI_Handle_t* handle){

	spi_clock_enable(handle->pSPIx);

	uint16_t temp = 0;

	if(handle->config.Direction == SPI_DIRECTION_2LINES){
		temp &= ~(1U << BIDI_MODE);
		temp &= ~(1U << RX_ONLY);
	}
	else if(handle->config.Direction == SPI_DIRECTION_2LINES_RXONLY){
		temp &= ~(1U << BIDI_MODE);
		temp |= (1U << RX_ONLY);
	}
	else if(handle->config.Direction == SPI_DIRECTION_1LINE){
		temp |= ~(1U << BIDI_MODE);
	}


	temp |= (1U) << SPE;							//SPI Enable
	temp |= handle->config.Mode << MSTR; 			//SPI Mode Select
	 	 	 	 	 	 	 	 	 	 	 	 //SPI Direction Select
	temp |= handle->config.DataSize << DFF; 		//SPI Data Size Select
	temp |= handle->config.CLKPolarity << CPOL;	 	//SPI Clock Polarity Select
	temp |= handle->config.CLKPhase << CPHA; 		//SPI Clock Phase Select

	//SPI Software Slave Management Select
	if(handle->config.NSS == SPI_SSM_ENABLE){
		temp |= handle->config.NSS << SSM;			//Software Slave Management
		temp |= (1U << SSI);						//Enabled and SSI Bit Set
	}
	else
		temp |= handle->config.NSS << SSM;

	temp |= handle->config.BaudRatePrescaler << BR; //SPI Baudrate Prescaler Select
	temp |= handle->config.FirstBit << LSB_FIRST; 	//SPI First Bit Select
	 											//SPI TI or Motorola Mode Select
												//SPI CRC Calculation Select
												//SPI CRC Polynomial Select

	handle->pSPIx->CR1 = temp;						//Configuration Upload CR1 Register
}
uint8_t veri;
uint16_t new_data;
void spi_write(SPI_Handle_t* handle, uint16_t* data, uint32_t len){

	if(handle->config.Direction == SPI_DIRECTION_1LINE){
		handle->pSPIx->CR1 = (1U) << BIDI_OE;
		for(int i= 0; i < len; i++){
			while(!(handle->pSPIx->SR & (1U<<TXE)));
				;
			handle->pSPIx->DR = *(uint8_t*)(data+i);
		}
	}
	else{
		if(handle->config.DataSize == SPI_DATASIZE_8BIT){
			for(int i= 0; i < len; i++){
				while(!(handle->pSPIx->SR & (1U<<TXE)));
					;
				veri = *(data+i); // Global Variable for Live Expression
				handle->pSPIx->DR = *(uint8_t*)(data+i);
			}
		}
		else if(handle->config.DataSize == SPI_DATASIZE_16BIT){
			for(int i= 0; i < len; i++){
				while(!(handle->pSPIx->SR & (1U << TXE)))
					;
				handle->pSPIx->DR = *(data + i);
			}
		}
	}


}
uint8_t spi_read_8_bit(SPI_Handle_t* handle){

	if(handle->config.Direction == SPI_DIRECTION_1LINE){
		handle->pSPIx->CR1 &= ~(1U << BIDI_OE);
			while(!(handle->pSPIx->SR & (1U << RXNE)))
					;
			uint8_t	data = handle->pSPIx->DR;
	}
	else{

		while(!(handle->pSPIx->SR & (1U << RXNE)))
				;
		uint8_t	data = handle->pSPIx->DR;

		return data;
	}
}

uint16_t spi_read_16bit(SPI_Handle_t* handle){

	if(handle->config.Direction == SPI_DIRECTION_1LINE){
		handle->pSPIx->CR1 &= ~(1U << BIDI_OE);
			while(!(handle->pSPIx->SR & (1U << RXNE)))
					;
			uint8_t	data = handle->pSPIx->DR;
	}
	else{

		while(!(handle->pSPIx->SR & (1U << RXNE)))
					;
		uint16_t data = handle->pSPIx->DR;

		return data;
	}
}


static void spi_clock_enable(SPI_RegDef_t* pSPIx){
	if(pSPIx == SPI1)
		SPI1_CLOCK_EN();
	else if(pSPIx == SPI2)
		SPI2_CLOCK_EN();
	else if(pSPIx == SPI3)
		SPI3_CLOCK_EN();
}
