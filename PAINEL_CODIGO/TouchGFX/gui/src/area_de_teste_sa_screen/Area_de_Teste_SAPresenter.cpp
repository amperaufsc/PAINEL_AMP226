#include <gui/area_de_teste_sa_screen/Area_de_Teste_SAView.hpp>
#include <gui/area_de_teste_sa_screen/Area_de_Teste_SAPresenter.hpp>

Area_de_Teste_SAPresenter::Area_de_Teste_SAPresenter(Area_de_Teste_SAView& v)
    : view(v)
{

}

void Area_de_Teste_SAPresenter::activate()
{
<<<<<<< HEAD
=======
	 model->updateCurrentScreen(5);
	 model->setStartAutonomos(0);

>>>>>>> dia1603
}

void Area_de_Teste_SAPresenter::deactivate()
{

}
void Area_de_Teste_SAPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 2) // PB11 BOLINHA // PA2 TX-D1
	    {
	    	model->setStartAutonomos(1);
	    }
	    else if (buttonId == 3) // PA3 TRIANGULO
	    {
	    	model->reportCurrentScreen(Model::AUTONOMOS);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	    	model->reportCurrentScreen(Model::AUTOCROSS);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoAutoCross_SAScreenSlideTransitionWest();
	    }

	}
}
void Area_de_Teste_SAPresenter::updateAutonomos(int val) { view.updateAutonomos(val); }
