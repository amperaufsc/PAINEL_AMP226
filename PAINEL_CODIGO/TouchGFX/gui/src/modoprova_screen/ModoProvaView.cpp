
#include <gui/modoprova_screen/ModoProvaView.hpp>
#include <touchgfx/Color.hpp>
#include <stdio.h>
#include "stm32u5xx_hal.h"

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

void ModoProvaView::updateTempMotor(int temp)
{
	Unicode::snprintf(Tempmotor_unBuffer, TEMPMOTOR_UN_SIZE, "%d", temp);
	Tempmotor_un.invalidate();
}

void ModoProvaView::updateTempAcc(int temp)
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

void ModoProvaView::updateRPM(int rpm)
{
	float rotacaotacometro = rpm/1000.0 ; // aqui so deixa em x100 pra nao sobrecarregar o sistema
    Unicode::snprintf(rpm_unBuffer, RPM_UN_SIZE, "%d", rotacao);
    tacometro.setValue(rotacaotacometro);

    if (rpm < 1000) {
    	        rpm0.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	        rpm1.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	        rpm2.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	        rpm3.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	        rpm4.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	        rpm5.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	        rpm6.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	    }
    	    else if (rpm >= 1000 && rpm < 2000) {
    	        rpm0.setColor(touchgfx::Color::getColorFromRGB(64, 126, 147));
    	        rpm1.setColor(touchgfx::Color::getColorFromRGB(64, 126, 147));
    	        rpm2.setColor(touchgfx::Color::getColorFromRGB(64, 126, 147));
    	        rpm3.setColor(touchgfx::Color::getColorFromRGB(64, 126, 147));
    	        rpm4.setColor(touchgfx::Color::getColorFromRGB(64, 126, 147));
    	        rpm5.setColor(touchgfx::Color::getColorFromRGB(64, 126, 147));
    	        rpm6.setColor(touchgfx::Color::getColorFromRGB(64, 126, 147));
    	    }
    	    else if (rpm >= 2000 && rpm < 2850) {
    	        rpm0.setColor(touchgfx::Color::getColorFromRGB(92, 198, 208));
    	        rpm1.setColor(touchgfx::Color::getColorFromRGB(92, 198, 208));
    	        rpm2.setColor(touchgfx::Color::getColorFromRGB(92, 198, 208));
    	        rpm3.setColor(touchgfx::Color::getColorFromRGB(92, 198, 208));
    	        rpm4.setColor(touchgfx::Color::getColorFromRGB(92, 198, 208));
    	        rpm5.setColor(touchgfx::Color::getColorFromRGB(92, 198, 208));
    	        rpm6.setColor(touchgfx::Color::getColorFromRGB(92, 198, 208));
    	    }
    	    else if (rpm >= 2850 && rpm < 3150) {
    	        rpm0.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    	        rpm1.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    	        rpm2.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    	        rpm3.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    	        rpm4.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    	        rpm5.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    	        rpm6.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    	    }
    	    else if (rpm >= 3150 && rpm < 4000) {
    	        rpm0.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
    	        rpm1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
    	        rpm2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
    	        rpm3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
    	        rpm4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
    	        rpm5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
    	        rpm6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
    	    }
    	    else if (rpm >= 4000 && rpm <= 5000) {
    	        rpm0.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	        rpm1.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	        rpm2.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	        rpm3.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	        rpm4.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	        rpm5.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	        rpm6.setColor(touchgfx::Color::getColorFromRGB(222, 34, 110));
    	    }
    	    else if (rpm > 5000) {
    			rpm0.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    			rpm1.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    			rpm2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    			rpm3.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    			rpm4.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    			rpm5.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    			rpm6.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    		}

    tacometro.invalidate();
    rpm_un.invalidate();
}
void ModoProvaView::updateSOC(int soc)
{
	Unicode::snprintf(bateria_unBuffer, BATERIA_UN_SIZE, "%d", soc);
	bateria_un.invalidate();
	bateria.setValue(soc);
	bateria.invalidate();
}
void ModoProvaView::updateVelocidade(int vel)
{
	    Unicode::snprintf(velocidade_unBuffer, VELOCIDADE_UN_SIZE, "%d", vel);
	    velocidade_un.invalidate();
	    velocimetro.setValue(vel);
	    velocimetro.invalidate();
}
void ModoProvaView::updateDistancia(int metros)
{
	    Unicode::snprintf(distancia_unBuffer, DISTANCIA_UN_SIZE, "%d", metros);
	    distancia_un.invalidate();
}
void ModoProvaView::updateAcelerador(int acelera)
{
		Unicode::snprintf(acelerador_unBuffer, ACELERADOR_UN_SIZE, "%d", acelera);
		acelerador_un.invalidate();
		Acelerador_bar.setValue(acelera);
		Acelerador_bar.invalidate();
}
void ModoProvaView::updateFreio(int freio)
{
		Unicode::snprintf(freio_unBuffer, FREIO_UN_SIZE, "%d", freio);
		freio_un.invalidate();
		freio_bar.setValue(freio);
		freio_bar.invalidate();
}
