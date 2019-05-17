
#include "d_sensors.h"
#include "general.h"
#include "can.h"

extern char driveMode, engineMap;

extern Indicator_Value Indicators[N_INDICATORS];
int clutchOld = 0;
int clutchValue = 0;

void dSensors_update(void)	{	// da definire come vanno riscalati i valori	
	//*indizzo_nella_matrice = (float) (ADC_BUF[0] * VDD ) / LEVEL ;
	//*indizzo_nella_matrice = (float) ((((ADC_BUF[2] * VDD ) / LEVEL )*0.8) + (*indirizzo_nella_matrice * 0.2));
	return ;
}

//extern int clutch_ramp;

void dSensors_Clutch_send(void)	{
	CAN_send(SW_CLUTCH_MODE_MAP_GCU_ID, clutchValue, driveMode, engineMap, EMPTY, 3);
	return ;
}

void dSensors_Sensors_send(void)	{
	/* manca la conversione della temp e corrente */
	CAN_send(SW_DEBUG_ID, 10, 35, EMPTY, EMPTY, 2);
	return ;
}

void dSensors_CLUTCH(int clutchAnalog)	{

	if (clutchAnalog >= CLUTCH_MAX_VALUE)
		clutchOld= CLUTCH_MAX_VALUE;
	else if (clutchAnalog <= CLUTCH_MIN_VALUE)
		clutchOld = CLUTCH_MIN_VALUE;
	else
		clutchOld = (int) (clutchAnalog * 0.8 ) + (clutchOld * 0.2);
	
	clutchValue = (int) (clutchOld * 100 / CLUTCH_MAX_VALUE ) ;
	
	Indicators[TH2O].intValore = clutchValue; 
	
	return ;
}
