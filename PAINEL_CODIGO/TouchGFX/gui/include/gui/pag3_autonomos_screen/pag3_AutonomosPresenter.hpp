#ifndef PAG3_AUTONOMOSPRESENTER_HPP
#define PAG3_AUTONOMOSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class pag3_AutonomosView;

class pag3_AutonomosPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    pag3_AutonomosPresenter(pag3_AutonomosView& v);

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

    virtual ~pag3_AutonomosPresenter() {}

private:
    pag3_AutonomosPresenter();

    pag3_AutonomosView& view;
};

#endif // PAG3_AUTONOMOSPRESENTER_HPP
