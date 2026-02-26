#ifndef INSPECAO_SAVIEW_HPP
#define INSPECAO_SAVIEW_HPP

#include <gui_generated/inspecao_sa_screen/Inspecao_SAViewBase.hpp>
#include <gui/inspecao_sa_screen/Inspecao_SAPresenter.hpp>

class Inspecao_SAView : public Inspecao_SAViewBase
{
public:
    Inspecao_SAView();
    virtual ~Inspecao_SAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSPECAO_SAVIEW_HPP
