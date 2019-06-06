/**
  ******************************************************************************
  * File Name          : I2C.h
  * Description        : This file provides code for the configuration
  *                      of the I2C instances.
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
#define RPM_STRIPE_MIN 			3000
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

#define START_CELL			0
#define DEF_CELL				10
#define TRACTION_CELL 	15
 	 
#define N_POINTERS 			6

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
void I2C_rpm_update(void);
 
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

void I2C_save_Traction(int tractionValue);
int I2C_get_Traction(void);

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
