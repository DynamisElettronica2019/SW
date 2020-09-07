
#ifndef D_SENSORS_H
#define D_SENSORS_H

#ifdef __cplusplus
extern "C" {
#endif
	
#include "main.h"
#include "adc.h"
#include "data.h"
	
#define CLUTCH_MAX_VALUE 	10000
#define CLUTCH_MIN_VALUE 	0
#define CLUTCH_OFFSET 		530
	
#define ADC_LSB 											(3.3f/4095.0f)
#define INA_GAIN 											(uint8_t)100
#define TEMP_VOLTAGE_OFFSET						100.0f 			/* [mV] */
#define TEMP_GAIN 										0.1f 				/* [°C/mV] */
#define TEMP_OFFSET										40.0f 			/* [°C] */
#define SHUNT_RESISTOR 								0.022f		  /* [Ohm] */

void dSensors_Clutch_send(void);	//in caso di invio diretto dalla task è inutile

void dSensors_Sensors_send(void);	//in caso di invio diretto dalla task è inutile	
	
void dSensors_convert(int currValue, int tempValue);
	
void dSensors_CLUTCH(int);

void dSensors_setClutchTarget(int movement);

void dSensors_setAutoXTarget(int movement);
	
#ifdef __cplusplus
}
#endif

#endif // D_SENSORS_H
