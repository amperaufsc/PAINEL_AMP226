#include <gui/pag1_autonomos_screen/pag1_AutonomosView.hpp>
#include <gui/pag1_autonomos_screen/pag1_AutonomosPresenter.hpp>

pag1_AutonomosPresenter::pag1_AutonomosPresenter(pag1_AutonomosView& v)
: view(v)
{

}

void pag1_AutonomosPresenter::activate()
{
	 model->startautonomos(6);
}

void pag1_AutonomosPresenter::deactivate()
{

}
void pag1_AutonomosPresenter::Botao1(int bn1)
{
	if (bn1 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotocheck_SAScreenSlideTransitionEast();
}
}

void pag1_AutonomosPresenter::Botao2(int bn2)
{
	if (bn2 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenSlideTransitionNorth();
}
}

void pag1_AutonomosPresenter::Botao3(int bn3)
{
	if (bn3 == 1){
	static_cast<FrontendApplication*>(Application::getInstance())->gotoAutoCross_SAScreenSlideTransitionWest();
}
}

