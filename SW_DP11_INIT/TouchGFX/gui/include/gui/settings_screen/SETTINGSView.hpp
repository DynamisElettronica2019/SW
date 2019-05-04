#ifndef SETTINGS_VIEW_HPP
#define SETTINGS_VIEW_HPP

#include <gui_generated/settings_screen/SETTINGSViewBase.hpp>
#include <gui/settings_screen/SETTINGSPresenter.hpp>

class SETTINGSView : public SETTINGSViewBase
{
public:
    SETTINGSView();
    virtual ~SETTINGSView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_VIEW_HPP
