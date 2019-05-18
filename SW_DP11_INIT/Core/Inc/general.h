

#ifndef GENERAL_H
#define GENERAL_H

#ifdef __cplusplus
 extern "C" {
#endif
	 
	 
/******************** DEFINES **********************/

#define TRUE 														1
#define FALSE 													0
	 
#define EMPTY 													0
	
/******************** MODES ***********************/

#define BOARD_DEBUG_MODE								0
#define DEBUG_MODE											1
#define SETTINGS_MODE										2
#define SKIDPAD_MODE										3
#define AUTOX_MODE											4
#define ACCELERATION_MODE								5
#define ENDURANCE_MODE									6
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


/******************** MAPS *************************/

#define MAP_1														1
#define MAP_2														2
	 
/****************** COMMANDS ***********************/
	
#define COMMAND_READY	 									1// - TIRA LA FRIZIONE
#define COMMAND_GO			 								3// PARTIAMO
#define COMMAND_STOP	 									4
	 
#define DCU_ACQUISITION_CODE   				  0
#define DCU_SAVE_LINEAR_CODE						1

/****************** TIMINGS ************************/

#define SENSORS_TIME										10		// 100Hz
#define SENSORS_SEND_TIME								100		// 10HZ
#define START_BUTTON_TIME								40		// 25HZ
#define RPM_STRIPE_TIME									100	  // 1HZ
#define DRIVE_MODE_TIME									10		//---- valore da definire
#define TRACTION_RPM_TIME 							100		// 10HZ
	 
#define POPUP_TIME         				      30

/******************* FUNCTIONS *********************/

void MX_FREERTOS_Init(void);
void GRAPHICS_MainTask(void);

#ifdef __cplusplus
}
#endif

#endif //GENERAL_H
