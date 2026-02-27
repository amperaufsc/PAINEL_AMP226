#ifndef SKIDPED_SAPRESENTER_HPP
#define SKIDPED_SAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Skidped_SAView;

class Skidped_SAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Skidped_SAPresenter(Skidped_SAView& v);

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


    virtual ~Skidped_SAPresenter() {}
    void notifyButtonChanged(uint32_t buttonID);

private:
    Skidped_SAPresenter();

    Skidped_SAView& view;
};

#endif // SKIDPED_SAPRESENTER_HPP
