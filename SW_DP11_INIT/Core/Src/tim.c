/**
  ******************************************************************************
  * File Name          : TIM.c
  * Description        : This file provides code for the configuration
  *                      of the TIM instances.
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

/* Includes ------------------------------------------------------------------*/
#include "tim.h"

/* USER CODE BEGIN 0 */

#include "general.h"
#include "cmsis_os.h"
#include "data.h"
#include "can.h"
#include "i2c.h"

extern osSemaphoreId aux1ButtonSemaphoreHandle;
extern osSemaphoreId okButtonSemaphoreHandle;
extern osSemaphoreId startButtonSemaphoreHandle;
extern osSemaphoreId rpmStripeSemaphoreHandle;
extern osSemaphoreId sensorsSemaphoreHandle;
extern osSemaphoreId settingsModeSemaphoreHandle;
extern osSemaphoreId boardDebugModeSemaphoreHandle;
extern osSemaphoreId debugModeSemaphoreHandle;
extern osSemaphoreId enduranceModeSemaphoreHandle;
extern osSemaphoreId accelerationModeSemaphoreHandle;
extern osSemaphoreId autocrossModeSemaphoreHandle;
extern osSemaphoreId skidpadModeSemaphoreHandle;

extern char driveMode;
	
int timerSensors = 0;
int timerStartButton = 0;
int timerRpmStripe = 0;
int timerDriveMode = 0;
int timerTractionRpm = 0;
int timerEfiAlive = 0;
int timerDCUAlive = 0;
int timerTractionSave = 0;
int timerRpmLimiterSave  = 0;
int timerEmergency = 0;

int emergencyFlag = 0;
int emergencyBlink = 0;
int DCU_is_dead = 0;
int DCU_was_not_dead = 0;
int	TRACTION_save = 0;
int RPM_LIM_save 	= 0;
			

extern int d_tractionValue, d_rpmLimiterValue;

extern Indicator_Value Indicators[N_INDICATORS];	

/* USER CODE END 0 */

TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim7;
TIM_HandleTypeDef htim12;

