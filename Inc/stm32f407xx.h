/*
 * stm32f407xx.h
 *
 *  Created on: 12 Mar 2022
 *      Author: enesb
 */

#ifndef STM32F407XX_H_
#define STM32F407XX_H_

//#define		static		PRIVATE
#define		PUBLIC

#define		DISABLE		0
#define		ENABLE		1
#define		RESET		DISABLE
#define		SET			ENABLE


// APBx and AHBx Peripheral Base Adresses
#define		PERIPH_BASEADDR		0x40000000U
#define 	APB1_BASEADDR		PERIPH_BASEADDR
#define 	APB2_BASEADDR		0x40010000U
#define 	AHB1_BASEADDR		0x40020000U
#define 	AHB2_BASEADDR		0x50000000U
#define 	AHB3_BASEADDR		0x60000000U


// Base addresses of peripherals for APB1
#define     TIM2_BASEADDR        APB1_BASEADDR
#define     TIM3_BASEADDR       (APB1_BASEADDR + 0x400)
#define     TIM4_BASEADDR       (APB1_BASEADDR + 0x800)   // 0x40000000U  +800  = 0x4000 0800U
#define     TIM5_BASEADDR       (APB1_BASEADDR + 0xC00)
#define     TIM6_BASEADDR       (APB1_BASEADDR + 0x1000)
#define     TIM7_BASEADDR       (APB1_BASEADDR + 0x1400)
#define     TIM12_BASEADDR      (APB1_BASEADDR + 0x1800)
#define     TIM13_BASEADDR      (APB1_BASEADDR + 0x1C00)
#define     TIM14_BASEADDR      (APB1_BASEADDR + 0x2000)

#define     RTC_BKP_BASEADDR	(APB1_BASEADDR + 0x2800)
#define     WWDG_BASEADDR		(APB1_BASEADDR + 0x2C00)
#define     IWDG_BASEADDR		(APB1_BASEADDR + 0x3000)
#define     I2S2EXT_BASEADDR	(APB1_BASEADDR + 0x3400)
#define     SPI2_I2S2_BASEADDR	(APB1_BASEADDR + 0x3800)
#define     SPI3_I2S3_BASEADDR	(APB1_BASEADDR + 0x3C00)
#define     I2S3EXT_BASEADDR	(APB1_BASEADDR + 0x4000)
#define     USART2_BASEADDR		(APB1_BASEADDR + 0x4400)
#define     USART3_BASEADDR		(APB1_BASEADDR + 0x4800)
#define     USART4_BASEADDR		(APB1_BASEADDR + 0x4C00)
#define     USART5_BASEADDR		(APB1_BASEADDR + 0x5000)
#define     I2C1_BASEADDR		(APB1_BASEADDR + 0x5400)
#define     I2C2_BASEADDR		(APB1_BASEADDR + 0x5800)
#define     I2C3_BASEADDR		(APB1_BASEADDR + 0x5C00)
#define     CAN1_BASEADDR		(APB1_BASEADDR + 0x6400)
#define     CAN2_BASEADDR		(APB1_BASEADDR + 0x6800)
#define     PWR_BASEADDR		(APB1_BASEADDR + 0x7000)
#define     DAC_BASEADDR		(APB1_BASEADDR + 0x7400)


// Base addresses of peripherals for APB2
#define     TIM1_BASEADDR		 APB2_BASEADDR
#define     TIM8_BASEADDR       (APB2_BASEADDR + 0x400)
#define     USART1_BASEADDR     (APB2_BASEADDR + 0x1000)
#define     USART6_BASEADDR     (APB2_BASEADDR + 0x1400)
#define     ADC123_BASEADDR     (APB2_BASEADDR + 0x2000)
#define     SDIO_BASEADDR       (APB2_BASEADDR + 0x2C00)
#define     SPI1_BASEADDR       (APB2_BASEADDR + 0x3000)
#define     SYSCFG_BASEADDR	    (APB2_BASEADDR + 0x3800)
#define     EXTI_BASEADDR	    (APB2_BASEADDR + 0x3C00)
#define     TIM9_BASEADDR		(APB2_BASEADDR + 0x4000)
#define     TIM10_BASEADDR		(APB2_BASEADDR + 0x4400)
#define     TIM11_BASEADDR		(APB2_BASEADDR + 0x4800)


