#ifndef PAG7_AUTONOMOSPRESENTER_HPP
#define PAG7_AUTONOMOSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class pag7_AutonomosView;

class pag7_AutonomosPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    pag7_AutonomosPresenter(pag7_AutonomosView& v);

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

    virtual ~pag7_AutonomosPresenter() {}

private:
    pag7_AutonomosPresenter();

    pag7_AutonomosView& view;
};

#endif // PAG7_AUTONOMOSPRESENTER_HPP
