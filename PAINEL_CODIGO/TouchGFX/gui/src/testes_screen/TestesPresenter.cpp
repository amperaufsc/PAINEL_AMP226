#include <gui/testes_screen/TestesView.hpp>
#include <gui/testes_screen/TestesPresenter.hpp>

TestesPresenter::TestesPresenter(TestesView& v)
    : view(v)
{

}

void TestesPresenter::activate()
{
	model->idpagina(1); //id = 1 qualquer outro é teste
}

void TestesPresenter::deactivate()
{

}


//botoes de controle
void TestesPresenter::Botao1(int bn1)
{

}

void TestesPresenter::Botao2(int bn2)
{

	if (bn2 == 1){

	}

}

void TestesPresenter::Botao3(int bn3)
{

}

void TestesPresenter::updateFalhaTMS(int falha)
{
    view.updateFalhaTMS(falha);
}

void TestesPresenter::updateFalhaECU(int falha)
{
    view.updateFalhaECU(falha);
}

void TestesPresenter::updateFalhaINV(int falha)
{
    view.updateFalhaINV(falha);
}

void TestesPresenter::RTDbotao(int rtd)
{
    view.RTDbotao(rtd);
}

void TestesPresenter::updateSOC(int soc)
{
    view.updateSOC(soc);
}

void TestesPresenter::updateRPM(int rpm)
{
    view.updateRPM(rpm);
}

void TestesPresenter::updateTempMotor(int temp)
{
    view.updateTempMotor(temp);
}

void TestesPresenter::updateTempInversor(int temp)
{
    view.updateTempInversor(temp);
}

void TestesPresenter::updateTempAcc(int temp)
{
    view.updateTempAcc(temp);
}

void TestesPresenter::updateCorrenteHV(float corrente)
{
    view.updateCorrenteHV(corrente);
}

void TestesPresenter::updateCorrenteInv(float corrente)
{
    view.updateCorrenteInv(corrente);
}

void TestesPresenter::updateTensaoHV(float tesao)
{
    view.updateTensaoHV(tesao);
}

void TestesPresenter::updateTensaoInversor(float tesao)
{
    view.updateTensaoInversor(tesao);
}

void TestesPresenter::updateTensaoCelulaMin(int tesao)
{
    view.updateTensaoCelulaMin(tesao);
}

void TestesPresenter::updateTensaoCelulaMax(int tesao)
{
    view.updateTensaoCelulaMax(tesao);
}
