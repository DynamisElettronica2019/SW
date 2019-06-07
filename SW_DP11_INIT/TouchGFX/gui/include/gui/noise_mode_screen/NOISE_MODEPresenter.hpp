#ifndef NOISE_MODE_PRESENTER_HPP
#define NOISE_MODE_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class NOISE_MODEView;

class NOISE_MODEPresenter : public Presenter, public ModelListener
{
public:
    NOISE_MODEPresenter(NOISE_MODEView& v);

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

    virtual ~NOISE_MODEPresenter() {};

private:
    NOISE_MODEPresenter();

    NOISE_MODEView& view;

		virtual void update();
};


#endif // NOISE_MODE_PRESENTER_HPP
