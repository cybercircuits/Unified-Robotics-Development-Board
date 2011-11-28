/*
 * urdb_stm32.h
 *
 *  Created on: Nov 6, 2011
 *      Author: Joe
 */

#ifndef URDB_STM32_H_
#define URDB_STM32_H_

#include <stdint.h>
#include <core_cm3.h>
#include <stm32l1xx_adc.h>
#include <stm32l1xx_dac.h>
#include <stm32l1xx_dma.h>
#include <stm32l1xx_flash.h>
#include <stm32l1xx_gpio.h>
#include <stm32l1xx_i2c.h>
#include <stm32l1xx_iwdg.h>
#include <stm32l1xx_pwr.h>
#include <stm32l1xx_rcc.h>
#include <stm32l1xx_rtc.h>
#include <stm32l1xx_spi.h>
#include <stm32l1xx_syscfg.h>
#include <stm32l1xx_tim.h>
#include <stm32l1xx_usart.h>
#include <stm32l1xx_wwdg.h>
#include <stm32l1xx.h>
#include "xmos_uart.h"

#define ARDUINO_A0_PORT		GPIOA			// ADCIN_0 = PA0
#define ARDUINO_A0_PIN		GPIO_Pin_0		// ADCIN_0 = PA0
#define ARDUINO_A0_SRC		GPIO_PinSource0
#define ARDUINO_A1_PORT		GPIOA			// ADCIN_1 = PA1
#define ARDUINO_A1_PIN		GPIO_Pin_1		// ADCIN_1 = PA1
#define ARDUINO_A1_SRC		GPIO_PinSource1
#define ARDUINO_A2_PORT		GPIOA			// ADCIN_4 = PA4
#define ARDUINO_A2_PIN		GPIO_Pin_4		// ADCIN_4 = PA4
#define ARDUINO_A2_SRC		GPIO_PinSource4
#define ARDUINO_A3_PORT		GPIOA			// ADCIN_5 = PA5
#define ARDUINO_A3_PIN		GPIO_Pin_5		// ADCIN_5 = PA5
#define ARDUINO_A3_SRC		GPIO_PinSource5
#define ARDUINO_A4_PORT		GPIOC			// ADCIN_15 = PC5
#define ARDUINO_A4_PIN		GPIO_Pin_15		// ADCIN_15 = PC5
#define ARDUINO_A4_SRC		GPIO_PinSource15
#define ARDUINO_A5_PORT		GPIOC			// ADCIN_14 = PC4
#define ARDUINO_A5_PIN		GPIO_Pin_4		// ADCIN_14 = PC4
#define ARDUINO_A5_SRC		GPIO_PinSource4

#define ARDUINO_SCL_MODE_PORT	GPIOA		// PA7
#define ARDUINO_SCL_MODE_PIN	GPIO_Pin_7	// PA7
#define ARDUINO_SDA_MODE_PORT	GPIOA		// PA6
#define ARDUINO_SDA_MODE_PIN	GPIO_Pin_6	// PA6
#define ARDUINO_SCL_PORT		GPIOB		// I2C2 SCL = PB10
#define ARDUINO_SCL_PIN			GPIO_Pin_10	// I2C2 SCL = PB10
#define ARDUINO_SCL_SRC			GPIO_PinSource10
#define ARDUINO_SDA_PORT		GPIOB		// I2C2 SDA = PB11
#define ARDUINO_SDA_PIN			GPIO_Pin_11	// I2C2 SDA = PB11
#define ARDUINO_SDA_SRC			GPIO_PinSource11

