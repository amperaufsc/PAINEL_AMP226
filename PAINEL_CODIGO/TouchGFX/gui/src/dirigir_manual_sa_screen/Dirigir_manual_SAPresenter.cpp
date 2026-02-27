#include <gui/dirigir_manual_sa_screen/Dirigir_manual_SAView.hpp>
#include <gui/dirigir_manual_sa_screen/Dirigir_manual_SAPresenter.hpp>

Dirigir_manual_SAPresenter::Dirigir_manual_SAPresenter(Dirigir_manual_SAView& v)
    : view(v)
{

}

void Dirigir_manual_SAPresenter::activate()
{

}

void Dirigir_manual_SAPresenter::deactivate()
{

}

void Dirigir_manual_SAPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 3) // PB11 BOLINHA
	    {
	     //   static_cast<FrontendApplication*>(Application::getInstance())->gotoSkinped_SAScreenBlockTransition();
	    }
	    else if (buttonId == 2) // PA3 TRIANGULO
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoInspecao_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	         static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenSlideTransitionWest();
	    }

	}
}

