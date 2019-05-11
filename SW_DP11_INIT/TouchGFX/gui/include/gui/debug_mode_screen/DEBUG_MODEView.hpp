#ifndef DEBUG_MODE_VIEW_HPP
#define DEBUG_MODE_VIEW_HPP

#include <gui_generated/debug_mode_screen/DEBUG_MODEViewBase.hpp>
#include <gui/debug_mode_screen/DEBUG_MODEPresenter.hpp>

#include <general.h>
#include <data.h>

#define N_DEBUG_MODE_VALUES 5
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
		touchgfx::Unicode::UnicodeChar Title1sx[6];
		touchgfx::Unicode::UnicodeChar Title2sx[6];
		touchgfx::Unicode::UnicodeChar Title3sx[6];
		touchgfx::Unicode::UnicodeChar Title4sx[6];
		touchgfx::Unicode::UnicodeChar Title5sx[6];

		touchgfx::Unicode::UnicodeChar Title1dx[6];
		touchgfx::Unicode::UnicodeChar Title2dx[6];
		touchgfx::Unicode::UnicodeChar Title3dx[6];
		touchgfx::Unicode::UnicodeChar Title4dx[6];
		touchgfx::Unicode::UnicodeChar Title5dx[6];
};

#endif // DEBUG_MODE_VIEW_HPP
