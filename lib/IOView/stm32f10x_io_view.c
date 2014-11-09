/*
 Peripheral View Magic for stm32f10x
 Ver.0.1 (2010/08)

 Copyright (c) 2010, audin
 All rights reserved.

 http://avr.paslog.jp
 

This code is licensed under the BSD License.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditionsare met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holders nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
THE POSSIBILITY OF SUCH DAMAGE.
*/

/* 20110510 Nemui-San Added GPIO(ODR&IDR ONLY) Bitfield Definitions */
/* 20110924 Nemui-San Added IOVIEW Sections */


#include "stm32f10x.h"

#define PRE_TYPE1 volatile
#define PRE_TYPE2 const
#define PRE_TYPE3 __attribute__ ((section(".ioview")))

#define IO_VIEW_ALL



//#define IO_TIM2_EN
//#define IO_TIM3_EN
//#define IO_TIM4_EN
//#define IO_TIM5_EN
//#define IO_TIM6_EN
//#define IO_TIM7_EN
//#define IO_RTC_EN
//#define IO_WWDG_EN
//#define IO_IWDG_EN
//#define IO_SPI2_EN
//#define IO_SPI3_EN
//#define IO_USART2_EN
//#define IO_USART3_EN
//#define IO_UART4_EN
//#define IO_UART5_EN
//#define IO_I2C1_EN
//#define IO_I2C2_EN
//#define IO_CAN1_EN
//#define IO_CAN2_EN
//#define IO_BKP_EN
//#define IO_PWR_EN
//#define IO_DAC_EN
//#define IO_AFIO_EN
//#define IO_EXTI_EN
//#define IO_GPIOA_EN
//#define IO_GPIOB_EN
//#define IO_GPIOC_EN
//#define IO_GPIOD_EN
//#define IO_GPIOE_EN
//#define IO_GPIOF_EN
//#define IO_GPIOG_EN
//#define IO_ADC1_EN
//#define IO_ADC2_EN
//#define IO_TIM1_EN
//#define IO_SPI1_EN
//#define IO_TIM8_EN
//#define IO_USART1_EN
//#define IO_ADC3_EN
//#define IO_SDIO_EN
//#define IO_DMA1_EN
//#define IO_DMA2_EN
//#define IO_DMA1_Channel1_EN
//#define IO_DMA1_Channel2_EN
//#define IO_DMA1_Channel3_EN
//#define IO_DMA1_Channel4_EN
//#define IO_DMA1_Channel5_EN
//#define IO_DMA1_Channel6_EN
//#define IO_DMA1_Channel7_EN
//#define IO_DMA2_Channel1_EN
//#define IO_DMA2_Channel2_EN
//#define IO_DMA2_Channel3_EN
//#define IO_DMA2_Channel4_EN
//#define IO_DMA2_Channel5_EN
//#define IO_RCC_EN
//#define IO_CRC_EN
//#define IO_FLASH_EN
//#define IO_OB_EN
//#define IO_ETH_EN
//#define IO_FSMC_Bank1_EN
//#define IO_FSMC_Bank1E_EN
//#define IO_FSMC_Bank2_EN
//#define IO_FSMC_Bank3_EN
//#define IO_FSMC_Bank4_EN
//#define IO_DBGMCU_EN


/*----------------------------------------------------------*/
typedef union GPIODATA_t {

	__IO uint16_t DUMMY;
	struct {
		__IO	uint16_t DR_00:	1;
		__IO	uint16_t DR_01:	1;
		__IO	uint16_t DR_02:	1;
		__IO	uint16_t DR_03:	1;
		__IO	uint16_t DR_04:	1;
		__IO	uint16_t DR_05:	1;
		__IO	uint16_t DR_06:	1;
		__IO	uint16_t DR_07:	1;
		__IO	uint16_t DR_08:	1;
		__IO	uint16_t DR_09:	1;
		__IO	uint16_t DR_10:	1;
		__IO	uint16_t DR_11:	1;
		__IO	uint16_t DR_12:	1;
		__IO	uint16_t DR_13:	1;
		__IO	uint16_t DR_14:	1;
		__IO	uint16_t DR_15:	1;
	} b_DR;
} GPIODATA_t;


