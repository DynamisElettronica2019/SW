
#ifndef D_POW_LIMITER_H
#define D_POW_LIMITER_H

#ifdef __cplusplus
 extern "C" {
#endif

#define POW_LIMITER_MAX_VALUE 		10 	/*100000*/
#define POW_LIMITER_MIN_VALUE	 		1		/* 10000*/
#define POW_LIMITER_STEP 					1		/*  500*/
	 
//#define POW_LIMITER_SKIDPAD_MAX_VALUE 		9  /*9000*/
//#define POW_LIMITER_SKIDPAD_MIN_VALUE	 		7	/*7000*/
//#define POW_LIMITER_SKIDPAD_STEP 					1		/* 100*/

void d_power_limiter_setValue(int movement);
	 
void d_power_limiter_init(int new_powerLimiterValue);
	
#ifdef __cplusplus
}
#endif

#endif //D_POW_LIMITER_H
