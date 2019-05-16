
#ifndef D_TRACTION_CONTROL_H
#define D_TRACTION_CONTROL_H

#ifdef __cplusplus
 extern "C" {
#endif

#define TRACTION_MIN_VALUE 		0
#define TRACTION_MAX_VALUE		7

void d_traction_control_setValue(int movement);
	
#ifdef __cplusplus
}
#endif

#endif //D_TRACTION_CONTROL_H
