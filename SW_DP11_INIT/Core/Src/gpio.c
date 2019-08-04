/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
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
#include "gpio.h"
/* USER CODE BEGIN 0 */

#include "general.h"
#include "data.h"
#include "can.h"
#include "i2c.h"
#include "d_traction_control.h"
#include "d_rpm_limiter.h"
#include "d_gears.h"

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

extern int state;
extern int flag_schermata;
extern int d_rpmLimiterValue, d_tractionValue;
extern Indicator_Value Indicators[N_INDICATORS];

int schermata_settings;		//---- Variabile che viene settata a 1 quando si è entrati in settings e si preme il pulsante ok nella prima schermata
int flag_defaultIndicators = 0;

int box_driveMode;
int box_indicator;
int buttonPressed = 0;

int debug_mode_scroll_sx;
int debug_mode_scroll_dx;
int board_debug_scroll;
int pointer_scroll;
int change_pointer;
extern int flagImuCalibration;

int commandSent = 0;

int calibrationDcuPopUp;
int calibrationImuPopUp;
extern int flagDcuCalibration;
extern void dGear_setNeutral(void);

extern int flagAutoX;
extern int AutoxTarget;

int temp_stato = 0;

/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SPI_NSS_GPIO_Port, SPI_NSS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, DEBUG_LED_3_Pin|DEBUG_LED_2_Pin|DEBUG_LED_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = LCD_RESET_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LCD_RESET_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin */
  GPIO_InitStruct.Pin = ENC_RIGHT_1_INT_Pin|SEL_MAP_1_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin 
                           PCPin */
  GPIO_InitStruct.Pin = ENC_RIGHT_2_Pin|ENC_RIGHT_4_Pin|ENC_RIGHT_8_Pin|SEL_MAP_4_Pin 
                          |SEL_MAP_8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = ENC_LEFT_1_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ENC_LEFT_1_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = ENC_LEFT_2_Pin|SEL_MAP_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PHPin PHPin */
  GPIO_InitStruct.Pin = ENC_LEFT_4_Pin|ENC_LEFT_8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = SPI_NSS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SPI_NSS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = SEL_MODE_4_Pin|SEL_MODE_8_Pin|SEL_MODE_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = SEL_MODE_1_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SEL_MODE_1_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin */
  GPIO_InitStruct.Pin = START_BUTTON_INT_Pin|AUX_3_BUTTON_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PGPin PGPin */
  GPIO_InitStruct.Pin = SHIFT_DOWN_INT_Pin|SHIFT_UP_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin */
  GPIO_InitStruct.Pin = NEUTRAL_BUTTON_INT_Pin|OK_BUTTON_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = AUX_1_BUTTON_INT_Pin|AUX_2_BUTTON_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin */
  GPIO_InitStruct.Pin = DEBUG_LED_3_Pin|DEBUG_LED_2_Pin|DEBUG_LED_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 13, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 13, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_IRQn, 8, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI3_IRQn, 8, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 12, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 12, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */

/*********** SELECTORS AND ENCODERS *******************************************/

extern char driveMode, engineMap;
extern char leftPosition, rightPosition;
encoder_position modeSelector, mapSelector;
encoder_position leftEncoder, rightEncoder;
int currentDcuCalibration, currentImuCalibration;

/************ TRUTH TABLE **************
----------------------------------------
|SWITCH POS | CODE POS | 1 | 2 | 4 | 8 |
----------------------------------------
|	  	1	    |		 0	   | 0 | 0 | 0 | 0 |
|  		2	    |	 	 1	   | 1 | 0 | 0 | 0 |
|	  	3	    |	 	 2	   | 0 | 1 | 0 | 0 |
|	  	4	    |    3	   | 1 | 1 | 0 | 0 |
|	  	5	    |	 	 4	   | 0 | 0 | 1 | 0 |
|	  	6	    |	 	 5	   | 1 | 0 | 1 | 0 |
|	  	7	    |	 	 6	   | 0 | 1 | 1 | 0 |
|	  	8	    |	 	 7	   | 1 | 1 | 1 | 0 |
----------------------------------------
*/

