/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SKIDPAD_VIEW_BASE_HPP
#define SKIDPAD_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/skidpad_screen/SKIDPADPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class SKIDPADViewBase : public touchgfx::View<SKIDPADPresenter>
{
public:
    SKIDPADViewBase();
    virtual ~SKIDPADViewBase() {}

    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box background;
    touchgfx::BoxWithBorder boxIndicator1;
    touchgfx::BoxWithBorder boxIndicator2;
    touchgfx::BoxWithBorder boxIndicator3;
    touchgfx::BoxWithBorder boxIndicator4;
    touchgfx::BoxWithBorder boxIndicator5;
    touchgfx::BoxWithBorder boxIndicator6;
    touchgfx::BoxWithBorder boxIndicatorGear;
    touchgfx::BoxWithBorder boxIndicatorMap;
    touchgfx::BoxWithBorder boxIndicatorTc;
    touchgfx::TextAreaWithOneWildcard textIndTitle1;
    touchgfx::TextAreaWithOneWildcard textIndTitle2;
    touchgfx::TextAreaWithOneWildcard textIndTitle3;
    touchgfx::TextAreaWithOneWildcard textIndTitle4;
    touchgfx::TextAreaWithOneWildcard textIndTitle5;
    touchgfx::TextAreaWithOneWildcard textIndTitle6;
    touchgfx::TextAreaWithOneWildcard textIndValue1;
    touchgfx::TextAreaWithOneWildcard textIndValue2;
    touchgfx::TextAreaWithOneWildcard textIndValue3;
    touchgfx::TextAreaWithOneWildcard textIndValue4;
    touchgfx::TextAreaWithOneWildcard textIndValue5;
    touchgfx::TextAreaWithOneWildcard textIndValue6;
    touchgfx::TextArea TEXTIndMap;
    touchgfx::TextArea TEXTIndTc;
    touchgfx::TextAreaWithOneWildcard textIndMapValue;
    touchgfx::TextAreaWithOneWildcard textIndTcValue;
    touchgfx::TextArea TEXTIndAcquisition;
    touchgfx::Box boxAcquisition;
    touchgfx::TextAreaWithOneWildcard textIndAcquisitionValue;
    touchgfx::Box boxText;
    touchgfx::TextArea TEXTSkidpad;
    touchgfx::TextAreaWithOneWildcard textIndGearValue;
    touchgfx::BoxWithBorder boxDCUdead;
    touchgfx::TextArea textDCUdead;
    touchgfx::BoxWithBorder boxAntistall;
    touchgfx::TextArea textAntistall;
    touchgfx::TextArea TEXTRpmLimiter;
    touchgfx::TextAreaWithOneWildcard textRpmLimiterValue;
    touchgfx::BoxWithBorder boxEntry;
    touchgfx::TextArea TEXTSkidpadEntry;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTINDTITLE1_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle1Buffer[TEXTINDTITLE1_SIZE];
    static const uint16_t TEXTINDTITLE2_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle2Buffer[TEXTINDTITLE2_SIZE];
    static const uint16_t TEXTINDTITLE3_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle3Buffer[TEXTINDTITLE3_SIZE];
    static const uint16_t TEXTINDTITLE4_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle4Buffer[TEXTINDTITLE4_SIZE];
    static const uint16_t TEXTINDTITLE5_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle5Buffer[TEXTINDTITLE5_SIZE];
    static const uint16_t TEXTINDTITLE6_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle6Buffer[TEXTINDTITLE6_SIZE];
    static const uint16_t TEXTINDVALUE1_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue1Buffer[TEXTINDVALUE1_SIZE];
    static const uint16_t TEXTINDVALUE2_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue2Buffer[TEXTINDVALUE2_SIZE];
    static const uint16_t TEXTINDVALUE3_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue3Buffer[TEXTINDVALUE3_SIZE];
    static const uint16_t TEXTINDVALUE4_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue4Buffer[TEXTINDVALUE4_SIZE];
    static const uint16_t TEXTINDVALUE5_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue5Buffer[TEXTINDVALUE5_SIZE];
    static const uint16_t TEXTINDVALUE6_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue6Buffer[TEXTINDVALUE6_SIZE];
    static const uint16_t TEXTINDMAPVALUE_SIZE = 3;
    touchgfx::Unicode::UnicodeChar textIndMapValueBuffer[TEXTINDMAPVALUE_SIZE];
    static const uint16_t TEXTINDTCVALUE_SIZE = 3;
    touchgfx::Unicode::UnicodeChar textIndTcValueBuffer[TEXTINDTCVALUE_SIZE];
    static const uint16_t TEXTINDACQUISITIONVALUE_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textIndAcquisitionValueBuffer[TEXTINDACQUISITIONVALUE_SIZE];
    static const uint16_t TEXTINDGEARVALUE_SIZE = 3;
    touchgfx::Unicode::UnicodeChar textIndGearValueBuffer[TEXTINDGEARVALUE_SIZE];
    static const uint16_t TEXTRPMLIMITERVALUE_SIZE = 7;
    touchgfx::Unicode::UnicodeChar textRpmLimiterValueBuffer[TEXTRPMLIMITERVALUE_SIZE];

private:

};

#endif // SKIDPAD_VIEW_BASE_HPP
