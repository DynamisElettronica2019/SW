/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/autocross_screen/AUTOCROSSViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

AUTOCROSSViewBase::AUTOCROSSViewBase()
{
    background.setPosition(0, 0, 640, 480);
    background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    boxTraction.setPosition(33, 109, 150, 193);
    boxTraction.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxTraction.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxTraction.setBorderSize(3);

    textTractionValue.setPosition(62, 88, 93, 197);
    textTractionValue.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTractionValue.setLinespacing(0);
    Unicode::snprintf(textTractionValueBuffer, TEXTTRACTIONVALUE_SIZE, "%s", TypedText(T_SINGLEUSEID536).getText());
    textTractionValue.setWildcard(textTractionValueBuffer);
    textTractionValue.setTypedText(TypedText(T_SINGLEUSEID535));

    textTraction.setXY(95, 273);
    textTraction.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTraction.setLinespacing(0);
    textTraction.setTypedText(TypedText(T_SINGLEUSEID539));

    boxTorque.setPosition(224, 55, 193, 248);
    boxTorque.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxTorque.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxTorque.setBorderSize(3);

    textTorqueValue.setPosition(224, -24, 193, 315);
    textTorqueValue.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTorqueValue.setLinespacing(0);
    Unicode::snprintf(textTorqueValueBuffer, TEXTTORQUEVALUE_SIZE, "%s", TypedText(T_SINGLEUSEID538).getText());
    textTorqueValue.setWildcard(textTorqueValueBuffer);
    textTorqueValue.setTypedText(TypedText(T_SINGLEUSEID537));

    textTorque.setXY(302, 273);
    textTorque.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textTorque.setLinespacing(0);
    textTorque.setTypedText(TypedText(T_SINGLEUSEID540));

    boxMaxPower.setPosition(458, 165, 150, 138);
    boxMaxPower.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxMaxPower.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxMaxPower.setBorderSize(3);

    textMaxPowerValue.setPosition(463, 171, 140, 92);
    textMaxPowerValue.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textMaxPowerValue.setLinespacing(0);
    Unicode::snprintf(textMaxPowerValueBuffer, TEXTMAXPOWERVALUE_SIZE, "%s", TypedText(T_SINGLEUSEID618).getText());
    textMaxPowerValue.setWildcard(textMaxPowerValueBuffer);
    textMaxPowerValue.setTypedText(TypedText(T_SINGLEUSEID617));

    textMaxPower.setXY(492, 273);
    textMaxPower.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textMaxPower.setLinespacing(0);
    textMaxPower.setTypedText(TypedText(T_SINGLEUSEID619));

    boxMap.setPosition(458, 109, 150, 45);
    boxMap.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxMap.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxMap.setBorderSize(3);

    textMap.setXY(468, 116);
    textMap.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textMap.setLinespacing(0);
    textMap.setTypedText(TypedText(T_SINGLEUSEID620));

    textMapValue.setPosition(536, 106, 76, 51);
    textMapValue.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textMapValue.setLinespacing(0);
    Unicode::snprintf(textMapValueBuffer, TEXTMAPVALUE_SIZE, "%s", TypedText(T_SINGLEUSEID685).getText());
    textMapValue.setWildcard(textMapValueBuffer);
    textMapValue.setTypedText(TypedText(T_SINGLEUSEID621));

    boxHV.setPosition(224, 319, 193, 45);
    boxHV.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxHV.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxHV.setBorderSize(3);

    textVBAT.setXY(230, 326);
    textVBAT.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textVBAT.setLinespacing(0);
    textVBAT.setTypedText(TypedText(T_SINGLEUSEID628));

    textVBATValue.setPosition(307, 314, 104, 47);
    textVBATValue.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textVBATValue.setLinespacing(0);
    Unicode::snprintf(textVBATValueBuffer, TEXTVBATVALUE_SIZE, "%s", TypedText(T_SINGLEUSEID630).getText());
    textVBATValue.setWildcard(textVBATValueBuffer);
    textVBATValue.setTypedText(TypedText(T_SINGLEUSEID629));

    boxMode.setPosition(33, 319, 150, 45);
    boxMode.setColor(touchgfx::Color::getColorFrom24BitRGB(6, 0, 255));
    boxMode.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxMode.setBorderSize(3);

    textMode.setPosition(35, 315, 147, 45);
    textMode.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textMode.setLinespacing(0);
    textMode.setTypedText(TypedText(T_SINGLEUSEID622));

    boxSOCBackground.setPosition(9, 8, 622, 27);
    boxSOCBackground.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxSOCBackground.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxSOCBackground.setBorderSize(2);

    barSOC.setPosition(11, 10, 619, 23);
    barSOC.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
    barSOC.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
    barSOC.setBorderSize(0);

    boxIndicator1.setPosition(8, 387, 150, 85);
    boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator1.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator1.setBorderSize(3);

    boxIndicator2.setPosition(166, 387, 150, 85);
    boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator2.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator2.setBorderSize(3);

    boxIndicator3.setPosition(324, 387, 150, 85);
    boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator3.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator3.setBorderSize(3);

    boxIndicator4.setPosition(482, 387, 150, 85);
    boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator4.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator4.setBorderSize(3);

    textIndicator1.setPosition(11, 388, 125, 30);
    textIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndicator1.setLinespacing(0);
    Unicode::snprintf(textIndicator1Buffer, TEXTINDICATOR1_SIZE, "%s", TypedText(T_SINGLEUSEID554).getText());
    textIndicator1.setWildcard(textIndicator1Buffer);
    textIndicator1.setTypedText(TypedText(T_SINGLEUSEID553));

    textIndicator2.setPosition(168, 388, 125, 30);
    textIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndicator2.setLinespacing(0);
    Unicode::snprintf(textIndicator2Buffer, TEXTINDICATOR2_SIZE, "%s", TypedText(T_SINGLEUSEID556).getText());
    textIndicator2.setWildcard(textIndicator2Buffer);
    textIndicator2.setTypedText(TypedText(T_SINGLEUSEID555));

    textIndicator3.setPosition(327, 388, 125, 30);
    textIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndicator3.setLinespacing(0);
    Unicode::snprintf(textIndicator3Buffer, TEXTINDICATOR3_SIZE, "%s", TypedText(T_SINGLEUSEID558).getText());
    textIndicator3.setWildcard(textIndicator3Buffer);
    textIndicator3.setTypedText(TypedText(T_SINGLEUSEID557));

    textIndicator4.setPosition(484, 388, 125, 30);
    textIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndicator4.setLinespacing(0);
    Unicode::snprintf(textIndicator4Buffer, TEXTINDICATOR4_SIZE, "%s", TypedText(T_SINGLEUSEID560).getText());
    textIndicator4.setWildcard(textIndicator4Buffer);
    textIndicator4.setTypedText(TypedText(T_SINGLEUSEID559));

    textIndicatorValue1.setPosition(18, 404, 140, 65);
    textIndicatorValue1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndicatorValue1.setLinespacing(0);
    Unicode::snprintf(textIndicatorValue1Buffer, TEXTINDICATORVALUE1_SIZE, "%s", TypedText(T_SINGLEUSEID562).getText());
    textIndicatorValue1.setWildcard(textIndicatorValue1Buffer);
    textIndicatorValue1.setTypedText(TypedText(T_SINGLEUSEID561));

    textIndicatorValue2.setPosition(176, 404, 140, 65);
    textIndicatorValue2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndicatorValue2.setLinespacing(0);
    Unicode::snprintf(textIndicatorValue2Buffer, TEXTINDICATORVALUE2_SIZE, "%s", TypedText(T_SINGLEUSEID564).getText());
    textIndicatorValue2.setWildcard(textIndicatorValue2Buffer);
    textIndicatorValue2.setTypedText(TypedText(T_SINGLEUSEID563));

    textIndicatorValue3.setPosition(334, 404, 140, 65);
    textIndicatorValue3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndicatorValue3.setLinespacing(0);
    Unicode::snprintf(textIndicatorValue3Buffer, TEXTINDICATORVALUE3_SIZE, "%s", TypedText(T_SINGLEUSEID566).getText());
    textIndicatorValue3.setWildcard(textIndicatorValue3Buffer);
    textIndicatorValue3.setTypedText(TypedText(T_SINGLEUSEID565));

    textIndicatorValue4.setPosition(492, 404, 140, 65);
    textIndicatorValue4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndicatorValue4.setLinespacing(0);
    Unicode::snprintf(textIndicatorValue4Buffer, TEXTINDICATORVALUE4_SIZE, "%s", TypedText(T_SINGLEUSEID568).getText());
    textIndicatorValue4.setWildcard(textIndicatorValue4Buffer);
    textIndicatorValue4.setTypedText(TypedText(T_SINGLEUSEID567));

    boxSD.setPosition(535, 319, 73, 45);
    boxSD.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    boxSD.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxSD.setBorderSize(3);

    textSD.setPosition(542, 321, 57, 35);
    textSD.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textSD.setLinespacing(0);
    textSD.setTypedText(TypedText(T_SINGLEUSEID623));

    boxUSB.setPosition(458, 319, 70, 45);
    boxUSB.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    boxUSB.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxUSB.setBorderSize(3);

    textUSB.setPosition(451, 323, 84, 35);
    textUSB.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textUSB.setLinespacing(0);
    textUSB.setTypedText(TypedText(T_SINGLEUSEID624));

    boxTS.setPosition(458, 54, 150, 45);
    boxTS.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
    boxTS.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxTS.setBorderSize(3);

    textTS.setPosition(463, 54, 141, 44);
    textTS.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textTS.setLinespacing(0);
    Unicode::snprintf(textTSBuffer, TEXTTS_SIZE, "%s", TypedText(T_SINGLEUSEID626).getText());
    textTS.setWildcard(textTSBuffer);
    textTS.setTypedText(TypedText(T_SINGLEUSEID625));

    boxRGN.setPosition(33, 54, 150, 45);
    boxRGN.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    boxRGN.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxRGN.setBorderSize(3);

    textRGN.setPosition(36, 54, 140, 45);
    textRGN.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textRGN.setLinespacing(0);
    textRGN.setTypedText(TypedText(T_SINGLEUSEID627));

    boxRTD.setPosition(43, 60, 557, 363);
    boxRTD.setVisible(false);
    boxRTD.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    boxRTD.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxRTD.setBorderSize(7);

    textRTD.setPosition(33, 139, 578, 176);
    textRTD.setVisible(false);
    textRTD.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textRTD.setLinespacing(0);
    textRTD.setTypedText(TypedText(T_SINGLEUSEID631));

    boxEntry.setPosition(8, 263, 625, 122);
    boxEntry.setColor(touchgfx::Color::getColorFrom24BitRGB(6, 0, 255));
    boxEntry.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxEntry.setBorderSize(5);

    textEntry.setXY(108, 276);
    textEntry.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textEntry.setLinespacing(0);
    textEntry.setTypedText(TypedText(T_SINGLEUSEID633));

    boxDCU.setPosition(66, 162, 523, 174);
    boxDCU.setVisible(false);
    boxDCU.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    boxDCU.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxDCU.setBorderSize(5);

    textDCU.setXY(84, 189);
    textDCU.setVisible(false);
    textDCU.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textDCU.setLinespacing(0);
    textDCU.setTypedText(TypedText(T_SINGLEUSEID676));

    add(background);
    add(boxTraction);
    add(textTractionValue);
    add(textTraction);
    add(boxTorque);
    add(textTorqueValue);
    add(textTorque);
    add(boxMaxPower);
    add(textMaxPowerValue);
    add(textMaxPower);
    add(boxMap);
    add(textMap);
    add(textMapValue);
    add(boxHV);
    add(textVBAT);
    add(textVBATValue);
    add(boxMode);
    add(textMode);
    add(boxSOCBackground);
    add(barSOC);
    add(boxIndicator1);
    add(boxIndicator2);
    add(boxIndicator3);
    add(boxIndicator4);
    add(textIndicator1);
    add(textIndicator2);
    add(textIndicator3);
    add(textIndicator4);
    add(textIndicatorValue1);
    add(textIndicatorValue2);
    add(textIndicatorValue3);
    add(textIndicatorValue4);
    add(boxSD);
    add(textSD);
    add(boxUSB);
    add(textUSB);
    add(boxTS);
    add(textTS);
    add(boxRGN);
    add(textRGN);
    add(boxRTD);
    add(textRTD);
    add(boxEntry);
    add(textEntry);
    add(boxDCU);
    add(textDCU);
}

void AUTOCROSSViewBase::setupScreen()
{

}