/**
  * @brief  write the byte corresponding to the position of the 
	*					encoder that was moved. 
  * @param  value of pin1 of the encoder
  * @param  value of pin2 of the encoder
  * @param  value of pin3 of the encoder 
  * @retval new position
  */

char GPIO_encoders_find_new_position(char pin1, char pin2, char pin4)
{
	char new_position;
	new_position = (pin1) | (pin2 << 1) | (pin4 << 2);
	return new_position;
}

char GPIO_encoders_find_new_mode(char pin1, char pin2, char pin4)
{
	char new_position;
	new_position = (8 - ((pin1) | (pin2 << 1) | (pin4 << 2))) & 7 ;
	return new_position;
}

/**
  * @brief  initialization of the right and left encoders. 
	*					it sets the position in which the encoders are at power on 
	*					as the references: left and wight encoders are relative and 
	*					not absolute.
  */

void GPIO_encoders_init(void)
{
	leftEncoder.pin1 = HAL_GPIO_ReadPin(ENC_LEFT_1_INT_GPIO_Port, ENC_LEFT_1_INT_Pin);
	leftEncoder.pin2 = HAL_GPIO_ReadPin(ENC_LEFT_2_GPIO_Port, ENC_LEFT_2_Pin);
	leftEncoder.pin4 = HAL_GPIO_ReadPin(ENC_LEFT_4_GPIO_Port, ENC_LEFT_4_Pin);
	
	leftPosition = GPIO_encoders_find_new_position(leftEncoder.pin1, leftEncoder.pin2, leftEncoder.pin4);

	rightEncoder.pin1 = HAL_GPIO_ReadPin(ENC_RIGHT_1_INT_GPIO_Port, ENC_RIGHT_1_INT_Pin);
	rightEncoder.pin2 = HAL_GPIO_ReadPin(ENC_RIGHT_2_GPIO_Port, ENC_RIGHT_2_Pin);
	rightEncoder.pin4 = HAL_GPIO_ReadPin(ENC_RIGHT_4_GPIO_Port, ENC_RIGHT_4_Pin);

	rightPosition = GPIO_encoders_find_new_position(rightEncoder.pin1, rightEncoder.pin2, rightEncoder.pin4);
	
	GPIO_driveMode_set();
	GPIO_engineMap_set();

	d_tractionValue = I2C_get_Traction();
	d_rpmLimiterValue = I2C_get_RpmLimiter();
	Indicators[DRIVE_MODE].intValore = driveMode;
	Indicators[MAP].intValore = engineMap;
}

/**
  * @brief  finds the new position of the mode selector encoder by 
	*					reading the value of pin1, pin2 and pin4. it forms the byte
	*					and sets the corresponding driving mode. (ABSOLUTE ENCODER)
  */

void GPIO_driveMode_set(void)
{
	char new_mode;
	modeSelector.pin1 = HAL_GPIO_ReadPin(SEL_MODE_1_INT_GPIO_Port, SEL_MODE_1_INT_Pin);
	modeSelector.pin2 = HAL_GPIO_ReadPin(SEL_MODE_2_GPIO_Port, SEL_MODE_2_Pin);
	modeSelector.pin4 = HAL_GPIO_ReadPin(SEL_MODE_4_GPIO_Port, SEL_MODE_4_Pin);
	
	new_mode = GPIO_encoders_find_new_mode(modeSelector.pin1, modeSelector.pin2, modeSelector.pin4);
	
//	if( new_mode == EMPTY_POSITION ) new_mode = ENDURANCE_MODE;	----- commentato perchè ora c'è NOISE_MODE
	
	if( driveMode != new_mode )
	{
		driveMode = new_mode;
	}
}

/**
  * @brief  finds the new position of the map selector encoder by 
	*					reading the value of pin 1, pin2 and pin4. it forms the byte
	*					and sets the corresponding engine map. (ABSOLUTE ENCODER)
  */

