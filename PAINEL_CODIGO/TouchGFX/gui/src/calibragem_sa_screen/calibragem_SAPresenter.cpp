#include <gui/calibragem_sa_screen/calibragem_SAView.hpp>
#include <gui/calibragem_sa_screen/calibragem_SAPresenter.hpp>

calibragem_SAPresenter::calibragem_SAPresenter(calibragem_SAView& v)
    : view(v)
{

}

void calibragem_SAPresenter::activate()
{
    gostatecalibragem = 0;
    missao = 0;
    view.ativacaobotao(gostatecalibragem);
}

void calibragem_SAPresenter::deactivate()
{

}

void calibragem_SAPresenter::Botao1(int bn1)
{
	if (bn1 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotoTrackdrive_SAScreenSlideTransitionEast();
}
}

void calibragem_SAPresenter::Botao2(int bn2)
{
	if (bn2 == 1){
		gostatecalibragem += 1;
		if (gostatecalibragem > 3){gostatecalibragem = 0;}
		if (gostatecalibragem == 1){missao = 1;
		model->startautonomos(missao);}
		view.ativacaobotao(gostatecalibragem);
	}

}

void calibragem_SAPresenter::Botao3(int bn3)
{
	if (bn3 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotocheck_SAScreenSlideTransitionWest();
}
}
