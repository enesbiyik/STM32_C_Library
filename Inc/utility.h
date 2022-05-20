/*
 * utility.h
 *
 *  Created on: 20 Nis 2022
 *      Author: enesb
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <stdint.h>

#define	SECOND_1		2014388
#define	DELAY_SECOND(x)		((x)*(SECOND_1))

void delay(uint32_t time);


#endif /* UTILITY_H_ */
