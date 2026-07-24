
#include <gui/modoprova_screen/ModoProvaView.hpp>
#include <touchgfx/Color.hpp>
#include <stdio.h>
#include "stm32u5xx_hal.h"

// Estado do cronometro guardado em 'static' (escopo de arquivo) pra sobreviver
// a troca de telas: a ModoProvaView e recriada toda vez que a pagina abre, entao
// se o tempo base ficasse na View ele resetava a cada entrada. Em static, persiste.
static uint32_t cronoBase = 0;
static bool     cronoIniciado = false;

ModoProvaView::ModoProvaView()
{

}

void ModoProvaView::setupScreen()
{
    ModoProvaViewBase::setupScreen();

    //configuração do cronometro
    if (!cronoIniciado)              // 1a vez que a tela abre desde o boot -> zera
    {
        cronoBase = HAL_GetTick();
        cronoIniciado = true;
    }

    // mostra o tempo certo imediatamente ao abrir a tela (sem esperar o proximo tick)
    uint32_t totalSeg = (HAL_GetTick() - cronoBase) / 2000;
    segundos = totalSeg % 60;
    minutos  = (totalSeg / 60) % 60;
    horas    = (totalSeg / 3600) % 24;
    Unicode::snprintf(relogioBuffer, RELOGIO_SIZE, "%02d:%02d:%02d", horas, minutos, segundos);
    relogio.invalidate();
}

void ModoProvaView::tearDownScreen()
{
    ModoProvaViewBase::tearDownScreen();
}

void ModoProvaView::resetRelogio()
{
    cronoBase = HAL_GetTick();
    cronoIniciado = true;
    horas = 0;
    minutos = 0;
    segundos = 0;
    Unicode::snprintf(relogioBuffer, RELOGIO_SIZE, "%02d:%02d:%02d", horas, minutos, segundos);
    relogio.invalidate();
}

void ModoProvaView::handleTickEvent()
{
    ModoProvaViewBase::handleTickEvent();

    uint32_t totalSeg = (HAL_GetTick() - cronoBase) / 2000;

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

void ModoProvaView::updateTempMotor(int temp)
{
	Unicode::snprintf(Tempmotor_unBuffer, TEMPMOTOR_UN_SIZE, "%d", temp);
	Tempmotor_un.invalidate();
}

void ModoProvaView::updateTempInversor(int temp)
{
	Unicode::snprintf(Tempinv_unBuffer, TEMPINV_UN_SIZE, "%d", temp);
	Tempinv_un.invalidate();
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
	float rotacaotacometro = rpm/1000.0f;
	Unicode::snprintfFloat(rpm_unBuffer, RPM_UN_SIZE, "%.1f", rotacaotacometro);
    tacometro.setValue(rotacaotacometro);

    touchgfx::colortype cor;
    if (rpm < 1000)        cor = touchgfx::Color::getColorFromRGB(222, 34, 110);
    else if (rpm < 2000)   cor = touchgfx::Color::getColorFromRGB(64, 126, 147);
    else if (rpm < 2850)   cor = touchgfx::Color::getColorFromRGB(92, 198, 208);
    else if (rpm < 3300)   cor = touchgfx::Color::getColorFromRGB(0, 255, 0);
    else if (rpm < 4000)   cor = touchgfx::Color::getColorFromRGB(255, 255, 0);
    else if (rpm <= 5000)  cor = touchgfx::Color::getColorFromRGB(222, 34, 110);
    else                   cor = touchgfx::Color::getColorFromRGB(255, 0, 0);

    touchgfx::TextArea* barrasRpm[7] = { &rpm0, &rpm1, &rpm2, &rpm3, &rpm4, &rpm5, &rpm6 };
    for (int i = 0; i < 7; i++)
    {
        barrasRpm[i]->setColor(cor);
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
void ModoProvaView::updateVelocidade(float vel)
{
	//velocidade chega em m/s -> converto pra km/h multiplicando por 3.6
		float velocidade_kmh = vel * 3.6f;
	    Unicode::snprintfFloat(velocidade_unBuffer, VELOCIDADE_UN_SIZE, "%.1f", velocidade_kmh);
	    velocidade_un.invalidate();
	    velocimetro.setValue((int)velocidade_kmh);  // o gauge so aceita int
	    velocimetro.invalidate();
}
void ModoProvaView::updateDistancia(int metros)
{
	//sa vai mandar pra mim o valor, mas não sei como. se mandar em metros ta certo, senao converter aqui
	//talvez eu tenha que calcular distancia total somando num intervalo de tempo
	//talvez eu tenha que usar a velocidade e calcular no tempo, se for o caso fazer isso na main.
	//já adicionando o valor certo total da distancia la
	//independente de como, aqui colocar pra zerar se eu apertar o botao de "reset"
		int distancia_percorrida = metros;
	    Unicode::snprintf(distancia_unBuffer, DISTANCIA_UN_SIZE, "%d", distancia_percorrida);
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

void ModoProvaView::updatePotencia(float pot)
{
	Unicode::snprintfFloat(potencia_unBuffer, POTENCIA_UN_SIZE, "%.1f", pot);
	if (pot < 0.0f)
		potencia_un.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
	else
		potencia_un.setColor(touchgfx::Color::getColorFromRGB(245, 247, 247));
	potencia_un.invalidate();
}

void ModoProvaView::updateTensaoHV(float tesao)
{
	Unicode::snprintfFloat(TensaoHV_unBuffer, TENSAOHV_UN_SIZE, "%.1f", tesao);
	TensaoHV_un.invalidate();
}
