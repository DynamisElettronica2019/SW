/**
  ******************************************************************************
  * File Name          : CAN.c
  * Description        : This file provides code for the configuration
  *                      of the CAN instances.
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
#include "can.h"

/* USER CODE BEGIN 0 */
#include "data.h"
#include "cmsis_os.h"
#include "i2c.h"
#include "general.h"
#include "d_sensors.h"

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
extern char state, targetMode;
extern int commandSent;
extern int autox_stop, acc_stop;
extern int buttonPressed;
int flagDcuCalibration;
int flagVcuCalibration;
int feedbackDcuCalibration;
int feedbackVcuCalibration;

extern int timerDCUAlive;
extern int DCU_is_dead;
extern int DCU_was_not_dead;

extern char targetMode;
extern int targetMap;
extern int targetTraction;
extern int targetTorque;
extern int targetKalman;
extern int targetRTD;
extern int targetRegen;

//extern int temp_stato;

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
		case DCU_ACQUISITION_FEEDBACK_ID:
			CAN_DCU_feedback(firstInt);
			CAN_DCU_is_alive();
			break;
		case DCU_DEBUG_1_ID:
			Indicators[DCU_BOARD].intValore2 = firstInt;
			Indicators[DCU_BOARD].intValore = secondInt;
			Indicators[XBEE].intValore2 = thirdInt;
			Indicators[VOLTAGE_3V3_DCU].intValore2 = fourthInt;
			CAN_DCU_is_alive();
			break;
		case DCU_DEBUG_2_ID:
			Indicators[VOLTAGE_12V_DCU].intValore = firstInt;
			Indicators[VOLTAGE_5V_DCU].intValore = secondInt;
			Indicators[VOLTAGE_3V3_DCU].intValore = thirdInt;
			Indicators[BRAKE_BIAS].intValore = fourthInt;
			CAN_DCU_is_alive();
			break;
		case DAU_FRONT_LIN_ID:
			// non li leggiamo perchè non lo abbiamo mai fatto, non per altre ragioni più profonde
			break;
		case DAU_FRONT_WH_ID:
			dSensors_calculateWaterTemperature(TH2O_FR, firstInt);
			dSensors_calculateWaterTemperature(TH2O_FL, secondInt);
			dSensors_calculateOilTemperature(TH2O_FR, thirdInt);
			dSensors_calculateOilTemperature(TH2O_FL, fourthInt);
			break;
		case DAU_FRONT_IR_1_ID:
			dSensors_calculateBrakeTemperature(TBRAKE_FR, firstInt);
			dSensors_calculateBrakeTemperature(TBRAKE_FL, secondInt);
			// gli altri ir non sono sempre in macchina. di solito non li leggiamo perchè non ci interessano
			break;
		case DAU_FRONT_IR_2_ID:
			// vedi sopra
			break;
		case DAU_FRONT_MISC_ID:
			Indicators[PBRAKE_F].intValore = firstInt;	//non ci dovrebbe essere una conversione-->verificare
			Indicators[PBRAKE_R].intValore = secondInt;
			Indicators[PITOT].intValore = thirdInt;		//verificare conversione e se ci interessa vederlo
			break;
		case DAU_FRONT_4TV_ID:
			Indicators[STRAIN_GAUGE_FR].intValore = firstInt; //verificare conversione e se ci interessa vederlo
			Indicators[STRAIN_GAUGE_FL].intValore = secondInt;
			dSensors_calculateSteeringWheelAngle(SW_ANGLE, thirdInt);	//manca la conversione!
			break;
		case DAU_FRONT_DEBUG_ID:
			Indicators[DAU_FRONT_BOARD].intValore2 = firstInt;
			Indicators[DAU_FRONT_BOARD].intValore = secondInt;
			break;
		case DAU_REAR_LIN_ID:
			// non li leggiamo perchè non lo abbiamo mai fatto, non per altre ragioni più profonde
			break;
		case DAU_REAR_WH_ID:
			dSensors_calculateWaterTemperature(TH2O_RR, firstInt);
			dSensors_calculateWaterTemperature(TH2O_RL, secondInt);
			dSensors_calculateOilTemperature(TH2O_RR, thirdInt);
			dSensors_calculateOilTemperature(TH2O_RL, fourthInt);			
			break;
		case DAU_REAR_IR_1_ID:
			dSensors_calculateBrakeTemperature(TBRAKE_RR, firstInt);
			dSensors_calculateBrakeTemperature(TBRAKE_RL, secondInt);
			// gli altri ir non sono sempre in macchina. di solito non li leggiamo perchè non ci interessano
			break;
		case DAU_REAR_IR_2_ID:
			// vedi sopra --> poi possiamo togliere i case dove non facciamo niente
			break;
		case DAU_REAR_COOL_ID:
			dSensors_calculateWaterTemperature(TH2O_RAD, firstInt);
			dSensors_calculateWaterPressure(PH2O, firstInt);			
			break;
		case DAU_REAR_4TV_ID:
			Indicators[STRAIN_GAUGE_RR].intValore = firstInt; //verificare conversione e se ci interessa vederlo
			Indicators[STRAIN_GAUGE_RL].intValore = secondInt;
			break;
		case DAU_REAR_DEBUG_ID:
			Indicators[DAU_REAR_BOARD].intValore2 = firstInt;
			Indicators[DAU_REAR_BOARD].intValore = secondInt;
			break;
		case IMU_FRONT_ACC_ID:
			Indicators[ACC_X_FRONT].floatValore = ((int16_t)firstInt)/100.0; 	//sono le conversioni DP11 --> verificare quelle nuove!			
			Indicators[ACC_Y_FRONT].floatValore = ((int16_t)secondInt)/100.0;
			Indicators[ACC_Z_FRONT].floatValore = ((int16_t)thirdInt)/100.0;
			break;
		case IMU_FRONT_GYRO_ID:
			Indicators[GYRO_X_FRONT].floatValore = ((int16_t)firstInt)/10.0; 	//sono le conversioni DP11 --> verificare quelle nuove!			
			Indicators[GYRO_Y_FRONT].floatValore = ((int16_t)secondInt)/10.0;
			Indicators[GYRO_Z_FRONT].floatValore = ((int16_t)thirdInt)/10.0;
			break;
		case IMU_FRONT_DEBUG_ID:
			Indicators[IMU_FRONT_BOARD].intValore2 = firstInt;
			Indicators[IMU_FRONT_BOARD].intValore = secondInt;
			break;
		case IMU_REAR_ACC_ID:
			Indicators[ACC_X_REAR].floatValore = ((int16_t)firstInt)/100.0; 	//sono le conversioni DP11 --> verificare quelle nuove!			
			Indicators[ACC_Y_REAR].floatValore = ((int16_t)secondInt)/100.0;
			Indicators[ACC_Z_REAR].floatValore = ((int16_t)thirdInt)/100.0;
			break;
		case IMU_REAR_GYRO_ID:
			Indicators[GYRO_X_REAR].floatValore = ((int16_t)firstInt)/10.0; 	//sono le conversioni DP11 --> verificare quelle nuove!			
			Indicators[GYRO_Y_REAR].floatValore = ((int16_t)secondInt)/10.0;
			Indicators[GYRO_Z_REAR].floatValore = ((int16_t)thirdInt)/10.0;
			break;
		case IMU_REAR_DEBUG_ID:
			Indicators[IMU_REAR_BOARD].intValore2 = firstInt;
			Indicators[IMU_REAR_BOARD].intValore = secondInt;
			break;
		case VCU_FEEDBACK_ID:
			CAN_VCU_feedback(firstInt,secondInt,thirdInt,fourthInt);
