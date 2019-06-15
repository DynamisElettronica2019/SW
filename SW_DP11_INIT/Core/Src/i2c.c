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
#include "data.h"

uint8_t i2cData[2];
extern uint8_t EndPointer[6], AccPointer[6], AutPointer[6], SkiPointer[6];
uint8_t DefPointer[6];
extern Indicator_Value Indicators[N_INDICATORS];
extern int box_driveMode;
extern int flagEngineOn;
extern int driveMode;
extern int flag_flash;

uint8_t devAddress;
uint8_t memAddress;
uint8_t defPage = 0;
uint8_t endPage = 1;
uint8_t accPage = 2;
uint8_t autPage = 3;
uint8_t skiPage = 4;

/* USER CODE END 0 */

I2C_HandleTypeDef hi2c1;

/* I2C1 init function */
void MX_I2C1_Init(void)
{

  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00C0EAFF;
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


/**************** RPM STRIPE *****************/

void I2C_setRPM(int rpm_value)
{
	if (rpm_value >= RPM_STRIPE_MIN) 
			 flagEngineOn = TRUE;
	else 
		flagEngineOn = FALSE;
	
	if (rpm_value < RPM_STRIPE_MIN)
     rpm_value = RPM_STRIPE_MIN;
	else if ( rpm_value > RPM_STRIPE_MAX)
     rpm_value = RPM_STRIPE_MAX;
	Indicators[RPM].intValore = rpm_value;
}

void I2C_brightness_max (uint16_t controller){

	i2cData[1] = 0x55;
	
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
	
	i2cData[0] = LED_1_RED;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_2_RED;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	i2cData[0] = LED_3_RED;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	i2cData[0] = LED_4_RED;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_5_RED;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_6_RED;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	return;
}
void I2C_debug_green_on(uint16_t controller){
	
	i2cData[1] = 0xFF;
	
	i2cData[0] = LED_1_GREEN;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);	
	
	i2cData[0] = LED_2_GREEN;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_3_GREEN;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_4_GREEN;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_5_GREEN;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_6_GREEN;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	return;
}
void I2C_debug_blue_on(uint16_t controller){
	
	i2cData[1] = 0xFF;
	
	i2cData[0] = LED_1_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	
	i2cData[0] = LED_2_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_3_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_4_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_5_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_6_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	return;
}

void I2C_debug_red_off(uint16_t controller){
	
	i2cData[1] = 0x00;
	
	i2cData[0] = LED_1_RED;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_2_RED;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	i2cData[0] = LED_3_RED;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	i2cData[0] = LED_4_RED;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_5_RED;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_6_RED;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	return;
}
void I2C_debug_green_off(uint16_t controller){
	
	i2cData[1] = 0x00;
	
	i2cData[0] = LED_1_GREEN;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);	
	
	i2cData[0] = LED_2_GREEN;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_3_GREEN;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_4_GREEN;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_5_GREEN;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_6_GREEN;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	return;
}
void I2C_debug_blue_off(uint16_t controller){
	
	i2cData[1] = 0x00;
	
	i2cData[0] = LED_1_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	
	i2cData[0] = LED_2_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_3_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_4_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_5_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);
	
	i2cData[0] = LED_6_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller<<1, i2cData, 2, 10);

	return;
}

