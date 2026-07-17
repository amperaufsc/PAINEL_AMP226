#include <gui/check_sa_screen/check_SAView.hpp>
#include <gui/check_sa_screen/check_SAPresenter.hpp>

check_SAPresenter::check_SAPresenter(check_SAView& v)
    : view(v)
{

}

void check_SAPresenter::activate()
{
    gostatecheck = 0;
    missao = 0;
    view.ativacaobotao(gostatecheck);
}

void check_SAPresenter::deactivate()
{

}

void check_SAPresenter::Botao1(int bn1)
{
	if (bn1 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotocalibragem_SAScreenSlideTransitionEast();
}
}

void check_SAPresenter::Botao2(int bn2)
{
	if (bn2 == 1){
		gostatecheck += 1;
		if (gostatecheck > 3){gostatecheck = 0;}
		if (gostatecheck == 1){missao = 0;
		model->startautonomos(missao);}
		else {
		missao = 6;
		model->startautonomos(missao);}
		view.ativacaobotao(gostatecheck);
	}

}

void check_SAPresenter::Botao3(int bn3)
{
	if (bn3 == 1){
	 static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenSlideTransitionWest();
}
}
