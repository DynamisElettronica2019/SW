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
		touchgfx::Unicode::UnicodeChar Title1sx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title2sx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title3sx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title4sx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title5sx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title6sx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title7sx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title8sx[TIT_LEN];

		touchgfx::Unicode::UnicodeChar Title1dx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title2dx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title3dx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title4dx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title5dx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title6dx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title7dx[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title8dx[TIT_LEN];

};

#endif // DEBUG_MODE_VIEW_HPP
