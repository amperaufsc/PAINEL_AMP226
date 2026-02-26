#ifndef EBS_TESTE_SAVIEW_HPP
#define EBS_TESTE_SAVIEW_HPP

#include <gui_generated/ebs_teste_sa_screen/EBS_Teste_SAViewBase.hpp>
#include <gui/ebs_teste_sa_screen/EBS_Teste_SAPresenter.hpp>

class EBS_Teste_SAView : public EBS_Teste_SAViewBase
{
public:
    EBS_Teste_SAView();
    virtual ~EBS_Teste_SAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // EBS_TESTE_SAVIEW_HPP
