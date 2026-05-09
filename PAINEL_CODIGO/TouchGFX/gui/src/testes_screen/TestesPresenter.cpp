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

void TestesPresenter::updateTempMotorValue(int tmot)
{
	view.updateTempMotor(tmot);
}
void TestesPresenter::updateTensaoInversorValue(float inv)
{
	view.updateTensaoInversor(inv);
}
void TestesPresenter::updateSOCValue(int soc)
{
	view.updateCorrenteAcumulador(soc);
}
void TestesPresenter::updateTempInversorValue(int tinv)
{
	view.updateTempInversor(tinv);
}
void TestesPresenter::updateTensaoCelulaMinValue(int mc)
{
	view.updateTensaoCelulaMin(mc);
}
void TestesPresenter::updateTempAcumuladorValue(int tacu)
{
	view.updateTempAcumulador(tacu);
}
void TestesPresenter::updateTensaoHVValue(float hv)
{
	view.updateTensaoHV(hv);
}
void TestesPresenter::updateCorrenteAcumuladorValue(float acu)
{
	view.updateCorrenteAcumulador(acu);
}
void TestesPresenter::updateRPMValue(int rpm)
{
	view.updateRPM(rpm);
}

// --- Implementação das Falhas ---
void TestesPresenter::updateFalhaTMSValue(int tms)
{
	view.updateFalhaTMS(tms);
}
void TestesPresenter::updateFalhaINVValue(int finv)
{
	view.updateFalhaINV(finv);
}
void TestesPresenter::updateFalhaECUValue(int ecu)
{
	view.updateFalhaECU(ecu);
}
void TestesPresenter::RTDativo(int rtd)
{
	view.RTDativo(rtd);
}
void TestesPresenter::hwButtonClicked(uint8_t buttonId)
{
	if (buttonId == 2)// BOLINHA
	{
		static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenSlideTransitionWest();
	}

}