/*----------------------------------------------------------*/

#if defined( IO_TIM2_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 TIM_TypeDef * PRE_TYPE2 IO_TIM2 PRE_TYPE3 = TIM2;
#endif

#if defined( IO_TIM3_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 TIM_TypeDef * PRE_TYPE2 IO_TIM3 PRE_TYPE3 = TIM3;
#endif

#if defined( IO_TIM4_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 TIM_TypeDef * PRE_TYPE2 IO_TIM4 PRE_TYPE3 = TIM4;
#endif

#if defined( IO_TIM5_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 TIM_TypeDef * PRE_TYPE2 IO_TIM5 PRE_TYPE3 = TIM5;
#endif

#if defined( IO_TIM6_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 TIM_TypeDef * PRE_TYPE2 IO_TIM6 PRE_TYPE3 = TIM6;
#endif

#if defined( IO_TIM7_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 TIM_TypeDef * PRE_TYPE2 IO_TIM7 PRE_TYPE3 = TIM7;
#endif

#if defined( IO_RTC_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 RTC_TypeDef * PRE_TYPE2 IO_RTC PRE_TYPE3 = RTC;
#endif

#if defined( IO_WWDG_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 WWDG_TypeDef * PRE_TYPE2 IO_WWDG PRE_TYPE3 = WWDG;
#endif

#if defined( IO_IWDG_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 IWDG_TypeDef * PRE_TYPE2 IO_IWDG PRE_TYPE3 = IWDG;
#endif

#if defined( IO_SPI2_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 SPI_TypeDef * PRE_TYPE2 IO_SPI2 PRE_TYPE3 = SPI2;
#endif

#if defined( IO_SPI3_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 SPI_TypeDef * PRE_TYPE2 IO_SPI3 PRE_TYPE3 = SPI3;
#endif

#if defined( IO_USART2_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 USART_TypeDef * PRE_TYPE2 IO_USART2 PRE_TYPE3 = USART2;
#endif

#if defined( IO_USART3_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 USART_TypeDef * PRE_TYPE2 IO_USART3 PRE_TYPE3 = USART3;
#endif

#if defined( IO_UART4_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 USART_TypeDef * PRE_TYPE2 IO_UART4 PRE_TYPE3 = UART4;
#endif

#if defined( IO_UART5_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 USART_TypeDef * PRE_TYPE2 IO_UART5 PRE_TYPE3 = UART5;
#endif

#if defined( IO_I2C1_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 I2C_TypeDef * PRE_TYPE2 IO_I2C1 PRE_TYPE3 = I2C1;
#endif

#if defined( IO_I2C2_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 I2C_TypeDef * PRE_TYPE2 IO_I2C2 PRE_TYPE3 = I2C2;
#endif

#if defined( IO_CAN1_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 CAN_TypeDef * PRE_TYPE2 IO_CAN1 PRE_TYPE3 = CAN1;
#endif

#if defined( IO_CAN2_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 CAN_TypeDef * PRE_TYPE2 IO_CAN2 PRE_TYPE3 = CAN2;
#endif

#if defined( IO_BKP_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 BKP_TypeDef * PRE_TYPE2 IO_BKP PRE_TYPE3 = BKP;
#endif

#if defined( IO_PWR_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 PWR_TypeDef * PRE_TYPE2 IO_PWR PRE_TYPE3 = PWR;
#endif

#if defined( IO_DAC_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DAC_TypeDef * PRE_TYPE2 IO_DAC PRE_TYPE3 = DAC;
#endif

#if defined( IO_AFIO_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 AFIO_TypeDef * PRE_TYPE2 IO_AFIO PRE_TYPE3 = AFIO;
#endif

#if defined( IO_EXTI_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 EXTI_TypeDef * PRE_TYPE2 IO_EXTI PRE_TYPE3 = EXTI;
#endif

#if defined( IO_GPIOA_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 GPIO_TypeDef * PRE_TYPE2 IO_GPIOA PRE_TYPE3 = GPIOA;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOA_IDR PRE_TYPE3 = (GPIODATA_t *)&GPIOA->IDR;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOA_ODR PRE_TYPE3 = (GPIODATA_t *)&GPIOA->ODR;
#endif

