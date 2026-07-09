#ifndef AREA_DE_TESTE_SAPRESENTER_HPP
#define AREA_DE_TESTE_SAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Area_de_Teste_SAView;

class Area_de_Teste_SAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Area_de_Teste_SAPresenter(Area_de_Teste_SAView& v);

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

    virtual ~Area_de_Teste_SAPresenter() {}

	//botoes
	virtual void Botao1(int bn1) override;
	virtual void Botao2(int bn2) override;
	virtual void Botao3(int bn3) override;

private:
    Area_de_Teste_SAPresenter();

    Area_de_Teste_SAView& view;
};

#endif // AREA_DE_TESTE_SAPRESENTER_HPP
