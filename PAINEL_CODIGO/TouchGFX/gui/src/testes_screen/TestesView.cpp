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

void TestesView::updateFalhaTMS(int falha)
{
    Unicode::snprintf(falhatmsuniBuffer, FALHATMSUNI_SIZE, "%d", falha);

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
    falhatmsuni.invalidate();
}

void TestesView::updateFalhaECU(int falha)
{
    Unicode::snprintf(falhaecuuniBuffer, FALHAECUUNI_SIZE, "%d", falha);

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
    falhaecuuni.invalidate();
}

void TestesView::updateFalhaINV(int falha)
{
    Unicode::snprintf(falhainvuniBuffer, FALHAINVUNI_SIZE, "%d", falha);

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
    falhainvuni.invalidate();
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
//    Unicode::snprintf(socuniBuffer, SOCUNI_SIZE, "%d", soc);
//    socuni.invalidate();
}

void TestesView::updateRPM(int rpm)
{
//    Unicode::snprintf(rpmuniBuffer, RPMUNI_SIZE, "%d", rpm);
//    rpmuni.invalidate();
}

void TestesView::updateTempMotor(int temp)
{
//    Unicode::snprintf(tempmotoruniBuffer, TEMPMOTORUNI_SIZE, "%d", temp);
//    tempmotoruni.invalidate();
}

void TestesView::updateTempInversor(int temp)
{
//    Unicode::snprintf(tempinvuniBuffer, TEMPINVUNI_SIZE, "%d", temp);
//    tempinvuni.invalidate();
}

void TestesView::updateTempAcc(int temp)
{
//	    Unicode::snprintf(tempaccuniBuffer, TEMPACCUNI_SIZE, "%d", temp);
//
//	    if (temp < 20)
//	    {
//
//	        tempaccuni.setColor(touchgfx::Color::getColorFromRGB(92,198,208));
//	    }
//	    else if (temp > 40)
//	    {
//
//	        tempaccuni.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
//	    }
//	    else
//	    {
//
//	        tempaccuni.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
//	    }
//
//
//	    tempaccuni.invalidate();
}

void TestesView::updateCorrenteHV(float corrente)
{
//    Unicode::snprintfFloat(correntehvuniBuffer, CORRENTEHVUNI_SIZE, "%.1f", corrente);
//    correntehvuni.invalidate();
}

void TestesView::updateCorrenteInv(float corrente)
{
//    Unicode::snprintfFloat(correnteinvuniBuffer, CORRENTEINVUNI_SIZE, "%.1f", corrente);
//    correnteinvuni.invalidate();
}

void TestesView::updateTensaoHV(float tesao)
{
//    Unicode::snprintfFloat(tensaohvuniBuffer, TENSAOHVUNI_SIZE, "%.1f", tesao);
//    tensaohvuni.invalidate();
}

void TestesView::updateTensaoInversor(float tesao)
{
//    Unicode::snprintfFloat(tensaoinvuniBuffer, TENSAOINVUNI_SIZE, "%.1f", tesao);
//    tensaoinvuni.invalidate();
}

void TestesView::updateTensaoCelulaMin(int tesao)
{
//    valTensaoMin = (float)tesao / 10.0f;
//
//    Unicode::snprintfFloat(tensaocelminuniBuffer, TENSAOCELMINUNI_SIZE, "%.1f", valTensaoMin);
//
//    float diferenca = valTensaoMax - valTensaoMin;
//    if (diferenca < 0) diferenca = -diferenca;
//
//    if (diferenca >= 0.5f)
//    {
//        tensaocelminuni.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
//        tensaocelmaxuni.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
//    }
//    else
//    {
//        tensaocelminuni.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
//        tensaocelmaxuni.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
//    }
//
//    tensaocelminuni.invalidate();
//    tensaocelmaxuni.invalidate();
}

void TestesView::updateTensaoCelulaMax(int tesao)
{
//    valTensaoMax = (float)tesao / 10.0f;
//
//    Unicode::snprintfFloat(tensaocelmaxuniBuffer, TENSAOCELMAXUNI_SIZE, "%.1f", valTensaoMax);
//
//    float diferenca = valTensaoMax - valTensaoMin;
//    if (diferenca < 0) diferenca = -diferenca;
//
//    if (diferenca >= 0.5f)
//    {
//        tensaocelminuni.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
//        tensaocelmaxuni.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
//    }
//    else
//    {
//        tensaocelminuni.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
//        tensaocelmaxuni.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
//    }
//
//    tensaocelminuni.invalidate();
//    tensaocelmaxuni.invalidate();
}
