#include <gui/settings_screen/SETTINGSView.hpp>

#include <string.h>

extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];
extern int schermata_settings;
extern int box_driveMode;
extern int box_indicator;
extern int pointer_scroll;
extern int change_pointer;

extern uint8_t AccPointer[6];
extern uint8_t EndPointer[6];
extern uint8_t AutPointer[6];
extern uint8_t SkiPointer[6];

extern int currentCalibration;
extern int feedbackCalibration;
extern int flagCalibration;
extern int calibrationPopUp;

int flag_schermata;
	
SETTINGSView::SETTINGSView()
{

}

void SETTINGSView::setupScreen()
{
		flagCalibration = 0;
		calibrationPopUp = 0;
		currentCalibration = 1;
		schermata_settings = 0;		// appena si entra nella modalità settings la variabile viene messa a 0, verrà messa a 1 in freertos.c
		box_driveMode = 0;				// viene incrementata a 1, 2, 3 e poi riportata a 0.
		box_indicator = 0;				// viene incrementata a 1, 2, 3, 4, 5 e poi riportata a 0.
		pointer_scroll = 0;
		flag_schermata = 0;
		change_pointer = 0;
    SETTINGSViewBase::setupScreen();
}

void SETTINGSView::tearDownScreen()
{
    SETTINGSViewBase::tearDownScreen();
}

