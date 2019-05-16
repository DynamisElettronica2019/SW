
#include "d_efiSense.h"

extern Indicator_Value Indicators[N_INDICATORS];

void dEfiSense_calculateTPS(Indicator_ID id, unsigned int value)
{
		Indicators[id].floatValore = ((int)(value*100)/EFI_SENSE_TPS_RANGE);
}

void dEfiSense_calculateWaterTemperature (Indicator_ID id, unsigned int value) 
{
   	Indicators[id].floatValore = ((int)(( EFI_SENSE_WATER_MIN_TEMP - (value * EFI_SENSE_WATER_TEMP_RANGE ) ) * 100)) / 100.0;
}

void dEfiSense_calculateOilInTemperature(Indicator_ID id, unsigned int value)
{
		Indicators[id].floatValore = ((int) (( EFI_SENSE_OIL_MIN_TEMP - (value * EFI_SENSE_OIL_TEMP_RANGE ) ) * 100)) / 100.0;
}

void dEfiSense_calculateOilOutTemperature(Indicator_ID id, unsigned int value)
{
     dEfiSense_calculateWaterTemperature(id,value);
}

void dEfiSense_calculateTemperature(Indicator_ID id, unsigned int value) 
{ //Value is Temperature, 256 values ranging from -10° to 160°
    Indicators[id].floatValore = ((int) ((((value * EFI_SENSE_TEMP_RANGE) / 256.0) - EFI_SENSE_MIN_TEMP) * 100)) / 100.0;
}

void dEfiSense_calculateVoltage(Indicator_ID id, unsigned int value) 
{ //Value is Battery Voltage, 1024 values ranging from 0 to 18V
     Indicators[id].floatValore =((int) (((value * EFI_SENSE_MAX_VOLTAGE) / 1024.0) * 100)) / 100.0;
}

void dEfiSense_calculateSpeed(Indicator_ID id, unsigned int value)
{
     Indicators[id].floatValore = 0.1*value;
}

void dEfiSense_calculateSlip(Indicator_ID id, unsigned int value)
{
     Indicators[id].floatValore = ((int) ((value * EFI_SENSE_SLIP) * 100)) / 100.0;
}
