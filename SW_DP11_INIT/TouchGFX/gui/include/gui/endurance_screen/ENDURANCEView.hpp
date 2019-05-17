#ifndef ENDURANCE_VIEW_HPP
#define ENDURANCE_VIEW_HPP

#include <gui_generated/endurance_screen/ENDURANCEViewBase.hpp>
#include <gui/endurance_screen/ENDURANCEPresenter.hpp>

#include <general.h>
#include <data.h>

class ENDURANCEView : public ENDURANCEViewBase
{
public:
    ENDURANCEView();
    virtual ~ENDURANCEView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		virtual void refreshEndurance();
		virtual void checkChangeScreen();
		virtual void screenEntryPopup();
protected:
		touchgfx::Unicode::UnicodeChar Title1[6];
		touchgfx::Unicode::UnicodeChar Title2[6];
		touchgfx::Unicode::UnicodeChar Title3[6];
		touchgfx::Unicode::UnicodeChar Title4[6];
		touchgfx::Unicode::UnicodeChar Title5[6];
		touchgfx::Unicode::UnicodeChar Title6[6];

		touchgfx::Unicode::UnicodeChar Gear[3];
		touchgfx::Unicode::UnicodeChar Acquisition[5];
		int cont;
		int screenEntry;
};

#endif // ENDURANCE_VIEW_HPP
