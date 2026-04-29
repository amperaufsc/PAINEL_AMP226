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

void TestesPresenter::updateTempMotorValue(int val)
{
	view.updateTempMotor(val);
}
void TestesPresenter::updateTensaoInversorValue(float val)
{
	view.updateTensaoInversor(val);
}
void TestesPresenter::updateSOCValue(int val)
{
	view.updateCorrenteAcumulador(val);
}
void TestesPresenter::updateTempInversorValue(int val)
{
	view.updateTempInversor(val);
}
void TestesPresenter::updateTensaoCelulaMinValue(int val)
{
	view.updateTensaoCelulaMin(val);
}

void TestesPresenter::updateTempAcumuladorValue(int val)
{
	view.updateTempAcumulador(val);
}
void TestesPresenter::updateTensaoHVValue(float val)
{
	view.updateTensaoHV(val);
}
void TestesPresenter::updateCorrenteAcumuladorValue(float val)
{
	view.updateCorrenteAcumulador(val);
}
void TestesPresenter::updateRPMValue(int val)
{
	view.updateRPM(val);
}

// --- Implementação das Falhas ---
void TestesPresenter::updateFalhaTMSValue(int val)
{
	view.updateFalhaTMS(val);
}
void TestesPresenter::updateFalhaINVValue(int val)
{
	view.updateFalhaINV(val);
}
void TestesPresenter::updateFalhaECUValue(int val)
{
	view.updateFalhaECU(val);
}

void TestesPresenter::hwButtonClicked(uint8_t buttonId)
{

	    if (buttonId == 2) //  // BOLINHA
	    {
	        static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenSlideTransitionWest();
	    }

}




