
#ifndef D_TORQUE_VECTORING_H
#define D_TORQUE_VECTORING_H

#ifdef __cplusplus
 extern "C" {
#endif

#define TV_MIN_VALUE 		-1
#define TV_MAX_VALUE		5

void d_torque_vectoring_setValue(int movement);
	 
void d_torque_vectoring_init(int new_torqueValue);
	
#ifdef __cplusplus
}
#endif

#endif //D_TORQUE_VECTORING_H
