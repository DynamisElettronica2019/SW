/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SETTINGS_VIEW_BASE_HPP
#define SETTINGS_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/settings_screen/SETTINGSPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class SETTINGSViewBase : public touchgfx::View<SETTINGSPresenter>
{
public:
    SETTINGSViewBase();
    virtual ~SETTINGSViewBase() {}

    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box background;
    touchgfx::BoxWithBorder boxIndSelected;
    touchgfx::BoxWithBorder boxIndicator1;
    touchgfx::BoxWithBorder boxIndicator2;
    touchgfx::BoxWithBorder boxIndicator3;
    touchgfx::BoxWithBorder boxIndicator4;
    touchgfx::BoxWithBorder boxIndicator5;
    touchgfx::BoxWithBorder boxIndicator6;
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
    touchgfx::TextAreaWithOneWildcard textIndDriveMode;
    touchgfx::TextAreaWithOneWildcard textIndTitleCurrent;
    touchgfx::BoxWithBorder boxCalibrationSelected;
    touchgfx::TextArea textAPPS_0;
    touchgfx::TextArea textAPPS_100;
    touchgfx::TextArea textSW_ANGLE;
    touchgfx::TextArea textLINEAR;
    touchgfx::TextArea textLOAD_CELL;
    touchgfx::TextArea textIMU;
    touchgfx::BoxWithBorder boxCalibration1;
    touchgfx::BoxWithBorder boxCalibration2;
    touchgfx::BoxWithBorder boxCalibration3;
    touchgfx::BoxWithBorder boxCalibration4;
    touchgfx::BoxWithBorder boxCalibrationImuSelected;
    touchgfx::TextArea textTitle1;
    touchgfx::TextArea textTitle2;
    touchgfx::TextArea textTitle3;
    touchgfx::TextArea textTitle4;
    touchgfx::TextArea textTitle5;
    touchgfx::TextArea textTitle6;
    touchgfx::TextArea textTitle7;
    touchgfx::TextArea textTitle8;
    touchgfx::TextArea textTitle9;
    touchgfx::TextArea textTitle10;
    touchgfx::Box box1;
    touchgfx::TextArea textIMU1;
    touchgfx::TextArea textIMU2;
    touchgfx::TextArea textInd1;
    touchgfx::TextArea textInd2;
    touchgfx::TextArea textInd3;
    touchgfx::TextArea textInd4;
    touchgfx::TextAreaWithOneWildcard textValue1;
    touchgfx::TextAreaWithOneWildcard textValue2;
    touchgfx::TextAreaWithOneWildcard textValue3;
    touchgfx::TextAreaWithOneWildcard textValue4;
    touchgfx::Box boxDONE;
    touchgfx::TextAreaWithOneWildcard textDONE;
    touchgfx::BoxWithBorder boxModeSelected;
    touchgfx::TextArea textACCELERATION;
    touchgfx::TextArea textENDURANCE;
    touchgfx::TextArea textAUTOCROSS;
    touchgfx::TextArea textSKIDPAD;
    touchgfx::TextArea textCALIBRATION;
    touchgfx::BoxWithBorder boxDCUdead;
    touchgfx::TextArea textDCUdead;

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
    static const uint16_t TEXTINDDRIVEMODE_SIZE = 20;
    touchgfx::Unicode::UnicodeChar textIndDriveModeBuffer[TEXTINDDRIVEMODE_SIZE];
    static const uint16_t TEXTINDTITLECURRENT_SIZE = 13;
    touchgfx::Unicode::UnicodeChar textIndTitleCurrentBuffer[TEXTINDTITLECURRENT_SIZE];
    static const uint16_t TEXTVALUE1_SIZE = 4;
    touchgfx::Unicode::UnicodeChar textValue1Buffer[TEXTVALUE1_SIZE];
    static const uint16_t TEXTVALUE2_SIZE = 4;
    touchgfx::Unicode::UnicodeChar textValue2Buffer[TEXTVALUE2_SIZE];
    static const uint16_t TEXTVALUE3_SIZE = 4;
    touchgfx::Unicode::UnicodeChar textValue3Buffer[TEXTVALUE3_SIZE];
    static const uint16_t TEXTVALUE4_SIZE = 4;
    touchgfx::Unicode::UnicodeChar textValue4Buffer[TEXTVALUE4_SIZE];
    static const uint16_t TEXTDONE_SIZE = 20;
    touchgfx::Unicode::UnicodeChar textDONEBuffer[TEXTDONE_SIZE];

private:

};

#endif // SETTINGS_VIEW_BASE_HPP
