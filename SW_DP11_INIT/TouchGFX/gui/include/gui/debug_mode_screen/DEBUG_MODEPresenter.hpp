#ifndef DEBUG_MODE_PRESENTER_HPP
#define DEBUG_MODE_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DEBUG_MODEView;

class DEBUG_MODEPresenter : public Presenter, public ModelListener
{
public:
    DEBUG_MODEPresenter(DEBUG_MODEView& v);

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

    virtual ~DEBUG_MODEPresenter() {};

private:
    DEBUG_MODEPresenter();

    DEBUG_MODEView& view;
};


#endif // DEBUG_MODE_PRESENTER_HPP
