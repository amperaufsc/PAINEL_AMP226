#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <cstdint>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}
    virtual void hwButtonClicked(uint8_t buttonId) {}
    virtual void updateSOCValue(int val) {}
    virtual void updateSpeedValue(int val) {}
    virtual void updateFreioValue(int val) {}
    virtual void updateAceleradorValue(int val) {}
    virtual void updateDistanciaValue(int val) { }
    virtual void updateAutonomos(int val) { }
    // Sensores e Medidas
    virtual void updateTempMotorValue(int val) {}
    virtual void updateTensaoInversorValue(int val) {}
    virtual void updateTempInversorValue(int val) {}
    virtual void updateTensaoCelulaMinValue(int val) {}
    virtual void updatePotenciaValue(int val) {}
    virtual void updateTempAcumuladorValue(int val) {}
    virtual void updateTensaoHVValue(int val) {}
    virtual void updateCorrenteAcumuladorValue(int val) {}
    virtual void updateRPMValue(int val) {}

    // Falhas
    virtual void updateFalhaBMSValue(int val) {}
    virtual void updateFalhaINVValue(int val) {}
    virtual void updateFalhaECUValue(int val) {}

    void bind(Model* m)
    {
        model = m;
    }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
