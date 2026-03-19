#include <gui/pag1_autonomos_screen/pag1_AutonomosView.hpp>
#include <gui/pag1_autonomos_screen/pag1_AutonomosPresenter.hpp>

pag1_AutonomosPresenter::pag1_AutonomosPresenter(pag1_AutonomosView& v)
    : view(v)
{

}

void pag1_AutonomosPresenter::activate()
{
	 model->updateCurrentScreen(4);
}

void pag1_AutonomosPresenter::deactivate()
{

}
void pag1_AutonomosPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 2) // PB11 BOLINHA // PA2 TX-D1
	    {
	          static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenBlockTransition();
	    }
	    else if (buttonId == 3) // PA3 TRIANGULO
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoInspecao_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	         static_cast<FrontendApplication*>(Application::getInstance())->gotoArea_de_Teste_SAScreenSlideTransitionWest();
	    }

	}
}
