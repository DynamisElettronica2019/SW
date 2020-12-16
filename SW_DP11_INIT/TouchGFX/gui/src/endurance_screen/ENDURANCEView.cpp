#include <gui/endurance_screen/ENDURANCEView.hpp>

#include <tim.h>
#include <string.h>
#include <touchgfx/Color.hpp>

extern char targetMode;
extern Indicator_Value Indicators[N_INDICATORS];
extern uint8_t EndPointer[6];

int timerDCUdead = 0;	//extern
extern int DCU_is_dead;
extern int DCU_was_not_dead;
extern int emergencyFlag;
extern int emergencyBlink;
int contBlink = 0;	//extern
extern int flagEngineOn;

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
	ENDURANCEView::checkChangeScreen();
	
	/******************TITOLI*******************/
	touchgfx::Unicode::strncpy( Title1, Indicators[EndPointer[0]].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title2, Indicators[EndPointer[1]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title3, Indicators[EndPointer[2]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title4, Indicators[EndPointer[3]].NOME, TIT_LEN);		

	
	Unicode::snprintf(textIndicator1Buffer, TEXTINDICATOR1_SIZE, "%s", Title1);	
	Unicode::snprintf(textIndicator2Buffer, TEXTINDICATOR2_SIZE, "%s", Title2);	
	Unicode::snprintf(textIndicator3Buffer, TEXTINDICATOR3_SIZE, "%s", Title3);	
	Unicode::snprintf(textIndicator4Buffer, TEXTINDICATOR4_SIZE, "%s", Title4);	

	
	/*************CONTROLLO VALORI EMERGENZA**************/
	
	// da rifare con valori dp12e
	
	/******************VALORI*******************/
	if (	Indicators[EndPointer[0]].intValore == DEF_VALUE && Indicators[EndPointer[0]].floatValore == DEF_VALUE )
		Unicode::snprintf(textIndicatorValue1Buffer, TEXTINDICATORVALUE1_SIZE, "%s", Empty);	
	else
		if ( Indicators[EndPointer[0]].TIPO == INT )
			Unicode::snprintf(textIndicatorValue1Buffer, TEXTINDICATORVALUE1_SIZE, "%d", Indicators[EndPointer[0]].intValore);
		else
			Unicode::snprintfFloat(textIndicatorValue1Buffer, TEXTINDICATORVALUE1_SIZE, "%.1f", Indicators[EndPointer[0]].floatValore);
		
	if (	Indicators[EndPointer[1]].intValore == DEF_VALUE && Indicators[EndPointer[1]].floatValore == DEF_VALUE )
		Unicode::snprintf(textIndicatorValue2Buffer, TEXTINDICATORVALUE2_SIZE, "%s", Empty);	
	else
		if ( Indicators[EndPointer[1]].TIPO == INT )
			Unicode::snprintf(textIndicatorValue2Buffer, TEXTINDICATORVALUE2_SIZE, "%d", Indicators[EndPointer[1]].intValore);
		else
			Unicode::snprintfFloat(textIndicatorValue2Buffer, TEXTINDICATORVALUE2_SIZE, "%.1f", Indicators[EndPointer[1]].floatValore);
	
	if (	Indicators[EndPointer[2]].intValore == DEF_VALUE && Indicators[EndPointer[2]].floatValore == DEF_VALUE )
		Unicode::snprintf(textIndicatorValue3Buffer, TEXTINDICATORVALUE3_SIZE, "%s", Empty);	
	else
		if ( Indicators[EndPointer[2]].TIPO == INT )
			Unicode::snprintf(textIndicatorValue3Buffer, TEXTINDICATORVALUE3_SIZE, "%d", Indicators[EndPointer[2]].intValore);
		else
			Unicode::snprintfFloat(textIndicatorValue3Buffer, TEXTINDICATORVALUE3_SIZE, "%.1f", Indicators[EndPointer[2]].floatValore);
		
	if (	Indicators[EndPointer[3]].intValore == DEF_VALUE && Indicators[EndPointer[3]].floatValore == DEF_VALUE )
		Unicode::snprintf(textIndicatorValue4Buffer, TEXTINDICATORVALUE4_SIZE, "%s", Empty);	
	else
		if ( Indicators[EndPointer[3]].TIPO == INT )
			Unicode::snprintf(textIndicatorValue4Buffer, TEXTINDICATORVALUE4_SIZE, "%d", Indicators[EndPointer[3]].intValore);
		else
			Unicode::snprintfFloat(textIndicatorValue4Buffer, TEXTINDICATORVALUE4_SIZE, "%.1f", Indicators[EndPointer[3]].floatValore);
	
		
	/****************VBATT-SOC**************/
	
	if(Indicators[VBAT].intValore == DEF_VALUE)
		Unicode::snprintf(textVBATValueBuffer, TEXTVBATVALUE_SIZE, "%s", Empty);	
	else
		Unicode::snprintf(textVBATValueBuffer, TEXTVBATVALUE_SIZE, "%d", Indicators[VBAT].intValore);

	#ifndef SIM_MODE
	if(Indicators[SOC].intValore == DEF_VALUE)
			barSOC.setPosition(11, 10, 0, 23);
	else
		barSOC.setPosition(11, 10, (int)((float)(618*Indicators[SOC].intValore)/100), 23);
	#else
		barSOC.setPosition(11, 10	, (int)((float)(618*Indicators[POW_LIM].intValore*10)/100), 23);
	#endif
		
	/****************TC-TV-MAP-POW*****************/
//	touchgfx::Unicode::strncpy( TractionValue, Indicators[TRACTION_CONTROL].charValore, 5);
//	touchgfx::Unicode::strncpy( TorqueValue, Indicators[TV].charValore, 5);	//-- Nello switch case del CAN si mette il carattere (0,DEF,1,2,..) con il 
																																						//-- comando strcpy altrimenti si hanno problemi di allocazione di memoria
	Unicode::snprintf(textTorqueValueBuffer, TEXTTORQUEVALUE_SIZE, "%d", Indicators[TV].intValore);
	Unicode::snprintf(textTractionValueBuffer, TEXTTRACTIONVALUE_SIZE, "%d", Indicators[TC].intValore);
	Unicode::snprintf(textMapValueBuffer, TEXTMAPVALUE_SIZE, "%d", Indicators[MAP].intValore);
	Unicode::snprintf(textMaxPowerValueBuffer, TEXTMAXPOWERVALUE_SIZE, "%d", Indicators[POW_LIM].intValore*10);

	/****************RTD-REGEN*****************/	
	
	
	if ( Indicators[TS].intValore == TS_OFF ){	
		boxTS.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
		touchgfx::Unicode::strncpy( TSValue, "TS OFF", 7);
		boxRTD.setVisible(false);
		textRTD.setVisible(false);	
	}else if ( Indicators[TS].intValore == TS_ON ){
		boxTS.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));	
		touchgfx::Unicode::strncpy( TSValue, "TS ON", 7);
		boxRTD.setVisible(false);
		textRTD.setVisible(false);	
	}else if ( Indicators[TS].intValore == TS_RTD ){
		boxTS.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
		touchgfx::Unicode::strncpy( TSValue, "RTD", 7);

		#ifndef SIM_MODE
			if ( Indicators[INSS_SPEED].floatValore <= MIN_SPEED){
		#endif
				boxRTD.setVisible(true);
				textRTD.setVisible(true);
		#ifndef SIM_MODE
			}	else {
				boxRTD.setVisible(false);
				textRTD.setVisible(false);	
			}				
		#endif
				
	}else{
		touchgfx::Unicode::strncpy(TSValue, "?", 7);
		boxTS.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
	}
	Unicode::snprintf(textTSBuffer, TEXTTS_SIZE, "%s", TSValue);
	
	if ( Indicators[REGEN].intValore == START_REGEN ){
		boxRGN.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
		textRGN.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
	}
	else if ( Indicators[REGEN].intValore == STOP_REGEN ){
		boxRGN.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
		textRGN.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
	}
	
	/****************ACQUISITION****************/
	
	if ( Indicators[ACQ].intValore == ACQ_ON ){	
		boxUSB.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	}else if ( Indicators[ACQ].intValore == ACQ_READY ){
		boxUSB.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 234, 0));
	}else{
		boxUSB.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
	}
	
	if ( Indicators[BMS_STATE].intValore == ACQ_ON ){	
		boxSD.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	}else if ( Indicators[BMS_STATE].intValore == ACQ_READY ){
		boxSD.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 234, 0));
	}else{
		boxSD.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
	}
	
	
	if ( DCU_is_dead == 1 && DCU_was_not_dead == 0 ){
		boxDCU.setVisible(true);
		textDCU.setVisible(true);
		timerDCUdead = 0;
		DCU_was_not_dead = 1;
	}
	
	/****************REFFRESH OGGETTI*****************/
	
	textIndicator1.invalidate();
	textIndicator2.invalidate();
	textIndicator3.invalidate();
	textIndicator4.invalidate();

	
	textIndicatorValue1.invalidate();
	textIndicatorValue2.invalidate();
	textIndicatorValue3.invalidate();
	textIndicatorValue4.invalidate();

	
	textTorqueValue.invalidate();
	textTractionValue.invalidate();
	textMapValue.invalidate();
	
	textVBATValue.invalidate();
	
	boxUSB.invalidate();
	boxSD.invalidate();
	
	boxDCU.invalidate();
	textDCU.invalidate();
	
	barSOC.invalidate();
	
	boxRTD.invalidate();
	textRTD.invalidate();
	boxRGN.invalidate();
	textRGN.invalidate();
	
}

void ENDURANCEView::checkChangeScreen()
{
	switch ( Indicators[DRIVE_MODE].intValore ){
//				case SETTINGS_MODE	:
//					application().gotoSETTINGSScreenNoTransition();
//					break;
//				case BOARD_DEBUG_MODE	:
//					application().gotoBOARD_DEBUGScreenNoTransition();
//					break;
//				case DEBUG_MODE	:
//					application().gotoDEBUG_MODEScreenNoTransition();
//					break;
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
//				case NOISE_MODE	:
//					application().gotoNOISE_MODEScreenNoTransition();
//					break;
	}	
}

void ENDURANCEView::screenEntryPopup()
{
	if (screenEntry >= POPUP_TIME) {
		boxEntry.setVisible(false);
		textEntry.setVisible(false);
		boxEntry.invalidate();
		textEntry.invalidate();
		background.invalidate();
	}
	
	if ( timerDCUdead >= POPUP_TIME)
	{
		boxDCU.setVisible(false);
	  textDCU.setVisible(false);
	}
}
/*
void ENDURANCEView::checkEmergency()
{
		ciao ciao
}
*/
