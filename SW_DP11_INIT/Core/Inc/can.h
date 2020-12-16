/**
  ******************************************************************************
  * File Name          : CAN.h
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __can_H
#define __can_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "id_can.h"
/* USER CODE END Includes */

extern CAN_HandleTypeDef hcan1;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_CAN1_Init(void);

/* USER CODE BEGIN Prototypes */

extern void CAN_Start(void);
static void CAN_filterConfig(void);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
void CAN_receive(int ID, uint16_t firstInt, uint16_t secondInt, uint16_t thirdInt, uint16_t fourthInt);
void CAN_send(int ID, uint16_t firstInt, uint16_t secondInt, uint16_t thirdInt, uint16_t fourthInt, uint8_t dlc_value);
void CAN_changeState(uint8_t mode_feedback);
void CAN_changeRoutineState(int routine_state);
void CAN_DCU_feedback(uint16_t firstInt);
void CAN_VCU_feedback(uint16_t firstInt, uint16_t secondInt, uint16_t thirdInt, uint16_t fourthInt);
void CAN_unpackThirdIntVCU(uint16_t thirdInt);
void CAN_DCU_is_alive(void);
void CAN_GCU_is_alive(void);
void CAN_targetMessage(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ can_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
