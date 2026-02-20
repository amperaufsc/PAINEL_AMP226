#ifndef PAG5_AUTONOMOSVIEW_HPP
#define PAG5_AUTONOMOSVIEW_HPP

#include <gui_generated/pag5_autonomos_screen/pag5_AutonomosViewBase.hpp>
#include <gui/pag5_autonomos_screen/pag5_AutonomosPresenter.hpp>

class pag5_AutonomosView : public pag5_AutonomosViewBase
{
public:
    pag5_AutonomosView();
    virtual ~pag5_AutonomosView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PAG5_AUTONOMOSVIEW_HPP
