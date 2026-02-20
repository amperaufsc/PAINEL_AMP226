#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}
void Screen1Presenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 3) // PB11
	    {
	        static_cast<FrontendApplication*>(Application::getInstance())->gotoTestesScreenNoTransition();
	    }
	    else if (buttonId == 2) // PA3
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoModoProvaScreenNoTransition();
	    }
	    else if (buttonId == 1) // PA2
	    {
	         static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenNoTransition();
	    }

	}
}

void Screen1Presenter::updateCANData(int value)
{
    view.setCANValue(value);
}
