#ifndef PAG2_AUTONOMOSVIEW_HPP
#define PAG2_AUTONOMOSVIEW_HPP

#include <gui_generated/pag2_autonomos_screen/pag2_AutonomosViewBase.hpp>
#include <gui/pag2_autonomos_screen/pag2_AutonomosPresenter.hpp>

class pag2_AutonomosView : public pag2_AutonomosViewBase
{
public:
    pag2_AutonomosView();
    virtual ~pag2_AutonomosView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PAG2_AUTONOMOSVIEW_HPP
