#ifndef PAG4_AUTONOMOSPRESENTER_HPP
#define PAG4_AUTONOMOSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class pag4_AutonomosView;

class pag4_AutonomosPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    pag4_AutonomosPresenter(pag4_AutonomosView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~pag4_AutonomosPresenter() {}

private:
    pag4_AutonomosPresenter();

    pag4_AutonomosView& view;
};

#endif // PAG4_AUTONOMOSPRESENTER_HPP
