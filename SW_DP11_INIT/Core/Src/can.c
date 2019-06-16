/**
  ******************************************************************************
  * File Name          : CAN.c
  * Description        : This file provides code for the configuration
  *                      of the CAN instances.
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
#include "can.h"

/* USER CODE BEGIN 0 */
#include "data.h"
#include "cmsis_os.h"
#include "i2c.h"
#include "d_efiSense.h"
#include "general.h"
#include "d_gears.h"

CAN_TxHeaderTypeDef packetHeader;
CAN_FilterTypeDef canFilterConfigHeader;
HAL_StatusTypeDef filterInitReturn;
HAL_StatusTypeDef canStartReturn;
HAL_StatusTypeDef canSendReturn;

uint32_t packetMailbox;
uint8_t dataPacket[8];

CAN_RxPacketTypeDef canReceivedMessage;
CAN_TxHeaderTypeDef header;

extern BaseType_t xHigherPriorityTaskWoken;

extern osMessageQId canQueueHandle;

extern Indicator_Value Indicators[N_INDICATORS];	
extern char state, driveMode;
extern int commandSent;
extern int timerEfiAlive;
extern int autox_stop, acc_stop;
int flagDcuCalibration;
int flagImuCalibration;
int feedbackDcuCalibration;
int flagEngineOn = FALSE;
int feedbackImuCalibration;

extern int timerDCUAlive;
extern int DCU_is_dead;
extern int DCU_was_not_dead;


/* USER CODE END 0 */

CAN_HandleTypeDef hcan1;

/* CAN1 init function */
void MX_CAN1_Init(void)
{

  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 5;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_8TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_1TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspInit 0 */

  /* USER CODE END CAN1_MspInit 0 */
    /* CAN1 clock enable */
    __HAL_RCC_CAN1_CLK_ENABLE();
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**CAN1 GPIO Configuration    
    PA11     ------> CAN1_RX
    PA12     ------> CAN1_TX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* CAN1 interrupt Init */
    HAL_NVIC_SetPriority(CAN1_TX_IRQn, 9, 0);
    HAL_NVIC_EnableIRQ(CAN1_TX_IRQn);
    HAL_NVIC_SetPriority(CAN1_RX0_IRQn, 9, 0);
    HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);
  /* USER CODE BEGIN CAN1_MspInit 1 */

  /* USER CODE END CAN1_MspInit 1 */
  }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{

  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspDeInit 0 */

  /* USER CODE END CAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CAN1_CLK_DISABLE();
  
    /**CAN1 GPIO Configuration    
    PA11     ------> CAN1_RX
    PA12     ------> CAN1_TX 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_11|GPIO_PIN_12);

    /* CAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(CAN1_TX_IRQn);
    HAL_NVIC_DisableIRQ(CAN1_RX0_IRQn);
  /* USER CODE BEGIN CAN1_MspDeInit 1 */

  /* USER CODE END CAN1_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */

extern void CAN_Start(void)
{
	CAN_filterConfig();
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_TX_MAILBOX_EMPTY);
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
  HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO1_MSG_PENDING);
	canStartReturn = HAL_CAN_Start(&hcan1);
	return;
}

static void CAN_filterConfig(void)
{
	canFilterConfigHeader.FilterBank = 0;
  canFilterConfigHeader.FilterMode = CAN_FILTERMODE_IDMASK;
  canFilterConfigHeader.FilterScale = CAN_FILTERSCALE_32BIT;
	canFilterConfigHeader.FilterIdHigh = (0x000 << 5);
  canFilterConfigHeader.FilterIdLow = 0x0000;
  canFilterConfigHeader.FilterMaskIdHigh = (0x000 << 5);
  canFilterConfigHeader.FilterMaskIdLow = 0x0000;
	canFilterConfigHeader.FilterFIFOAssignment = CAN_RX_FIFO0;
  canFilterConfigHeader.FilterActivation = ENABLE;	
  canFilterConfigHeader.SlaveStartFilterBank = 14;
	filterInitReturn = HAL_CAN_ConfigFilter(&hcan1, &canFilterConfigHeader);
	return;
}


