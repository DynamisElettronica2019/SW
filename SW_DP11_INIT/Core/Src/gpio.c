/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */

#include "general.h"
#include "data.h"
#include "can.h"
#include "i2c.h"
#include "d_traction_control.h"

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

extern int state;
extern int flag_schermata;
extern int targetTraction;
extern int targetTorque;
extern int targetPower;
int targetKalman;
int targetRegen = 2; // start with STOP_REGEN target

extern Indicator_Value Indicators[N_INDICATORS];

int schermata_settings;		//---- Variabile che viene settata a 1 quando si è entrati in settings e si preme il pulsante ok nella prima schermata
int flag_defaultIndicators = 0;

int settingsScreen;
int box_driveMode;
int box_indicator;
int box_setting;
int box_kalman;

int buttonPressed = 0;

int debug_mode_scroll_sx;
int debug_mode_scroll_dx;
int board_debug_scroll;
int pointer_scroll;
int change_pointer;

int commandSent = 0;

int calibrationDcuPopUp;
int calibrationImuPopUp;
extern int flagDcuCalibration;

extern int flagAutoX;
extern int AutoxTarget;
extern int targetRTD;

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

extern char targetMode, targetMap;
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
	GPIO_map_set();
		
	#ifndef SIM_MODE
		targetTraction = I2C_get_Traction();
		targetPower	=	I2C_get_PowerLimiter();
	#elsif
		Indicators[TC].intValore = I2C_get_Traction();
		Indicators[POW_LIM].intValore = I2C_get_PowerLimiter();
	#endif
		
	Indicators[DRIVE_MODE].intValore = targetMode;
	Indicators[MAP].intValore = targetMap;
}

/**
  * @brief  finds the new position of the mode selector encoder by 
	*					reading the value of pin1, pin2 and pin4. it forms the byte
	*					and sets the corresponding driving mode. (ABSOLUTE ENCODER)
  */

void GPIO_driveMode_set(void)
{
	char new_mode;
	
	#ifndef SIM_MODE
	if ( Indicators[INSS_SPEED].floatValore <= MIN_SPEED){
	#endif	
	
		modeSelector.pin1 = HAL_GPIO_ReadPin(SEL_MODE_1_INT_GPIO_Port, SEL_MODE_1_INT_Pin);
		modeSelector.pin2 = HAL_GPIO_ReadPin(SEL_MODE_2_GPIO_Port, SEL_MODE_2_Pin);
		modeSelector.pin4 = HAL_GPIO_ReadPin(SEL_MODE_4_GPIO_Port, SEL_MODE_4_Pin);
		
		new_mode = GPIO_encoders_find_new_mode(modeSelector.pin1, modeSelector.pin2, modeSelector.pin4);
	
		if( new_mode == EMPTY_POSITION ) 
			new_mode = ENDURANCE_MODE;	
		if( targetMode != new_mode )
			targetMode = new_mode;
		
	#ifndef SIM_MODE
	}
	#endif
	
}

/**
  * @brief  finds the new position of the map selector encoder by 
	*					reading the value of pin 1, pin2 and pin4. it forms the byte
	*					and sets the corresponding engine map. (ABSOLUTE ENCODER)
  */

void GPIO_map_set(void)
{	
	char new_map;

	#ifndef SIM_MODE
	if ( Indicators[INSS_SPEED].floatValore <= MIN_SPEED){
	#endif
		
		mapSelector.pin1 = HAL_GPIO_ReadPin(SEL_MAP_1_INT_GPIO_Port, SEL_MAP_1_INT_Pin);
		mapSelector.pin2 = HAL_GPIO_ReadPin(SEL_MAP_2_GPIO_Port, SEL_MAP_2_Pin);
		mapSelector.pin4 = HAL_GPIO_ReadPin(SEL_MAP_4_GPIO_Port, SEL_MAP_4_Pin);

		new_map = GPIO_encoders_find_new_mode(mapSelector.pin1, mapSelector.pin2, mapSelector.pin4);
	
		if( targetMap != new_map )
		{
			targetMap = new_map;
		}
		
	#ifndef SIM_MODE	
	}
	#endif
	
}

