/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/settings_screen/SETTINGSViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SETTINGSViewBase::SETTINGSViewBase()
{
    background.setPosition(0, 0, 640, 480);
    background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    boxIndSelected.setPosition(0, 2, 166, 101);
    boxIndSelected.setVisible(false);
    boxIndSelected.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    boxIndSelected.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndSelected.setBorderSize(2);

    boxIndicator1.setPosition(8, 12, 150, 79);
    boxIndicator1.setVisible(false);
    boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator1.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator1.setBorderSize(2);

    boxIndicator2.setPosition(482, 12, 150, 79);
    boxIndicator2.setVisible(false);
    boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator2.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator2.setBorderSize(2);

    boxIndicator3.setPosition(8, 381, 150, 79);
    boxIndicator3.setVisible(false);
    boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator3.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator3.setBorderSize(2);

    boxIndicator4.setPosition(166, 381, 150, 79);
    boxIndicator4.setVisible(false);
    boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator4.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator4.setBorderSize(2);

    boxIndicator5.setPosition(324, 381, 150, 79);
    boxIndicator5.setVisible(false);
    boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator5.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator5.setBorderSize(2);

    boxIndicator6.setPosition(482, 381, 150, 79);
    boxIndicator6.setVisible(false);
    boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator6.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator6.setBorderSize(2);

    textIndTitle1.setPosition(11, 9, 125, 30);
    textIndTitle1.setVisible(false);
    textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle1.setLinespacing(0);
    Unicode::snprintf(textIndTitle1Buffer, TEXTINDTITLE1_SIZE, "%s", TypedText(T_SINGLEUSEID157).getText());
    textIndTitle1.setWildcard(textIndTitle1Buffer);
    textIndTitle1.setTypedText(TypedText(T_SINGLEUSEID156));

    textIndTitle2.setPosition(486, 9, 125, 30);
    textIndTitle2.setVisible(false);
    textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle2.setLinespacing(0);
    Unicode::snprintf(textIndTitle2Buffer, TEXTINDTITLE2_SIZE, "%s", TypedText(T_SINGLEUSEID159).getText());
    textIndTitle2.setWildcard(textIndTitle2Buffer);
    textIndTitle2.setTypedText(TypedText(T_SINGLEUSEID158));

    textIndTitle3.setPosition(11, 381, 125, 30);
    textIndTitle3.setVisible(false);
    textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle3.setLinespacing(0);
    Unicode::snprintf(textIndTitle3Buffer, TEXTINDTITLE3_SIZE, "%s", TypedText(T_SINGLEUSEID161).getText());
    textIndTitle3.setWildcard(textIndTitle3Buffer);
    textIndTitle3.setTypedText(TypedText(T_SINGLEUSEID160));

    textIndTitle4.setPosition(170, 381, 125, 30);
    textIndTitle4.setVisible(false);
    textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle4.setLinespacing(0);
    Unicode::snprintf(textIndTitle4Buffer, TEXTINDTITLE4_SIZE, "%s", TypedText(T_SINGLEUSEID163).getText());
    textIndTitle4.setWildcard(textIndTitle4Buffer);
    textIndTitle4.setTypedText(TypedText(T_SINGLEUSEID162));

    textIndTitle5.setPosition(328, 381, 125, 30);
    textIndTitle5.setVisible(false);
    textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle5.setLinespacing(0);
    Unicode::snprintf(textIndTitle5Buffer, TEXTINDTITLE5_SIZE, "%s", TypedText(T_SINGLEUSEID165).getText());
    textIndTitle5.setWildcard(textIndTitle5Buffer);
    textIndTitle5.setTypedText(TypedText(T_SINGLEUSEID164));

    textIndTitle6.setPosition(486, 381, 125, 30);
    textIndTitle6.setVisible(false);
    textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle6.setLinespacing(0);
    Unicode::snprintf(textIndTitle6Buffer, TEXTINDTITLE6_SIZE, "%s", TypedText(T_SINGLEUSEID167).getText());
    textIndTitle6.setWildcard(textIndTitle6Buffer);
    textIndTitle6.setTypedText(TypedText(T_SINGLEUSEID166));

    textIndValue1.setPosition(18, 24, 140, 65);
    textIndValue1.setVisible(false);
    textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue1.setLinespacing(0);
    Unicode::snprintf(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%s", TypedText(T_SINGLEUSEID169).getText());
    textIndValue1.setWildcard(textIndValue1Buffer);
    textIndValue1.setTypedText(TypedText(T_SINGLEUSEID168));

    textIndValue2.setPosition(492, 23, 140, 65);
    textIndValue2.setVisible(false);
    textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue2.setLinespacing(0);
    Unicode::snprintf(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%s", TypedText(T_SINGLEUSEID171).getText());
    textIndValue2.setWildcard(textIndValue2Buffer);
    textIndValue2.setTypedText(TypedText(T_SINGLEUSEID170));

    textIndValue3.setPosition(18, 394, 140, 65);
    textIndValue3.setVisible(false);
    textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue3.setLinespacing(0);
    Unicode::snprintf(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%s", TypedText(T_SINGLEUSEID173).getText());
    textIndValue3.setWildcard(textIndValue3Buffer);
    textIndValue3.setTypedText(TypedText(T_SINGLEUSEID172));

    textIndValue4.setPosition(176, 394, 140, 65);
    textIndValue4.setVisible(false);
    textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue4.setLinespacing(0);
    Unicode::snprintf(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%s", TypedText(T_SINGLEUSEID175).getText());
    textIndValue4.setWildcard(textIndValue4Buffer);
    textIndValue4.setTypedText(TypedText(T_SINGLEUSEID174));

    textIndValue5.setPosition(334, 394, 140, 65);
    textIndValue5.setVisible(false);
    textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue5.setLinespacing(0);
    Unicode::snprintf(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%s", TypedText(T_SINGLEUSEID177).getText());
    textIndValue5.setWildcard(textIndValue5Buffer);
    textIndValue5.setTypedText(TypedText(T_SINGLEUSEID176));

    textIndValue6.setPosition(492, 394, 140, 65);
    textIndValue6.setVisible(false);
    textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue6.setLinespacing(0);
    Unicode::snprintf(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%s", TypedText(T_SINGLEUSEID179).getText());
    textIndValue6.setWildcard(textIndValue6Buffer);
    textIndValue6.setTypedText(TypedText(T_SINGLEUSEID178));

    textIndDriveMode.setPosition(156, 34, 328, 44);
    textIndDriveMode.setVisible(false);
    textIndDriveMode.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndDriveMode.setLinespacing(0);
    Unicode::snprintf(textIndDriveModeBuffer, TEXTINDDRIVEMODE_SIZE, "%s", TypedText(T_SINGLEUSEID186).getText());
    textIndDriveMode.setWildcard(textIndDriveModeBuffer);
    textIndDriveMode.setTypedText(TypedText(T_SINGLEUSEID180));

    textIndTitleCurrent.setPosition(124, 206, 393, 66);
    textIndTitleCurrent.setVisible(false);
    textIndTitleCurrent.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitleCurrent.setLinespacing(0);
    Unicode::snprintf(textIndTitleCurrentBuffer, TEXTINDTITLECURRENT_SIZE, "%s", TypedText(T_SINGLEUSEID185).getText());
    textIndTitleCurrent.setWildcard(textIndTitleCurrentBuffer);
    textIndTitleCurrent.setTypedText(TypedText(T_SINGLEUSEID182));

    boxCalibrationSelected.setPosition(53, 4, 535, 68);
    boxCalibrationSelected.setVisible(false);
    boxCalibrationSelected.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxCalibrationSelected.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    boxCalibrationSelected.setBorderSize(6);

    textAPPS_0.setXY(196, 3);
    textAPPS_0.setVisible(false);
    textAPPS_0.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textAPPS_0.setLinespacing(0);
    textAPPS_0.setTypedText(TypedText(T_SINGLEUSEID364));

    textAPPS_100.setXY(162, 83);
    textAPPS_100.setVisible(false);
    textAPPS_100.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textAPPS_100.setLinespacing(0);
    textAPPS_100.setTypedText(TypedText(T_SINGLEUSEID365));

    textSW_ANGLE.setXY(169, 163);
    textSW_ANGLE.setVisible(false);
    textSW_ANGLE.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textSW_ANGLE.setLinespacing(0);
    textSW_ANGLE.setTypedText(TypedText(T_SINGLEUSEID366));

    textLINEAR.setXY(218, 243);
    textLINEAR.setVisible(false);
    textLINEAR.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textLINEAR.setLinespacing(0);
    textLINEAR.setTypedText(TypedText(T_SINGLEUSEID367));

    textLOAD_CELL.setXY(167, 323);
    textLOAD_CELL.setVisible(false);
    textLOAD_CELL.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textLOAD_CELL.setLinespacing(0);
    textLOAD_CELL.setTypedText(TypedText(T_SINGLEUSEID368));

    textIMU.setXY(262, 403);
    textIMU.setVisible(false);
    textIMU.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIMU.setLinespacing(0);
    textIMU.setTypedText(TypedText(T_SINGLEUSEID415));

    boxCalibration1.setPosition(0, 0, 165, 81);
    boxCalibration1.setVisible(false);
    boxCalibration1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxCalibration1.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxCalibration1.setBorderSize(5);

    boxCalibration2.setPosition(160, 0, 168, 81);
    boxCalibration2.setVisible(false);
    boxCalibration2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxCalibration2.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxCalibration2.setBorderSize(5);

    boxCalibration3.setPosition(320, 0, 160, 81);
    boxCalibration3.setVisible(false);
    boxCalibration3.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxCalibration3.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxCalibration3.setBorderSize(5);

    boxCalibration4.setPosition(473, 0, 167, 81);
    boxCalibration4.setVisible(false);
    boxCalibration4.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxCalibration4.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxCalibration4.setBorderSize(5);

    boxCalibrationImuSelected.setPosition(2, 135, 322, 50);
    boxCalibrationImuSelected.setVisible(false);
    boxCalibrationImuSelected.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxCalibrationImuSelected.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    boxCalibrationImuSelected.setBorderSize(5);

    textTitle1.setXY(8, 140);
    textTitle1.setVisible(false);
    textTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTitle1.setLinespacing(0);
    textTitle1.setTypedText(TypedText(T_SINGLEUSEID416));

    textTitle2.setXY(8, 210);
    textTitle2.setVisible(false);
    textTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTitle2.setLinespacing(0);
    textTitle2.setTypedText(TypedText(T_SINGLEUSEID418));

    textTitle3.setXY(8, 280);
    textTitle3.setVisible(false);
    textTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTitle3.setLinespacing(0);
    textTitle3.setTypedText(TypedText(T_SINGLEUSEID420));

    textTitle4.setXY(9, 350);
    textTitle4.setVisible(false);
    textTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTitle4.setLinespacing(0);
    textTitle4.setTypedText(TypedText(T_SINGLEUSEID422));

    textTitle5.setXY(5, 420);
    textTitle5.setVisible(false);
    textTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTitle5.setLinespacing(0);
    textTitle5.setTypedText(TypedText(T_SINGLEUSEID424));

    textTitle6.setXY(327, 140);
    textTitle6.setVisible(false);
    textTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTitle6.setLinespacing(0);
    textTitle6.setTypedText(TypedText(T_SINGLEUSEID425));

    textTitle7.setXY(327, 210);
    textTitle7.setVisible(false);
    textTitle7.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTitle7.setLinespacing(0);
    textTitle7.setTypedText(TypedText(T_SINGLEUSEID426));

    textTitle8.setXY(327, 277);
    textTitle8.setVisible(false);
    textTitle8.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTitle8.setLinespacing(0);
    textTitle8.setTypedText(TypedText(T_SINGLEUSEID427));

    textTitle9.setXY(328, 350);
    textTitle9.setVisible(false);
    textTitle9.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTitle9.setLinespacing(0);
    textTitle9.setTypedText(TypedText(T_SINGLEUSEID428));

    textTitle10.setXY(324, 420);
    textTitle10.setVisible(false);
    textTitle10.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTitle10.setLinespacing(0);
    textTitle10.setTypedText(TypedText(T_SINGLEUSEID429));

    box1.setPosition(208, 87, 108, 44);
    box1.setVisible(false);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(30, 255, 0));

    textIMU1.setXY(216, 90);
    textIMU1.setVisible(false);
    textIMU1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textIMU1.setLinespacing(0);
    textIMU1.setTypedText(TypedText(T_SINGLEUSEID430));

    textIMU2.setXY(335, 90);
    textIMU2.setVisible(false);
    textIMU2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textIMU2.setLinespacing(0);
    textIMU2.setTypedText(TypedText(T_SINGLEUSEID431));

    textInd1.setXY(14, 6);
    textInd1.setVisible(false);
    textInd1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textInd1.setLinespacing(0);
    textInd1.setTypedText(TypedText(T_SINGLEUSEID432));

    textInd2.setXY(173, 6);
    textInd2.setVisible(false);
    textInd2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textInd2.setLinespacing(0);
    textInd2.setTypedText(TypedText(T_SINGLEUSEID433));

    textInd3.setXY(335, 6);
    textInd3.setVisible(false);
    textInd3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textInd3.setLinespacing(0);
    textInd3.setTypedText(TypedText(T_SINGLEUSEID434));

    textInd4.setXY(486, 6);
    textInd4.setVisible(false);
    textInd4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textInd4.setLinespacing(0);
    textInd4.setTypedText(TypedText(T_SINGLEUSEID435));

    textValue1.setPosition(49, -15, 95, 85);
    textValue1.setVisible(false);
    textValue1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textValue1.setLinespacing(0);
    Unicode::snprintf(textValue1Buffer, TEXTVALUE1_SIZE, "%s", TypedText(T_SINGLEUSEID437).getText());
    textValue1.setWildcard(textValue1Buffer);
    textValue1.setTypedText(TypedText(T_SINGLEUSEID436));

    textValue2.setPosition(217, -15, 95, 85);
    textValue2.setVisible(false);
    textValue2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textValue2.setLinespacing(0);
    Unicode::snprintf(textValue2Buffer, TEXTVALUE2_SIZE, "%s", TypedText(T_SINGLEUSEID439).getText());
    textValue2.setWildcard(textValue2Buffer);
    textValue2.setTypedText(TypedText(T_SINGLEUSEID438));

    textValue3.setPosition(372, -15, 95, 85);
    textValue3.setVisible(false);
    textValue3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textValue3.setLinespacing(0);
    Unicode::snprintf(textValue3Buffer, TEXTVALUE3_SIZE, "%s", TypedText(T_SINGLEUSEID441).getText());
    textValue3.setWildcard(textValue3Buffer);
    textValue3.setTypedText(TypedText(T_SINGLEUSEID440));

    textValue4.setPosition(518, -15, 95, 85);
    textValue4.setVisible(false);
    textValue4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textValue4.setLinespacing(0);
    Unicode::snprintf(textValue4Buffer, TEXTVALUE4_SIZE, "%s", TypedText(T_SINGLEUSEID443).getText());
    textValue4.setWildcard(textValue4Buffer);
    textValue4.setTypedText(TypedText(T_SINGLEUSEID442));

    boxDONE.setPosition(23, 188, 595, 104);
    boxDONE.setVisible(false);
    boxDONE.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

    textDONE.setPosition(38, 202, 564, 76);
    textDONE.setVisible(false);
    textDONE.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textDONE.setLinespacing(0);
    Unicode::snprintf(textDONEBuffer, TEXTDONE_SIZE, "%s", TypedText(T_SINGLEUSEID370).getText());
    textDONE.setWildcard(textDONEBuffer);
    textDONE.setTypedText(TypedText(T_SINGLEUSEID369));

    boxModeSelected.setPosition(10, 15, 460, 83);
    boxModeSelected.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxModeSelected.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    boxModeSelected.setBorderSize(6);

    textACCELERATION.setPosition(20, 22, 450, 75);
    textACCELERATION.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textACCELERATION.setLinespacing(0);
    textACCELERATION.setTypedText(TypedText(T_SINGLEUSEID152));

    textENDURANCE.setPosition(20, 112, 450, 75);
    textENDURANCE.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textENDURANCE.setLinespacing(0);
    textENDURANCE.setTypedText(TypedText(T_SINGLEUSEID153));

    textAUTOCROSS.setPosition(20, 202, 450, 75);
    textAUTOCROSS.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textAUTOCROSS.setLinespacing(0);
    textAUTOCROSS.setTypedText(TypedText(T_SINGLEUSEID154));

    textSKIDPAD.setPosition(20, 292, 450, 75);
    textSKIDPAD.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textSKIDPAD.setLinespacing(0);
    textSKIDPAD.setTypedText(TypedText(T_SINGLEUSEID155));

    textCALIBRATION.setPosition(20, 382, 450, 75);
    textCALIBRATION.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textCALIBRATION.setLinespacing(0);
    textCALIBRATION.setTypedText(TypedText(T_SINGLEUSEID363));

    boxDCUdead.setPosition(66, 162, 523, 174);
    boxDCUdead.setVisible(false);
    boxDCUdead.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    boxDCUdead.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxDCUdead.setBorderSize(5);

    textDCUdead.setXY(86, 189);
    textDCUdead.setVisible(false);
    textDCUdead.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textDCUdead.setLinespacing(0);
    textDCUdead.setTypedText(TypedText(T_SINGLEUSEID375));

    boxSW.setPosition(537, 387, 93, 84);
    boxSW.setColor(touchgfx::Color::getColorFrom24BitRGB(9, 0, 140));
    boxSW.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxSW.setBorderSize(5);

    textSW.setPosition(554, 393, 61, 26);
    textSW.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textSW.setLinespacing(0);
    textSW.setTypedText(TypedText(T_SINGLEUSEID451));

    textSWnumber.setXY(571, 419);
    textSWnumber.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textSWnumber.setLinespacing(0);
    Unicode::snprintf(textSWnumberBuffer, TEXTSWNUMBER_SIZE, "%s", TypedText(T_SINGLEUSEID453).getText());
    textSWnumber.setWildcard(textSWnumberBuffer);
    textSWnumber.resizeToCurrentText();
    textSWnumber.setTypedText(TypedText(T_SINGLEUSEID452));

    add(background);
    add(boxIndSelected);
    add(boxIndicator1);
    add(boxIndicator2);
    add(boxIndicator3);
    add(boxIndicator4);
    add(boxIndicator5);
    add(boxIndicator6);
    add(textIndTitle1);
    add(textIndTitle2);
    add(textIndTitle3);
    add(textIndTitle4);
    add(textIndTitle5);
    add(textIndTitle6);
    add(textIndValue1);
    add(textIndValue2);
    add(textIndValue3);
    add(textIndValue4);
    add(textIndValue5);
    add(textIndValue6);
    add(textIndDriveMode);
    add(textIndTitleCurrent);
    add(boxCalibrationSelected);
    add(textAPPS_0);
    add(textAPPS_100);
    add(textSW_ANGLE);
    add(textLINEAR);
    add(textLOAD_CELL);
    add(textIMU);
    add(boxCalibration1);
    add(boxCalibration2);
    add(boxCalibration3);
    add(boxCalibration4);
    add(boxCalibrationImuSelected);
    add(textTitle1);
    add(textTitle2);
    add(textTitle3);
    add(textTitle4);
    add(textTitle5);
    add(textTitle6);
    add(textTitle7);
    add(textTitle8);
    add(textTitle9);
    add(textTitle10);
    add(box1);
    add(textIMU1);
    add(textIMU2);
    add(textInd1);
    add(textInd2);
    add(textInd3);
    add(textInd4);
    add(textValue1);
    add(textValue2);
    add(textValue3);
    add(textValue4);
    add(boxDONE);
    add(textDONE);
    add(boxModeSelected);
    add(textACCELERATION);
    add(textENDURANCE);
    add(textAUTOCROSS);
    add(textSKIDPAD);
    add(textCALIBRATION);
    add(boxDCUdead);
    add(textDCUdead);
    add(boxSW);
    add(textSW);
    add(textSWnumber);
}

void SETTINGSViewBase::setupScreen()
{

}
