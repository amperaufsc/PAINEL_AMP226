#ifndef MODOPROVAPRESENTER_HPP
#define MODOPROVAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;


class ModoProvaView;

class ModoProvaPresenter : public Presenter, public ModelListener
{
public:
    ModoProvaPresenter(ModoProvaView& v);

    virtual void activate();
    virtual void deactivate();
    virtual ~ModoProvaPresenter() {};
;
	virtual void updateTempMotor(int temp) override;
	virtual void updateTempAcc(int temp) override;
    virtual void updateAcelerador(int acelera) override;
    virtual void updateFreio(int freio) override;
    virtual void updateVelocidade(float vel) override;
    virtual void updateDistancia(int metros) override;
    virtual void updateRPM(int rpm) override;
    virtual void updateSOC(int soc) override;

	//botoes
	virtual void Botao1(int bn1) override;
	virtual void Botao2(int bn2) override;
	virtual void Botao3(int bn3) override;
private:
    ModoProvaPresenter();
    ModoProvaView& view;
};

#endif
