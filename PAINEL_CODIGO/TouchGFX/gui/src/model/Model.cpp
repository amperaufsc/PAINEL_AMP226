#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include <stdbool.h>
#include <stdint.h>
#include "cmsis_os2.h"


extern "C" {
    #include "main.h" // Para garantir que can_msg_t seja reconhecida
    extern osMessageQueueId_t QueueButtonHandle;
    extern osMessageQueueId_t Queue_CAN_RXHandle; // Handle da fila do CAN
    extern volatile uint8_t pressedButtonId;
#ifndef CAN_MSG_TYPEDEF
    #define CAN_MSG_TYPEDEF
    typedef struct {
        uint32_t id;
        uint8_t  data[8];
        uint32_t dlc;
    } can_msg_t;
    #endif

    extern osMessageQueueId_t Queue_CAN_RXHandle;
    extern osMessageQueueId_t QueueButtonHandle;
    extern volatile uint8_t pressedButtonId;
}


Model::Model() : modelListener(0)
{

}

extern "C" {
    extern volatile uint8_t pressedButtonId; // Variável que vem do main.c
}

void Model::tick()
{
    /* --- LÓGICA EXISTENTE DOS BOTÕES --- */
    static int debounceCounter = 0;
    if (debounceCounter > 0) debounceCounter--;

    if (pressedButtonId != 0 && debounceCounter == 0)
    {
        // Aqui o TouchGFX ainda reage normalmente ao clique (mudar tela, etc)
        modelListener->hwButtonClicked(pressedButtonId);
        pressedButtonId = 0;
        debounceCounter = 15;
    }
    else if (pressedButtonId != 0)
    {
        pressedButtonId = 0;
    }

    can_msg_t msg_recebida;

        // Tenta ler a fila. Se houver mensagem (osOK), processa.
        // Usamos timeout 0 para não travar a interface gráfica.
        if (osMessageQueueGet(Queue_CAN_RXHandle, &msg_recebida, NULL, 0) == osOK)
        {
            // Pega o valor que veio no dado (index 0)
            uint16_t valorRPM = msg_recebida.data[0];

            // Envia para o Presenter
            modelListener->updateRPMValue(valorRPM);
        }


}