void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{	
	HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &(canReceivedMessage.CAN_RxPacket_Header), canReceivedMessage.CAN_RxPacket_Data); 

  xQueueSendFromISR( canQueueHandle, &canReceivedMessage, &xHigherPriorityTaskWoken );

  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

void CAN_receive(int ID, uint16_t firstInt, uint16_t secondInt, uint16_t thirdInt, uint16_t fourthInt)
{
	switch(ID)
	{
	   case EFI_GEAR_RPM_TPS_PH2O_ID:
				dGears_setGear(firstInt);
				I2C_setRPM(secondInt);
				dEfiSense_calculateTPS(TPS,thirdInt);
				dEfiSense_calculatePH2O(PH2O,fourthInt);
				timerEfiAlive = 0;
				break;
		 case EFI_WATER_TEMPERATURE_ID:
				dEfiSense_calculateWaterTemperature(TH2O_SX_IN, firstInt);
				dEfiSense_calculateWaterTemperature(TH2O_SX_OUT, secondInt);
				dEfiSense_calculateWaterTemperature(TH2O_DX_IN, thirdInt);
				dEfiSense_calculateWaterTemperature(TH2O_DX_OUT, fourthInt);
		 		timerEfiAlive = 0;
				break;
		case EFI_OIL_T_ENGINE_BAT_ID:
				dEfiSense_calculateOilInTemperature(OIL_TEMP_IN, firstInt);
				dEfiSense_calculateOilOutTemperature(OIL_TEMP_OUT, secondInt);
				dEfiSense_calculateTemperature(TH2O, thirdInt);
				dEfiSense_calculateVoltage(VBAT, fourthInt);
				timerEfiAlive = 0;
				break;
     case EFI_TRACTION_CONTROL_ID:
				dEfiSense_calculateSpeed(VH_SPEED, firstInt);
				dEfiSense_calculateSlip(EFI_SLIP_TARGET, secondInt);
			  dEfiSense_calculateSlip(EFI_SLIP, thirdInt);
		  	timerEfiAlive = 0;
        break;
     case EFI_MANUAL_LIMITER_FAN_H2O_PIT_LANE_ID:
			  Indicators[MAN_LIM_ACT].intValore = firstInt;	
			  Indicators[FAN].intValore = secondInt; 
				Indicators[H2OPUMP_DC].intValore = thirdInt;
				Indicators[PIT_LANE_ACT].intValore = fourthInt; 
		 		timerEfiAlive = 0;
        break;
     case EFI_PRESSURES_LAMBDA_SMOT_ID:
				dEfiSense_calculatePressure(FUEL_PRESS, firstInt);
				dEfiSense_calculatePressure(OIL_PRESS, secondInt);
				dEfiSense_calculatePressure(LAMBDA, thirdInt);
				Indicators[FLAG_SMOT].intValore = fourthInt; 
		 		timerEfiAlive = 0;
				break;
		 case EFI_LOIL_EXHAUST_ID:
				dEfiSense_calculateFuelLevel(FUEL_LEVEL, firstInt);
				dEfiSense_calculateTempScarico(T_SCARICO_1, secondInt);
				dEfiSense_calculateTempScarico(T_SCARICO_2, thirdInt);
		 		timerEfiAlive = 0;
				break;
		 case GCU_TRACTION_LIMITER_LOIL_EFI_ID:
				Indicators[AN_SLIP_TRGT].intValore = firstInt;
				Indicators[AN_SLIP_TRIM].intValore = secondInt;
				Indicators[AN_MAN_LIM].intValore = thirdInt;
				Indicators[OIL_LEVEL].intValore = fourthInt;
				break;
     case GCU_CLUTCH_MODE_MAP_SW_ID:
				Indicators[CLUTCH_FEEDBACK].intValore = firstInt;
				CAN_changeState(secondInt);
				Indicators[MAP].intValore = thirdInt; // 0 1 o 1 2 ??
				Indicators[ANTISTALL].intValore = fourthInt;
        break;
		 case GCU_TRACTION_LIMITER_AUTOG_ACC_SW_ID:
				Indicators[TRACTION_CONTROL].intValore = firstInt;
				Indicators[RPM_LIM].intValore = secondInt;
			  // autogearshift feedback
				CAN_changeRoutineState(fourthInt);
        break;
     case DCU_ACQUISITION_SW_ID:
				CAN_DCU_feedback(firstInt,secondInt);
				CAN_DCU_is_alive();
        break;
		 case	IMU1_DATA_1_ID:
			 	Indicators[ACC_X_1].floatValore = ((int16_t)firstInt)/100.0;
				Indicators[ACC_Y_1].floatValore = ((int16_t)secondInt)/100.0;
				Indicators[GYR_X_1].floatValore = ((int16_t)thirdInt)/10.0;
				Indicators[GYR_Z_1].floatValore = ((int16_t)fourthInt)/10.0;
			 break;
		 case	IMU1_DATA_2_ID:
			  Indicators[HEAD_1].floatValore 	= ((int16_t)firstInt)/100.0;
				Indicators[ACC_Z_1].floatValore = ((int16_t)secondInt)/100.0;
				Indicators[GYR_Y_1].floatValore = ((int16_t)thirdInt)/10.0;
				Indicators[IMU1_INFO].intValore = fourthInt;
			 break;
		 case	IMU2_DATA_1_ID:
			 	Indicators[ACC_X_2].floatValore = ((int16_t)firstInt)/100.0;
				Indicators[ACC_Y_2].floatValore = ((int16_t)secondInt)/100.0;
				Indicators[GYR_X_2].floatValore = ((int16_t)thirdInt)/10.0;
				Indicators[GYR_Z_2].floatValore = ((int16_t)fourthInt)/10.0;
			 break;
		 case	IMU2_DATA_2_ID:
			  Indicators[HEAD_2].floatValore  = ((int16_t)firstInt)/100.0;
				Indicators[ACC_Z_2].floatValore = ((int16_t)secondInt)/100.0;
				Indicators[GYR_Y_2].floatValore = ((int16_t)thirdInt)/10.0;
				Indicators[IMU2_INFO].intValore = fourthInt;
			 break;
//		 case DAU_FR_ID:
//			  Indicators[BPS_F].intValore  = thirdInt; //da togliere
//			 break;
//		 case DAU_FL_ID:
//			  Indicators[BPS_R].intValore  = thirdInt; //da togliere
//			 break;
     case DAU_FR_DEBUG_ID:
				Indicators[DAU_FR_BOARD].intValore2 = firstInt;
				Indicators[DAU_FR_BOARD].intValore = secondInt;
        break;
	   case DAU_FL_DEBUG_ID:
			  Indicators[DAU_FL_BOARD].intValore2 = firstInt;
			  Indicators[DAU_FL_BOARD].intValore = secondInt; 
        break;
     case DAU_REAR_DEBUG_ID:
				Indicators[DAU_R_BOARD].intValore2 = firstInt;
				Indicators[DAU_R_BOARD].intValore = secondInt;
				break;
     case GCU_DEBUG_1_ID:
				Indicators[GCU_BOARD].intValore2 = firstInt;
				Indicators[GCU_BOARD].intValore = secondInt;
				Indicators[H2O_PUMP].floatValore = thirdInt/10;
        Indicators[FUEL_PUMP].floatValore = fourthInt/10;
        break;
     case GCU_DEBUG_2_ID:
        Indicators[GEAR_CURR].floatValore = firstInt/10;
        Indicators[CLUTCH_CURR].floatValore = secondInt/10;
        Indicators[H2O_FAN_SX].floatValore = thirdInt/10;
        Indicators[H2O_FAN_DX].floatValore = fourthInt/10;
        break;
     case DCU_DEBUG_1_ID:
        Indicators[DCU_BOARD].intValore2 = firstInt;
				Indicators[DCU_BOARD].intValore = secondInt;
				Indicators[XBEE].intValore2 = thirdInt;
			  Indicators[DCU_3V3].intValore2 = fourthInt;
				CAN_DCU_is_alive();
        break;
		 case DCU_DEBUG_2_ID:
        Indicators[DCU_12V].intValore = firstInt;
        Indicators[DCU_5V].intValore = secondInt;
				Indicators[DCU_3V3].intValore = thirdInt;
				Indicators[BRAKE_BIAS].intValore = fourthInt;
				CAN_DCU_is_alive();
        break;
		 case IMU_SW_FEEDBACK_ID:
			 	flagImuCalibration = 1;
				feedbackImuCalibration = firstInt;
				break;
     default:
        break;
	}
}

