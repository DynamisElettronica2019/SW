#include <gui/board_debug_screen/BOARD_DEBUGView.hpp>

extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];
extern int board_debug_scroll;

BOARD_DEBUGView::BOARD_DEBUGView()
{

}

void BOARD_DEBUGView::setupScreen()
{
		board_debug_scroll = 1;		// parte da 1 perchè è riferito all'indicatore al centro
    BOARD_DEBUGViewBase::setupScreen();
}

void BOARD_DEBUGView::tearDownScreen()
{
    BOARD_DEBUGViewBase::tearDownScreen();
}

void BOARD_DEBUGView::refreshBoardDebug()
{
	BOARD_DEBUGView::checkChangeScreen();

	if (board_debug_scroll == START_BOARD){	//-------- da sistemare logica
		pointer1 = END_BOARD;
		pointer2 = board_debug_scroll;
		pointer3 = board_debug_scroll + 1;
		pointer4 = board_debug_scroll + 2;
		pointer5 = board_debug_scroll + 3;
	}
	else 
		if (board_debug_scroll == END_BOARD){	//-------- da sistemare logica
			pointer1 = board_debug_scroll - 1;
			pointer2 = board_debug_scroll;
			pointer3 = START_BOARD;
		}
		else {
			pointer1 = board_debug_scroll - 1;
			pointer2 = board_debug_scroll;
			pointer3 = board_debug_scroll + 1;
			pointer4 = board_debug_scroll + 2;
			pointer5 = board_debug_scroll + 3;
		}
		
	touchgfx::Unicode::strncpy( Title1, Indicators[pointer1].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title2, Indicators[pointer2].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title3, Indicators[pointer3].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title4, Indicators[pointer4].NOME, TIT_LEN);
	touchgfx::Unicode::strncpy( Title5, Indicators[pointer5].NOME, TIT_LEN);
		
		//-------------- DA VALUTARE COME INSERIRE TEMPERATURA E CORRENTE E STAMPARLI NEGLI APPOSITI SPAZI ------------------
		
	Unicode::snprintf(textIndTitle1Buffer, TEXTINDTITLE1_SIZE, "%s", Title1);	
	Unicode::snprintf(textIndTitle2Buffer, TEXTINDTITLE2_SIZE, "%s", Title2);	
	Unicode::snprintf(textIndTitle3Buffer, TEXTINDTITLE3_SIZE, "%s", Title3);
	Unicode::snprintf(textIndTitle4Buffer, TEXTINDTITLE4_SIZE, "%s", Title2);	
	Unicode::snprintf(textIndTitle5Buffer, TEXTINDTITLE5_SIZE, "%s", Title3);
		
	textIndTitle1.invalidate();
	textIndTitle2.invalidate();
	textIndTitle3.invalidate();
	textIndTitle4.invalidate();
	textIndTitle5.invalidate();
		
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
