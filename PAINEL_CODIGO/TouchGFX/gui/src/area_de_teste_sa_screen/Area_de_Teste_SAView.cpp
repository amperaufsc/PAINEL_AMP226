#include <gui/area_de_teste_sa_screen/Area_de_Teste_SAView.hpp>

Area_de_Teste_SAView::Area_de_Teste_SAView()
{

}

void Area_de_Teste_SAView::setupScreen()
{
    Area_de_Teste_SAViewBase::setupScreen();
}

void Area_de_Teste_SAView::tearDownScreen()
{
    Area_de_Teste_SAViewBase::tearDownScreen();
}
void Area_de_Teste_SAView::updateAutonomos(int val) {
    Unicode::snprintf(TESTE_STARTBuffer, TESTE_START_SIZE, "%d", val);
    TESTE_START.invalidate();
}
