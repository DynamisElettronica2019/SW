
#ifndef ID_CAN_H
#define ID_CAN_H

/************************** EFI ***************************/
#define EFI_HALL_WHEEL_ID														0x304
#define EFI_WATER_TEMPERATURE_ID										0x30C
#define EFI_OIL_T_ENGINE_BAT_ID											0x30D
#define EFI_GEAR_RPM_TPS_PH2O_ID										0x305
#define EFI_TRACTION_CONTROL_ID											0x306
#define EFI_MANUAL_LIMITER_FAN_H2O_PIT_LANE_ID			0x30E
#define EFI_PRESSURES_LAMBDA_SMOT_ID								0x307
#define EFI_LOIL_EXHAUST_ID													0x30F


/************************ GCU *****************************/
#define GCU_TRACTION_LIMITER_LOIL_EFI_ID						0x500
#define GCU_CLUTCH_MODE_MAP_SW_ID										0x310
#define GCU_TRACTION_LIMITER_AUTOG_ACC_SW_ID				0x311


/********************* STEERING WHEEL *********************/
#define SW_FIRE_GCU_ID															0x204
#define SW_GEARSHIFT_ID															0x200
#define SW_CLUTCH_MODE_MAP_GCU_ID										0x201
#define SW_OK_BUTTON_GCU_ID													0x202
#define SW_TRACTION_LIMITER_GCU_ID									0x203
#define SW_ACQUISITION_DCU_ID												0x400

/************************** DCU ***************************/
#define DCU_ACQUISITION_SW_ID												0x401
#define DCU_AUTOGEARSHIFT_GCU_ID										0x207


/************************** DAU ***************************/
#define DAU_FR_ID																		0x650
#define DAU_FL_ID																		0x651
#define DAU_REAR_ID																	0x652
#define DAU_FL_IR_ID																0x654
#define DAU_FR_IR_ID																0x655
#define DAU_REAR_IR_RL_ID														0x656
#define DAU_REAR_IR_RR_ID														0x657


/************************** IMU ***************************/
#define IMU1_DATA_1_ID															0x70A
#define IMU1_DATA_2_ID															0x70B
#define IMU2_DATA_1_ID															0x70C
#define IMU2_DATA_2_ID															0x70D


/************************* DEBUG **************************/
#define DAU_FR_DEBUG_ID															0x312
#define DAU_FL_DEBUG_ID															0x313
#define DAU_REAR_DEBUG_ID														0x314
#define SW_DEBUG_ID																	0x315
#define GCU_DEBUG_1_ID															0x316
#define GCU_DEBUG_2_ID															0x317
#define DCU_DEBUG_1_ID															0x318
#define DCU_DEBUG_2_ID															0x319



/******************* MASKS & FILTERS **********************/
/* ANCORA DA DEFINIRE
//MASK
#define SW_MASK_EFI_DEBUG_IMU_EBB                0b11111100000
//FILTERS
#define SW_FILTER_EFI_DEBUG                                0b01100000000
#define SW_FILTER_IMU_EBB                                0b11100000000

//MASK
#define GCU_MASK_EFI_SW_EBB                                0b11111110100
//FILTERS
#define GCU_FILTER_EFI                                        0b01100000100
#define GCU_FILTER_SW_DCU                                0b01000000000
*/



#endif //ID_CAN_H
