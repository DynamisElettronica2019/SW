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

#endif // ACCELERATION_VIEW_HPP
