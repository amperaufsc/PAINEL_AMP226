#include <gui/modoprova_screen/ModoProvaView.hpp>
#include <touchgfx/Color.hpp>

ModoProvaView::ModoProvaView()
{

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
    rpm0.invalidate();
    rpm1.invalidate();
    rpm2.invalidate();
    rpm3.invalidate();
    rpm4.invalidate();
    rpm5.invalidate();
    rpm6.invalidate();


    //animação da cor da rotação do motor
    if (val < 100) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255)); // branco
        rpm0.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    }
    else if (val >= 100 && val <= 1500) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0)); // vermelho
        rpm0.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    }
    else if (val > 1500 && val <= 2500) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(92, 108, 208)); // azul claro
        rpm0.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    }
    else if (val > 2500 && val <= 3100) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0)); // verde
        rpm0.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    }
    else if (val > 3100 && val <= 3500) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0)); // amarelo
        rpm0.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    }
    else if (val > 3500 && val <= 4500) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110)); // rosa escuro
        rpm0.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    }
    else if (val > 4500) {
        xmil.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0)); // vermelho
        rpm0.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        rpm6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    }


    xmil.invalidate();
    rpm0.invalidate();
    rpm1.invalidate();
    rpm2.invalidate();
    rpm3.invalidate();
    rpm4.invalidate();
    rpm5.invalidate();
    rpm6.invalidate();
    RPM_un.invalidate();
}

void ModoProvaView::updateSpeedValue(float val) {
    velocimetro.setValue(val);
    velocimetro.invalidate();

    Unicode::snprintfFloat(velocidade_unBuffer, VELOCIDADE_UN_SIZE, "%.1f", val);
    velocidade_un.invalidate();
}

void ModoProvaView::updateSOC(int val)
{	if (val >= 40) {
		bateria_un.setColor(touchgfx::Color::getColorFromRGB(92, 108, 208)); // azul claro
	}
	else if (val < 40 && val >= 20) {
		bateria_un.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0)); // amarelo
	}
	else if (val < 20 ) {
		bateria_un.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110)); // rosa escuro
	}

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
void ModoProvaView::updateTempInversor(int val) {
	Unicode::snprintfFloat(TensaoHV_unBuffer, TENSAOHV_UN_SIZE, "%d", val);
	 if (val > 45) {
		 TensaoHV_un.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
		    } else {
		 TensaoHV_un.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		    }
    TensaoHV_un.invalidate();
}

void ModoProvaView::updateDistancia(float val) {
    Unicode::snprintfFloat(distancia_unBuffer, DISTANCIA_UN_SIZE, "%.1f" , val);
    distancia_un.invalidate();
}

void ModoProvaView::updateTempAcumulador(int val) {
	    Unicode::snprintf(TempAcumulador_unBuffer, TEMPACUMULADOR_UN_SIZE, "%d", val);
	    if (val > 45) {
	        TempAcumulador_un.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
	    } else {
	        TempAcumulador_un.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	    }
	    TempAcumulador_un.invalidate();
}
