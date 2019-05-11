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

extern uint8_t EndPointer[6], AccPointer[6], AutPointer[6], SkiPointer[6];

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

void I2C_eeprom_write (uint8_t indicatorAddress, uint16_t memAddress) {
	
	HAL_GPIO_WritePin(DEBUG_LED_3_GPIO_Port, DEBUG_LED_3_Pin, GPIO_PIN_SET);
	
	HAL_I2C_Mem_Write(&hi2c1, EEPROM_ADDRESS, memAddress, I2C_MEMADD_SIZE_8BIT, &indicatorAddress, sizeof(uint8_t), 100);
	//HAL_Delay (10);
	return;
}

uint8_t I2C_eeprom_read (uint16_t memAddress) {
	
	HAL_GPIO_WritePin(DEBUG_LED_3_GPIO_Port, DEBUG_LED_3_Pin, GPIO_PIN_RESET);
	
	uint8_t indicatore;
	HAL_I2C_Mem_Read(&hi2c1, EEPROM_ADDRESS, memAddress, I2C_MEMADD_SIZE_8BIT, &indicatore, sizeof(uint8_t), 100);
	return indicatore;
}

void I2C_save_endPointers(void){
	I2C_eeprom_write (EndPointer[0], End_0);
	I2C_eeprom_write (EndPointer[1], End_1);
	I2C_eeprom_write (EndPointer[2], End_2);
	I2C_eeprom_write (EndPointer[3], End_3);
	I2C_eeprom_write (EndPointer[4], End_4);
	I2C_eeprom_write (EndPointer[5], End_5);
}

void I2C_save_accPointers(void){
	I2C_eeprom_write (AccPointer[0], Acc_0);
	I2C_eeprom_write (AccPointer[1], Acc_1);
	I2C_eeprom_write (AccPointer[2], Acc_2);
	I2C_eeprom_write (AccPointer[3], Acc_3);
	I2C_eeprom_write (AccPointer[4], Acc_4);
	I2C_eeprom_write (AccPointer[5], Acc_5);
}

void I2C_save_autPointers(void){
	I2C_eeprom_write (AutPointer[0], Aut_0);
	I2C_eeprom_write (AutPointer[1], Aut_1);
	I2C_eeprom_write (AutPointer[2], Aut_2);
	I2C_eeprom_write (AutPointer[3], Aut_3);
	I2C_eeprom_write (AutPointer[4], Aut_4);
	I2C_eeprom_write (AutPointer[5], Aut_5);
}

void I2C_save_skiPointers(void){
	I2C_eeprom_write (SkiPointer[0], Ski_0);
	I2C_eeprom_write (SkiPointer[1], Ski_1);
	I2C_eeprom_write (SkiPointer[2], Ski_2);
	I2C_eeprom_write (SkiPointer[3], Ski_3);
	I2C_eeprom_write (SkiPointer[4], Ski_4);
	I2C_eeprom_write (SkiPointer[5], Ski_5);
}

void I2C_get_endPointers(void){
	EndPointer[0] = I2C_eeprom_read (End_0);
	EndPointer[1] = I2C_eeprom_read (End_1);
	EndPointer[2] = I2C_eeprom_read (End_2);
	EndPointer[3] = I2C_eeprom_read (End_3);
	EndPointer[4] = I2C_eeprom_read (End_4);
	EndPointer[5] = I2C_eeprom_read (End_5);
}

void I2C_get_accPointers(void){
	AccPointer[0] = I2C_eeprom_read (Acc_0);
	AccPointer[1] = I2C_eeprom_read (Acc_1);
	AccPointer[2] = I2C_eeprom_read (Acc_2);
	AccPointer[3] = I2C_eeprom_read (Acc_3);
	AccPointer[4] = I2C_eeprom_read (Acc_4);
	AccPointer[5] = I2C_eeprom_read (Acc_5);
}

void I2C_get_autPointers(void){
	AutPointer[0] = I2C_eeprom_read (Aut_0);
	AutPointer[1] = I2C_eeprom_read (Aut_1);
	AutPointer[2] = I2C_eeprom_read (Aut_2);
	AutPointer[3] = I2C_eeprom_read (Aut_3);
	AutPointer[4] = I2C_eeprom_read (Aut_4);
	AutPointer[5] = I2C_eeprom_read (Aut_5);
}

void I2C_get_skiPointers(void){
	SkiPointer[0] = I2C_eeprom_read (Ski_0);
	SkiPointer[1] = I2C_eeprom_read (Ski_1);
	SkiPointer[2] = I2C_eeprom_read (Ski_2);
	SkiPointer[3] = I2C_eeprom_read (Ski_3);
	SkiPointer[4] = I2C_eeprom_read (Ski_4);
	SkiPointer[5] = I2C_eeprom_read (Ski_5);
}

void I2C_getPointers(void){
	uint8_t flag;
	int i;
	
	flag = I2C_eeprom_read (FirstOn);
	
	if ( flag == 0 ){
		I2C_eeprom_write (1, FirstOn);
		for (i = 0; i < N_POINTERS; i++){
			EndPointer[i] = I2C_eeprom_read (Def_0 + i);
			AccPointer[i] = I2C_eeprom_read (Def_0 + i);
			AutPointer[i] = I2C_eeprom_read (Def_0 + i);
			SkiPointer[i] = I2C_eeprom_read (Def_0 + i);
		}
	}
	else{
		I2C_get_endPointers();
		I2C_get_accPointers();
		I2C_get_autPointers();
		I2C_get_skiPointers();
	}		
}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
