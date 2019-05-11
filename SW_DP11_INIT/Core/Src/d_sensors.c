
#include "d_sensors.h"

extern uint32_t ADC_BUF[3];

void dSensors_update(void)	{	// da definire come vanno riscalati i valori

	//*indizzo_nella_matrice = (float) (ADC_BUF[0] * VDD ) / LEVEL ;
	//*indizzo_nella_matrice = (float) (ADC_BUF[1] * VDD ) / LEVEL ;
	//*indizzo_nella_matrice = (float) ((((ADC_BUF[2] * VDD ) / LEVEL )*0.8) + (*indirizzo_nella_matrice * 0.2));
	return ;
}

void dSensors_Clutch_send(void)	{
	
	// invio su can del clutch
	return ;
}

void dSensors_Sensors_send(void)	{
	
	// invio su can dei sensori
	return ;
}