void CAN_send(int ID, uint16_t firstInt, uint16_t secondInt, uint16_t thirdInt, uint16_t fourthInt, uint8_t dlc_value)
{
	uint32_t mailbox; 	// mailbox da discutere con gli altri
	
	header.StdId = ID;
	header.RTR = CAN_RTR_DATA;
	header.IDE = CAN_ID_STD;
	header.DLC = dlc_value*2;
	
	dataPacket[0] = (uint8_t)((firstInt >> 8) & 0x00FF);
  dataPacket[1] = (uint8_t)(firstInt & 0x00FF);
  dataPacket[2] = (uint8_t)((secondInt >> 8) & 0x00FF);
  dataPacket[3] = (uint8_t)(secondInt & 0x00FF);
	dataPacket[4] = (uint8_t)((thirdInt >> 8) & 0x00FF);
  dataPacket[5] = (uint8_t)(thirdInt & 0x00FF);
  dataPacket[6] = (uint8_t)((fourthInt >> 8) & 0x00FF);
  dataPacket[7] = (uint8_t)(fourthInt & 0x00FF);
	
  HAL_CAN_AddTxMessage(&hcan1, &header, dataPacket, &mailbox);
}

void CAN_changeState(int mode_feedback)
{
	switch (mode_feedback)
	{
		case ENDURANCE_MODE:
			if(state == ENDURANCE_MODE_START)
					state = ENDURANCE_MODE_FEEDBACK;
			break;
		case SKIDPAD_MODE:
			if(state == SKIDPAD_MODE_START)
					state = SKIDPAD_MODE_FEEDBACK;
			break;
		case ACCELERATION_MODE:
			if(state == ACCELERATION_MODE_START)
					state = ACCELERATION_MODE_FEEDBACK;
			break;
		case AUTOX_MODE:
			if(state == AUTOX_MODE_START)
					state = AUTOX_MODE_FEEDBACK;
			break;
	  default:
			break;
	}
	
  Indicators[DRIVE_MODE].intValore = mode_feedback;
}

