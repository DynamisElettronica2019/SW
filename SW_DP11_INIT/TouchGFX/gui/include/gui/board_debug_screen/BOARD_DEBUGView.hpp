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
		touchgfx::Unicode::UnicodeChar Title1[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title2[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title3[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title4[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title5[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title6[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title7[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title8[TIT_LEN];

		uint8_t pointer1;
		uint8_t pointer2;
		uint8_t pointer3;
		uint8_t pointer4;
		uint8_t pointer5;
		uint8_t pointer6;
		uint8_t pointer7;
		uint8_t pointer8;
};

#endif // BOARD_DEBUG_VIEW_HPP
