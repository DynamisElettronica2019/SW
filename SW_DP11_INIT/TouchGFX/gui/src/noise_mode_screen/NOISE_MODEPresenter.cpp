#include <gui/noise_mode_screen/NOISE_MODEView.hpp>
#include <gui/noise_mode_screen/NOISE_MODEPresenter.hpp>

NOISE_MODEPresenter::NOISE_MODEPresenter(NOISE_MODEView& v)
    : view(v)
{
}

void NOISE_MODEPresenter::activate()
{

}

void NOISE_MODEPresenter::deactivate()
{

}

void NOISE_MODEPresenter::update()
{
	view.refreshNoiseMode();
}
