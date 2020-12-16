/**
  ******************************************************************************
  * File Name          : I2C.h
  * Description        : This file provides code for the configuration
  *                      of the I2C instances.
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
#ifndef __i2c_H
#define __i2c_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
	 
#include "general.h"
	 
/* USER CODE END Includes */

extern I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN Private defines */

#define controller_0 0x29
#define controller_1 0x28
	 
#define RPM_STRIPE_MAX      12000
#define RPM_STRIPE_MIN 			4000
#define RPM_STRIPE_OFFSET 	(RPM_STRIPE_MAX-RPM_STRIPE_MIN)/12

 
#define LED_1_RED				0x0F
#define LED_1_GREEN			0x10
#define LED_1_BLUE			0x11

#define LED_2_RED				0x12
#define LED_2_GREEN			0x13
#define LED_2_BLUE			0x14

#define LED_3_RED				0x15
#define LED_3_GREEN			0x16
#define LED_3_BLUE			0x17
	
#define LED_4_RED				0x18
#define LED_4_GREEN			0x19
#define LED_4_BLUE			0x1A

#define LED_5_RED				0x1B
#define LED_5_GREEN			0x1C
#define LED_5_BLUE			0x1D

#define LED_6_RED				0x1E
#define LED_6_GREEN			0x1F
#define LED_6_BLUE			0x20

#define EEPROM_ADDRESS 	0xA

#define DEF_PAGE 				0	 
#define END_PAGE 				1		
#define ACC_PAGE 				2	
#define AUT_PAGE 				3	
#define SKI_PAGE 				4
#define TARGET_PAGE			5

#define START_CELL			0
#define DEF_CELL				5
#define TRACTION_CELL 	1
#define TORQUE_CELL			2
#define KALMAN_CELL 		3
#define POW_LIM_CELL		4
 	 
#define N_POINTERS 			4	//6

/* USER CODE END Private defines */

void MX_I2C1_Init(void);

/* USER CODE BEGIN Prototypes */

void I2C_setRPM(int rpm_value);
void I2C_rpm_setup(void);
void I2C_test(void);
void I2C_brightness_max (uint16_t);
void I2C_controller_0_ON(void);
void I2C_controller_1_ON(void);
void I2C_debug_red_on(uint16_t);
void I2C_debug_green_on(uint16_t);
void I2C_debug_blue_on(uint16_t);
void I2C_debug_red_off(uint16_t);
void I2C_debug_green_off(uint16_t);
void I2C_debug_blue_off(uint16_t);
void I2C_rpm_command(int);
void I2C_rpm_flash(void);
 
void I2C_eeprom_write(uint8_t , uint16_t);	//si passa l'indice dell'inidicatore e l'indirizzo della memmoria
uint8_t I2C_eeprom_read(uint16_t);		 			// ritorna l'indice dell'indicatore da visualizzare

void I2C_save_endPointers(void);
void I2C_save_accPointers(void);
void I2C_save_autPointers(void);
void I2C_save_skiPointers(void);
void I2C_save_Pointers(void);
void I2C_save_defPointers(void);

void I2C_get_endPointers(void);
void I2C_get_accPointers(void);
void I2C_get_autPointers(void);
void I2C_get_skiPointers(void);
void I2C_get_defPointers(void);

void I2C_getPointers(void);

void I2C_save_Traction(int value);
int I2C_get_Traction(void);
void I2C_save_Torque(int value);
int I2C_get_Torque(void);
void I2C_save_PowerLimiter(int value);
int I2C_get_PowerLimiter(void);
void I2C_save_Kalman(int value);
int I2C_get_Kalman(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ i2c_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
