#include <gui/aceleracao_sa_screen/Aceleracao_SAView.hpp>

Aceleracao_SAView::Aceleracao_SAView()
{

}

void Aceleracao_SAView::setupScreen()
{
    Aceleracao_SAViewBase::setupScreen();
}

void Aceleracao_SAView::tearDownScreen()
{
    Aceleracao_SAViewBase::tearDownScreen();
}

void Aceleracao_SAView::ativacaobotao(int gostate)
{
    if (gostate == 1)
    {
        aceleracao_gostate.setVisible(true);
    }
    else
    {
    	aceleracao_gostate.setVisible(false);
    }
    aceleracao_gostate.invalidate();
}
