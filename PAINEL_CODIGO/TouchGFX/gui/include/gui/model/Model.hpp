#ifndef MODEL_HPP
#define MODEL_HPP

#include <cstdint>

class ModelListener;


class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void updateCurrentScreen(uint8_t screenId);
    void setStartAutonomos(uint8_t valor);


protected:
    ModelListener* modelListener;

    int model_recebeu_fila;
        uint32_t ultimo_id_intruso;
        int id_errado_count;

};

#endif // MODEL_HPP