/* TIM4 init function */
void MX_TIM4_Init(void)
{
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 5-1;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 200-1;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 50;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim4);

}
/* TIM7 init function */
void MX_TIM7_Init(void)
{
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  htim7.Instance = TIM7;
  htim7.Init.Prescaler = 9999;
  htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim7.Init.Period = 9-1;
  htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }

}
/* TIM12 init function */
void MX_TIM12_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim12.Instance = TIM12;
  htim12.Init.Prescaler = 5-1;
  htim12.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim12.Init.Period = 20000-1;
  htim12.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim12.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim12) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim12, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim12) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 8000;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim12, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim12);

}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* tim_pwmHandle)
{

  if(tim_pwmHandle->Instance==TIM4)
  {
  /* USER CODE BEGIN TIM4_MspInit 0 */

  /* USER CODE END TIM4_MspInit 0 */
    /* TIM4 clock enable */
    __HAL_RCC_TIM4_CLK_ENABLE();

    /* TIM4 interrupt Init */
    HAL_NVIC_SetPriority(TIM4_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(TIM4_IRQn);
  /* USER CODE BEGIN TIM4_MspInit 1 */

  /* USER CODE END TIM4_MspInit 1 */
  }
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM7)
  {
  /* USER CODE BEGIN TIM7_MspInit 0 */

  /* USER CODE END TIM7_MspInit 0 */
    /* TIM7 clock enable */
    __HAL_RCC_TIM7_CLK_ENABLE();

    /* TIM7 interrupt Init */
    HAL_NVIC_SetPriority(TIM7_IRQn, 11, 0);
    HAL_NVIC_EnableIRQ(TIM7_IRQn);
  /* USER CODE BEGIN TIM7_MspInit 1 */

  /* USER CODE END TIM7_MspInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM10)
  {
  /* USER CODE BEGIN TIM10_MspInit 0 */

  /* USER CODE END TIM10_MspInit 0 */
    /* TIM10 clock enable */
    __HAL_RCC_TIM10_CLK_ENABLE();
  /* USER CODE BEGIN TIM10_MspInit 1 */

  /* USER CODE END TIM10_MspInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM12)
  {
  /* USER CODE BEGIN TIM12_MspInit 0 */

  /* USER CODE END TIM12_MspInit 0 */
    /* TIM12 clock enable */
    __HAL_RCC_TIM12_CLK_ENABLE();

    /* TIM12 interrupt Init */
    HAL_NVIC_SetPriority(TIM8_BRK_TIM12_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(TIM8_BRK_TIM12_IRQn);
  /* USER CODE BEGIN TIM12_MspInit 1 */

  /* USER CODE END TIM12_MspInit 1 */
  }
}
void HAL_TIM_MspPostInit(TIM_HandleTypeDef* timHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(timHandle->Instance==TIM4)
  {
  /* USER CODE BEGIN TIM4_MspPostInit 0 */

  /* USER CODE END TIM4_MspPostInit 0 */
    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**TIM4 GPIO Configuration    
    PD12     ------> TIM4_CH1 
    */
    GPIO_InitStruct.Pin = LCD_BACKLIGHT_PWM_OUTPUT_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
    HAL_GPIO_Init(LCD_BACKLIGHT_PWM_OUTPUT_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM4_MspPostInit 1 */

  /* USER CODE END TIM4_MspPostInit 1 */
  }
  else if(timHandle->Instance==TIM12)
  {
  /* USER CODE BEGIN TIM12_MspPostInit 0 */

  /* USER CODE END TIM12_MspPostInit 0 */
  
    __HAL_RCC_GPIOH_CLK_ENABLE();
    /**TIM12 GPIO Configuration    
    PH6     ------> TIM12_CH1 
    */
    GPIO_InitStruct.Pin = BUZZER_PWM_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF9_TIM12;
    HAL_GPIO_Init(BUZZER_PWM_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM12_MspPostInit 1 */

  /* USER CODE END TIM12_MspPostInit 1 */
  }

}

void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef* tim_pwmHandle)
{

  if(tim_pwmHandle->Instance==TIM4)
  {
  /* USER CODE BEGIN TIM4_MspDeInit 0 */

  /* USER CODE END TIM4_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM4_CLK_DISABLE();

    /* TIM4 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM4_IRQn);
  /* USER CODE BEGIN TIM4_MspDeInit 1 */

  /* USER CODE END TIM4_MspDeInit 1 */
  }
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM7)
  {
  /* USER CODE BEGIN TIM7_MspDeInit 0 */

  /* USER CODE END TIM7_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM7_CLK_DISABLE();

    /* TIM7 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM7_IRQn);
  /* USER CODE BEGIN TIM7_MspDeInit 1 */

  /* USER CODE END TIM7_MspDeInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM10)
  {
  /* USER CODE BEGIN TIM10_MspDeInit 0 */

  /* USER CODE END TIM10_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM10_CLK_DISABLE();
  /* USER CODE BEGIN TIM10_MspDeInit 1 */

  /* USER CODE END TIM10_MspDeInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM12)
  {
  /* USER CODE BEGIN TIM12_MspDeInit 0 */

  /* USER CODE END TIM12_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM12_CLK_DISABLE();

    /* TIM12 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM8_BRK_TIM12_IRQn);
  /* USER CODE BEGIN TIM12_MspDeInit 1 */

  /* USER CODE END TIM12_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */

void TIM_tractionRpm_send(void){
	CAN_send(SW_TRACTION_LIMITER_GCU_ID, d_tractionValue, d_rpmLimiterValue, EMPTY, EMPTY, 2);
}

void TIM_callback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */
		
	if (htim->Instance == TIM7) {	
		
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		
		HAL_GPIO_TogglePin(DEBUG_LED_3_GPIO_Port, DEBUG_LED_3_Pin);
		timerSensors = timerSensors + 1;
		timerStartButton = timerStartButton + 1;
		timerRpmStripe = timerRpmStripe + 1;
		timerDriveMode = timerDriveMode + 1;
		timerTractionRpm = timerTractionRpm + 1;
		timerEfiAlive = timerEfiAlive + 1;
		timerDCUAlive = timerDCUAlive + 1;
		
		if ( emergencyFlag == 1 ){
			timerEmergency = timerEmergency + 1;
			emergencyBlink = 1;
		}
		if ( timerEmergency >= EMERGENCY_BLINK_TIME ){
			emergencyBlink = 0;
			//timerEmergency = 0;
			emergencyFlag = 2;
		}
		if ( timerDCUAlive >= DCU_DEAD_TIME ){
			DCU_is_dead = 1;
		}
		
		if ( timerSensors >= SENSORS_TIME ){
			xSemaphoreGiveFromISR( sensorsSemaphoreHandle, &xHigherPriorityTaskWoken );
			timerSensors = 0;	
		}
		if ( timerStartButton >= START_BUTTON_TIME){
			xSemaphoreGiveFromISR( startButtonSemaphoreHandle, &xHigherPriorityTaskWoken );	
			timerStartButton = 0;
		}
		if ( timerRpmStripe >= RPM_STRIPE_TIME ){
			xSemaphoreGiveFromISR( rpmStripeSemaphoreHandle, &xHigherPriorityTaskWoken );
			timerRpmStripe = 0;	
		}
		if ( timerTractionRpm >= TRACTION_RPM_TIME ){
			TIM_tractionRpm_send();
			timerTractionRpm = 0;
		}
		
		if ( timerEfiAlive >= EFI_DEAD_TIME ){
			 data_efiOff();
			 timerEfiAlive = 0;
		}
		if (TRACTION_save == 1 ){
			 timerTractionSave =  timerTractionSave + 1;
		}
		if (RPM_LIM_save == 1 ){
			 timerRpmLimiterSave = timerRpmLimiterSave  + 1;
		}
		if (  timerTractionSave >= TRACTION_SAVE_TIME ){
			TRACTION_save = 0;
			timerTractionSave = 0;
			I2C_save_Traction(Indicators[TRACTION_CONTROL].intValore);
		}
		if ( timerRpmLimiterSave >= RPM_LIM_SAVE_TIME ){
			RPM_LIM_save 	= 0;
			timerRpmLimiterSave = 0;
			I2C_save_RpmLimiter(Indicators[RPM_LIM].intValore);
		}
		if ( timerDriveMode >= DRIVE_MODE_TIME ){
			switch ( driveMode ){
				case SETTINGS_MODE	:
					xSemaphoreGiveFromISR( settingsModeSemaphoreHandle, &xHigherPriorityTaskWoken );
					break;
				case BOARD_DEBUG_MODE	:
					xSemaphoreGiveFromISR( boardDebugModeSemaphoreHandle, &xHigherPriorityTaskWoken );
					break;
				case DEBUG_MODE	:
					xSemaphoreGiveFromISR( debugModeSemaphoreHandle, &xHigherPriorityTaskWoken );
					break;
				case ENDURANCE_MODE	:
					xSemaphoreGiveFromISR( enduranceModeSemaphoreHandle, &xHigherPriorityTaskWoken );
					break;
				case ACCELERATION_MODE	:
					xSemaphoreGiveFromISR( accelerationModeSemaphoreHandle, &xHigherPriorityTaskWoken );
					break;
				case AUTOX_MODE	:
					xSemaphoreGiveFromISR( autocrossModeSemaphoreHandle, &xHigherPriorityTaskWoken );
					break;
				case SKIDPAD_MODE	:
					xSemaphoreGiveFromISR( skidpadModeSemaphoreHandle, &xHigherPriorityTaskWoken );
					break;
			}
			timerDriveMode = 0;
		}
		portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
  }
  /* USER CODE END Callback 1 */
}

void TIM_startTimers(void)
{
	htim12.Instance->CCR1 = htim12.Init.Period/2;
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim12, TIM_CHANNEL_1);
	
	HAL_TIM_Base_Start_IT(&htim7);
}

void TIM_stopBuzzer(void)
{
	htim12.Instance->CCR1 = 0;
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
