#include <gui/settings_screen/SETTINGSView.hpp>
#include <gui/settings_screen/SETTINGSPresenter.hpp>

SETTINGSPresenter::SETTINGSPresenter(SETTINGSView& v)
    : view(v)
{
}

void SETTINGSPresenter::activate()
{

}

void SETTINGSPresenter::deactivate()
{

}

void SETTINGSPresenter::update()
{
	view.refreshSettings();
}
