#include <gui/testes_screen/TestesView.hpp>
#include <touchgfx/Color.hpp>
#include <stdio.h>

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

void TestesView::updateTempMotor(int tmot) {
    Unicode::snprintf(Tempmotor_unBuffer, TEMPMOTOR_UN_SIZE, "%d", tmot);
    Tempmotor_un.invalidate();
}

void TestesView::updateTensaoInversor(float inv) {
	Unicode::snprintfFloat(TensaoInversor_unBuffer, TENSAOINVERSOR_UN_SIZE, "%.1f", inv);
    TensaoInversor_un.invalidate();
}

void TestesView::updateSOC(int soc) {
    Unicode::snprintf(CargaAcumulador_unBuffer, CARGAACUMULADOR_UN_SIZE, "%d", soc);
    Correnteacumulador_un.invalidate();
}

void TestesView::updateTempInversor(int tinv) {
    Unicode::snprintf(Tempinversor_unBuffer, TEMPINVERSOR_UN_SIZE, "%d", tinv);
    Tempinversor_un.invalidate();
}

void TestesView::updateMinCel(int mc) {
    Unicode::snprintf(TensaoCelulamaisbaixa_unBuffer, TENSAOCELULAMAISBAIXA_UN_SIZE, "%d", mc);
    TensaoCelulamaisbaixa_un.invalidate();
}

void TestesView::updateTempAcumulador(int tacu) {
    Unicode::snprintf(TempAcumulador_unBuffer, TEMPACUMULADOR_UN_SIZE, "%d", tacu);
    if (tacu > 45) {
        TempAcumulador_un.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    } else { TempAcumulador_un.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255)); }
    TempAcumulador_un.invalidate();
}

void TestesView::updateTensaoHV(float hv) {
	Unicode::snprintfFloat(TensaoHV_unBuffer, TENSAOHV_UN_SIZE, "%.1f", hv);
    TensaoHV_un.invalidate();
}


void TestesView::updateRPM(int rpm) {
    int rpm100 = rpm;
    Unicode::snprintf(RPM_unBuffer, RPM_UN_SIZE, "%d", rpm100);
    RPM_un.invalidate();
}

void TestesView::updateCorrenteAcumulador(float val) {
	Unicode::snprintfFloat(Correnteacumulador_unBuffer, CORRENTEACUMULADOR_UN_SIZE, "%.1f", val);
    Correnteacumulador_un.invalidate();
}

  //Atualizações de Falhas
void TestesView::updateFalhaTMS(int tms) {
    if (tms > 0) {
        valor_falhaBMS.setVisible(true);
        falhaBMS.setVisible(true);
        falhaBMS_azul.setVisible(false);
    } else {
        valor_falhaBMS.setVisible(false);
        falhaBMS.setVisible(false);
        falhaBMS_azul.setVisible(true);
    }

    Unicode::snprintf(valor_falhaBMSBuffer, VALOR_FALHABMS_SIZE, "%d", tms);

    valor_falhaBMS.invalidate();
    falhaBMS.invalidate();
    falhaBMS_azul.invalidate();
}

void TestesView::updateFalhaINV(int finv) {
    if (finv > 0) {
    	valor_falha_INV.setVisible(true);
    	falhainversor.setVisible(true);
        falhainversor_azul.setVisible(false);
    } else {
    	valor_falha_INV.setVisible(false);
    	falhainversor.setVisible(false);
        falhainversor_azul.setVisible(true);
    }

    Unicode::snprintf(valor_falha_INVBuffer, VALOR_FALHA_INV_SIZE, "%d", finv);

    falhainversor_azul.invalidateContent();
    falhainversor.invalidateContent();
    valor_falha_INV.invalidateContent();
}

void TestesView::updateFalhaECU(int ecu) {
    if (ecu > 0) {
    	valor_falha_ECU.setVisible(true);
    	falhaECU.setVisible(true);
    	falhaECU_azul.setVisible(false);
    } else {
    	valor_falha_ECU.setVisible(false);
    	falhaECU.setVisible(false);
    	falhaECU_azul.setVisible(true);
    }

    Unicode::snprintf(valor_falha_ECUBuffer, VALOR_FALHA_ECU_SIZE, "%d", ecu);

    falhaECU_azul.invalidate();
    falhaECU.invalidate();
    valor_falha_ECU.invalidate();

}
void TestesView::RTDativo(int rtd) {
    if (rtd == 3) {
    	rtdtestes.setVisible(true);
    } else {
    	rtdtestes.setVisible(false);
    }

    rtdtestes.invalidate();
}
