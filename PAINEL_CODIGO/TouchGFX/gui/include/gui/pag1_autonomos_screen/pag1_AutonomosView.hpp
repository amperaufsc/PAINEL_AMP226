#ifndef PAG1_AUTONOMOSVIEW_HPP
#define PAG1_AUTONOMOSVIEW_HPP

#include <gui_generated/pag1_autonomos_screen/pag1_AutonomosViewBase.hpp>
#include <gui/pag1_autonomos_screen/pag1_AutonomosPresenter.hpp>

class pag1_AutonomosView : public pag1_AutonomosViewBase
{
public:
    pag1_AutonomosView();
    virtual ~pag1_AutonomosView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PAG1_AUTONOMOSVIEW_HPP
