#include <gui/skidped_sa_screen/Skidped_SAView.hpp>
#include <gui/skidped_sa_screen/Skidped_SAPresenter.hpp>

Skidped_SAPresenter::Skidped_SAPresenter(Skidped_SAView& v)
    : view(v)
{

}

void Skidped_SAPresenter::activate()
{
	 model->updateCurrentScreen(8);
}

void Skidped_SAPresenter::deactivate()
{

}
void Skidped_SAPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 3) // PB11 BOLINHA
	    {
	    	model->setStartAutonomos(4);
	    }
	    else if (buttonId == 2) // PA3 TRIANGULO
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoAceleracao_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	         static_cast<FrontendApplication*>(Application::getInstance())->gotoTrackdrive_SAScreenSlideTransitionWest();
	    }

	}
}

