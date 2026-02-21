#include <gui/capa_screen/CapaView.hpp>

CapaView::CapaView()
{

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
    // 1. Limpa o buffer e escreve o novo valor formatado como decimal (%d)
    // textAreaCANBuffer é criado automaticamente pelo Designer se você ativou o Wildcard
    //criei este comentario aqui mas depois pode apagar pra testar o can // Unicode::snprintf(textAreaCANBuffer, TEXTAREACAN_SIZE, "%d", value);

    // 2. Avisa o TouchGFX que o texto mudou e precisa ser redesenhado na tela
    //criei este comentario aqui mas depois pode apagar pra testar o can // textAreaCAN.invalidate();
}

void CapaView::modoespera()
{

    piscarimagem++;


    if (piscarimagem % 60 == 0)
    {
        logoazul.setVisible(!logoazul.isVisible());
        logoazul.invalidate();
    }


    if (piscarimagem >= 1200)
    {
        piscarimagem = 0;
    }
}

