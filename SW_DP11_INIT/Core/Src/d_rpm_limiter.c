/**
  ******************************************************************************
  * @file    d_rpm_limiter.c
  ******************************************************************************
  * Computation of the new RPM limiter value and propagation of the
	*	updated value on CANbus. The RPM limiter value is sent when the driving
	* mode is either ACCELERATION or AUTOCROSS.
	* RPM limiter MAX and MIN values are decided together with GCU and EFI.
  ******************************************************************************
  */

#include "d_rpm_limiter.h"
#include "data.h"
#include "general.h"

extern Indicator_Value Indicators[N_INDICATORS];
extern int RPM_LIM_save;

int d_rpmLimiterValue;

void d_rpm_limiter_init(int new_rpmLimiterValue)
{
//	Indicators[RPM_LIM].intValore = new_rpmLimiterValue;
	d_rpmLimiterValue = new_rpmLimiterValue;
}

/**
  * @brief  computation of the new value of RPM and check if it is feasible 
  * @param  movements done with left encoder 
  */

void d_rpm_limiter_setValue(int movement)
{
	int value;
	value = (Indicators[RPM_LIM].intValore);
	
	if( Indicators[DRIVE_MODE].intValore	== SKIDPAD_MODE )
	{
		value = value - movement*RPM_LIMITER_SKIDPAD_STEP; //forse con -
		RPM_LIM_save = 1;
		
		if(value > RPM_LIMITER_SKIDPAD_MAX_VALUE){
			value = RPM_LIMITER_SKIDPAD_MAX_VALUE;
		} else if(value < RPM_LIMITER_SKIDPAD_MIN_VALUE){
			value = RPM_LIMITER_SKIDPAD_MIN_VALUE;
		}
	}
	else if( Indicators[DRIVE_MODE].intValore == AUTOX_MODE || Indicators[DRIVE_MODE].intValore == ACCELERATION_MODE )
	{
		value = value - movement*RPM_LIMITER_STEP; //forse con -
		RPM_LIM_save = 1;
		
		if(value > RPM_LIMITER_MAX_VALUE){
			value = RPM_LIMITER_MAX_VALUE;
		} else if(value < RPM_LIMITER_MIN_VALUE){
			value = RPM_LIMITER_MIN_VALUE;
		}
	}
	//Indicators[RPM_LIM].intValore = value;
	d_rpmLimiterValue = value;
}



