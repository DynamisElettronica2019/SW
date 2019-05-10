/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/board_debug_screen/BOARD_DEBUGViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

BOARD_DEBUGViewBase::BOARD_DEBUGViewBase()
{
    CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    background.setPosition(0, 0, 640, 480);
    background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    textACCELERATION.setPosition(432, 17, 200, 75);
    textACCELERATION.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textACCELERATION.setLinespacing(0);
    textACCELERATION.setTypedText(TypedText(T_SINGLEUSEID187));

    textENDURANCE.setPosition(220, 17, 200, 75);
    textENDURANCE.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textENDURANCE.setLinespacing(0);
    textENDURANCE.setTypedText(TypedText(T_SINGLEUSEID188));

    boxIndCurrent.setPosition(2, 194, 636, 123);
    boxIndCurrent.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxIndCurrent.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(158, 158, 158));
    boxIndCurrent.setBorderSize(5);

    line1.setPosition(200, 10, 20, 480);
    line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    line1.setPainter(line1Painter);
    line1.setStart(10, 0);
    line1.setEnd(10, 460);
    line1.setLineWidth(2);
    line1.setLineEndingStyle(Line::SQUARE_CAP_ENDING);
    line1.setVisible(false);

    line2.setPosition(420, 10, 20, 480);
    line2Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    line2.setPainter(line2Painter);
    line2.setStart(10, 0);
    line2.setEnd(10, 460);
    line2.setLineWidth(2);
    line2.setLineEndingStyle(Line::SQUARE_CAP_ENDING);
    line2.setVisible(false);

    line3.setPosition(8, 82, 632, 20);
    line3Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    line3.setPainter(line3Painter);
    line3.setStart(0, 10);
    line3.setEnd(620, 10);
    line3.setLineWidth(2);
    line3.setLineEndingStyle(Line::SQUARE_CAP_ENDING);
    line3.setVisible(false);

    textIndTitle1.setPosition(8, 110, 166, 75);
    textIndTitle1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle1.setLinespacing(0);
    Unicode::snprintf(textIndTitle1Buffer, TEXTINDTITLE1_SIZE, "%s", TypedText(T_SINGLEUSEID198).getText());
    textIndTitle1.setWildcard(textIndTitle1Buffer);
    textIndTitle1.setTypedText(TypedText(T_SINGLEUSEID197));

    textIndTitle2.setPosition(8, 220, 166, 75);
    textIndTitle2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle2.setLinespacing(0);
    Unicode::snprintf(textIndTitle2Buffer, TEXTINDTITLE2_SIZE, "%s", TypedText(T_SINGLEUSEID194).getText());
    textIndTitle2.setWildcard(textIndTitle2Buffer);
    textIndTitle2.setTypedText(TypedText(T_SINGLEUSEID193));

    textIndTitle3.setPosition(8, 330, 166, 75);
    textIndTitle3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle3.setLinespacing(0);
    Unicode::snprintf(textIndTitle3Buffer, TEXTINDTITLE3_SIZE, "%s", TypedText(T_SINGLEUSEID190).getText());
    textIndTitle3.setWildcard(textIndTitle3Buffer);
    textIndTitle3.setTypedText(TypedText(T_SINGLEUSEID189));

    textIndTitle4.setPosition(8, 440, 166, 75);
    textIndTitle4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndTitle4.setLinespacing(0);
    Unicode::snprintf(textIndTitle4Buffer, TEXTINDTITLE4_SIZE, "%s", TypedText(T_SINGLEUSEID200).getText());
    textIndTitle4.setWildcard(textIndTitle4Buffer);
    textIndTitle4.setTypedText(TypedText(T_SINGLEUSEID199));

    textIndValueTemp1.setPosition(249, 115, 140, 65);
    textIndValueTemp1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValueTemp1.setLinespacing(0);
    Unicode::snprintf(textIndValueTemp1Buffer, TEXTINDVALUETEMP1_SIZE, "%s", TypedText(T_SINGLEUSEID202).getText());
    textIndValueTemp1.setWildcard(textIndValueTemp1Buffer);
    textIndValueTemp1.setTypedText(TypedText(T_SINGLEUSEID201));

    textIndValueTemp2.setPosition(250, 225, 140, 65);
    textIndValueTemp2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValueTemp2.setLinespacing(0);
    Unicode::snprintf(textIndValueTemp2Buffer, TEXTINDVALUETEMP2_SIZE, "%s", TypedText(T_SINGLEUSEID204).getText());
    textIndValueTemp2.setWildcard(textIndValueTemp2Buffer);
    textIndValueTemp2.setTypedText(TypedText(T_SINGLEUSEID203));

    textIndValueTemp3.setPosition(249, 335, 140, 65);
    textIndValueTemp3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValueTemp3.setLinespacing(0);
    Unicode::snprintf(textIndValueTemp3Buffer, TEXTINDVALUETEMP3_SIZE, "%s", TypedText(T_SINGLEUSEID206).getText());
    textIndValueTemp3.setWildcard(textIndValueTemp3Buffer);
    textIndValueTemp3.setTypedText(TypedText(T_SINGLEUSEID205));

    textIndValueTemp4.setPosition(249, 445, 140, 65);
    textIndValueTemp4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValueTemp4.setLinespacing(0);
    Unicode::snprintf(textIndValueTemp4Buffer, TEXTINDVALUETEMP4_SIZE, "%s", TypedText(T_SINGLEUSEID208).getText());
    textIndValueTemp4.setWildcard(textIndValueTemp4Buffer);
    textIndValueTemp4.setTypedText(TypedText(T_SINGLEUSEID207));

    textIndValueCurr1.setPosition(463, 115, 140, 65);
    textIndValueCurr1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValueCurr1.setLinespacing(0);
    Unicode::snprintf(textIndValueCurr1Buffer, TEXTINDVALUECURR1_SIZE, "%s", TypedText(T_SINGLEUSEID210).getText());
    textIndValueCurr1.setWildcard(textIndValueCurr1Buffer);
    textIndValueCurr1.setTypedText(TypedText(T_SINGLEUSEID209));

    textIndValueCurr2.setPosition(464, 225, 140, 65);
    textIndValueCurr2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValueCurr2.setLinespacing(0);
    Unicode::snprintf(textIndValueCurr2Buffer, TEXTINDVALUECURR2_SIZE, "%s", TypedText(T_SINGLEUSEID212).getText());
    textIndValueCurr2.setWildcard(textIndValueCurr2Buffer);
    textIndValueCurr2.setTypedText(TypedText(T_SINGLEUSEID211));

    textIndValueCurr3.setPosition(463, 335, 140, 65);
    textIndValueCurr3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValueCurr3.setLinespacing(0);
    Unicode::snprintf(textIndValueCurr3Buffer, TEXTINDVALUECURR3_SIZE, "%s", TypedText(T_SINGLEUSEID214).getText());
    textIndValueCurr3.setWildcard(textIndValueCurr3Buffer);
    textIndValueCurr3.setTypedText(TypedText(T_SINGLEUSEID213));

    textIndValueCurr4.setPosition(463, 445, 140, 65);
    textIndValueCurr4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textIndValueCurr4.setLinespacing(0);
    Unicode::snprintf(textIndValueCurr4Buffer, TEXTINDVALUECURR4_SIZE, "%s", TypedText(T_SINGLEUSEID216).getText());
    textIndValueCurr4.setWildcard(textIndValueCurr4Buffer);
    textIndValueCurr4.setTypedText(TypedText(T_SINGLEUSEID215));

    add(background);
    add(textACCELERATION);
    add(textENDURANCE);
    add(boxIndCurrent);
    add(line1);
    add(line2);
    add(line3);
    add(textIndTitle1);
    add(textIndTitle2);
    add(textIndTitle3);
    add(textIndTitle4);
    add(textIndValueTemp1);
    add(textIndValueTemp2);
    add(textIndValueTemp3);
    add(textIndValueTemp4);
    add(textIndValueCurr1);
    add(textIndValueCurr2);
    add(textIndValueCurr3);
    add(textIndValueCurr4);
}

void BOARD_DEBUGViewBase::setupScreen()
{

}