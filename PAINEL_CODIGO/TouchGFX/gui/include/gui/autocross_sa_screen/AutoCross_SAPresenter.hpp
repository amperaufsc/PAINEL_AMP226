#ifndef AUTOCROSS_SAPRESENTER_HPP
#define AUTOCROSS_SAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AutoCross_SAView;

class AutoCross_SAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AutoCross_SAPresenter(AutoCross_SAView& v);

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

    virtual ~AutoCross_SAPresenter() {}
    void notifyButtonChanged(uint32_t buttonID);


private:
    AutoCross_SAPresenter();

    AutoCross_SAView& view;
};

#endif // AUTOCROSS_SAPRESENTER_HPP