void SETTINGSView::refreshSettings()
{
	SETTINGSView::checkChangeScreen();
	
	switch (schermata_settings){
		case 0 :
			if (flag_schermata == 0)
				SETTINGSView::changeDisplay();
			boxModeSelected.setVisible(false);
			boxModeSelected.invalidate();
			boxModeSelected.setPosition(15, 20 + (90*box_driveMode), 476, 75);
			boxModeSelected.setVisible(true);
			boxModeSelected.invalidate();
			
			textIndTitle1.invalidate();
			textIndTitle2.invalidate();
			textIndTitle3.invalidate();
			textIndTitle4.invalidate();
			textIndTitle5.invalidate();
			textIndTitle6.invalidate();
			textIndTitleCurrent.invalidate();
			textIndDriveMode.invalidate();
			
			textIndValue1.invalidate();
			textIndValue2.invalidate();
			textIndValue3.invalidate();
			textIndValue4.invalidate();
			textIndValue5.invalidate();
			textIndValue6.invalidate();
			boxIndSelected.invalidate();
			boxCalibrationSelected.invalidate();
			break;
		case 1 :
			if (flag_schermata == 0)
				SETTINGSView::changeDisplay();
			
			SETTINGSView::moveSelectedBox();
			
			switch (box_driveMode){
				case SETT_ACC_BOX:
					touchgfx::Unicode::strncpy( TitleDriveMode, "ACCELERATION", 15);					
					SETTINGSView::displayAcceleration();
					break;
				case SETT_END_BOX:
					touchgfx::Unicode::strncpy( TitleDriveMode, "ENDURANCE", 15);
					SETTINGSView::displayEndurance();
					break;
				case SETT_AUT_BOX:
					touchgfx::Unicode::strncpy( TitleDriveMode, "AUTOCROSS", 15);
					SETTINGSView::displayAutocross();
					break;
				case SETT_SKI_BOX:
					touchgfx::Unicode::strncpy( TitleDriveMode, "SKIDPAD", 15);
					SETTINGSView::displaySkidpad();
					break;					
			}
			Unicode::snprintf(textIndDriveModeBuffer, TEXTINDDRIVEMODE_SIZE, "%s", TitleDriveMode);	
			
			textIndTitle1.invalidate();
			textIndTitle2.invalidate();
			textIndTitle3.invalidate();
			textIndTitle4.invalidate();
			textIndTitle5.invalidate();
			textIndTitle6.invalidate();
			textIndTitleCurrent.invalidate();
			textIndDriveMode.invalidate();
			
			textIndValue1.invalidate();
			textIndValue2.invalidate();
			textIndValue3.invalidate();
			textIndValue4.invalidate();
			textIndValue5.invalidate();
			textIndValue6.invalidate();
				
			break;
		case 2:
			if (flag_schermata == 0)
				SETTINGSView::changeDisplay();
			boxCalibrationSelected.setVisible(false);
			boxCalibrationSelected.invalidate();
			boxCalibrationSelected.setPosition(58, 22 + (90*(currentCalibration-1)), 535, 83);
			boxCalibrationSelected.setVisible(true);
			boxCalibrationSelected.invalidate();
			SETTINGSView::calibrationDisplay();
			break;
			
	}
	
}
void SETTINGSView::checkChangeScreen()
{
	switch ( Indicators[DRIVE_MODE].intValore ){
				case SETTINGS_MODE	:
					
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

void SETTINGSView::changeDisplay()
{
	flag_schermata = 1;
	if (schermata_settings == 1){
		boxIndSelected.setVisible(true);
		boxIndicator1.setVisible(true);
		boxIndicator2.setVisible(true);
		boxIndicator3.setVisible(true);
		boxIndicator4.setVisible(true);
		boxIndicator5.setVisible(true);
		boxIndicator6.setVisible(true);
		textIndTitle1.setVisible(true);
		textIndTitle2.setVisible(true);
		textIndTitle3.setVisible(true);
		textIndTitle4.setVisible(true);
		textIndTitle5.setVisible(true);
		textIndTitle6.setVisible(true);
		textIndValue1.setVisible(true);
		textIndValue2.setVisible(true);
		textIndValue3.setVisible(true);
		textIndValue4.setVisible(true);
		textIndValue5.setVisible(true);
		textIndValue6.setVisible(true);
		textIndDriveMode.setVisible(true);
		textIndTitleCurrent.setVisible(true);
		boxModeSelected.setVisible(false);
		textACCELERATION.setVisible(false);
		textENDURANCE.setVisible(false);
		textAUTOCROSS.setVisible(false);
		textSKIDPAD.setVisible(false);
		textCALIBRATION.setVisible(false);
	}
	else if (schermata_settings == 2){
		
		textLOAD_CELL.setVisible(true);
		textLINEAR.setVisible(true);
		textAPPS_0.setVisible(true);
		textAPPS_100.setVisible(true);
		textSW_ANGLE.setVisible(true);
		boxCalibrationSelected.setVisible(true);
		boxModeSelected.setVisible(false);
		textACCELERATION.setVisible(false);
		textENDURANCE.setVisible(false);
		textAUTOCROSS.setVisible(false);
		textSKIDPAD.setVisible(false);
		textCALIBRATION.setVisible(false);
	}
	else if (schermata_settings == 0){
		boxIndSelected.setVisible(false);
		boxIndicator1.setVisible(false);
		boxIndicator2.setVisible(false);
		boxIndicator3.setVisible(false);
		boxIndicator4.setVisible(false);
		boxIndicator5.setVisible(false);
		boxIndicator6.setVisible(false);
		textIndTitle1.setVisible(false);
		textIndTitle2.setVisible(false);
		textIndTitle3.setVisible(false);
		textIndTitle4.setVisible(false);
		textIndTitle5.setVisible(false);
		textIndTitle6.setVisible(false);
		textIndValue1.setVisible(false);
		textIndValue2.setVisible(false);
		textIndValue3.setVisible(false);
		textIndValue4.setVisible(false);
		textIndValue5.setVisible(false);
		textIndValue6.setVisible(false);
		textIndDriveMode.setVisible(false);
		textIndTitleCurrent.setVisible(false);
		textLOAD_CELL.setVisible(false);
		textLINEAR.setVisible(false);
		textAPPS_0.setVisible(false);
		textAPPS_100.setVisible(false);
		textSW_ANGLE.setVisible(false);
		boxCalibrationSelected.setVisible(false);
		boxModeSelected.setVisible(true);
		textACCELERATION.setVisible(true);
		textENDURANCE.setVisible(true);
		textAUTOCROSS.setVisible(true);
		textSKIDPAD.setVisible(true);
		textCALIBRATION.setVisible(true);
	}
	textACCELERATION.invalidate();
	textENDURANCE.invalidate();
	textAUTOCROSS.invalidate();
	textSKIDPAD.invalidate();
	textCALIBRATION.invalidate();
	boxModeSelected.invalidate();
	boxCalibrationSelected.invalidate();
}


void SETTINGSView::moveSelectedBox()
{
	boxIndSelected.setVisible(false);
	boxIndSelected.invalidate();
	switch (box_indicator){
		case 0 :
			boxIndSelected.setPosition(0, 1, 166, 101);
			break;
		case 1 :
			boxIndSelected.setPosition(474, 1, 166, 101);
			break;
		case 2 :
			boxIndSelected.setPosition(0, 371, 166, 101);
			break;
		case 3 :
			boxIndSelected.setPosition(158, 371, 166, 101);
			break;
		case 4 :
			boxIndSelected.setPosition(316, 371, 166, 101);
			break;
		case 5 :
			boxIndSelected.setPosition(474, 371, 166, 101);
			break;
	}
	boxIndSelected.setVisible(true);
	boxIndSelected.invalidate();
}

void SETTINGSView::displayAcceleration()
{
	
		switch (box_indicator){
		case 0 :
			if (change_pointer == 1){
				change_pointer = 0;
				AccPointer[0] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[AccPointer[0]].NOME, TIT_LEN);
			break;
		case 1 :
			if (change_pointer == 1){
				change_pointer = 0;
				AccPointer[1] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[AccPointer[1]].NOME, TIT_LEN);
			break;
		case 2 :
			if (change_pointer == 1){
				change_pointer = 0;
				AccPointer[2] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[AccPointer[2]].NOME, TIT_LEN);
			break;
		case 3 :
			if (change_pointer == 1){
				change_pointer = 0;
				AccPointer[3] = pointer_scroll;
				}
			touchgfx::Unicode::strncpy( Title, Indicators[AccPointer[3]].NOME, TIT_LEN);
			break;
		case 4 :
			if (change_pointer == 1){
				change_pointer = 0;
				AccPointer[4] = pointer_scroll;
				}
			touchgfx::Unicode::strncpy( Title, Indicators[AccPointer[4]].NOME, TIT_LEN);
			break;
		case 5 :
			if (change_pointer == 1){
				change_pointer = 0;
				AccPointer[5] = pointer_scroll;
				}
			touchgfx::Unicode::strncpy( Title, Indicators[AccPointer[5]].NOME, TIT_LEN);
			break;
	}
		
	touchgfx::Unicode::strncpy( Title1, Indicators[AccPointer[0]].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title2, Indicators[AccPointer[1]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title3, Indicators[AccPointer[2]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title4, Indicators[AccPointer[3]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title5, Indicators[AccPointer[4]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title6, Indicators[AccPointer[5]].NOME, TIT_LEN);
	
	Unicode::snprintf(textIndTitle1Buffer, TEXTINDTITLE1_SIZE, "%s", Title1);	
	Unicode::snprintf(textIndTitle2Buffer, TEXTINDTITLE2_SIZE, "%s", Title2);	
	Unicode::snprintf(textIndTitle3Buffer, TEXTINDTITLE3_SIZE, "%s", Title3);	
	Unicode::snprintf(textIndTitle4Buffer, TEXTINDTITLE4_SIZE, "%s", Title4);	
	Unicode::snprintf(textIndTitle5Buffer, TEXTINDTITLE5_SIZE, "%s", Title5);	
	Unicode::snprintf(textIndTitle6Buffer, TEXTINDTITLE6_SIZE, "%s", Title6);
	
	Unicode::snprintf(textIndTitleCurrentBuffer, TEXTINDTITLECURRENT_SIZE, "%s", Title);
	
	if ( Indicators[AccPointer[0]].TIPO == INT )
		Unicode::snprintf(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%d", Indicators[AccPointer[0]].intValore);
	else
		Unicode::snprintfFloat(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%.1f", Indicators[AccPointer[0]].floatValore);
	
	if ( Indicators[AccPointer[1]].TIPO == INT )
		Unicode::snprintf(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%d", Indicators[AccPointer[1]].intValore);
	else
		Unicode::snprintfFloat(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%.1f", Indicators[AccPointer[1]].floatValore);
	
	if ( Indicators[AccPointer[2]].TIPO == INT )
		Unicode::snprintf(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%d", Indicators[AccPointer[2]].intValore);
	else
		Unicode::snprintfFloat(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%.1f", Indicators[AccPointer[2]].floatValore);
	
	if ( Indicators[AccPointer[3]].TIPO == INT )
		Unicode::snprintf(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%d", Indicators[AccPointer[3]].intValore);
	else
		Unicode::snprintfFloat(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%.1f", Indicators[AccPointer[3]].floatValore);
	
	if ( Indicators[AccPointer[4]].TIPO == INT )
		Unicode::snprintf(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%d", Indicators[AccPointer[4]].intValore);
	else
		Unicode::snprintfFloat(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%.1f", Indicators[AccPointer[4]].floatValore);
	
	if ( Indicators[AccPointer[5]].TIPO == INT )
		Unicode::snprintf(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%d", Indicators[AccPointer[5]].intValore);
	else
		Unicode::snprintfFloat(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%.1f", Indicators[AccPointer[5]].floatValore);
}

void SETTINGSView::displayEndurance()
{
	
	switch (box_indicator){
		case 0 :			
			if (change_pointer == 1){
				change_pointer = 0;
				EndPointer[0] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[EndPointer[0]].NOME, TIT_LEN);
			break;
		case 1 :
			if (change_pointer == 1){
				change_pointer = 0;
				EndPointer[1] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[EndPointer[1]].NOME, TIT_LEN);
			break;
		case 2 :
			if (change_pointer == 1){
				change_pointer = 0;
				EndPointer[2] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[EndPointer[2]].NOME, TIT_LEN);
			break;
		case 3 :
			if (change_pointer == 1){
				change_pointer = 0;
				EndPointer[3] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[EndPointer[3]].NOME, TIT_LEN);
			break;
		case 4 :
			if (change_pointer == 1){
				change_pointer = 0;
				EndPointer[4] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[EndPointer[4]].NOME, TIT_LEN);
			break;
		case 5 :
			if (change_pointer == 1){
				change_pointer = 0;
				EndPointer[5] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[EndPointer[5]].NOME, TIT_LEN);
			break;
	}
	
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
	
	Unicode::snprintf(textIndTitleCurrentBuffer, TEXTINDTITLECURRENT_SIZE, "%s", Title);
	
	if ( Indicators[EndPointer[0]].TIPO == INT )
		Unicode::snprintf(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%d", Indicators[EndPointer[0]].intValore);
	else
		Unicode::snprintfFloat(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%.1f", Indicators[EndPointer[0]].floatValore);
	
	if ( Indicators[EndPointer[1]].TIPO == INT )
		Unicode::snprintf(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%d", Indicators[EndPointer[1]].intValore);
	else
		Unicode::snprintfFloat(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%.1f", Indicators[EndPointer[1]].floatValore);
	
	if ( Indicators[EndPointer[2]].TIPO == INT )
		Unicode::snprintf(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%d", Indicators[EndPointer[2]].intValore);
	else
		Unicode::snprintfFloat(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%.1f", Indicators[EndPointer[2]].floatValore);
	
	if ( Indicators[EndPointer[3]].TIPO == INT )
		Unicode::snprintf(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%d", Indicators[EndPointer[3]].intValore);
	else
		Unicode::snprintfFloat(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%.1f", Indicators[EndPointer[3]].floatValore);
	
	if ( Indicators[EndPointer[4]].TIPO == INT )
		Unicode::snprintf(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%d", Indicators[EndPointer[4]].intValore);
	else
		Unicode::snprintfFloat(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%.1f", Indicators[EndPointer[4]].floatValore);
	
	if ( Indicators[EndPointer[5]].TIPO == INT )
		Unicode::snprintf(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%d", Indicators[EndPointer[5]].intValore);
	else
		Unicode::snprintfFloat(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%.1f", Indicators[EndPointer[5]].floatValore);
}

void SETTINGSView::displayAutocross()
{
	
	switch (box_indicator){
		case 0 :
			if (change_pointer == 1){
				change_pointer = 0;
				AutPointer[0] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[AutPointer[0]].NOME, TIT_LEN);
			break;
		case 1 :
			if (change_pointer == 1){
				change_pointer = 0;
				AutPointer[1] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[AutPointer[1]].NOME, TIT_LEN);
			break;
		case 2 :
			if (change_pointer == 1){
				change_pointer = 0;
				AutPointer[2] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[AutPointer[2]].NOME, TIT_LEN);
			break;
		case 3 :
			if (change_pointer == 1){
				change_pointer = 0;
				AutPointer[3] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[AutPointer[3]].NOME, TIT_LEN);
			break;
		case 4 :
			if (change_pointer == 1){
				change_pointer = 0;
				AutPointer[4] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[AutPointer[4]].NOME, TIT_LEN);
			break;
		case 5 :
			if (change_pointer == 1){
				change_pointer = 0;
				AutPointer[5] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[AutPointer[5]].NOME, TIT_LEN);
			break;
	}
	
	touchgfx::Unicode::strncpy( Title1, Indicators[AutPointer[0]].NOME, TIT_LEN);	
	touchgfx::Unicode::strncpy( Title2, Indicators[AutPointer[1]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title3, Indicators[AutPointer[2]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title4, Indicators[AutPointer[3]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title5, Indicators[AutPointer[4]].NOME, TIT_LEN);		
	touchgfx::Unicode::strncpy( Title6, Indicators[AutPointer[5]].NOME, TIT_LEN);
	
	Unicode::snprintf(textIndTitle1Buffer, TEXTINDTITLE1_SIZE, "%s", Title1);	
	Unicode::snprintf(textIndTitle2Buffer, TEXTINDTITLE2_SIZE, "%s", Title2);	
	Unicode::snprintf(textIndTitle3Buffer, TEXTINDTITLE3_SIZE, "%s", Title3);	
	Unicode::snprintf(textIndTitle4Buffer, TEXTINDTITLE4_SIZE, "%s", Title4);	
	Unicode::snprintf(textIndTitle5Buffer, TEXTINDTITLE5_SIZE, "%s", Title5);	
	Unicode::snprintf(textIndTitle6Buffer, TEXTINDTITLE6_SIZE, "%s", Title6);
	
	Unicode::snprintf(textIndTitleCurrentBuffer, TEXTINDTITLECURRENT_SIZE, "%s", Title);
	
	if ( Indicators[AutPointer[0]].TIPO == INT )
		Unicode::snprintf(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%d", Indicators[AutPointer[0]].intValore);
	else
		Unicode::snprintfFloat(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%.1f", Indicators[AutPointer[0]].floatValore);
	
	if ( Indicators[AutPointer[1]].TIPO == INT )
		Unicode::snprintf(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%d", Indicators[AutPointer[1]].intValore);
	else
		Unicode::snprintfFloat(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%.1f", Indicators[AutPointer[1]].floatValore);
	
	if ( Indicators[AutPointer[2]].TIPO == INT )
		Unicode::snprintf(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%d", Indicators[AutPointer[2]].intValore);
	else
		Unicode::snprintfFloat(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%.1f", Indicators[AutPointer[2]].floatValore);
	
	if ( Indicators[AutPointer[3]].TIPO == INT )
		Unicode::snprintf(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%d", Indicators[AutPointer[3]].intValore);
	else
		Unicode::snprintfFloat(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%.1f", Indicators[AutPointer[3]].floatValore);
	
	if ( Indicators[AutPointer[4]].TIPO == INT )
		Unicode::snprintf(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%d", Indicators[AutPointer[4]].intValore);
	else
		Unicode::snprintfFloat(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%.1f", Indicators[AutPointer[4]].floatValore);
	
	if ( Indicators[AutPointer[5]].TIPO == INT )
		Unicode::snprintf(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%d", Indicators[AutPointer[5]].intValore);
	else
		Unicode::snprintfFloat(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%.1f", Indicators[AutPointer[5]].floatValore);
}

void SETTINGSView::displaySkidpad()
{
	
	switch (box_indicator){
		case 0 :
			if (change_pointer == 1){
				change_pointer = 0;
				SkiPointer[0] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[SkiPointer[0]].NOME, TIT_LEN);
			break;
		case 1 :
			if (change_pointer == 1){
				change_pointer = 0;
				SkiPointer[1] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[SkiPointer[1]].NOME, TIT_LEN);
			break;
		case 2 :
			if (change_pointer == 1){
				change_pointer = 0;
				SkiPointer[2] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[SkiPointer[2]].NOME, TIT_LEN);
			break;
		case 3 :
			if (change_pointer == 1){
				change_pointer = 0;
				SkiPointer[3] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[SkiPointer[3]].NOME, TIT_LEN);
			break;
		case 4 :
			if (change_pointer == 1){
				change_pointer = 0;
				SkiPointer[4] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[SkiPointer[4]].NOME, TIT_LEN);
			break;
		case 5 :
			if (change_pointer == 1){
				change_pointer = 0;
				SkiPointer[5] = pointer_scroll;
			}
			touchgfx::Unicode::strncpy( Title, Indicators[SkiPointer[5]].NOME, TIT_LEN);
			break;
	}
	
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
	
	Unicode::snprintf(textIndTitleCurrentBuffer, TEXTINDTITLECURRENT_SIZE, "%s", Title);
	
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
}

void SETTINGSView::calibrationDisplay()
{
	if (flagCalibration == 1 && calibrationPopUp < (3 * POPUP_TIME)){
		switch (feedbackCalibration){
			case COMMAND_SAVE_APPS0:
				touchgfx::Unicode::strncpy( CurrCalibration, "APPS 0%", 20);
				break;
			case COMMAND_SAVE_APPS100:
				touchgfx::Unicode::strncpy( CurrCalibration, "APPS 100%", 20);
				break;
			case COMMAND_SAVE_SW_ANGLE:
				touchgfx::Unicode::strncpy( CurrCalibration, "SW ANGLE", 20);
				break;
			case COMMAND_SAVE_LINEAR:
				touchgfx::Unicode::strncpy( CurrCalibration, "LINEAR", 20);
				break;
			case COMMAND_SAVE_LOAD_CELL:
				touchgfx::Unicode::strncpy( CurrCalibration, "LOAD CELL", 20);
				break;
			default:
				touchgfx::Unicode::strncpy( CurrCalibration, "NOTHING", 20);
				break;			
		}
		Unicode::snprintf(textDONEBuffer, TEXTDONE_SIZE, "%s", CurrCalibration);	
		textDONE.setVisible(true);
		textDONE.invalidate();
		boxDONE.setVisible(true);
		boxDONE.invalidate();
		calibrationPopUp ++;
	}
	else{
		calibrationPopUp = 0;
		flagCalibration = 0;
		boxDONE.setVisible(false);
		boxDONE.invalidate();
		textDONE.setVisible(false);
		textDONE.invalidate();
	}
}
