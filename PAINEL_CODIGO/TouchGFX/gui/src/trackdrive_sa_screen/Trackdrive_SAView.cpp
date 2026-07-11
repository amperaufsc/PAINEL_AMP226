#include <gui/trackdrive_sa_screen/Trackdrive_SAView.hpp>

Trackdrive_SAView::Trackdrive_SAView()
{

}

void Trackdrive_SAView::setupScreen()
{
    Trackdrive_SAViewBase::setupScreen();
}

void Trackdrive_SAView::tearDownScreen()
{
    Trackdrive_SAViewBase::tearDownScreen();
}

void Trackdrive_SAView::ativacaobotao(int gostate)
{
    if (gostate == 1)
    {
        trackdrive_gostate.setVisible(true);
    }
    else
    {
    	trackdrive_gostate.setVisible(false);
    }
    trackdrive_gostate.invalidate();
}
