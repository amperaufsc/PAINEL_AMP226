#ifndef AUTOCROSS_SAVIEW_HPP
#define AUTOCROSS_SAVIEW_HPP

#include <gui_generated/autocross_sa_screen/AutoCross_SAViewBase.hpp>
#include <gui/autocross_sa_screen/AutoCross_SAPresenter.hpp>

class AutoCross_SAView : public AutoCross_SAViewBase
{
public:
    AutoCross_SAView();
    virtual ~AutoCross_SAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // AUTOCROSS_SAVIEW_HPP
