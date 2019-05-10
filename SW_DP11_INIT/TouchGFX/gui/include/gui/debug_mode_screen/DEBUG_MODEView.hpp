#ifndef DEBUG_MODE_VIEW_HPP
#define DEBUG_MODE_VIEW_HPP

#include <gui_generated/debug_mode_screen/DEBUG_MODEViewBase.hpp>
#include <gui/debug_mode_screen/DEBUG_MODEPresenter.hpp>

#include <general.h>
#include <data.h>

class DEBUG_MODEView : public DEBUG_MODEViewBase
{
public:
    DEBUG_MODEView();
    virtual ~DEBUG_MODEView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		virtual void refreshDebugMode();
		virtual void checkChangeScreen();
protected:
};

#endif // DEBUG_MODE_VIEW_HPP