//		CAN_VCU_is_alive();  --> Ha senso?
			break;
		case VCU_DRIVER_INPUT_ID:
			dSensors_calculateAPPS(APPS_1, firstInt);
			dSensors_calculateAPPS(APPS_2, secondInt);
			dSensors_calculateRegen(LOAD_CELL,thirdInt);
			Indicators[IMPLAUSIBILITY].intValore = fourthInt;
			break;
		case VCU_CRITICAL_DEBUG_ID:
			//serve il cooling domain? secondo me no 
			Indicators[LVB_VOLTAGE].intValore = secondInt;
			Indicators[DCDC_VOLTAGE].intValore = thirdInt;
			Indicators[VOLTAGE_24V_VCU].intValore = fourthInt;
			break;
		case VCU_DEBUG_1_ID:
			Indicators[VOLTAGE_5V_VCU].intValore = firstInt;
			Indicators[VOLTAGE_3V3_VCU].intValore = secondInt;
			Indicators[LVB_VOLTAGE].intValore2 = thirdInt; //Possiamo togliere GLVS_CURR
			Indicators[PUMP_CURR].intValore = fourthInt;
			break;
		case VCU_DEBUG_2_ID:
			Indicators[DCDC_VOLTAGE].intValore2 = firstInt; //Possiamo togliere GLVS_CURR
			Indicators[BATTERY_FAN_CURR].intValore2 = secondInt;
			Indicators[RAD_FAN_CURR].intValore2 = thirdInt; 
			Indicators[VOLTAGE_24V_VCU].intValore2 = fourthInt; //''
			break;
		case VCU_DEBUG_3_ID:
			Indicators[VCU_BOARD].intValore2 = firstInt; 
			Indicators[VCU_BOARD].intValore = secondInt;
			Indicators[SPEAKER_CURR].intValore2 = thirdInt; 
			break;
		case VCU_COOLING_ID:
			//secondo me non serve acquisirlo
			break;
		case VCU_INSS_X_ID:
			Indicators[INSS_ACC_X].floatValore = (firstInt << 16) | (secondInt & 0xFF); 
			Indicators[INSS_GYRO_X].floatValore = (thirdInt << 16) | (fourthInt & 0xFF);
			break;
		case VCU_INSS_Y_ID:
			Indicators[INSS_ACC_Y].floatValore = (firstInt << 16) | (secondInt & 0xFF); 
			Indicators[INSS_GYRO_Y].floatValore = (thirdInt << 16) | (fourthInt & 0xFF);
			break;
		case VCU_INSS_Z_ID:
			Indicators[INSS_ACC_Z].floatValore = (firstInt << 16) | (secondInt & 0xFF); 
			Indicators[INSS_GYRO_Z].floatValore = (thirdInt << 16) | (fourthInt & 0xFF);
			break;
		case VCU_INSS_SPEED_ID:
			Indicators[INSS_SPEED].floatValore = (firstInt << 16) | (secondInt & 0xFF);
			break;
		case VCU_INSS_LAT_ID:
			Indicators[INSS_LAT].floatValore = (firstInt << 16) | (secondInt & 0xFF); 
			Indicators[INSS_LONG].floatValore = (thirdInt << 16) | (fourthInt & 0xFF);
			break;
		case VCU_INSS_TIME_ID:
			//don't care
			break;
		case VCU_INSS_GPS_ID:
			Indicators[INSS_HDOP].floatValore = (firstInt << 16) | (secondInt & 0xFF);
			Indicators[INSS_N_SETELLITES].floatValore = fourthInt;
			break;
		case VCU_AUX_ID:
			//empty for now
			break;
		case BMS_ACCUMULATOR_VOLTAGE_ID:
			Indicators[V_TS_INVERTER].intValore = firstInt; 
			Indicators[VBAT].intValore = secondInt; //possiamo eliminare V_TS_ACCUMULATOR
			Indicators[SUM_OF_CELLS].intValore = thirdInt;  // a che serve?
			break;
		case BMS_CURRENT_LIMITER_AIR_TEMP_ID:
			// non ce ne frega niente
			break;
		case BMS_ACCUMULATOR_CELL_STATE_ID:
			Indicators[MAX_CELL_VOLTAGE].intValore = firstInt; 
			Indicators[MIN_CELL_VOLTAGE].intValore = secondInt;
			Indicators[MAX_CELL_TEMP].intValore = thirdInt; 
			Indicators[MIN_CELL_TEMP].intValore = fourthInt; 
			break;
		case BMS_ACCUMULATOR_SYSTEM_STATE1_ID:
			Indicators[SOC].intValore = thirdInt;
			break;
		case BMS_ACCUMULATOR_SYSTEM_STATE2_ID:
			// ci serve?
			break;
		case BMS_DEBUG_1_ID:
			Indicators[BMS_MASTER_BOARD].intValore = firstInt;
			Indicators[BMS_MASTER_BOARD].intValore2 = secondInt;
			Indicators[BMS_12V_SENSE].intValore = thirdInt;
			Indicators[BMS_STATE].intValore = fourthInt; 
			break;
		case BMS_DEBUG_2_ID:
			//serve?
			break;
		case BMS_CELL_TEMPERATURE_ID:
			//anche no
			break;
		case BMS_AUX_ID:
			//per ora niente
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