void I2C_rpm_command(int rpm_value){
	if (rpm_value > RPM_STRIPE_MIN){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_6_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_6_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	
	if (rpm_value > RPM_STRIPE_MIN+RPM_STRIPE_OFFSET){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_5_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_5_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	
	if (rpm_value > RPM_STRIPE_MIN+2*RPM_STRIPE_OFFSET){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_4_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_4_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	
	if (rpm_value > RPM_STRIPE_MIN+3*RPM_STRIPE_OFFSET){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_3_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_3_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	
	if (rpm_value > RPM_STRIPE_MIN+4*RPM_STRIPE_OFFSET){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_2_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_2_GREEN;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	
	if (rpm_value > RPM_STRIPE_MIN+5*RPM_STRIPE_OFFSET){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_1_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_1_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_0<<1, i2cData, 2, 10);
	}
	if (rpm_value > RPM_STRIPE_MIN+6*RPM_STRIPE_OFFSET){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_6_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_6_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	
	if (rpm_value > RPM_STRIPE_MIN+7*RPM_STRIPE_OFFSET){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_5_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_5_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	
	if (rpm_value > RPM_STRIPE_MIN+8*RPM_STRIPE_OFFSET){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_4_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_4_RED;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	
	if (rpm_value > RPM_STRIPE_MIN+9*RPM_STRIPE_OFFSET){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_3_BLUE;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_3_BLUE;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	if (rpm_value > RPM_STRIPE_MIN+10*RPM_STRIPE_OFFSET){
	i2cData[1] = 0xFF;
	i2cData[0] = LED_2_BLUE;
	HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_2_BLUE;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	if (rpm_value > RPM_STRIPE_MIN+11*RPM_STRIPE_OFFSET){
		i2cData[1] = 0xFF;
		i2cData[0] = LED_1_BLUE;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}
	else{
		i2cData[1] = 0x00;
		i2cData[0] = LED_1_BLUE;
		HAL_I2C_Master_Transmit(&hi2c1, controller_1<<1, i2cData, 2, 10);
	}

}

void I2C_rpm_flash(void){
	I2C_debug_green_off (controller_0);
	I2C_debug_red_off (controller_0);
	I2C_debug_red_off (controller_1);
	if( flag_flash == 1){
		I2C_debug_blue_on(controller_0);
		I2C_debug_blue_on(controller_1);
	}
	else{
		I2C_debug_blue_off(controller_0);
		I2C_debug_blue_off(controller_1);
	}
}

void I2C_rpm_update(void){ 
	int rpm_value;
	rpm_value = Indicators[RPM].intValore;
	
	if(rpm_value == DEF_VALUE) rpm_value = 0;

	if ( Indicators[DRIVE_MODE].intValore == ENDURANCE_MODE ){
		if( rpm_value < 10000 || Indicators[GEAR].intValore == 5){
			I2C_rpm_command(rpm_value);
		}else {
			I2C_rpm_flash();
		}
	}else if ( Indicators[DRIVE_MODE].intValore == AUTOX_MODE ){
		if( rpm_value < 10500 || Indicators[GEAR].intValore == 5){
			I2C_rpm_command(rpm_value);
		}else {
			I2C_rpm_flash();
		}	
	}else{		
		I2C_rpm_command(rpm_value);
	}
	return;
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

/****************** EEPROM *******************/

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

	devAddress = EEPROM_ADDRESS << 3 | endPage >> 4;	
	memAddress = endPage << 4 | START_CELL;
	
	HAL_I2C_Mem_Write(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, EndPointer, N_POINTERS, 100);
	
	HAL_Delay(10);
}

void I2C_save_accPointers(void){	
	
	devAddress = EEPROM_ADDRESS << 3 | accPage >> 4;	
	memAddress = accPage << 4 | START_CELL;
	
	HAL_I2C_Mem_Write(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, AccPointer, N_POINTERS, 100);
	
	HAL_Delay(10);
}

void I2C_save_autPointers(void){
		
	devAddress = EEPROM_ADDRESS << 3 | autPage >> 4;	
	memAddress = autPage << 4 | START_CELL;
	
	HAL_I2C_Mem_Write(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, AutPointer, N_POINTERS, 100);
	
	HAL_Delay(10);
}

void I2C_save_skiPointers(void){
		
	devAddress = EEPROM_ADDRESS << 3 | skiPage >> 4;	
	memAddress = skiPage << 4 | START_CELL;
	
	HAL_I2C_Mem_Write(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, SkiPointer, N_POINTERS, 100);
	
	HAL_Delay(10);
}

void I2C_get_endPointers(void){
		
	devAddress = EEPROM_ADDRESS << 3 | endPage >> 4;	
	memAddress = endPage << 4 | START_CELL;
	
	HAL_I2C_Mem_Read(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, EndPointer, N_POINTERS, 100);
}

void I2C_get_accPointers(void){
	
	devAddress = EEPROM_ADDRESS << 3 | accPage >> 4;	
	memAddress = accPage << 4 | START_CELL;
	
	HAL_I2C_Mem_Read(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, AccPointer, N_POINTERS, 100);
}

void I2C_get_autPointers(void){
	
	devAddress = EEPROM_ADDRESS << 3 | autPage >> 4;	
	memAddress = autPage << 4 | START_CELL;
	
	HAL_I2C_Mem_Read(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, AutPointer, N_POINTERS, 100);
}

void I2C_get_skiPointers(void){
	
	devAddress = EEPROM_ADDRESS << 3 | skiPage >> 4;	
	memAddress = skiPage << 4 | START_CELL;
	
	HAL_I2C_Mem_Read(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, SkiPointer, N_POINTERS, 100);
}

void I2C_get_defPointers(void){
	
	devAddress = EEPROM_ADDRESS << 3 | defPage >> 4;
	memAddress = defPage << 4 | DEF_CELL;
	
	HAL_I2C_Mem_Read(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, EndPointer, N_POINTERS, 100);
	HAL_I2C_Mem_Read(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, AccPointer, N_POINTERS, 100);
	HAL_I2C_Mem_Read(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, AutPointer, N_POINTERS, 100);
	HAL_I2C_Mem_Read(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, SkiPointer, N_POINTERS, 100);

}

void I2C_getPointers(void){
	
	uint8_t flag = 0;
	
	//	--------------------- COMMENTATO PER ASSEGNARE I VALORI DI DEFAULT IN FASE DI DEBUG, DOPO LA PRIMA ACCENSIONE E SALVATAGGIO DEGLI INDICATORI è DA DECOMMENTARE
	
	devAddress = EEPROM_ADDRESS << 3 | defPage >> 4;
	memAddress = defPage << 4 | START_CELL;	
	
	HAL_I2C_Mem_Read(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, &flag, 1, 100);
		
	if ( flag == 0 ){		
		flag = 1;
		I2C_save_defPointers();
		I2C_get_defPointers();
		devAddress = EEPROM_ADDRESS << 3 | defPage >> 4;
		memAddress = defPage << 4 | DEF_CELL;
		HAL_I2C_Mem_Write(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, &flag, 1, 100);
		HAL_Delay(10);
		I2C_save_accPointers();
		I2C_save_endPointers();
		I2C_save_autPointers();
		I2C_save_skiPointers();
	}
	else{
		I2C_get_endPointers();
		I2C_get_accPointers();
		I2C_get_autPointers();
		I2C_get_skiPointers();
	}	
		
	
	//--------------------- QUESTE RIGHE INVECE DOVRANNO ESSERE ELIMINATE
	
	//I2C_save_defPointers();
	//I2C_get_defPointers();
}

void I2C_save_defPointers(void){		// in teoria non serve più
		
	uint8_t flag = 0;
	
	devAddress = EEPROM_ADDRESS << 3 | defPage >> 4;
	memAddress = defPage << 4 | START_CELL;
	
	HAL_I2C_Mem_Write(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, &flag, 1, 100);
	
	//------------messi temporaneamente, sono da sistemare
	  DefPointer[0] = OIL_PRESS;
		DefPointer[1] = TH2O;
		DefPointer[2] = OIL_TEMP_IN;
		DefPointer[3] = TPS;
		DefPointer[4] = VBAT;
		DefPointer[5] = FUEL_LEVEL;
	
	memAddress = defPage << 4 | DEF_CELL;
	HAL_I2C_Mem_Write(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, DefPointer, N_POINTERS, 100);
	
	HAL_Delay(10);
	
}

void I2C_save_Pointers(void){
	switch (box_driveMode){
		case SETT_ACC_BOX:
			I2C_save_accPointers();
			break;
		case SETT_END_BOX:
			I2C_save_endPointers();
			break;
		case SETT_AUT_BOX:
			I2C_save_autPointers();
			break;
		case SETT_SKI_BOX:
			I2C_save_skiPointers();
			break;
	}
}

void I2C_save_Traction(int value){
	
	uint8_t tractionValue;
	tractionValue = value;
	
	devAddress = EEPROM_ADDRESS << 3 | defPage >> 4;
	memAddress = defPage << 4 | TRACTION_CELL;

	HAL_I2C_Mem_Write(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, &tractionValue, 1, 100);
	
	HAL_Delay(10);
	
}

int I2C_get_Traction(void){
	
	uint8_t tractionValue;
	
	devAddress = EEPROM_ADDRESS << 3 | defPage >> 4;
	memAddress = defPage << 4 | TRACTION_CELL;

	HAL_I2C_Mem_Read(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, &tractionValue, 1, 100);

	return (tractionValue);
	
}

void I2C_save_RpmLimiter(int value){
	
	uint8_t rpmLimValue;
	rpmLimValue = value;
	
	devAddress = EEPROM_ADDRESS << 3 | defPage >> 4;
	memAddress = defPage << 4 | RPM_LIM_CELL;

	HAL_I2C_Mem_Write(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, &rpmLimValue, 1, 100);
	
	HAL_Delay(10);
	
}

int I2C_get_RpmLimiter(void){
	
	uint8_t rpmLimValue;
	
	devAddress = EEPROM_ADDRESS << 3 | defPage >> 4;
	memAddress = defPage << 4 | RPM_LIM_CELL;

	HAL_I2C_Mem_Read(&hi2c1, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, &rpmLimValue, 1, 100);

	return (rpmLimValue);
	
}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
