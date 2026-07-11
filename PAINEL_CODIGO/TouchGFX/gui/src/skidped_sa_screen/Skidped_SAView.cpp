#include <gui/skidped_sa_screen/Skidped_SAView.hpp>

Skidped_SAView::Skidped_SAView()
{

}

void Skidped_SAView::setupScreen()
{
    Skidped_SAViewBase::setupScreen();
}

void Skidped_SAView::tearDownScreen()
{
    Skidped_SAViewBase::tearDownScreen();
}

void Skidped_SAView::ativacaobotao(int gostate)
{
    if (gostate == 1)
    {
        skidpad_gostate.setVisible(true);
    }
    else
    {
    	skidpad_gostate.setVisible(false);
    }
    skidpad_gostate.invalidate();
}
