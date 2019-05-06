/**
  ******************************************************************************
  * File Name          : SPI.c
  * Description        : This file provides code for the configuration
  *                      of the SPI instances.
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
#include "spi.h"

/* USER CODE BEGIN 0 */

uint8_t spiData[4];

/* USER CODE END 0 */

SPI_HandleTypeDef hspi1;

/* SPI1 init function */
void MX_SPI1_Init(void)
{

  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_9BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_SPI_MspInit(SPI_HandleTypeDef* spiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(spiHandle->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspInit 0 */

  /* USER CODE END SPI1_MspInit 0 */
    /* SPI1 clock enable */
    __HAL_RCC_SPI1_CLK_ENABLE();
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**SPI1 GPIO Configuration    
    PA5     ------> SPI1_SCK
    PA7     ------> SPI1_MOSI 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN SPI1_MspInit 1 */

  /* USER CODE END SPI1_MspInit 1 */
  }
}

void HAL_SPI_MspDeInit(SPI_HandleTypeDef* spiHandle)
{

  if(spiHandle->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspDeInit 0 */

  /* USER CODE END SPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI1_CLK_DISABLE();
  
    /**SPI1 GPIO Configuration    
    PA5     ------> SPI1_SCK
    PA7     ------> SPI1_MOSI 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_5|GPIO_PIN_7);

  /* USER CODE BEGIN SPI1_MspDeInit 1 */

  /* USER CODE END SPI1_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */

/**
  * @brief  send on SPI the initial commands to turn on the display. 
  * @param  SPI pointer to a SPI_HandleTypeDef structure that contains
  *         the configuration information for the SPI we want to send on.
  * @retval void
  */

void SPI_ltdc_init_sequence(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(DEBUG_LED_2_GPIO_Port, DEBUG_LED_2_Pin, GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_11, GPIO_PIN_SET);
	HAL_Delay(120);
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_Delay(120);
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_11, GPIO_PIN_SET);
	HAL_Delay(120);
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_Delay(120);
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_11, GPIO_PIN_SET);
	
	HAL_Delay(10);
	SPI_sleep_out(hspi);
	HAL_Delay(130);
	SPI_colmod(hspi);
	//HAL_Delay(10);
	SPI_display_ON(hspi);
	HAL_Delay(10);
	SPI_invert_colors(hspi);
	SPI_brightness(hspi);
	//SPI_flip_vertical(hspi);
	SPI_flip_horizontal(hspi);

	HAL_GPIO_WritePin(DEBUG_LED_2_GPIO_Port, DEBUG_LED_2_Pin, GPIO_PIN_RESET);
}

/**
  * @brief  send on SPI the initial command SLEEP OUT
	* 				to the display. The command is composed by 9 bits: first bit is
	*					the DNC and last 8 bits are the command.
	*   			DNC = 0 - COMMAND 0x11 : 00001011
	*					The parameter is composed by 9 bits: first bit is the DNC and
	*					last 8 bits are the parameter.
	* 				See datasheet for more information. 
  * @param  SPI pointer to a SPI_HandleTypeDef structure that contains
  *         the configuration information for the SPI we want to send on.
  * @retval void
  */


void SPI_sleep_out(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//	HAL_Delay(10);

	spiData[0] = 0x11;
	spiData[1] = 0x00;

	HAL_SPI_Transmit(hspi, spiData, 1, 5);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

/**
  * @brief  send on SPI the initial command COLMOD and the parameters
	* 				to the display. The command is composed by 9 bits: first bit is
	*					the DNC and last 8 bits are the command.
	*   			DNC = 0 - COMMAND 0x3A : 00111010
	*					The parameter is composed by 9 bits: first bit is the DNC and
	*					last 8 bits are the parameter.
	*					DNC = 1 - PARAMETERS x110xxxx (ex. 01101111 0x6F)
	* 				See datasheet for more information. 
  * @param  SPI pointer to a SPI_HandleTypeDef structure that contains
  *         the configuration information for the SPI we want to send on.
  * @retval void
  */

void SPI_colmod(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//	HAL_Delay();
	
	spiData[0] =  0x3A;
	spiData[1] = 	0x00;

	spiData[2] = 0x6F;
	spiData[3] = 0x01;

	HAL_SPI_Transmit(hspi, spiData, 2, 5);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}


/**
  * @brief  send on SPI the initial command DISPLAY ON
	* 				to the display. The message is composed by 9 bits: first bit is
	*					the DNC and last 8 bits are the command. See datasheet for more 
	*					information. 
	*					DNC = 0 - COMMAND DISPLAY ON 0x29 : 00101001
  * @param  SPI pointer to a SPI_HandleTypeDef structure that contains
  *         the configuration information for the SPI we want to send on.
  * @retval void
  */

void SPI_display_ON(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//	HAL_Delay(10);

	spiData[0] = 0x29;
	spiData[1] = 0x00;

	HAL_SPI_Transmit(hspi, spiData, 1, 5);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

/**
  * @brief  send on SPI the initial command INVERT COLORS
	* 				to the display. The message is composed by 9 bits: first bit is
	*					the DNC and last 8 bits are the command. See datasheet for more 
	*					information. 
	*					DNC = 0 - COMMAND INVERT COLORS 0x21 : 00100001
  * @param  SPI pointer to a SPI_HandleTypeDef structure that contains
  *         the configuration information for the SPI we want to send on.
  * @retval void
  */

void SPI_invert_colors(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//	HAL_Delay(10);

	spiData[0] = 0x21;
	spiData[1] = 0x00;

	HAL_SPI_Transmit(hspi, spiData, 1, 5);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}


/**
  * @brief  send on SPI the initial command BRIGHTNESS and the parameters
	* 				to the display. The command is composed by 9 bits: first bit is
	*					the DNC and last 8 bits are the command.
	*   			DNC = 0 - COMMAND 0x51 : 01010001
	*					The parameter is composed by 9 bits: first bit is the DNC and
	*					last 8 bits are the parameter.
  *					DNC = 1 - PARAMETERS 0xFF : 11111111 (doesn's seem to work)
	* 				See datasheet for more information. 
  * @param  SPI pointer to a SPI_HandleTypeDef structure that contains
  *         the configuration information for the SPI we want to send on.
  * @retval void
  */

void SPI_brightness(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//	HAL_Delay();
	
	spiData[0] =  0x51;
	spiData[1] = 	0x00;

	spiData[2] = 0xFF;
	spiData[3] = 0x01;

	HAL_SPI_Transmit(hspi, spiData, 2, 5);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

/**
  * @brief  send on SPI the initial command MEMORY ACCESS CONTROL and the parameters
	* 				to the display to FLIP VERTICALLY. The command is composed by 9 bits: 
	*					first bit is the DNC and last 8 bits are the command.
	*   			DNC = 0 - COMMAND 0x36 : 00110110
	*					The parameter is composed by 9 bits: first bit is the DNC and
	*					last 8 bits are the parameter.
  *					DNC = 1 - PARAMETERS 0x09 : 00001001
	* 				See datasheet for more information. 
  * @param  SPI pointer to a SPI_HandleTypeDef structure that contains
  *         the configuration information for the SPI we want to send on.
  * @retval void
  */

void SPI_flip_vertical(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//	HAL_Delay();
	
	spiData[0] =  0x36;
	spiData[1] = 	0x00;

	spiData[2] = 0x09;
	spiData[3] = 0x01;

	HAL_SPI_Transmit(hspi, spiData, 2, 5);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

/**
  * @brief  send on SPI the initial command MEMORY ACCESS CONTROL and the parameters
	* 				to the display to FLIP HORIZONTALLY. The command is composed by 9 bits: 
	*					first bit is the DNC and last 8 bits are the command.
	*   			DNC = 0 - COMMAND 0x36 : 00110110
	*					The parameter is composed by 9 bits: first bit is the DNC and
	*					last 8 bits are the parameter.
  *					DNC = 1 - PARAMETERS 0x0A : 00001010
	* 				See datasheet for more information. 
  * @param  SPI pointer to a SPI_HandleTypeDef structure that contains
  *         the configuration information for the SPI we want to send on.
  * @retval void
  */

void SPI_flip_horizontal(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//	HAL_Delay();
	
	spiData[0] =  0x36;
	spiData[1] = 	0x00;

	spiData[2] = 0x0A;
	spiData[3] = 0x01;

	HAL_SPI_Transmit(hspi, spiData, 2, 5);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
