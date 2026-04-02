#include <gui/skidped_sa_screen/Skidped_SAView.hpp>
#include <gui/skidped_sa_screen/Skidped_SAPresenter.hpp>

Skidped_SAPresenter::Skidped_SAPresenter(Skidped_SAView& v)
    : view(v)
{

}

void Skidped_SAPresenter::activate()
{
<<<<<<< HEAD
=======
	 model->updateCurrentScreen(8);
	 model->setStartAutonomos(0);
>>>>>>> dia1603
}

void Skidped_SAPresenter::deactivate()
{

}
void Skidped_SAPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 2) // PB11 BOLINHA // PA2 TX-D1
	    {
	    	model->setStartAutonomos(4);
	    }
	    else if (buttonId == 3) // PA3 TRIANGULO
	    {
	    	model->reportCurrentScreen(Model::ACELERACAO);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoAceleracao_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	    	model->reportCurrentScreen(Model::TRACKDRIVE);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoTrackdrive_SAScreenSlideTransitionWest();
	    }

	}
}

