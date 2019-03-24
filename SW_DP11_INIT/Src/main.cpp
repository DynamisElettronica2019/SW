/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "d_ltdc_init.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

CAN_HandleTypeDef hcan1;

CRC_HandleTypeDef hcrc;

I2C_HandleTypeDef hi2c1;

QSPI_HandleTypeDef hqspi;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim7;
TIM_HandleTypeDef htim12;

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
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
extern "C" void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_CAN1_Init(void);
static void MX_QUADSPI_Init(void);
static void MX_SPI1_Init(void);
static void MX_I2C1_Init(void);
static void MX_ADC1_Init(void);
static void MX_CRC_Init(void);
static void MX_TIM7_Init(void);
static void MX_TIM12_Init(void);
extern void GRAPHICS_HW_Init(void);
extern void GRAPHICS_Init(void);
extern void GRAPHICS_MainTask(void);
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

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_CAN1_Init();
  MX_QUADSPI_Init();
  MX_SPI1_Init();
  MX_I2C1_Init();
  MX_ADC1_Init();
  MX_CRC_Init();
  MX_TIM7_Init();
  MX_TIM12_Init();
  /* USER CODE BEGIN 2 */

	LTDC_init_sequence(&hspi1);

  /* USER CODE END 2 */

/* Initialise the graphical hardware */
  GRAPHICS_HW_Init();

  /* Initialise the graphical stack engine */
  GRAPHICS_Init();
      
  

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
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
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
  osMessageQDef(canQueue, 5, uint16_t);
  canQueueHandle = osMessageCreate(osMessageQ(canQueue), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
 

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /**Configure LSE Drive Capability 
  */
  HAL_PWR_EnableBkUpAccess();
  /**Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 200;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /**Activate the Over-Drive mode 
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV8;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC|RCC_PERIPHCLK_I2C1;
  PeriphClkInitStruct.PLLSAI.PLLSAIN = 50;
  PeriphClkInitStruct.PLLSAI.PLLSAIR = 2;
  PeriphClkInitStruct.PLLSAI.PLLSAIQ = 2;
  PeriphClkInitStruct.PLLSAI.PLLSAIP = RCC_PLLSAIP_DIV2;
  PeriphClkInitStruct.PLLSAIDivQ = 1;
  PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_2;
  PeriphClkInitStruct.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 3;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_15CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
  */
  sConfig.Channel = ADC_CHANNEL_6;
  sConfig.Rank = ADC_REGULAR_RANK_3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */

  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
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
  /* USER CODE BEGIN CAN1_Init 2 */

  /* USER CODE END CAN1_Init 2 */

}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  hcrc.Init.DefaultPolynomialUse = DEFAULT_POLYNOMIAL_ENABLE;
  hcrc.Init.DefaultInitValueUse = DEFAULT_INIT_VALUE_ENABLE;
  hcrc.Init.InputDataInversionMode = CRC_INPUTDATA_INVERSION_NONE;
  hcrc.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;
  hcrc.InputDataFormat = CRC_INPUTDATA_FORMAT_BYTES;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00606092;
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
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief QUADSPI Initialization Function
  * @param None
  * @retval None
  */
