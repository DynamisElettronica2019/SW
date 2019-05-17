
#ifndef D_GEARS_H
#define D_GEARS_H

#ifdef __cplusplus
 extern "C" {
#endif
	 
#define MIN_GEAR 1
#define MAX_GEAR 5
	 
#define EFI_GEAR_COMMAND_NEUTRAL   		  0
#define EFI_GEAR_COMMAND_ERROR    		  8

	 
#define GEAR_COMMAND_UP 								400
#define GEAR_COMMAND_DOWN  	    				200
	 
#define GEAR_COMMAND_NEUTRAL_UP 				50
#define GEAR_COMMAND_NEUTRAL_DOWN   		100
	 
void dGears_upShift(void);
void dGears_downShift(void);
void dGears_setGear(int newGear);
void dGears_setNeutral(void);
	 
#ifdef __cplusplus
}
#endif

#endif //D_GEARS_H


