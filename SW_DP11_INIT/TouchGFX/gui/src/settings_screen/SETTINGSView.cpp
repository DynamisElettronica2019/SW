#include <gui/settings_screen/SETTINGSView.hpp>

#include <string.h>

extern char driveMode;
extern Indicator_Value Indicators[N_INDICATORS];
extern int schermata_settings;
extern int box_driveMode;
extern int box_indicator;
extern int pointer_scroll;
extern int change_pointer;
extern int flag_defaultIndicators;

extern uint8_t AccPointer[6];
extern uint8_t EndPointer[6];
extern uint8_t AutPointer[6];
extern uint8_t SkiPointer[6];

extern int currentCalibration, currentIMUCalibration;
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
		currentIMUCalibration = 1;
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
			if (flag_schermata == 0){
				flag_schermata = 1;
				changeSchermata0(true);
				changeSchermata1(false);
				changeSchermata2(false);
				changeSchermata3(false);
			}
			//	SETTINGSView::changeDisplay();		
			boxModeSelected.setVisible(false);
			boxModeSelected.invalidate();
			boxModeSelected.setPosition(15, 23 + (90*box_driveMode), 476, 75);
			boxModeSelected.setVisible(true);
			boxModeSelected.invalidate();
		
			boxCalibrationSelected.invalidate();
			break;
		case 1 :
			if (flag_schermata == 0){
				flag_schermata = 1;
				changeSchermata0(false);
				changeSchermata1(true);
				changeSchermata2(false);
				changeSchermata3(false);
			}		
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
			if (flag_schermata == 0){
				flag_schermata = 1;
				changeSchermata0(false);
				changeSchermata1(false);
				changeSchermata2(true);
				changeSchermata3(false);
			}	
			//	SETTINGSView::changeDisplay();
			boxCalibrationSelected.setVisible(false);
			boxCalibrationSelected.invalidate();
			boxCalibrationSelected.setPosition(58, 10 + (80*(currentCalibration-1)), 535, 63);
			boxCalibrationSelected.setVisible(true);
			boxCalibrationSelected.invalidate();
			SETTINGSView::calibrationDisplay();
			break;
		case 3:
			if (flag_schermata == 0){
				flag_schermata = 1;
				changeSchermata0(false);
				changeSchermata1(false);
				changeSchermata2(false);
				changeSchermata3(true);
			}	
			boxCalibrationImuSelected.setVisible(false);
			boxCalibrationImuSelected.invalidate();
			if( currentIMUCalibration >= 1 && currentIMUCalibration <= 5 )
				boxCalibrationImuSelected.setPosition(2, 135 + (70*(currentIMUCalibration-1)), 300, 50);
			else if ( currentIMUCalibration >= 5 && currentIMUCalibration <= 10 )
				boxCalibrationImuSelected.setPosition(310, 135 + (70*(currentIMUCalibration-5)), 300, 50);
			boxCalibrationImuSelected.setVisible(true);
			boxCalibrationImuSelected.invalidate();
			
