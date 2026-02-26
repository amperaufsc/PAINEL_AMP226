#ifndef MENU_SAPRESENTER_HPP
#define MENU_SAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Menu_SAView;

class Menu_SAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Menu_SAPresenter(Menu_SAView& v);

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

    virtual ~Menu_SAPresenter() {}

private:
    Menu_SAPresenter();

    Menu_SAView& view;
};

#endif // MENU_SAPRESENTER_HPP
