#ifndef PAG6_AUTONOMOSVIEW_HPP
#define PAG6_AUTONOMOSVIEW_HPP

#include <gui_generated/pag6_autonomos_screen/pag6_AutonomosViewBase.hpp>
#include <gui/pag6_autonomos_screen/pag6_AutonomosPresenter.hpp>

class pag6_AutonomosView : public pag6_AutonomosViewBase
{
public:
    pag6_AutonomosView();
    virtual ~pag6_AutonomosView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PAG6_AUTONOMOSVIEW_HPP