// Base addresses of peripherals for AHB1
#define  	GPIOA_BASEADDR			 AHB1_BASEADDR      // 4002 0000
#define  	GPIOB_BASEADDR			(AHB1_BASEADDR + 0x400)  // 4002 04000
#define  	GPIOC_BASEADDR			(AHB1_BASEADDR + 0x800)
#define  	GPIOD_BASEADDR			(AHB1_BASEADDR + 0xC00)  // 0x40020000U +0C00 = 0x4002 0C00U
#define  	GPIOE_BASEADDR			(AHB1_BASEADDR + 0x1000)
#define  	GPIOF_BASEADDR			(AHB1_BASEADDR + 0x1400)
#define  	GPIOG_BASEADDR			(AHB1_BASEADDR + 0x1800)
#define  	GPIOH_BASEADDR			(AHB1_BASEADDR + 0x1C00)
#define  	GPIOI_BASEADDR			(AHB1_BASEADDR + 0x2000)
#define  	CRC_BASEADDR			(AHB1_BASEADDR + 0x3000)
#define  	RCC_BASEADDR			(AHB1_BASEADDR + 0x3800)
#define  	FLASH_BASEADDR			(AHB1_BASEADDR + 0x3C00)
#define     BKPSRAM_BASEADDR		(AHB1_BASEADDR + 0x4000)
#define  	DMA1_BASEADDR			(AHB1_BASEADDR + 0x6000)
#define  	DMA2_BASEADDR			(AHB1_BASEADDR + 0x6400)
#define  	ETHERNET1_BASEADDR		(AHB1_BASEADDR + 0x8000)
#define  	ETHERNET2_BASEADDR		(AHB1_BASEADDR + 0x8400)
#define  	ETHERNET3_BASEADDR		(AHB1_BASEADDR + 0x8800)
#define  	ETHERNET4_BASEADDR		(AHB1_BASEADDR + 0x8C00)
#define  	ETHERNET5_BASEADDR		(AHB1_BASEADDR + 0x9000)
#define     USB_OTG_HS_BASEADDR		(AHB1_BASEADDR + 0x40000)
#define     USB_OTG_FS_BASEADDR		(0x50000000U)


typedef struct
{
  volatile uint32_t CR;            /*!< TODO,     										Address offset: 0x00 */
  volatile uint32_t PLLCFGR;       /*!< TODO,     										Address offset: 0x04 */
  volatile uint32_t CFGR;          /*!< TODO,     										Address offset: 0x08 */
  volatile uint32_t CIR;           /*!< TODO,     										Address offset: 0x0C */
  volatile uint32_t AHB1RSTR;      /*!< TODO,     										Address offset: 0x10 */
  volatile uint32_t AHB2RSTR;      /*!< TODO,     										Address offset: 0x14 */
  volatile uint32_t AHB3RSTR;      /*!< TODO,     										Address offset: 0x18 */
  	  	   uint32_t RESERVED0;     /*!< Reserved, 0x1C                                                       */
  volatile uint32_t APB1RSTR;      /*!< TODO,     										Address offset: 0x20 */
  volatile uint32_t APB2RSTR;      /*!< TODO,     										Address offset: 0x24 */
           uint32_t RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                  */
  volatile uint32_t AHB1ENR;       /*!< TODO,     										Address offset: */
  volatile uint32_t AHB2ENR;       /*!< TODO,     										Address offset: 0x34 */
  volatile uint32_t AHB3ENR;       /*!< TODO,     										Address offset: 0x38 */
           uint32_t RESERVED2;     /*!< Reserved, 0x3C                                                       */
  volatile uint32_t APB1ENR;       /*!< TODO,     										Address offset: 0x40 */
  volatile uint32_t APB2ENR;       /*!< TODO,     										Address offset: 0x44 */
           uint32_t RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                  */
  volatile uint32_t AHB1LPENR;     /*!< TODO,     										Address offset: 0x50 */
  volatile uint32_t AHB2LPENR;     /*!< TODO,     										Address offset: 0x54 */
  volatile uint32_t AHB3LPENR;     /*!< TODO,     										Address offset: 0x58 */
           uint32_t RESERVED4;     /*!< Reserved, 0x5C                                                       */
  volatile uint32_t APB1LPENR;
  volatile uint32_t RCC_APB2LPENR;
  volatile uint32_t RESERVED5[2];
  volatile uint32_t RCC_BDCR;
  volatile uint32_t RCC_CSR;
  volatile uint32_t RESERVED6[2];
  volatile uint32_t RCC_SSCGR;
  volatile uint32_t RCC_PLLI2SCFGR;
 } RCC_RegDef_t;



