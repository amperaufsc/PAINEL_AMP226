#ifndef CAPAPRESENTER_HPP
#define CAPAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class CapaView;

class CapaPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    CapaPresenter(CapaView& v);

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

    virtual ~CapaPresenter() {}

    //botoes
    virtual void Botao1(int bn1) override;
    virtual void Botao2(int bn2) override;
    virtual void Botao3(int bn3) override;



private:
    CapaPresenter();

    CapaView& view;
};

#endif // CAPAPRESENTER_HPP
