#ifndef EBS_TESTE_SAPRESENTER_HPP
#define EBS_TESTE_SAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class EBS_Teste_SAView;

class EBS_Teste_SAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    EBS_Teste_SAPresenter(EBS_Teste_SAView& v);

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


    virtual ~EBS_Teste_SAPresenter() {}
    void notifyButtonChanged(uint32_t buttonID);


private:
    EBS_Teste_SAPresenter();

    EBS_Teste_SAView& view;
};

#endif // EBS_TESTE_SAPRESENTER_HPP
