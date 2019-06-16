
/**
  ******************************************************************************
  * @file    d_gears.c
  ******************************************************************************
  * Propagation of the gear value to send on CANbus and update of the global 
	* value of the gear with the last data sent by EFI.
  ******************************************************************************
  */

#include "d_gears.h"
#include "can.h"		
#include "general.h"
#include "data.h"
#include "string.h"

char d_currentGear = 0;
extern Indicator_Value Indicators[N_INDICATORS];
extern int changeGearFlag;

void dGears_setGear (int newGear)
{
	switch (newGear){
		case 0:
			strcpy ( Indicators[GEAR].charValore, "N");
			break;
		case 1:
			strcpy ( Indicators[GEAR].charValore, "1");
			break;
		case 2:
			strcpy ( Indicators[GEAR].charValore, "2");
			break;
		case 3:
			strcpy ( Indicators[GEAR].charValore, "3");
			break;
		case 4:
			strcpy ( Indicators[GEAR].charValore, "4");
			break;
		case 5:
			strcpy ( Indicators[GEAR].charValore, "5");
			break;
		case 8:
			strcpy ( Indicators[GEAR].charValore, "E");
		default:
			break;
	}
	
	d_currentGear = newGear;
	Indicators[GEAR].intValore = newGear;
}

void dGear_setNeutral(void)
{
	if( d_currentGear != 0)
	{
		if( d_currentGear == 1 ){
			CAN_send(SW_GEARSHIFT_ID, GEAR_COMMAND_NEUTRAL_UP, EMPTY, EMPTY, EMPTY, 1);
			//dGears_setGear(0); //-------- TOGLIERE
		}
		
		else if ( d_currentGear == 2 ){
			CAN_send(SW_GEARSHIFT_ID, GEAR_COMMAND_NEUTRAL_DOWN, EMPTY, EMPTY, EMPTY, 1);
			//dGears_setGear(0); //-------- TOGLIERE
		}
	}	
}

void dGears_upShift(void)
{
	CAN_send(SW_GEARSHIFT_ID, GEAR_COMMAND_UP, EMPTY, EMPTY, EMPTY, 1);
	//dGears_setGear(d_currentGear+1);
}
		
void dGears_downShift(void)
{
		CAN_send(SW_GEARSHIFT_ID, GEAR_COMMAND_DOWN, EMPTY, EMPTY, EMPTY, 1);
	//dGears_setGear(d_currentGear-1);
}
