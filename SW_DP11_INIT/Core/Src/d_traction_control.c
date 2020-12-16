
/**
  ******************************************************************************
  * @file    d_traction_control.c
  ******************************************************************************
  * Computation of the new traction control value. The value is sent each 10ms
	* together with RPM_LIMITER. See TIM file for more info.
	* Traction MAX and MIN values are decided together with GCU and EFI. 
  ******************************************************************************
  */

#include "d_traction_control.h"
#include "data.h"

extern Indicator_Value Indicators[N_INDICATORS];
extern int	TRACTION_save;

int targetTraction;

void d_traction_control_init(int new_tractionValue)
{
	Indicators[TC].intValore = new_tractionValue;
}

/**
  * @brief  computation of the new value of traction and check if it is feasible 
  * @param  movements done with left encoder 
  */

void d_traction_control_setValue(int movement)
{
	int value;
	value = Indicators[TC].intValore;
	value = value - movement; 
	TRACTION_save = 1;
	
	if(value >= TRACTION_MAX_VALUE){
		value = TRACTION_MAX_VALUE;
  } else if(value <= TRACTION_MIN_VALUE){
    value = TRACTION_MIN_VALUE;
	}
	
	targetTraction = value;
	
	#ifdef SIM_MODE
		Indicators[TC].intValore = value;
	#endif
		
}