void GPIO_engineMap_set(void)
{	
	char new_map;
	mapSelector.pin1 = HAL_GPIO_ReadPin(SEL_MAP_1_INT_GPIO_Port, SEL_MAP_1_INT_Pin);
	mapSelector.pin2 = HAL_GPIO_ReadPin(SEL_MAP_2_GPIO_Port, SEL_MAP_2_Pin);
	mapSelector.pin4 = HAL_GPIO_ReadPin(SEL_MAP_4_GPIO_Port, SEL_MAP_4_Pin);

	new_map = GPIO_encoders_find_new_mode(mapSelector.pin1, mapSelector.pin2, mapSelector.pin4);
	
	// a Nico non piace il % :(
	if(new_map == 0 || new_map == 2 || new_map == 4 || new_map == 6) new_map = MAP_2;
	else new_map = MAP_1;
	if(engineMap != new_map)
	{
		engineMap = new_map;
		HAL_GPIO_TogglePin(DEBUG_LED_2_GPIO_Port, DEBUG_LED_2_Pin);
	}

}

/**
	* @brief  returns the number of positions the left encoder moved:
	*					it reads the value of pin 1, 2 and 4 and finds the corresponding
	*					byte. by doing the deifference between the current 
	*					position and the previous -> RELATIVE ENCODER
  * @retval movement
  */
int variabile;

int GPIO_leftEncoder_movement(void)
{	
	char new_pos;
	int movement = 0;
	leftEncoder.pin1 = HAL_GPIO_ReadPin(ENC_LEFT_1_INT_GPIO_Port, ENC_LEFT_1_INT_Pin);
	leftEncoder.pin2 = HAL_GPIO_ReadPin(ENC_LEFT_2_GPIO_Port, ENC_LEFT_2_Pin);
	leftEncoder.pin4 = HAL_GPIO_ReadPin(ENC_LEFT_4_GPIO_Port, ENC_LEFT_4_Pin);

	new_pos = GPIO_encoders_find_new_position(leftEncoder.pin1, leftEncoder.pin2, leftEncoder.pin4);

	HAL_GPIO_TogglePin(DEBUG_LED_3_GPIO_Port, DEBUG_LED_3_Pin);
	
	movement = new_pos - leftPosition; // magari segni invertiti
	if (movement == -7 )
		movement = 1;
	else if (movement == 7)
		movement = -1;
	leftPosition = new_pos;
	
	//Indicators[CLUTCH_FEEDBACK].intValore = movement;

	return movement;

}

/**
	* @brief  returns the number of positions the right encoder moved:
	*					it reads the value of pin 1, 2 and 4 and finds the corresponding
	*					byte. by doing the deifference between the current 
	*					position and the previous -> RELATIVE ENCODER
  * @retval movement
  */

int GPIO_rightEncoder_movement(void)
{	
	char new_pos;
	int movement = 0;

	rightEncoder.pin1 = HAL_GPIO_ReadPin(ENC_RIGHT_1_INT_GPIO_Port, ENC_RIGHT_1_INT_Pin);
	rightEncoder.pin2 = HAL_GPIO_ReadPin(ENC_RIGHT_2_GPIO_Port, ENC_RIGHT_2_Pin);
	rightEncoder.pin4 = HAL_GPIO_ReadPin(ENC_RIGHT_4_GPIO_Port, ENC_RIGHT_4_Pin);

	new_pos = GPIO_encoders_find_new_position(rightEncoder.pin1, rightEncoder.pin2, rightEncoder.pin4);

	
	HAL_GPIO_TogglePin(DEBUG_LED_2_GPIO_Port, DEBUG_LED_2_Pin);

	movement = - new_pos + rightPosition; // magari segni invertiti
	if (movement == -7 )
		movement = 1;
	else if (movement == 7)
		movement = -1;
	
	rightPosition = new_pos;
	
	return movement;

}


