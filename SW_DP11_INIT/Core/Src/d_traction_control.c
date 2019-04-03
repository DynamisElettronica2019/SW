
/**
  ******************************************************************************
  * @file    d_traction_control.c
  ******************************************************************************
  * Computation of the new traction control value and propagation of the
	*	updated value on CANbus. The traction value is sent when the driving
	* mode is among ENDURANCE, ACCELERATION, AUTOCROSS and SKIDPAD.
	* Traction MAX and MIN values are decided together with GCU. 
  ******************************************************************************
  */

#include "d_traction_control.h"
//#include "can.h"

int d_tractionValue;

/**
  * @brief  send on can the new value of traction control
  */
	
void d_traction_control_propagateValue(void)
{
	//send value on can d_tractionValue
}

/**
  * @brief  computation of the new value of traction and check if it is feasible 
  * @param  movements done with left encoder 
  */

void d_traction_control_setValue(int movement)
{
	int value;
	// value = traction control value dalla matrice globale perchè
	// è aggiornato dal mex can
	value = value + movement; //forse con -
	
	if(value > TRACTION_MAX_VALUE){
		value = TRACTION_MAX_VALUE;
  } else if(value < TRACTION_MIN_VALUE){
    value = TRACTION_MIN_VALUE;
	}
	
	d_tractionValue = value;
}


/**
  * @brief  compute the new value of traction control and send it on CAN
  * @param  movements done with left encoder 
  */

void d_traction_control_handle(int movement)
{
	d_traction_control_setValue(movement);	
	d_traction_control_propagateValue();	
}

