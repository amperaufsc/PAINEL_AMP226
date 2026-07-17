#include <gui/aceleracao_sa_screen/Aceleracao_SAView.hpp>
#include <gui/aceleracao_sa_screen/Aceleracao_SAPresenter.hpp>

Aceleracao_SAPresenter::Aceleracao_SAPresenter(Aceleracao_SAView& v)
    : view(v)
{

}

void Aceleracao_SAPresenter::activate()
{
    gostateaceleracao = 0;
    missao = 0;
    view.ativacaobotao(gostateaceleracao);
}

void Aceleracao_SAPresenter::deactivate()
{

}

void Aceleracao_SAPresenter::Botao1(int bn1)
{
	if (bn1 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotoAutoCross_SAScreenSlideTransitionEast();
}
}

void Aceleracao_SAPresenter::Botao2(int bn2)
{
	if (bn2 == 1){
		gostateaceleracao += 1;
		if (gostateaceleracao > 3){gostateaceleracao = 0;}
		if (gostateaceleracao == 1){missao = 4;
		model->startautonomos(missao);}
		else {
		missao = 6;
		model->startautonomos(missao);}
		view.ativacaobotao(gostateaceleracao);
	}

}

void Aceleracao_SAPresenter::Botao3(int bn3)
{
	if (bn3 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotoSkidped_SAScreenSlideTransitionWest();
}
}
