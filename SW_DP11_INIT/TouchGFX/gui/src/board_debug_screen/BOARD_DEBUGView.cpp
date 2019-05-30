#include <gui/board_debug_screen/BOARD_DEBUGView.hpp>

extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];
extern int board_debug_scroll;

BOARD_DEBUGView::BOARD_DEBUGView()
{

}

void BOARD_DEBUGView::setupScreen()
{
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
	
		//-------------- DA VALUTARE COME INSERIRE TEMPERATURA E CORRENTE E STAMPARLI NEGLI APPOSITI SPAZI ------------------

	if(pointer1>=START_BOARD_DEBUG && pointer1<=END_BOARDS){
		Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%d", Indicators[pointer1].intValore);	
		Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%d", Indicators[pointer1].intValore2);
		Unicode::snprintf(textIndUnitSx_1Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_1Buffer, TEXTINDUNITDX_8_SIZE, "%s",unit_C);	
	}else if(pointer1>=START_CURRENTS_ONLY_A && pointer1<=END_CURRENTS_ONLY_A){
		Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%d", Indicators[pointer1].floatValore);	
		Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_1Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_A);	
		Unicode::snprintf(textIndUnitDx_1Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer1>=START_CURRENTS_ONLY_MA && pointer1<=END_CURRENTS_ONLY_MA){
		Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%d", Indicators[pointer1].intValore);	
		Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_1Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_1Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer1>=START_IMU_ACC && pointer1<=END_IMU_ACC){
		Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%d", Indicators[pointer1].floatValore);	
		Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_1Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_msq);	
		Unicode::snprintf(textIndUnitDx_1Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer1>=START_IMU_GYR && pointer1<=END_IMU_GYR){
		Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%d", Indicators[pointer1].floatValore);	
		Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_1Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_rps);	
		Unicode::snprintf(textIndUnitDx_1Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer1>=START_IMU_HEAD && pointer1<=END_IMU_HEAD){
		Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%d", Indicators[pointer1].floatValore);	
		Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_1Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_degree);	
		Unicode::snprintf(textIndUnitDx_1Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}
	
	if(pointer2>=START_BOARD_DEBUG && pointer2<=END_BOARDS){
		Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%d", Indicators[pointer2].intValore);	
		Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%d", Indicators[pointer2].intValore2);
		Unicode::snprintf(textIndUnitSx_2Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_2Buffer, TEXTINDUNITDX_8_SIZE, "%s",unit_C);	
	}else if(pointer2>=START_CURRENTS_ONLY_A && pointer2<=END_CURRENTS_ONLY_A){
		Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%d", Indicators[pointer2].floatValore);	
		Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_2Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_A);	
		Unicode::snprintf(textIndUnitDx_2Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer2>=START_CURRENTS_ONLY_MA && pointer2<=END_CURRENTS_ONLY_MA){
		Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%d", Indicators[pointer2].intValore);	
		Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_2Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_2Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer2>=START_IMU_ACC && pointer2<=END_IMU_ACC){
		Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%d", Indicators[pointer2].floatValore);	
		Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_2Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_msq);	
		Unicode::snprintf(textIndUnitDx_2Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer2>=START_IMU_GYR && pointer2<=END_IMU_GYR){
		Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%d", Indicators[pointer2].floatValore);	
		Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_2Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_rps);	
		Unicode::snprintf(textIndUnitDx_2Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer2>=START_IMU_HEAD && pointer2<=END_IMU_HEAD){
		Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%d", Indicators[pointer2].floatValore);	
		Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_2Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_degree);	
		Unicode::snprintf(textIndUnitDx_2Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}
	
	if(pointer3>=START_BOARD_DEBUG && pointer3<=END_BOARDS){
		Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%d", Indicators[pointer3].intValore);	
		Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%d", Indicators[pointer3].intValore2);
		Unicode::snprintf(textIndUnitSx_3Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_3Buffer, TEXTINDUNITDX_8_SIZE, "%s",unit_C);	
	}else if(pointer3>=START_CURRENTS_ONLY_A && pointer3<=END_CURRENTS_ONLY_A){
		Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%d", Indicators[pointer3].floatValore);	
		Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_3Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_A);	
		Unicode::snprintf(textIndUnitDx_3Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer3>=START_CURRENTS_ONLY_MA && pointer3<=END_CURRENTS_ONLY_MA){
		Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%d", Indicators[pointer3].intValore);	
		Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_3Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_3Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer3>=START_IMU_ACC && pointer3<=END_IMU_ACC){
		Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%d", Indicators[pointer3].floatValore);	
		Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_3Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_msq);	
		Unicode::snprintf(textIndUnitDx_3Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer3>=START_IMU_GYR && pointer3<=END_IMU_GYR){
		Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%d", Indicators[pointer3].floatValore);	
		Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_3Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_rps);	
		Unicode::snprintf(textIndUnitDx_3Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer3>=START_IMU_HEAD && pointer3<=END_IMU_HEAD){
		Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%d", Indicators[pointer3].floatValore);	
		Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_3Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_degree);	
		Unicode::snprintf(textIndUnitDx_3Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}
	
	if(pointer4>=START_BOARD_DEBUG && pointer4<=END_BOARDS){
		Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%d", Indicators[pointer4].intValore);	
		Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%d", Indicators[pointer4].intValore2);
		Unicode::snprintf(textIndUnitSx_4Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_4Buffer, TEXTINDUNITDX_8_SIZE, "%s",unit_C);	
	}else if(pointer4>=START_CURRENTS_ONLY_A && pointer4<=END_CURRENTS_ONLY_A){
		Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%d", Indicators[pointer4].floatValore);	
		Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_4Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_A);	
		Unicode::snprintf(textIndUnitDx_4Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer4>=START_CURRENTS_ONLY_MA && pointer4<=END_CURRENTS_ONLY_MA){
		Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%d", Indicators[pointer4].intValore);	
		Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_4Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_mA);	
		Unicode::snprintf(textIndUnitDx_4Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer4>=START_IMU_ACC && pointer4<=END_IMU_ACC){
		Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%d", Indicators[pointer4].floatValore);	
		Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_4Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_msq);	
		Unicode::snprintf(textIndUnitDx_4Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer4>=START_IMU_GYR && pointer4<=END_IMU_GYR){
		Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%d", Indicators[pointer4].floatValore);	
		Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_4Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_rps);	
		Unicode::snprintf(textIndUnitDx_4Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}else if(pointer4>=START_IMU_HEAD && pointer4<=END_IMU_HEAD){
		Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%d", Indicators[pointer4].floatValore);	
		Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%d",notDef);
		Unicode::snprintf(textIndUnitSx_4Buffer, TEXTINDUNITSX_8_SIZE, "%s",unit_degree);	
		Unicode::snprintf(textIndUnitDx_4Buffer, TEXTINDUNITDX_8_SIZE, "%s",notDef);	
	}
	
	Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%d", Indicators[pointer3].intValore);	
	Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%d", Indicators[pointer3].intValore2);
	Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%d", Indicators[pointer4].intValore);	
	Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%d", Indicators[pointer4].intValore2);
	Unicode::snprintf(textIndValueTemp5Buffer, TEXTINDVALUETEMP5_SIZE, "%d", Indicators[pointer5].intValore);	
	Unicode::snprintf(textIndValueCurr5Buffer, TEXTINDVALUECURR5_SIZE, "%d", Indicators[pointer5].intValore2);
	Unicode::snprintf(textIndValueTemp6Buffer, TEXTINDVALUETEMP6_SIZE, "%d", Indicators[pointer6].intValore);	
	Unicode::snprintf(textIndValueCurr6Buffer, TEXTINDVALUECURR6_SIZE, "%d", Indicators[pointer6].intValore2);
	Unicode::snprintf(textIndValueTemp7Buffer, TEXTINDVALUETEMP7_SIZE, "%d", Indicators[pointer7].intValore);	
	Unicode::snprintf(textIndValueCurr7Buffer, TEXTINDVALUECURR7_SIZE, "%d", Indicators[pointer7].intValore2);	
	Unicode::snprintf(textIndValueTemp8Buffer, TEXTINDVALUETEMP8_SIZE, "%d", Indicators[pointer8].intValore);	
	Unicode::snprintf(textIndValueCurr8Buffer, TEXTINDVALUECURR8_SIZE, "%d", Indicators[pointer8].intValore2);	
		
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
	}	
}
