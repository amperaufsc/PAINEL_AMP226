#ifndef ACELERACAO_SAVIEW_HPP
#define ACELERACAO_SAVIEW_HPP

#include <gui_generated/aceleracao_sa_screen/Aceleracao_SAViewBase.hpp>
#include <gui/aceleracao_sa_screen/Aceleracao_SAPresenter.hpp>

class Aceleracao_SAView : public Aceleracao_SAViewBase
{
public:
    Aceleracao_SAView();
    virtual ~Aceleracao_SAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ACELERACAO_SAVIEW_HPP
