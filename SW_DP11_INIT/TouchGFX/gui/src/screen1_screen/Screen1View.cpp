#include <gui/screen1_screen/Screen1View.hpp>


extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];
int count = 0;

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{

}

void Screen1View::refreshScreen1()
{
	count ++;
	if( count >= 100)
		Screen1View::checkChangeScreen();
}

void Screen1View::checkChangeScreen()
{
	switch ( Indicators[DRIVE_MODE].intValore ){
				case SETTINGS_MODE	:
					application().gotoSETTINGSScreenNoTransition();
					break;
				case BOARD_DEBUG_MODE	:
					application().gotoBOARD_DEBUGScreenNoTransition();
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
