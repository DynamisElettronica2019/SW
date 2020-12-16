#ifndef AUTOCROSS_VIEW_HPP
#define AUTOCROSS_VIEW_HPP

#include <gui_generated/autocross_screen/AUTOCROSSViewBase.hpp>
#include <gui/autocross_screen/AUTOCROSSPresenter.hpp>

#include <general.h>
#include <data.h>

class AUTOCROSSView : public AUTOCROSSViewBase
{
public:
    AUTOCROSSView();
    virtual ~AUTOCROSSView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		virtual void refreshAutocross();
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

#endif // AUTOCROSS_VIEW_HPP
