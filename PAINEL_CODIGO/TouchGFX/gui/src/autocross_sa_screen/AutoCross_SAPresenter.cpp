#include <gui/autocross_sa_screen/AutoCross_SAView.hpp>
#include <gui/autocross_sa_screen/AutoCross_SAPresenter.hpp>

AutoCross_SAPresenter::AutoCross_SAPresenter(AutoCross_SAView& v)
    : view(v)
{

}

void AutoCross_SAPresenter::activate()
{
    gostateautocross = 0;
    missao = 0;
    view.ativacaobotao(gostateautocross);
}

void AutoCross_SAPresenter::deactivate()
{

}

void AutoCross_SAPresenter::Botao1(int bn1)
{
	if (bn1 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenSlideTransitionEast();
}
}

void AutoCross_SAPresenter::Botao2(int bn2)
{
	if (bn2 == 1){
		gostateautocross += 1;
		if (gostateautocross > 3){gostateautocross = 0;}
		if (gostateautocross == 1){missao = 5;
		model->startautonomos(missao);}
		view.ativacaobotao(gostateautocross);
	}

}

void AutoCross_SAPresenter::Botao3(int bn3)
{
	if (bn3 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotoAceleracao_SAScreenSlideTransitionWest();
}
}
