#include <gui/pag1_autonomos_screen/pag1_AutonomosView.hpp>
#include <gui/pag1_autonomos_screen/pag1_AutonomosPresenter.hpp>

pag1_AutonomosPresenter::pag1_AutonomosPresenter(pag1_AutonomosView& v)
    : view(v)
{

}

void pag1_AutonomosPresenter::activate()
{
}

void pag1_AutonomosPresenter::deactivate()
{

}
void pag1_AutonomosPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 3) // PB11 BOLINHA
	    {
	    	model->reportCurrentScreen(Model::CAPA);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenBlockTransition();
	    }
	    else if (buttonId == 2) // PA3 TRIANGULO
	    {
	    	model->reportCurrentScreen(Model::INSPECAO);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoInspecao_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	    	model->reportCurrentScreen(Model::AREA_TESTE);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoArea_de_Teste_SAScreenSlideTransitionWest();
	    }

	}
}
