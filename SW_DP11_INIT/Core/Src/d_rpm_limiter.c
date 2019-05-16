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

extern Indicator_Value Indicators[N_INDICATORS];

int d_rpmLimiterValue;

/**
  * @brief  computation of the new value of RPM and check if it is feasible 
  * @param  movements done with left encoder 
  */

void d_rpm_limiter_setValue(int movement)
{
	int value;
	value = Indicators[RPM_LIM].intValore;
	value = value + movement; //forse con -
	
	if(value > RPM_LIMITER_MAX_VALUE){
		value = RPM_LIMITER_MAX_VALUE;
  } else if(value < RPM_LIMITER_MIN_VALUE){
    value = RPM_LIMITER_MIN_VALUE;
	}

	d_rpmLimiterValue = value;
}
