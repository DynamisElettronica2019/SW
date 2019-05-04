#include <gui/debug_mode_screen/DEBUG_MODEView.hpp>
#include <gui/debug_mode_screen/DEBUG_MODEPresenter.hpp>

DEBUG_MODEPresenter::DEBUG_MODEPresenter(DEBUG_MODEView& v)
    : view(v)
{
}

void DEBUG_MODEPresenter::activate()
{

}

void DEBUG_MODEPresenter::deactivate()
{

}

void DEBUG_MODEPresenter::update()
{
	view.refreshDebugMode();
}
