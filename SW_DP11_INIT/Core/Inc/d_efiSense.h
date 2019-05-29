
#ifndef D_EFI_H
#define D_EFI_H

#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "data.h"

#define EFI_SENSE_TEMP_RANGE 160
#define EFI_SENSE_MIN_TEMP 10
#define EFI_SENSE_MAX_VOLTAGE   18
#define EFI_SENSE_WATER_TEMP_RANGE  (0.35572f)
#define EFI_SENSE_WATER_MIN_TEMP (190.95f)
#define EFI_SENSE_OIL_TEMP_RANGE  (0.36094f)
#define EFI_SENSE_OIL_MIN_TEMP (196.36f)
#define EFI_SENSE_SLIP (0.1f)
#define EFI_SENSE_TPS_RANGE 255
#define EFI_SENSE_PH2O_RANGE (0.009768f)
#define EFI_SENSE_PH2O_MIN (0.996336f)
#define EFI_FUEL_LEVEL_RANGE_1 (0.111721f)
#define EFI_FUEL_LEVEL_RANGE_2 (0.007224f)
#define EFI_FUEL_LEVEL_OFFSET_1 (18.7223f)
#define EFI_FUEL_LEVEL_OFFSET_2 (12.29331f)
#define EFI_SCARICO_RANGE (1.2219f)
	 
	 
void dEfiSense_calculateTPS(Indicator_ID id, unsigned int value);
void dEfiSense_calculateWaterTemperature(Indicator_ID id, unsigned int value);
void dEfiSense_calculateOilInTemperature (Indicator_ID id, unsigned int value);
void dEfiSense_calculateOilOutTemperature (Indicator_ID id, unsigned int value);
void dEfiSense_calculateTemperature(Indicator_ID id, unsigned int value);
void dEfiSense_calculateVoltage(Indicator_ID id, unsigned int value);
void dEfiSense_calculateSpeed(Indicator_ID id, unsigned int value);
void dEfiSense_calculateSlip(Indicator_ID id, unsigned int value);
void dEfiSense_calculatePressure(Indicator_ID id, unsigned int value);
void dEfiSense_calculatePH2O(Indicator_ID id, unsigned int value);
void dEfiSense_calculateFuelLevel(Indicator_ID id, unsigned int value);
void dEfiSense_calculateTempScarico(Indicator_ID id, unsigned int value);

#ifdef __cplusplus
}
#endif

#endif //D_EFI_H
