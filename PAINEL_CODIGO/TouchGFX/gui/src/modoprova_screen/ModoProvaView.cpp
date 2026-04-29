#include <gui/modoprova_screen/ModoProvaView.hpp>
#include <touchgfx/Color.hpp>

ModoProvaView::ModoProvaView()
{
    // Construtor vazio
}

void ModoProvaView::setupScreen()
{
    ModoProvaViewBase::setupScreen();
}

void ModoProvaView::tearDownScreen()
{
    ModoProvaViewBase::tearDownScreen();
}

void ModoProvaView::updateRPMValue(int val)
{
    float rpm_dividido = val / 1000.0f;
    tacografo.setValue(rpm_dividido);
    tacografo.invalidate();
    Unicode::snprintfFloat(RPM_unBuffer, RPM_UN_SIZE, "%.1f", rpm_dividido);
    xmil.invalidate();

    //animação da cor da rotação do motor
    //depois ver quais cores ficarao mais bonitinhas e o range da rotaçao do motor
    if (val < 100) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255)); // branco
    }
    else if (val >= 100 && val <= 1000) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(0, 0, 255)); // azul frio
    }
    else if (val > 1000 && val <= 2000) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(92, 108, 208)); // azul claro
    }
    else if (val > 2000 && val <= 2500) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0)); // verde
    }
    else if (val > 2500 && val <= 3400) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0)); // amarelo
    }
    else if (val > 3400 && val <= 4000) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110)); // rosa escuro
    }
    else if (val > 4000) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0)); // vermelho
    }


    xmil.invalidate();
    RPM_un.invalidate();
}

void ModoProvaView::updateSpeedValue(int val) {
    velocimetro.setValue(val);
    velocimetro.invalidate();

    Unicode::snprintf(velocidade_unBuffer, VELOCIDADE_UN_SIZE, "%d", val);
    velocidade_un.invalidate();
}

void ModoProvaView::updateSOC(int val)
{
    bateria.setValue(val);
    Unicode::snprintf(bateria_unBuffer, BATERIA_UN_SIZE, "%d", val);
    bateria_un.invalidate();
    bateria.invalidate();
}
void ModoProvaView::updateFreio(int val)
{
    freio_bar.setValue(val);
    Unicode::snprintf(freio_unBuffer, FREIO_UN_SIZE, "%d", val);
    freio_bar.invalidate();
    freio_un.invalidate();
}

void ModoProvaView::updateAcelerador(int val)
{
    Acelarador_bar.setValue(val);
    Unicode::snprintf(acelerador_unBuffer, ACELERADOR_UN_SIZE, "%d", val);
    Acelarador_bar.invalidate();
    acelerador_un.invalidate();
}
void ModoProvaView::updateTensaoHV(float val) {
	Unicode::snprintfFloat(TensaoHV_unBuffer, TENSAOHV_UN_SIZE, "%.1f", val);
    TensaoHV_un.invalidate();
}

void ModoProvaView::updateDistancia(float val) {
    Unicode::snprintfFloat(distancia_unBuffer, DISTANCIA_UN_SIZE, "%.1f" , val);
    distancia_un.invalidate();
}

void ModoProvaView::updateTempAcumulador(int val) {
	    Unicode::snprintf(TempAcumulador_unBuffer, TEMPACUMULADOR_UN_SIZE, "%d", val);
	    if (val > 50) {
	        TempAcumulador_un.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
	    } else {
	        TempAcumulador_un.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	    }
	    TempAcumulador_un.invalidate();
}
