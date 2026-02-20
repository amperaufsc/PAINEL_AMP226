#ifndef PAG4_AUTONOMOSVIEW_HPP
#define PAG4_AUTONOMOSVIEW_HPP

#include <gui_generated/pag4_autonomos_screen/pag4_AutonomosViewBase.hpp>
#include <gui/pag4_autonomos_screen/pag4_AutonomosPresenter.hpp>

class pag4_AutonomosView : public pag4_AutonomosViewBase
{
public:
    pag4_AutonomosView();
    virtual ~pag4_AutonomosView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PAG4_AUTONOMOSVIEW_HPP