void GPIO_rightEncoder_boardDebugMode(int movement)
{
	// scorri il menu - AGGIORNARE LA MATRICE GLOBALE 
	if (movement == 1)
		board_debug_scroll = board_debug_scroll + 1;
	if (movement == -1)
		board_debug_scroll = board_debug_scroll - 1;
	if (board_debug_scroll > END_BOARD_DEBUG - 7)
		board_debug_scroll = END_BOARD_DEBUG - 7;
	if (board_debug_scroll < START_BOARD_DEBUG)
		board_debug_scroll = START_BOARD_DEBUG;
}

void GPIO_rightEncoder_debugMode(int movement)
{
	// scorri la parte dx del menu - AGGIORNARE LA MATRICE GLOBALE
	if (movement == 1)
			debug_mode_scroll_dx = debug_mode_scroll_dx + 1;
	if (movement == -1)
			debug_mode_scroll_dx = debug_mode_scroll_dx - 1;
	if (debug_mode_scroll_dx < FIRST_CAR_PARAMETER_SX + N_DEBUG_MODE_VALUES )
		debug_mode_scroll_dx = FIRST_CAR_PARAMETER_SX + N_DEBUG_MODE_VALUES - 1;
	if (debug_mode_scroll_dx >= LAST_CAR_PARAMETER_DX)
		debug_mode_scroll_dx = LAST_CAR_PARAMETER_DX - 1;
}

void GPIO_rightEncoder_settingsMode(int movement)
{
  // scorri le finestrelle
	switch (schermata_settings){
		case 0: 
			if (movement == 1)
				box_driveMode = box_driveMode + 1;
			if (movement == -1)
				box_driveMode = box_driveMode - 1;
			if (box_driveMode >= 5 )
				box_driveMode = 0;
			if (box_driveMode <= -1 )
				box_driveMode = 4;
			break;
		case 1:
			change_pointer = 1; 
			if (movement == 1)
				pointer_scroll = pointer_scroll + 1;
			if (movement == -1)
				pointer_scroll = pointer_scroll - 1;
			if (pointer_scroll < FIRST_CAR_PARAMETER)
				pointer_scroll = N_INDICATORS - 1;
			if (pointer_scroll >	LAST_CAR_PARAMETER)
				pointer_scroll = 0;
			break;
		case 2:
			if (movement == 1)
				currentDcuCalibration = currentDcuCalibration + 1;
			if (movement == -1)
				currentDcuCalibration = currentDcuCalibration - 1;
			if (currentDcuCalibration >= 7)
				currentDcuCalibration = 1;
			if (currentDcuCalibration <= 0)
				currentDcuCalibration = 6;
			break;
		case 3:
			if (movement == 1)
				currentImuCalibration = currentImuCalibration + 1;
			if (movement == -1)
				currentImuCalibration = currentImuCalibration - 1;
			if (currentImuCalibration >= 11)
				currentImuCalibration = 1;
			if (currentImuCalibration <= 0)
				currentImuCalibration = 10;
			break;
		default:
			break;
	}
}


void GPIO_leftEncoder_boardDebugMode(int movement)
{
	if (movement == 1)
		board_debug_scroll = board_debug_scroll + 1;
	if (movement == -1)
		board_debug_scroll = board_debug_scroll - 1;
	if (board_debug_scroll > END_BOARD_DEBUG - 7)
		board_debug_scroll = END_BOARD_DEBUG - 7;
	if (board_debug_scroll < START_BOARD_DEBUG)
		board_debug_scroll = START_BOARD_DEBUG;
}

void GPIO_leftEncoder_debugMode(int movement)
{
// scorri la parte sx del menu - AGGIORNIAMO MATRICE GLOBALE
	if (movement == 1)
			debug_mode_scroll_sx = debug_mode_scroll_sx + 1;
	if (movement == -1)
			debug_mode_scroll_sx = debug_mode_scroll_sx - 1;
	if (debug_mode_scroll_sx < FIRST_CAR_PARAMETER_SX + N_DEBUG_MODE_VALUES )
		debug_mode_scroll_sx = FIRST_CAR_PARAMETER_SX + N_DEBUG_MODE_VALUES - 1;
	if (debug_mode_scroll_sx >= LAST_CAR_PARAMETER_DX)
		debug_mode_scroll_sx = LAST_CAR_PARAMETER_DX - 1;
}

