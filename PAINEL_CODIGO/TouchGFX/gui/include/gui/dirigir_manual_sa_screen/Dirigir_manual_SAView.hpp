#ifndef DIRIGIR_MANUAL_SAVIEW_HPP
#define DIRIGIR_MANUAL_SAVIEW_HPP

#include <gui_generated/dirigir_manual_sa_screen/Dirigir_manual_SAViewBase.hpp>
#include <gui/dirigir_manual_sa_screen/Dirigir_manual_SAPresenter.hpp>

class Dirigir_manual_SAView : public Dirigir_manual_SAViewBase
{
public:
    Dirigir_manual_SAView();
    virtual ~Dirigir_manual_SAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DIRIGIR_MANUAL_SAVIEW_HPP