static void MX_QUADSPI_Init(void)
{

  /* USER CODE BEGIN QUADSPI_Init 0 */

  /* USER CODE END QUADSPI_Init 0 */

  /* USER CODE BEGIN QUADSPI_Init 1 */

  /* USER CODE END QUADSPI_Init 1 */
  /* QUADSPI parameter configuration*/
  hqspi.Instance = QUADSPI;
  hqspi.Init.ClockPrescaler = 2;
  hqspi.Init.FifoThreshold = 1;
  hqspi.Init.SampleShifting = QSPI_SAMPLE_SHIFTING_NONE;
  hqspi.Init.FlashSize = 1;
  hqspi.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_1_CYCLE;
  hqspi.Init.ClockMode = QSPI_CLOCK_MODE_0;
  hqspi.Init.FlashID = QSPI_FLASH_ID_1;
  hqspi.Init.DualFlash = QSPI_DUALFLASH_DISABLE;
  if (HAL_QSPI_Init(&hqspi) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN QUADSPI_Init 2 */

  /* USER CODE END QUADSPI_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_9BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_HARD_OUTPUT;
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
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM7 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM7_Init(void)
{

  /* USER CODE BEGIN TIM7_Init 0 */

  /* USER CODE END TIM7_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM7_Init 1 */

  /* USER CODE END TIM7_Init 1 */
  htim7.Instance = TIM7;
  htim7.Init.Prescaler = 9999;
  htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim7.Init.Period = 10;
  htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM7_Init 2 */

  /* USER CODE END TIM7_Init 2 */

}

/**
  * @brief TIM12 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM12_Init(void)
{

  /* USER CODE BEGIN TIM12_Init 0 */

  /* USER CODE END TIM12_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM12_Init 1 */

  /* USER CODE END TIM12_Init 1 */
  htim12.Instance = TIM12;
  htim12.Init.Prescaler = 0;
  htim12.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim12.Init.Period = 0;
  htim12.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim12.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim12) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim12, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim12) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim12, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM12_Init 2 */

  /* USER CODE END TIM12_Init 2 */
  HAL_TIM_MspPostInit(&htim12);

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 10, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
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
  HAL_GPIO_WritePin(GPIOD, DEBUG_LED_3_Pin|DEBUG_LED_2_Pin|DEBUG_LED_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LCD_RESET_Pin */
  GPIO_InitStruct.Pin = LCD_RESET_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LCD_RESET_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : ENC_RIGHT_1_INT_Pin NEUTRAL_BUTTON_INT_Pin OK_BUTTON_INT_Pin SEL_MAP_1_INT_Pin */
  GPIO_InitStruct.Pin = ENC_RIGHT_1_INT_Pin|NEUTRAL_BUTTON_INT_Pin|OK_BUTTON_INT_Pin|SEL_MAP_1_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : ENC_RIGHT_2_Pin ENC_RIGHT_4_Pin ENC_RIGHT_8_Pin SEL_MAP_4_Pin 
                           SEL_MAP_8_Pin */
  GPIO_InitStruct.Pin = ENC_RIGHT_2_Pin|ENC_RIGHT_4_Pin|ENC_RIGHT_8_Pin|SEL_MAP_4_Pin 
                          |SEL_MAP_8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : ENC_LEFT_1_INT_Pin AUX_1_BUTTON_INT_Pin AUX_2_BUTTON_INT_Pin */
  GPIO_InitStruct.Pin = ENC_LEFT_1_INT_Pin|AUX_1_BUTTON_INT_Pin|AUX_2_BUTTON_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : ENC_LEFT_2_Pin SEL_MAP_2_Pin */
  GPIO_InitStruct.Pin = ENC_LEFT_2_Pin|SEL_MAP_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : ENC_LEFT_4_Pin ENC_LEFT_8_Pin */
  GPIO_InitStruct.Pin = ENC_LEFT_4_Pin|ENC_LEFT_8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pins : SEL_MODE_4_Pin SEL_MODE_8_Pin SEL_MODE_2_Pin */
  GPIO_InitStruct.Pin = SEL_MODE_4_Pin|SEL_MODE_8_Pin|SEL_MODE_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : SEL_MODE_1_INT_Pin */
  GPIO_InitStruct.Pin = SEL_MODE_1_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SEL_MODE_1_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : START_BUTTON_INT_Pin AUX_3_BUTTON_INT_Pin */
  GPIO_InitStruct.Pin = START_BUTTON_INT_Pin|AUX_3_BUTTON_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : SHIFT_DOWN_INT_Pin SHIFT_UP_INT_Pin */
  GPIO_InitStruct.Pin = SHIFT_DOWN_INT_Pin|SHIFT_UP_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : DEBUG_LED_3_Pin DEBUG_LED_2_Pin DEBUG_LED_1_Pin */
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

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

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

  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */ 
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
/* USER CODE END Header_canTask */
void canTask(void const * argument)
{
  /* USER CODE BEGIN canTask */
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(canSemaphoreHandle, portMAX_DELAY);
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
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(modeSelectorSemaphoreHandle, portMAX_DELAY);
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
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(leftEncoderSemaphoreHandle, portMAX_DELAY);
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
  /* Infinite loop */
  for(;;)
  {
		xSemaphoreTake(rightEncoderSemaphoreHandle, portMAX_DELAY);
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

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
