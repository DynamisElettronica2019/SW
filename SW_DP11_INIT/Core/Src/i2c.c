/**
  ******************************************************************************
  * File Name          : I2C.c
  * Description        : This file provides code for the configuration
  *                      of the I2C instances.
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
#include "i2c.h"

/* USER CODE BEGIN 0 */

	uint8_t i2cData[2];

	int RPM = 0;		//RPM = *indirizzo_della_matrice_degli_rpm;
/* USER CODE END 0 */

I2C_HandleTypeDef hi2c1;

/* I2C1 init function */
void MX_I2C1_Init(void)
{

  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00606092;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /**Configure Analogue filter 
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /**Configure Digital filter 
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_I2C_MspInit(I2C_HandleTypeDef* i2cHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(i2cHandle->Instance==I2C1)
  {
  /* USER CODE BEGIN I2C1_MspInit 0 */

  /* USER CODE END I2C1_MspInit 0 */
  
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**I2C1 GPIO Configuration    
    PB7     ------> I2C1_SDA
    PB8     ------> I2C1_SCL 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* I2C1 clock enable */
    __HAL_RCC_I2C1_CLK_ENABLE();

    /* I2C1 interrupt Init */
    HAL_NVIC_SetPriority(I2C1_EV_IRQn, 14, 0);
    HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
    HAL_NVIC_SetPriority(I2C1_ER_IRQn, 14, 0);
    HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);
  /* USER CODE BEGIN I2C1_MspInit 1 */

  /* USER CODE END I2C1_MspInit 1 */
  }
}

void HAL_I2C_MspDeInit(I2C_HandleTypeDef* i2cHandle)
{

  if(i2cHandle->Instance==I2C1)
  {
  /* USER CODE BEGIN I2C1_MspDeInit 0 */

  /* USER CODE END I2C1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C1_CLK_DISABLE();
  
    /**I2C1 GPIO Configuration    
    PB7     ------> I2C1_SDA
    PB8     ------> I2C1_SCL 
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_7|GPIO_PIN_8);

    /* I2C1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(I2C1_EV_IRQn);
    HAL_NVIC_DisableIRQ(I2C1_ER_IRQn);
  /* USER CODE BEGIN I2C1_MspDeInit 1 */

  /* USER CODE END I2C1_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */

void I2C_brightness_max (uint16_t controller){

	i2cData[1] = 0xAA;
	
	i2cData[0] = 0x07; 	 
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	i2cData[0] = 0x08; 	 	
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	i2cData[0] = 0x09; 	 	
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	i2cData[0] = 0x0A; 	 		
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	i2cData[0] = 0x0B; 	 	
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	i2cData[0] = 0x0C; 	 	
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	i2cData[0] = 0x0D; 	 		
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	i2cData[0] = 0x0E; 	 	
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	return;
}
	
void I2C_controller_0_ON(void){
	
	i2cData[0] = 0x27; 	// registro - reset
	i2cData[1] = 0xFF;		// dati
	HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x00; 	
	i2cData[1] = 0x40;	
	HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x01; 	 
	i2cData[1] = 0x00;		
	HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x02; 	 
	i2cData[1] = 0x00;		
	HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	
	I2C_brightness_max (controller_0);
	return ;
}

void I2C_controller_1_ON(void){
	
	i2cData[0] = 0x27; 	// registro - reset
	i2cData[1] = 0xFF;		// dati
	HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x00; 
	i2cData[1] = 0x40;		
	HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x01; 	
	i2cData[1] = 0x00;		
	HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x02; 	
	i2cData[1] = 0x00;		
	HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	
	I2C_brightness_max (controller_1);
	return ;
}

void I2C_debug_red_on(uint16_t controller){
	
	i2cData[1] = 0xFF;
	
	i2cData[0] = 0x0F;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x12;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	i2cData[0] = 0x15;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	i2cData[0] = 0x18;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x1B;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x1E;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	return;
}
void I2C_debug_green_on(uint16_t controller){
	
	i2cData[1] = 0xFF;
	
	i2cData[0] = 0x10;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);	
	
	i2cData[0] = 0x13;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x16;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x19;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x1C;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x1F;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	return;
}
void I2C_debug_blue_on(uint16_t controller){
	
	i2cData[1] = 0xFF;
	
	i2cData[0] = 0x11;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	
	i2cData[0] = 0x14;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x17;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x1A;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x1D;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x20;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	return;
}

void I2C_debug_red_off(uint16_t controller){
	
	i2cData[1] = 0x00;
	
	i2cData[0] = 0x0F;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x12;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	i2cData[0] = 0x15;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	i2cData[0] = 0x18;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x1B;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x1E;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	return;
}
void I2C_debug_green_off(uint16_t controller){
	
	i2cData[1] = 0x00;
	
	i2cData[0] = 0x10;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);	
	
	i2cData[0] = 0x13;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x16;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x19;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x1C;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x1F;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	return;
}
void I2C_debug_blue_off(uint16_t controller){
	
	i2cData[1] = 0x00;
	
	i2cData[0] = 0x11;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	
	i2cData[0] = 0x14;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x17;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x1A;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x1D;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = 0x20;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	return;
}

void I2C_rpm_update(void){ 

	
	if (RPM > 700){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_1_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_1_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	
	if (RPM > 1700){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_2_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_2_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	
	if (RPM > 2700){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_3_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_3_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	
	if (RPM > 3700){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_4_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_4_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	
	if (RPM > 4700){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_5_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_5_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	
	if (RPM > 5700){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_6_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_6_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	
	
	if (RPM > 6700){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_1_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_1_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	
	if (RPM > 7700){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_2_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_2_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	
	if (RPM > 8700){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_3_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_3_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	
	if (RPM > 9700){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_4_BLUE;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_4_BLUE;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	
	if (RPM > 10700){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_5_BLUE;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_5_BLUE;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	
	if (RPM > 11700){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_6_BLUE;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_6_BLUE;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	
	return ;
}
void I2C_test(void){
	
	I2C_debug_green_off(controller_0);
	I2C_debug_blue_off(controller_1);
	I2C_debug_red_on(controller_0);
	I2C_debug_green_on(controller_1);
	HAL_Delay(332);
	I2C_debug_red_off(controller_0);
	I2C_debug_green_off(controller_1);
	HAL_Delay(1);
	I2C_debug_blue_on(controller_0);
	I2C_debug_red_on(controller_1);
	HAL_Delay(332);
	I2C_debug_blue_off(controller_0);
	I2C_debug_red_off(controller_1);	
	HAL_Delay(1);
	I2C_debug_green_on(controller_0);
	I2C_debug_blue_on(controller_1);
	return;
}
void I2C_rpm_setup (void) {
	HAL_GPIO_WritePin(DEBUG_LED_3_GPIO_Port, DEBUG_LED_3_Pin, GPIO_PIN_SET);
	I2C_controller_0_ON();
	I2C_controller_1_ON();
	//HAL_Delay(5000);
	HAL_GPIO_WritePin(DEBUG_LED_3_GPIO_Port, DEBUG_LED_3_Pin, GPIO_PIN_RESET);
	return;
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
