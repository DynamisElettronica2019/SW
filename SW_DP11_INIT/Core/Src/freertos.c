/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     

#include "gpio.h"
#include "i2c.h"
#include "adc.h"
#include "tim.h"
#include "can.h"

#include "general.h"
#include "data.h"

#include "d_gears.h"
#include "d_rpm_limiter.h"
#include "d_sensors.h"
#include "d_traction_control.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
extern void dGear_setNeutral(void);
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

char driveMode, engineMap;
char leftPosition, rightPosition;
int state;

int timerClutch = 0;
int timerTempCurr = 0;
int okButtonPressed = 0;

extern BaseType_t xHigherPriorityTaskWoken;

extern Indicator_Value Indicators[N_INDICATORS];


/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId ledBlink_TaskHandle;
osThreadId can_TaskHandle;
osThreadId upShift_TaskHandle;
osThreadId downShift_TaskHandle;
osThreadId modeSel_TaskHandle;
osThreadId mapSel_TaskHandle;
osThreadId leftEnc_TaskHandle;
osThreadId rightEnc_TaskHandle;
osThreadId startBut_TaskHandle;
osThreadId neutralBut_TaskHandle;
osThreadId okBut_TaskHandle;
osThreadId aux1But_TaskHandle;
osThreadId aux2But_TaskHandle;
osThreadId aux3But_TaskHandle;
osThreadId rpmStripe_TaskHandle;
osThreadId sensors_TaskHandle;
osThreadId acc_TaskHandle;
osThreadId autox_TaskHandle;
osThreadId end_TaskHandle;
osThreadId skidpad_TaskHandle;
osThreadId settings_TaskHandle;
osThreadId debug_TaskHandle;
osThreadId boardDebug_TaskHandle;
osThreadId debugFrtos_taskHandle;
osThreadId aux1_TaskHandle;
osThreadId aux2_TaskHandle;
osMessageQId canQueueHandle;
osSemaphoreId canSemaphoreHandle;
osSemaphoreId upShiftSemaphoreHandle;
osSemaphoreId downShiftSemaphoreHandle;
osSemaphoreId modeSelectorSemaphoreHandle;
osSemaphoreId mapSelectorSemaphoreHandle;
osSemaphoreId leftEncoderSemaphoreHandle;
osSemaphoreId rightEncoderSemaphoreHandle;
osSemaphoreId startButtonSemaphoreHandle;
osSemaphoreId neutralButtonSemaphoreHandle;
osSemaphoreId okButtonSemaphoreHandle;
osSemaphoreId aux1ButtonSemaphoreHandle;
osSemaphoreId aux2ButtonSemaphoreHandle;
osSemaphoreId aux3ButtonSemaphoreHandle;
osSemaphoreId rpmStripeSemaphoreHandle;
osSemaphoreId sensorsSemaphoreHandle;
osSemaphoreId accelerationModeSemaphoreHandle;
osSemaphoreId autocrossModeSemaphoreHandle;
osSemaphoreId enduranceModeSemaphoreHandle;
osSemaphoreId skidpadModeSemaphoreHandle;
osSemaphoreId settingsModeSemaphoreHandle;
osSemaphoreId debugModeSemaphoreHandle;
osSemaphoreId boardDebugModeSemaphoreHandle;
osSemaphoreId debugFreeRTOSSemaphoreHandle;
osSemaphoreId aux1SemaphoreHandle;
osSemaphoreId aux2SemaphoreHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void ledBlinkTask(void const * argument);
void canTask(void const * argument);
void upShiftTask(void const * argument);
void downShiftTask(void const * argument);
void modeSelectorTask(void const * argument);
void mapSelectorTask(void const * argument);
void leftEncoderTask(void const * argument);
void rightEncoderTask(void const * argument);
void startButtonTask(void const * argument);
void neutralButtonTask(void const * argument);
void okButtonTask(void const * argument);
void aux1ButtonTask(void const * argument);
void aux2ButtonTask(void const * argument);
void aux3ButtonTask(void const * argument);
void rpmStripeTask(void const * argument);
void sensorsTask(void const * argument);
void accelerationModeTask(void const * argument);
void autocrossModeTask(void const * argument);
void enduranceModeTask(void const * argument);
void skidpadModeTask(void const * argument);
void settingsModeTask(void const * argument);
void debugModeTask(void const * argument);
void boardDebugModeTask(void const * argument);
void debugFreeRTOSTask(void const * argument);
void aux1Task(void const * argument);
void aux2Task(void const * argument);

extern void MX_GRAPHICS_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationIdleHook(void);
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);
void vApplicationMallocFailedHook(void);

/* USER CODE BEGIN 2 */
__weak void vApplicationIdleHook( void )
{
   /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
   task. It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()). If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
}
/* USER CODE END 2 */

