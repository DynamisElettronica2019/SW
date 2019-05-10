#include <gui/endurance_screen/ENDURANCEView.hpp>
#include <gui/endurance_screen/ENDURANCEPresenter.hpp>

ENDURANCEPresenter::ENDURANCEPresenter(ENDURANCEView& v)
    : view(v)
{
}

void ENDURANCEPresenter::activate()
{

}

void ENDURANCEPresenter::deactivate()
{

}

void ENDURANCEPresenter::update()
{
	view.refreshEndurance();
}
