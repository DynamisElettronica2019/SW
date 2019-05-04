#include <gui/board_debug_screen/BOARD_DEBUGView.hpp>

extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];

BOARD_DEBUGView::BOARD_DEBUGView()
{

}

void BOARD_DEBUGView::setupScreen()
{
    BOARD_DEBUGViewBase::setupScreen();
}

void BOARD_DEBUGView::tearDownScreen()
{
    BOARD_DEBUGViewBase::tearDownScreen();
}

void BOARD_DEBUGView::refreshBoardDebug()
{
	BOARD_DEBUGView::checkChangeScreen();
	
}

void BOARD_DEBUGView::checkChangeScreen()
{
	switch ( driveMode ){
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
