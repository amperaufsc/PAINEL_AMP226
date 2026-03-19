#include <gui/capa_screen/CapaView.hpp>
#include <gui/capa_screen/CapaPresenter.hpp>

CapaPresenter::CapaPresenter(CapaView& v)
    : view(v)
{

}

void CapaPresenter::activate()
{
	 model->updateCurrentScreen(0);
}

void CapaPresenter::deactivate()
{

}

void CapaPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 2) // PB11 BOLINHA // PA2 TX-D1
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenBlockTransition();
	    }
	    else if (buttonId == 3) // PA3 TRIANGULO
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoModoProvaScreenBlockTransition();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoTestesScreenBlockTransition();
	    }

	}
}


void CapaPresenter::updateCANData(int value)
{
    view.setCANValue(value);
}
