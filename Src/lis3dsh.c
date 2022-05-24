/*
 * lis3dsh.c
 *
 *  Created on: 23 May 2022
 *      Author: enesb
 */

#include "lis3dsh.h"



void MEMS_SPI_Communicate(SPI_Handle_t* handle, uint8_t status, uint8_t address, uint8_t *data){
	if(status == MEMS_WRITE){

		uint16_t send_data = 0x0;

		send_data &= ~(status << 15);
		send_data |= address << 8;
		send_data |= *data;

		while(!(handle->pSPIx->SR & (1U << TXE)))
						;

		handle->pSPIx->DR = send_data;

	}else if(status == MEMS_READ){
		uint16_t send_data = 0x0;

		send_data |= (status << 15);
		send_data |= address << 8;

		while(!(handle->pSPIx->SR & (1U << TXE)))
						;
		handle->pSPIx->DR = send_data;

		while(!(handle->pSPIx->SR & (1U << RXNE)))
						;
		*data = handle->pSPIx->DR;
	}
}

void get_xyz_value(SPI_Handle_t* handle, uint8_t *x, uint8_t *y, uint8_t *z){

	static uint8_t receive_data;

	//MEMS_SPI_Communicate(handle ,MEMS_READ, OUT_X_L, &receive_data);
	//*x |= receive_data;
	//delay(DELAY_SECOND(0.00001));
	MEMS_SPI_Communicate(handle, MEMS_READ, OUT_X_H, &receive_data);
	*x |= (receive_data);// << 8);
	delay(DELAY_SECOND(0.00001));
	//MEMS_SPI_Communicate(handle, MEMS_READ, OUT_Y_L, &receive_data);
	//*y |= receive_data;
	//delay(DELAY_SECOND(0.00001));
	MEMS_SPI_Communicate(handle, MEMS_READ, OUT_Y_H, &receive_data);
	*y |= (receive_data),// << 8);
	delay(DELAY_SECOND(0.00001));
	//MEMS_SPI_Communicate(handle, MEMS_READ, OUT_Z_L, &receive_data);
	//*z |= receive_data;
	//delay(DELAY_SECOND(0.00001));
	MEMS_SPI_Communicate(handle, MEMS_READ, OUT_Z_H, &receive_data);
	*z |= (receive_data);// << 8);
	delay(DELAY_SECOND(0.00001));
}

