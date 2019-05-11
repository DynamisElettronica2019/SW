

#ifndef GENERAL_H
#define GENERAL_H

#ifdef __cplusplus
 extern "C" {
#endif


/********************DEFINES********************/

#define BOARD_DEBUG_MODE		0
#define DEBUG_MODE					1
#define SETTINGS_MODE				2
#define SKIDPAD_MODE				3
#define AUTOX_MODE					4
#define ACCELERATION_MODE		5
#define ENDURANCE_MODE			6
#define EMPTY_POSITION			7
	 
#define MAP_1								1
#define MAP_2								2
	 
#define MAX_DRIVE_MODE			SKIDPAD_MODE
	 
	 
/*******************STATES*****************************************************/

#define AUTOX_MODE_DEFAULT						0
#define AUTOX_MODE_START							1

#define ACCELERATION_MODE_DEFAULT			0
#define ACCELERATION_MODE_START				1

#define ENDURANCE_MODE_DEFAULT				0
#define ENDURANCE_MODE_START					1

#define SKIDPAD_MODE_DEFAULT					0
#define SKIDPAD_MODE_START						1

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
