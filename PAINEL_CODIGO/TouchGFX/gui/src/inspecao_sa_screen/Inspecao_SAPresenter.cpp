#include <gui/inspecao_sa_screen/Inspecao_SAView.hpp>
#include <gui/inspecao_sa_screen/Inspecao_SAPresenter.hpp>

Inspecao_SAPresenter::Inspecao_SAPresenter(Inspecao_SAView& v)
    : view(v)
{

}

void Inspecao_SAPresenter::activate()
{
<<<<<<< HEAD
=======
	 model->updateCurrentScreen(11);
	 model->setStartAutonomos(0);
>>>>>>> dia1603
}

void Inspecao_SAPresenter::deactivate()
{

}
void Inspecao_SAPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 2) // PB11 BOLINHA // PA2 TX-D1
	    {
	    	model->setStartAutonomos(7);
	    }
	    else if (buttonId == 3) // PA3 TRIANGULO
	    {
	    	model->reportCurrentScreen(Model::EBS);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoEBS_Teste_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
<<<<<<< HEAD
	    	model->reportCurrentScreen(Model::AUTONOMOS);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenSlideTransitionWest();
=======
	         static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenSlideTransitionWest();
>>>>>>> dia1603
	    }

	}
}
