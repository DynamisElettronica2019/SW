#include <gui/endurance_screen/ENDURANCEView.hpp>

#include <string.h>
#include <touchgfx/Color.hpp>

extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];
extern uint8_t EndPointer[6];

extern int timerDCUdead;
extern int DCU_is_dead;
extern int DCU_was_not_dead;
extern int emergencyFlag;
extern int emergencyBlink;
extern int contBlink;

ENDURANCEView::ENDURANCEView()
{

}

void ENDURANCEView::setupScreen()
{
		touchgfx::Unicode::strncpy( Empty, DEF_SIMBOL, TIT_LEN);
		screenEntry = 0;
		contBlink = 0;
		ENDURANCEViewBase::setupScreen();
}

void ENDURANCEView::tearDownScreen()
{
    ENDURANCEViewBase::tearDownScreen();
}

void ENDURANCEView::refreshEndurance()
{	
	screenEntry ++;
	timerDCUdead ++;
	ENDURANCEView::screenEntryPopup();	
	ENDURANCEView::checkFuelIndicator();
	ENDURANCEView::checkChangeScreen();
	ENDURANCEView::checkAntistall();
	
	/******************TITOLI*******************/
	touchgfx::Unicode::strncpy( Title1, Indicators[EndPointer[0]].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title2, Indicators[EndPointer[1]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title3, Indicators[EndPointer[2]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title4, Indicators[EndPointer[3]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title5, Indicators[EndPointer[4]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title6, Indicators[EndPointer[5]].NOME, TIT_LEN);
	
	Unicode::snprintf(textIndTitle1Buffer, TEXTINDTITLE1_SIZE, "%s", Title1);	
	Unicode::snprintf(textIndTitle2Buffer, TEXTINDTITLE2_SIZE, "%s", Title2);	
	Unicode::snprintf(textIndTitle3Buffer, TEXTINDTITLE3_SIZE, "%s", Title3);	
	Unicode::snprintf(textIndTitle4Buffer, TEXTINDTITLE4_SIZE, "%s", Title4);	
	Unicode::snprintf(textIndTitle5Buffer, TEXTINDTITLE5_SIZE, "%s", Title5);	
	Unicode::snprintf(textIndTitle6Buffer, TEXTINDTITLE6_SIZE, "%s", Title6);
	
	/*************CONTROLLO VALORI EMERGENZA**************/
	if (((Indicators[H2OPUMP_DC].intValore < EMERGENCY_DC_H2O && Indicators[VH_SPEED].floatValore > EMERGENCY_VH_SPEED) ||
				Indicators[OIL_PRESS].floatValore < EMERGENCY_P_OIL || Indicators[OIL_TEMP_IN].floatValore > EMERGENCY_T_OIL || 
				Indicators[PH2O].floatValore > EMERGENCY_P_H2O || Indicators[TH2O].floatValore > EMERGENCY_T_H2O || 
				Indicators[FUEL_LEVEL].floatValore < EMERGENCY_L_FUEL || Indicators[FUEL_PRESS].floatValore < EMERGENCY_P_FUEL ||
				Indicators[VBAT].floatValore < EMERGENCY_V_BAT) && emergencyFlag == 0
			  ){ 
		emergencyFlag = 1;
	}
				
	if ( emergencyBlink == 1 ){
		emergencyBlinkCont ++;
		if ( emergencyBlinkCont < 10 ){
			background.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			boxIndicatorGear.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
		}
		else{
			background.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
			boxIndicatorGear.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
		}
		if ( emergencyBlinkCont > 20 )
			emergencyBlinkCont = 0;
	}
	else {
		boxIndicatorGear.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
		background.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
	}		
	background.invalidate();
	boxIndicatorGear.invalidate();
	if ( emergencyFlag == 2) 
		checkEmergency();
	
	/******************VALORI*******************/
	if (	Indicators[EndPointer[0]].intValore == DEF_VALUE && Indicators[EndPointer[0]].floatValore == DEF_VALUE )
		Unicode::snprintf(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%s", Empty);	
	else
		if ( Indicators[EndPointer[0]].TIPO == INT )
			Unicode::snprintf(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%d", Indicators[EndPointer[0]].intValore);
		else
			Unicode::snprintfFloat(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%.1f", Indicators[EndPointer[0]].floatValore);
		
	if (	Indicators[EndPointer[1]].intValore == DEF_VALUE && Indicators[EndPointer[1]].floatValore == DEF_VALUE )
		Unicode::snprintf(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%s", Empty);	
	else
		if ( Indicators[EndPointer[1]].TIPO == INT )
			Unicode::snprintf(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%d", Indicators[EndPointer[1]].intValore);
		else
			Unicode::snprintfFloat(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%.1f", Indicators[EndPointer[1]].floatValore);
	
	if (	Indicators[EndPointer[2]].intValore == DEF_VALUE && Indicators[EndPointer[2]].floatValore == DEF_VALUE )
		Unicode::snprintf(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%s", Empty);	
	else
		if ( Indicators[EndPointer[2]].TIPO == INT )
			Unicode::snprintf(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%d", Indicators[EndPointer[2]].intValore);
		else
			Unicode::snprintfFloat(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%.1f", Indicators[EndPointer[2]].floatValore);
		
	if (	Indicators[EndPointer[3]].intValore == DEF_VALUE && Indicators[EndPointer[3]].floatValore == DEF_VALUE )
		Unicode::snprintf(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%s", Empty);	
	else
		if ( Indicators[EndPointer[3]].TIPO == INT )
			Unicode::snprintf(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%d", Indicators[EndPointer[3]].intValore);
		else
			Unicode::snprintfFloat(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%.1f", Indicators[EndPointer[3]].floatValore);
		
	if (	Indicators[EndPointer[4]].intValore == DEF_VALUE && Indicators[EndPointer[4]].floatValore == DEF_VALUE )
		Unicode::snprintf(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%s", Empty);	
	else
		if ( Indicators[EndPointer[4]].TIPO == INT )
			Unicode::snprintf(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%d", Indicators[EndPointer[4]].intValore);
		else
			Unicode::snprintfFloat(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%.1f", Indicators[EndPointer[4]].floatValore);
	
	if (	Indicators[EndPointer[5]].intValore == DEF_VALUE && Indicators[EndPointer[5]].floatValore == DEF_VALUE )
		Unicode::snprintf(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%s", Empty);	
	else
		if ( Indicators[EndPointer[5]].TIPO == INT )
			Unicode::snprintf(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%d", Indicators[EndPointer[5]].intValore);
		else
			Unicode::snprintfFloat(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%.1f", Indicators[EndPointer[5]].floatValore);
		
	/****************GEAR-TC-MAP*****************/
	touchgfx::Unicode::strncpy( Gear, Indicators[GEAR].charValore, 3);	//-- Nello switch case del CAN si mette il carattere (N,1,2,..) con il 
																																						//-- comando strcpy altrimenti si hanno problemi di allocazione di memoria
	Unicode::snprintf(textIndGearValueBuffer, TEXTINDGEARVALUE_SIZE, "%s", Gear);
	Unicode::snprintf(textIndTcValueBuffer, TEXTINDTCVALUE_SIZE, "%d", Indicators[TRACTION_CONTROL].intValore);
	Unicode::snprintf(textIndMapValueBuffer, TEXTINDMAPVALUE_SIZE, "%d", Indicators[MAP].intValore);

	/****************ACQUISITION*****************/
	
	if ( Indicators[ACQ].intValore == ACQ_ON ){	
		touchgfx::Unicode::strncpy( Acquisition, "ON", 5);
		boxAcquisition.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	}else if ( Indicators[ACQ].intValore == ACQ_READY ){
		touchgfx::Unicode::strncpy( Acquisition, "OFF", 5);
		boxAcquisition.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 234, 0));
	}else{
		touchgfx::Unicode::strncpy( Acquisition, "OFF", 5);
		boxAcquisition.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
	}
	Unicode::snprintf(textIndAcquisitionValueBuffer, TEXTINDACQUISITIONVALUE_SIZE, "%s", Acquisition);
		
	if ( DCU_is_dead == 1 && DCU_was_not_dead == 0 ){
		boxDCUdead.setVisible(true);
		textDCUdead.setVisible(true);
		timerDCUdead = 0;
		DCU_was_not_dead = 1;
	}
	
	/****************REFFRESH OGGETTI*****************/
	
	textIndTitle1.invalidate();
	textIndTitle2.invalidate();
	textIndTitle3.invalidate();
	textIndTitle4.invalidate();
	textIndTitle5.invalidate();
	textIndTitle6.invalidate();
	
	textIndValue1.invalidate();
	textIndValue2.invalidate();
	textIndValue3.invalidate();
	textIndValue4.invalidate();
	textIndValue5.invalidate();
	textIndValue6.invalidate();
	

	
	textIndGearValue.invalidate();
	textIndTcValue.invalidate();
	textIndMapValue.invalidate();
	
	boxIndicatorGear.invalidate();
	
	textIndAcquisitionValue.invalidate();
	boxAcquisition.invalidate();

	boxDCUdead.invalidate();
	textDCUdead.invalidate();
}

void ENDURANCEView::checkChangeScreen()
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

void ENDURANCEView::screenEntryPopup()
{
	if (screenEntry >= POPUP_TIME) {
		boxEntry.setVisible(false);
		TEXTEnduranceEntry.setVisible(false);
		boxEntry.invalidate();
		TEXTEnduranceEntry.invalidate();
		background.invalidate();
		textIndGearValue.setVisible(true);
	  boxIndicatorGear.invalidate();
	}
	
	if ( timerDCUdead >= POPUP_TIME)
	{
		boxDCUdead.setVisible(false);
	  textDCUdead.setVisible(false);
	}
}

void ENDURANCEView::checkEmergency()
{
	switch (EndPointer[0]){
		case OIL_PRESS:
			if ( Indicators[OIL_PRESS].floatValore < EMERGENCY_P_OIL ){
				boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case OIL_TEMP_IN:
			if ( Indicators[OIL_TEMP_IN].floatValore > EMERGENCY_T_OIL ){
				boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case PH2O:
			if ( Indicators[PH2O].floatValore > EMERGENCY_P_H2O ){
				boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case TH2O:
			if ( Indicators[TH2O].floatValore > EMERGENCY_T_H2O ){
				boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case FUEL_LEVEL:
			if ( Indicators[FUEL_LEVEL].floatValore < EMERGENCY_L_FUEL ){
				boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case VBAT:
			if ( Indicators[VBAT].floatValore < EMERGENCY_V_BAT ){
				boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
	}
	switch (EndPointer[1]){
		case OIL_PRESS:
			if ( Indicators[OIL_PRESS].floatValore < EMERGENCY_P_OIL ){
				boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case OIL_TEMP_IN:
			if ( Indicators[OIL_TEMP_IN].floatValore > EMERGENCY_T_OIL ){
				boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case PH2O:
			if ( Indicators[PH2O].floatValore > EMERGENCY_P_H2O ){
				boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case TH2O:
			if ( Indicators[TH2O].floatValore > EMERGENCY_T_H2O ){
				boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case FUEL_LEVEL:
			if ( Indicators[FUEL_LEVEL].floatValore < EMERGENCY_L_FUEL ){
				boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case VBAT:
			if ( Indicators[VBAT].floatValore < EMERGENCY_V_BAT ){
				boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
	}
	switch (EndPointer[2]){
		case OIL_PRESS:
			if ( Indicators[OIL_PRESS].floatValore < EMERGENCY_P_OIL ){
				boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case OIL_TEMP_IN:
			if ( Indicators[OIL_TEMP_IN].floatValore > EMERGENCY_T_OIL ){
				boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case PH2O:
			if ( Indicators[PH2O].floatValore > EMERGENCY_P_H2O ){
				boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case TH2O:
			if ( Indicators[TH2O].floatValore > EMERGENCY_T_H2O ){
				boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case FUEL_LEVEL:
			if ( Indicators[FUEL_LEVEL].floatValore < EMERGENCY_L_FUEL ){
				boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case VBAT:
			if ( Indicators[VBAT].floatValore < EMERGENCY_V_BAT ){
				boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
	}
	switch (EndPointer[3]){
		case OIL_PRESS:
			if ( Indicators[OIL_PRESS].floatValore < EMERGENCY_P_OIL ){
				boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case OIL_TEMP_IN:
			if ( Indicators[OIL_TEMP_IN].floatValore > EMERGENCY_T_OIL ){
				boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case PH2O:
			if ( Indicators[PH2O].floatValore > EMERGENCY_P_H2O ){
				boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case TH2O:
			if ( Indicators[TH2O].floatValore > EMERGENCY_T_H2O ){
				boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case FUEL_LEVEL:
			if ( Indicators[FUEL_LEVEL].floatValore < EMERGENCY_L_FUEL ){
				boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case VBAT:
			if ( Indicators[VBAT].floatValore < EMERGENCY_V_BAT ){
				boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
	}
	switch (EndPointer[4]){
		case OIL_PRESS:
			if ( Indicators[OIL_PRESS].floatValore < EMERGENCY_P_OIL ){
				boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case OIL_TEMP_IN:
			if ( Indicators[OIL_TEMP_IN].floatValore > EMERGENCY_T_OIL ){
				boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case PH2O:
			if ( Indicators[PH2O].floatValore > EMERGENCY_P_H2O ){
				boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case TH2O:
			if ( Indicators[TH2O].floatValore > EMERGENCY_T_H2O ){
				boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case FUEL_LEVEL:
			if ( Indicators[FUEL_LEVEL].floatValore < EMERGENCY_L_FUEL ){
				boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case VBAT:
			if ( Indicators[VBAT].floatValore < EMERGENCY_V_BAT ){
				boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
	}
	switch (EndPointer[5]){
				case OIL_PRESS:
			if ( Indicators[OIL_PRESS].floatValore < EMERGENCY_P_OIL ){
				boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case OIL_TEMP_IN:
			if ( Indicators[OIL_TEMP_IN].floatValore > EMERGENCY_T_OIL ){
				boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case PH2O:
			if ( Indicators[PH2O].floatValore > EMERGENCY_P_H2O ){
				boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case TH2O:
			if ( Indicators[TH2O].floatValore > EMERGENCY_T_H2O ){
				boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case FUEL_LEVEL:
			if ( Indicators[FUEL_LEVEL].floatValore < EMERGENCY_L_FUEL ){
				boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
		case VBAT:
			if ( Indicators[VBAT].floatValore < EMERGENCY_V_BAT ){
				boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
				textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 0, 0));
			}
			else{
				boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB( 0, 0, 0));
				textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
				textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB( 255, 255, 255));
			}
			break;
	}
}

void ENDURANCEView::checkFuelIndicator(){
	if ( Indicators[EndPointer[0]].ID == FUEL_LEVEL && Indicators[VH_SPEED].floatValore > VH_SPEED_MIN ){
		textIndTitle1.setVisible(false);
		textIndValue1.setVisible(false);
		textIndTitle1.invalidate();
		textIndValue1.invalidate();
	}
	else{
		textIndTitle1.setVisible(true);
		textIndValue1.setVisible(true);
		textIndTitle1.invalidate();
		textIndValue1.invalidate();
	}
	if ( Indicators[EndPointer[1]].ID == FUEL_LEVEL && Indicators[VH_SPEED].floatValore > VH_SPEED_MIN ){
		textIndTitle2.setVisible(false);
		textIndValue2.setVisible(false);
		textIndTitle2.invalidate();
		textIndValue2.invalidate();
	}
	else{
		textIndTitle2.setVisible(true);
		textIndValue2.setVisible(true);
		textIndTitle2.invalidate();
		textIndValue2.invalidate();
	}
	if ( Indicators[EndPointer[2]].ID == FUEL_LEVEL && Indicators[VH_SPEED].floatValore > VH_SPEED_MIN ){
		textIndTitle3.setVisible(false);
		textIndValue3.setVisible(false);
		textIndTitle3.invalidate();
		textIndValue3.invalidate();
	}
	else{
		textIndTitle3.setVisible(true);
		textIndValue3.setVisible(true);
		textIndTitle3.invalidate();
		textIndValue3.invalidate();
	}
	if ( Indicators[EndPointer[3]].ID == FUEL_LEVEL && Indicators[VH_SPEED].floatValore > VH_SPEED_MIN ){
		textIndTitle4.setVisible(false);
		textIndValue4.setVisible(false);
		textIndTitle4.invalidate();
		textIndValue4.invalidate();
	}
	else{
		textIndTitle4.setVisible(true);
		textIndValue4.setVisible(true);
		textIndTitle4.invalidate();
		textIndValue4.invalidate();
	}
	if ( Indicators[EndPointer[4]].ID == FUEL_LEVEL && Indicators[VH_SPEED].floatValore > VH_SPEED_MIN ){
		textIndTitle5.setVisible(false);
		textIndValue5.setVisible(false);
		textIndTitle5.invalidate();
		textIndValue5.invalidate();
	}
	else{
		textIndTitle5.setVisible(true);
		textIndValue5.setVisible(true);
		textIndTitle5.invalidate();
		textIndValue5.invalidate();
	}
	if ( Indicators[EndPointer[5]].ID == FUEL_LEVEL && Indicators[VH_SPEED].floatValore > VH_SPEED_MIN ){
		textIndTitle6.setVisible(false);
		textIndValue6.setVisible(false);
		textIndTitle6.invalidate();
		textIndValue6.invalidate();
	}
	else{
		textIndTitle6.setVisible(true);
		textIndValue6.setVisible(true);
		textIndTitle6.invalidate();
		textIndValue6.invalidate();
	}
}

void ENDURANCEView::checkAntistall(void)
{
		if(Indicators[ANTISTALL].intValore == 1)
		{
			contBlink ++;
			
			if ( contBlink < 20 ){
				boxAntistall.setVisible(true);
				textAntistall.setVisible(true);
			}
			else{
			boxAntistall.setVisible(false);
			textAntistall.setVisible(false);
			}
			
			if ( contBlink > 40 ){
				contBlink = 0;
			}
		}
		else{
			boxAntistall.setVisible(false);
			textAntistall.setVisible(false);
		}
		
	boxAntistall.invalidate();
	textAntistall.invalidate();
}
