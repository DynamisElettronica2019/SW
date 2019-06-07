#ifndef SKIDPAD_VIEW_HPP
#define SKIDPAD_VIEW_HPP

#include <gui_generated/skidpad_screen/SKIDPADViewBase.hpp>
#include <gui/skidpad_screen/SKIDPADPresenter.hpp>

#include <general.h>
#include <data.h>

class SKIDPADView : public SKIDPADViewBase
{
public:
    SKIDPADView();
    virtual ~SKIDPADView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		virtual void refreshSkidpad();
		virtual void checkChangeScreen();
		virtual void screenEntryPopup();
		virtual void checkEmergency();
		virtual void checkFuelIndicator();
protected:
		touchgfx::Unicode::UnicodeChar Empty[6];

		touchgfx::Unicode::UnicodeChar Title1[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title2[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title3[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title4[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title5[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title6[TIT_LEN];

		touchgfx::Unicode::UnicodeChar Gear[3];
		touchgfx::Unicode::UnicodeChar Acquisition[5];
    int screenEntry;
		int emergencyBlinkCont;
};

#endif // SKIDPAD_VIEW_HPP
