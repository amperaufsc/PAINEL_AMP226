#ifndef MODOPROVAPRESENTER_HPP
#define MODOPROVAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

// AQUI É O ÚNICO LUGAR ONDE A DECLARAÇÃO VAZIA É PERMITIDA
class ModoProvaView;

class ModoProvaPresenter : public Presenter, public ModelListener
{
public:
    ModoProvaPresenter(ModoProvaView& v);

    virtual void activate();
    virtual void deactivate();
    virtual ~ModoProvaPresenter() {};

    virtual void updateRPMValue(int val);
    virtual void updateSpeedValue(int val);
    virtual void updateSOCValue(int val);
    virtual void updateFreioValue(int val);
    virtual void updateAceleradorValue(int val);
    virtual void hwButtonClicked(uint8_t buttonId);
    virtual void updateTensaoHVValue(int val);
    virtual void updateDistanciaValue(int val);
    virtual void updatePotenciaValue(int val);
    virtual void updateTempAcumuladorValue(int val);

private:
    ModoProvaPresenter();
    ModoProvaView& view; // O compilador sabe que a view existe graças à linha 11
};

#endif
