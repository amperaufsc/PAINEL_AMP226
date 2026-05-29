#include <gui/capa_screen/CapaView.hpp>

CapaView::CapaView()
{
	tickCounter = 0;
}

void CapaView::setupScreen()
{
    CapaViewBase::setupScreen();
}

void CapaView::tearDownScreen()
{
    CapaViewBase::tearDownScreen();
}

void CapaView::setCANValue(int value)
{

}

void CapaView::modoespera()
{

<<<<<<< HEAD

=======
>>>>>>> dia1603
}

void CapaView::handleTickEvent()
{
    // Sempre chama a função da base primeiro
	CapaViewBase::handleTickEvent();

    tickCounter++; // Conta 1 frame

    // Fase 1: Do tick 0 ao 59 (1 segundo) -> Deixa a imagem INVISÍVEL
    if (tickCounter < 60)
    {
        if (logobranca.isVisible()) {
        	logobranca.setVisible(false);
        	logobranca.invalidate();
        }
    }
    // Fase 2: Do tick 60 ao 179 (2 segundos) -> Deixa a imagem VISÍVEL
    else if (tickCounter < 180)
    {
        if (!logobranca.isVisible()) {
        	logobranca.setVisible(true);
        	logobranca.invalidate();
        }
    }
    // Fase 3: Chegou em 180 (3 segundos totais) -> Zera o ciclo e recomeça
    else
    {
        tickCounter = 0;
    }
}
