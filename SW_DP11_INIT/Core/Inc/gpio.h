/**
  ******************************************************************************
  * File Name          : gpio.h
  * Description        : This file contains all the functions prototypes for 
  *                      the gpio  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
 
/***************** SELECTORS AND ENCODERS *************************************/

typedef struct encoder_position
{
	char pin1;
	char pin2;
	char pin4;
} encoder_position;

void GPIO_encoders_init(void);
void GPIO_driveMode_set(void);
void GPIO_map_set(void);

int GPIO_leftEncoder_movement(void);
void GPIO_leftEncoder_boardDebugMode(int movement);
void GPIO_leftEncoder_debugMode(int movement);
void GPIO_leftEncoder_settingsMode(int movement);

int GPIO_rightEncoder_movement(void);
void GPIO_rightEncoder_boardDebugMode(int movement);
void GPIO_rightEncoder_debugMode(int movement);
void GPIO_rightEncoder_settingsMode(int movement);

/******************************************************************************/

void GPIO_okButton_handle(void);
void GPIO_aux1Button_handle(void);
void GPIO_aux2Button_handle(void);
void GPIO_neutralButton_handle(void);
void GPIO_startButton_handle(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
