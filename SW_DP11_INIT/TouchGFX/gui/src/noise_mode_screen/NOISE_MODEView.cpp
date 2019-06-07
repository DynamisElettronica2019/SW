#include <gui/noise_mode_screen/NOISE_MODEView.hpp>

extern int state;
extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];

int contBlink;

NOISE_MODEView::NOISE_MODEView()
{

}

void NOISE_MODEView::setupScreen()
{
		contBlink = 0;
		touchgfx::Unicode::strncpy( Empty, DEF_SIMBOL, TIT_LEN);
    NOISE_MODEViewBase::setupScreen();
}

void NOISE_MODEView::tearDownScreen()
{
    NOISE_MODEViewBase::tearDownScreen();
}

void NOISE_MODEView::refreshNoiseMode()
{
	NOISE_MODEView::checkChangeScreen();
	
	if (Indicators[MAP].intValore == 1 ){
		contBlink ++;
		if ( contBlink < 20 ){
			boxMapPopUp.setVisible(true);
			textMapPopUp.setVisible(true);
		}
		else{
		boxMapPopUp.setVisible(false);
		textMapPopUp.setVisible(false);
		}
		if ( contBlink > 40 ){
			contBlink = 0;
		}
	}
	else{
		boxMapPopUp.setVisible(false);
		textMapPopUp.setVisible(false);
	}
	boxMapPopUp.invalidate();
	textMapPopUp.invalidate();
	
	
	
	if (	Indicators[T_SCARICO_1].intValore == DEF_VALUE && Indicators[T_SCARICO_1].floatValore == DEF_VALUE )
		Unicode::snprintf(textTrmcValue1Buffer, TEXTTRMCVALUE1_SIZE, "%s", Empty);	
	else
		if ( Indicators[T_SCARICO_1].TIPO == INT )
			Unicode::snprintf(textTrmcValue1Buffer, TEXTTRMCVALUE1_SIZE, "%d", Indicators[T_SCARICO_1].intValore);
		else
			Unicode::snprintfFloat(textTrmcValue1Buffer, TEXTTRMCVALUE1_SIZE, "%.1f", Indicators[T_SCARICO_1].floatValore);
		
	if (	Indicators[T_SCARICO_2].intValore == DEF_VALUE && Indicators[T_SCARICO_2].floatValore == DEF_VALUE )
		Unicode::snprintf(textTrmcValue2Buffer, TEXTTRMCVALUE2_SIZE, "%s", Empty);	
	else
		if ( Indicators[T_SCARICO_2].TIPO == INT )
			Unicode::snprintf(textTrmcValue1Buffer, TEXTTRMCVALUE2_SIZE, "%d", Indicators[T_SCARICO_2].intValore);
		else
			Unicode::snprintfFloat(textTrmcValue2Buffer, TEXTTRMCVALUE2_SIZE, "%.1f", Indicators[T_SCARICO_2].floatValore);
		
	if (	Indicators[TPS].intValore == DEF_VALUE && Indicators[TPS].floatValore == DEF_VALUE )
		Unicode::snprintf(textTpsValueBuffer, TEXTTPSVALUE_SIZE, "%s", Empty);	
	else
		if ( Indicators[TPS].TIPO == INT )
			Unicode::snprintf(textTpsValueBuffer, TEXTTPSVALUE_SIZE, "%d", Indicators[TPS].intValore);
		else
			Unicode::snprintfFloat(textTpsValueBuffer, TEXTTPSVALUE_SIZE, "%.1f", Indicators[TPS].floatValore);
		
	if (	Indicators[RPM].intValore == DEF_VALUE && Indicators[RPM].floatValore == DEF_VALUE )
		Unicode::snprintf(textRpmValueBuffer, TEXTRPMVALUE_SIZE, "%s", Empty);	
	else
		if ( Indicators[RPM].TIPO == INT )
			Unicode::snprintf(textRpmValueBuffer, TEXTRPMVALUE_SIZE, "%d", Indicators[RPM].intValore);
		else
			Unicode::snprintfFloat(textRpmValueBuffer, TEXTRPMVALUE_SIZE, "%.1f", Indicators[RPM].floatValore);
		
}

void NOISE_MODEView::checkChangeScreen()
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
				case NOISE_MODE	:
					
					break;
	}		
}
