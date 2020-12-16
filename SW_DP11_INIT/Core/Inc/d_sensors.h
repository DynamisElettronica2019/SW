
#ifndef D_SENSORS_H
#define D_SENSORS_H

#ifdef __cplusplus
extern "C" {
#endif
	
#include "main.h"
#include "adc.h"
#include "data.h"
	
#define ADC_LSB 											(3.3f/4095.0f)
#define INA_GAIN 											(uint8_t)100
#define TEMP_VOLTAGE_OFFSET						100.0f 			/* [mV] */
#define TEMP_GAIN 										0.1f 				/* [°C/mV] */
#define TEMP_OFFSET										40.0f 			/* [°C] */
#define SHUNT_RESISTOR 								0.022f		  /* [Ohm] */
#define WATER_TEMP_RANGE  						0.35572f
#define WATER_MIN_TEMP 								190.95f
#define PH2O_RANGE (0.009768f)
#define PH2O_MIN (0.996336f)

void dSensors_Sensors_send(void);	//in caso di invio diretto dalla task è inutile	
	
void dSensors_convert(int currValue, int tempValue);
	
void dSensors_calculateWaterPressure (Indicator_ID id, unsigned int value);
void dSensors_calculateWaterTemperature (Indicator_ID id, unsigned int value);
void dSensors_calculateOilTemperature (Indicator_ID id, unsigned int value);
void dSensors_calculateBrakeTemperature(Indicator_ID id, unsigned int value);
void dSensors_calculateSteeringWheelAngle(Indicator_ID id, unsigned int value);
void dSensors_calculateAPPS(Indicator_ID id, unsigned int value);
void dSensors_calculateRegen(Indicator_ID id, unsigned int value);

#ifdef __cplusplus
}
#endif

#endif // D_SENSORS_H
