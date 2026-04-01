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
    virtual void updateSOC(int val);
    virtual void updateRPMValue(int val);
    virtual void updateSpeedValue(int val);
    virtual void updateFreio(int val);
    virtual void updateAcelerador(int val);
    virtual void updateTensaoHV(int val);
    virtual void updateDistancia(float val);
    virtual void updatePotencia(int val);
    virtual void updateTempAcumulador(int val);


};

#endif
