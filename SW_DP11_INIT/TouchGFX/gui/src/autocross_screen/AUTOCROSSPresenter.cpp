#include <gui/autocross_screen/AUTOCROSSView.hpp>
#include <gui/autocross_screen/AUTOCROSSPresenter.hpp>

AUTOCROSSPresenter::AUTOCROSSPresenter(AUTOCROSSView& v)
    : view(v)
{
}

void AUTOCROSSPresenter::activate()
{

}

void AUTOCROSSPresenter::deactivate()
{

}

void AUTOCROSSPresenter::update()
{
	view.refreshAutocross();
}
