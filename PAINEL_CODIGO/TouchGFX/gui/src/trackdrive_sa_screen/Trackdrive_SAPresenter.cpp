#include <gui/trackdrive_sa_screen/Trackdrive_SAView.hpp>
#include <gui/trackdrive_sa_screen/Trackdrive_SAPresenter.hpp>

Trackdrive_SAPresenter::Trackdrive_SAPresenter(Trackdrive_SAView& v)
    : view(v)
{

}

void Trackdrive_SAPresenter::activate()
{
    gostatetrackdrive = 0;
    missao = 0;
    view.ativacaobotao(gostatetrackdrive);
}

void Trackdrive_SAPresenter::deactivate()
{

}

void Trackdrive_SAPresenter::Botao1(int bn1)
{
	if (bn1 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotoSkidped_SAScreenSlideTransitionEast();
}
}

void Trackdrive_SAPresenter::Botao2(int bn2)
{
	if (bn2 == 1){
		gostatetrackdrive += 1;
		if (gostatetrackdrive > 3){gostatetrackdrive = 0;}
		if (gostatetrackdrive == 1){missao = 2;
		model->startautonomos(missao);}
		else {
		missao = 6;
		model->startautonomos(missao);}
		view.ativacaobotao(gostatetrackdrive);
	}

}

void Trackdrive_SAPresenter::Botao3(int bn3)
{
	if (bn3 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotocalibragem_SAScreenSlideTransitionWest();
}
}
