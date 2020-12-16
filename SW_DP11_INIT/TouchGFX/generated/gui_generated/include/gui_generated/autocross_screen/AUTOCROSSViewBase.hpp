/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef AUTOCROSS_VIEW_BASE_HPP
#define AUTOCROSS_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/autocross_screen/AUTOCROSSPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class AUTOCROSSViewBase : public touchgfx::View<AUTOCROSSPresenter>
{
public:
    AUTOCROSSViewBase();
    virtual ~AUTOCROSSViewBase() {}

    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box background;
    touchgfx::BoxWithBorder boxTraction;
    touchgfx::TextAreaWithOneWildcard textTractionValue;
    touchgfx::TextArea textTraction;
    touchgfx::BoxWithBorder boxTorque;
    touchgfx::TextAreaWithOneWildcard textTorqueValue;
    touchgfx::TextArea textTorque;
    touchgfx::BoxWithBorder boxMaxPower;
    touchgfx::TextAreaWithOneWildcard textMaxPowerValue;
    touchgfx::TextArea textMaxPower;
    touchgfx::BoxWithBorder boxMap;
    touchgfx::TextArea textMap;
    touchgfx::TextAreaWithOneWildcard textMapValue;
    touchgfx::BoxWithBorder boxHV;
    touchgfx::TextArea textVBAT;
    touchgfx::TextAreaWithOneWildcard textVBATValue;
    touchgfx::BoxWithBorder boxMode;
    touchgfx::TextArea textMode;
    touchgfx::BoxWithBorder boxSOCBackground;
    touchgfx::BoxWithBorder barSOC;
    touchgfx::BoxWithBorder boxIndicator1;
    touchgfx::BoxWithBorder boxIndicator2;
    touchgfx::BoxWithBorder boxIndicator3;
    touchgfx::BoxWithBorder boxIndicator4;
    touchgfx::TextAreaWithOneWildcard textIndicator1;
    touchgfx::TextAreaWithOneWildcard textIndicator2;
    touchgfx::TextAreaWithOneWildcard textIndicator3;
    touchgfx::TextAreaWithOneWildcard textIndicator4;
    touchgfx::TextAreaWithOneWildcard textIndicatorValue1;
    touchgfx::TextAreaWithOneWildcard textIndicatorValue2;
    touchgfx::TextAreaWithOneWildcard textIndicatorValue3;
    touchgfx::TextAreaWithOneWildcard textIndicatorValue4;
    touchgfx::BoxWithBorder boxSD;
    touchgfx::TextArea textSD;
    touchgfx::BoxWithBorder boxUSB;
    touchgfx::TextArea textUSB;
    touchgfx::BoxWithBorder boxTS;
    touchgfx::TextAreaWithOneWildcard textTS;
    touchgfx::BoxWithBorder boxRGN;
    touchgfx::TextArea textRGN;
    touchgfx::BoxWithBorder boxRTD;
    touchgfx::TextArea textRTD;
    touchgfx::BoxWithBorder boxEntry;
    touchgfx::TextArea textEntry;
    touchgfx::BoxWithBorder boxDCU;
    touchgfx::TextArea textDCU;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTTRACTIONVALUE_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textTractionValueBuffer[TEXTTRACTIONVALUE_SIZE];
    static const uint16_t TEXTTORQUEVALUE_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textTorqueValueBuffer[TEXTTORQUEVALUE_SIZE];
    static const uint16_t TEXTMAXPOWERVALUE_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textMaxPowerValueBuffer[TEXTMAXPOWERVALUE_SIZE];
    static const uint16_t TEXTMAPVALUE_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textMapValueBuffer[TEXTMAPVALUE_SIZE];
    static const uint16_t TEXTVBATVALUE_SIZE = 7;
    touchgfx::Unicode::UnicodeChar textVBATValueBuffer[TEXTVBATVALUE_SIZE];
    static const uint16_t TEXTINDICATOR1_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndicator1Buffer[TEXTINDICATOR1_SIZE];
    static const uint16_t TEXTINDICATOR2_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndicator2Buffer[TEXTINDICATOR2_SIZE];
    static const uint16_t TEXTINDICATOR3_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndicator3Buffer[TEXTINDICATOR3_SIZE];
    static const uint16_t TEXTINDICATOR4_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndicator4Buffer[TEXTINDICATOR4_SIZE];
    static const uint16_t TEXTINDICATORVALUE1_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndicatorValue1Buffer[TEXTINDICATORVALUE1_SIZE];
    static const uint16_t TEXTINDICATORVALUE2_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndicatorValue2Buffer[TEXTINDICATORVALUE2_SIZE];
    static const uint16_t TEXTINDICATORVALUE3_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndicatorValue3Buffer[TEXTINDICATORVALUE3_SIZE];
    static const uint16_t TEXTINDICATORVALUE4_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndicatorValue4Buffer[TEXTINDICATORVALUE4_SIZE];
    static const uint16_t TEXTTS_SIZE = 8;
    touchgfx::Unicode::UnicodeChar textTSBuffer[TEXTTS_SIZE];

private:

};

#endif // AUTOCROSS_VIEW_BASE_HPP
