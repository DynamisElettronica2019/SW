
/**
  ******************************************************************************
  * @file    d_ltdc_init.c
  * @brief   LTDC initialization via SPI.
  ******************************************************************************
	*/

#include "d_ltdc_init.h"

uint8_t spiData[4];

// PA4 - SPI1_NSS PIN

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


void LTDC_display_ON(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_Delay(10);

	spiData[0] = 0x00;
	spiData[1] = 0x29;

	HAL_SPI_Transmit(hspi, spiData, 2, 10);

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

void LTDC_colmod(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_Delay(10);
	
	spiData[0] = 0x00;
	spiData[1] = 0x3A;

	spiData[2] = 0x01;
	spiData[3] = 0x6F;

	HAL_SPI_Transmit(hspi, spiData, 4, 10);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

/**
  * @brief  send on SPI the initial command DISPLAY ON and COLMOD
	* 				to the display. 
  * @param  SPI pointer to a SPI_HandleTypeDef structure that contains
  *         the configuration information for the SPI we want to send on.
  * @retval void
  */

void LTDC_init_sequence(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(DEBUG_LED_2_GPIO_Port, DEBUG_LED_2_Pin, GPIO_PIN_SET);
	LTDC_display_ON(hspi);
	LTDC_colmod(hspi);
	HAL_GPIO_WritePin(DEBUG_LED_2_GPIO_Port, DEBUG_LED_2_Pin, GPIO_PIN_RESET);
}
