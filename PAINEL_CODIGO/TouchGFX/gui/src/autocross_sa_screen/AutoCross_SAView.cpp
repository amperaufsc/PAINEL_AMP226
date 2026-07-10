#include <gui/autocross_sa_screen/AutoCross_SAView.hpp>
#include <gui/autocross_sa_screen/AutoCross_SAPresenter.hpp>

AutoCross_SAView::AutoCross_SAView()
{

}

void AutoCross_SAView::setupScreen()
{
    AutoCross_SAViewBase::setupScreen();
}

void AutoCross_SAView::tearDownScreen()
{
    AutoCross_SAViewBase::tearDownScreen();
}

void AutoCross_SAView::ativacaobotao(int gostate)
{
    if (gostate == 1)
    {
        autocross_gostate.setVisible(true);
    }
    else
    {
        autocross_gostate.setVisible(false);
    }
    autocross_gostate.invalidate();
}

