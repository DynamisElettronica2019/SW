
#ifndef D_RPM_LIMITER_H
#define D_RPM_LIMITER_H

#ifdef __cplusplus
 extern "C" {
#endif

#define RPM_LIMITER_MAX_VALUE 		0
#define RPM_LIMITER_MIN_VALUE	 		7

	 
void d_rpm_limiter_propagateValue(void);
void d_rpm_limiter_setValue(int movement);
void d_rpm_limiter_handle(int movement);
	
#ifdef __cplusplus
}
#endif

#endif //D_RPM_LIMITER_H
