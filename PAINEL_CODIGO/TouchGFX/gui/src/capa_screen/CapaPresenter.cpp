#include <gui/capa_screen/CapaView.hpp>
#include <gui/capa_screen/CapaPresenter.hpp>

CapaPresenter::CapaPresenter(CapaView& v)
    : view(v)
{

}

void CapaPresenter::activate()
{
<<<<<<< HEAD
=======
	 model->updateCurrentScreen(0);
>>>>>>> dia1603
}

void CapaPresenter::deactivate()
{

}

void CapaPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 2) // PB11 BOLINHA // PA2 TX-D1
	    {
<<<<<<< HEAD
	    	model->reportCurrentScreen(Model::TESTES);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoTestesScreenBlockTransition();
=======
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenBlockTransition();
>>>>>>> dia1603
	    }
	    else if (buttonId == 3) // PA3 TRIANGULO
	    {
	    	model->reportCurrentScreen(Model::MODOPROVA);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoModoProvaScreenBlockTransition();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
<<<<<<< HEAD
	    	model->reportCurrentScreen(Model::AUTONOMOS);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenBlockTransition();
=======
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoTestesScreenBlockTransition();
>>>>>>> dia1603
	    }

	}
}


void CapaPresenter::updateCANData(int value)
{
    view.setCANValue(value);
}
