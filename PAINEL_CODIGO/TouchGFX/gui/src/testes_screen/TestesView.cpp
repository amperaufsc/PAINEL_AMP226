#include <gui/testes_screen/TestesView.hpp>

TestesView::TestesView()
{

}

void TestesView::setupScreen()
{
    TestesViewBase::setupScreen();
}

void TestesView::tearDownScreen()
{
    TestesViewBase::tearDownScreen();
}

void TestesView::dadosteste(float correnteAcc, float soc, float potencia, float tempAcc, float tempMot, float tempInv, float tensaoInv, float tensaoHV, float tensaoMC, int rpm, float velocidade)
{

    Unicode::snprintfFloat(Correnteacumulador_unBuffer, CORRENTEACUMULADOR_UN_SIZE, "%d", correnteAcc);
    Unicode::snprintfFloat(CargaAcumulador_unBuffer, CARGAACUMULADOR_UN_SIZE, "%d", soc);
    Unicode::snprintfFloat(Potencia_unBuffer, POTENCIA_UN_SIZE, "%d", potencia);
    Unicode::snprintfFloat(TempAcumulador_unBuffer, TEMPACUMULADOR_UN_SIZE, "%d", tempAcc);
    Unicode::snprintfFloat(Tempmotor_unBuffer, TEMPMOTOR_UN_SIZE, "%d", tempMot);
    Unicode::snprintfFloat(Tempinversor_unBuffer, TEMPINVERSOR_UN_SIZE, "%d", tempInv);
    Unicode::snprintfFloat(TensaoInversor_unBuffer, TENSAOINVERSOR_UN_SIZE, "%d", tensaoInv);
    Unicode::snprintfFloat(TensaoHV_unBuffer, TENSAOHV_UN_SIZE, "%d", tensaoHV);
    Unicode::snprintfFloat(TensaoCelulamaisbaixa_unBuffer, TENSAOCELULAMAISBAIXA_UN_SIZE, "%d", tensaoMC);


    Unicode::snprintf(RPM_unBuffer, RPM_UN_SIZE, "%d", rpm);


    Correnteacumulador_un.invalidate();
    CargaAcumulador_un.invalidate();
    Potencia_un.invalidate();
    TempAcumulador_un.invalidate();
    Tempmotor_un.invalidate();
    Tempinversor_un.invalidate();
    TensaoInversor_un.invalidate();
    TensaoHV_un.invalidate();
    TensaoCelulamaisbaixa_un.invalidate();
    RPM_un.invalidate();
}
