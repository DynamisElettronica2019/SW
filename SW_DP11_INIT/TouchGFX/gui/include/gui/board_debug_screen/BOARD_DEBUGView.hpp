#ifndef BOARD_DEBUG_VIEW_HPP
#define BOARD_DEBUG_VIEW_HPP

#include <gui_generated/board_debug_screen/BOARD_DEBUGViewBase.hpp>
#include <gui/board_debug_screen/BOARD_DEBUGPresenter.hpp>

#include <general.h>
#include <data.h>

class BOARD_DEBUGView : public BOARD_DEBUGViewBase
{
public:
    BOARD_DEBUGView();
    virtual ~BOARD_DEBUGView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		virtual void refreshBoardDebug();
		virtual void checkChangeScreen();
protected:
		touchgfx::Unicode::UnicodeChar Title1[6];
		touchgfx::Unicode::UnicodeChar Title2[6];
		touchgfx::Unicode::UnicodeChar Title3[6];
		touchgfx::Unicode::UnicodeChar Title4[6];
		touchgfx::Unicode::UnicodeChar Title5[6];
		uint8_t pointer1;
		uint8_t pointer2;
		uint8_t pointer3;
		uint8_t pointer4;
		uint8_t pointer5;
};

#endif // BOARD_DEBUG_VIEW_HPP
