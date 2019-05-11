#include <gui/skidpad_screen/SKIDPADView.hpp>

#include <string.h>
#include <touchgfx/Color.hpp>

extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];
//extern Indicator_Pointer SkiPointer;
extern uint8_t SkiPointer[6];

SKIDPADView::SKIDPADView()
{

}

void SKIDPADView::setupScreen()
{
    SKIDPADViewBase::setupScreen();
	
		SkiPointer[0] = 0;
		SkiPointer[1] = 1;
		SkiPointer[2] = 2;
		SkiPointer[3] = 3;
		SkiPointer[4] = 4;
		SkiPointer[5] = 5;
		boxIndicatorGear.invalidate();
}

void SKIDPADView::tearDownScreen()
{
    SKIDPADViewBase::tearDownScreen();
}

void SKIDPADView::refreshSkidpad()
{	
	SKIDPADView::checkChangeScreen();
	
	/******************TITOLI*******************/
	touchgfx::Unicode::strncpy( Title1, Indicators[SkiPointer[0]].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title2, Indicators[SkiPointer[1]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title3, Indicators[SkiPointer[2]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title4, Indicators[SkiPointer[3]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title5, Indicators[SkiPointer[4]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title6, Indicators[SkiPointer[5]].NOME, TIT_LEN);
	
	Unicode::snprintf(textIndTitle1Buffer, TEXTINDTITLE1_SIZE, "%s", Title1);	
	Unicode::snprintf(textIndTitle2Buffer, TEXTINDTITLE2_SIZE, "%s", Title2);	
	Unicode::snprintf(textIndTitle3Buffer, TEXTINDTITLE3_SIZE, "%s", Title3);	
	Unicode::snprintf(textIndTitle4Buffer, TEXTINDTITLE4_SIZE, "%s", Title4);	
	Unicode::snprintf(textIndTitle5Buffer, TEXTINDTITLE5_SIZE, "%s", Title5);	
	Unicode::snprintf(textIndTitle6Buffer, TEXTINDTITLE6_SIZE, "%s", Title6);
	
	/******************VALORI*******************/
	if ( Indicators[SkiPointer[0]].TIPO == INT )
		Unicode::snprintf(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%d", Indicators[SkiPointer[0]].intValore);
	else
		Unicode::snprintfFloat(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%.1f", Indicators[SkiPointer[0]].floatValore);
	
	if ( Indicators[SkiPointer[1]].TIPO == INT )
		Unicode::snprintf(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%d", Indicators[SkiPointer[1]].intValore);
	else
		Unicode::snprintfFloat(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%.1f", Indicators[SkiPointer[1]].floatValore);
	
	if ( Indicators[SkiPointer[2]].TIPO == INT )
		Unicode::snprintf(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%d", Indicators[SkiPointer[2]].intValore);
	else
		Unicode::snprintfFloat(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%.1f", Indicators[SkiPointer[2]].floatValore);
	
	if ( Indicators[SkiPointer[3]].TIPO == INT )
		Unicode::snprintf(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%d", Indicators[SkiPointer[3]].intValore);
	else
		Unicode::snprintfFloat(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%.1f", Indicators[SkiPointer[3]].floatValore);
	
	if ( Indicators[SkiPointer[4]].TIPO == INT )
		Unicode::snprintf(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%d", Indicators[SkiPointer[4]].intValore);
	else
		Unicode::snprintfFloat(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%.1f", Indicators[SkiPointer[4]].floatValore);
	
	if ( Indicators[SkiPointer[5]].TIPO == INT )
		Unicode::snprintf(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%d", Indicators[SkiPointer[5]].intValore);
	else
		Unicode::snprintfFloat(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%.1f", Indicators[SkiPointer[5]].floatValore);
	
	/****************GEAR-TC-MAP*****************/
	touchgfx::Unicode::strncpy( Gear, Indicators[GEAR_MOTOR].charValore, 3);		//-- Nello switch case del CAN si mette il carattere (N,1,2,..) con il 
																																							//-- comando strcpy altrimenti si hanno problemi di allocazione di memoria
	Unicode::snprintf(textIndGearValueBuffer, TEXTINDGEARVALUE_SIZE, "%s", Gear);
	Unicode::snprintf(textIndTcValueBuffer, TEXTINDTCVALUE_SIZE, "%d", Indicators[TRACTION_CONTROL].intValore);
	Unicode::snprintf(textIndMapValueBuffer, TEXTINDMAPVALUE_SIZE, "%d", Indicators[MAP].intValore);

	/****************ACQUISITION*****************/
	
	if ( Indicators[ACQ].intValore == 1 ){					//--------- da decidere come modificare il valore quando letto da CAN
		touchgfx::Unicode::strncpy( Acquisition, "ON", 5);
		boxAcquisition.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	}
	else{
		touchgfx::Unicode::strncpy( Acquisition, "OFF", 5);
		boxAcquisition.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
	}
	Unicode::snprintf(textIndAcquisitionValueBuffer, TEXTINDACQUISITIONVALUE_SIZE, "%s", Acquisition);
	
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
	
}

void SKIDPADView::checkChangeScreen()
{
	switch ( driveMode ){
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
					
					break;
	}	
}