#if defined( IO_GPIOB_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 GPIO_TypeDef * PRE_TYPE2 IO_GPIOB PRE_TYPE3 = GPIOB;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOB_IDR PRE_TYPE3 = (GPIODATA_t *)&GPIOB->IDR;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOB_ODR PRE_TYPE3 = (GPIODATA_t *)&GPIOB->ODR;
#endif

#if defined( IO_GPIOC_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 GPIO_TypeDef * PRE_TYPE2 IO_GPIOC PRE_TYPE3 = GPIOC;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOC_IDR PRE_TYPE3 = (GPIODATA_t *)&GPIOC->IDR;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOC_ODR PRE_TYPE3 = (GPIODATA_t *)&GPIOC->ODR;
#endif

#if defined( IO_GPIOD_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 GPIO_TypeDef * PRE_TYPE2 IO_GPIOD PRE_TYPE3 = GPIOD;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOD_IDR PRE_TYPE3 = (GPIODATA_t *)&GPIOD->IDR;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOD_ODR PRE_TYPE3 = (GPIODATA_t *)&GPIOD->ODR;
#endif

#if defined( IO_GPIOE_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 GPIO_TypeDef * PRE_TYPE2 IO_GPIOE PRE_TYPE3 = GPIOE;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOE_IDR PRE_TYPE3 = (GPIODATA_t *)&GPIOE->IDR;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOE_ODR PRE_TYPE3 = (GPIODATA_t *)&GPIOE->ODR;
#endif

#if defined( IO_GPIOF_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 GPIO_TypeDef * PRE_TYPE2 IO_GPIOF PRE_TYPE3 = GPIOF;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOF_IDR PRE_TYPE3 = (GPIODATA_t *)&GPIOF->IDR;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOF_ODR PRE_TYPE3 = (GPIODATA_t *)&GPIOF->ODR;
#endif

#if defined( IO_GPIOG_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 GPIO_TypeDef * PRE_TYPE2 IO_GPIOG PRE_TYPE3 = GPIOG;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOG_IDR PRE_TYPE3 = (GPIODATA_t *)&GPIOG->IDR;
	PRE_TYPE1 GPIODATA_t * PRE_TYPE2 IO_GPIOG_ODR PRE_TYPE3 = (GPIODATA_t *)&GPIOG->ODR;
#endif

#if defined( IO_ADC1_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 ADC_TypeDef * PRE_TYPE2 IO_ADC1 PRE_TYPE3 = ADC1;
#endif

#if defined( IO_ADC2_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 ADC_TypeDef * PRE_TYPE2 IO_ADC2 PRE_TYPE3 = ADC2;
#endif

#if defined( IO_TIM1_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 TIM_TypeDef * PRE_TYPE2 IO_TIM1 PRE_TYPE3 = TIM1;
#endif

#if defined( IO_SPI1_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 SPI_TypeDef * PRE_TYPE2 IO_SPI1 PRE_TYPE3 = SPI1;
#endif

#if defined( IO_TIM8_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 TIM_TypeDef * PRE_TYPE2 IO_TIM8 PRE_TYPE3 = TIM8;
#endif

#if defined( IO_USART1_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 USART_TypeDef * PRE_TYPE2 IO_USART1 PRE_TYPE3 = USART1;
#endif

#if defined( IO_ADC3_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 ADC_TypeDef * PRE_TYPE2 IO_ADC3 PRE_TYPE3 = ADC3;
#endif

#if defined( IO_SDIO_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 SDIO_TypeDef * PRE_TYPE2 IO_SDIO PRE_TYPE3 = SDIO;
#endif

#if defined( IO_DMA1_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_TypeDef * PRE_TYPE2 IO_DMA1 PRE_TYPE3 = DMA1;
#endif

#if defined( IO_DMA2_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_TypeDef * PRE_TYPE2 IO_DMA2 PRE_TYPE3 = DMA2;
#endif

#if defined( IO_DMA1_Channel1_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_Channel_TypeDef * PRE_TYPE2 IO_DMA1_Channel1 PRE_TYPE3 = DMA1_Channel1;
#endif

#if defined( IO_DMA1_Channel2_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_Channel_TypeDef * PRE_TYPE2 IO_DMA1_Channel2 PRE_TYPE3 = DMA1_Channel2;
#endif