void CAN_changeRoutineState(int command_feedback)
{
	if(Indicators[DRIVE_MODE].intValore == ACCELERATION_MODE)
	{
		switch(command_feedback)
		{
			case COMMAND_READY:
				if(state == ACCELERATION_MODE_DEFAULT && commandSent == 1){
					state = ACCELERATION_MODE_READY;
					commandSent = 0;
				}
				break;
			case COMMAND_GO:
				if(state == ACCELERATION_MODE_READY && commandSent == 1){
					state = ACCELERATION_MODE_GO;
					commandSent = 0;
				}
				break;
			case COMMAND_STOP:
				if(state == ACCELERATION_MODE_READY || state == ACCELERATION_MODE_GO){
					state = ACCELERATION_MODE_DEFAULT;
					acc_stop = 1;
				}
				break;
			default:
				break;
		}
	}
	
	if(Indicators[DRIVE_MODE].intValore == AUTOX_MODE)
	{
		switch(command_feedback)
		{
			case COMMAND_READY:
				if(state == AUTOX_MODE_DEFAULT && commandSent == 1){
					state = AUTOX_MODE_READY;
					commandSent = 0;
				}
				break;
			case COMMAND_GO:
				if(state == AUTOX_MODE_READY && commandSent == 1){
					state = AUTOX_MODE_GO;
					commandSent = 0;
				}
				break;
			case COMMAND_STOP:
				if(state == AUTOX_MODE_READY || state == AUTOX_MODE_GO){
					state = AUTOX_MODE_DEFAULT; 
					autox_stop = 1;
				}
				break;
		}
	}
}

void CAN_DCU_feedback(uint16_t firstInt, uint16_t secondInt)
{
	if( firstInt == DCU_ACQUISITION_CODE ){
		Indicators[ACQ].intValore = secondInt;
	} else if( firstInt == DCU_SAVE_CALIBRATION_CODE ){
		feedbackDcuCalibration	= secondInt;
		flagDcuCalibration = 1;
	}			
}

void CAN_DCU_is_alive(void)
{
	timerDCUAlive = 0;
	DCU_is_dead = 0;
	DCU_was_not_dead = 0;
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
