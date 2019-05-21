#include <gui/board_debug_screen/BOARD_DEBUGView.hpp>

extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];
extern int board_debug_scroll;

BOARD_DEBUGView::BOARD_DEBUGView()
{

}

void BOARD_DEBUGView::setupScreen()
{
		board_debug_scroll = START_BOARD;		// parte da 1 perchè è riferito all'indicatore al centro
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
	
	touchgfx::Unicode::strncpy( Title1, Indicators[pointer1].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title2, Indicators[pointer2].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title3, Indicators[pointer3].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title4, Indicators[pointer4].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title5, Indicators[pointer5].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title6, Indicators[pointer6].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title7, Indicators[pointer7].NOME, TIT_LEN);
	
		//-------------- DA VALUTARE COME INSERIRE TEMPERATURA E CORRENTE E STAMPARLI NEGLI APPOSITI SPAZI ------------------
	
	Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%d", Indicators[pointer1].intValore);	
	Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%d", Indicators[pointer1].intValore2);
	Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%d", Indicators[pointer2].intValore);	
	Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%d", Indicators[pointer2].intValore2);
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
		
	Unicode::snprintf(textIndTitle1Buffer, TEXTINDTITLE1_SIZE, "%s", Title1);	
	Unicode::snprintf(textIndTitle2Buffer, TEXTINDTITLE2_SIZE, "%s", Title2);	
	Unicode::snprintf(textIndTitle3Buffer, TEXTINDTITLE3_SIZE, "%s", Title3);
	Unicode::snprintf(textIndTitle4Buffer, TEXTINDTITLE4_SIZE, "%s", Title4);	
	Unicode::snprintf(textIndTitle5Buffer, TEXTINDTITLE5_SIZE, "%s", Title5);
	Unicode::snprintf(textIndTitle6Buffer, TEXTINDTITLE6_SIZE, "%s", Title6);	
	Unicode::snprintf(textIndTitle7Buffer, TEXTINDTITLE7_SIZE, "%s", Title7);
		
	textIndTitle1.invalidate();
	textIndTitle2.invalidate();
	textIndTitle3.invalidate();
	textIndTitle4.invalidate();
	textIndTitle5.invalidate();
	textIndTitle6.invalidate();
	textIndTitle7.invalidate();
		
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
