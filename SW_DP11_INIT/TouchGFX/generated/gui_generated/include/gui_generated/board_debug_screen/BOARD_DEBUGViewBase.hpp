/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef BOARD_DEBUG_VIEW_BASE_HPP
#define BOARD_DEBUG_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/board_debug_screen/BOARD_DEBUGPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class BOARD_DEBUGViewBase : public touchgfx::View<BOARD_DEBUGPresenter>
{
public:
    BOARD_DEBUGViewBase();
    virtual ~BOARD_DEBUGViewBase() {}

    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box background;
    touchgfx::TextArea textACCELERATION;
    touchgfx::TextArea textENDURANCE;
    touchgfx::BoxWithBorder boxIndCurrent;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;
    touchgfx::Line line2;
    touchgfx::PainterRGB565 line2Painter;
    touchgfx::Line line3;
    touchgfx::PainterRGB565 line3Painter;
    touchgfx::TextAreaWithOneWildcard textIndTitle1;
    touchgfx::TextAreaWithOneWildcard textIndTitle2;
    touchgfx::TextAreaWithOneWildcard textIndTitle3;
    touchgfx::TextAreaWithOneWildcard textIndTitle4;
    touchgfx::TextAreaWithOneWildcard textIndValueTemp1;
    touchgfx::TextAreaWithOneWildcard textIndValueTemp2;
    touchgfx::TextAreaWithOneWildcard textIndValueTemp3;
    touchgfx::TextAreaWithOneWildcard textIndValueTemp4;
    touchgfx::TextAreaWithOneWildcard textIndValueCurr1;
    touchgfx::TextAreaWithOneWildcard textIndValueCurr2;
    touchgfx::TextAreaWithOneWildcard textIndValueCurr3;
    touchgfx::TextAreaWithOneWildcard textIndValueCurr4;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTINDTITLE1_SIZE = 7;
    touchgfx::Unicode::UnicodeChar textIndTitle1Buffer[TEXTINDTITLE1_SIZE];
    static const uint16_t TEXTINDTITLE2_SIZE = 7;
    touchgfx::Unicode::UnicodeChar textIndTitle2Buffer[TEXTINDTITLE2_SIZE];
    static const uint16_t TEXTINDTITLE3_SIZE = 7;
    touchgfx::Unicode::UnicodeChar textIndTitle3Buffer[TEXTINDTITLE3_SIZE];
    static const uint16_t TEXTINDTITLE4_SIZE = 7;
    touchgfx::Unicode::UnicodeChar textIndTitle4Buffer[TEXTINDTITLE4_SIZE];
    static const uint16_t TEXTINDVALUETEMP1_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValueTemp1Buffer[TEXTINDVALUETEMP1_SIZE];
    static const uint16_t TEXTINDVALUETEMP2_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValueTemp2Buffer[TEXTINDVALUETEMP2_SIZE];
    static const uint16_t TEXTINDVALUETEMP3_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValueTemp3Buffer[TEXTINDVALUETEMP3_SIZE];
    static const uint16_t TEXTINDVALUETEMP4_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValueTemp4Buffer[TEXTINDVALUETEMP4_SIZE];
    static const uint16_t TEXTINDVALUECURR1_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValueCurr1Buffer[TEXTINDVALUECURR1_SIZE];
    static const uint16_t TEXTINDVALUECURR2_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValueCurr2Buffer[TEXTINDVALUECURR2_SIZE];
    static const uint16_t TEXTINDVALUECURR3_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValueCurr3Buffer[TEXTINDVALUECURR3_SIZE];
    static const uint16_t TEXTINDVALUECURR4_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValueCurr4Buffer[TEXTINDVALUECURR4_SIZE];

private:

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 9600;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

};

#endif // BOARD_DEBUG_VIEW_BASE_HPP
