#ifndef SETTINGS_VIEW_HPP
#define SETTINGS_VIEW_HPP

#include <gui_generated/settings_screen/SETTINGSViewBase.hpp>
#include <gui/settings_screen/SETTINGSPresenter.hpp>

#include <general.h>
#include <data.h>

class SETTINGSView : public SETTINGSViewBase
{
public:
    SETTINGSView();
    virtual ~SETTINGSView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		virtual void refreshSettings();
		virtual void checkChangeScreen();
		virtual void changeDisplay();
		virtual void moveSelectedBox();
		virtual void displayAcceleration();
		virtual void displayEndurance();
		virtual void displayAutocross();
		virtual void displaySkidpad();
protected:
		int flag_schermata;
		touchgfx::Unicode::UnicodeChar TitleDriveMode[20];
		touchgfx::Unicode::UnicodeChar Title[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title1[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title2[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title3[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title4[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title5[TIT_LEN];
		touchgfx::Unicode::UnicodeChar Title6[TIT_LEN];

};

#endif // SETTINGS_VIEW_HPP
