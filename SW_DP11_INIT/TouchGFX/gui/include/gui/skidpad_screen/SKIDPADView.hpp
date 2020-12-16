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
protected:
	
		touchgfx::Unicode::UnicodeChar Empty[6];
		touchgfx::Unicode::UnicodeChar Title1[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title2[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title3[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title4[TIT_LEN];

		touchgfx::Unicode::UnicodeChar TorqueValue[5];
		touchgfx::Unicode::UnicodeChar TractionValue[5];
		touchgfx::Unicode::UnicodeChar USBAcquisition[5];
		touchgfx::Unicode::UnicodeChar TSValue[7];

		touchgfx::Unicode::UnicodeChar Acquisition[5];

		int screenEntry;

};

#endif // SKIDPAD_VIEW_HPP
