#include <gui/ebs_teste_sa_screen/EBS_Teste_SAView.hpp>
#include <gui/ebs_teste_sa_screen/EBS_Teste_SAPresenter.hpp>

EBS_Teste_SAPresenter::EBS_Teste_SAPresenter(EBS_Teste_SAView& v)
    : view(v)
{

}

void EBS_Teste_SAPresenter::activate()
{

}

void EBS_Teste_SAPresenter::deactivate()
{

}
void EBS_Teste_SAPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 3) // PB11 BOLINHA
	    {
	     //   static_cast<FrontendApplication*>(Application::getInstance())->gotoSkinped_SAScreenBlockTransition();
	    }
	    else if (buttonId == 2) // PA3 TRIANGULO
	    {
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoTrackdrive_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	         static_cast<FrontendApplication*>(Application::getInstance())->gotoInspecao_SAScreenSlideTransitionWest();
	    }

	}
}
