
#include "data.h"
#include "general.h"
#include "i2c.h"

uint8_t  EndPointer[4], AccPointer[4], AutPointer[4], SkiPointer[4];

Indicator_Value Indicators[N_INDICATORS];	

extern int targetTraction;
extern int targetTorque;
extern int targetPower;
extern int targetKalman;

void data_indicatorsInit(void)
{
		Indicators[TV] = (Indicator_Value) {TV, INT, "TV", 0, 0, 0, "?"};
		Indicators[SOC] = (Indicator_Value) {SOC, INT, "SOC", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[VBAT] = (Indicator_Value) {VBAT, INT, "V BAT", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TC] = (Indicator_Value) {TC, INT, "TC", 0, 0, 0, "?"};
		Indicators[TS] = (Indicator_Value) {TS, INT, "TS", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[ACQ] = (Indicator_Value) {ACQ, INT, "ACQ", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[REGEN] = (Indicator_Value) {REGEN, INT, "REGEN", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[SD_STATE] = (Indicator_Value) {SD_STATE, INT, "SD_STATE", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[MAP] = (Indicator_Value) {MAP, INT, "MAP", DEF_VALUE, DEF_VALUE, DEF_VALUE,"?"};
		Indicators[DRIVE_MODE] = (Indicator_Value) {DRIVE_MODE, INT, "MODE", 0, 0, 0,"?"};
		Indicators[POW_LIM] = (Indicator_Value) {POW_LIM, INT, "POW_LIM", 8, DEF_VALUE, DEF_VALUE,"?"};
		Indicators[TH2O_FL] = (Indicator_Value) {TH2O_FL, FLOAT, "TH2O_FL", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TH2O_FR] = (Indicator_Value) {TH2O_FR, FLOAT, "TH2O_FR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TOIL_FR] = (Indicator_Value) {TOIL_FR, FLOAT, "TOIL_FR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TOIL_FL] = (Indicator_Value) {TOIL_FL, FLOAT, "TOIL_FL", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TH2O_RR] = (Indicator_Value) {TH2O_RR, FLOAT, "TH2O_RR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TH2O_RL] = (Indicator_Value) {TH2O_RL, FLOAT, "TH2O_RL", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TBRAKE_FR] = (Indicator_Value) {TBRAKE_FR, FLOAT, "TBRAKE_FR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TBRAKE_FL] = (Indicator_Value) {TBRAKE_FL, FLOAT, "TBRAKE_FL", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TBRAKE_RR] = (Indicator_Value) {TBRAKE_RR, FLOAT, "TBRAKE_RR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TBRAKE_RL] = (Indicator_Value) {TBRAKE_RL, FLOAT, "TBRAKE_RL", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TOIL_RR] = (Indicator_Value) {TOIL_RR, FLOAT, "TOIL_RR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TOIL_RL] = (Indicator_Value) {TOIL_RL, FLOAT, "TOIL_RL", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TH2O_RAD] = (Indicator_Value) {TH2O_RAD, FLOAT, "TH2O_RAD", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[PH2O] = (Indicator_Value) {PH2O, FLOAT, "PH2O", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[PBRAKE_F] = (Indicator_Value) {PBRAKE_F, FLOAT, "PBRAKE_F", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[PBRAKE_R] = (Indicator_Value) {PBRAKE_R, FLOAT, "PBRAKE_R", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[PITOT] = (Indicator_Value) {PITOT, FLOAT, "PITOT", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[STRAIN_GAUGE_FR] = (Indicator_Value) {STRAIN_GAUGE_FR, FLOAT, "STR_G_FR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[STRAIN_GAUGE_FL] = (Indicator_Value) {STRAIN_GAUGE_FL, FLOAT, "STR_G_FL", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[SW_ANGLE] = (Indicator_Value) {SW_ANGLE, FLOAT, "SW_ANGLE", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[STRAIN_GAUGE_RR] = (Indicator_Value) {STRAIN_GAUGE_RR, FLOAT, "STR_G_RR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[STRAIN_GAUGE_RL] = (Indicator_Value) {STRAIN_GAUGE_RL, FLOAT, "STR_G_RL", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[PT100] = (Indicator_Value) {PT100, FLOAT, "PT100", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[BRAKE_BIAS] = (Indicator_Value) {BRAKE_BIAS, FLOAT, "BRAKE_BIAS", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[APPS_1] = (Indicator_Value) {APPS_1, INT, "APPS_1", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[APPS_2] = (Indicator_Value) {APPS_2, INT, "APPS_2", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[LOAD_CELL] = (Indicator_Value) {LOAD_CELL, FLOAT, "LOAD_CELL", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[IMPLAUSIBILITY] = (Indicator_Value) {IMPLAUSIBILITY, INT, "IMPL", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[PWM_BATTERY_FAN] = (Indicator_Value) {PWM_BATTERY_FAN, INT, "PWM_BAT_FAN", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[PWM_RAD_FAN] = (Indicator_Value) {PWM_RAD_FAN, INT, "PWM_RAD_FAN", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[VOLTAGE_12V_DCU] = (Indicator_Value) {VOLTAGE_12V_DCU, FLOAT, "12V_DCU", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[VOLTAGE_5V_DCU] = (Indicator_Value) {VOLTAGE_5V_DCU, FLOAT, "5V_DCU", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[VOLTAGE_3V3_DCU] = (Indicator_Value) {VOLTAGE_3V3_DCU, FLOAT, "3V3_DCU", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[VOLTAGE_24V_VCU] = (Indicator_Value) {VOLTAGE_24V_VCU, FLOAT, "24V_VCU", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[VOLTAGE_5V_VCU] = (Indicator_Value) {VOLTAGE_5V_VCU, FLOAT, "5V_VCU", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[VOLTAGE_3V3_VCU] = (Indicator_Value) {VOLTAGE_3V3_VCU, FLOAT, "3V3_VCU", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[LVB_VOLTAGE] = (Indicator_Value) {LVB_VOLTAGE, FLOAT, "LVB_VOLT", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[DCDC_VOLTAGE] = (Indicator_Value) {DCDC_VOLTAGE, FLOAT, "DCDC_VOLT", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[GLVS_CURR] = (Indicator_Value) {GLVS_CURR, FLOAT, "GLVS_CURR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[PUMP_CURR] = (Indicator_Value) {PUMP_CURR, FLOAT, "PUMP_CURR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[SPEAKER_CURR] = (Indicator_Value) {SPEAKER_CURR, FLOAT, "SPEAK_CURR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[DCDC_CURR] = (Indicator_Value) {DCDC_CURR, FLOAT, "DCDC_CURR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[BATTERY_FAN_CURR] = (Indicator_Value) {BATTERY_FAN_CURR, FLOAT, "BAT_FAN_C", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[RAD_FAN_CURR] = (Indicator_Value) {RAD_FAN_CURR, FLOAT, "RAD_FAN_C", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[INVERTER_CURR] = (Indicator_Value) {INVERTER_CURR, FLOAT, "INV_CURR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[XBEE] = (Indicator_Value) {XBEE, FLOAT, "XBEE", DEF_VALUE, DEF_VALUE,DEF_VALUE,"?"};
		Indicators[ACC_X_FRONT] = (Indicator_Value) {ACC_X_FRONT, FLOAT, "ACC_X_F", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[ACC_Y_FRONT] = (Indicator_Value) {ACC_Y_FRONT, FLOAT, "ACC_Y_F", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[ACC_Z_FRONT] = (Indicator_Value) {ACC_Z_FRONT, FLOAT, "ACC_Z_F", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[ACC_X_REAR] = (Indicator_Value) {ACC_X_REAR, FLOAT, "ACC_X_R", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[ACC_Y_REAR] = (Indicator_Value) {ACC_Y_REAR, FLOAT, "ACC_Y_R", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[ACC_Z_REAR] = (Indicator_Value) {ACC_Z_REAR, FLOAT, "ACC_Z_R", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[GYRO_X_FRONT] = (Indicator_Value) {GYRO_X_FRONT, FLOAT, "GYRO_X_F", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[GYRO_Y_FRONT] = (Indicator_Value) {GYRO_Y_FRONT, FLOAT, "GYRO_Y_F", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[GYRO_Z_FRONT] = (Indicator_Value) {GYRO_Z_FRONT, FLOAT, "GYRO_Z_F", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[GYRO_X_REAR] = (Indicator_Value) {GYRO_X_REAR, FLOAT, "GYRO_X_R", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[GYRO_Y_REAR] = (Indicator_Value) {GYRO_Y_REAR, FLOAT, "GYRO_Y_R", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[GYRO_Z_REAR] = (Indicator_Value) {GYRO_Z_REAR, FLOAT, "GYRO_Z_R", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[INSS_ACC_X] = (Indicator_Value) {INSS_ACC_X, FLOAT, "IMU_ACC_X", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[INSS_ACC_Y] = (Indicator_Value) {INSS_ACC_Y, FLOAT, "IMU_ACC_Y", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[INSS_ACC_Z] = (Indicator_Value) {INSS_ACC_Z, FLOAT, "IMU_ACC_Z", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[INSS_GYRO_X] = (Indicator_Value) {INSS_GYRO_X, FLOAT, "IMU_GYRO_X", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[INSS_GYRO_Y] = (Indicator_Value) {INSS_GYRO_Y, FLOAT, "IMU_GYRO_Y", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[INSS_GYRO_Z] = (Indicator_Value) {INSS_GYRO_Z, FLOAT, "IMU_GYRO_Z", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[INSS_SPEED] = (Indicator_Value) {INSS_SPEED, FLOAT, "SPEED", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[INSS_LAT] = (Indicator_Value) {INSS_LAT, FLOAT, "LAT", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[INSS_LONG] = (Indicator_Value) {INSS_LONG, FLOAT, "LONG", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[INSS_HDOP] = (Indicator_Value) {INSS_HDOP, INT, "HDOP", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[INSS_N_SETELLITES] = (Indicator_Value) {INSS_N_SETELLITES, INT, "N_SET", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[V_TS_INVERTER] = (Indicator_Value) {V_TS_INVERTER, INT, "V_TS_INVR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[V_TS_ACCUMULATOR] = (Indicator_Value) {V_TS_ACCUMULATOR, INT, "V_TS_ACC", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[SUM_OF_CELLS] = (Indicator_Value) {SUM_OF_CELLS, INT, "SUM_CELLS", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[MAX_CELL_VOLTAGE] = (Indicator_Value) {MAX_CELL_VOLTAGE, FLOAT, "MAX_CELL_V", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[MIN_CELL_VOLTAGE] = (Indicator_Value) {MIN_CELL_VOLTAGE, FLOAT, "MIN_CELL_V", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[ACC_AIR_TEMP1] = (Indicator_Value) {ACC_AIR_TEMP1, FLOAT, "AIR_TEMP1", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[ACC_AIR_TEMP2] = (Indicator_Value) {ACC_AIR_TEMP2, FLOAT, "AIR_TEMP2", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[ACC_STATE] = (Indicator_Value) {ACC_STATE, INT, "ACC_STATE", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[IMD_INS] = (Indicator_Value) {IMD_INS, INT, "IMD_INS", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[BMS_STATE] = (Indicator_Value) {BMS_STATE, INT, "BMS_STATE", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[TS_PRECHARGING_STATE] = (Indicator_Value) {TS_PRECHARGING_STATE, INT, "TS_PRE_ST", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[ACC_TS_CURRENT] = (Indicator_Value) {ACC_TS_CURRENT, FLOAT, "ACC_TS_CURR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[BMS_MAX_HUMIDITY] = (Indicator_Value) {BMS_MAX_HUMIDITY, INT, "BMS_MAX_HUM", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[BMS_12V_SENSE] = (Indicator_Value) {BMS_12V_SENSE, FLOAT, "BMS_12V", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[CURR_LIM_MAX_INPUT_CURRENT] = (Indicator_Value) {CURR_LIM_MAX_INPUT_CURRENT, FLOAT, "CURR_LIM_IN", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[CURR_LIM_MAX_OUTPUT_CURRENT] = (Indicator_Value) {CURR_LIM_MAX_OUTPUT_CURRENT,FLOAT , "CURR_LIM_O", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[MAX_CELL_TEMP] = (Indicator_Value) {MAX_CELL_TEMP, FLOAT, "MAX_CELL_T", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[MIN_CELL_TEMP] = (Indicator_Value) {MIN_CELL_TEMP, FLOAT, "MIN_CELL_T", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[DCU_BOARD] = (Indicator_Value) {DCU_BOARD, FLOAT, "DCU", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[DAU_FRONT_BOARD] = (Indicator_Value) {DAU_FRONT_BOARD, FLOAT, "DAU_FRONT", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[DAU_REAR_BOARD] = (Indicator_Value) {DAU_REAR_BOARD, FLOAT, "DAU_REAR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[IMU_FRONT_BOARD] = (Indicator_Value) {IMU_FRONT_BOARD, FLOAT, "IMU_FRONT", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[IMU_REAR_BOARD] = (Indicator_Value) {IMU_REAR_BOARD, FLOAT, "IMU_REAR", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[VCU_BOARD] = (Indicator_Value) {VCU_BOARD, FLOAT, "VCU", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[SW_BOARD] = (Indicator_Value) {SW_BOARD, FLOAT, "SW", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[BMS_MASTER_BOARD] = (Indicator_Value) {BMS_MASTER_BOARD, FLOAT, "BMS_MASTER", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[BMS_SLAVE_1_BOARD] = (Indicator_Value) {BMS_SLAVE_1_BOARD, FLOAT, "BMS_SLAVE_1", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[BMS_SLAVE_2_BOARD] = (Indicator_Value) {BMS_SLAVE_2_BOARD, FLOAT, "BMS_SLAVE_2", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[BMS_SLAVE_3_BOARD] = (Indicator_Value) {BMS_SLAVE_3_BOARD, FLOAT, "BMS_SLAVE_3", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[BMS_SLAVE_4_BOARD] = (Indicator_Value) {BMS_SLAVE_4_BOARD, FLOAT, "BMS_SLAVE_4", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[BMS_SLAVE_5_BOARD] = (Indicator_Value) {BMS_SLAVE_5_BOARD, FLOAT, "BMS_SLAVE_5", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		Indicators[BMS_SLAVE_6_BOARD] = (Indicator_Value) {BMS_SLAVE_6_BOARD, FLOAT, "BMS_SLAVE_6", DEF_VALUE, DEF_VALUE, DEF_VALUE, "?"};
		
		targetKalman = I2C_get_Kalman();
}

void data_simMode_init(void)
{
	Indicators[REGEN].intValore = STOP_REGEN;
	Indicators[TS].intValore = TS_OFF;
	Indicators[ACQ].intValore = ACQ_OFF;
	Indicators[BMS_STATE].intValore = ACQ_OFF;
}