void GPIO_leftEncoder_settingsMode(int movement)
{
	switch (schermata_settings){
		case 0: 
			if (movement == 1)
				box_driveMode = box_driveMode + 1;
			if (movement == -1)
				box_driveMode = box_driveMode - 1;
			if (box_driveMode >= 5 )
				box_driveMode = 0;
			if (box_driveMode <= -1 )
				box_driveMode = 4;
			break;
		case 1:
			pointer_scroll = 0; //------- ogni volta che si cambia box si azzera lo scorrimento degli indicatori
			if (movement == 1)
				box_indicator = box_indicator + 1;
			if (movement == -1)
				box_indicator = box_indicator - 1;
			if (box_indicator >= 6)
				box_indicator = 0;
			if (box_indicator <= -1)
				box_indicator = 5;
			break;
		case 2:
			if (movement == 1)
				currentDcuCalibration = currentDcuCalibration + 1;
			if (movement == -1)
				currentDcuCalibration = currentDcuCalibration - 1;
			if (currentDcuCalibration >= 7)
				currentDcuCalibration = 1;
			if (currentDcuCalibration <= 0)
				currentDcuCalibration = 6;
			break;
		case 3:
			if (movement == 1)
				currentImuCalibration = currentImuCalibration + 1;
			if (movement == -1)
				currentImuCalibration = currentImuCalibration - 1;
			if (currentImuCalibration >= 11)
				currentImuCalibration = 1;
			if (currentImuCalibration <= 0)
				currentImuCalibration = 10;
			break;
		default:
			break;
		}
}

/******************************************************************************/

void GPIO_okButton_handle(void)
{
		if( driveMode == ACCELERATION_MODE && state == ACCELERATION_MODE_DEFAULT ){
			CAN_send(SW_OK_BUTTON_GCU_ID, driveMode, COMMAND_READY, EMPTY, EMPTY, 2);
			commandSent = 1;
		}else	if( driveMode == ACCELERATION_MODE && state == ACCELERATION_MODE_READY ){
			CAN_send(SW_OK_BUTTON_GCU_ID, driveMode, COMMAND_GO, EMPTY, EMPTY, 2);
			commandSent = 1;
		}
		
		if( driveMode == AUTOX_MODE && state == AUTOX_MODE_DEFAULT && flagAutoX == 0 ){
			CAN_send(SW_OK_BUTTON_GCU_ID, driveMode, COMMAND_READY, AutoxTarget, EMPTY, 3);
			temp_stato = 1;
			commandSent = 1;
		}else	if( driveMode == AUTOX_MODE && state == AUTOX_MODE_READY  && flagAutoX ==0 ) {
			CAN_send(SW_OK_BUTTON_GCU_ID, driveMode, COMMAND_GO, AutoxTarget, EMPTY, 3);
			temp_stato = 2;
			commandSent = 1;
		}else if( driveMode == AUTOX_MODE /*&& state == AUTOX_MODE_DEFAULT*/ && flagAutoX == 1 && temp_stato == 0){
			CAN_send(SW_OK_BUTTON_GCU_ID, driveMode, 5, AutoxTarget, EMPTY, 3);
			commandSent = 1;
		}else	if( driveMode == AUTOX_MODE /*&& state == AUTOX_MODE_READY*/  && flagAutoX ==1 && temp_stato == 1) {
			CAN_send(SW_OK_BUTTON_GCU_ID, driveMode, COMMAND_READY, AutoxTarget, EMPTY, 3);
			commandSent = 1;
		}else	if( driveMode == AUTOX_MODE /*&& state == AUTOX_MODE_GO */ && flagAutoX ==1 && temp_stato == 2) {
			CAN_send(SW_OK_BUTTON_GCU_ID, driveMode, COMMAND_GO, AutoxTarget, EMPTY, 3);
			commandSent = 1;
		}

		if( driveMode == SETTINGS_MODE){
			if (schermata_settings == 0 && box_driveMode >= 0 && box_driveMode <= 3){
				flag_schermata = 0;
				schermata_settings = 1;
			}else if (schermata_settings == 0 && box_driveMode == 4 ){
				flag_schermata = 0;
				schermata_settings = 2;
			}else if (schermata_settings == 2 && currentDcuCalibration >= 0 && currentDcuCalibration <= 5 && flagDcuCalibration == 0){
				CAN_send(SW_ACQUISITION_DCU_ID, DCU_SAVE_CALIBRATION_CODE, currentDcuCalibration, EMPTY, EMPTY, 2);	
			}else if (schermata_settings == 2 && currentDcuCalibration == 6 && flagDcuCalibration == 0){
				flag_schermata = 0;
				schermata_settings = 3;
			}	else if (schermata_settings == 3 && flagImuCalibration == 0){
				CAN_send(SW_IMU_CALIBRATION_ID, Indicators[SEL_IMU].intValore, currentImuCalibration, EMPTY, EMPTY, 2);	
			}
		}
//		
//		if( driveMode == SKIDPAD_MODE ){
//			if( buttonPressed == 0 ){
//				state = SKIDPAD_SEND_100_STATE;
//			}
//			else if( buttonPressed == 1 ){
//				state = SKIDPAD_SEND_TRGT_VALUE;
//			}
//		}
		
}

