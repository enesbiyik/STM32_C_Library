/*
 * stm32f407xx_gpio.c
 *
 *  Created on: 12 Mar 2022
 *      Author: enesb
 */
#include "stm32f407xx_gpio.h"
#include "stm32f407xx.h"

 static void gpio_clock_en_di(GPIO_RegDef_t *pGPIOx ,BOOL state);
 static uint8_t getFromExtiCodeIrqNumber(uint8_t exticr_no);

void gpio_clock_en_di(GPIO_RegDef_t *pGPIOx ,BOOL state)
{
	if(state == ENABLE)
	{
		if(pGPIOx == GPIOA)
			GPIOA_CLOCK_EN();
		else if(pGPIOx == GPIOB)
			GPIOB_CLOCK_EN();
		else if(pGPIOx == GPIOC)
			GPIOC_CLOCK_EN();
		else if(pGPIOx == GPIOD)
			GPIOD_CLOCK_EN();
		else if(pGPIOx == GPIOE)
			GPIOE_CLOCK_EN();
		else if(pGPIOx == GPIOF)
			GPIOF_CLOCK_EN();
		else if(pGPIOx == GPIOG)
			GPIOG_CLOCK_EN();
		else if(pGPIOx == GPIOH)
			 GPIOH_CLOCK_EN();
		else if(pGPIOx == GPIOI)
			GPIOI_CLOCK_EN();
	}
	if(state == DISABLE)
		;
}

void gpio_init(GPIO_Handle_t *pgpio_handle)
{
	uint32_t temp=0;

	gpio_clock_en_di(pgpio_handle->pGPIOx ,ENABLE);



	//1.mode seçimi yapılacak
	if(pgpio_handle->gpio_pin_config.pin_mode <GPIO_MODE_INT_FT) // non -interrupt mode
	{
		temp = (pgpio_handle->gpio_pin_config.pin_mode <<(2*pgpio_handle->gpio_pin_config.pin_number));
		pgpio_handle->pGPIOx->MODER &= ~(0b11<<(2*pgpio_handle->gpio_pin_config.pin_number));
		pgpio_handle->pGPIOx->MODER |=temp;
	}
	else  // interrupt mode
	{

		SYSCFG_CLOCK_EN(); // System Clock Enable

		if (pgpio_handle->gpio_pin_config.pin_mode == GPIO_MODE_INT_FT)
		{
			EXTI->FTSR |= (1u<<pgpio_handle->gpio_pin_config.pin_number);

			EXTI->RTSR &= ~(1u<<pgpio_handle->gpio_pin_config.pin_number);
		}
		else if (pgpio_handle->gpio_pin_config.pin_mode == GPIO_MODE_INT_RT)
		{
			EXTI->RTSR |= (1u<<pgpio_handle->gpio_pin_config.pin_number);
			EXTI->FTSR &= ~(1u<<pgpio_handle->gpio_pin_config.pin_number);
		}

		else if (pgpio_handle->gpio_pin_config.pin_mode == GPIO_MODE_INT_FRT)
		{
			EXTI->FTSR |= (1u<<pgpio_handle->gpio_pin_config.pin_number);
			EXTI->RTSR |= (1u<<pgpio_handle->gpio_pin_config.pin_number);
		}

		uint8_t exticr_no = pgpio_handle->gpio_pin_config.pin_number / 4 ;
		uint8_t exticr_shift_no = pgpio_handle->gpio_pin_config.pin_number % 4 ;
		uint8_t port_code = get_exticr_port_code(pgpio_handle->pGPIOx);// port gelicek
		SYSCFG->EXTICR[exticr_no] |= (port_code<<(exticr_shift_no *4));

		// enable interrupt request pin0
		EXTI->IMR |=(1u<<pgpio_handle->gpio_pin_config.pin_number);
		uint8_t irq_no = getFromExtiCodeIrqNumber(exticr_no);
		nvic_enable(irq_no);
	}

		//2. otype
		temp  = (pgpio_handle->gpio_pin_config.pin_otype << (pgpio_handle->gpio_pin_config.pin_number));
		pgpio_handle->pGPIOx->OTYPER &= ~(1u<<(pgpio_handle->gpio_pin_config.pin_number));
		pgpio_handle->pGPIOx->OTYPER |= temp;
		//3.speed
		temp  = (pgpio_handle->gpio_pin_config.pin_speed << (2*pgpio_handle->gpio_pin_config.pin_number));
		pgpio_handle->pGPIOx->OSPEEDR &= ~(0b11<<(2*pgpio_handle->gpio_pin_config.pin_number));
		pgpio_handle->pGPIOx->OSPEEDR |= temp;

		//4.pupd
		temp  = (pgpio_handle->gpio_pin_config.pin_pu_pd << (2*pgpio_handle->gpio_pin_config.pin_number));
		pgpio_handle->pGPIOx->PUPDR &= ~(0b11<<(2*pgpio_handle->gpio_pin_config.pin_number));
		pgpio_handle->pGPIOx->PUPDR |= temp;

		//5.alternate

		temp = (pgpio_handle->gpio_pin_config.pin_alter_mode <<(4*(pgpio_handle->gpio_pin_config.pin_number %8)));
		int alter_register_number = pgpio_handle->gpio_pin_config.pin_number / 8;
		pgpio_handle->pGPIOx->AFR[alter_register_number] &= ~(0b1111<<(4*(pgpio_handle->gpio_pin_config.pin_number %8)));
		pgpio_handle->pGPIOx->AFR[alter_register_number] |= temp;
}

