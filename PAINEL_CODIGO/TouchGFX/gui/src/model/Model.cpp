#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include <stdbool.h>
#include <stdint.h>
#include "cmsis_os2.h"
#include "can_types.h"

extern "C" {
    #include "main.h" // Para garantir que can_msg_t seja reconhecida
    extern FDCAN_HandleTypeDef hfdcan1;
    extern osMessageQueueId_t QueueButtonHandle;
    extern osMessageQueueId_t Queue_CAN_RXHandle; // Handle da fila do CAN
    extern volatile uint8_t pressedButtonId;
    extern int valorSoc;


    extern osMessageQueueId_t Queue_CAN_RXHandle;
    extern osMessageQueueId_t Queue_CAN_TXHandle;
    extern osMessageQueueId_t QueueButtonHandle;
    extern volatile uint8_t pressedButtonId;
}


Model::Model() : modelListener(0), currentScreen(CAPA)
{

}

extern "C" {
    extern bool estadoBotaoPA8; // 1. Mantenha esta aqui (FORA da classe)
    extern volatile uint8_t pressedButtonId;
}
uint32_t model_recebeu_fila = 0;
uint32_t id_errado_count = 0;
uint32_t ultimo_id_intruso = 0;

void Model::tick()
{
	/* --- LÓGICA EXISTENTE DO BOTÃO VIRTUAL --- */
	    static int debounceCounter = 0;
	    if (debounceCounter > 0) debounceCounter--;

	    if (pressedButtonId != 0 && debounceCounter == 0)
	    {
	        modelListener->hwButtonClicked(pressedButtonId);
	        pressedButtonId = 0;
	        debounceCounter = 15;
	    }
	    else if (pressedButtonId != 0)
	    {
	        pressedButtonId = 0;
	    }

	    /* --- LÓGICA DE RECEPÇÃO CAN --- */
	    can_msg_t msg_recebida;

	    // Verifica se conseguimos tirar algo da fila
	    if (osMessageQueueGet(Queue_CAN_RXHandle, &msg_recebida, NULL, 0) == osOK)
	    {
	        model_recebeu_fila++;

	        uint16_t valor = msg_recebida.data[0];

	        switch (msg_recebida.id)
	        {
	            case 0x341: modelListener->updateRPMValue(valor); break; // Aqui vai mostrar a Screen!
	            case 0x124: modelListener->updateSpeedValue(valor); break;
	            case 0x125: modelListener->updateSOCValue(valor); break;
	            case 0x126: modelListener->updateFreioValue(valor); break;
	            case 0x127: modelListener->updateAceleradorValue(valor); break;
	            case 0x241: modelListener->updateTensaoHVValue(valor); break;
	            case 0x123: modelListener->updateDistanciaValue(valor); break;
	            case 0x130: modelListener->updatePotenciaValue(valor); break;
	            case 0x131: modelListener->updateTempAcumuladorValue(valor); break;
	            case 0x132: modelListener->updateTempMotorValue(valor); break;
	            case 0x133: modelListener->updateTensaoInversorValue(valor); break;
	            case 0x135: modelListener->updateTempInversorValue(valor); break;
	            case 0x136: modelListener->updateTensaoCelulaMinValue(valor); break;
	            case 0x139: modelListener->updateTensaoHVValue(valor); break;
	            default:
	                ultimo_id_intruso = msg_recebida.id;
	                id_errado_count++;
	                break;
	        } // FIM DO SWITCH
	    } // FIM DO IF DA FILA CAN


	}
void Model::reportCurrentScreen(ScreenID screenId)
{
	currentScreen = screenId;

	    can_msg_t msg_tx;
	    msg_tx.id = 0x341;
	  //  msg_tx.dlc = 1;
	    msg_tx.data[0] = (uint8_t)currentScreen;

	    // Coloca na fila de transmissão.
	    // O timeout 0 garante que a UI não trave se a fila estiver cheia.
	    osMessageQueuePut(Queue_CAN_TXHandle, &msg_tx, 0, 0);
}