#if defined( IO_DMA1_Channel3_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_Channel_TypeDef * PRE_TYPE2 IO_DMA1_Channel3 PRE_TYPE3 = DMA1_Channel3;
#endif

#if defined( IO_DMA1_Channel4_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_Channel_TypeDef * PRE_TYPE2 IO_DMA1_Channel4 PRE_TYPE3 = DMA1_Channel4;
#endif

#if defined( IO_DMA1_Channel5_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_Channel_TypeDef * PRE_TYPE2 IO_DMA1_Channel5 PRE_TYPE3 = DMA1_Channel5;
#endif

#if defined( IO_DMA1_Channel6_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_Channel_TypeDef * PRE_TYPE2 IO_DMA1_Channel6 PRE_TYPE3 = DMA1_Channel6;
#endif

#if defined( IO_DMA1_Channel7_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_Channel_TypeDef * PRE_TYPE2 IO_DMA1_Channel7 PRE_TYPE3 = DMA1_Channel7;
#endif

#if defined( IO_DMA2_Channel1_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_Channel_TypeDef * PRE_TYPE2 IO_DMA2_Channel1 PRE_TYPE3 = DMA2_Channel1;
#endif

#if defined( IO_DMA2_Channel2_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_Channel_TypeDef * PRE_TYPE2 IO_DMA2_Channel2 PRE_TYPE3 = DMA2_Channel2;
#endif

#if defined( IO_DMA2_Channel3_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_Channel_TypeDef * PRE_TYPE2 IO_DMA2_Channel3 PRE_TYPE3 = DMA2_Channel3;
#endif

#if defined( IO_DMA2_Channel4_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_Channel_TypeDef * PRE_TYPE2 IO_DMA2_Channel4 PRE_TYPE3 = DMA2_Channel4;
#endif

#if defined( IO_DMA2_Channel5_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DMA_Channel_TypeDef * PRE_TYPE2 IO_DMA2_Channel5 PRE_TYPE3 = DMA2_Channel5;
#endif

#if defined( IO_RCC_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 RCC_TypeDef * PRE_TYPE2 IO_RCC PRE_TYPE3 = RCC;
#endif

#if defined( IO_CRC_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 CRC_TypeDef * PRE_TYPE2 IO_CRC PRE_TYPE3 = CRC;
#endif

#if defined( IO_FLASH_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 FLASH_TypeDef * PRE_TYPE2 IO_FLASH PRE_TYPE3 = FLASH;
#endif

#if defined( IO_OB_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 OB_TypeDef * PRE_TYPE2 IO_OB PRE_TYPE3 = OB;
#endif

#if defined( IO_ETH_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 ETH_TypeDef * PRE_TYPE2 IO_ETH PRE_TYPE3 = ETH;
#endif

#if defined( IO_FSMC_Bank1_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 FSMC_Bank1_TypeDef * PRE_TYPE2 IO_FSMC_Bank1 PRE_TYPE3 = FSMC_Bank1;
#endif

#if defined( IO_FSMC_Bank1E_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 FSMC_Bank1E_TypeDef * PRE_TYPE2 IO_FSMC_Bank1E PRE_TYPE3 = FSMC_Bank1E;
#endif

#if defined( IO_FSMC_Bank2_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 FSMC_Bank2_TypeDef * PRE_TYPE2 IO_FSMC_Bank2 PRE_TYPE3 = FSMC_Bank2;
#endif

#if defined( IO_FSMC_Bank3_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 FSMC_Bank3_TypeDef * PRE_TYPE2 IO_FSMC_Bank3 PRE_TYPE3 = FSMC_Bank3;
#endif

#if defined( IO_FSMC_Bank4_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 FSMC_Bank4_TypeDef * PRE_TYPE2 IO_FSMC_Bank4 PRE_TYPE3 = FSMC_Bank4;
#endif

#if defined( IO_DBGMCU_EN ) || defined( IO_VIEW_ALL )
	PRE_TYPE1 DBGMCU_TypeDef * PRE_TYPE2 IO_DBGMCU PRE_TYPE3 = DBGMCU;
#endif



/*-------------------------- end --------------------------------*/

