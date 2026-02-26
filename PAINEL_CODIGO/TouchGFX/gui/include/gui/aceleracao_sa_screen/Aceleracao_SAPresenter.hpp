#ifndef ACELERACAO_SAPRESENTER_HPP
#define ACELERACAO_SAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Aceleracao_SAView;

class Aceleracao_SAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Aceleracao_SAPresenter(Aceleracao_SAView& v);

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
    virtual void updateCANData(int value);

    virtual ~Aceleracao_SAPresenter() {}
    void notifyButtonChanged(uint32_t buttonID);

private:
    Aceleracao_SAPresenter();

    Aceleracao_SAView& view;
};

#endif // ACELERACAO_SAPRESENTER_HPP