/* USER CODE BEGIN 4 */
__weak void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
   /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
   called if a stack overflow is detected. */
}
/* USER CODE END 4 */

/* USER CODE BEGIN 5 */
__weak void vApplicationMallocFailedHook(void)
{
   /* vApplicationMallocFailedHook() will only be called if
   configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h. It is a hook
   function that will get called if a call to pvPortMalloc() fails.
   pvPortMalloc() is called internally by the kernel whenever a task, queue,
   timer or semaphore is created. It is also called by various parts of the
   demo application. If heap_1.c or heap_2.c are used, then the size of the
   heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
   FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
   to query the size of free heap space that remains (although it does not
   provide information on how the remaining heap might be fragmented). */
}
/* USER CODE END 5 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of canSemaphore */
  osSemaphoreDef(canSemaphore);
  canSemaphoreHandle = osSemaphoreCreate(osSemaphore(canSemaphore), 1);

  /* definition and creation of upShiftSemaphore */
  osSemaphoreDef(upShiftSemaphore);
  upShiftSemaphoreHandle = osSemaphoreCreate(osSemaphore(upShiftSemaphore), 1);

  /* definition and creation of downShiftSemaphore */
  osSemaphoreDef(downShiftSemaphore);
  downShiftSemaphoreHandle = osSemaphoreCreate(osSemaphore(downShiftSemaphore), 1);

  /* definition and creation of modeSelectorSemaphore */
  osSemaphoreDef(modeSelectorSemaphore);
  modeSelectorSemaphoreHandle = osSemaphoreCreate(osSemaphore(modeSelectorSemaphore), 1);

  /* definition and creation of mapSelectorSemaphore */
  osSemaphoreDef(mapSelectorSemaphore);
  mapSelectorSemaphoreHandle = osSemaphoreCreate(osSemaphore(mapSelectorSemaphore), 1);

  /* definition and creation of leftEncoderSemaphore */
  osSemaphoreDef(leftEncoderSemaphore);
  leftEncoderSemaphoreHandle = osSemaphoreCreate(osSemaphore(leftEncoderSemaphore), 1);

  /* definition and creation of rightEncoderSemaphore */
  osSemaphoreDef(rightEncoderSemaphore);
  rightEncoderSemaphoreHandle = osSemaphoreCreate(osSemaphore(rightEncoderSemaphore), 1);

  /* definition and creation of startButtonSemaphore */
  osSemaphoreDef(startButtonSemaphore);
  startButtonSemaphoreHandle = osSemaphoreCreate(osSemaphore(startButtonSemaphore), 1);

  /* definition and creation of neutralButtonSemaphore */
  osSemaphoreDef(neutralButtonSemaphore);
  neutralButtonSemaphoreHandle = osSemaphoreCreate(osSemaphore(neutralButtonSemaphore), 1);

  /* definition and creation of okButtonSemaphore */
  osSemaphoreDef(okButtonSemaphore);
  okButtonSemaphoreHandle = osSemaphoreCreate(osSemaphore(okButtonSemaphore), 1);

  /* definition and creation of aux1ButtonSemaphore */
  osSemaphoreDef(aux1ButtonSemaphore);
  aux1ButtonSemaphoreHandle = osSemaphoreCreate(osSemaphore(aux1ButtonSemaphore), 1);

  /* definition and creation of aux2ButtonSemaphore */
  osSemaphoreDef(aux2ButtonSemaphore);
  aux2ButtonSemaphoreHandle = osSemaphoreCreate(osSemaphore(aux2ButtonSemaphore), 1);

  /* definition and creation of aux3ButtonSemaphore */
  osSemaphoreDef(aux3ButtonSemaphore);
  aux3ButtonSemaphoreHandle = osSemaphoreCreate(osSemaphore(aux3ButtonSemaphore), 1);

  /* definition and creation of rpmStripeSemaphore */
  osSemaphoreDef(rpmStripeSemaphore);
  rpmStripeSemaphoreHandle = osSemaphoreCreate(osSemaphore(rpmStripeSemaphore), 1);

  /* definition and creation of sensorsSemaphore */
  osSemaphoreDef(sensorsSemaphore);
  sensorsSemaphoreHandle = osSemaphoreCreate(osSemaphore(sensorsSemaphore), 1);

  /* definition and creation of accelerationModeSemaphore */
  osSemaphoreDef(accelerationModeSemaphore);
  accelerationModeSemaphoreHandle = osSemaphoreCreate(osSemaphore(accelerationModeSemaphore), 1);

  /* definition and creation of autocrossModeSemaphore */
  osSemaphoreDef(autocrossModeSemaphore);
  autocrossModeSemaphoreHandle = osSemaphoreCreate(osSemaphore(autocrossModeSemaphore), 1);

  /* definition and creation of enduranceModeSemaphore */
  osSemaphoreDef(enduranceModeSemaphore);
  enduranceModeSemaphoreHandle = osSemaphoreCreate(osSemaphore(enduranceModeSemaphore), 1);

  /* definition and creation of skidpadModeSemaphore */
  osSemaphoreDef(skidpadModeSemaphore);
  skidpadModeSemaphoreHandle = osSemaphoreCreate(osSemaphore(skidpadModeSemaphore), 1);

  /* definition and creation of settingsModeSemaphore */
  osSemaphoreDef(settingsModeSemaphore);
  settingsModeSemaphoreHandle = osSemaphoreCreate(osSemaphore(settingsModeSemaphore), 1);

  /* definition and creation of debugModeSemaphore */
  osSemaphoreDef(debugModeSemaphore);
  debugModeSemaphoreHandle = osSemaphoreCreate(osSemaphore(debugModeSemaphore), 1);

  /* definition and creation of boardDebugModeSemaphore */
  osSemaphoreDef(boardDebugModeSemaphore);
  boardDebugModeSemaphoreHandle = osSemaphoreCreate(osSemaphore(boardDebugModeSemaphore), 1);

  /* definition and creation of debugFreeRTOSSemaphore */
  osSemaphoreDef(debugFreeRTOSSemaphore);
  debugFreeRTOSSemaphoreHandle = osSemaphoreCreate(osSemaphore(debugFreeRTOSSemaphore), 1);

  /* definition and creation of aux1Semaphore */
  osSemaphoreDef(aux1Semaphore);
  aux1SemaphoreHandle = osSemaphoreCreate(osSemaphore(aux1Semaphore), 1);

  /* definition and creation of aux2Semaphore */
  osSemaphoreDef(aux2Semaphore);
  aux2SemaphoreHandle = osSemaphoreCreate(osSemaphore(aux2Semaphore), 1);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
	xSemaphoreTake(aux1ButtonSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(aux2ButtonSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(aux3ButtonSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(canSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(upShiftSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(downShiftSemaphoreHandle, portMAX_DELAY);
	//xSemaphoreTake(modeSelectorSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(mapSelectorSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(leftEncoderSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(rightEncoderSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(startButtonSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(neutralButtonSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(okButtonSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(rpmStripeSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(sensorsSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(accelerationModeSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(autocrossModeSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(enduranceModeSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(skidpadModeSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(settingsModeSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(debugModeSemaphoreHandle, portMAX_DELAY);
	xSemaphoreTake(boardDebugModeSemaphoreHandle, portMAX_DELAY);
	
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
	
	HAL_TIM_Base_Start_IT(&htim7);
	
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 4096);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of ledBlink_Task */
  osThreadDef(ledBlink_Task, ledBlinkTask, osPriorityIdle, 0, 128);
  ledBlink_TaskHandle = osThreadCreate(osThread(ledBlink_Task), NULL);

  /* definition and creation of can_Task */
  osThreadDef(can_Task, canTask, osPriorityAboveNormal, 0, 128);
  can_TaskHandle = osThreadCreate(osThread(can_Task), NULL);

  /* definition and creation of upShift_Task */
  osThreadDef(upShift_Task, upShiftTask, osPriorityAboveNormal, 0, 128);
  upShift_TaskHandle = osThreadCreate(osThread(upShift_Task), NULL);

  /* definition and creation of downShift_Task */
  osThreadDef(downShift_Task, downShiftTask, osPriorityAboveNormal, 0, 128);
  downShift_TaskHandle = osThreadCreate(osThread(downShift_Task), NULL);

  /* definition and creation of modeSel_Task */
  osThreadDef(modeSel_Task, modeSelectorTask, osPriorityAboveNormal, 0, 128);
  modeSel_TaskHandle = osThreadCreate(osThread(modeSel_Task), NULL);

  /* definition and creation of mapSel_Task */
  osThreadDef(mapSel_Task, mapSelectorTask, osPriorityNormal, 0, 128);
  mapSel_TaskHandle = osThreadCreate(osThread(mapSel_Task), NULL);

  /* definition and creation of leftEnc_Task */
  osThreadDef(leftEnc_Task, leftEncoderTask, osPriorityNormal, 0, 128);
  leftEnc_TaskHandle = osThreadCreate(osThread(leftEnc_Task), NULL);

  /* definition and creation of rightEnc_Task */
  osThreadDef(rightEnc_Task, rightEncoderTask, osPriorityNormal, 0, 128);
  rightEnc_TaskHandle = osThreadCreate(osThread(rightEnc_Task), NULL);

  /* definition and creation of startBut_Task */
  osThreadDef(startBut_Task, startButtonTask, osPriorityAboveNormal, 0, 128);
  startBut_TaskHandle = osThreadCreate(osThread(startBut_Task), NULL);

  /* definition and creation of neutralBut_Task */
  osThreadDef(neutralBut_Task, neutralButtonTask, osPriorityNormal, 0, 128);
  neutralBut_TaskHandle = osThreadCreate(osThread(neutralBut_Task), NULL);

  /* definition and creation of okBut_Task */
  osThreadDef(okBut_Task, okButtonTask, osPriorityNormal, 0, 128);
  okBut_TaskHandle = osThreadCreate(osThread(okBut_Task), NULL);

  /* definition and creation of aux1But_Task */
  osThreadDef(aux1But_Task, aux1ButtonTask, osPriorityNormal, 0, 128);
  aux1But_TaskHandle = osThreadCreate(osThread(aux1But_Task), NULL);

  /* definition and creation of aux2But_Task */
  osThreadDef(aux2But_Task, aux2ButtonTask, osPriorityNormal, 0, 128);
  aux2But_TaskHandle = osThreadCreate(osThread(aux2But_Task), NULL);

  /* definition and creation of aux3But_Task */
  osThreadDef(aux3But_Task, aux3ButtonTask, osPriorityNormal, 0, 128);
  aux3But_TaskHandle = osThreadCreate(osThread(aux3But_Task), NULL);

  /* definition and creation of rpmStripe_Task */
  osThreadDef(rpmStripe_Task, rpmStripeTask, osPriorityNormal, 0, 128);
  rpmStripe_TaskHandle = osThreadCreate(osThread(rpmStripe_Task), NULL);

  /* definition and creation of sensors_Task */
  osThreadDef(sensors_Task, sensorsTask, osPriorityNormal, 0, 128);
  sensors_TaskHandle = osThreadCreate(osThread(sensors_Task), NULL);

  /* definition and creation of acc_Task */
  osThreadDef(acc_Task, accelerationModeTask, osPriorityNormal, 0, 128);
  acc_TaskHandle = osThreadCreate(osThread(acc_Task), NULL);

  /* definition and creation of autox_Task */
  osThreadDef(autox_Task, autocrossModeTask, osPriorityNormal, 0, 128);
  autox_TaskHandle = osThreadCreate(osThread(autox_Task), NULL);

  /* definition and creation of end_Task */
  osThreadDef(end_Task, enduranceModeTask, osPriorityNormal, 0, 128);
  end_TaskHandle = osThreadCreate(osThread(end_Task), NULL);

  /* definition and creation of skidpad_Task */
  osThreadDef(skidpad_Task, skidpadModeTask, osPriorityNormal, 0, 128);
  skidpad_TaskHandle = osThreadCreate(osThread(skidpad_Task), NULL);

  /* definition and creation of settings_Task */
  osThreadDef(settings_Task, settingsModeTask, osPriorityNormal, 0, 128);
  settings_TaskHandle = osThreadCreate(osThread(settings_Task), NULL);

  /* definition and creation of debug_Task */
  osThreadDef(debug_Task, debugModeTask, osPriorityNormal, 0, 128);
  debug_TaskHandle = osThreadCreate(osThread(debug_Task), NULL);

  /* definition and creation of boardDebug_Task */
  osThreadDef(boardDebug_Task, boardDebugModeTask, osPriorityNormal, 0, 128);
  boardDebug_TaskHandle = osThreadCreate(osThread(boardDebug_Task), NULL);

  /* definition and creation of debugFrtos_task */
  osThreadDef(debugFrtos_task, debugFreeRTOSTask, osPriorityNormal, 0, 128);
  debugFrtos_taskHandle = osThreadCreate(osThread(debugFrtos_task), NULL);

  /* definition and creation of aux1_Task */
  osThreadDef(aux1_Task, aux1Task, osPriorityNormal, 0, 128);
  aux1_TaskHandle = osThreadCreate(osThread(aux1_Task), NULL);

  /* definition and creation of aux2_Task */
  osThreadDef(aux2_Task, aux2Task, osPriorityNormal, 0, 128);
  aux2_TaskHandle = osThreadCreate(osThread(aux2_Task), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Create the queue(s) */
  /* definition and creation of canQueue */
  osMessageQDef(canQueue, 8, CAN_RxPacketTypeDef);
  canQueueHandle = osMessageCreate(osMessageQ(canQueue), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
	
  /* USER CODE END RTOS_QUEUES */
}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{

/* Graphic application */  
  GRAPHICS_MainTask();

  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_ledBlinkTask */
/**
* @brief Function implementing the ledBlink_Task thread.
* @param argument: Not used
* @retval None
*/


/* USER CODE END Header_ledBlinkTask */
void ledBlinkTask(void const * argument)
{
  /* USER CODE BEGIN ledBlinkTask */
  /* Infinite loop */
  for(;;)
  {
		HAL_GPIO_TogglePin(DEBUG_LED_1_GPIO_Port, DEBUG_LED_1_Pin);

//		Indicators[TRACTION_CONTROL].intValore = state;
		
//		Indicators[DRIVE_MODE].intValore = driveMode;		//--- da togliere, solo per debug
//		Indicators[MAP].intValore = engineMap;		//--- da togliere, solo per debug
		
    osDelay(250);
  }
  /* USER CODE END ledBlinkTask */
}

/* USER CODE BEGIN Header_canTask */
/**
* @brief Function implementing the can_Task thread.

* @param argument: Not used
* @retval None
*/

#define NUCLEO 0x1F4
#define CAN_DEBUGGER 0x234

/* USER CODE END Header_canTask */
void canTask(void const * argument)
{
  /* USER CODE BEGIN canTask */
	CAN_RxPacketTypeDef canMessageRX;
	uint16_t firstInt, secondInt, thirdInt, fourthInt;
  /* Infinite loop */
  for(;;)
  {
		if(xQueueReceive(canQueueHandle, &canMessageRX, portMAX_DELAY))
		{
			firstInt 	= (unsigned int) ((canMessageRX.CAN_RxPacket_Data[0] << 8) | (canMessageRX.CAN_RxPacket_Data[1] & 0xFF));
			secondInt = (unsigned int) ((canMessageRX.CAN_RxPacket_Data[2] << 8) | (canMessageRX.CAN_RxPacket_Data[3] & 0xFF));
			thirdInt 	= (unsigned int) ((canMessageRX.CAN_RxPacket_Data[4] << 8) | (canMessageRX.CAN_RxPacket_Data[5] & 0xFF));
			fourthInt = (unsigned int) ((canMessageRX.CAN_RxPacket_Data[6] << 8) | (canMessageRX.CAN_RxPacket_Data[7] & 0xFF));
			CAN_receive(canMessageRX.CAN_RxPacket_Header.StdId, firstInt, secondInt, thirdInt, fourthInt);
		}
    osDelay(1);
  }
  /* USER CODE END canTask */
}

/* USER CODE BEGIN Header_upShiftTask */
/**
* @brief Function implementing the upShift_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_upShiftTask */
void upShiftTask(void const * argument)
{
  /* USER CODE BEGIN upShiftTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(upShiftSemaphoreHandle, portMAX_DELAY);
		vTaskDelay(80/portTICK_PERIOD_MS);
		if ( 0 == HAL_GPIO_ReadPin(SHIFT_UP_INT_GPIO_Port, SHIFT_UP_INT_Pin) )
			dGears_upShift();
		vTaskDelay(100/portTICK_PERIOD_MS);
    osDelay(1);
  }
  /* USER CODE END upShiftTask */
}

/* USER CODE BEGIN Header_downShiftTask */
/**
* @brief Function implementing the downShift_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_downShiftTask */
void downShiftTask(void const * argument)
{
  /* USER CODE BEGIN downShiftTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(downShiftSemaphoreHandle, portMAX_DELAY);
		vTaskDelay(80/portTICK_PERIOD_MS);
		if ( 0 == HAL_GPIO_ReadPin(SHIFT_DOWN_INT_GPIO_Port, SHIFT_DOWN_INT_Pin) )
			dGears_downShift();
		vTaskDelay(100/portTICK_PERIOD_MS);
    osDelay(1);
  }
  /* USER CODE END downShiftTask */
}

/* USER CODE BEGIN Header_modeSelectorTask */
/**
* @brief Function implementing the modeSel_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_modeSelectorTask */
void modeSelectorTask(void const * argument)
{
  /* USER CODE BEGIN modeSelectorTask */
	char old_driveMode;
	
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(modeSelectorSemaphoreHandle, portMAX_DELAY);
		vTaskDelay(50/portTICK_PERIOD_MS);
		old_driveMode = driveMode;
		GPIO_driveMode_set();
		if (old_driveMode == SETTINGS_MODE)
		{
			// save settings on eeprom
			I2C_save_Pointers();
		}
		switch (driveMode)
		{
			case AUTOX_MODE:
					state = AUTOX_MODE_START;
				break;
			case ACCELERATION_MODE:
					state = ACCELERATION_MODE_START;
				break;
			case ENDURANCE_MODE:
					state = ENDURANCE_MODE_START;
				break;
			case SKIDPAD_MODE:
					state = SKIDPAD_MODE_START;
				break;
			case DEBUG_MODE:
					state = DEBUG_MODE_DEFAULT;
				break;
			case BOARD_DEBUG_MODE:
					state = BOARD_DEBUG_MODE_DEFAULT;
				break;
			case SETTINGS_MODE:
					state = SETTINGS_MODE_DEFAULT;
				break;
		}
		
		osDelay(1);
  }	
  /* USER CODE END modeSelectorTask */
}

/* USER CODE BEGIN Header_mapSelectorTask */
/**
* @brief Function implementing the mapSel_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_mapSelectorTask */
void mapSelectorTask(void const * argument)
{
  /* USER CODE BEGIN mapSelectorTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(mapSelectorSemaphoreHandle, portMAX_DELAY);
		vTaskDelay(50/portTICK_PERIOD_MS);
		
		GPIO_engineMap_set();
		
		//invio su can della mappa - polling ? appena si accende efi ? 
		
    osDelay(1);
  }
  /* USER CODE END mapSelectorTask */
}

/* USER CODE BEGIN Header_leftEncoderTask */
/**
* @brief Function implementing the leftEnc_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_leftEncoderTask */
void leftEncoderTask(void const * argument)
{
  /* USER CODE BEGIN leftEncoderTask */
  int movement = 0;
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(leftEncoderSemaphoreHandle, portMAX_DELAY);
		vTaskDelay(50/portTICK_PERIOD_MS);
		movement = GPIO_leftEncoder_movement();
//		leftPosition = leftPosition + movement; 
//		if (leftPosition > 7 )
//			leftPosition = 0;
//		else if (leftPosition < 0 )
//			leftPosition = 7;
		//Indicators[TRACTION_CONTROL].intValore = leftPosition;
		//Indicators[MAP].intValore = leftPosition;
		// leftposition magari non serve - dobbiamo vedere se � meglio ci serve
		// la posizione relativa o assoluta
		
		switch(driveMode)
		{
			case AUTOX_MODE:
			case ACCELERATION_MODE:
			case ENDURANCE_MODE:
			case SKIDPAD_MODE:
				d_traction_control_setValue(movement);
				break;
			case BOARD_DEBUG_MODE:
				GPIO_leftEncoder_boardDebugMode(movement);
				break;		
			case DEBUG_MODE:
			  GPIO_leftEncoder_debugMode(movement);
				break;
			case SETTINGS_MODE:
				GPIO_leftEncoder_settingsMode(movement);
				break;
			default: 
				break;
		}
    osDelay(1);
  }
  /* USER CODE END leftEncoderTask */
}

/* USER CODE BEGIN Header_rightEncoderTask */
/**
* @brief Function implementing the rightEnc_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_rightEncoderTask */
void rightEncoderTask(void const * argument)
{
  /* USER CODE BEGIN rightEncoderTask */
  int movement = 0;
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(rightEncoderSemaphoreHandle, portMAX_DELAY);
		vTaskDelay(50/portTICK_PERIOD_MS);
		movement = GPIO_rightEncoder_movement();
//	  rightPosition = rightPosition + movement;
//		if (rightPosition > 7 )
//			rightPosition = 0;
//		else if (rightPosition < 0 )
//			rightPosition = 7;
		//Indicators[MAP].intValore = rightPosition;
		
		switch(driveMode)
		{
			case AUTOX_MODE:
			case ACCELERATION_MODE:
				d_rpm_limiter_setValue(movement);
				break;
			case BOARD_DEBUG_MODE:
				GPIO_rightEncoder_boardDebugMode(movement);
				break;
			case DEBUG_MODE:
				GPIO_rightEncoder_debugMode(movement);
				break;
			case SETTINGS_MODE:
				GPIO_rightEncoder_settingsMode(movement);
				break;
			default: 
				break;
		}
    osDelay(1);
	}
  /* USER CODE END rightEncoderTask */
}

/* USER CODE BEGIN Header_startButtonTask */
/**
* @brief Function implementing the startBut_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startButtonTask */
void startButtonTask(void const * argument)
{
  /* USER CODE BEGIN startButtonTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(startButtonSemaphoreHandle, portMAX_DELAY);
		
		if( 0 == HAL_GPIO_ReadPin(START_BUTTON_INT_GPIO_Port, START_BUTTON_INT_Pin) )
		{
			CAN_send(SW_FIRE_GCU_ID, TRUE, EMPTY, EMPTY, EMPTY, 1);
		}

    osDelay(1);
  }
  /* USER CODE END startButtonTask */
}

/* USER CODE BEGIN Header_neutralButtonTask */
/**
* @brief Function implementing the neutralBut_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_neutralButtonTask */
void neutralButtonTask(void const * argument)
{
  /* USER CODE BEGIN neutralButtonTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(neutralButtonSemaphoreHandle, portMAX_DELAY);
		dGear_setNeutral();
		vTaskDelay(50/portTICK_PERIOD_MS);
    osDelay(1);
  }
  /* USER CODE END neutralButtonTask */
}

/* USER CODE BEGIN Header_okButtonTask */
/**
* @brief Function implementing the okBut_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_okButtonTask */
void okButtonTask(void const * argument)
{
  /* USER CODE BEGIN okButtonTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(okButtonSemaphoreHandle, portMAX_DELAY);
		//vTaskDelay(50/portTICK_PERIOD_MS);
		GPIO_okButton_handle();
		vTaskDelay(200/portTICK_PERIOD_MS);
		okButtonPressed = 0;
    osDelay(1);
  }
  /* USER CODE END okButtonTask */
}

/* USER CODE BEGIN Header_aux1ButtonTask */
/**
* @brief Function implementing the aux1But_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_aux1ButtonTask */
void aux1ButtonTask(void const * argument)
{
  /* USER CODE BEGIN aux1ButtonTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(aux1ButtonSemaphoreHandle, portMAX_DELAY);
		vTaskDelay(50/portTICK_PERIOD_MS);
		GPIO_aux1Button_handle();
		
    osDelay(1);
  }
  /* USER CODE END aux1ButtonTask */
}

/* USER CODE BEGIN Header_aux2ButtonTask */
/**
* @brief Function implementing the aux2But_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_aux2ButtonTask */
void aux2ButtonTask(void const * argument)
{
  /* USER CODE BEGIN aux2ButtonTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(aux2ButtonSemaphoreHandle, portMAX_DELAY);
		vTaskDelay(200/portTICK_PERIOD_MS);
		GPIO_aux2Button_handle();
    osDelay(1);
  }
  /* USER CODE END aux2ButtonTask */
}

/* USER CODE BEGIN Header_aux3ButtonTask */
/**
* @brief Function implementing the aux3But_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_aux3ButtonTask */
void aux3ButtonTask(void const * argument)
{
  /* USER CODE BEGIN aux3ButtonTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(aux3ButtonSemaphoreHandle, portMAX_DELAY);
		vTaskDelay(50/portTICK_PERIOD_MS);
    osDelay(1);
  }
  /* USER CODE END aux3ButtonTask */
}

/* USER CODE BEGIN Header_rpmStripeTask */
/**
* @brief Function implementing the rpmStripe_Task thread.
* @param argument: Not used
* @retval None
*/


/* USER CODE END Header_rpmStripeTask */
void rpmStripeTask(void const * argument)
{
  /* USER CODE BEGIN rpmStripeTask */

  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(rpmStripeSemaphoreHandle, portMAX_DELAY);
		
		I2C_rpm_update();

    osDelay(1);
  }
  /* USER CODE END rpmStripeTask */
}

/* USER CODE BEGIN Header_sensorsTask */
/**
* @brief Function implementing the sensors_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_sensorsTask */
void sensorsTask(void const * argument)
{
  /* USER CODE BEGIN sensorsTask */

  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(sensorsSemaphoreHandle, portMAX_DELAY);
		
		timerClutch = timerClutch + 1;
		timerTempCurr = timerTempCurr + 1;
		
		ADC_read();
		
	  dSensors_Clutch_send();	
		
		if (timerTempCurr >= SENSORS_SEND_TIME){
			dSensors_Sensors_send();	
			timerTempCurr = 0;
		}
		
    osDelay(1);
  }
  /* USER CODE END sensorsTask */
}

/* USER CODE BEGIN Header_accelerationModeTask */
/**
* @brief Function implementing the acc_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_accelerationModeTask */
void accelerationModeTask(void const * argument)
{
  /* USER CODE BEGIN accelerationModeTask */
 /* Infinite loop */
  for(;;)
  {	
		xSemaphoreTake(accelerationModeSemaphoreHandle, portMAX_DELAY);
    switch(state)
		{
			case ACCELERATION_MODE_START:
				break;
			case ACCELERATION_MODE_FEEDBACK:
				state = ACCELERATION_MODE_DEFAULT;
				break;
			case ACCELERATION_MODE_READY:
				// stampa a schermo mex READY ?
				break;
			case ACCELERATION_MODE_GO:
				// stampa a schermo mex GO - per un tot di sec? 
			case ACCELERATION_MODE_DEFAULT:
				break;
		}
		osDelay(1);
  }
  /* USER CODE END accelerationModeTask */
}

/* USER CODE BEGIN Header_autocrossModeTask */
/**
* @brief Function implementing the autox_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_autocrossModeTask */
void autocrossModeTask(void const * argument)
{
  /* USER CODE BEGIN autocrossModeTask */
   /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(autocrossModeSemaphoreHandle, portMAX_DELAY);
    switch(state)
		{
			case AUTOX_MODE_START:
				break;
			case AUTOX_MODE_FEEDBACK:
				state = AUTOX_MODE_DEFAULT;
				break;
			case AUTOX_MODE_READY:
				// stampa a schermo mex READY ?
				break;
			case AUTOX_MODE_GO:
				// stampa a schermo mex GO ? 
			case AUTOX_MODE_DEFAULT:
				break;
		}
		osDelay(1);
  }
  /* USER CODE END autocrossModeTask */
}

