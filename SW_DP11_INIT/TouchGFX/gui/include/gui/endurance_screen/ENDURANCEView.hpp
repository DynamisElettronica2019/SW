#ifndef ENDURANCE_VIEW_HPP
#define ENDURANCE_VIEW_HPP

#include <gui_generated/endurance_screen/ENDURANCEViewBase.hpp>
#include <gui/endurance_screen/ENDURANCEPresenter.hpp>

class ENDURANCEView : public ENDURANCEViewBase
{
public:
    ENDURANCEView();
    virtual ~ENDURANCEView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ENDURANCE_VIEW_HPP
