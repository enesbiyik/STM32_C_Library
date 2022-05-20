/*
 * stm32f407xx_gpio.h
 *
 *  Created on: 12 Mar 2022
 *      Author: enesb
 */

#ifndef STM32F407XX_GPIO_H_
#define STM32F407XX_GPIO_H_
#include <stdint.h>
#include "stm32f407xx.h"
#include "corem4.h"

typedef uint8_t BOOL;

typedef struct{
	uint8_t pin_number;
	uint8_t pin_mode;
	uint8_t pin_speed;
	uint8_t pin_pu_pd;
	uint8_t pin_otype;
	uint8_t pin_alter_mode;
}GPIO_PinConfig_t;


typedef struct{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t gpio_pin_config;
}GPIO_Handle_t;

// GPIO MODE STATES
#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTER		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_INT_FT	4
#define GPIO_MODE_INT_RT	5
#define GPIO_MODE_INT_FRT	6

#define	GPIO_OTYPE_PP		0
#define	GPIO_OTYPE_OD		1

#define	GPIO_SPEED_LOW		0
#define	GPIO_SPEED_MED		1
#define	GPIO_SPEED_FAST		2
#define	GPIO_SPEED_VFAST	3

#define	GPIO_PUPD_NO		0
#define	GPIO_PUPD_PU		1
#define	GPIO_PUPD_PD		2

#define GPIO_PIN_0			0
#define GPIO_PIN_1			1
#define GPIO_PIN_2			2
#define GPIO_PIN_3			3
#define GPIO_PIN_4			4
#define GPIO_PIN_5			5
#define GPIO_PIN_6			6
#define GPIO_PIN_7			7
#define GPIO_PIN_8			8
#define GPIO_PIN_9			9
#define GPIO_PIN_10			10
#define GPIO_PIN_11			11
#define GPIO_PIN_12			12
#define GPIO_PIN_13			13
#define GPIO_PIN_14			14
#define GPIO_PIN_15			15

#define	GPIO_SET			1
#define GPIO_RESET			0
#define GPIO_ALL_SET_PINS	0xFFFF
#define GPIO_ALL_RESET_PINS	0x0000

#define GPIO_SET_0			(1U << 0)
#define GPIO_SET_1			(1U << 1)
#define GPIO_SET_2			(1U << 2)
#define GPIO_SET_3			(1U << 3)
#define GPIO_SET_4			(1U << 4)
#define GPIO_SET_5			(1U << 5)
#define GPIO_SET_6			(1U << 6)
#define GPIO_SET_7			(1U << 7)
#define GPIO_SET_8			(1U << 8)
#define GPIO_SET_9			(1U << 9)
#define GPIO_SET_10			(1U << 10)
#define GPIO_SET_11			(1U << 11)
#define GPIO_SET_12			(1U << 12)
#define GPIO_SET_13			(1U << 13)
#define GPIO_SET_14			(1U << 14)
#define GPIO_SET_15			(1U << 15)

typedef enum {GPIO_AF0, GPIO_AF1, GPIO_AF2, GPIO_AF3, GPIO_AF4, GPIO_AF5, GPIO_AF6, GPIO_AF7,
			  GPIO_AF8, GPIO_AF9, GPIO_AF10, GPIO_AF11, GPIO_AF12, GPIO_AF13, GPIO_AF14
			  }GPIO_Alternate_Functions;

void gpio_init(GPIO_Handle_t *pgpio_handle);
void gpio_write_out_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no,BOOL val);
BOOL gpio_read_input_pin(GPIO_RegDef_t *pgpiox,uint16_t pin_no);
void gpio_toggle_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no);
void gpio_write_port(GPIO_RegDef_t *pGPIOx, uint16_t val);
uint16_t gpio_read_input_port(GPIO_RegDef_t *pGPIOx);

typedef enum{Port_CodeA, Port_CodeB, Port_CodeC, Port_CodeD, Port_CodeE, Port_CodeF}ExtiCR_PortCode;

ExtiCR_PortCode get_exticr_port_code(const GPIO_RegDef_t *pGPIOx);

#endif /* STM32F407XX_GPIO_H_ */