/* USER CODE BEGIN Header_enduranceModeTask */
/**
* @brief Function implementing the end_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_enduranceModeTask */
void enduranceModeTask(void const * argument)
{
  /* USER CODE BEGIN enduranceModeTask */
  /* Infinite loop */
   for(;;)
  {
		xSemaphoreTake(enduranceModeSemaphoreHandle, portMAX_DELAY);
    switch(state)
		{
			case ENDURANCE_MODE_START:
				break;
			case ENDURANCE_MODE_FEEDBACK:
				state = ENDURANCE_MODE_DEFAULT;
				break;
			case ENDURANCE_MODE_DEFAULT:
				break;
		}
		osDelay(1);
  }
  /* USER CODE END enduranceModeTask */
}

/* USER CODE BEGIN Header_skidpadModeTask */
/**
* @brief Function implementing the skidpad_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_skidpadModeTask */
void skidpadModeTask(void const * argument)
{
  /* USER CODE BEGIN skidpadModeTask */
 /* Infinite loop */
 for(;;)
 {
		xSemaphoreTake(skidpadModeSemaphoreHandle, portMAX_DELAY);
		switch(state)
		{
			case SKIDPAD_MODE_START:
				break;
			case SKIDPAD_MODE_FEEDBACK:
				state = SKIDPAD_MODE_DEFAULT;
				break;
			case SKIDPAD_MODE_DEFAULT:
				break;
		}
		osDelay(1);
  }
  /* USER CODE END skidpadModeTask */
}

