#ifndef MODEL_HPP
#define MODEL_HPP
#include <cstdint>
#include <stdint.h>

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

    void idpagina(int pag_atual); //funcao pra armazenar o valor da pagina no model
    void startautonomos(int sa); //funcao pra armazenar o valor de sa

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
