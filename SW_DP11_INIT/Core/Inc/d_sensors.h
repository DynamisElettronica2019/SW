
#ifndef D_SENSORS_H
#define D_SENSORS_H

#ifdef __cplusplus
extern "C" {
#endif
	
#include "main.h"
#include "adc.h"
	
#define VDD 3.3
#define LEVEL 4095

	void dSensors_Clutch_send(void);	//in caso di invio diretto dalla task è inutile

	void dSensors_Sensors_send(void);	//in caso di invio diretto dalla task è inutile	
	
	void dSensors_update(void);
	
#ifdef __cplusplus
}
#endif

#endif // D_SENSORS_H
