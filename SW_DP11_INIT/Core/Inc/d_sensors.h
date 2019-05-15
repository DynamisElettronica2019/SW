
#ifndef D_SENSORS_H
#define D_SENSORS_H

#ifdef __cplusplus
extern "C" {
#endif
	
#include "main.h"
#include "adc.h"
#include "data.h"
	
#define CLUTCH_MAX_VALUE 4000
#define CLUTCH_MIN_VALUE 0

	void dSensors_Clutch_send(void);	//in caso di invio diretto dalla task è inutile

	void dSensors_Sensors_send(void);	//in caso di invio diretto dalla task è inutile	
	
	void dSensors_update(void);
	
	void dSensors_CLUTCH(int);
	
#ifdef __cplusplus
}
#endif

#endif // D_SENSORS_H
