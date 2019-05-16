

#ifndef GENERAL_H
#define GENERAL_H

#ifdef __cplusplus
 extern "C" {
#endif


#define TRUE 										1
#define FALSE 									0
	 
#define EMPTY 									0
	
#define GEAR_COMMAND_UP 				400
#define GEAR_COMMAND_DOWN  	    200
	 
#define DCU_ACQUISITION_CODE    0
#define DCU_SAVE_LINEAR_CODE		1

/********************DEFINES********************/

#define BOARD_DEBUG_MODE				0
#define DEBUG_MODE							1
#define SETTINGS_MODE						2
#define SKIDPAD_MODE						3
#define AUTOX_MODE							4
#define ACCELERATION_MODE				5
#define ENDURANCE_MODE					6
#define EMPTY_POSITION					7
	 
#define MAP_1										1
#define MAP_2										2
	 
#define MAX_DRIVE_MODE					SKIDPAD_MODE
	 
/*******************STATES*****************************************************/

#define AUTOX_MODE_DEFAULT						0
#define AUTOX_MODE_FEEDBACK						1
#define AUTOX_MODE_START							2
#define AUTOX_MODE_READY							3
#define AUTOX_MODE_STEADY 						4
#define AUTOX_MODE_GO 								5

#define ACCELERATION_MODE_DEFAULT			0
#define ACCELERATION_MODE_FEEDBACK	  1
#define ACCELERATION_MODE_START				2
#define ACCELERATION_MODE_READY				3
#define ACCELERATION_MODE_STEADY 			4
#define ACCELERATION_MODE_GO 					5

#define ENDURANCE_MODE_DEFAULT				0
#define ENDURANCE_MODE_FEEDBACK				1
#define ENDURANCE_MODE_START					2

#define SKIDPAD_MODE_DEFAULT					0
#define SKIDPAD_MODE_FEEDBACK					1
#define SKIDPAD_MODE_START						2

#define ACCELERATION_READY	 					2
#define ACCELERATION_STEADY						1

#define AUTOX_READY	 									2
#define AUTOX_STEADY									1

/*******************TIMINGS****************************************************/

#define SENSORS_TIME						100
#define SENSORS_SEND_TIME				100
#define START_BUTTON_TIME				40
#define RPM_STRIPE_TIME					1000
#define DRIVE_MODE_TIME					10		//---- valore da definire
#define TRACTION_RPM_TIME 			100		


#define DEBUG_MODE_DEFAULT						0

#define BOARD_DEBUG_MODE_DEFAULT			0

#define SETTINGS_MODE_DEFAULT					0
	 
	 
/********************FUNCTIONS*******************/

void MX_FREERTOS_Init(void);
void GRAPHICS_MainTask(void);

#ifdef __cplusplus
}
#endif

#endif //GENERAL_H
