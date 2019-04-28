#ifndef AUTOCROSS_PRESENTER_HPP
#define AUTOCROSS_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AUTOCROSSView;

class AUTOCROSSPresenter : public Presenter, public ModelListener
{
public:
    AUTOCROSSPresenter(AUTOCROSSView& v);

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

    virtual ~AUTOCROSSPresenter() {};

private:
    AUTOCROSSPresenter();

    AUTOCROSSView& view;

		virtual void update();
};


#endif // AUTOCROSS_PRESENTER_HPP
