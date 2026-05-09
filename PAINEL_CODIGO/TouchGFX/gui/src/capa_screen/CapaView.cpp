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

}

void CapaView::animacaologo()
{
    tickCounter++;
    if (tickCounter >= 120)
    {
        tickCounter = 0;
        logobranca.setVisible(!logobranca.isVisible());
        logobranca.invalidate();
    }
}
