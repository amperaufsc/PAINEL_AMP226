#include <gui/modoprova_screen/ModoProvaView.hpp>
#include <gui/modoprova_screen/ModoProvaPresenter.hpp>
#include <gui/common/FrontendApplication.hpp>

ModoProvaPresenter::ModoProvaPresenter(ModoProvaView& v) : view(v) { }

void ModoProvaPresenter::activate()
{
	model->idpagina(2);
}
void ModoProvaPresenter::deactivate()
{

}
void ModoProvaPresenter::Botao1(int bn1){}

void ModoProvaPresenter::Botao2(int bn2)
{
	if (bn2 == 1){
		static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenBlockTransition();

	}
}

void ModoProvaPresenter::Botao3(int bn3){}

void ModoProvaPresenter::updateTempMotor(int temp)
{
    view.updateTempMotor(temp);
}

void ModoProvaPresenter::updateTempAcc(int temp)
{
    view.updateTempAcc(temp);
}
