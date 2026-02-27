#ifndef AREA_DE_TESTE_SAVIEW_HPP
#define AREA_DE_TESTE_SAVIEW_HPP

#include <gui_generated/area_de_teste_sa_screen/Area_de_Teste_SAViewBase.hpp>
#include <gui/area_de_teste_sa_screen/Area_de_Teste_SAPresenter.hpp>

class Area_de_Teste_SAView : public Area_de_Teste_SAViewBase
{
public:
    Area_de_Teste_SAView();
    virtual ~Area_de_Teste_SAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // AREA_DE_TESTE_SAVIEW_HPP
