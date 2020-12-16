/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2019 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_RESET_Pin GPIO_PIN_11
#define LCD_RESET_GPIO_Port GPIOI
#define ENC_RIGHT_1_INT_Pin GPIO_PIN_0
#define ENC_RIGHT_1_INT_GPIO_Port GPIOC
#define ENC_RIGHT_1_INT_EXTI_IRQn EXTI0_IRQn
#define ENC_RIGHT_2_Pin GPIO_PIN_1
#define ENC_RIGHT_2_GPIO_Port GPIOC
#define ENC_RIGHT_4_Pin GPIO_PIN_2
#define ENC_RIGHT_4_GPIO_Port GPIOC
#define ENC_RIGHT_8_Pin GPIO_PIN_3
#define ENC_RIGHT_8_GPIO_Port GPIOC
#define TEMP_SENSOR_Pin GPIO_PIN_0
#define TEMP_SENSOR_GPIO_Port GPIOA
#define ENC_LEFT_1_INT_Pin GPIO_PIN_1
#define ENC_LEFT_1_INT_GPIO_Port GPIOA
#define ENC_LEFT_1_INT_EXTI_IRQn EXTI1_IRQn
#define ENC_LEFT_2_Pin GPIO_PIN_2
#define ENC_LEFT_2_GPIO_Port GPIOA
#define ENC_LEFT_4_Pin GPIO_PIN_2
#define ENC_LEFT_4_GPIO_Port GPIOH
#define ENC_LEFT_8_Pin GPIO_PIN_3
#define ENC_LEFT_8_GPIO_Port GPIOH
#define CLUTCH_ANALOG_INPUT_Pin GPIO_PIN_3
#define CLUTCH_ANALOG_INPUT_GPIO_Port GPIOA
#define SPI_NSS_Pin GPIO_PIN_4
#define SPI_NSS_GPIO_Port GPIOA
#define SW_CURRENT_SENSE_Pin GPIO_PIN_6
#define SW_CURRENT_SENSE_GPIO_Port GPIOA
#define BUZZER_PWM_Pin GPIO_PIN_6
#define BUZZER_PWM_GPIO_Port GPIOH
#define SEL_MODE_4_Pin GPIO_PIN_12
#define SEL_MODE_4_GPIO_Port GPIOB
#define SEL_MODE_8_Pin GPIO_PIN_13
#define SEL_MODE_8_GPIO_Port GPIOB
#define SEL_MODE_1_INT_Pin GPIO_PIN_14
#define SEL_MODE_1_INT_GPIO_Port GPIOB
#define SEL_MODE_1_INT_EXTI_IRQn EXTI15_10_IRQn
#define SEL_MODE_2_Pin GPIO_PIN_15
#define SEL_MODE_2_GPIO_Port GPIOB
#define START_BUTTON_INT_Pin GPIO_PIN_11
#define START_BUTTON_INT_GPIO_Port GPIOD
#define START_BUTTON_INT_EXTI_IRQn EXTI15_10_IRQn
#define LCD_BACKLIGHT_PWM_OUTPUT_Pin GPIO_PIN_12
#define LCD_BACKLIGHT_PWM_OUTPUT_GPIO_Port GPIOD
#define AUX_3_BUTTON_INT_Pin GPIO_PIN_13
#define AUX_3_BUTTON_INT_GPIO_Port GPIOD
#define AUX_3_BUTTON_INT_EXTI_IRQn EXTI15_10_IRQn
#define SHIFT_DOWN_INT_Pin GPIO_PIN_2
#define SHIFT_DOWN_INT_GPIO_Port GPIOG
#define SHIFT_DOWN_INT_EXTI_IRQn EXTI2_IRQn
#define SHIFT_UP_INT_Pin GPIO_PIN_3
#define SHIFT_UP_INT_GPIO_Port GPIOG
#define SHIFT_UP_INT_EXTI_IRQn EXTI3_IRQn
#define NEUTRAL_BUTTON_INT_Pin GPIO_PIN_6
#define NEUTRAL_BUTTON_INT_GPIO_Port GPIOC
#define NEUTRAL_BUTTON_INT_EXTI_IRQn EXTI9_5_IRQn
#define OK_BUTTON_INT_Pin GPIO_PIN_7
#define OK_BUTTON_INT_GPIO_Port GPIOC
#define OK_BUTTON_INT_EXTI_IRQn EXTI9_5_IRQn
#define AUX_1_BUTTON_INT_Pin GPIO_PIN_8
#define AUX_1_BUTTON_INT_GPIO_Port GPIOA
#define AUX_1_BUTTON_INT_EXTI_IRQn EXTI9_5_IRQn
#define AUX_2_BUTTON_INT_Pin GPIO_PIN_9
#define AUX_2_BUTTON_INT_GPIO_Port GPIOA
#define AUX_2_BUTTON_INT_EXTI_IRQn EXTI9_5_IRQn
#define SEL_MAP_2_Pin GPIO_PIN_15
#define SEL_MAP_2_GPIO_Port GPIOA
#define SEL_MAP_1_INT_Pin GPIO_PIN_10
#define SEL_MAP_1_INT_GPIO_Port GPIOC
#define SEL_MAP_1_INT_EXTI_IRQn EXTI15_10_IRQn
#define SEL_MAP_4_Pin GPIO_PIN_11
#define SEL_MAP_4_GPIO_Port GPIOC
#define SEL_MAP_8_Pin GPIO_PIN_12
#define SEL_MAP_8_GPIO_Port GPIOC
#define DEBUG_LED_3_Pin GPIO_PIN_3
#define DEBUG_LED_3_GPIO_Port GPIOD
#define DEBUG_LED_2_Pin GPIO_PIN_4
#define DEBUG_LED_2_GPIO_Port GPIOD
#define DEBUG_LED_1_Pin GPIO_PIN_5
#define DEBUG_LED_1_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

#define	SIM_MODE

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
