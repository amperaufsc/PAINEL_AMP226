#ifndef DIRIGIR_MANUAL_SAPRESENTER_HPP
#define DIRIGIR_MANUAL_SAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Dirigir_manual_SAView;

class Dirigir_manual_SAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Dirigir_manual_SAPresenter(Dirigir_manual_SAView& v);

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
    virtual void hwButtonClicked(uint8_t buttonId) override;


    virtual ~Dirigir_manual_SAPresenter() {}
    void notifyButtonChanged(uint32_t buttonID);

private:
    Dirigir_manual_SAPresenter();

    Dirigir_manual_SAView& view;
};

#endif // DIRIGIR_MANUAL_SAPRESENTER_HPP
