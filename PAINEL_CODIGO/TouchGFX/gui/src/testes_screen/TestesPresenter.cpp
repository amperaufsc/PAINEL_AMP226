#include <gui/testes_screen/TestesView.hpp>
#include <gui/testes_screen/TestesPresenter.hpp>

TestesPresenter::TestesPresenter(TestesView& v)
    : view(v)
{

}

void TestesPresenter::activate()
{
	 model->updateCurrentScreen(1);
}

void TestesPresenter::deactivate()
{

}

void TestesPresenter::updateTempMotorValue(int val)      { view.updateTempMotor(val); }
void TestesPresenter::updateTensaoInversorValue(int val) { view.updateTensaoInversor(val); }
void TestesPresenter::updateSOCValue(int val) { view.updateCorrenteAcumulador(val); }
void TestesPresenter::updateTempInversorValue(int val)   { view.updateTempInversor(val); }
void TestesPresenter::updateTensaoCelulaMinValue(int val){ view.updateTensaoCelulaMin(val); }
void TestesPresenter::updatePotenciaValue(int val)       { view.updatePotencia(val); }
void TestesPresenter::updateTempAcumuladorValue(int val) { view.updateTempAcumulador(val); }
void TestesPresenter::updateTensaoHVValue(int val)       { view.updateTensaoHV(val); }
void TestesPresenter::updateCorrenteAcumuladorValue(int val){ view.updateCorrenteAcumulador(val); }
void TestesPresenter::updateRPMValue(int val)            { view.updateRPM(val); }

// --- Implementação das Falhas ---
void TestesPresenter::updateFalhaBMSValue(int val)       { view.updateFalhaBMS(val); }
void TestesPresenter::updateFalhaINVValue(int val)       { view.updateFalhaINV(val); }
void TestesPresenter::updateFalhaECUValue(int val)       { view.updateFalhaECU(val); }

void TestesPresenter::hwButtonClicked(uint8_t buttonId)
{

	    if (buttonId == 3) // PB11
	    {
	        static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenSlideTransitionWest();
	    }

}




