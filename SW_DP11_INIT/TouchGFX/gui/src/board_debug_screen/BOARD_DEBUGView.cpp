#include <gui/board_debug_screen/BOARD_DEBUGView.hpp>

extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];
extern int board_debug_scroll;

BOARD_DEBUGView::BOARD_DEBUGView()
{

}

void BOARD_DEBUGView::setupScreen()
{
		touchgfx::Unicode::strncpy( Empty, DEF_SIMBOL, TIT_LEN);
		touchgfx::Unicode::strncpy( notDef, NOT_DEF_SIMBOL, TIT_LEN);
		touchgfx::Unicode::strncpy( unit_A, "A", TIT_LEN);
		touchgfx::Unicode::strncpy( unit_mA, "mA", TIT_LEN);
		touchgfx::Unicode::strncpy( unit_C, "°C", TIT_LEN);
		touchgfx::Unicode::strncpy( unit_rps, "rad/s", TIT_LEN);
		touchgfx::Unicode::strncpy( unit_msq, "m/s^2", TIT_LEN);
		touchgfx::Unicode::strncpy( unit_degree, "°", TIT_LEN);
		board_debug_scroll = START_BOARD_DEBUG;		// parte da 1 perchè è riferito all'indicatore al centro
    BOARD_DEBUGViewBase::setupScreen();
}

void BOARD_DEBUGView::tearDownScreen()
{
    BOARD_DEBUGViewBase::tearDownScreen();
}

