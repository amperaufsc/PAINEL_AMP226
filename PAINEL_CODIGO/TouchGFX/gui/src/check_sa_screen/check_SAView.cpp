#include <gui/check_sa_screen/check_SAView.hpp>

check_SAView::check_SAView()
{

}

void check_SAView::setupScreen()
{
    check_SAViewBase::setupScreen();
}

void check_SAView::tearDownScreen()
{
    check_SAViewBase::tearDownScreen();
}

void check_SAView::ativacaobotao(int gostate)
{
    if (gostate == 1)
    {
        check_gostate.setVisible(true);
    }
    else
    {
    	check_gostate.setVisible(false);
    }
    check_gostate.invalidate();
}
