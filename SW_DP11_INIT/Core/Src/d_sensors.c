
#include "d_sensors.h"
#include "general.h"
#include "can.h"

extern char driveMode, engineMap;
extern uint32_t ADC_BUF[3];
extern Indicator_Value Indicators[N_INDICATORS];
int clutchValue = 0;

void dSensors_update(void)	{	// da definire come vanno riscalati i valori
	
	//*indizzo_nella_matrice = (float) (ADC_BUF[0] * VDD ) / LEVEL ;
	//*indizzo_nella_matrice = (float) ((((ADC_BUF[2] * VDD ) / LEVEL )*0.8) + (*indirizzo_nella_matrice * 0.2));
	return ;
}

void dSensors_Clutch_send(void)	{
	CAN_send(SW_CLUTCH_MODE_MAP_GCU_ID, clutchValue, driveMode, engineMap, EMPTY, 3);
	return ;
}

void dSensors_Sensors_send(void)	{
	/* manca la conversione della temp e corrente */
	CAN_send(SW_DEBUG_ID, 10, 35, EMPTY, EMPTY, 2);
	return ;
}

void dSensors_CLUTCH(uint16_t clutchAnalog)	{
	float aux;
	uint16_t channel_2;
//	if (clutchAnalog >= CLUTCH_MAX_VALUE)
//		clutchValue = CLUTCH_MAX_VALUE;
//	else if (clutchAnalog <= CLUTCH_MIN_VALUE)
//		clutchValue = CLUTCH_MIN_VALUE;
//	else
//		clutchValue = (int) (clutchAnalog * 0.8 ) + (clutchValue * 0.2);
//	
//	clutchValue = (int) (clutchValue / CLUTCH_MAX_VALUE * 100);
	
	aux = clutchAnalog/4095.0*100.0;
	channel_2 = (uint16_t)aux;
	Indicators[TH2O].floatValore = aux; 
	clutchValue = (uint16_t)aux;
	
	return ;
}