/* USER CODE BEGIN Header_settingsModeTask */
/**
* @brief Function implementing the settings_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_settingsModeTask */
void settingsModeTask(void const * argument)
{
  /* USER CODE BEGIN settingsModeTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(settingsModeSemaphoreHandle, portMAX_DELAY);
    switch(state)
		{
			case SETTINGS_MODE_DEFAULT:
				break;
		}
		osDelay(1);
  }
  /* USER CODE END settingsModeTask */
}

/* USER CODE BEGIN Header_debugModeTask */
/**
* @brief Function implementing the debug_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_debugModeTask */
void debugModeTask(void const * argument)
{
  /* USER CODE BEGIN debugModeTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(debugModeSemaphoreHandle, portMAX_DELAY);
    switch(state)
		{
			case DEBUG_MODE_DEFAULT:
				break;
		}
		osDelay(1);
  }
  /* USER CODE END debugModeTask */
}

/* USER CODE BEGIN Header_boardDebugModeTask */
/**
* @brief Function implementing the boardDebug_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_boardDebugModeTask */
void boardDebugModeTask(void const * argument)
{
  /* USER CODE BEGIN boardDebugModeTask */
   /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(boardDebugModeSemaphoreHandle, portMAX_DELAY);
    switch(state)
		{
			case BOARD_DEBUG_MODE_DEFAULT:
				break;
		}
		osDelay(1);
  }
  /* USER CODE END boardDebugModeTask */
}

/* USER CODE BEGIN Header_debugFreeRTOSTask */
/**
* @brief Function implementing the debugFrtos_task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_debugFreeRTOSTask */
void debugFreeRTOSTask(void const * argument)
{
  /* USER CODE BEGIN debugFreeRTOSTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(debugFreeRTOSSemaphoreHandle, portMAX_DELAY);
    osDelay(1);
  }
  /* USER CODE END debugFreeRTOSTask */
}

/* USER CODE BEGIN Header_aux1Task */
/**
* @brief Function implementing the aux1_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_aux1Task */
void aux1Task(void const * argument)
{
  /* USER CODE BEGIN aux1Task */
	
	//uint8_t indirizzo = 11;
	
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(aux1SemaphoreHandle, portMAX_DELAY);
		
    osDelay(1);
  }
  /* USER CODE END aux1Task */
}

/* USER CODE BEGIN Header_aux2Task */
/**
* @brief Function implementing the aux2_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_aux2Task */
void aux2Task(void const * argument)
{
  /* USER CODE BEGIN aux2Task */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(aux2SemaphoreHandle, portMAX_DELAY);
    osDelay(1);
  }
  /* USER CODE END aux2Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
