#ifndef MODEL_HPP
#define MODEL_HPP

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

    enum ScreenID {
            CAPA = 0,
            TESTES = 1,
            MODOPROVA = 2,          // O terceiro agora é o ID 2
            AUTONOMOS = 3,          // pag1_Autonomos
            AREA_TESTE = 4,         // Area_de_Teste_SA
            AUTOCROSS = 5,          // AutoCross_SA
            ACELERACAO = 6,         // Aceleracao_SA
            SKIDPED = 7,            // Skidped_SA
            TRACKDRIVE = 8,         // Trackdrive_SA
            EBS = 9,                // EBS_Teste_SA
            MANUAL = 10,            // Dirigir_manual_SA
            INSPECAO = 11           // Inspecao_SA
        };

        void reportCurrentScreen(ScreenID screenId);

protected:
    ModelListener* modelListener;
    ScreenID currentScreen;
    bool estadoPB11;
    bool isTelaPermitidaParaPB11(ScreenID id);

};

#endif // MODEL_HPP
