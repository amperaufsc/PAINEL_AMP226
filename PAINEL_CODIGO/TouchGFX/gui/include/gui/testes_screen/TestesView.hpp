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
    virtual void dadosteste(float correnteAcc, float soc, float potencia, float tempAcc, float tempMot, float tempInv, float tensaoInv, float tensaoHV, float tensaoMC, int rpm, float velocidade);

protected:
};

#endif // TESTESVIEW_HPP
