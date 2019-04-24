#ifndef ACCELERATION_VIEW_HPP
#define ACCELERATION_VIEW_HPP

#include <gui_generated/acceleration_screen/ACCELERATIONViewBase.hpp>
#include <gui/acceleration_screen/ACCELERATIONPresenter.hpp>

class ACCELERATIONView : public ACCELERATIONViewBase
{
public:
    ACCELERATIONView();
    virtual ~ACCELERATIONView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ACCELERATION_VIEW_HPP
