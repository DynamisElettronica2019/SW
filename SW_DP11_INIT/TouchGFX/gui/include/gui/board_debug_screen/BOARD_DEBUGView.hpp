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
};

#endif // BOARD_DEBUG_VIEW_HPP
