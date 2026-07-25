#ifndef TESTESVIEW_HPP
#define TESTESVIEW_HPP

#include <gui_generated/testes_screen/TestesViewBase.hpp>
#include <gui/testes_screen/TestesPresenter.hpp>

class TestesView : public TestesViewBase
{
public:
	TestesView();
	virtual ~TestesView() {}
	virtual void setupScreen();
	virtual void tearDownScreen();

	//virtual void updateFalhaTMS(int falha);         //comentado: nao tem mais widget na tela nova
	virtual void updateFalhaECU(int falha);
	virtual void updateFalhaINV(int falha);
	virtual void RTDbotao(int rtd);
	//virtual void updateSOC(int soc);                //comentado: nao tem mais widget na tela nova
	virtual void updateRPM(int rpm);
	virtual void updateTempMotor(int temp);
	virtual void updateTempInversor(int temp);
	//virtual void updateTempAcc(int temp);           //comentado: nao tem mais widget na tela nova
	virtual void updateCorrenteHV(float corrente);
	virtual void updateCorrenteInv(float corrente);
	virtual void updateTensaoHV(float tesao);         //reativado: widget TensaoHV_un voltou na tela
	virtual void updateTensaoInversor(float tesao);
	//virtual void updateTensaoCelulaMin(int tesao);  //comentado: nao tem mais widget na tela nova
	//virtual void updateTensaoCelulaMax(int tesao);  //comentado: nao tem mais widget na tela nova

	//widgets novos da tela de testes
	virtual void updateDistancia(int metros);
	virtual void updateControlWord(int cw);
	virtual void updateStatusInversor(int status);
	virtual void updateCurrentState(int estado);
	virtual void updateTorque(int torque);

	virtual void handleTickEvent();
	void resetRelogio();

protected:
	//float valTensaoMin;   //comentado: so era usado pelas tensoes de celula (sem widget agora)
	//float valTensaoMax;   //comentado: so era usado pelas tensoes de celula (sem widget agora)
	float correntelixo = 0.0f;


	uint32_t baseTick;
	int horas;
	int minutos;
	int segundos;
};

#endif // TESTESVIEW_HPP
