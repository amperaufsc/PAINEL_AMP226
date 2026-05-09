#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <cstdint>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    //botão
    virtual void hwButtonClicked(uint8_t buttonId) {}


    // Sensores e Medidas
    virtual void updateSpeedValue(float vel) {}
    virtual void updateFreioValue(int fre) {}
    virtual void updateAceleradorValue(int acel) {}
    virtual void updateDistanciaValue(int km) { }
    virtual void updateAutonomos(int val) { }
    virtual void updateRPMValue(int rpm) {}

    //temperatura
    virtual void updateTempAcumuladorValue(int tacu) {}
    virtual void updateTempInversorValue(int tinv) {}
    virtual void updateTempMotorValue(int tmot) {}

    //tensao e corrente
    virtual void updateMinCel(int mc) {}
    virtual void updateSOCValue(int soc) {}
    virtual void updateTensaoHVValue(float hv) {}
    virtual void updateTensaoInversorValue(float inv) {}
    virtual void updateCorrenteAcumuladorValue(float acu) {}


    // Falhas
    virtual void updateFalhaTMSValue(int tms) {}
    virtual void updateFalhaINVValue(int finv) {}
    virtual void updateFalhaECUValue(int ecu) {}
    virtual void RTDativo(int rtd) {}


    void bind(Model* m)
    {
        model = m;
    }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
