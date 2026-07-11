#include <gui/testes_screen/TestesView.hpp>
#include <touchgfx/Color.hpp>
#include <stdio.h>
#include "stm32u5xx_hal.h"

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

void TestesView::resetRelogio()
{
    baseTick = HAL_GetTick();
    horas = 0;
    minutos = 0;
    segundos = 0;
    Unicode::snprintf(relogioBuffer, RELOGIO_SIZE, "%02d:%02d:%02d", horas, minutos, segundos);
    relogio.invalidate();
}

void TestesView::handleTickEvent()
{
    TestesViewBase::handleTickEvent();

    uint32_t totalSeg = (HAL_GetTick() - baseTick) / 1000;

    int novoSeg =  totalSeg        % 60;
    int novoMin = (totalSeg / 60)  % 60;
    int novoHor = (totalSeg / 3600) % 24;

    if (novoSeg != segundos)
    {
        segundos = novoSeg;
        minutos  = novoMin;
        horas    = novoHor;
        Unicode::snprintf(relogioBuffer, RELOGIO_SIZE, "%02d:%02d:%02d", horas, minutos, segundos);
        relogio.invalidate();
    }
}


void TestesView::updateFalhaTMS(int falha)
{
    Unicode::snprintf(FalhatmsuniBuffer, FALHATMSUNI_SIZE, "%d", falha);

    if (falha != 0)
    {
        tmsok.setVisible(false);
        falhatms.setVisible(true);
    }
    else
    {
        tmsok.setVisible(true);
        falhatms.setVisible(false);
    }

    tmsok.invalidate();
    falhatms.invalidate();
    Falhatmsuni.invalidate();
}

void TestesView::updateFalhaECU(int falha)
{
    Unicode::snprintf(FalhaecuuniBuffer, FALHAECUUNI_SIZE, "%d", falha);

    if (falha != 0)
    {
        ecuok.setVisible(false);
        falhaecu.setVisible(true);

    }
    else
    {
    	ecuok.setVisible(true);
    	falhaecu.setVisible(false);
    }

    ecuok.invalidate();
    falhaecu.invalidate();
    Falhaecuuni.invalidate();
}

void TestesView::updateFalhaINV(int falha)
{
    Unicode::snprintf(FalhainvuniBuffer, FALHAINVUNI_SIZE, "%d", falha);

    if (falha != 0)
    {
        invok.setVisible(false);
        falhainv.setVisible(true);
    }
    else
    {
        invok.setVisible(true);
        falhainv.setVisible(false);
    }

    invok.invalidate();
    falhainv.invalidate();
    Falhainvuni.invalidate();
}

void TestesView::RTDbotao(int rtd)
{
    if (rtd == 1)
    {
        rtdativado.setVisible(true);
        rtddesativado.setVisible(false);
    }
    else if (rtd == 0)
    {
        rtdativado.setVisible(false);
        rtddesativado.setVisible(true);
    }
    rtdativado.invalidate();
    rtddesativado.invalidate();
}

void TestesView::updateSOC(int soc)
{
    Unicode::snprintf(Soc_unBuffer, SOC_UN_SIZE, "%d", soc);
    Soc_un.invalidate();
}

void TestesView::updateRPM(int rpm)
{
	int rotacao = rpm;
    Unicode::snprintf(rpm_unBuffer, RPM_UN_SIZE, "%d", rotacao);
    rpm_un.invalidate();
}

void TestesView::updateTempMotor(int temp)
{
    Unicode::snprintf(Tempmotor_unBuffer, TEMPMOTOR_UN_SIZE, "%d", temp);
	Tempmotor_un.invalidate();
}

void TestesView::updateTempInversor(int temp)
{
    Unicode::snprintf(Tempinversor_unBuffer, TEMPINVERSOR_UN_SIZE, "%d", temp);
    Tempinversor_un.invalidate();
}

void TestesView::updateTempAcc(int temp)
{
	    Unicode::snprintf(Tempacc_unBuffer, TEMPACC_UN_SIZE, "%d", temp);

	    if (temp < 15)
	    {

	    	Tempacc_un.setColor(touchgfx::Color::getColorFromRGB(92,198,208));
	    }
	    else if (temp > 55)
	    {

	    	Tempacc_un.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
	    }
	    else
	    {

	    	Tempacc_un.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
	    }


	    Tempacc_un.invalidate();
}

void TestesView::updateCorrenteHV(float corrente)
{
	//esse if é so pra quando a corrente da menos de 0 ele ficar em 0
	if (corrente >= 0){
		Unicode::snprintfFloat(correntehv_unBuffer, CORRENTEHV_UN_SIZE, "%.1f", corrente);
		correntehv_un.invalidate();
	}
	else{
	    Unicode::snprintfFloat(correntehv_unBuffer, CORRENTEHV_UN_SIZE, "%.1f", correntelixo);
	    correntehv_un.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
	    correntehv_un.invalidate();
	}
}

void TestesView::updateCorrenteInv(float corrente)
{
	//esse if é so pra quando a corrente da menos de 0(que é impossivel) ele ficar em 0
	if (corrente >= 0){
    Unicode::snprintfFloat(correnteinv_unBuffer, CORRENTEINV_UN_SIZE, "%.1f", corrente);
    correnteinv_un.invalidate();
	}
	else{
	    Unicode::snprintfFloat(correnteinv_unBuffer, CORRENTEINV_UN_SIZE, "%.1f", correntelixo);
	    correnteinv_un.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
	    correnteinv_un.invalidate();
	}
}

void TestesView::updateTensaoHV(float tesao)
{
    Unicode::snprintfFloat(TensaoHV_unBuffer, TENSAOHV_UN_SIZE, "%.1f", tesao);
    TensaoHV_un.invalidate();
}

void TestesView::updateTensaoInversor(float tesao)
{
    Unicode::snprintfFloat(TensaoInversor_unBuffer, TENSAOINVERSOR_UN_SIZE, "%.1f", tesao);
    TensaoInversor_un.invalidate();
}

void TestesView::updateTensaoCelulaMin(int tesao)
{
    valTensaoMin = (float)tesao / 10.0f;

    Unicode::snprintfFloat(TensaoCelulamaisbaixa_unBuffer, TENSAOCELULAMAISBAIXA_UN_SIZE, "%.1f", valTensaoMin);

    float diferenca = valTensaoMax - valTensaoMin;
    if (diferenca >= 0.5f)
    {
    	TensaoCelulamaisbaixa_un.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    	TensaoCelulamaisalta_un.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    }
    else
    {
    	TensaoCelulamaisbaixa_un.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    	TensaoCelulamaisalta_un.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    }

    TensaoCelulamaisbaixa_un.invalidate();
    TensaoCelulamaisalta_un.invalidate();
}

void TestesView::updateTensaoCelulaMax(int tesao)
{
    valTensaoMax = (float)tesao / 10.0f;

    Unicode::snprintfFloat(TensaoCelulamaisalta_unBuffer, TENSAOCELULAMAISALTA_UN_SIZE, "%.1f", valTensaoMax);

    float diferenca = valTensaoMax - valTensaoMin;

    if (diferenca >= 0.5f)
    {
    	TensaoCelulamaisbaixa_un.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    	TensaoCelulamaisalta_un.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    }
    else
    {
    	TensaoCelulamaisbaixa_un.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    	TensaoCelulamaisalta_un.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    }
    TensaoCelulamaisbaixa_un.invalidate();
    TensaoCelulamaisalta_un.invalidate();
}
