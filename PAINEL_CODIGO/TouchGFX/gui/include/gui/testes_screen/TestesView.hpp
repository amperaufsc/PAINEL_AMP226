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

	virtual void updateFalhaTMS(int falha);
    virtual void updateFalhaECU(int falha);
    virtual void updateFalhaINV(int falha);
    virtual void RTDbotao(int rtd);
    virtual void updateSOC(int soc);
    virtual void updateRPM(int rpm);
    virtual void updateTempMotor(int temp);
    virtual void updateTempInversor(int temp);
    virtual void updateTempAcc(int temp);
    virtual void updateCorrenteHV(float corrente);
    virtual void updateCorrenteInv(float corrente);
    virtual void updateTensaoHV(float tesao);
    virtual void updateTensaoInversor(float tesao);
    virtual void updateTensaoCelulaMin(int tesao);
    virtual void updateTensaoCelulaMax(int tesao);

protected:
    float valTensaoMin;
    float valTensaoMax;
    float correntelixo = 0.0f;
};

#endif // TESTESVIEW_HPP
