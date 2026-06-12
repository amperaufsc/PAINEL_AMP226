#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <stdbool.h>
#include <stdint.h>
#include <cstdint>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }
    	//*funçoes virtuais vazias*//
    	//*vao ser indicadas pelo ponteiro modellistener->*//
    //Falhas
    virtual void RTDbotao(int rtd) {}
    virtual void updateFalhaTMS(int falha) {}
    virtual void updateFalhaECU(int falha) {}
    virtual void updateFalhaINV(int falha) {}

    // Motor, Inversor e acumulador
    virtual void updateRPM(int rpm) {}
    virtual void updateTempMotor(int temp) {}
    virtual void updateTempInversor(int temp) {}
    virtual void updateTempAcc(int temp) {}
    virtual void updateSOC(int soc) {}

    // Corrente e Tensão
    virtual void updateCorrenteHV(float corrente) {}
    virtual void updateCorrenteInv(float corrente) {}
    virtual void updateTensaoHV(float tesao) {}
    virtual void updateTensaoInversor(float tesao) {}
    virtual void updateTensaoCelulaMin(int tesao) {}
    virtual void updateTensaoCelulaMax(int tesao) {}

    //
    virtual void updateAcelerador(int acelera) {}
    virtual void updateFreio(int freio) {}
    virtual void updateVelocidade(int vel) {}
    virtual void updateDistancia(int metros) {}

    //botoes
    virtual void Botao1(int bn1) {}
    virtual void Botao2(int bn2) {}
    virtual void Botao3(int bn3) {}

protected:
    Model* model;
};
#endif // MODELLISTENER_HPP