/**
	* @brief  returns the number of positions the left encoder moved:
	*					it reads the value of pin 1, 2 and 4 and finds the corresponding
	*					byte. by doing the deifference between the current 
	*					position and the previous -> RELATIVE ENCODER
  * @retval movement
  */

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

	movement = - new_pos + rightPosition;
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
	switch(settingsScreen){
		case SETTINGS_DEFAULT:
			if (movement == 1)
				box_setting = box_setting + 1;
			if (movement == -1)
				box_setting = box_setting - 1;
			if (box_driveMode >= 5 )
				box_setting = 0;
			if (box_driveMode <= -1 )
				box_setting = 4;
			break;
		case SETTINGS_INDICATORS_MODE: 
			if (movement == 1)
				box_driveMode = box_driveMode + 1;
			if (movement == -1)
				box_driveMode = box_driveMode - 1;
			if (box_driveMode >= 5 )
				box_driveMode = 0;
			if (box_driveMode <= -1 )
				box_driveMode = 4;
			break;
		case SETTINGS_INDICATORS_CHANGE:
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
		case SETTINGS_INSS_DATA:
			
			break;
		case SETTINGS_CALIBRATION:
			if (movement == 1)
				currentDcuCalibration = currentDcuCalibration + 1;
			if (movement == -1)
				currentDcuCalibration = currentDcuCalibration - 1;
			if (currentDcuCalibration >= 6)
				currentDcuCalibration = 1;
			if (currentDcuCalibration <= 0)
				currentDcuCalibration = 5;
			break;
		case SETTINGS_KALMAN:
			if (movement == 1)
				box_kalman = box_kalman + 1;
			if (movement == -1)
				box_kalman = box_kalman - 1;
			if (box_driveMode >= 6 )
				box_kalman = 1;
			if (box_driveMode <= -1 )
				box_kalman = 5;
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
	switch(settingsScreen){
		case SETTINGS_DEFAULT:
			if (movement == 1)
				box_setting = box_setting + 1;
			if (movement == -1)
				box_setting = box_setting - 1;
			if (box_driveMode >= 5 )
				box_setting = 0;
			if (box_driveMode <= -1 )
				box_setting = 4;
			break;
		case SETTINGS_INDICATORS_MODE: 
			if (movement == 1)
				box_driveMode = box_driveMode + 1;
			if (movement == -1)
				box_driveMode = box_driveMode - 1;
			if (box_driveMode >= 5 )
				box_driveMode = 0;
			if (box_driveMode <= -1 )
				box_driveMode = 4;
			break;
		case SETTINGS_INDICATORS_CHANGE:
			pointer_scroll = 0; //------- ogni volta che si cambia box si azzera lo scorrimento degli indicatori
			if (movement == 1)
				box_indicator = box_indicator + 1;
			if (movement == -1)
				box_indicator = box_indicator - 1;
			if (box_indicator >= 4)
				box_indicator = 0;
			if (box_indicator <= -1)
				box_indicator = 4;
			break;
		case SETTINGS_INSS_DATA:
			
			break;
		case SETTINGS_CALIBRATION:
			if (movement == 1)
				currentDcuCalibration = currentDcuCalibration + 1;
			if (movement == -1)
				currentDcuCalibration = currentDcuCalibration - 1;
			if (currentDcuCalibration >= 6)
				currentDcuCalibration = 1;
			if (currentDcuCalibration <= 0)
				currentDcuCalibration = 5;
			break;
		case SETTINGS_KALMAN:
			if (movement == 1)
				box_kalman = box_kalman + 1;
			if (movement == -1)
				box_kalman = box_kalman - 1;
			if (box_driveMode >= 6 )
				box_kalman = 1;
			if (box_driveMode <= -1 )
				box_kalman = 5;
			break;
		default:
			break;
		}
}

/******************************************************************************/

void GPIO_okButton_handle(void)
{
	uint16_t canMessagge = 0;
	
	#ifdef SIM_MODE
		if (Indicators[TS].intValore == TS_ON)
			Indicators[TS].intValore = TS_OFF;
		else if (Indicators[TS].intValore == TS_OFF)
			Indicators[TS].intValore = TS_ON;
	#endif

	if( Indicators[DRIVE_MODE].intValore == SETTINGS_MODE){
		
		if ( settingsScreen == SETTINGS_DEFAULT ){
			if ( box_setting <= 3 ) {
				settingsScreen = box_setting;
			}
			else if ( box_setting == 4 ){	
				
				canMessagge = DCU_SAVE_NEW_START_POSITION & 0xFF;
				canMessagge = canMessagge | ( DCU_SAVE_NEW_START_POSITION << 8 );
			
				CAN_send(SW_ACQUISITION_ID, canMessagge, EMPTY, EMPTY, EMPTY, 1);	
			}
		}
		else if ( settingsScreen == SETTINGS_INDICATORS_MODE ){
			settingsScreen = SETTINGS_INDICATORS_CHANGE;
		}
		else if ( settingsScreen == SETTINGS_INSS_DATA ) {
			
		}
		else if ( settingsScreen == SETTINGS_CALIBRATION ) {
			
			canMessagge = currentDcuCalibration & 0xFF;
			canMessagge = canMessagge | ( DCU_VCU_CALIBRATE_SENSOR << 8 );
			
			CAN_send(SW_ACQUISITION_ID, canMessagge, EMPTY, EMPTY, EMPTY, 1);	
		}
		else if ( settingsScreen == SETTINGS_KALMAN ) {
			targetKalman = box_kalman;
		}
	}
}

