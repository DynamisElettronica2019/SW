#ifndef ACCELERATION_VIEW_HPP
#define ACCELERATION_VIEW_HPP

#include <gui_generated/acceleration_screen/ACCELERATIONViewBase.hpp>
#include <gui/acceleration_screen/ACCELERATIONPresenter.hpp>

#include <general.h>
#include <data.h>

class ACCELERATIONView : public ACCELERATIONViewBase
{
public:
		ACCELERATIONView();
    virtual ~ACCELERATIONView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		virtual void refreshAcceleration();
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
		int cont;
};

#endif // ACCELERATION_VIEW_HPP