void gpio_write_out_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no,BOOL val)
{
	if ( val == GPIO_SET)
		pgpiox->ODR |= (1u<<pin_no);
	else
		pgpiox->ODR &= ~(1u<<pin_no);
}

BOOL gpio_read_input_pin(GPIO_RegDef_t *pgpiox,uint16_t pin_no)
{

	uint16_t res =(uint16_t)((pgpiox->IDR)& (1 << pin_no));
	res = ((res != 0) ? GPIO_SET : GPIO_RESET);  // //  return (!(res)==0)
	return res;
}

void gpio_toggle_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no)
{
	pgpiox->ODR ^= (1u<<pin_no);
}

void gpio_write_port(GPIO_RegDef_t *pgpiox,uint16_t val)
{

	pgpiox->ODR =val;
}

uint16_t gpio_read_input_port(GPIO_RegDef_t *pgpiox)
{
	uint16_t val=0;
	pgpiox->IDR =0;
	val = (uint16_t)pgpiox->IDR;
	return val;
}

ExtiCR_PortCode get_exticr_port_code(const GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
		return Port_CodeA;
	else if(pGPIOx == GPIOB)
		return Port_CodeB;
	else if(pGPIOx == GPIOC)
			return Port_CodeC;
	else if(pGPIOx == GPIOD)
			return Port_CodeD;
	else if(pGPIOx == GPIOE)
			return Port_CodeE;
	else if(pGPIOx == GPIOF)
			return Port_CodeF;

}

static uint8_t getFromExtiCodeIrqNumber(uint8_t exticr_no)
{
	if(exticr_no == EXTI0)
		return IRQ_NO_EXTI0;
	else if(exticr_no == EXTI1)
		return IRQ_NO_EXTI1;
	else if(exticr_no == EXTI2)
		return IRQ_NO_EXTI2;
	else if(exticr_no == EXTI3)
		return IRQ_NO_EXTI3;
	else if(exticr_no == EXTI4)
		return IRQ_NO_EXTI4;
	else if(exticr_no>EXTI4 && exticr_no<EXTI10)
		return IRQ_NO_EXTI9_5;
	else if(exticr_no> EXTI9 && exticr_no<= EXTI15)
		return IRQ_NO_EXTI15_10;
}
