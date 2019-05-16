
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

	 
	 
void dEfiSense_calculateTPS(Indicator_ID id, unsigned int value);
void dEfiSense_calculateWaterTemperature(Indicator_ID id, unsigned int value);
void dEfiSense_calculateOilInTemperature (Indicator_ID id, unsigned int value);
void dEfiSense_calculateOilOutTemperature (Indicator_ID id, unsigned int value);
void dEfiSense_calculateTemperature(Indicator_ID id, unsigned int value);
void dEfiSense_calculateVoltage(Indicator_ID id, unsigned int value);
void dEfiSense_calculateSpeed(Indicator_ID id, unsigned int value);
void dEfiSense_calculateSlip(Indicator_ID id, unsigned int value);

#ifdef __cplusplus
}
#endif

#endif //D_EFI_H
