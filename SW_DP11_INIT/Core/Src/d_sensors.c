
#include "d_sensors.h"
#include "general.h"
#include "can.h"

extern char driveMode, engineMap;
extern int ADC_BUF[3];
extern Indicator_Value Indicators[N_INDICATORS];
int clutchOld = 0;
int clutchValue = 0;

void dSensors_convert(int currValue, int tempValue)	{
	Indicators[SW_BOARD].intValore  = (uint16_t)((float)currValue*ADC_LSB/(SHUNT_RESISTOR*INA_GAIN)*1000.0f);
	Indicators[SW_BOARD].intValore2 = (((float)tempValue * ADC_LSB * 1000.0f) - TEMP_VOLTAGE_OFFSET)*TEMP_GAIN - TEMP_OFFSET;
}


void dSensors_Clutch_send(void)	{
	CAN_send(SW_CLUTCH_MODE_MAP_GCU_ID, clutchValue, driveMode, engineMap, EMPTY, 3);
	return ;
}

void dSensors_Sensors_send(void)	{
	/* manca la conversione della temp e corrente */
	dSensors_convert(ADC_BUF[CURR_ADC],ADC_BUF[TEMP_ADC]);
	CAN_send(SW_DEBUG_ID, Indicators[SW_BOARD].intValore2,Indicators[SW_BOARD].intValore, EMPTY, EMPTY, 2);
	return ;
}

void dSensors_CLUTCH(int clutchAnalog){

	if (clutchAnalog >= CLUTCH_MAX_VALUE)
		clutchOld= CLUTCH_MAX_VALUE;
	else if (clutchAnalog <= CLUTCH_MIN_VALUE)
		clutchOld = CLUTCH_MIN_VALUE;
	else
		clutchOld = (int) (clutchAnalog * 0.8 ) + (clutchOld * 0.2);
	
	clutchValue = (int) (clutchOld * 100 / CLUTCH_MAX_VALUE ) ;
	
	Indicators[CLUTCH_POSITION].intValore = clutchValue; 
	
	return ;
}