void GPIO_neutralButton_handle(void)
{
	if( driveMode == ENDURANCE_MODE || driveMode == ACCELERATION_MODE || driveMode == SKIDPAD_MODE || driveMode == AUTOX_MODE )
			dGear_setNeutral();
	else if( driveMode == SETTINGS_MODE){
			if( schermata_settings == 1 || schermata_settings == 2 ){
				schermata_settings = 0;		
				flag_schermata = 0;
				I2C_save_Pointers();
			}	else if( schermata_settings == 3 ){
				schermata_settings = 2;
				flag_schermata = 0;
			}
		}
}

void GPIO_aux1Button_handle(void)
{
	if( Indicators[ACQ].intValore == ACQ_ON && driveMode != SETTINGS_MODE) {
		CAN_send(SW_ACQUISITION_DCU_ID, DCU_ACQUISITION_CODE, COMMAND_ACQ_STOP, EMPTY, EMPTY, 2);
		//Indicators[ACQ].intValore = ACQ_OFF;
	}
	else if (( Indicators[ACQ].intValore == ACQ_OFF || Indicators[ACQ].intValore == ACQ_READY ) && driveMode != SETTINGS_MODE) {
		CAN_send(SW_ACQUISITION_DCU_ID, DCU_ACQUISITION_CODE, COMMAND_ACQ_START, EMPTY, EMPTY, 2);
		//Indicators[ACQ].intValore = ACQ_ON;
	} 	
	else if ( driveMode == SETTINGS_MODE && schermata_settings == 0 ) {
		if( Indicators[SEL_SW].intValore == 1 ) 
			Indicators[SEL_SW].intValore = 2;
		else if ( Indicators[SEL_SW].intValore == 2 ) 
			Indicators[SEL_SW].intValore = 1;
	}
	else if ( driveMode == SETTINGS_MODE && schermata_settings == 1 ) {
		flag_defaultIndicators = 1;
	}
	else if ( driveMode == SETTINGS_MODE && schermata_settings == 3 ) {
		if( Indicators[SEL_IMU].intValore == 1 ) 
			Indicators[SEL_IMU].intValore = 2;
		else if ( Indicators[SEL_IMU].intValore == 2 ) 
			Indicators[SEL_IMU].intValore = 1;
	}
}
		
void GPIO_aux2Button_handle(void)
{
	if( driveMode == SETTINGS_MODE )
		I2C_save_Pointers();
	
	HAL_NVIC_SystemReset();
}

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