void BOARD_DEBUGView::refreshBoardDebug()
{
	BOARD_DEBUGView::checkChangeScreen();

	pointer1 = board_debug_scroll;
	pointer2 = board_debug_scroll + 1;
	pointer3 = board_debug_scroll + 2;
	pointer4 = board_debug_scroll + 3;
	pointer5 = board_debug_scroll + 4;
	pointer6 = board_debug_scroll + 5;
	pointer7 = board_debug_scroll + 6;
	pointer8 = board_debug_scroll + 7;
	
	touchgfx::Unicode::strncpy( Title1, Indicators[pointer1].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title2, Indicators[pointer2].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title3, Indicators[pointer3].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title4, Indicators[pointer4].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title5, Indicators[pointer5].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title6, Indicators[pointer6].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title7, Indicators[pointer7].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title8, Indicators[pointer8].NOME, TIT_LEN);
	

	if(pointer1>=START_BOARD_DEBUG && pointer1<=END_BOARDS){
		if(Indicators[pointer1].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%d", Indicators[pointer1].intValore);	
		if(Indicators[pointer1].intValore2 == DEF_VALUE)
			Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%d", Indicators[pointer1].intValore2);
		Unicode::snprintf(textIndUnitSx_1Buffer, TEXTINDUNITSX_1_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_1Buffer, TEXTINDUNITDX_1_SIZE, "%s",unit_C);	
	}else if(pointer1>=START_CURRENTS_ONLY_A && pointer1<=END_CURRENTS_ONLY_A){
		if(Indicators[pointer1].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%.2f", Indicators[pointer1].floatValore);
		Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_1Buffer, TEXTINDUNITSX_1_SIZE, "%s",unit_A);	
		Unicode::snprintf(textIndUnitDx_1Buffer, TEXTINDUNITDX_1_SIZE, "%s",notDef);	
	}else if(pointer1>=START_CURRENTS_ONLY_MA && pointer1<=END_CURRENTS_ONLY_MA){
		if(Indicators[pointer1].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%d", Indicators[pointer1].intValore);	
		Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_1Buffer, TEXTINDUNITSX_1_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_1Buffer, TEXTINDUNITDX_1_SIZE, "%s",notDef);	
	}else if(pointer1>=START_IMU_ACC && pointer1<=END_IMU_ACC){
		if(Indicators[pointer1].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%.2f", Indicators[pointer1].floatValore);	
		Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_1Buffer, TEXTINDUNITSX_1_SIZE, "%s",unit_msq);	
		Unicode::snprintf(textIndUnitDx_1Buffer, TEXTINDUNITDX_1_SIZE, "%s",notDef);	
	}else if(pointer1>=START_IMU_GYR && pointer1<=END_IMU_GYR){
		if(Indicators[pointer1].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%.2f", Indicators[pointer1].floatValore);	
		Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_1Buffer, TEXTINDUNITSX_1_SIZE, "%s",unit_rps);	
		Unicode::snprintf(textIndUnitDx_1Buffer, TEXTINDUNITDX_1_SIZE, "%s",notDef);	
	}else if(pointer1>=START_IMU_HEAD && pointer1<=END_IMU_HEAD){
		if(Indicators[pointer1].floatValore == DEF_VALUE)	
			Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%.2f", Indicators[pointer1].floatValore);	
		Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_1Buffer, TEXTINDUNITSX_1_SIZE, "%s",unit_degree);	
		Unicode::snprintf(textIndUnitDx_1Buffer, TEXTINDUNITDX_1_SIZE, "%s",notDef);	
	}
	
	if(pointer2>=START_BOARD_DEBUG && pointer2<=END_BOARDS){
		if(Indicators[pointer2].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%d", Indicators[pointer2].intValore);	
		if(Indicators[pointer2].intValore2 == DEF_VALUE)
			Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%d", Indicators[pointer2].intValore2);
		Unicode::snprintf(textIndUnitSx_2Buffer, TEXTINDUNITSX_2_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_2Buffer, TEXTINDUNITDX_2_SIZE, "%s",unit_C);	
	}else if(pointer2>=START_CURRENTS_ONLY_A && pointer2<=END_CURRENTS_ONLY_A){
		if(Indicators[pointer2].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%.2f", Indicators[pointer2].floatValore);
		Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_2Buffer, TEXTINDUNITSX_2_SIZE, "%s",unit_A);	
		Unicode::snprintf(textIndUnitDx_2Buffer, TEXTINDUNITDX_2_SIZE, "%s",notDef);	
	}else if(pointer2>=START_CURRENTS_ONLY_MA && pointer2<=END_CURRENTS_ONLY_MA){
		if(Indicators[pointer2].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%d", Indicators[pointer2].intValore);	
		Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_2Buffer, TEXTINDUNITSX_2_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_2Buffer, TEXTINDUNITDX_2_SIZE, "%s",notDef);	
	}else if(pointer2>=START_IMU_ACC && pointer2<=END_IMU_ACC){
		if(Indicators[pointer2].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%.2f", Indicators[pointer2].floatValore);	
		Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_2Buffer, TEXTINDUNITSX_2_SIZE, "%s",unit_msq);	
		Unicode::snprintf(textIndUnitDx_2Buffer, TEXTINDUNITDX_2_SIZE, "%s",notDef);	
	}else if(pointer2>=START_IMU_GYR && pointer2<=END_IMU_GYR){
		if(Indicators[pointer2].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%.2f", Indicators[pointer2].floatValore);	
		Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_2Buffer, TEXTINDUNITSX_2_SIZE, "%s",unit_rps);	
		Unicode::snprintf(textIndUnitDx_2Buffer, TEXTINDUNITDX_2_SIZE, "%s",notDef);	
	}else if(pointer2>=START_IMU_HEAD && pointer2<=END_IMU_HEAD){
		if(Indicators[pointer2].floatValore == DEF_VALUE)	
			Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%.2f", Indicators[pointer2].floatValore);	
		Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_2Buffer, TEXTINDUNITSX_2_SIZE, "%s",unit_degree);	
		Unicode::snprintf(textIndUnitDx_2Buffer, TEXTINDUNITDX_2_SIZE, "%s",notDef);	
	}
	
	if(pointer3>=START_BOARD_DEBUG && pointer3<=END_BOARDS){
		if(Indicators[pointer3].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%d", Indicators[pointer3].intValore);	
		if(Indicators[pointer3].intValore2 == DEF_VALUE)
			Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%d", Indicators[pointer3].intValore2);
		Unicode::snprintf(textIndUnitSx_3Buffer, TEXTINDUNITSX_3_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_3Buffer, TEXTINDUNITDX_3_SIZE, "%s",unit_C);	
	}else if(pointer3>=START_CURRENTS_ONLY_A && pointer3<=END_CURRENTS_ONLY_A){
		if(Indicators[pointer3].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%.2f", Indicators[pointer3].floatValore);
		Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_3Buffer, TEXTINDUNITSX_3_SIZE, "%s",unit_A);	
		Unicode::snprintf(textIndUnitDx_3Buffer, TEXTINDUNITDX_3_SIZE, "%s",notDef);	
	}else if(pointer3>=START_CURRENTS_ONLY_MA && pointer3<=END_CURRENTS_ONLY_MA){
		if(Indicators[pointer3].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%d", Indicators[pointer3].intValore);	
		Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_3Buffer, TEXTINDUNITSX_3_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_3Buffer, TEXTINDUNITDX_3_SIZE, "%s",notDef);	
	}else if(pointer3>=START_IMU_ACC && pointer3<=END_IMU_ACC){
		if(Indicators[pointer3].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%.2f", Indicators[pointer3].floatValore);	
		Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_3Buffer, TEXTINDUNITSX_3_SIZE, "%s",unit_msq);	
		Unicode::snprintf(textIndUnitDx_3Buffer, TEXTINDUNITDX_3_SIZE, "%s",notDef);	
	}else if(pointer3>=START_IMU_GYR && pointer3<=END_IMU_GYR){
		if(Indicators[pointer3].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%.2f", Indicators[pointer3].floatValore);	
		Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_3Buffer, TEXTINDUNITSX_3_SIZE, "%s",unit_rps);	
		Unicode::snprintf(textIndUnitDx_3Buffer, TEXTINDUNITDX_3_SIZE, "%s",notDef);	
	}else if(pointer3>=START_IMU_HEAD && pointer3<=END_IMU_HEAD){
		if(Indicators[pointer3].floatValore == DEF_VALUE)	
			Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%.2f", Indicators[pointer3].floatValore);	
		Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_3Buffer, TEXTINDUNITSX_3_SIZE, "%s",unit_degree);	
		Unicode::snprintf(textIndUnitDx_3Buffer, TEXTINDUNITDX_3_SIZE, "%s",notDef);	
	}
	
	if(pointer4>=START_BOARD_DEBUG && pointer4<=END_BOARDS){
		if(Indicators[pointer4].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%d", Indicators[pointer4].intValore);	
		if(Indicators[pointer4].intValore2 == DEF_VALUE)
			Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%d", Indicators[pointer4].intValore2);
		Unicode::snprintf(textIndUnitSx_4Buffer, TEXTINDUNITSX_4_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_4Buffer, TEXTINDUNITDX_4_SIZE, "%s",unit_C);	
	}else if(pointer4>=START_CURRENTS_ONLY_A && pointer4<=END_CURRENTS_ONLY_A){
		if(Indicators[pointer4].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%.2f", Indicators[pointer4].floatValore);
		Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_4Buffer, TEXTINDUNITSX_4_SIZE, "%s",unit_A);	
		Unicode::snprintf(textIndUnitDx_4Buffer, TEXTINDUNITDX_4_SIZE, "%s",notDef);	
	}else if(pointer4>=START_CURRENTS_ONLY_MA && pointer4<=END_CURRENTS_ONLY_MA){
		if(Indicators[pointer4].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%d", Indicators[pointer4].intValore);	
		Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_4Buffer, TEXTINDUNITSX_4_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_4Buffer, TEXTINDUNITDX_4_SIZE, "%s",notDef);	
	}else if(pointer4>=START_IMU_ACC && pointer4<=END_IMU_ACC){
		if(Indicators[pointer4].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%.2f", Indicators[pointer4].floatValore);	
		Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_4Buffer, TEXTINDUNITSX_4_SIZE, "%s",unit_msq);	
		Unicode::snprintf(textIndUnitDx_4Buffer, TEXTINDUNITDX_4_SIZE, "%s",notDef);	
	}else if(pointer4>=START_IMU_GYR && pointer4<=END_IMU_GYR){
		if(Indicators[pointer4].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%.2f", Indicators[pointer4].floatValore);	
		Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_4Buffer, TEXTINDUNITSX_4_SIZE, "%s",unit_rps);	
		Unicode::snprintf(textIndUnitDx_4Buffer, TEXTINDUNITDX_4_SIZE, "%s",notDef);	
	}else if(pointer4>=START_IMU_HEAD && pointer4<=END_IMU_HEAD){
		if(Indicators[pointer4].floatValore == DEF_VALUE)	
			Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%.2f", Indicators[pointer4].floatValore);	
		Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_4Buffer, TEXTINDUNITSX_4_SIZE, "%s",unit_degree);	
		Unicode::snprintf(textIndUnitDx_4Buffer, TEXTINDUNITDX_4_SIZE, "%s",notDef);	
	}
	
	if(pointer5>=START_BOARD_DEBUG && pointer5<=END_BOARDS){
		if(Indicators[pointer5].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%d", Indicators[pointer5].intValore);	
		if(Indicators[pointer5].intValore2 == DEF_VALUE)
			Unicode::snprintf(textIndValueCurr5Buffer, TEXTINDVALUECURR5_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueCurr5Buffer, TEXTINDVALUECURR5_SIZE, "%d", Indicators[pointer5].intValore2);
		Unicode::snprintf(textIndUnitSx_5Buffer, TEXTINDUNITSX_5_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_5Buffer, TEXTINDUNITDX_5_SIZE, "%s",unit_C);	
	}else if(pointer5>=START_CURRENTS_ONLY_A && pointer5<=END_CURRENTS_ONLY_A){
		if(Indicators[pointer5].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%.2f", Indicators[pointer5].floatValore);
		Unicode::snprintf(textIndValueCurr5Buffer, TEXTINDVALUECURR5_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_5Buffer, TEXTINDUNITSX_5_SIZE, "%s",unit_A);	
		Unicode::snprintf(textIndUnitDx_5Buffer, TEXTINDUNITDX_5_SIZE, "%s",notDef);	
	}else if(pointer5>=START_CURRENTS_ONLY_MA && pointer5<=END_CURRENTS_ONLY_MA){
		if(Indicators[pointer5].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%d", Indicators[pointer5].intValore);	
		Unicode::snprintf(textIndValueCurr5Buffer, TEXTINDVALUECURR5_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_5Buffer, TEXTINDUNITSX_5_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_5Buffer, TEXTINDUNITDX_5_SIZE, "%s",notDef);	
	}else if(pointer5>=START_IMU_ACC && pointer5<=END_IMU_ACC){
		if(Indicators[pointer5].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%.2f", Indicators[pointer5].floatValore);	
		Unicode::snprintf(textIndValueCurr5Buffer, TEXTINDVALUECURR5_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_5Buffer, TEXTINDUNITSX_5_SIZE, "%s",unit_msq);	
		Unicode::snprintf(textIndUnitDx_5Buffer, TEXTINDUNITDX_5_SIZE, "%s",notDef);	
	}else if(pointer5>=START_IMU_GYR && pointer5<=END_IMU_GYR){
		if(Indicators[pointer5].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%.2f", Indicators[pointer5].floatValore);	
		Unicode::snprintf(textIndValueCurr5Buffer, TEXTINDVALUECURR5_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_5Buffer, TEXTINDUNITSX_5_SIZE, "%s",unit_rps);	
		Unicode::snprintf(textIndUnitDx_5Buffer, TEXTINDUNITDX_5_SIZE, "%s",notDef);	
	}else if(pointer5>=START_IMU_HEAD && pointer5<=END_IMU_HEAD){
		if(Indicators[pointer5].floatValore == DEF_VALUE)	
			Unicode::snprintf(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%.2f", Indicators[pointer5].floatValore);	
		Unicode::snprintf(textIndValueCurr5Buffer, TEXTINDVALUECURR5_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_5Buffer, TEXTINDUNITSX_5_SIZE, "%s",unit_degree);	
		Unicode::snprintf(textIndUnitDx_5Buffer, TEXTINDUNITDX_5_SIZE, "%s",notDef);	
	}
	
	if(pointer6>=START_BOARD_DEBUG && pointer6<=END_BOARDS){
		if(Indicators[pointer6].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%d", Indicators[pointer6].intValore);	
		if(Indicators[pointer6].intValore2 == DEF_VALUE)
			Unicode::snprintf(textIndValueCurr6Buffer, TEXTINDVALUECURR6_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueCurr6Buffer, TEXTINDVALUECURR6_SIZE, "%d", Indicators[pointer6].intValore2);
		Unicode::snprintf(textIndUnitSx_6Buffer, TEXTINDUNITSX_6_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_6Buffer, TEXTINDUNITDX_6_SIZE, "%s",unit_C);	
	}else if(pointer6>=START_CURRENTS_ONLY_A && pointer6<=END_CURRENTS_ONLY_A){
		if(Indicators[pointer6].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%.2f", Indicators[pointer6].floatValore);
		Unicode::snprintf(textIndValueCurr6Buffer, TEXTINDVALUECURR6_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_6Buffer, TEXTINDUNITSX_6_SIZE, "%s",unit_A);	
		Unicode::snprintf(textIndUnitDx_6Buffer, TEXTINDUNITDX_6_SIZE, "%s",notDef);	
	}else if(pointer6>=START_CURRENTS_ONLY_MA && pointer6<=END_CURRENTS_ONLY_MA){
		if(Indicators[pointer6].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%d", Indicators[pointer6].intValore);	
		Unicode::snprintf(textIndValueCurr6Buffer, TEXTINDVALUECURR6_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_6Buffer, TEXTINDUNITSX_6_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_6Buffer, TEXTINDUNITDX_6_SIZE, "%s",notDef);	
	}else if(pointer6>=START_IMU_ACC && pointer6<=END_IMU_ACC){
		if(Indicators[pointer6].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%.2f", Indicators[pointer6].floatValore);	
		Unicode::snprintf(textIndValueCurr6Buffer, TEXTINDVALUECURR6_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_6Buffer, TEXTINDUNITSX_6_SIZE, "%s",unit_msq);	
		Unicode::snprintf(textIndUnitDx_6Buffer, TEXTINDUNITDX_6_SIZE, "%s",notDef);	
	}else if(pointer6>=START_IMU_GYR && pointer6<=END_IMU_GYR){
		if(Indicators[pointer6].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%.2f", Indicators[pointer6].floatValore);	
		Unicode::snprintf(textIndValueCurr6Buffer, TEXTINDVALUECURR6_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_6Buffer, TEXTINDUNITSX_6_SIZE, "%s",unit_rps);	
		Unicode::snprintf(textIndUnitDx_6Buffer, TEXTINDUNITDX_6_SIZE, "%s",notDef);	
	}else if(pointer6>=START_IMU_HEAD && pointer6<=END_IMU_HEAD){
		if(Indicators[pointer6].floatValore == DEF_VALUE)	
			Unicode::snprintf(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%.2f", Indicators[pointer6].floatValore);	
		Unicode::snprintf(textIndValueCurr6Buffer, TEXTINDVALUECURR6_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_6Buffer, TEXTINDUNITSX_6_SIZE, "%s",unit_degree);	
		Unicode::snprintf(textIndUnitDx_6Buffer, TEXTINDUNITDX_6_SIZE, "%s",notDef);	
	}
	
	if(pointer7>=START_BOARD_DEBUG && pointer7<=END_BOARDS){
		if(Indicators[pointer7].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%d", Indicators[pointer7].intValore);	
		if(Indicators[pointer7].intValore2 == DEF_VALUE)
			Unicode::snprintf(textIndValueCurr7Buffer, TEXTINDVALUECURR7_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueCurr7Buffer, TEXTINDVALUECURR7_SIZE, "%d", Indicators[pointer7].intValore2);
		Unicode::snprintf(textIndUnitSx_7Buffer, TEXTINDUNITSX_7_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_7Buffer, TEXTINDUNITDX_7_SIZE, "%s",unit_C);	
	}else if(pointer7>=START_CURRENTS_ONLY_A && pointer7<=END_CURRENTS_ONLY_A){
		if(Indicators[pointer7].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%.2f", Indicators[pointer7].floatValore);
		Unicode::snprintf(textIndValueCurr7Buffer, TEXTINDVALUECURR7_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_7Buffer, TEXTINDUNITSX_7_SIZE, "%s",unit_A);	
		Unicode::snprintf(textIndUnitDx_7Buffer, TEXTINDUNITDX_7_SIZE, "%s",notDef);	
	}else if(pointer7>=START_CURRENTS_ONLY_MA && pointer7<=END_CURRENTS_ONLY_MA){
		if(Indicators[pointer7].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%d", Indicators[pointer7].intValore);	
		Unicode::snprintf(textIndValueCurr7Buffer, TEXTINDVALUECURR7_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_7Buffer, TEXTINDUNITSX_7_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_7Buffer, TEXTINDUNITDX_7_SIZE, "%s",notDef);	
	}else if(pointer7>=START_IMU_ACC && pointer7<=END_IMU_ACC){
		if(Indicators[pointer7].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%.2f", Indicators[pointer7].floatValore);	
		Unicode::snprintf(textIndValueCurr7Buffer, TEXTINDVALUECURR7_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_7Buffer, TEXTINDUNITSX_7_SIZE, "%s",unit_msq);	
		Unicode::snprintf(textIndUnitDx_7Buffer, TEXTINDUNITDX_7_SIZE, "%s",notDef);	
	}else if(pointer7>=START_IMU_GYR && pointer7<=END_IMU_GYR){
		if(Indicators[pointer7].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%.2f", Indicators[pointer7].floatValore);	
		Unicode::snprintf(textIndValueCurr7Buffer, TEXTINDVALUECURR7_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_7Buffer, TEXTINDUNITSX_7_SIZE, "%s",unit_rps);	
		Unicode::snprintf(textIndUnitDx_7Buffer, TEXTINDUNITDX_7_SIZE, "%s",notDef);	
	}else if(pointer7>=START_IMU_HEAD && pointer7<=END_IMU_HEAD){
		if(Indicators[pointer7].floatValore == DEF_VALUE)	
			Unicode::snprintf(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%.2f", Indicators[pointer7].floatValore);	
		Unicode::snprintf(textIndValueCurr7Buffer, TEXTINDVALUECURR7_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_7Buffer, TEXTINDUNITSX_7_SIZE, "%s",unit_degree);	
		Unicode::snprintf(textIndUnitDx_7Buffer, TEXTINDUNITDX_7_SIZE, "%s",notDef);	
	}
	
	if(pointer8>=START_BOARD_DEBUG && pointer8<=END_BOARDS){
		if(Indicators[pointer8].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%d", Indicators[pointer8].intValore);	
		if(Indicators[pointer8].intValore2 == DEF_VALUE)
			Unicode::snprintf(textIndValueCurr8Buffer, TEXTINDVALUECURR8_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueCurr8Buffer, TEXTINDVALUECURR8_SIZE, "%d", Indicators[pointer8].intValore2);
		Unicode::snprintf(textIndUnitSx_8Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_8Buffer, TEXTINDUNITDX_8_SIZE, "%s",unit_C);	
	}else if(pointer8>=START_CURRENTS_ONLY_A && pointer8<=END_CURRENTS_ONLY_A){
		if(Indicators[pointer8].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%.2f", Indicators[pointer8].floatValore);
		Unicode::snprintf(textIndValueCurr8Buffer, TEXTINDVALUECURR8_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_8Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_A);	
		Unicode::snprintf(textIndUnitDx_8Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer8>=START_CURRENTS_ONLY_MA && pointer8<=END_CURRENTS_ONLY_MA){
		if(Indicators[pointer8].intValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%s", Empty);
		else
			Unicode::snprintf(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%d", Indicators[pointer8].intValore);	
		Unicode::snprintf(textIndValueCurr8Buffer, TEXTINDVALUECURR8_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_8Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_8Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer8>=START_IMU_ACC && pointer8<=END_IMU_ACC){
		if(Indicators[pointer8].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%.2f", Indicators[pointer8].floatValore);	
		Unicode::snprintf(textIndValueCurr8Buffer, TEXTINDVALUECURR8_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_8Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_msq);	
		Unicode::snprintf(textIndUnitDx_8Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer8>=START_IMU_GYR && pointer8<=END_IMU_GYR){
		if(Indicators[pointer8].floatValore == DEF_VALUE)
			Unicode::snprintf(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%.2f", Indicators[pointer8].floatValore);	
		Unicode::snprintf(textIndValueCurr8Buffer, TEXTINDVALUECURR8_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_8Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_rps);	
		Unicode::snprintf(textIndUnitDx_8Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer8>=START_IMU_HEAD && pointer8<=END_IMU_HEAD){
		if(Indicators[pointer8].floatValore == DEF_VALUE)	
			Unicode::snprintf(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%s", Empty);
		else
			Unicode::snprintfFloat(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%.2f", Indicators[pointer8].floatValore);	
		Unicode::snprintf(textIndValueCurr8Buffer, TEXTINDVALUECURR8_SIZE, "%s",notDef);
		Unicode::snprintf(textIndUnitSx_8Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_degree);	
		Unicode::snprintf(textIndUnitDx_8Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}	

	
	Unicode::snprintf(textIndTitle1Buffer, TEXTINDTITLE1_SIZE, "%s", Title1);	
	Unicode::snprintf(textIndTitle2Buffer, TEXTINDTITLE2_SIZE, "%s", Title2);	
	Unicode::snprintf(textIndTitle3Buffer, TEXTINDTITLE3_SIZE, "%s", Title3);
	Unicode::snprintf(textIndTitle4Buffer, TEXTINDTITLE4_SIZE, "%s", Title4);	
	Unicode::snprintf(textIndTitle5Buffer, TEXTINDTITLE5_SIZE, "%s", Title5);
	Unicode::snprintf(textIndTitle6Buffer, TEXTINDTITLE6_SIZE, "%s", Title6);	
	Unicode::snprintf(textIndTitle7Buffer, TEXTINDTITLE7_SIZE, "%s", Title7);
	Unicode::snprintf(textIndTitle8Buffer, TEXTINDTITLE8_SIZE, "%s", Title8);
	
	boxIndCurrent.invalidate();	
		
	textIndTitle1.invalidate();
	textIndTitle2.invalidate();
	textIndTitle3.invalidate();
	textIndTitle4.invalidate();
	textIndTitle5.invalidate();
	textIndTitle6.invalidate();
	textIndTitle7.invalidate();
	textIndTitle8.invalidate();
		
	textIndValueTemp1.invalidate();
	textIndValueCurr1.invalidate();		
	textIndValueTemp2.invalidate();
	textIndValueCurr2.invalidate();		
	textIndValueTemp3.invalidate();
	textIndValueCurr3.invalidate();		
	textIndValueTemp4.invalidate();
	textIndValueCurr4.invalidate();		
	textIndValueTemp5.invalidate();
	textIndValueCurr5.invalidate();		
	textIndValueTemp6.invalidate();
	textIndValueCurr6.invalidate();		
	textIndValueTemp7.invalidate();
	textIndValueCurr7.invalidate();		
	textIndValueTemp8.invalidate();
	textIndValueCurr8.invalidate();		
	
	textIndUnitSx_1.invalidate();
	textIndUnitSx_2.invalidate();
	textIndUnitSx_3.invalidate();
	textIndUnitSx_4.invalidate();
	textIndUnitSx_5.invalidate();
	textIndUnitSx_6.invalidate();
	textIndUnitSx_7.invalidate();
	textIndUnitSx_8.invalidate();

	textIndUnitDx_1.invalidate();
	textIndUnitDx_2.invalidate();
	textIndUnitDx_3.invalidate();
	textIndUnitDx_4.invalidate();
	textIndUnitDx_5.invalidate();
	textIndUnitDx_6.invalidate();
	textIndUnitDx_7.invalidate();
	textIndUnitDx_8.invalidate();
}

void BOARD_DEBUGView::checkChangeScreen()
{
	switch ( Indicators[DRIVE_MODE].intValore ){
				case SETTINGS_MODE	:
					application().gotoSETTINGSScreenNoTransition();
					break;
				case BOARD_DEBUG_MODE	:
					
					break;
				case DEBUG_MODE	:
					application().gotoDEBUG_MODEScreenNoTransition();
					break;
				case ENDURANCE_MODE	:
					application().gotoENDURANCEScreenNoTransition();
					break;
				case ACCELERATION_MODE	:
					application().gotoACCELERATIONScreenNoTransition();
					break;
				case AUTOX_MODE	:
					application().gotoAUTOCROSSScreenNoTransition();
					break;
				case SKIDPAD_MODE	:
					application().gotoSKIDPADScreenNoTransition();
					break;
				case NOISE_MODE	:
					application().gotoNOISE_MODEScreenNoTransition();
					break;
	}	
}
