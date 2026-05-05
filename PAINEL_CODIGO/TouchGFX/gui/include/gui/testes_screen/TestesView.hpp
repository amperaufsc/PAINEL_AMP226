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
    void updateButtonState(uint32_t buttonID);
    virtual void updateTempMotor(int val);
    virtual void updateTensaoInversor(float val);
    virtual void updateSOC(int val);
    virtual void updateTempInversor(int val);
    virtual void updateTensaoCelulaMin(int val);
    virtual void updateTempAcumulador(int val);
    virtual void updateTensaoHV(float num);
    virtual void updateRPM(int val);
    virtual void updateCorrenteAcumulador(float val);
    virtual void updateFalhaTMS(int val);
    virtual void updateFalhaINV(int val);
    virtual void updateFalhaECU(int val);
    virtual void RTDativo(int val);

protected:
};

#endif // TESTESVIEW_HPP
