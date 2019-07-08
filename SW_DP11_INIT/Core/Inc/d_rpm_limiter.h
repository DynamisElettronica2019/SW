#ifndef D_RPM_LIMITER_H
#define D_RPM_LIMITER_H

#ifdef __cplusplus
 extern "C" {
#endif

#define RPM_LIMITER_MAX_VALUE 		115 /*11500*/
#define RPM_LIMITER_MIN_VALUE	 		65	/* 6500*/
#define RPM_LIMITER_STEP 					5		/*  500*/
	 
#define RPM_LIMITER_SKIDPAD_MAX_VALUE 		90  /*9000*/
#define RPM_LIMITER_SKIDPAD_MIN_VALUE	 		70	/*7000*/
#define RPM_LIMITER_SKIDPAD_STEP 					1		/* 100*/

void d_rpm_limiter_setValue(int movement);
	 
void d_rpm_limiter_init(int new_rpmLimiterValue);
	
#ifdef __cplusplus
}
#endif

#endif //D_RPM_LIMITER_H
