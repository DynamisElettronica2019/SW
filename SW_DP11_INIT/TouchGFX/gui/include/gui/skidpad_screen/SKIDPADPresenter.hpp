#ifndef SKIDPAD_PRESENTER_HPP
#define SKIDPAD_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SKIDPADView;

class SKIDPADPresenter : public Presenter, public ModelListener
{
public:
    SKIDPADPresenter(SKIDPADView& v);

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

    virtual ~SKIDPADPresenter() {};

private:
    SKIDPADPresenter();

    SKIDPADView& view;

		virtual void update();
};


#endif // SKIDPAD_PRESENTER_HPP
