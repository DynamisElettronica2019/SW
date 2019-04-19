

#ifndef GENERAL_H
#define GENERAL_H

#ifdef __cplusplus
 extern "C" {
#endif


/********************DEFINES********************/

#define SETTINGS_MODE				0
#define BOARD_DEBUG_MODE		1
#define DEBUG_MODE					2
#define ENDURANCE_MODE			3
#define ACCELERATION_MODE		4
#define AUTOX_MODE					5
#define SKIDPAD_MODE				6
	 
#define MAP_1								0
#define MAP_2								1
	 
#define MAX_DRIVE_MODE			SKIDPAD_MODE
	 
	 
#define SENSORS_TIME						200
#define START_BUTTON_TIME				40
#define RPM_STRIPE_TIME					1000
#define DRIVE_MODE_TIME					10		//---- valore da definire
#define MAP_TRACTION_RPM_TIME 	20		//---- valore da definire

/********************FUNCTIONS*******************/


void MX_FREERTOS_Init(void);
void GRAPHICS_MainTask(void);


#ifdef __cplusplus
}
#endif

#endif //GENERAL_H