//			SETTINGSView::calibrationDisplay();
			if( Indicators[SEL_IMU].intValore == 1 ){
				box1.setVisible(false);
				box1.invalidate();
				box1.setPosition(208, 87, 108, 44);
				textIMU1.setVisible(true);
				textIMU2.setVisible(false);
				box1.setVisible(true);
				box1.invalidate();
				textIMU1.invalidate();
				textIMU2.invalidate();
				
				Unicode::snprintf(textValue1Buffer, TEXTVALUE1_SIZE, "%d", (Indicators[IMU1_INFO].intValore<<7)|(Indicators[IMU1_INFO].intValore<<6));
				Unicode::snprintf(textValue2Buffer, TEXTVALUE2_SIZE, "%d", (Indicators[IMU1_INFO].intValore<<5)|(Indicators[IMU1_INFO].intValore<<4));
				Unicode::snprintf(textValue3Buffer, TEXTVALUE3_SIZE, "%d", (Indicators[IMU1_INFO].intValore<<3)|(Indicators[IMU1_INFO].intValore<<2));
				Unicode::snprintf(textValue4Buffer, TEXTVALUE4_SIZE, "%d", (Indicators[IMU1_INFO].intValore<<1)|(Indicators[IMU1_INFO].intValore));
			
			}else if( Indicators[SEL_IMU].intValore == 2 ){
				box1.setVisible(false);
				box1.invalidate();
				box1.setPosition(327, 87, 108, 44);
				textIMU1.setVisible(false);
				textIMU2.setVisible(true);
				box1.setVisible(true);
				box1.invalidate();
				textIMU1.invalidate();
				textIMU2.invalidate();
				
				Unicode::snprintf(textValue1Buffer, TEXTVALUE1_SIZE, "%d", (Indicators[IMU2_INFO].intValore<<7)|(Indicators[IMU2_INFO].intValore<<6));
				Unicode::snprintf(textValue2Buffer, TEXTVALUE2_SIZE, "%d", (Indicators[IMU2_INFO].intValore<<5)|(Indicators[IMU2_INFO].intValore<<4));
				Unicode::snprintf(textValue3Buffer, TEXTVALUE3_SIZE, "%d", (Indicators[IMU2_INFO].intValore<<3)|(Indicators[IMU2_INFO].intValore<<2));
				Unicode::snprintf(textValue4Buffer, TEXTVALUE4_SIZE, "%d", (Indicators[IMU2_INFO].intValore<<1)|(Indicators[IMU2_INFO].intValore));
			}
			textValue1.invalidate();
			textValue2.invalidate();
			textValue3.invalidate();
			textValue4.invalidate();
			break;
	}
	
}
void SETTINGSView::checkChangeScreen(){
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
				case NOISE_MODE	:
					application().gotoNOISE_MODEScreenNoTransition();
					break;
	}	
}

void SETTINGSView::changeSchermata0(bool visible){
		boxModeSelected.setVisible(visible);
		textACCELERATION.setVisible(visible);
		textENDURANCE.setVisible(visible);
		textAUTOCROSS.setVisible(visible);
		textSKIDPAD.setVisible(visible);
		textCALIBRATION.setVisible(visible);
		textACCELERATION.invalidate();
		textENDURANCE.invalidate();
		textAUTOCROSS.invalidate();
		textSKIDPAD.invalidate();
		boxModeSelected.invalidate();
}

void SETTINGSView::changeSchermata1(bool visible){
		boxIndSelected.setVisible(visible);
		boxIndicator1.setVisible(visible);
		boxIndicator2.setVisible(visible);
		boxIndicator3.setVisible(visible);
		boxIndicator4.setVisible(visible);
		boxIndicator5.setVisible(visible);
		boxIndicator6.setVisible(visible);
		textIndTitle1.setVisible(visible);
		textIndTitle2.setVisible(visible);
		textIndTitle3.setVisible(visible);
		textIndTitle4.setVisible(visible);
		textIndTitle5.setVisible(visible);
		textIndTitle6.setVisible(visible);
		textIndValue1.setVisible(visible);
		textIndValue2.setVisible(visible);
		textIndValue3.setVisible(visible);
		textIndValue4.setVisible(visible);
		textIndValue5.setVisible(visible);
		textIndValue6.setVisible(visible);
		textIndDriveMode.setVisible(visible);
		textIndTitleCurrent.setVisible(visible);
	
		textIndTitle1.invalidate();
		textIndTitle2.invalidate();
		textIndTitle3.invalidate();
		textIndTitle4.invalidate();
		textIndTitle5.invalidate();
		textIndTitle6.invalidate();
		textIndTitleCurrent.invalidate();
		textIndDriveMode.invalidate();
		textIndTitleCurrent.invalidate();
		
		textIndValue1.invalidate();
		textIndValue2.invalidate();
		textIndValue3.invalidate();
		textIndValue4.invalidate();
		textIndValue5.invalidate();
		textIndValue6.invalidate();
		boxIndSelected.invalidate();
}

