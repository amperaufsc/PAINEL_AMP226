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

   // enum ScreenID {
    //        CAPA = 0,
    //        TESTES = 1,
    //        MODOPROVA = 2,          // O terceiro agora é o ID 2
     //       AUTONOMOS = 3,          // pag1_Autonomos
     //       AREA_TESTE = 4,         // Area_de_Teste_SA
     //       AUTOCROSS = 5,          // AutoCross_SA
   //         ACELERACAO = 6,         // Aceleracao_SA
    //        SKIDPED = 7,            // Skidped_SA
    //        TRACKDRIVE = 8,         // Trackdrive_SA
    //        EBS = 9,                // EBS_Teste_SA
   //         MANUAL = 10,            // Dirigir_manual_SA
   //         INSPECAO = 11           // Inspecao_SA
   //     };

    //    void reportCurrentScreen(ScreenID screenId);

protected:
    ModelListener* modelListener;

    float distancia_total; //em METROS assumindo que a velocidade é m/s e é um float alinhar pra ver como vai ser mandado
    float velocidadeatual; //assumindo que a velocidade é m/s
    uint32_t ultimoTick;  // Para calcular o tempo real entre execuções

  //  ScreenID currentScreen;
  //  bool estadoPB11;
 //   bool isTelaPermitidaParaPB11(ScreenID id);
    int model_recebeu_fila;
        uint32_t ultimo_id_intruso;
        int id_errado_count;

};

#endif // MODEL_HPP
