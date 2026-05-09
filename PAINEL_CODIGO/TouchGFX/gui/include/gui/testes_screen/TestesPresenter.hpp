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
    virtual void hwButtonClicked(uint8_t buttonId) override;

    // Sensores e Medidas
    virtual void updateRPMValue(int rpm) override;

    //temperatura
    virtual void updateTempAcumuladorValue(int tacu) override;
    virtual void updateTempInversorValue(int tinv) override;
    virtual void updateTempMotorValue(int tmot) override;

    //tensao e corrente
    virtual void updateMinCel(int mc) override;
    virtual void updateSOCValue(int soc) override;
    virtual void updateTensaoHVValue(float hv) override;
    virtual void updateTensaoInversorValue(float inv) override;
    virtual void updateCorrenteAcumuladorValue(float acu) override;

    // Falhas
    virtual void updateFalhaTMSValue(int tms) override;
    virtual void updateFalhaINVValue(int finv) override;
    virtual void updateFalhaECUValue(int ecu) override;
    virtual void RTDativo(int rtd) override;

    virtual ~TestesPresenter() {}
    void notifyButtonChanged(uint32_t buttonID);


private:
    TestesPresenter();

    TestesView& view;
};

#endif // TESTESPRESENTER_HPP
