
#ifndef DATA_H
#define DATA_H

#ifdef __cplusplus
 extern "C" {
#endif
/********************DEFINES********************/
	 
#define N_INDICATORS 50	//------------- Da decidere quali indicatori utilizzare
#define TIT_LEN 7				//------------- Lunghezza massima della stringa va visualizzare come titolo
#define START_BOARD 10	//------------- Inizio indicatori per schermata board debug !!!(messi a caso)!!!
#define END_BOARD 20		//------------- Fine indicatori per schermata board debug		!!!(messi a caso)!!!
	
/********************DATA TYPE********************/	 // per ora vengono creati in freertos.c e dichiarati come extern dalle altre parti

typedef enum {
        /* car parameters */
        EBB, TH2O, OIL_PRESS, TPS, VBAT, RPM, Adc, TRACTION_CONTROL, 
				CLUTCH_POSITION, OIL_TEMP_IN, OIL_TEMP_OUT, CLUTCH_FEEDBACK, ACQ,
        EFI_STATUS, TRIM1, TRIM2, EFI_CRASH_COUNTER, TH2O_SX_IN, TH2O_SX_OUT,
        TH2O_DX_IN, TH2O_DX_OUT, EBB_STATE, EFI_SLIP, LAUNCH_CONTROL, RPM_LIM,
        FUEL_PRESS, EBB_MOTOR_CURRENT, GCU_TEMP, FB_CODE, FB_VAL, MAP,
        /* settings */
        S_DASH_TOP_L, S_DASH_TOP_R, S_DASH_BOTTOM_L, S_DASH_BOTTOM_R,
        S_BYPASS_GEARS, S_INVERT_COLORS,
        /* boards */
        EBB_BOARD, GCU_BOARD, SW_BOARD, DCU_BOARD,
        DAU_FL_BOARD, DAU_FR_BOARD, DAU_R_BOARD,
        /* sensors */
        FUEL_PUMP, H2O_PUMP, H2O_FANS, CLUTCH, DRS_CURR,
        GEAR_MOTOR
} Indicator_ID;

typedef enum { 
				INT, FLOAT 
} Type;

typedef struct {
        Indicator_ID ID;
        Type TIPO;
        char NOME[TIT_LEN];
        int intValore;
        float floatValore;
				char	charValore[2];	//per gli indicatori tipo la marcia che posso contenre una lettera (come la N)
} Indicator_Value;

//typedef struct {
//        Indicator_Value *BOX[6];
//} Indicator_Pointer;

	 

#ifdef __cplusplus
}
#endif

#endif //DATA_H
