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
void ModoProvaPresenter::Botao1(int bn1)
{
	if (bn1 == 1){
		model->resetDistancia(); //zera a distancia percorrida
	}
}

void ModoProvaPresenter::Botao2(int bn2)
{
	if (bn2 == 1){
		static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenBlockTransition();

	}
}

void ModoProvaPresenter::Botao3(int bn3)
{
    if (bn3 == 1){
        view.resetRelogio();
    }
}

void ModoProvaPresenter::updateTempMotor(int temp)
{
    view.updateTempMotor(temp);
}

void ModoProvaPresenter::updateTempInversor(int temp)
{
    view.updateTempInversor(temp);
}

void ModoProvaPresenter::updateTempAcc(int temp)
{
    view.updateTempAcc(temp);
}

void ModoProvaPresenter::updateAcelerador(int acelera)
{
    view.updateAcelerador(acelera);
}

void ModoProvaPresenter::updateFreio(int freio)
{
    view.updateFreio(freio);
}
void ModoProvaPresenter::updateVelocidade(float vel)
{
    view.updateVelocidade(vel);
}

void ModoProvaPresenter::updateDistancia(int metros)
{
    view.updateDistancia(metros);
}
void ModoProvaPresenter::updateRPM(int rpm)
{
    view.updateRPM(rpm);
}

void ModoProvaPresenter::updateSOC(int soc)
{
    view.updateSOC(soc);
}

void ModoProvaPresenter::updatePotencia(float pot)
{
    view.updatePotencia(pot);
}

void ModoProvaPresenter::updateTensaoHV(float tesao)
{
    view.updateTensaoHV(tesao);
}
