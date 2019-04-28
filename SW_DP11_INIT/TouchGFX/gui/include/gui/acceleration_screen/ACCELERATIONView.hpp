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
protected:
		touchgfx::Unicode::UnicodeChar Title1[6];
		touchgfx::Unicode::UnicodeChar Title2[6];
		touchgfx::Unicode::UnicodeChar Title3[6];
		touchgfx::Unicode::UnicodeChar Title4[6];
		touchgfx::Unicode::UnicodeChar Title5[6];
		touchgfx::Unicode::UnicodeChar Title6[6];

		touchgfx::Unicode::UnicodeChar Gear[3];
		touchgfx::Unicode::UnicodeChar Acquisition[5];

};

#endif // ACCELERATION_VIEW_HPP
