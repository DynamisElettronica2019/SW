
/**
  ******************************************************************************
  * @file    d_torque_vectoring.c
  ******************************************************************************
  * Computation of the new torque vectoring value. The value is sent each 10ms
	* together with other targets. See TIM file for more info.
	* Torque MAX and MIN values are decided together with VCU. 
  ******************************************************************************
  */

#include "d_torque_vectoring.h"
#include "data.h"
#include "general.h"

extern Indicator_Value Indicators[N_INDICATORS];
extern int TV_save;
extern int timerTorqueVectoringSave;

int targetTorque;

void d_torque_vectoring_init(int new_torqueValue)
{
	Indicators[TV].intValore = new_torqueValue;
}

/**
  * @brief  computation of the new value of torque and check if it is feasible 
  * @param  movements done with right encoder 
  */


void d_torque_vectoring_setValue(int movement)
{
	int value;
	if(Indicators[DRIVE_MODE].intValore == ACCELERATION_MODE)
		value = 0;
	else{
		value = Indicators[TV].intValore;
		value = value - movement; 
		TV_save = 1;
		
		if(value >= TV_MAX_VALUE){
			value = TV_MAX_VALUE;
		} else if(value <= TV_MIN_VALUE){
			value = TV_MIN_VALUE;
		}
	}
	
	targetTorque = value;
	
	#ifdef SIM_MODE
		Indicators[TV].intValore = value;
	#endif
		
}

//void d_torque_vectoring_setValue(int movement)
//{
//	int value;
//	
//	timerTorqueVectoringSave = 0;
//	
//	value = Indicators[TRACTION_CONTROL].intValore;
//	
//	if ( value == 255 ){
//		value = 0;
//	}
//	
//	value = value - movement; 
//	TV_save = 1;

//	if(value >= TORQUE_MAX_VALUE){
//		value = TORQUE_MAX_VALUE;
//  } else if(value <= TORQUE_MIN_VALUE){
//    value = TORQUE_MIN_VALUE;
//	}
//	
//	if ( value == 0 ){
//		value = 255;
//	}
//	else if ( value == -1 ){
//		value = 0;
//	}

//	targetTorque = value;
//	
//	#ifdef SIM_MODE
//		Indicators[TV].intValore = value;
//	#endif
//	
//}


