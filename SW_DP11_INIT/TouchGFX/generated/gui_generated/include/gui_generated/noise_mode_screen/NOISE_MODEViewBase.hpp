/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef NOISE_MODE_VIEW_BASE_HPP
#define NOISE_MODE_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/noise_mode_screen/NOISE_MODEPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class NOISE_MODEViewBase : public touchgfx::View<NOISE_MODEPresenter>
{
public:
    NOISE_MODEViewBase();
    virtual ~NOISE_MODEViewBase() {}

    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box background;
    touchgfx::BoxWithBorder boxRPM;
    touchgfx::BoxWithBorder boxTPS;
    touchgfx::BoxWithBorder boxTRMC2;
    touchgfx::BoxWithBorder boxTRMC1;
    touchgfx::Box boxText;
    touchgfx::TextArea textNOISEMODE;
    touchgfx::TextArea textRPM;
    touchgfx::TextAreaWithOneWildcard textRpmValue;
    touchgfx::TextArea textTPS;
    touchgfx::TextAreaWithOneWildcard textTpsValue;
    touchgfx::TextArea textTRMC2;
    touchgfx::TextArea textTRMC1;
    touchgfx::TextAreaWithOneWildcard textTrmcValue2;
    touchgfx::BoxWithBorder boxIndicatorGear;
    touchgfx::TextAreaWithOneWildcard textIndGearValue;
    touchgfx::BoxWithBorder boxTRMC1_1;
    touchgfx::TextArea textTRMC1_1;
    touchgfx::TextAreaWithOneWildcard textTrmcValue1;
    touchgfx::BoxWithBorder boxIndicator1;
    touchgfx::TextAreaWithOneWildcard textIndValueVBAT;
    touchgfx::BoxWithBorder boxIndicator1_1;
    touchgfx::TextAreaWithOneWildcard textIndValuePOIL;
    touchgfx::TextArea textIndTitle1;
    touchgfx::TextArea textIndTitle2;
    touchgfx::BoxWithBorder boxMapPopUp;
    touchgfx::TextArea textMapPopUp;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTRPMVALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textRpmValueBuffer[TEXTRPMVALUE_SIZE];
    static const uint16_t TEXTTPSVALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTpsValueBuffer[TEXTTPSVALUE_SIZE];
    static const uint16_t TEXTTRMCVALUE2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTrmcValue2Buffer[TEXTTRMCVALUE2_SIZE];
    static const uint16_t TEXTINDGEARVALUE_SIZE = 3;
    touchgfx::Unicode::UnicodeChar textIndGearValueBuffer[TEXTINDGEARVALUE_SIZE];
    static const uint16_t TEXTTRMCVALUE1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTrmcValue1Buffer[TEXTTRMCVALUE1_SIZE];
    static const uint16_t TEXTINDVALUEVBAT_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValueVBATBuffer[TEXTINDVALUEVBAT_SIZE];
    static const uint16_t TEXTINDVALUEPOIL_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValuePOILBuffer[TEXTINDVALUEPOIL_SIZE];

private:

};

#endif // NOISE_MODE_VIEW_BASE_HPP