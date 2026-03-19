#include <gui/autocross_sa_screen/AutoCross_SAView.hpp>
#include <gui/autocross_sa_screen/AutoCross_SAPresenter.hpp>

AutoCross_SAPresenter::AutoCross_SAPresenter(AutoCross_SAView& v)
    : view(v)
{

}

void AutoCross_SAPresenter::activate()
{
	 model->updateCurrentScreen(6);
	 model->setStartAutonomos(0);
}

void AutoCross_SAPresenter::deactivate()
{

}
void AutoCross_SAPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 2) // PB11 BOLINHA // PA2 TX-D1
	    {
	    	model->setStartAutonomos(2);
	    }
	    else if (buttonId == 3) // PA3 TRIANGULO
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoArea_de_Teste_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	         static_cast<FrontendApplication*>(Application::getInstance())->gotoAceleracao_SAScreenSlideTransitionWest();
	    }

	}
}