typedef struct{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
}GPIO_RegDef_t;

#define		RCC			((RCC_RegDef_t *)(RCC_BASEADDR))

#define		GPIOA		((GPIO_RegDef_t*)GPIOA_BASEADDR) // mode: 4002 0000  otype: 4002 0004
#define		GPIOB		((GPIO_RegDef_t*)GPIOB_BASEADDR) // mode: 4002 0400 otype: 4002 0404
#define		GPIOC		((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define		GPIOD		((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define		GPIOE		((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define		GPIOF		((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define		GPIOG		((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define		GPIOH		((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define		GPIOI		((GPIO_RegDef_t*)GPIOI_BASEADDR)


#define GPIOA_CLOCK_EN()	 (RCC->AHB1ENR |= (1u<<0))
#define GPIOB_CLOCK_EN()	 (RCC->AHB1ENR |= (1u<<1))
#define GPIOC_CLOCK_EN()	 (RCC->AHB1ENR |= (1u<<2))
#define GPIOD_CLOCK_EN()	 (RCC->AHB1ENR |= (1u<<3))
#define GPIOE_CLOCK_EN()	 (RCC->AHB1ENR |= (1u<<4))
#define GPIOF_CLOCK_EN()	 (RCC->AHB1ENR |= (1u<<5))
#define GPIOG_CLOCK_EN()	 (RCC->AHB1ENR |= (1u<<6))
#define GPIOH_CLOCK_EN()	 (RCC->AHB1ENR |= (1u<<7))
#define GPIOI_CLOCK_EN()	 (RCC->AHB1ENR |= (1u<<8))

typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_RegDef_t;

typedef struct{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t RESERVED0;
	volatile uint32_t CMPCR;
}SYSCFG_RegDef_t;

#define		EXTI		((EXTI_RegDef_t*)EXTI_BASEADDR)
#define		SYSCFG		((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define	SYSCFG_CLOCK_EN()	(RCC->APB2ENR |=(1u<<14))

typedef struct{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}USART_RegDef_t;

#define		USART1		((USART_RegDef_t*)USART1_BASEADDR)
#define		USART2		((USART_RegDef_t*)USART2_BASEADDR)
#define		USART3		((USART_RegDef_t*)USART3_BASEADDR)
#define		USART4		((USART_RegDef_t*)USART4_BASEADDR)
#define		USART5		((USART_RegDef_t*)USART5_BASEADDR)
#define		USART6		((USART_RegDef_t*)USART6_BASEADDR)

#define USART1_CLOCK_EN() 	(RCC->APB2ENR |= (1U << 4))
#define USART2_CLOCK_EN()	(RCC->APB1ENR |= (1U << 17))
#define USART3_CLOCK_EN() 	(RCC->APB1ENR |= (1U << 18))
#define USART4_CLOCK_EN()	(RCC->APB1ENR |= (1U << 19))
#define USART5_CLOCK_EN() 	(RCC->APB1ENR |= (1U << 20))
#define USART6_CLOCK_EN() 	(RCC->APB2ENR |= (1U << 5))

typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SCR;
}SPI_RegDef_t;

#define		SPI1		((SPI_RegDef_t*)SPI1_BASEADDR)
#define		SPI2		((SPI_RegDef_t*)SPI2_I2S2_BASEADDR)
#define		SPI3		((SPI_RegDef_t*)SPI3_I2S3_BASEADDR)

#define SPI1_CLOCK_EN() 	(RCC->APB2ENR |= (1U << 12))
#define SPI2_CLOCK_EN()		(RCC->APB1ENR |= (1U << 14))
#define SPI3_CLOCK_EN() 	(RCC->APB1ENR |= (1U << 15))

#endif /* STM32F407XX_H_ */
