/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/debug_mode_screen/DEBUG_MODEViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

DEBUG_MODEViewBase::DEBUG_MODEViewBase()
{
    CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    background.setPosition(0, 0, 640, 480);
    background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    boxIndCurrent.setPosition(6, 71, 629, 69);
    boxIndCurrent.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndCurrent.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    boxIndCurrent.setBorderSize(5);

    line1.setPosition(315, 0, 15, 480);
    line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    line1.setPainter(line1Painter);
    line1.setStart(5, 10);
    line1.setEnd(5, 470);
    line1.setLineWidth(3);
    line1.setLineEndingStyle(Line::SQUARE_CAP_ENDING);

    textIndTitle1sx.setPosition(0, 25, 166, 50);
    textIndTitle1sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle1sx.setLinespacing(0);
    Unicode::snprintf(textIndTitle1sxBuffer, TEXTINDTITLE1SX_SIZE, "%s", TypedText(T_SINGLEUSEID218).getText());
    textIndTitle1sx.setWildcard(textIndTitle1sxBuffer);
    textIndTitle1sx.setTypedText(TypedText(T_SINGLEUSEID217));

    textIndTitle2sx.setPosition(0, 85, 166, 50);
    textIndTitle2sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle2sx.setLinespacing(0);
    Unicode::snprintf(textIndTitle2sxBuffer, TEXTINDTITLE2SX_SIZE, "%s", TypedText(T_SINGLEUSEID220).getText());
    textIndTitle2sx.setWildcard(textIndTitle2sxBuffer);
    textIndTitle2sx.setTypedText(TypedText(T_SINGLEUSEID219));

    textIndTitle3sx.setPosition(0, 145, 166, 50);
    textIndTitle3sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle3sx.setLinespacing(0);
    Unicode::snprintf(textIndTitle3sxBuffer, TEXTINDTITLE3SX_SIZE, "%s", TypedText(T_SINGLEUSEID222).getText());
    textIndTitle3sx.setWildcard(textIndTitle3sxBuffer);
    textIndTitle3sx.setTypedText(TypedText(T_SINGLEUSEID221));

    textIndTitle4sx.setPosition(0, 205, 166, 50);
    textIndTitle4sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle4sx.setLinespacing(0);
    Unicode::snprintf(textIndTitle4sxBuffer, TEXTINDTITLE4SX_SIZE, "%s", TypedText(T_SINGLEUSEID224).getText());
    textIndTitle4sx.setWildcard(textIndTitle4sxBuffer);
    textIndTitle4sx.setTypedText(TypedText(T_SINGLEUSEID223));

    textIndTitle1dx.setPosition(320, 25, 166, 50);
    textIndTitle1dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle1dx.setLinespacing(0);
    Unicode::snprintf(textIndTitle1dxBuffer, TEXTINDTITLE1DX_SIZE, "%s", TypedText(T_SINGLEUSEID226).getText());
    textIndTitle1dx.setWildcard(textIndTitle1dxBuffer);
    textIndTitle1dx.setTypedText(TypedText(T_SINGLEUSEID225));

    textIndTitle2dx.setPosition(320, 85, 166, 50);
    textIndTitle2dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle2dx.setLinespacing(0);
    Unicode::snprintf(textIndTitle2dxBuffer, TEXTINDTITLE2DX_SIZE, "%s", TypedText(T_SINGLEUSEID228).getText());
    textIndTitle2dx.setWildcard(textIndTitle2dxBuffer);
    textIndTitle2dx.setTypedText(TypedText(T_SINGLEUSEID227));

    textIndTitle3dx.setPosition(320, 145, 166, 50);
    textIndTitle3dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle3dx.setLinespacing(0);
    Unicode::snprintf(textIndTitle3dxBuffer, TEXTINDTITLE3DX_SIZE, "%s", TypedText(T_SINGLEUSEID230).getText());
    textIndTitle3dx.setWildcard(textIndTitle3dxBuffer);
    textIndTitle3dx.setTypedText(TypedText(T_SINGLEUSEID229));

    textIndTitle4dx.setPosition(320, 205, 166, 50);
    textIndTitle4dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle4dx.setLinespacing(0);
    Unicode::snprintf(textIndTitle4dxBuffer, TEXTINDTITLE4DX_SIZE, "%s", TypedText(T_SINGLEUSEID232).getText());
    textIndTitle4dx.setWildcard(textIndTitle4dxBuffer);
    textIndTitle4dx.setTypedText(TypedText(T_SINGLEUSEID231));

    textIndValue1sx.setPosition(161, 25, 154, 50);
    textIndValue1sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue1sx.setLinespacing(0);
    Unicode::snprintf(textIndValue1sxBuffer, TEXTINDVALUE1SX_SIZE, "%s", TypedText(T_SINGLEUSEID249).getText());
    textIndValue1sx.setWildcard(textIndValue1sxBuffer);
    textIndValue1sx.setTypedText(TypedText(T_SINGLEUSEID233));

    textIndValue2sx.setPosition(161, 85, 154, 50);
    textIndValue2sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue2sx.setLinespacing(0);
    Unicode::snprintf(textIndValue2sxBuffer, TEXTINDVALUE2SX_SIZE, "%s", TypedText(T_SINGLEUSEID236).getText());
    textIndValue2sx.setWildcard(textIndValue2sxBuffer);
    textIndValue2sx.setTypedText(TypedText(T_SINGLEUSEID235));

    textIndValue3sx.setPosition(161, 145, 154, 50);
    textIndValue3sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue3sx.setLinespacing(0);
    Unicode::snprintf(textIndValue3sxBuffer, TEXTINDVALUE3SX_SIZE, "%s", TypedText(T_SINGLEUSEID238).getText());
    textIndValue3sx.setWildcard(textIndValue3sxBuffer);
    textIndValue3sx.setTypedText(TypedText(T_SINGLEUSEID237));

    textIndValue4sx.setPosition(161, 205, 154, 50);
    textIndValue4sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue4sx.setLinespacing(0);
    Unicode::snprintf(textIndValue4sxBuffer, TEXTINDVALUE4SX_SIZE, "%s", TypedText(T_SINGLEUSEID240).getText());
    textIndValue4sx.setWildcard(textIndValue4sxBuffer);
    textIndValue4sx.setTypedText(TypedText(T_SINGLEUSEID239));

    textIndValue1dx.setPosition(481, 25, 154, 50);
    textIndValue1dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue1dx.setLinespacing(0);
    Unicode::snprintf(textIndValue1dxBuffer, TEXTINDVALUE1DX_SIZE, "%s", TypedText(T_SINGLEUSEID242).getText());
    textIndValue1dx.setWildcard(textIndValue1dxBuffer);
    textIndValue1dx.setTypedText(TypedText(T_SINGLEUSEID241));

    textIndValue2dx.setPosition(481, 85, 154, 50);
    textIndValue2dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue2dx.setLinespacing(0);
    Unicode::snprintf(textIndValue2dxBuffer, TEXTINDVALUE2DX_SIZE, "%s", TypedText(T_SINGLEUSEID244).getText());
    textIndValue2dx.setWildcard(textIndValue2dxBuffer);
    textIndValue2dx.setTypedText(TypedText(T_SINGLEUSEID243));

    textIndValue3dx.setPosition(481, 145, 154, 50);
    textIndValue3dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue3dx.setLinespacing(0);
    Unicode::snprintf(textIndValue3dxBuffer, TEXTINDVALUE3DX_SIZE, "%s", TypedText(T_SINGLEUSEID246).getText());
    textIndValue3dx.setWildcard(textIndValue3dxBuffer);
    textIndValue3dx.setTypedText(TypedText(T_SINGLEUSEID245));

    textIndValue4dx.setPosition(481, 205, 154, 50);
    textIndValue4dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue4dx.setLinespacing(0);
    Unicode::snprintf(textIndValue4dxBuffer, TEXTINDVALUE4DX_SIZE, "%s", TypedText(T_SINGLEUSEID248).getText());
    textIndValue4dx.setWildcard(textIndValue4dxBuffer);
    textIndValue4dx.setTypedText(TypedText(T_SINGLEUSEID247));

    line1_1.setPosition(69, 109, 502, 15);
    line1_1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    line1_1.setPainter(line1_1Painter);
    line1_1.setStart(0, 5);
    line1_1.setEnd(500, 5);
    line1_1.setLineWidth(1);
    line1_1.setLineEndingStyle(Line::ROUND_CAP_ENDING);
    line1_1.setVisible(false);

    line1_1_1.setPosition(69, 233, 502, 15);
    line1_1_1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    line1_1_1.setPainter(line1_1_1Painter);
    line1_1_1.setStart(0, 5);
    line1_1_1.setEnd(500, 5);
    line1_1_1.setLineWidth(1);
    line1_1_1.setLineEndingStyle(Line::ROUND_CAP_ENDING);
    line1_1_1.setVisible(false);

    line1_1_2.setPosition(69, 356, 502, 15);
    line1_1_2Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    line1_1_2.setPainter(line1_1_2Painter);
    line1_1_2.setStart(0, 5);
    line1_1_2.setEnd(500, 5);
    line1_1_2.setLineWidth(1);
    line1_1_2.setLineEndingStyle(Line::ROUND_CAP_ENDING);
    line1_1_2.setVisible(false);

    textIndTitle5sx.setPosition(0, 265, 166, 50);
    textIndTitle5sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle5sx.setLinespacing(0);
    Unicode::snprintf(textIndTitle5sxBuffer, TEXTINDTITLE5SX_SIZE, "%s", TypedText(T_SINGLEUSEID265).getText());
    textIndTitle5sx.setWildcard(textIndTitle5sxBuffer);
    textIndTitle5sx.setTypedText(TypedText(T_SINGLEUSEID264));

    textIndValue5sx.setPosition(161, 265, 154, 50);
    textIndValue5sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue5sx.setLinespacing(0);
    Unicode::snprintf(textIndValue5sxBuffer, TEXTINDVALUE5SX_SIZE, "%s", TypedText(T_SINGLEUSEID267).getText());
    textIndValue5sx.setWildcard(textIndValue5sxBuffer);
    textIndValue5sx.setTypedText(TypedText(T_SINGLEUSEID266));

    textIndTitle5dx.setPosition(320, 265, 166, 50);
    textIndTitle5dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle5dx.setLinespacing(0);
    Unicode::snprintf(textIndTitle5dxBuffer, TEXTINDTITLE5DX_SIZE, "%s", TypedText(T_SINGLEUSEID269).getText());
    textIndTitle5dx.setWildcard(textIndTitle5dxBuffer);
    textIndTitle5dx.setTypedText(TypedText(T_SINGLEUSEID268));

    textIndValue5dx.setPosition(481, 265, 154, 50);
    textIndValue5dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue5dx.setLinespacing(0);
    Unicode::snprintf(textIndValue5dxBuffer, TEXTINDVALUE5DX_SIZE, "%s", TypedText(T_SINGLEUSEID271).getText());
    textIndValue5dx.setWildcard(textIndValue5dxBuffer);
    textIndValue5dx.setTypedText(TypedText(T_SINGLEUSEID270));

    textIndTitle6sx.setPosition(0, 325, 166, 50);
    textIndTitle6sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle6sx.setLinespacing(0);
    Unicode::snprintf(textIndTitle6sxBuffer, TEXTINDTITLE6SX_SIZE, "%s", TypedText(T_SINGLEUSEID287).getText());
    textIndTitle6sx.setWildcard(textIndTitle6sxBuffer);
    textIndTitle6sx.setTypedText(TypedText(T_SINGLEUSEID286));

    textIndValue6sx.setPosition(161, 325, 154, 50);
    textIndValue6sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue6sx.setLinespacing(0);
    Unicode::snprintf(textIndValue6sxBuffer, TEXTINDVALUE6SX_SIZE, "%s", TypedText(T_SINGLEUSEID289).getText());
    textIndValue6sx.setWildcard(textIndValue6sxBuffer);
    textIndValue6sx.setTypedText(TypedText(T_SINGLEUSEID288));

    textIndTitle7sx.setPosition(0, 385, 166, 50);
    textIndTitle7sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle7sx.setLinespacing(0);
    Unicode::snprintf(textIndTitle7sxBuffer, TEXTINDTITLE7SX_SIZE, "%s", TypedText(T_SINGLEUSEID291).getText());
    textIndTitle7sx.setWildcard(textIndTitle7sxBuffer);
    textIndTitle7sx.setTypedText(TypedText(T_SINGLEUSEID290));

    textIndTitle8sx.setPosition(0, 445, 166, 50);
    textIndTitle8sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle8sx.setLinespacing(0);
    Unicode::snprintf(textIndTitle8sxBuffer, TEXTINDTITLE8SX_SIZE, "%s", TypedText(T_SINGLEUSEID293).getText());
    textIndTitle8sx.setWildcard(textIndTitle8sxBuffer);
    textIndTitle8sx.setTypedText(TypedText(T_SINGLEUSEID292));

    textIndValue7sx.setPosition(161, 385, 154, 50);
    textIndValue7sx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue7sx.setLinespacing(0);
    Unicode::snprintf(textIndValue7sxBuffer, TEXTINDVALUE7SX_SIZE, "%s", TypedText(T_SINGLEUSEID295).getText());
    textIndValue7sx.setWildcard(textIndValue7sxBuffer);
    textIndValue7sx.setTypedText(TypedText(T_SINGLEUSEID294));

    textIndValue6sx_1.setPosition(161, 445, 154, 50);
    textIndValue6sx_1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue6sx_1.setLinespacing(0);
    Unicode::snprintf(textIndValue6sx_1Buffer, TEXTINDVALUE6SX_1_SIZE, "%s", TypedText(T_SINGLEUSEID297).getText());
    textIndValue6sx_1.setWildcard(textIndValue6sx_1Buffer);
    textIndValue6sx_1.setTypedText(TypedText(T_SINGLEUSEID296));

    textIndTitle7dx.setPosition(320, 385, 166, 50);
    textIndTitle7dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle7dx.setLinespacing(0);
    Unicode::snprintf(textIndTitle7dxBuffer, TEXTINDTITLE7DX_SIZE, "%s", TypedText(T_SINGLEUSEID299).getText());
    textIndTitle7dx.setWildcard(textIndTitle7dxBuffer);
    textIndTitle7dx.setTypedText(TypedText(T_SINGLEUSEID298));

    textIndTitle6dx.setPosition(320, 325, 166, 50);
    textIndTitle6dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle6dx.setLinespacing(0);
    Unicode::snprintf(textIndTitle6dxBuffer, TEXTINDTITLE6DX_SIZE, "%s", TypedText(T_SINGLEUSEID301).getText());
    textIndTitle6dx.setWildcard(textIndTitle6dxBuffer);
    textIndTitle6dx.setTypedText(TypedText(T_SINGLEUSEID300));

    textIndTitle8dx.setPosition(320, 445, 166, 50);
    textIndTitle8dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle8dx.setLinespacing(0);
    Unicode::snprintf(textIndTitle8dxBuffer, TEXTINDTITLE8DX_SIZE, "%s", TypedText(T_SINGLEUSEID303).getText());
    textIndTitle8dx.setWildcard(textIndTitle8dxBuffer);
    textIndTitle8dx.setTypedText(TypedText(T_SINGLEUSEID302));

    textIndValue6dx.setPosition(481, 325, 154, 50);
    textIndValue6dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue6dx.setLinespacing(0);
    Unicode::snprintf(textIndValue6dxBuffer, TEXTINDVALUE6DX_SIZE, "%s", TypedText(T_SINGLEUSEID305).getText());
    textIndValue6dx.setWildcard(textIndValue6dxBuffer);
    textIndValue6dx.setTypedText(TypedText(T_SINGLEUSEID304));

    textIndValue7dx.setPosition(481, 385, 154, 50);
    textIndValue7dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue7dx.setLinespacing(0);
    Unicode::snprintf(textIndValue7dxBuffer, TEXTINDVALUE7DX_SIZE, "%s", TypedText(T_SINGLEUSEID307).getText());
    textIndValue7dx.setWildcard(textIndValue7dxBuffer);
    textIndValue7dx.setTypedText(TypedText(T_SINGLEUSEID306));

    textIndValue8dx.setPosition(481, 445, 154, 50);
    textIndValue8dx.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValue8dx.setLinespacing(0);
    Unicode::snprintf(textIndValue8dxBuffer, TEXTINDVALUE8DX_SIZE, "%s", TypedText(T_SINGLEUSEID309).getText());
    textIndValue8dx.setWildcard(textIndValue8dxBuffer);
    textIndValue8dx.setTypedText(TypedText(T_SINGLEUSEID308));

    add(background);
    add(boxIndCurrent);
    add(line1);
    add(textIndTitle1sx);
    add(textIndTitle2sx);
    add(textIndTitle3sx);
    add(textIndTitle4sx);
    add(textIndTitle1dx);
    add(textIndTitle2dx);
    add(textIndTitle3dx);
    add(textIndTitle4dx);
    add(textIndValue1sx);
    add(textIndValue2sx);
    add(textIndValue3sx);
    add(textIndValue4sx);
    add(textIndValue1dx);
    add(textIndValue2dx);
    add(textIndValue3dx);
    add(textIndValue4dx);
    add(line1_1);
    add(line1_1_1);
    add(line1_1_2);
    add(textIndTitle5sx);
    add(textIndValue5sx);
    add(textIndTitle5dx);
    add(textIndValue5dx);
    add(textIndTitle6sx);
    add(textIndValue6sx);
    add(textIndTitle7sx);
    add(textIndTitle8sx);
    add(textIndValue7sx);
    add(textIndValue6sx_1);
    add(textIndTitle7dx);
    add(textIndTitle6dx);
    add(textIndTitle8dx);
    add(textIndValue6dx);
    add(textIndValue7dx);
    add(textIndValue8dx);
}

void DEBUG_MODEViewBase::setupScreen()
{

}
