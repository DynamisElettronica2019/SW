
#ifndef DATA_H
#define DATA_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"
	 
/********************DEFINES********************/
	 
#define N_INDICATORS BMS_SLAVE_6_BOARD+1		
#define TIT_LEN 11													//--- Lunghezza massima della stringa va visualizzare come titolo
	 	 
#define N_DEBUG_MODE_VALUES 8								//--- numero di indicatori nella schermata di DEBUG_MODE
	 
#define START_BOARD_DEBUG	  			DCU_BOARD	
#define END_BOARD_DEBUG 					BMS_SLAVE_6_BOARD		
#define END_BOARDS 								BMS_SLAVE_6_BOARD
	 
	 
#define START_CURRENTS_ONLY_A 		GLVS_CURR
#define END_CURRENTS_ONLY_A				INVERTER_CURR
	 
#define START_CURRENTS_ONLY_MA 		XBEE
#define END_CURRENTS_ONLY_MA			SPEAKER_CURR

#define START_IMU_ACC							ACC_X_FRONT
#define END_IMU_ACC								ACC_Z_REAR

#define START_IMU_GYR							GYRO_X_FRONT
#define END_IMU_GYR 							GYRO_Z_REAR
	 
#define FIRST_CAR_PARAMETER 			TV
#define	LAST_CAR_PARAMETER				BMS_SLAVE_6_BOARD
	 
	 
#define FIRST_CAR_PARAMETER_SX 		FIRST_CAR_PARAMETER
#define	LAST_CAR_PARAMETER_SX 		GYRO_Z_REAR

#define	FIRST_CAR_PARAMETER_DX 		V_TS_INVERTER 
#define	LAST_CAR_PARAMETER_DX 		MIN_CELL_TEMP 
	 
#define DEF_VALUE 9999  //------------- Valore con cui si inizializza la matrice di dati per capire se sono arrivati dati nuovi dal CAN o no
#define DEF_SIMBOL "?"  
#define NOT_DEF_SIMBOL "-"

#define MAX_HDOP									5
#define MIN_N_SATELLITES					10

#define FIRST_DEFAULT_INDICATOR		PH2O
#define SECOND_DEFAULT_INDICATOR	TH2O_RAD
#define THIRD_DEFAULT_INDICATOR		TH2O_FR
#define FOURTH_DEFAULT_INDICATOR	TH2O_FL

/********************DATA TYPE********************/	 

typedef enum {
        /* car parameters */
				
				/*-------Parameters--------*/ 			// indicatori fissi sulle schermate
				TV, SOC, VBAT, TC, 
				TS, ACQ, REGEN, SD_STATE, DRIVE_MODE, MAP, POW_LIM,


				/*------Temperatures-------*/			//	inizio degli indicatori da poter selezionare
				TH2O_FL, TH2O_FR, TOIL_FR, TOIL_FL, TH2O_RR, TH2O_RL,		
				TBRAKE_FR, TBRAKE_FL, TBRAKE_RR, TBRAKE_RL,
				TOIL_RR, TOIL_RL, TH2O_RAD, PH2O,


				/*---------Sensors---------*/
				PBRAKE_F, PBRAKE_R,	PITOT,																								
				STRAIN_GAUGE_FR, STRAIN_GAUGE_FL, SW_ANGLE,																					
				STRAIN_GAUGE_RR, STRAIN_GAUGE_RL, PT100,																																
				BRAKE_BIAS, APPS_1, APPS_2, LOAD_CELL,


				/*---------Others----------*/			// fine degli indicatori da poter selezionare
				IMPLAUSIBILITY,	 PWM_BATTERY_FAN, PWM_RAD_FAN,


				/*--------Voltages---------*/
				VOLTAGE_12V_DCU, VOLTAGE_5V_DCU, VOLTAGE_3V3_DCU, 
				VOLTAGE_24V_VCU, VOLTAGE_5V_VCU, VOLTAGE_3V3_VCU,
				LVB_VOLTAGE, DCDC_VOLTAGE,


				/*--------Currents---------*/ 					
				GLVS_CURR, PUMP_CURR,	RAD_FAN_CURR, 												
				DCDC_CURR, BATTERY_FAN_CURR, 
				INVERTER_CURR, XBEE, SPEAKER_CURR,														


				/*----------IMUs-----------*/
				ACC_X_FRONT, ACC_Y_FRONT, ACC_Z_FRONT,																																	
				ACC_X_REAR, ACC_Y_REAR, ACC_Z_REAR,																													
				GYRO_X_FRONT, GYRO_Y_FRONT, GYRO_Z_FRONT,																														
				GYRO_X_REAR, GYRO_Y_REAR, GYRO_Z_REAR,																															
				INSS_ACC_X,	INSS_ACC_Y, INSS_ACC_Z,
				INSS_GYRO_X, INSS_GYRO_Y, INSS_GYRO_Z,										
				INSS_SPEED,						
				INSS_LAT, INSS_LONG,
				INSS_HDOP, INSS_N_SETELLITES,


				/*-------High Voltage------*/
				V_TS_INVERTER, V_TS_ACCUMULATOR, SUM_OF_CELLS,
				MAX_CELL_VOLTAGE, MIN_CELL_VOLTAGE,
				ACC_AIR_TEMP1, ACC_AIR_TEMP2,															
				ACC_STATE, IMD_INS, BMS_STATE, ACCUMULATOR_SOC, TS_PRECHARGING_STATE,															
				ACC_TS_CURRENT, BMS_MAX_HUMIDITY, BMS_12V_SENSE,
				CURR_LIM_MAX_INPUT_CURRENT, CURR_LIM_MAX_OUTPUT_CURRENT,
				MAX_CELL_TEMP, MIN_CELL_TEMP,


				/*--------Boards-----------*/
				DCU_BOARD, DAU_FRONT_BOARD, DAU_REAR_BOARD,
				IMU_FRONT_BOARD, IMU_REAR_BOARD, VCU_BOARD,
				SW_BOARD, BMS_MASTER_BOARD,
				BMS_SLAVE_1_BOARD, BMS_SLAVE_2_BOARD,
				BMS_SLAVE_3_BOARD, BMS_SLAVE_4_BOARD,
				BMS_SLAVE_5_BOARD, BMS_SLAVE_6_BOARD,
						
} Indicator_ID;

typedef enum { 
				INT, FLOAT 
} Type;

typedef struct {
        Indicator_ID ID;
        Type TIPO;
        char NOME[TIT_LEN];
        int intValore;
        float floatValore;
				int intValore2; // per corrente e temperatura
				char	charValore[2];	//per gli indicatori tipo la marcia che posso contenre una lettera (come la N)
} Indicator_Value;


typedef struct {
	CAN_RxHeaderTypeDef CAN_RxPacket_Header;
	uint8_t CAN_RxPacket_Data[8];
} CAN_RxPacketTypeDef;


void data_indicatorsInit(void);
void data_efiOff(void);
void data_simMode_init(void);

#ifdef __cplusplus
}
#endif

#endif //DATA_H

