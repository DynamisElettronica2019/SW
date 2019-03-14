
#include "d_ltdc_init.h"

uint8_t spiData[4];

void LTDC_display_ON(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_Delay(10);

	// DNC = 0 - COMMAND DISPLAY ON 0x29 : 00101001
	spiData[0] = 0x00;
	spiData[1] = 0x29;

	HAL_SPI_Transmit(hspi, spiData, 2, 10);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

void LTDC_colmod(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_Delay(10);

	// DNC = 0 - COMMAND 0x3A : 00111010
	spiData[0] = 0x00;
	spiData[1] = 0x3A;
	// DNC = 1 - PARAMETERS x110xxxx (01101111 0x6F)
	spiData[2] = 0x01;
	spiData[3] = 0x6F;

	HAL_SPI_Transmit(hspi, spiData, 4, 10);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}


void LTDC_init_sequence(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(DEBUG_LED_2_GPIO_Port, DEBUG_LED_2_Pin, GPIO_PIN_SET);
	LTDC_display_ON(hspi);
	LTDC_colmod(hspi);
	HAL_GPIO_WritePin(DEBUG_LED_2_GPIO_Port, DEBUG_LED_2_Pin, GPIO_PIN_RESET);

}