void CAN_changeState(uint8_t mode_feedback)
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

void CAN_DCU_feedback(uint16_t firstInt)	//---------------- da inserire anche VCU
{
	// NB. SOFI HA DEI DISAGI CON LE OPERAZIONI BIT A BIT!
	uint8_t DCUcode, DCUcommand;
	
	DCUcode = (uint8_t)((firstInt >> 8) & 0x00FF);
	DCUcommand = (uint8_t)(firstInt & 0x00FF); //forse non il modo migliore
	
	switch( DCUcode ){
		case DCU_ACQUISITION_FB:
			Indicators[ACQ].intValore = DCUcommand;
			break;
		case DCU_NEW_START_POSITION_FB:
			//flagNewPosition = 1;
			break;
		case DCU_CALIBRATE_SENSOR_FB:
			feedbackDcuCalibration = DCUcommand;
			flagDcuCalibration = 1;	
			break;
		default: 
			break;
	}
}

void CAN_DCU_is_alive(void)
{
	timerDCUAlive = 0;
	DCU_is_dead = 0;
	DCU_was_not_dead = 0;
}

void CAN_targetMessage(void)
{
	uint16_t firstInt, secondInt, thirdInt;
	
	firstInt = 0;
	firstInt = targetMap & 0xFF;
	firstInt = firstInt | (targetMode << 8);
	
	secondInt = 0;
	secondInt = targetTorque & 0xFF;
	secondInt = secondInt | (targetTraction << 8);
	
	thirdInt = 0;
	thirdInt = (( targetKalman << 8 ) || (( Indicators[TS].intValore << 6) & 0x03 ) ||
							(( Indicators[REGEN].intValore << 4) & 0x03 ) || ((Indicators[ACQ].intValore << 2) & 0X03) );
	
	CAN_send(SW_TARGET_ID, firstInt, secondInt, thirdInt, EMPTY, 3);
	
}

