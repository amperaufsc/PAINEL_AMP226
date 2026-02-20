#ifndef PAG1_AUTONOMOSPRESENTER_HPP
#define PAG1_AUTONOMOSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class pag1_AutonomosView;

class pag1_AutonomosPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    pag1_AutonomosPresenter(pag1_AutonomosView& v);

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

    virtual ~pag1_AutonomosPresenter() {}

private:
    pag1_AutonomosPresenter();

    pag1_AutonomosView& view;
};

#endif // PAG1_AUTONOMOSPRESENTER_HPP
