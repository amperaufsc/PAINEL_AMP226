#ifndef PAG3_AUTONOMOSVIEW_HPP
#define PAG3_AUTONOMOSVIEW_HPP

#include <gui_generated/pag3_autonomos_screen/pag3_AutonomosViewBase.hpp>
#include <gui/pag3_autonomos_screen/pag3_AutonomosPresenter.hpp>

class pag3_AutonomosView : public pag3_AutonomosViewBase
{
public:
    pag3_AutonomosView();
    virtual ~pag3_AutonomosView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PAG3_AUTONOMOSVIEW_HPP
