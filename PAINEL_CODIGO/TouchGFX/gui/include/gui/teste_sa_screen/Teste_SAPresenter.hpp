#ifndef TESTE_SAPRESENTER_HPP
#define TESTE_SAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Teste_SAView;

class Teste_SAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Teste_SAPresenter(Teste_SAView& v);

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

    virtual ~Teste_SAPresenter() {}

private:
    Teste_SAPresenter();

    Teste_SAView& view;
};

#endif // TESTE_SAPRESENTER_HPP
