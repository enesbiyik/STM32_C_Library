/*
 * lis3dsh.h
 *
 *  Created on: 23 May 2022
 *      Author: enesb
 */
#include <stdint.h>
#include "stm32f407xx.h"
#include "spi.h"
#include "utility.h"

#ifndef LIS3DSH_H_
#define LIS3DSH_H_

#define MEMS_WRITE	0
#define MEMS_READ	1

#define OUT_X_L	0x28
#define OUT_X_H	0x29
#define OUT_Y_L	0x2A
#define OUT_Y_H	0x2B
#define OUT_Z_L	0x2C
#define OUT_Z_H	0x2D

void MEMS_SPI_Communicate(SPI_Handle_t* handle, uint8_t status, uint8_t address, uint8_t *data);
void get_xyz_value(SPI_Handle_t* handle, uint8_t *x, uint8_t *y, uint8_t *z);

#endif /* LIS3DSH_H_ */
