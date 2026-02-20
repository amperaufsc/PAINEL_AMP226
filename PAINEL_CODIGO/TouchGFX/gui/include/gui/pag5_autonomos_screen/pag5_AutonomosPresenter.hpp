#ifndef PAG5_AUTONOMOSPRESENTER_HPP
#define PAG5_AUTONOMOSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class pag5_AutonomosView;

class pag5_AutonomosPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    pag5_AutonomosPresenter(pag5_AutonomosView& v);

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

    virtual ~pag5_AutonomosPresenter() {}

private:
    pag5_AutonomosPresenter();

    pag5_AutonomosView& view;
};

#endif // PAG5_AUTONOMOSPRESENTER_HPP
