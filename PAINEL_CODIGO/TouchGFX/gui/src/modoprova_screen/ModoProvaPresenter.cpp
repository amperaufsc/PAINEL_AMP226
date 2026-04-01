#include <gui/modoprova_screen/ModoProvaView.hpp>
#include <gui/modoprova_screen/ModoProvaPresenter.hpp>
#include <gui/common/FrontendApplication.hpp> // ESSENCIAL PARA O TRANSIÇÃO DE TELA

ModoProvaPresenter::ModoProvaPresenter(ModoProvaView& v) : view(v) { }

void ModoProvaPresenter::activate() {

	    model->updateCurrentScreen(3); // ID para Modo Prova

}
void ModoProvaPresenter::deactivate() { }

void ModoProvaPresenter::hwButtonClicked(uint8_t buttonId)
{
    if (buttonId == 2) // PA2 TX-D1 BOLINHA
    {
        static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenSlideTransitionWest();
    }
}

void ModoProvaPresenter::updateRPMValue(int val)
{
    view.updateRPMValue(val);
}
void ModoProvaPresenter::updateSpeedValue(int val)
{
    view.updateSpeedValue(val);
}
void ModoProvaPresenter::updateSOCValue(int val)
{
    view.updateSOC(val);
}
void ModoProvaPresenter::updateFreioValue(int val)
{
	view.updateFreio(val);
}
void ModoProvaPresenter::updateAceleradorValue(int val)
{
	view.updateAcelerador(val);
}
void ModoProvaPresenter::updateTensaoHVValue(int val)
{
	view.updateTensaoHV(val);
}
void ModoProvaPresenter::updateDistanciaValue(float val)
{
	view.updateDistancia(val);
}
void ModoProvaPresenter::updatePotenciaValue(int val)
{
	view.updatePotencia(val);
}
void ModoProvaPresenter::updateTempAcumuladorValue(int val)
{
	view.updateTempAcumulador(val);
}
