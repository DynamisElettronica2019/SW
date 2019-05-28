
#ifndef DATA_H
#define DATA_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"
	 
/********************DEFINES********************/
	 
#define N_INDICATORS 65 //------------- Da decidere quali indicatori utilizzare
#define TIT_LEN 11				//------------- Lunghezza massima della stringa va visualizzare come titolo
	 
#define START_BOARD GCU_BOARD	//------------- Inizio indicatori per schermata board debug !!!(messi a caso)!!!
#define END_BOARD DAU_R_BOARD		//------------- Fine indicatori per schermata board debug		!!!(messi a caso)!!!
	 
#define FIRST_CAR_PARAMETER 			0
#define	LAST_CAR_PARAMETER 				DRIVE_MODE 
	 
#define DEF_VALUE 9999  //------------- Valore con cui si inizializza la matrice di dati per capire se sono arrivati dati nuovi dal CAN o no
#define DEF_SIMBOL "?"  

#define N_DEBUG_MODE_VALUES 8	//--- numero di indicatori nella schermata di DEBUG_MODE
/********************DATA TYPE********************/	 // per ora vengono creati in freertos.c e dichiarati come extern dalle altre parti

typedef enum {
        /* car parameters */
        TH2O, OIL_PRESS, TPS, VBAT, RPM, TRACTION_CONTROL, GEAR,
				CLUTCH_POSITION, OIL_TEMP_IN, OIL_TEMP_OUT, CLUTCH_FEEDBACK, ACQ,
        TH2O_SX_IN, TH2O_SX_OUT,
        TH2O_DX_IN, TH2O_DX_OUT, EFI_SLIP, LAUNCH_CONTROL, RPM_LIM, FUEL_LEVEL,
        FUEL_PRESS, MAP, TH2O_ENGINE, VH_SPEED, PH2O, EFI_SLIP_TARGET, MAN_LIM_ACT,
				FAN, H2OPUMP_DC, PIT_LANE_ACT, FLAG_SMOT, LAMBDA, T_SCARICO_1, T_SCARICO_2,
				DRIVE_MODE,
        /* boards */
        GCU_BOARD, SW_BOARD, DCU_BOARD, XBEE,
        DAU_FL_BOARD, DAU_FR_BOARD, DAU_R_BOARD,
        /* sensors */
        FUEL_PUMP, H2O_PUMP, H2O_FAN_DX, H2O_FAN_SX, CLUTCH_CURR, GEAR_CURR,
				DCU_3V3, DCU_5V, DCU_12V, 
				ACC_X_1, ACC_Y_1, ACC_Z_1, GYR_X_1, GYR_Y_1, GYR_Z_1, HEAD_1,
				ACC_X_2, ACC_Y_2, ACC_Z_2, GYR_X_2, GYR_Y_2, GYR_Z_2, HEAD_2			
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
				int intValore2; // per corrente e temperatura
				char	charValore[2];	//per gli indicatori tipo la marcia che posso contenre una lettera (come la N)
} Indicator_Value;

//typedef struct {
//        Indicator_Value *BOX[6];
//} Indicator_Pointer;

typedef struct {
	CAN_RxHeaderTypeDef CAN_RxPacket_Header;
	uint8_t CAN_RxPacket_Data[8];
} CAN_RxPacketTypeDef;


#ifdef __cplusplus
}
#endif

#endif //DATA_H
