#include <gui/pag1_autonomos_screen/pag1_AutonomosView.hpp>
#include <gui/pag1_autonomos_screen/pag1_AutonomosPresenter.hpp>

pag1_AutonomosPresenter::pag1_AutonomosPresenter(pag1_AutonomosView& v)
    : view(v)
{

}

void pag1_AutonomosPresenter::activate()
{
<<<<<<< HEAD
=======
	 model->updateCurrentScreen(4);
	 model->setStartAutonomos(0);
>>>>>>> dia1603
}

void pag1_AutonomosPresenter::deactivate()
{

}
void pag1_AutonomosPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 2) // PB11 BOLINHA // PA2 TX-D1
	    {
	    	model->reportCurrentScreen(Model::CAPA);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenBlockTransition();
	    }
	    else if (buttonId == 3) // PA3 TRIANGULO
	    {
<<<<<<< HEAD
	    	model->reportCurrentScreen(Model::INSPECAO);
=======
>>>>>>> dia1603
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoInspecao_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
<<<<<<< HEAD
	    	model->reportCurrentScreen(Model::AREA_TESTE);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoArea_de_Teste_SAScreenSlideTransitionWest();
=======
	         static_cast<FrontendApplication*>(Application::getInstance())->gotoArea_de_Teste_SAScreenSlideTransitionWest();
>>>>>>> dia1603
	    }

	}
}
