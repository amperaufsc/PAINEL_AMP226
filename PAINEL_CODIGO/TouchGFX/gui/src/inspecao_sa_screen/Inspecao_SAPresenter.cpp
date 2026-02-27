#include <gui/inspecao_sa_screen/Inspecao_SAView.hpp>
#include <gui/inspecao_sa_screen/Inspecao_SAPresenter.hpp>

Inspecao_SAPresenter::Inspecao_SAPresenter(Inspecao_SAView& v)
    : view(v)
{

}

void Inspecao_SAPresenter::activate()
{

}

void Inspecao_SAPresenter::deactivate()
{

}
void Inspecao_SAPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 3) // PB11 BOLINHA
	    {
	     //   static_cast<FrontendApplication*>(Application::getInstance())->gotoSkinped_SAScreenBlockTransition();
	    }
	    else if (buttonId == 2) // PA3 TRIANGULO
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoEBS_Teste_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	         static_cast<FrontendApplication*>(Application::getInstance())->gotoDirigir_manual_SAScreenSlideTransitionWest();
	    }

	}
}
