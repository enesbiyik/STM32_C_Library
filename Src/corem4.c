/*
 * corem4.c
 *
 *  Created on: 20 Nis 2022
 *      Author: enesb
 */

#include "corem4.h"

void nvic_enable(int irq_number){
	if(irq_number < 32){
		*NVIC_ISER0 |= (1U << irq_number);
	}
	else if(irq_number > 31 && irq_number < 64){
		*NVIC_ISER1 |= (1U << (irq_number % 32));
	}
	else if(irq_number > 63 && irq_number < 96){
		*NVIC_ISER2 |= (1U << (irq_number % 32));
	}
	else if(irq_number > 95 && irq_number < 128){
		*NVIC_ISER3 |= (1U << (irq_number % 32));
	}
	else if(irq_number > 127 && irq_number < 160){
		*NVIC_ISER4 |= (1U << (irq_number % 32));
	}
}

void nvic_disable(int irq_number){
	if(irq_number < 32){
		*NVIC_ICER0 |= (1U << irq_number);
	}
	else if(irq_number > 31 && irq_number < 64){
		*NVIC_ICER1 |= (1U << (irq_number % 32));
	}
	else if(irq_number > 63 && irq_number < 96){
		*NVIC_ICER2 |= (1U << (irq_number % 32));
	}
	else if(irq_number > 95 && irq_number < 128){
		*NVIC_ICER3 |= (1U << (irq_number % 32));
	}
	else if(irq_number > 127 && irq_number < 160){
		*NVIC_ICER4 |= (1U << (irq_number % 32));
	}
}
