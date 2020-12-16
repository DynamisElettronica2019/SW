

#ifndef GENERAL_H
#define GENERAL_H

#ifdef __cplusplus
 extern "C" {
#endif
	 
/******************** DEFINES **********************/

#define TRUE 														1
#define FALSE 													0
	 
#define EMPTY 													0
	 
#define SETT_ACC_BOX										0
#define SETT_END_BOX										1
#define SETT_AUT_BOX										2
#define SETT_SKI_BOX										3
	
/******************** MODES ***********************/

#define EMPTY_POSITION									7
#define BOARD_DEBUG_MODE								6
#define DEBUG_MODE											5
#define SETTINGS_MODE										4
#define SKIDPAD_MODE										3
#define AUTOX_MODE											2
#define ACCELERATION_MODE								1
#define ENDURANCE_MODE									0

#define SETTINGS_DEFAULT								0
#define SETTINGS_INDICATORS_MODE				1
#define SETTINGS_INDICATORS_CHANGE			5
#define SETTINGS_INSS_DATA							2
#define SETTINGS_CALIBRATION						3
#define SETTINGS_KALMAN									4

	
/********************* STATES *********************/

#define AUTOX_MODE_DEFAULT							20
#define AUTOX_MODE_FEEDBACK							21
#define AUTOX_MODE_START								22
#define AUTOX_MODE_READY								23
#define AUTOX_MODE_GO 									25

#define ACCELERATION_MODE_DEFAULT				10
#define ACCELERATION_MODE_FEEDBACK	 	  11
#define ACCELERATION_MODE_START					12
#define ACCELERATION_MODE_READY					13
#define ACCELERATION_MODE_GO 						15

#define ENDURANCE_MODE_DEFAULT					0
#define ENDURANCE_MODE_FEEDBACK					1
#define ENDURANCE_MODE_START						2

#define SKIDPAD_MODE_DEFAULT						30
#define SKIDPAD_MODE_FEEDBACK						31
#define SKIDPAD_MODE_START							32
#define SKIDPAD_SEND_TRGT_VALUE 				33
#define SKIDPAD_SEND_100_STATE					34

#define DEBUG_MODE_DEFAULT							0

#define BOARD_DEBUG_MODE_DEFAULT				0

#define SETTINGS_MODE_DEFAULT						0


/***************** MAPS & OTHERS *******************/

#define MAP_1														1
#define MAP_2														2
	 
#define ACQ_ON													1
#define ACQ_OFF					 								2
#define ACQ_READY												3

#define MIN_SPEED												1.0f	 //------------- da settare il valore della velocità minima per essere consderati fermi

#define TS_OFF													0
#define TS_ON														1
#define TS_RTD													2

/****************** COMMANDS ***********************/
	
#define COMMAND_STOP	 									0
#define COMMAND_READY	 									1// - TIRA LA FRIZIONE
#define COMMAND_GO			 								2// PARTIAMO

#define COMMAND_ACQ_START								1
#define COMMAND_ACQ_STOP 								2

#define COMMAND_SAVE_APPS0							1
#define COMMAND_SAVE_APPS100						2
#define COMMAND_SAVE_SW_ANGLE						3
#define COMMAND_SAVE_LINEAR							4
#define COMMAND_SAVE_LOAD_CELL					5

#define START_RTD												1
#define STOP_RTD												2

#define START_REGEN											1
#define STOP_REGEN											2

#define DCU_ACQUISITION_FB							1
#define DCU_NEW_START_POSITION_FB				2
#define DCU_CALIBRATE_SENSOR_FB					3

#define DCU_ACQUISITION_REQUEST   		  1
#define DCU_SAVE_NEW_START_POSITION			2
#define DCU_VCU_CALIBRATE_SENSOR				3
#define VCU_RTD_REQUEST									1
#define VCU_REGEN_REQUEST								2
#define	VCU_OK_BUTTON										3

/****************** TIMINGS ************************/

#define TIMER_100HZ											10		// 100  Hz
#define TIMER_10HZ											100		// 10   Hz
#define TIMER_1HZ												1000	// 1		HZ
#define START_BUTTON_TIME								10		// 100  Hz
#define RPM_STRIPE_TIME									100	  // 10   Hz
#define DRIVE_MODE_TIME									10		// 100  Hz
#define TRACTION_RPM_TIME 							100		// 10   Hz
#define EFI_DEAD_TIME			 							1000	// 1    Hz (1s)
#define DCU_DEAD_TIME 									20000 // 0.05 Hz (20s)
#define GCU_DEAD_TIME										1000	// 1		HZ (1s)
#define TRACTION_SAVE_TIME							5000  // 0.2  Hz (5s)
#define TV_SAVE_TIME										5000  // 0.2  Hz (5s)
#define EMERGENCY_BLINK_TIME						5000 	// 0.2  Hz (5s)
#define OK_BUTTON_BOUNCE_TIME						1000	// 1    Hz (1s)
#define RTD_PRESSED_TIME								200		// 2 		s

#define POPUP_TIME         				      30

/******************* FUNCTIONS *********************/

void MX_FREERTOS_Init(void);
void GRAPHICS_MainTask(void);

#ifdef __cplusplus
}
#endif

#endif //GENERAL_H