void GPIO_neutralButton_handle(void)
{
	uint16_t canMessagge = 0;
	
	if( Indicators[DRIVE_MODE].intValore == SETTINGS_MODE ){
		if( settingsScreen == SETTINGS_INDICATORS_MODE || settingsScreen == SETTINGS_INSS_DATA || 
				settingsScreen == SETTINGS_CALIBRATION || settingsScreen == SETTINGS_KALMAN ){
			settingsScreen = SETTINGS_DEFAULT;
		}
		else if( schermata_settings == SETTINGS_INDICATORS_CHANGE ){
			settingsScreen = SETTINGS_DEFAULT;
			I2C_save_Pointers();
		}
	}
	else if ( Indicators[DRIVE_MODE].intValore == ENDURANCE_MODE || Indicators[DRIVE_MODE].intValore == ACCELERATION_MODE ||
						Indicators[DRIVE_MODE].intValore == SKIDPAD_MODE || Indicators[DRIVE_MODE].intValore == AUTOX_MODE ){
		if ( Indicators[REGEN].intValore == START_REGEN ){
			targetRegen = STOP_REGEN;
		}
		else if ( Indicators[REGEN].intValore == STOP_REGEN ){
				targetRegen = START_REGEN;
		}
		
		canMessagge = targetRegen & 0xFF;
		canMessagge = canMessagge | ( VCU_REGEN_REQUEST << 8 );
		
		CAN_send(SW_BUTTONS_ID, canMessagge, EMPTY, EMPTY, EMPTY, 1);
		
		#ifdef SIM_MODE
			Indicators[REGEN].intValore = targetRegen;
		#endif
		
	}
}

void GPIO_aux1Button_handle(void)
{
	uint16_t canMessagge = 0;
	
	if( Indicators[ACQ].intValore == ACQ_ON && Indicators[DRIVE_MODE].intValore != SETTINGS_MODE) {
		
		canMessagge = COMMAND_ACQ_STOP & 0xFF;
		canMessagge = canMessagge | ( DCU_ACQUISITION_REQUEST << 8 );
		
		CAN_send(SW_ACQUISITION_ID, canMessagge, EMPTY, EMPTY, EMPTY, 1);
		
		#ifdef SIM_MODE
			Indicators[ACQ].intValore = ACQ_OFF;
			Indicators[BMS_STATE].intValore = ACQ_OFF;
		#endif
		
	}
	else if (( Indicators[ACQ].intValore == ACQ_OFF || Indicators[ACQ].intValore == ACQ_READY ) && Indicators[DRIVE_MODE].intValore != SETTINGS_MODE) {
		
		canMessagge = COMMAND_ACQ_START & 0xFF;
		canMessagge = canMessagge | ( DCU_ACQUISITION_REQUEST << 8 );
		
		CAN_send(SW_ACQUISITION_ID, canMessagge, EMPTY, EMPTY, EMPTY, 1);
		
		#ifdef SIM_MODE
			Indicators[ACQ].intValore = ACQ_ON;
			Indicators[BMS_STATE].intValore = ACQ_ON;
		#endif
		
	} 
	else if ( Indicators[DRIVE_MODE].intValore == SETTINGS_MODE && settingsScreen == SETTINGS_INDICATORS_CHANGE ) {
		
		flag_defaultIndicators = 1;
	}
}
		
void GPIO_aux2Button_handle(void)
{
	if( Indicators[DRIVE_MODE].intValore == SETTINGS_MODE )
		I2C_save_Pointers();
	
	HAL_NVIC_SystemReset();
}

void GPIO_startButton_handle(void)
{
	uint16_t canMessagge = 0;

	#ifndef SIM_MODE
	if( Indicators[INSS_SPEED].floatValore <= MIN_SPEED ){		
	{
	#endif
	
		if (Indicators[TS].intValore == TS_RTD){
			targetRTD = STOP_RTD;
			#ifdef SIM_MODE
				Indicators[TS].intValore = TS_ON;
			#endif
		}else if( Indicators[TS].intValore == TS_ON ){
				targetRTD = START_RTD;
			#ifdef SIM_MODE
				Indicators[TS].intValore = TS_RTD;
			#endif
		}
		
		if ( Indicators[TS].intValore != targetRTD ){
			canMessagge = targetRTD & 0xFF;
			canMessagge = canMessagge | ( VCU_RTD_REQUEST << 8 );
			CAN_send(SW_BUTTONS_ID, canMessagge, EMPTY, EMPTY, EMPTY, 1);	
		}			
	
	#ifndef SIM_MODE
	}
	#endif
}


/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
