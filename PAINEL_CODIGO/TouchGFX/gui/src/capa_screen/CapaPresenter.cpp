#include <gui/capa_screen/CapaView.hpp>
#include <gui/capa_screen/CapaPresenter.hpp>

CapaPresenter::CapaPresenter(CapaView& v)
    : view(v)
{

}

void CapaPresenter::activate()
{
	model->idpagina(0);
}

void CapaPresenter::deactivate()
{

}

//botoes de controle
void CapaPresenter::Botao1(int bn1) //*^*//
{
	if (bn1 == 1){
		static_cast<FrontendApplication*>(Application::getInstance())->gotoModoProvaScreenBlockTransition();
	}
}

void CapaPresenter::Botao2(int bn2)//*O*//
{
	if (bn2 == 1){
//		static_cast<FrontendApplication*>(Application::getInstance())->gotopag1_AutonomosScreenBlockTransition();
	}
}
void CapaPresenter::Botao3(int bn3)//*X*//
{
	if (bn3 == 1){
		static_cast<FrontendApplication*>(Application::getInstance())->gotoTestesScreenBlockTransition();
	}
}
