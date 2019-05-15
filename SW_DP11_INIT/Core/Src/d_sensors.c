
#include "d_sensors.h"

extern uint32_t ADC_BUF[3];
extern Indicator_Value Indicators[N_INDICATORS];
int clutchValue = 0;

void dSensors_update(void)	{	// da definire come vanno riscalati i valori
	
	//*indizzo_nella_matrice = (float) (ADC_BUF[0] * VDD ) / LEVEL ;
	//*indizzo_nella_matrice = (float) ((((ADC_BUF[2] * VDD ) / LEVEL )*0.8) + (*indirizzo_nella_matrice * 0.2));
	return ;
}

void dSensors_Clutch_send(void)	{
	
	// invio su can di clutchValue
	return ;
}

void dSensors_Sensors_send(void)	{
	
	// invio su can dei sensori
	return ;
}

void dSensors_CLUTCH(int clutchAnalog)	{
	
	if (clutchAnalog >= CLUTCH_MAX_VALUE)
		clutchValue = CLUTCH_MAX_VALUE;
	else if (clutchAnalog <= CLUTCH_MIN_VALUE)
		clutchValue = CLUTCH_MIN_VALUE;
	else
		clutchValue = (int) (clutchAnalog * 0.8 ) + (clutchValue * 0.2);
	
	clutchValue = (int) (clutchValue / CLUTCH_MAX_VALUE * 100);
	
	return ;
}
