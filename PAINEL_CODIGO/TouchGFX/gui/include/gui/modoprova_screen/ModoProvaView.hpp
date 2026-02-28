#ifndef MODOPROVAVIEW_HPP
#define MODOPROVAVIEW_HPP

#include <gui_generated/modoprova_screen/ModoProvaViewBase.hpp>

// AQUI É A DEFINIÇÃO COMPLETA, SEM O "class ModoProvaView;" ANTES
class ModoProvaView : public ModoProvaViewBase
{
public:
    ModoProvaView();
    virtual ~ModoProvaView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void updateRPMValue(int val);
};

#endif