#define ARDUINO_D0_PORT		GPIOD		// U3TX = PD8
#define ARDUINO_D0_PIN		GPIO_Pin_8	// U3TX = PD8
#define ARDUINO_D1_PORT		GPIOD		// U3RX = PD9
#define ARDUINO_D1_PIN		GPIO_Pin_9	// U3RX = PD9
#define ARDUINO_D2_PORT		GPIOE		// PE14
#define ARDUINO_D2_PIN		GPIO_Pin_14	// PE14
#define ARDUINO_D3_PORT		GPIOB		// PB12
#define ARDUINO_D3_PIN		GPIO_Pin_12	// PB12
#define ARDUINO_D4_PORT		GPIOE		// PE15
#define ARDUINO_D4_PIN		GPIO_Pin_15	// PE15
#define ARDUINO_D5_PORT		GPIOB		// PB13
#define ARDUINO_D5_PIN		GPIO_Pin_13	// PB13
#define ARDUINO_D6_PORT		GPIOB		// PB14
#define ARDUINO_D6_PIN		GPIO_Pin_14	// PB14
#define ARDUINO_D7_PORT		GPIOD		// PD10
#define ARDUINO_D7_PIN		GPIO_Pin_10	// PD10
#define ARDUINO_D8_PORT		GPIOD		// PD11
#define ARDUINO_D8_PIN		GPIO_Pin_11	// PD11
#define ARDUINO_D9_PORT		GPIOD		// PD12
#define ARDUINO_D9_PIN		GPIO_Pin_12	// PD12
#define ARDUINO_D10_PORT	GPIOD		// SPI2_NSS = PD0
#define ARDUINO_D10_PIN		GPIO_Pin_0	// SPI2_NSS = PD0
#define ARDUINO_D11_PORT	GPIOB		// SPI2_MOSI = PB15
#define ARDUINO_D11_PIN		GPIO_Pin_15	// SPI2_MOSI = PB15
#define ARDUINO_D12_PORT	GPIOD		// SPI2_MISO = PD3
#define ARDUINO_D12_PIN		GPIO_Pin_3	// SPI2_MISO = PD3
#define ARDUINO_D13_PORT	GPIOD		// SPI2_SCK = PD1
#define ARDUINO_D13_PIN		GPIO_Pin_1	// SPI2_SCK = PD1

#define XMOS_TIM_PORT	GPIOB		// TIM3_CH2 = PB5
#define XMOS_TIM_PIN	GPIO_Pin_5	// TIM3_CH2 = PB5
#define XMOS_TIM_SRC	GPIO_PinSource5
#define XMOS_TX_PORT	GPIOB		// U1TX = PB6
#define XMOS_TX_PIN		GPIO_Pin_6	// U1TX = PB6
#define XMOS_RX_PORT	GPIOB		// U1RX = PB7
#define XMOS_RX_PIN		GPIO_Pin_7	// U1RX = PB7

#define M0_ADC_PORT		GPIOB		// ADCIN_8 = PB0
#define M0_ADC_PIN		GPIO_Pin_0	// ADCIN_8 = PB0
#define M0_ADC_SRC		GPIO_PinSource0
#define M1_ADC_PORT		GPIOB		// ADCIN_9 = PB1
#define M1_ADC_PIN		GPIO_Pin_1	// ADCIN_9 = PB1
#define M1_ADC_SRC		GPIO_PinSource1
#define M2_ADC_PORT		GPIOE		// ADCIN_22 = PE7
#define M2_ADC_PIN		GPIO_Pin_7	// ADCIN_22 = PE7
#define M2_ADC_SRC		GPIO_PinSource7

#define EXT_ADC_0_PORT	GPIOC		// ADCIN_10 = PC0
#define EXT_ADC_0_PIN	GPIO_Pin_0	// ADCIN_10 = PC0
#define EXT_ADC_0_SRC	GPIO_PinSource0
#define EXT_ADC_1_PORT	GPIOC		// ADCIN_11 = PC1
#define EXT_ADC_1_PIN	GPIO_Pin_1	// ADCIN_11 = PC1
#define EXT_ADC_1_SRC	GPIO_PinSource1
#define EXT_ADC_2_PORT	GPIOC		// ADCIN_12 = PC2
#define EXT_ADC_2_PIN	GPIO_Pin_2	// ADCIN_12 = PC2
#define EXT_ADC_2_SRC	GPIO_PinSource2
#define EXT_ADC_3_PORT	GPIOC		// ADCIN_13 = PC3
#define EXT_ADC_3_PIN	GPIO_Pin_3	// ADCIN_13 = PC3
#define EXT_ADC_3_SRC	GPIO_PinSource3
#endif /* URDB_STM32_H_ */
