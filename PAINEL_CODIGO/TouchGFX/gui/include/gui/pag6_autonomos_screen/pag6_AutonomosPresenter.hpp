#ifndef PAG6_AUTONOMOSPRESENTER_HPP
#define PAG6_AUTONOMOSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class pag6_AutonomosView;

class pag6_AutonomosPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    pag6_AutonomosPresenter(pag6_AutonomosView& v);

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

    virtual ~pag6_AutonomosPresenter() {}

private:
    pag6_AutonomosPresenter();

    pag6_AutonomosView& view;
};

#endif // PAG6_AUTONOMOSPRESENTER_HPP
