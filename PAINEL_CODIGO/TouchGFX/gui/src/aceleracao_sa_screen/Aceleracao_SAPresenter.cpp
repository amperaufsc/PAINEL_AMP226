#include <gui/aceleracao_sa_screen/Aceleracao_SAView.hpp>
#include <gui/aceleracao_sa_screen/Aceleracao_SAPresenter.hpp>

Aceleracao_SAPresenter::Aceleracao_SAPresenter(Aceleracao_SAView& v)
    : view(v)
{

}

void Aceleracao_SAPresenter::activate()
{
	 model->updateCurrentScreen(6);
	 model->setStartAutonomos(0);
}

void Aceleracao_SAPresenter::deactivate()
{

}
void Aceleracao_SAPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 2) // PB11 BOLINHA // PA2 TX-D1
	    {
	    	model->setStartAutonomos(6);
	    }
	    else if (buttonId == 1) // PA3 TRIANGULO
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoAutoCross_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 2) // PA2 X
	    {
	         static_cast<FrontendApplication*>(Application::getInstance())->gotoSkidped_SAScreenSlideTransitionWest();
	    }

	}
}
