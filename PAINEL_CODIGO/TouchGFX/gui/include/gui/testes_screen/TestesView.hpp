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

    // Sensores e Medidas
    virtual void updateRPMValue(int rpm);


    //temperatura
    virtual void updateTempAcumuladorValue(int tacu);
    virtual void updateTempInversorValue(int tinv);
    virtual void updateTempMotorValue(int tmot);

    //tensao e corrente
    virtual void updateMinCel(int mc);
    virtual void updateTensaoHVValue(float hv);
    virtual void updateTensaoInversorValue(float inv);
    virtual void updateCorrenteAcumuladorValue(float acu);

    // Falhas
    virtual void updateFalhaTMSValue(int tms);
    virtual void updateFalhaINVValue(int finv);
    virtual void updateFalhaECUValue(int ecu);
    virtual void RTDativo(int rtd);

protected:
};

#endif // TESTESVIEW_HPP
