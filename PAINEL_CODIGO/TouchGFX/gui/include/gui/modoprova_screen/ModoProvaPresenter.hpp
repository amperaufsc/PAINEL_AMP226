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
    virtual void hwButtonClicked(uint8_t buttonId);

private:
    ModoProvaPresenter();
    ModoProvaView& view; // O compilador sabe que a view existe graças à linha 11
};

#endif