void SETTINGSView::changeSchermata2(bool visible){
		textLOAD_CELL.setVisible(visible);
		textLINEAR.setVisible(visible);
		textAPPS_0.setVisible(visible);
		textAPPS_100.setVisible(visible);
		textSW_ANGLE.setVisible(visible);
		textIMU.setVisible(visible);
		boxCalibrationSelected.setVisible(visible);
	
		textLOAD_CELL.invalidate();
		textLINEAR.invalidate();
		textAPPS_0.invalidate();
		textAPPS_100.invalidate();
		textSW_ANGLE.invalidate();
		textIMU.invalidate();
		boxCalibrationSelected.invalidate();
}

void SETTINGSView::changeSchermata3(bool visible){
	
		textValue1.setVisible(visible);
		textValue2.setVisible(visible);
		textValue3.setVisible(visible);
		textValue4.setVisible(visible);
		textInd1.setVisible(visible);
		textInd2.setVisible(visible);
		textInd3.setVisible(visible);
		textInd4.setVisible(visible);
		textIMU1.setVisible(visible);
		textIMU2.setVisible(visible);
		textTitle1.setVisible(visible);
		textTitle2.setVisible(visible);
		textTitle3.setVisible(visible);
		textTitle4.setVisible(visible);
		textTitle5.setVisible(visible);
		textTitle6.setVisible(visible);
		textTitle7.setVisible(visible);
		textTitle8.setVisible(visible);
		textTitle9.setVisible(visible);
		textTitle10.setVisible(visible);
		boxCalibrationImuSelected.setVisible(visible);
		box1.setVisible(visible);
		boxCalibration1.setVisible(visible);
		boxCalibration2.setVisible(visible);
		boxCalibration3.setVisible(visible);
		boxCalibration4.setVisible(visible);
	
		textValue1.invalidate();
		textValue2.invalidate();
		textValue3.invalidate();
		textValue4.invalidate();
		textInd1.invalidate();
		textInd2.invalidate();
		textInd3.invalidate();
		textInd4.invalidate();
		textIMU1.invalidate();
		textIMU2.invalidate();
		textTitle1.invalidate();
		textTitle2.invalidate();
		textTitle3.invalidate();
		textTitle4.invalidate();
		textTitle5.invalidate();
		textTitle6.invalidate();
		textTitle7.invalidate();
		textTitle8.invalidate();
		textTitle9.invalidate();
		textTitle10.invalidate();
		boxCalibrationImuSelected.invalidate();
		box1.invalidate();
		boxCalibration1.invalidate();
		boxCalibration2.invalidate();
		boxCalibration3.invalidate();
		boxCalibration4.invalidate();
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
		if ( flag_defaultIndicators == 1 ){
			AccPointer[0] = TH2O;
			AccPointer[1] = VBAT;
			AccPointer[2] = OIL_PRESS;
			AccPointer[3] = OIL_TEMP_IN;
			AccPointer[4] = TPS;
			AccPointer[5] = FUEL_LEVEL;
			flag_defaultIndicators = 0;
		} else {
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
	if ( flag_defaultIndicators == 1 ){
			EndPointer[0] = TH2O;
			EndPointer[1] = VBAT;
			EndPointer[2] = OIL_PRESS;
			EndPointer[3] = OIL_TEMP_IN;
			EndPointer[4] = BRAKE_BIAS;
			EndPointer[5] = FUEL_LEVEL;
			flag_defaultIndicators = 0;
		} else {
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
	if ( flag_defaultIndicators == 1 ){
			AutPointer[0] = TH2O;
			AutPointer[1] = VBAT;
			AutPointer[2] = OIL_PRESS;
			AutPointer[3] = OIL_TEMP_IN;
			AutPointer[4] = BRAKE_BIAS;
			AutPointer[5] = FUEL_LEVEL;
			flag_defaultIndicators = 0;
		} else {
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
	if ( flag_defaultIndicators == 1 ){
			SkiPointer[0] = TH2O;
			SkiPointer[1] = VBAT;
			SkiPointer[2] = OIL_PRESS;
			SkiPointer[3] = OIL_TEMP_IN;
			SkiPointer[4] = TPS;
			SkiPointer[5] = FUEL_LEVEL;
			flag_defaultIndicators = 0;
	} else {
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
