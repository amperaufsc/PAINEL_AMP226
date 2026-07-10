#ifndef CALIBRAGEM_SAVIEW_HPP
#define CALIBRAGEM_SAVIEW_HPP

#include <gui_generated/calibragem_sa_screen/calibragem_SAViewBase.hpp>
#include <gui/calibragem_sa_screen/calibragem_SAPresenter.hpp>

class calibragem_SAView : public calibragem_SAViewBase
{
public:
    calibragem_SAView();
    virtual ~calibragem_SAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CALIBRAGEM_SAVIEW_HPP
