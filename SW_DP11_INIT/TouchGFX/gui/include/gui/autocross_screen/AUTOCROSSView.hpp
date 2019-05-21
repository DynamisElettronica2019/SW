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
	  virtual void screenCheckMessage();
protected:
	
		touchgfx::Unicode::UnicodeChar Empty[6];
		touchgfx::Unicode::UnicodeChar Ready[9];
		touchgfx::Unicode::UnicodeChar Steady[9];
		touchgfx::Unicode::UnicodeChar Go[9];

		touchgfx::Unicode::UnicodeChar Title1[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title2[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title3[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title4[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title5[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title6[TIT_LEN];

		touchgfx::Unicode::UnicodeChar Gear[3];
		touchgfx::Unicode::UnicodeChar Acquisition[5];
		int screenEntry;
};

#endif // AUTOCROSS_VIEW_HPP
