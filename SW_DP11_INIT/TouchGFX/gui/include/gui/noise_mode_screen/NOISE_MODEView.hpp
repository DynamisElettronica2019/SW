#ifndef NOISE_MODE_VIEW_HPP
#define NOISE_MODE_VIEW_HPP

#include <gui_generated/noise_mode_screen/NOISE_MODEViewBase.hpp>
#include <gui/noise_mode_screen/NOISE_MODEPresenter.hpp>

#include <general.h>
#include <data.h>

class NOISE_MODEView : public NOISE_MODEViewBase
{
public:
    NOISE_MODEView();
    virtual ~NOISE_MODEView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		virtual void checkChangeScreen();
		virtual void refreshNoiseMode();
protected:
		touchgfx::Unicode::UnicodeChar Empty[6];
};

#endif // NOISE_MODE_VIEW_HPP
