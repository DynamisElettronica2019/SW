

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

#define BOARD_DEBUG_MODE								6
#define DEBUG_MODE											5
#define SETTINGS_MODE										4
#define SKIDPAD_MODE										3
#define AUTOX_MODE											2
#define ACCELERATION_MODE								1
#define ENDURANCE_MODE									0
#define EMPTY_POSITION									7
	
#define MAX_DRIVE_MODE						SKIDPAD_MODE
	
/********************* STATES *********************/

#define AUTOX_MODE_DEFAULT							0
#define AUTOX_MODE_FEEDBACK							1
#define AUTOX_MODE_START								2
#define AUTOX_MODE_READY								3
#define AUTOX_MODE_GO 									5

#define ACCELERATION_MODE_DEFAULT				0
#define ACCELERATION_MODE_FEEDBACK	 	  1
#define ACCELERATION_MODE_START					2
#define ACCELERATION_MODE_READY					3
#define ACCELERATION_MODE_GO 						5

#define ENDURANCE_MODE_DEFAULT					0
#define ENDURANCE_MODE_FEEDBACK					1
#define ENDURANCE_MODE_START						2

#define SKIDPAD_MODE_DEFAULT						0
#define SKIDPAD_MODE_FEEDBACK						1
#define SKIDPAD_MODE_START							2

#define DEBUG_MODE_DEFAULT							0

#define BOARD_DEBUG_MODE_DEFAULT				0

#define SETTINGS_MODE_DEFAULT						0


/***************** MAPS & OTHERS *******************/

#define MAP_1														1
#define MAP_2														2
	 
#define ACQ_ON													1
#define ACQ_OFF					 								2
#define ACQ_READY												3

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


#define DCU_ACQUISITION_CODE   				  1
#define DCU_SAVE_CALIBRATION_CODE				2

/****************** TIMINGS ************************/

#define SENSORS_TIME										10		// 100Hz
#define SENSORS_SEND_TIME								100		// 10HZ
#define START_BUTTON_TIME								40		// 25HZ
#define RPM_STRIPE_TIME									100	  // 10HZ
#define DRIVE_MODE_TIME									10		// 100HZ
#define TRACTION_RPM_TIME 							100		// 10HZ
#define EFI_DEAD_TIME			 							1000	// 1HZ (1s)
#define DCU_DEAD_TIME 									10000 // 0.1Hz
#define TRACTION_SAVE_TIME							5000  // 0.2 Hz
#define RPM_LIM_SAVE_TIME							  5000  // 0.2 Hz

#define POPUP_TIME         				      30

/******************* FUNCTIONS *********************/

void MX_FREERTOS_Init(void);
void GRAPHICS_MainTask(void);

#ifdef __cplusplus
}
#endif

#endif //GENERAL_H
