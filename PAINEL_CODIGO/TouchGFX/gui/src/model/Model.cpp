#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include <stdbool.h>
#include <stdint.h>
#include "cmsis_os2.h"
#include "can_types.h"

extern "C" {
    #include "main.h" // Para garantir que can_msg_t seja reconhecida
    extern osMessageQueueId_t QueueButtonHandle;
    extern osMessageQueueId_t Queue_CAN_RXHandle; // Handle da fila do CAN
    extern volatile uint8_t pressedButtonId;
    extern int valorSoc;
    extern volatile uint8_t ID_DA_PAGINA;
    extern volatile uint8_t START_AUTONOMOS;



    extern osMessageQueueId_t Queue_CAN_RXHandle;
    extern osMessageQueueId_t QueueButtonHandle;
    extern volatile uint8_t pressedButtonId;
}


Model::Model() :
		modelListener(0),
		//calculo da distancia
		distancia_total(0.0f),
		velocidadeatual(0.0f),
		ultimoTick(0)

{

}

extern "C" {
    extern volatile uint8_t pressedButtonId; // Variável que vem do main.c
}
uint32_t model_recebeu_fila = 0;
uint32_t id_errado_count = 0;
uint32_t ultimo_id_intruso = 0;

void Model::updateCurrentScreen(uint8_t screenId) {
    ID_DA_PAGINA = screenId;
}

void Model::setStartAutonomos(uint8_t valor) { // Nome deve ser IDÊNTICO ao .hpp
    START_AUTONOMOS = valor;
}

void Model::tick()
{
	/* CALCULANDO A DISTANCIA */

	    uint32_t now = osKernelGetTickCount(); // Pega o tempo atual em ms

	    if (ultimoTick != 0) // filtro pra começar a execução
	    {
	        uint32_t elapsed_ms = now - ultimoTick;


	        // Distância = velocidade * tempo (convertendo ms para segundos)
	        // d = v * (ms / 1000)
	        if (velocidadeatual > 0.1f) { // Filtro de ruído
	        	distancia_total += velocidadeatual * ((float)elapsed_ms / 1000.0f);
	        }

	        // Envia para a UI
	        if (modelListener != 0) {
	            modelListener->updateDistanciaValue((float)(distancia_total / 1000.0f));
	        }
	    }
	    ultimoTick = now;



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

        // 1. Verifica se conseguimos tirar algo da fila
        if (osMessageQueueGet(Queue_CAN_RXHandle, &msg_recebida, NULL, 0) == osOK)
        {
            model_recebeu_fila++; // Se este número subir, o Model está lendo a fila!

            uint16_t valor = msg_recebida.data[0];

            switch (msg_recebida.id)
            {
                case 0x123:
                    modelListener->updateRPMValue(valor);
                    break;

                case 0x124:
                    modelListener->updateSpeedValue(valor);
                    velocidadeatual = (int)valor;
                    break;

                case 0x125:
                    modelListener->updateSOCValue(valor);
                    break;

                case 0x000: // Supondo o ID do Freio
                    modelListener->updateFreioValue(valor);
                    break;

                case 0x741: // Supondo o ID do Acelerador
                    modelListener->updateAceleradorValue(valor);
                    break;

                case 0x128: // ID da Tensão
                    modelListener->updateTensaoHVValue(valor);
                    break;

                case 0x130: // ID da Potência
                    modelListener->updatePotenciaValue(valor);
                    break;

                case 0x131: // ID da Temperatura
                    modelListener->updateTempAcumuladorValue(valor);
                    break;

                case 0x132:
                	modelListener->updateTempMotorValue(valor);
                	break;

                case 0x133:
                	modelListener->updateTensaoInversorValue(valor);
                	break;

                case 0x135:
                	modelListener->updateTempInversorValue(valor);
                	break;

                case 0x136:
                	modelListener->updateTensaoCelulaMinValue(valor);
                    break;

                case 0x139:
                	modelListener->updateTensaoHVValue(valor);
                    break;

                case 0x541:
                	modelListener->updateAutonomos(valor);
                    break;

                default:
                    // Se cair aqui, o ID que chegou não é o que esperávamos
                	ultimo_id_intruso = msg_recebida.id;
                    id_errado_count++;
                    break;
            }
        }
    }
