#include <gui/trackdrive_sa_screen/Trackdrive_SAView.hpp>
#include <gui/trackdrive_sa_screen/Trackdrive_SAPresenter.hpp>

Trackdrive_SAPresenter::Trackdrive_SAPresenter(Trackdrive_SAView& v)
    : view(v)
{

}

void Trackdrive_SAPresenter::activate()
{
	 model->updateCurrentScreen(9);
}

void Trackdrive_SAPresenter::deactivate()
{

}
void Trackdrive_SAPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 3) // PB11 BOLINHA
	    {
	    	model->setStartAutonomos(5);
	    }
	    else if (buttonId == 2) // PA3 TRIANGULO
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoSkidped_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	         static_cast<FrontendApplication*>(Application::getInstance())->gotoEBS_Teste_SAScreenSlideTransitionWest();
	    }

	}
}
