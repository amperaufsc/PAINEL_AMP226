//AQUI É GALO
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

void Model::setStartAutonomos(uint8_t valor) {
    START_AUTONOMOS = valor;
}

void Model::tick()
{
	/* CALCULANDO A DISTANCIA */
	uint32_t now = osKernelGetTickCount();

	    if (this->ultimoTick != 0)
	    {
	        uint32_t elapsed_ms = now - this->ultimoTick;

	        // Se você fixou 100.0f e não funciona, o erro está aqui ou no Listener
	        if (this->velocidadeatual > 0.1f) {
	            float tempo_s = (float)elapsed_ms / 1000.0f;
	            this->distancia_total += (this->velocidadeatual / 3.6f) * tempo_s;
	        }

	        if (modelListener != 0) {
	            // Teste: force um valor fixo aqui para ver se a tela atualiza
	            // modelListener->updateDistanciaValue(99.9f);
	            modelListener->updateDistanciaValue((float)(this->distancia_total / 1000.0f));
	        }
	    }
	    this->ultimoTick = now;

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

            // vou fazer de maneira poluida primeiro pq é mais provavel de funcionar, depois
            // de garantir que funciona ajusto pra deixar bonito
            uint16_t rpm = (msg_recebida.data[0] << 8 | msg_recebida.data[1]);
            uint16_t TempMotor = (msg_recebida.data[2] << 8 | msg_recebida.data[3]);
            uint16_t TempInversor = (msg_recebida.data[6] << 8 | msg_recebida.data[7]);
            uint16_t freio = msg_recebida.data[5];
            uint16_t acelerador = msg_recebida.data[4];
            uint16_t TempAcumulador = msg_recebida.data[7];
            uint16_t TensaoHV = memcpy(&AcumCurrent, &RxData[4], sizeof(float));
            uint16_t TensaoInversor = memcpy(&AcumCurrent, &RxData[0], sizeof(float));
            uint16_t valor = msg_recebida.data[0];


            switch (msg_recebida.id)
            {

                case 0x420:
                    modelListener->updateRPMValue(rpm);
                    break;

                case 0x420:
                	modelListener->updateTempMotorValue(TempMotor);
                	break;

                case 0x420:
                    modelListener->updateTempInversorValue(TempInversor);
                    break;

                case 0x000: //colocar velocidade em km/h(olhar com pedro)
                    modelListener->updateSpeedValue(valor);
                    modelListener->updateDistanciaValue(valor);

                    break;
                    //(olhar com matheus)
                case 0x000:
                    modelListener->updateSOCValue(valor);
                    break;

                case 0x000: // ID da Potência
                    modelListener->updatePotenciaValue(valor);
                    break;

                case 0x000:
                	modelListener->updateTensaoCelulaMinValue(valor);
                    break;


                case 0x121: // Supondo o ID do Freio
                    modelListener->updateFreioValue(freio);
                    break;

                case 0x121: // Supondo o ID do Acelerador
                    modelListener->updateAceleradorValue(acelerador);
                    break;

                case 0x121: // ID da Temperatura
                    modelListener->updateTempAcumuladorValue(TempAcumulador);
                    break;

                case 0x421: // ID da Tensão
                    modelListener->updateTensaoHVValue(TensaoHV);
                    break;

                case 0x421: //trifasico
                	modelListener->updateTensaoInversorValue(TensaoInversor);
                	break;

//                case 0x541: // olhar com pedro e ver se é necessario e oq que isso realmente significa

//                	modelListener->updateAutonomos(valor);
//                    break;

                    //esses tres ainda precisa declarar
                    // falhas

//                case 0x120:
//                	modelListener->falha_TMS(valor);
//                    break;
//
//                case 0x120:
//                	modelListener->falha_ECU(valor);
//                    break;
//
//                case 0x120:
//                	modelListener->falha_INVERTER(valor);
//                    break;


                default:
                    // Se cair aqui, o ID que chegou não é o que esperávamos
                	ultimo_id_intruso = msg_recebida.id;
                    id_errado_count++;
                    break;
            }
        }
    }
