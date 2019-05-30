/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/endurance_screen/ENDURANCEViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ENDURANCEViewBase::ENDURANCEViewBase()
{
    background.setPosition(0, 0, 640, 480);
    background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    boxIndicator1.setPosition(8, 8, 150, 85);
    boxIndicator1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator1.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator1.setBorderSize(3);

    boxIndicator2.setPosition(482, 8, 150, 85);
    boxIndicator2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator2.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator2.setBorderSize(3);

    boxIndicator3.setPosition(8, 387, 150, 85);
    boxIndicator3.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator3.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator3.setBorderSize(3);

    boxIndicator4.setPosition(166, 387, 150, 85);
    boxIndicator4.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator4.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator4.setBorderSize(3);

    boxIndicator5.setPosition(324, 387, 150, 85);
    boxIndicator5.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator5.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator5.setBorderSize(3);

    boxIndicator6.setPosition(482, 387, 150, 85);
    boxIndicator6.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicator6.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicator6.setBorderSize(3);

    boxIndicatorGear.setPosition(180, 20, 280, 320);
    boxIndicatorGear.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicatorGear.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicatorGear.setBorderSize(3);

    boxIndicatorTc.setPosition(21, 110, 125, 150);
    boxIndicatorTc.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicatorTc.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicatorTc.setBorderSize(3);

    boxIndicatorMap.setPosition(495, 110, 125, 150);
    boxIndicatorMap.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndicatorMap.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxIndicatorMap.setBorderSize(3);

    textIndTitle1.setPosition(11, 9, 125, 30);
    textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle1.setLinespacing(0);
    Unicode::snprintf(textIndTitle1Buffer, TEXTINDTITLE1_SIZE, "%s", TypedText(T_SINGLEUSEID2).getText());
    textIndTitle1.setWildcard(textIndTitle1Buffer);
    textIndTitle1.setTypedText(TypedText(T_SINGLEUSEID1));

    textIndTitle2.setPosition(486, 9, 125, 30);
    textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle2.setLinespacing(0);
    Unicode::snprintf(textIndTitle2Buffer, TEXTINDTITLE2_SIZE, "%s", TypedText(T_SINGLEUSEID4).getText());
    textIndTitle2.setWildcard(textIndTitle2Buffer);
    textIndTitle2.setTypedText(TypedText(T_SINGLEUSEID3));

    textIndTitle3.setPosition(11, 388, 125, 30);
    textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle3.setLinespacing(0);
    Unicode::snprintf(textIndTitle3Buffer, TEXTINDTITLE3_SIZE, "%s", TypedText(T_SINGLEUSEID8).getText());
    textIndTitle3.setWildcard(textIndTitle3Buffer);
    textIndTitle3.setTypedText(TypedText(T_SINGLEUSEID7));

    textIndTitle4.setPosition(170, 388, 125, 30);
    textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle4.setLinespacing(0);
    Unicode::snprintf(textIndTitle4Buffer, TEXTINDTITLE4_SIZE, "%s", TypedText(T_SINGLEUSEID6).getText());
    textIndTitle4.setWildcard(textIndTitle4Buffer);
    textIndTitle4.setTypedText(TypedText(T_SINGLEUSEID5));

    textIndTitle5.setPosition(328, 388, 125, 30);
    textIndTitle5.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle5.setLinespacing(0);
    Unicode::snprintf(textIndTitle5Buffer, TEXTINDTITLE5_SIZE, "%s", TypedText(T_SINGLEUSEID10).getText());
    textIndTitle5.setWildcard(textIndTitle5Buffer);
    textIndTitle5.setTypedText(TypedText(T_SINGLEUSEID9));

    textIndTitle6.setPosition(486, 388, 125, 30);
    textIndTitle6.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle6.setLinespacing(0);
    Unicode::snprintf(textIndTitle6Buffer, TEXTINDTITLE6_SIZE, "%s", TypedText(T_SINGLEUSEID12).getText());
    textIndTitle6.setWildcard(textIndTitle6Buffer);
    textIndTitle6.setTypedText(TypedText(T_SINGLEUSEID11));

    textIndValue1.setPosition(18, 25, 140, 65);
    textIndValue1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue1.setLinespacing(0);
    Unicode::snprintf(textIndValue1Buffer, TEXTINDVALUE1_SIZE, "%s", TypedText(T_SINGLEUSEID14).getText());
    textIndValue1.setWildcard(textIndValue1Buffer);
    textIndValue1.setTypedText(TypedText(T_SINGLEUSEID13));

    textIndValue2.setPosition(492, 25, 140, 65);
    textIndValue2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue2.setLinespacing(0);
    Unicode::snprintf(textIndValue2Buffer, TEXTINDVALUE2_SIZE, "%s", TypedText(T_SINGLEUSEID16).getText());
    textIndValue2.setWildcard(textIndValue2Buffer);
    textIndValue2.setTypedText(TypedText(T_SINGLEUSEID15));

    textIndValue3.setPosition(18, 404, 140, 65);
    textIndValue3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue3.setLinespacing(0);
    Unicode::snprintf(textIndValue3Buffer, TEXTINDVALUE3_SIZE, "%s", TypedText(T_SINGLEUSEID18).getText());
    textIndValue3.setWildcard(textIndValue3Buffer);
    textIndValue3.setTypedText(TypedText(T_SINGLEUSEID17));

    textIndValue4.setPosition(176, 404, 140, 65);
    textIndValue4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue4.setLinespacing(0);
    Unicode::snprintf(textIndValue4Buffer, TEXTINDVALUE4_SIZE, "%s", TypedText(T_SINGLEUSEID20).getText());
    textIndValue4.setWildcard(textIndValue4Buffer);
    textIndValue4.setTypedText(TypedText(T_SINGLEUSEID19));

    textIndValue5.setPosition(334, 404, 140, 65);
    textIndValue5.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue5.setLinespacing(0);
    Unicode::snprintf(textIndValue5Buffer, TEXTINDVALUE5_SIZE, "%s", TypedText(T_SINGLEUSEID22).getText());
    textIndValue5.setWildcard(textIndValue5Buffer);
    textIndValue5.setTypedText(TypedText(T_SINGLEUSEID21));

    textIndValue6.setPosition(492, 404, 140, 65);
    textIndValue6.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue6.setLinespacing(0);
    Unicode::snprintf(textIndValue6Buffer, TEXTINDVALUE6_SIZE, "%s", TypedText(T_SINGLEUSEID24).getText());
    textIndValue6.setWildcard(textIndValue6Buffer);
    textIndValue6.setTypedText(TypedText(T_SINGLEUSEID23));

    TEXTIndTc.setPosition(22, 170, 38, 29);
    TEXTIndTc.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    TEXTIndTc.setLinespacing(0);
    TEXTIndTc.setTypedText(TypedText(T_SINGLEUSEID27));

    TEXTIndMap.setPosition(497, 170, 59, 27);
    TEXTIndMap.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    TEXTIndMap.setLinespacing(0);
    TEXTIndMap.setTypedText(TypedText(T_SINGLEUSEID28));

    textIndTcValue.setPosition(48, 70, 98, 185);
    textIndTcValue.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTcValue.setLinespacing(0);
    Unicode::snprintf(textIndTcValueBuffer, TEXTINDTCVALUE_SIZE, "%s", TypedText(T_SINGLEUSEID30).getText());
    textIndTcValue.setWildcard(textIndTcValueBuffer);
    textIndTcValue.setTypedText(TypedText(T_SINGLEUSEID29));

    textIndMapValue.setPosition(522, 70, 98, 185);
    textIndMapValue.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndMapValue.setLinespacing(0);
    Unicode::snprintf(textIndMapValueBuffer, TEXTINDMAPVALUE_SIZE, "%s", TypedText(T_SINGLEUSEID32).getText());
    textIndMapValue.setWildcard(textIndMapValueBuffer);
    textIndMapValue.setTypedText(TypedText(T_SINGLEUSEID31));

    TEXTIndAcquisition.setPosition(11, 271, 154, 31);
    TEXTIndAcquisition.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    TEXTIndAcquisition.setLinespacing(0);
    TEXTIndAcquisition.setTypedText(TypedText(T_SINGLEUSEID33));

    boxAcquisition.setPosition(25, 305, 125, 53);
    boxAcquisition.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));

    textIndAcquisitionValue.setPosition(30, 290, 115, 63);
    textIndAcquisitionValue.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textIndAcquisitionValue.setLinespacing(0);
    Unicode::snprintf(textIndAcquisitionValueBuffer, TEXTINDACQUISITIONVALUE_SIZE, "%s", TypedText(T_SINGLEUSEID35).getText());
    textIndAcquisitionValue.setWildcard(textIndAcquisitionValueBuffer);
    textIndAcquisitionValue.setTypedText(TypedText(T_SINGLEUSEID34));

    boxText.setPosition(180, 347, 280, 28);
    boxText.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 234, 0));

    textIndGearValue.setPosition(156, -90, 329, 504);
    textIndGearValue.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndGearValue.setLinespacing(0);
    Unicode::snprintf(textIndGearValueBuffer, TEXTINDGEARVALUE_SIZE, "%s", TypedText(T_SINGLEUSEID278).getText());
    textIndGearValue.setWildcard(textIndGearValueBuffer);
    textIndGearValue.setTypedText(TypedText(T_SINGLEUSEID277));

    TEXTEndurance.setPosition(227, 347, 186, 33);
    TEXTEndurance.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    TEXTEndurance.setLinespacing(0);
    TEXTEndurance.setTypedText(TypedText(T_SINGLEUSEID36));

    boxEntry.setPosition(8, 277, 621, 104);
    boxEntry.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 234, 0));
    boxEntry.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxEntry.setBorderSize(5);

    TEXTEnduranceEntry.setXY(78, 283);
    TEXTEnduranceEntry.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    TEXTEnduranceEntry.setLinespacing(0);
    TEXTEnduranceEntry.setTypedText(TypedText(T_SINGLEUSEID273));

    add(background);
    add(boxIndicator1);
    add(boxIndicator2);
    add(boxIndicator3);
    add(boxIndicator4);
    add(boxIndicator5);
    add(boxIndicator6);
    add(boxIndicatorGear);
    add(boxIndicatorTc);
    add(boxIndicatorMap);
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
    add(TEXTIndTc);
    add(TEXTIndMap);
    add(textIndTcValue);
    add(textIndMapValue);
    add(TEXTIndAcquisition);
    add(boxAcquisition);
    add(textIndAcquisitionValue);
    add(boxText);
    add(textIndGearValue);
    add(TEXTEndurance);
    add(boxEntry);
    add(TEXTEnduranceEntry);
}

void ENDURANCEViewBase::setupScreen()
{

}
