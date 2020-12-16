
#include "d_sensors.h"
#include "general.h"

extern int ADC_BUF[3];
extern Indicator_Value Indicators[N_INDICATORS];

void dSensors_convert(int currValue, int tempValue)	{
	Indicators[SW_BOARD].intValore  = (uint16_t)((float)currValue*ADC_LSB/(SHUNT_RESISTOR*INA_GAIN)*1000.0f);
	Indicators[SW_BOARD].intValore2 = (((float)tempValue * ADC_LSB * 1000.0f) - TEMP_VOLTAGE_OFFSET)*TEMP_GAIN - TEMP_OFFSET;
}

void dSensors_Sensors_send(void)	{
	dSensors_convert(ADC_BUF[CURR_ADC],ADC_BUF[TEMP_ADC]);
	//CAN_send(SW_DEBUG_ID, Indicators[SW_BOARD].intValore2,Indicators[SW_BOARD].intValore, EMPTY, EMPTY, 2);
	return ;
}

// sono le conversioni dp11, da verificare!!
void dSensors_calculateWaterPressure(Indicator_ID id, unsigned int value)
{
		Indicators[id].floatValore = ((float)(value*PH2O_RANGE)) - PH2O_MIN;
}

void dSensors_calculateWaterTemperature (Indicator_ID id, unsigned int value) 
{
   	Indicators[id].floatValore = ((int)(( WATER_MIN_TEMP - (value * WATER_TEMP_RANGE ) ) * 100)) / 100.0;
}

void dSensors_calculateOilTemperature(Indicator_ID id, unsigned int value)
{
		 dSensors_calculateWaterTemperature(id,value);
}

// da fare questa conversione con le nuove dau (va rifatta anche quella di dcu!)
void dSensors_calculateBrakeTemperature(Indicator_ID id, unsigned int value)
{
	Indicators[id].floatValore = value;
}

// da fare queste conversioni con i nuovi sensori
void dSensors_calculateSteeringWheelAngle(Indicator_ID id, unsigned int value)
{
	Indicators[id].intValore = value;
}

void dSensors_calculateAPPS(Indicator_ID id, unsigned int value)
{
	Indicators[id].intValore = value;
}

void dSensors_calculateRegen(Indicator_ID id, unsigned int value)
{
	Indicators[id].intValore = value;
}
