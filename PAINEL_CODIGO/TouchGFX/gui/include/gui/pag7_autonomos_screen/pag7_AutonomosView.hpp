#ifndef PAG7_AUTONOMOSVIEW_HPP
#define PAG7_AUTONOMOSVIEW_HPP

#include <gui_generated/pag7_autonomos_screen/pag7_AutonomosViewBase.hpp>
#include <gui/pag7_autonomos_screen/pag7_AutonomosPresenter.hpp>

class pag7_AutonomosView : public pag7_AutonomosViewBase
{
public:
    pag7_AutonomosView();
    virtual ~pag7_AutonomosView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PAG7_AUTONOMOSVIEW_HPP
