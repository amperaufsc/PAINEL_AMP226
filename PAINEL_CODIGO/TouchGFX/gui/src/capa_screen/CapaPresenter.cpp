#include <gui/capa_screen/CapaView.hpp>
#include <gui/capa_screen/CapaPresenter.hpp>

CapaPresenter::CapaPresenter(CapaView& v)
    : view(v)
{

}

void CapaPresenter::activate()
{

}

void CapaPresenter::deactivate()
{

}

void CapaPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 3) // PB11 BOLINHA
	    {
	        static_cast<FrontendApplication*>(Application::getInstance())->gotoTestesScreenBlockTransition();
	    }
	    else if (buttonId == 2) // PA3 TRIANGULO
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoModoProvaScreenBlockTransition();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	         static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenBlockTransition();
	    }

	}
}


void CapaPresenter::updateCANData(int value)
{
    view.setCANValue(value);
}
