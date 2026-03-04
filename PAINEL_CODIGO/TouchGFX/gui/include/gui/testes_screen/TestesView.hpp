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
        virtual void updateTensaoInversor(int val);
        virtual void updateSOC(int val);
        virtual void updateTempInversor(int val);
        virtual void updateTensaoCelulaMin(int val);
        virtual void updatePotencia(int val);
        virtual void updateTempAcumulador(int val);
        virtual void updateTensaoHV(int val);
        virtual void updateRPM(int val);
        virtual void updateCorrenteAcumulador(int val);
            virtual void updateFalhaBMS(int val);
            virtual void updateFalhaINV(int val);
            virtual void updateFalhaECU(int val);

protected:
};

#endif // TESTESVIEW_HPP
