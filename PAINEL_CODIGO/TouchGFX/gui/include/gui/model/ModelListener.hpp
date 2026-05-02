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
    virtual void updateSpeedValue(float val) {}
    virtual void updateFreioValue(int val) {}
    virtual void updateAceleradorValue(int val) {}
    virtual void updateDistanciaValue(int val) { }
    virtual void updateAutonomos(int val) { }
    // Sensores e Medidas
    virtual void updateTempMotorValue(int val) {}
    virtual void updateTensaoInversorValue(float val) {}
    virtual void updateTempInversorValue(int val) {}
    virtual void updateTensaoCelulaMinValue(int val) {}

    virtual void updateTempAcumuladorValue(int val) {}
    virtual void updateTensaoHVValue(float val) {}
    virtual void updateCorrenteAcumuladorValue(float val) {}
    virtual void updateRPMValue(int val) {}

    // Falhas
    virtual void updateFalhaTMSValue(int val) {}
    virtual void updateFalhaINVValue(int val) {}
    virtual void updateFalhaECUValue(int val) {}

    //calculos
    //distancia


    void bind(Model* m)
    {
        model = m;
    }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
