#ifndef TESTE_SAVIEW_HPP
#define TESTE_SAVIEW_HPP

#include <gui_generated/teste_sa_screen/Teste_SAViewBase.hpp>
#include <gui/teste_sa_screen/Teste_SAPresenter.hpp>

class Teste_SAView : public Teste_SAViewBase
{
public:
    Teste_SAView();
    virtual ~Teste_SAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TESTE_SAVIEW_HPP
