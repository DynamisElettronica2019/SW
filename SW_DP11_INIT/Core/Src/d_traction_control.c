
/**
  ******************************************************************************
  * @file    d_traction_control.c
  ******************************************************************************
  * Computation of the new traction control value and propagation of the
	*	updated value on CANbus. The traction value is sent when the driving
	* mode is among ENDURANCE, ACCELERATION, AUTOCROSS and SKIDPAD.
	* Traction MAX and MIN values are decided together with GCU and EFI. 
  ******************************************************************************
  */

#include "d_traction_control.h"
#include "data.h"

extern Indicator_Value Indicators[N_INDICATORS];

int d_tractionValue;

/**
  * @brief  computation of the new value of traction and check if it is feasible 
  * @param  movements done with left encoder 
  */

void d_traction_control_setValue(int movement)
{
	int value;
	value = Indicators[TRACTION_CONTROL].intValore;
	value = value + movement; //forse con -
	
	if(value > TRACTION_MAX_VALUE){
		value = TRACTION_MAX_VALUE;
  } else if(value < TRACTION_MIN_VALUE){
    value = TRACTION_MIN_VALUE;
	}
	
	d_tractionValue = value;
}