void CAN_VCU_feedback(uint16_t firstInt, uint16_t secondInt, uint16_t thirdInt, uint16_t fourthInt)
{
	CAN_changeState((uint8_t)((firstInt >> 8) & 0x00FF));
	Indicators[MAP].intValore = (uint8_t)(firstInt & 0x00FF);
	
	Indicators[TC].intValore = ((uint8_t)((secondInt >> 8) & 0x00FF)); 
	Indicators[TV].intValore = (uint8_t)(secondInt & 0x00FF);
	
	CAN_unpackThirdIntVCU(thirdInt);
	
//	CAN_changeRoutineState((uint8_t)((fourthInt >> 8) & 0x00FF)); --> quando ci sarà una routine di ACC
	feedbackVcuCalibration = (uint8_t)(fourthInt & 0x00FF);
	flagVcuCalibration = 1;	
}


void CAN_unpackThirdIntVCU(uint16_t thirdInt)
{
//		uint8_t keyValue, rtdFBValue;
//		Indicators[KF].intValore = ...; c'è una ragione se ishac non ha messo l'indicator del kf?
//		Indicators[POW_LIM].intValore = ...; operazione bit a bit da fare
//		Indicators[REGEN].intValore = ...; '' 

//		keyValue =  ...; solita operazione bit a bit
// 		rtdFBValue = ...; ''

// 		if( keyValue == TS_OFF && rtdFBValue == TS_OFF )
//				Indicators[TS].intValore = TS_OFF;
//		else if( keyValue == TS_ON && rtdFBValue == TS_OFF )
//				Indicators[TS].intValore = TS_ON;
//		else if( keyValue == TS_ON && rtdFBValue == TS_RTD )
//				Indicators[TS].intValore = TS_RTD;
//		else
//				PROBLEMA!!

}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
