#include <gui/debug_mode_screen/DEBUG_MODEView.hpp>

extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];

DEBUG_MODEView::DEBUG_MODEView()
{

}

void DEBUG_MODEView::setupScreen()
{
    DEBUG_MODEViewBase::setupScreen();
}

void DEBUG_MODEView::tearDownScreen()
{
    DEBUG_MODEViewBase::tearDownScreen();
}

void DEBUG_MODEView::refreshDebugMode()
{
    DEBUG_MODEView::checkChangeScreen();
}

void DEBUG_MODEView::checkChangeScreen()
{
	switch ( driveMode ){
				case SETTINGS_MODE	:
					application().gotoSETTINGSScreenNoTransition();
					break;
				case BOARD_DEBUG_MODE	:
					application().gotoBOARD_DEBUGScreenNoTransition();
					break;
				case DEBUG_MODE	:
					
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

