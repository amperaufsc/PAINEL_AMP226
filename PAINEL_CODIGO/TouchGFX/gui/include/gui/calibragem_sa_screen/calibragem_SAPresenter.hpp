#ifndef CALIBRAGEM_SAPRESENTER_HPP
#define CALIBRAGEM_SAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class calibragem_SAView;

class calibragem_SAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    calibragem_SAPresenter(calibragem_SAView& v);

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

    virtual ~calibragem_SAPresenter() {}

private:
    calibragem_SAPresenter();

    calibragem_SAView& view;
};

#endif // CALIBRAGEM_SAPRESENTER_HPP
