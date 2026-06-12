#ifndef TESTESPRESENTER_HPP
#define TESTESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TestesView;

class TestesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TestesPresenter(TestesView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~TestesPresenter() {}

	virtual void updateFalhaTMS(int falha) override;
	virtual void updateFalhaECU(int falha) override;
	virtual void updateFalhaINV(int falha) override;
	virtual void RTDbotao(int rtd) override;
	virtual void updateSOC(int soc) override;
	virtual void updateRPM(int rpm) override;
	virtual void updateTempMotor(int temp) override;
	virtual void updateTempInversor(int temp) override;
	virtual void updateTempAcc(int temp) override;
	virtual void updateCorrenteHV(float corrente) override;
	virtual void updateCorrenteInv(float corrente) override;
	virtual void updateTensaoHV(float tesao) override;
	virtual void updateTensaoInversor(float tesao) override;
	virtual void updateTensaoCelulaMin(int tesao) override;
	virtual void updateTensaoCelulaMax(int tesao) override;

    //botoes
    virtual void Botao1(int bn1);
    virtual void Botao2(int bn2);
    virtual void Botao3(int bn3);


private:
    TestesPresenter();

    TestesView& view;
};

#endif // TESTESPRESENTER_HPP
