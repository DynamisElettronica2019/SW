#ifndef SETTINGS_PRESENTER_HPP
#define SETTINGS_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SETTINGSView;

class SETTINGSPresenter : public Presenter, public ModelListener
{
public:
    SETTINGSPresenter(SETTINGSView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~SETTINGSPresenter() {};

private:
    SETTINGSPresenter();

    SETTINGSView& view;
};


#endif // SETTINGS_PRESENTER_HPP
