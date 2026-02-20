#ifndef PAG2_AUTONOMOSPRESENTER_HPP
#define PAG2_AUTONOMOSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class pag2_AutonomosView;

class pag2_AutonomosPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    pag2_AutonomosPresenter(pag2_AutonomosView& v);

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

    virtual ~pag2_AutonomosPresenter() {}

private:
    pag2_AutonomosPresenter();

    pag2_AutonomosView& view;
};

#endif // PAG2_AUTONOMOSPRESENTER_HPP
