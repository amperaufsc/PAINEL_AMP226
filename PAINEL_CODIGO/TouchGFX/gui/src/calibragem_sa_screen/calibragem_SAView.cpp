#include <gui/calibragem_sa_screen/calibragem_SAView.hpp>

calibragem_SAView::calibragem_SAView()
{

}

void calibragem_SAView::setupScreen()
{
    calibragem_SAViewBase::setupScreen();
}

void calibragem_SAView::tearDownScreen()
{
    calibragem_SAViewBase::tearDownScreen();
}

void calibragem_SAView::ativacaobotao(int gostate)
{
    if (gostate == 1)
    {
        calibragem_gostate.setVisible(true);
    }
    else
    {
    	calibragem_gostate.setVisible(false);
    }
    calibragem_gostate.invalidate();
}
