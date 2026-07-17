#include <gui/skidped_sa_screen/Skidped_SAView.hpp>
#include <gui/skidped_sa_screen/Skidped_SAPresenter.hpp>

Skidped_SAPresenter::Skidped_SAPresenter(Skidped_SAView& v)
    : view(v)
{

}

void Skidped_SAPresenter::activate()
{
    gostateskidped = 0;
    missao = 0;
    view.ativacaobotao(gostateskidped);
}

void Skidped_SAPresenter::deactivate()
{

}

void Skidped_SAPresenter::Botao1(int bn1)
{
	if (bn1 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotoAceleracao_SAScreenSlideTransitionEast();
}
}

void Skidped_SAPresenter::Botao2(int bn2)
{
	if (bn2 == 1){
		gostateskidped += 1;
		if (gostateskidped > 3){gostateskidped = 0;}
		if (gostateskidped == 1){
			missao = 3;
		model->startautonomos(missao);}
		else {
		missao = 6;
		model->startautonomos(missao);}
		view.ativacaobotao(gostateskidped);
	}

}

void Skidped_SAPresenter::Botao3(int bn3)
{
	if (bn3 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotoTrackdrive_SAScreenSlideTransitionWest();
}
}
