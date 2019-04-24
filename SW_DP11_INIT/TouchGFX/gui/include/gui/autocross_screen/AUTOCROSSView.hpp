#ifndef AUTOCROSS_VIEW_HPP
#define AUTOCROSS_VIEW_HPP

#include <gui_generated/autocross_screen/AUTOCROSSViewBase.hpp>
#include <gui/autocross_screen/AUTOCROSSPresenter.hpp>

class AUTOCROSSView : public AUTOCROSSViewBase
{
public:
    AUTOCROSSView();
    virtual ~AUTOCROSSView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // AUTOCROSS_VIEW_HPP
