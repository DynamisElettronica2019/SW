
#include "data.h"
#include "general.h"

uint8_t  EndPointer[6], AccPointer[6], AutPointer[6], SkiPointer[6];

Indicator_Value Indicators[N_INDICATORS];	

void data_indicatorsInit(void)
{
  Indicators[TH2O] 							= (Indicator_Value) {TH2O, FLOAT, "TH2O", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};	
	Indicators[OIL_PRESS] 				= (Indicator_Value) {OIL_PRESS, FLOAT, "POIL", DEF_VALUE,DEF_VALUE , DEF_VALUE,"?"};
	Indicators[TPS] 							= (Indicator_Value) {TPS, FLOAT, "TPS", DEF_VALUE,DEF_VALUE, DEF_VALUE,"?"};
  Indicators[VBAT] 							= (Indicator_Value) {VBAT, FLOAT, "VBAT", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[RPM] 							= (Indicator_Value) {RPM, INT, "RPM", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};	
	Indicators[TRACTION_CONTROL] 	= (Indicator_Value) {TRACTION_CONTROL, INT,"TC", 6, 0, 0,"?"};	
  Indicators[GEAR] 							= (Indicator_Value) {GEAR, INT,"GEAR", 0, 0, 0,"N"};	
	Indicators[CLUTCH_POSITION] 	= (Indicator_Value) {CLUTCH_POSITION, INT, "CLUTCH", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[OIL_TEMP_IN] 			= (Indicator_Value) {OIL_TEMP_IN, FLOAT,"TOIL_I", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
	Indicators[OIL_TEMP_OUT] 			= (Indicator_Value) {OIL_TEMP_OUT, FLOAT,"TOIL_O", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
	Indicators[CLUTCH_FEEDBACK]	 	= (Indicator_Value) {CLUTCH_FEEDBACK, INT, "CLUTCHFB", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  

	Indicators[AN_MAN_LIM] 				= (Indicator_Value) {AN_MAN_LIM, INT, "AN_MAN_LIM", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};							//ok
	Indicators[AN_SLIP_TRIM] 				= (Indicator_Value) {AN_SLIP_TRIM, INT, "AN_S_TRIM", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};							//ok
	Indicators[AN_SLIP_TRGT] 				= (Indicator_Value) {AN_SLIP_TRGT, INT, "AN_S_TRGT", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};							//ok
	Indicators[OIL_LEVEL] 				= (Indicator_Value) {OIL_LEVEL, INT, "L_OIL", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};							//ok

	Indicators[ACQ] 							= (Indicator_Value) {ACQ, INT, "ACQ", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};							//ok
  Indicators[TH2O_SX_IN] 				= (Indicator_Value) {TH2O_SX_IN, FLOAT, "TH_SX_I", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};		//-----
  Indicators[TH2O_SX_OUT] 			= (Indicator_Value) {TH2O_SX_OUT, FLOAT, "TH_SX_O", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};		//-----
  Indicators[TH2O_DX_IN] 				= (Indicator_Value) {TH2O_DX_IN, FLOAT, "TH_DX_I", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};		//-----
  Indicators[TH2O_DX_OUT] 			= (Indicator_Value) {TH2O_DX_OUT, FLOAT, "TH_DX_O", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};		//-----
  Indicators[EFI_SLIP] 					= (Indicator_Value) {EFI_SLIP, FLOAT, "EFI_SLIP", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};			// ok

  Indicators[RPM_LIM] 					= (Indicator_Value) {RPM_LIM, INT, "RPM_LIM", 9, DEF_VALUE, DEF_VALUE,"?"};
	Indicators[FUEL_LEVEL] 				= (Indicator_Value) {FUEL_LEVEL, FLOAT, "FUEL", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[FUEL_PRESS] 				= (Indicator_Value) {FUEL_PRESS, FLOAT, "PFUEL", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
//  Indicators[MAP] 							= (Indicator_Value) {MAP, INT, "MAP", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};

	Indicators[VH_SPEED]					= (Indicator_Value) {VH_SPEED, FLOAT, "VH_SPEED", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[PH2O] 							= (Indicator_Value) {PH2O, FLOAT, "PH2O", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[EFI_SLIP_TARGET]		= (Indicator_Value) {EFI_SLIP_TARGET, FLOAT, "EFI_SL_T", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[MAN_LIM_ACT]				= (Indicator_Value) {MAN_LIM_ACT, INT, "MAN_LIM", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[FAN] 							= (Indicator_Value) {FAN, INT, "FAN", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[H2OPUMP_DC] 				= (Indicator_Value) {H2OPUMP_DC, INT, "H2O_DC", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[PIT_LANE_ACT]			= (Indicator_Value) {PIT_LANE_ACT, INT, "PITLANE", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[FLAG_SMOT]					= (Indicator_Value) {FLAG_SMOT, INT, "SMOT", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[LAMBDA]						= (Indicator_Value) {LAMBDA, FLOAT, "LAMBDA", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[T_SCARICO_1] 			= (Indicator_Value) {T_SCARICO_1, FLOAT, "T_SC_1", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[T_SCARICO_2] 			= (Indicator_Value) {T_SCARICO_2, FLOAT, "T_SC_2", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[DRIVE_MODE]				= (Indicator_Value) {DRIVE_MODE, INT, "MODE", 0, 0, 0,"?"};
	
	Indicators[GCU_BOARD] 				= (Indicator_Value) {GCU_BOARD, FLOAT, "GCU", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
	Indicators[SW_BOARD] 					= (Indicator_Value) {SW_BOARD, FLOAT, "SW", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
	Indicators[DCU_BOARD] 				= (Indicator_Value) {DCU_BOARD, FLOAT, "DCU", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
	Indicators[XBEE] 							= (Indicator_Value) {XBEE, FLOAT, "XBEE", DEF_VALUE, DEF_VALUE,DEF_VALUE,"?"};
	Indicators[DAU_FL_BOARD] 			= (Indicator_Value) {DAU_FL_BOARD, FLOAT, "DAU_FL", DEF_VALUE,DEF_VALUE, DEF_VALUE,"?"};
	Indicators[DAU_FR_BOARD] 			= (Indicator_Value) {DAU_FR_BOARD, FLOAT, "DAU_FR", DEF_VALUE,DEF_VALUE, DEF_VALUE,"?"};
	Indicators[DAU_R_BOARD] 			= (Indicator_Value) {DAU_R_BOARD, FLOAT, "DAU_R", DEF_VALUE,DEF_VALUE, DEF_VALUE,"?"};
 
  Indicators[FUEL_PUMP] 				= (Indicator_Value) {FUEL_PUMP, FLOAT, "FUEL_PUMP", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[H2O_PUMP] 					= (Indicator_Value) {H2O_PUMP, FLOAT, "H20_PUMP", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[H2O_FAN_DX] 				= (Indicator_Value) {H2O_FAN_DX, FLOAT, "HFAN_DX", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[H2O_FAN_SX] 				= (Indicator_Value) {H2O_FAN_SX, FLOAT, "HFAN_SX", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[CLUTCH_CURR]				= (Indicator_Value) {CLUTCH_CURR, FLOAT, "CLUTCH", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[GEAR_CURR] 				= (Indicator_Value) {GEAR_CURR, FLOAT, "GEAR", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[DCU_3V3] 					= (Indicator_Value) {DCU_3V3, INT, "DCU_3V3", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[DCU_5V] 						= (Indicator_Value) {DCU_5V, INT, "DCU_5V", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[DCU_12V] 					= (Indicator_Value) {DCU_12V, INT, "DCU_12V", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[ACC_X_1] 					= (Indicator_Value) {ACC_X_1, FLOAT, "ACC_X_1", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[ACC_Y_1] 					= (Indicator_Value) {ACC_Y_1, FLOAT, "ACC_Y_1", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[ACC_Z_1] 					= (Indicator_Value) {ACC_Z_1, FLOAT, "ACC_Z_1", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[GYR_X_1] 					= (Indicator_Value) {GYR_X_1, FLOAT, "GYR_X_1", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[GYR_Y_1] 					= (Indicator_Value) {GYR_Y_1, FLOAT, "GYR_Y_1", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[GYR_Z_1] 					= (Indicator_Value) {GYR_Z_1, FLOAT, "GYR_Z_1", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[HEAD_1] 						= (Indicator_Value) {HEAD_1, FLOAT, "HEAD_1", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[ACC_X_2] 					= (Indicator_Value) {ACC_X_2, FLOAT, "ACC_X_2", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[ACC_Y_2] 					= (Indicator_Value) {ACC_Y_2, FLOAT, "ACC_Y_2", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[ACC_Z_2] 					= (Indicator_Value) {ACC_Z_2, FLOAT, "ACC_Z_2", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[GYR_X_2] 					= (Indicator_Value) {GYR_X_2, FLOAT, "GYR_X_2", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[GYR_Y_2] 					= (Indicator_Value) {GYR_Y_2, FLOAT, "GYR_Y_2", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[GYR_Z_2] 					= (Indicator_Value) {GYR_Z_2, FLOAT, "GYR_Z_2", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[HEAD_2] 						= (Indicator_Value) {HEAD_2, FLOAT, "HEAD_2", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};

	Indicators[MAP] = (Indicator_Value) {MAP, INT, "MAP", 0, 0, 0,"?"};

}

void data_efiOff(void)
{
  Indicators[TH2O_SX_IN] 				= (Indicator_Value) {TH2O_SX_IN, FLOAT, "TH_SX_I", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};		//-----
  Indicators[TH2O_SX_OUT] 			= (Indicator_Value) {TH2O_SX_OUT, FLOAT, "TH_SX_O", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};		//-----
  Indicators[TH2O_DX_IN] 				= (Indicator_Value) {TH2O_DX_IN, FLOAT, "TH_DX_I", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};		//-----
  Indicators[TH2O_DX_OUT] 			= (Indicator_Value) {TH2O_DX_OUT, FLOAT, "TH_DX_O", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};		//-----
  Indicators[OIL_TEMP_IN] 			= (Indicator_Value) {OIL_TEMP_IN, FLOAT,"TOIL_I", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
	Indicators[OIL_TEMP_OUT] 			= (Indicator_Value) {OIL_TEMP_OUT, FLOAT,"TOIL_O", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
	Indicators[TH2O] 							= (Indicator_Value) {TH2O, FLOAT, "TH2O", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};	
	Indicators[OIL_PRESS] 				= (Indicator_Value) {OIL_PRESS, FLOAT, "POIL", DEF_VALUE,DEF_VALUE , DEF_VALUE,"?"};
  Indicators[VBAT] 							= (Indicator_Value) {VBAT, FLOAT, "VBAT", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[VBAT] 							= (Indicator_Value) {VBAT, FLOAT, "VBAT", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[RPM] 							= (Indicator_Value) {RPM, INT, "RPM", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};	
  Indicators[PH2O] 							= (Indicator_Value) {PH2O, FLOAT, "PH2O", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
	Indicators[VH_SPEED]					= (Indicator_Value) {VH_SPEED, FLOAT, "VH_SPEED", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[EFI_SLIP_TARGET]		= (Indicator_Value) {EFI_SLIP_TARGET, FLOAT, "EFI_SL_T", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
	Indicators[EFI_SLIP] 					= (Indicator_Value) {EFI_SLIP, FLOAT, "EFI_SLIP", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};			// ok
	Indicators[MAN_LIM_ACT]				= (Indicator_Value) {MAN_LIM_ACT, INT, "MAN_LIM", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[FAN] 							= (Indicator_Value) {FAN, INT, "FAN", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[H2OPUMP_DC] 				= (Indicator_Value) {H2OPUMP_DC, INT, "H2O_DC", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[PIT_LANE_ACT]			= (Indicator_Value) {PIT_LANE_ACT, INT, "PITLANE", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
	Indicators[FUEL_PRESS] 				= (Indicator_Value) {FUEL_PRESS, FLOAT, "PFUEL", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[FLAG_SMOT]					= (Indicator_Value) {FLAG_SMOT, INT, "SMOT", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[LAMBDA]						= (Indicator_Value) {LAMBDA, FLOAT, "LAMBDA", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[T_SCARICO_1] 			= (Indicator_Value) {T_SCARICO_1, FLOAT, "T_SC_1", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
  Indicators[T_SCARICO_2] 			= (Indicator_Value) {T_SCARICO_2, FLOAT, "T_SC_2", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
 	Indicators[FUEL_LEVEL] 				= (Indicator_Value) {FUEL_LEVEL, FLOAT, "FUEL", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
}
