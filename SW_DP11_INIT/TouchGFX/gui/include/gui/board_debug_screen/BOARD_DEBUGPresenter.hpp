#ifndef BOARD_DEBUG_PRESENTER_HPP
#define BOARD_DEBUG_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class BOARD_DEBUGView;

class BOARD_DEBUGPresenter : public Presenter, public ModelListener
{
public:
    BOARD_DEBUGPresenter(BOARD_DEBUGView& v);

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

    virtual ~BOARD_DEBUGPresenter() {};

private:
    BOARD_DEBUGPresenter();

    BOARD_DEBUGView& view;
};


#endif // BOARD_DEBUG_PRESENTER_HPP
