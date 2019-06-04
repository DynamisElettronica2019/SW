/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef DEBUG_MODE_VIEW_BASE_HPP
#define DEBUG_MODE_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/debug_mode_screen/DEBUG_MODEPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class DEBUG_MODEViewBase : public touchgfx::View<DEBUG_MODEPresenter>
{
public:
    DEBUG_MODEViewBase();
    virtual ~DEBUG_MODEViewBase() {}

    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box background;
    touchgfx::BoxWithBorder boxIndCurrent;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;
    touchgfx::TextAreaWithOneWildcard textIndTitle1sx;
    touchgfx::TextAreaWithOneWildcard textIndTitle2sx;
    touchgfx::TextAreaWithOneWildcard textIndTitle3sx;
    touchgfx::TextAreaWithOneWildcard textIndTitle4sx;
    touchgfx::TextAreaWithOneWildcard textIndTitle1dx;
    touchgfx::TextAreaWithOneWildcard textIndTitle2dx;
    touchgfx::TextAreaWithOneWildcard textIndTitle3dx;
    touchgfx::TextAreaWithOneWildcard textIndTitle4dx;
    touchgfx::TextAreaWithOneWildcard textIndValue1sx;
    touchgfx::TextAreaWithOneWildcard textIndValue2sx;
    touchgfx::TextAreaWithOneWildcard textIndValue3sx;
    touchgfx::TextAreaWithOneWildcard textIndValue4sx;
    touchgfx::TextAreaWithOneWildcard textIndValue1dx;
    touchgfx::TextAreaWithOneWildcard textIndValue2dx;
    touchgfx::TextAreaWithOneWildcard textIndValue3dx;
    touchgfx::TextAreaWithOneWildcard textIndValue4dx;
    touchgfx::Line line1_1;
    touchgfx::PainterRGB565 line1_1Painter;
    touchgfx::Line line1_1_1;
    touchgfx::PainterRGB565 line1_1_1Painter;
    touchgfx::Line line1_1_2;
    touchgfx::PainterRGB565 line1_1_2Painter;
    touchgfx::TextAreaWithOneWildcard textIndTitle5sx;
    touchgfx::TextAreaWithOneWildcard textIndValue5sx;
    touchgfx::TextAreaWithOneWildcard textIndTitle5dx;
    touchgfx::TextAreaWithOneWildcard textIndValue5dx;
    touchgfx::TextAreaWithOneWildcard textIndTitle6sx;
    touchgfx::TextAreaWithOneWildcard textIndValue6sx;
    touchgfx::TextAreaWithOneWildcard textIndTitle7sx;
    touchgfx::TextAreaWithOneWildcard textIndTitle8sx;
    touchgfx::TextAreaWithOneWildcard textIndValue7sx;
    touchgfx::TextAreaWithOneWildcard textIndValue8sx;
    touchgfx::TextAreaWithOneWildcard textIndTitle7dx;
    touchgfx::TextAreaWithOneWildcard textIndTitle6dx;
    touchgfx::TextAreaWithOneWildcard textIndTitle8dx;
    touchgfx::TextAreaWithOneWildcard textIndValue6dx;
    touchgfx::TextAreaWithOneWildcard textIndValue7dx;
    touchgfx::TextAreaWithOneWildcard textIndValue8dx;
    touchgfx::BoxWithBorder boxDCUdead;
    touchgfx::TextArea textDCUdead;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTINDTITLE1SX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle1sxBuffer[TEXTINDTITLE1SX_SIZE];
    static const uint16_t TEXTINDTITLE2SX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle2sxBuffer[TEXTINDTITLE2SX_SIZE];
    static const uint16_t TEXTINDTITLE3SX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle3sxBuffer[TEXTINDTITLE3SX_SIZE];
    static const uint16_t TEXTINDTITLE4SX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle4sxBuffer[TEXTINDTITLE4SX_SIZE];
    static const uint16_t TEXTINDTITLE1DX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle1dxBuffer[TEXTINDTITLE1DX_SIZE];
    static const uint16_t TEXTINDTITLE2DX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle2dxBuffer[TEXTINDTITLE2DX_SIZE];
    static const uint16_t TEXTINDTITLE3DX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle3dxBuffer[TEXTINDTITLE3DX_SIZE];
    static const uint16_t TEXTINDTITLE4DX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle4dxBuffer[TEXTINDTITLE4DX_SIZE];
    static const uint16_t TEXTINDVALUE1SX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue1sxBuffer[TEXTINDVALUE1SX_SIZE];
    static const uint16_t TEXTINDVALUE2SX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue2sxBuffer[TEXTINDVALUE2SX_SIZE];
    static const uint16_t TEXTINDVALUE3SX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue3sxBuffer[TEXTINDVALUE3SX_SIZE];
    static const uint16_t TEXTINDVALUE4SX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue4sxBuffer[TEXTINDVALUE4SX_SIZE];
    static const uint16_t TEXTINDVALUE1DX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue1dxBuffer[TEXTINDVALUE1DX_SIZE];
    static const uint16_t TEXTINDVALUE2DX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue2dxBuffer[TEXTINDVALUE2DX_SIZE];
    static const uint16_t TEXTINDVALUE3DX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue3dxBuffer[TEXTINDVALUE3DX_SIZE];
    static const uint16_t TEXTINDVALUE4DX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue4dxBuffer[TEXTINDVALUE4DX_SIZE];
    static const uint16_t TEXTINDTITLE5SX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle5sxBuffer[TEXTINDTITLE5SX_SIZE];
    static const uint16_t TEXTINDVALUE5SX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue5sxBuffer[TEXTINDVALUE5SX_SIZE];
    static const uint16_t TEXTINDTITLE5DX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle5dxBuffer[TEXTINDTITLE5DX_SIZE];
    static const uint16_t TEXTINDVALUE5DX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue5dxBuffer[TEXTINDVALUE5DX_SIZE];
    static const uint16_t TEXTINDTITLE6SX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle6sxBuffer[TEXTINDTITLE6SX_SIZE];
    static const uint16_t TEXTINDVALUE6SX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue6sxBuffer[TEXTINDVALUE6SX_SIZE];
    static const uint16_t TEXTINDTITLE7SX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle7sxBuffer[TEXTINDTITLE7SX_SIZE];
    static const uint16_t TEXTINDTITLE8SX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle8sxBuffer[TEXTINDTITLE8SX_SIZE];
    static const uint16_t TEXTINDVALUE7SX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue7sxBuffer[TEXTINDVALUE7SX_SIZE];
    static const uint16_t TEXTINDVALUE8SX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue8sxBuffer[TEXTINDVALUE8SX_SIZE];
    static const uint16_t TEXTINDTITLE7DX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle7dxBuffer[TEXTINDTITLE7DX_SIZE];
    static const uint16_t TEXTINDTITLE6DX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle6dxBuffer[TEXTINDTITLE6DX_SIZE];
    static const uint16_t TEXTINDTITLE8DX_SIZE = 12;
    touchgfx::Unicode::UnicodeChar textIndTitle8dxBuffer[TEXTINDTITLE8DX_SIZE];
    static const uint16_t TEXTINDVALUE6DX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue6dxBuffer[TEXTINDVALUE6DX_SIZE];
    static const uint16_t TEXTINDVALUE7DX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue7dxBuffer[TEXTINDVALUE7DX_SIZE];
    static const uint16_t TEXTINDVALUE8DX_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textIndValue8dxBuffer[TEXTINDVALUE8DX_SIZE];

private:

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 9600;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

};

#endif // DEBUG_MODE_VIEW_BASE_HPP
