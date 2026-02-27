#include <gui/area_de_teste_sa_screen/Area_de_Teste_SAView.hpp>
#include <gui/area_de_teste_sa_screen/Area_de_Teste_SAPresenter.hpp>

Area_de_Teste_SAPresenter::Area_de_Teste_SAPresenter(Area_de_Teste_SAView& v)
    : view(v)
{

}

void Area_de_Teste_SAPresenter::activate()
{

}

void Area_de_Teste_SAPresenter::deactivate()
{

}
void Area_de_Teste_SAPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 3) // PB11 BOLINHA
	    {
	     //     static_cast<FrontendApplication*>(Application::getInstance())->CapaScreenSlideTransition();
	    }
	    else if (buttonId == 2) // PA3 TRIANGULO
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	         static_cast<FrontendApplication*>(Application::getInstance())->gotoAutoCross_SAScreenSlideTransitionWest();
	    }

	}
}
