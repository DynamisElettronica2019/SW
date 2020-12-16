
/**
  ******************************************************************************
  * @file    d_power_limiter.c
  ******************************************************************************
  * Computation of the new power limiter value. The value is sent each 10ms
	* together with other targets. See TIM file for more info.
	* Power limiter MAX and MIN values are decided together with VCU. 
  ******************************************************************************
  */

#include "d_pow_limiter.h"
#include "data.h"

extern Indicator_Value Indicators[N_INDICATORS];
extern int POW_LIM_save;
extern int timerPowerLimiterSave;

int targetPower;

void d_power_limiter_init(int new_powerLimiterValue)
{
	Indicators[POW_LIM].intValore = new_powerLimiterValue;
}

/**
  * @brief  computation of the new value of power limiter and check if it is feasible 
  * @param  movements done with right encoder 
  */

void d_power_limiter_setValue(int movement)
{
	int value;
	
	timerPowerLimiterSave = 0;
	
	value = Indicators[POW_LIM].intValore;
	
	value = value - movement; 
	POW_LIM_save = 1;
	
	if(value >= POW_LIMITER_MAX_VALUE){
		value = POW_LIMITER_MAX_VALUE;
  } else if(value <= POW_LIMITER_MIN_VALUE){
    value = POW_LIMITER_MIN_VALUE;
	}
	
	targetPower = value;

	#ifdef SIM_MODE
		Indicators[POW_LIM].intValore = value;
	#endif
}


