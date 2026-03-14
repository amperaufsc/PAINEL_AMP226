#include <gui/autocross_sa_screen/AutoCross_SAView.hpp>
#include <gui/autocross_sa_screen/AutoCross_SAPresenter.hpp>

AutoCross_SAPresenter::AutoCross_SAPresenter(AutoCross_SAView& v)
    : view(v)
{

}

void AutoCross_SAPresenter::activate()
{
}

void AutoCross_SAPresenter::deactivate()
{

}
void AutoCross_SAPresenter::hwButtonClicked(uint8_t buttonId)
{
	{
	    if (buttonId == 3) // PB11 BOLINHA
	    {
	     //   static_cast<FrontendApplication*>(Application::getInstance())->gotoSkinped_SAScreenBlockTransition();
	    }
	    else if (buttonId == 2) // PA3 TRIANGULO
	    {
	    	model->reportCurrentScreen(Model::AREA_TESTE);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoArea_de_Teste_SAScreenSlideTransitionEast();
	    }
	    else if (buttonId == 1) // PA2 X
	    {
	    	model->reportCurrentScreen(Model::ACELERACAO);
	    	static_cast<FrontendApplication*>(Application::getInstance())->gotoAceleracao_SAScreenSlideTransitionWest();
	    }

	}
}
