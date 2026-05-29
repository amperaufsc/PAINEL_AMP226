//AQUI É GALO
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include <stdbool.h>
#include <stdint.h>
#include "cmsis_os2.h"
#include "can_types.h"
#include <cstring>

extern "C" {
    #include "main.h" // Para garantir que can_msg_t seja reconhecida
    extern FDCAN_HandleTypeDef hfdcan1;
    extern osMessageQueueId_t QueueButtonHandle;
    extern osMessageQueueId_t Queue_CAN_RXHandle; // Handle da fila do CAN
    extern volatile uint8_t pressedButtonId;
    extern int valorSoc;
    extern volatile uint8_t ID_DA_PAGINA;
    extern volatile uint8_t START_AUTONOMOS;



    extern osMessageQueueId_t Queue_CAN_RXHandle
	;
    extern osMessageQueueId_t QueueButtonHandle;
    extern volatile uint8_t pressedButtonId;
    extern float tensaoHV_float;
    extern float tensaoInversor_float;
}


Model::Model() : modelListener(0), currentScreen(CAPA) , estadoPB11(false)
		modelListener(0)
{

}
bool Model::isTelaPermitidaParaPB11(ScreenID id)
{
    // Retorna true apenas se for uma das telas que você listou
    return (id == AREA_TESTE || id == AUTOCROSS || id == ACELERACAO ||
            id == SKIDPED || id == TRACKDRIVE || id == EBS || id == INSPECAO);
}

extern "C" {
    extern bool estadoBotaoPA8; // 1. Mantenha esta aqui (FORA da classe)
    extern volatile uint8_t pressedButtonId;
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
//	/* CALCULANDO A DISTANCIA */ Isso se tornará inutil se Sistemas autonomos mandar tanto a distancia quanto a velocidade pra mim
//	uint32_t now = osKernelGetTickCount();
//
//	    if (this->ultimoTick != 0)
//	    {
//	        uint32_t elapsed_ms = now - this->ultimoTick;
//
//	        // Se você fixou 100.0f e não funciona, o erro está aqui ou no Listener
//	        if (this->velocidadeatual > 0.1f) {
//	            float tempo_s = (float)elapsed_ms / 1000.0f;
//	            this->distancia_total += (this->velocidadeatual / 3.6f) * tempo_s;
//	        }
//
//	        if (modelListener != 0) {
//	            // Teste: force um valor fixo aqui para ver se a tela atualiza
//	            // modelListener->updateDistanciaValue(99.9f);
//	            modelListener->updateDistanciaValue((float)(this->distancia_total / 1000.0f));
//	        }
//	    }
//	    this->ultimoTick = now;
	/* --- LÓGICA EXISTENTE DO BOTÃO VIRTUAL --- */
	    static int debounceCounter = 0;
	    if (debounceCounter > 0) debounceCounter--;

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
        while (osMessageQueueGet(Queue_CAN_RXHandle, &msg_recebida, NULL, 0) == osOK)
        {
            model_recebeu_fila++; // Se este número subir, o Model está lendo a fila!

            switch (msg_recebida.id)
            {
            case 0x120: { // falhas validado
            				uint8_t falha_INVERTER = msg_recebida.data[0];
            				uint8_t readtodrive = msg_recebida.data[3];
            			    uint8_t falha_TMS = msg_recebida.data[4];
                            uint16_t falha_ECU = ((uint16_t)msg_recebida.data[1] << 8) | msg_recebida.data[2];
                            if (readtodrive == 3) {  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
                            } else { HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);}

							modelListener->RTDativo(readtodrive);
                            modelListener->updateFalhaTMSValue(falha_TMS);
                            modelListener->updateFalhaECUValue(falha_ECU);
                            modelListener->updateFalhaINVValue(falha_INVERTER);

                            break;
                         }
            case 0x121: {	//funciona mensagens 1 byte
            				uint8_t tensCelMin = msg_recebida.data[0];
            				uint8_t soc = msg_recebida.data[3];
            				uint8_t acelerador = msg_recebida.data[4];
                            uint8_t freio = msg_recebida.data[5];
                            uint8_t TempAcumulador = msg_recebida.data[7];

                            modelListener->updateTensaoCelulaMinValue(tensCelMin);
                            modelListener->updateSOCValue(soc);
                            modelListener->updateFreioValue(freio);
                            modelListener->updateAceleradorValue(acelerador);
                            modelListener->updateTempAcumuladorValue(TempAcumulador);
                            break;
                        }
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


            case 0x220: { //validado
                            float correnteHV_float = 0.0f; //acumulador

                            memcpy(&correnteHV_float, &msg_recebida.data[4], sizeof(float));

                            modelListener->updateCorrenteAcumuladorValue((float)correnteHV_float);
                            break;
                        }

            case 0x420: {	//funciona mensagens 2bytes
                            uint16_t rpm = ((uint16_t)msg_recebida.data[0] << 8) | msg_recebida.data[1];
                            uint16_t TempMotor = ((uint16_t)msg_recebida.data[2] << 8) | msg_recebida.data[3];
                            uint16_t TempInversor = ((uint16_t)msg_recebida.data[6] << 8) | msg_recebida.data[7];

                            modelListener->updateRPMValue(rpm);
                            modelListener->updateTempMotorValue(TempMotor);
                            modelListener->updateTempInversorValue(TempInversor);
                            break;
                        }

            case 0x421: {	// funciona
                            tensaoInversor_float = 0.0f; //trifasico
                            tensaoHV_float = 0.0f; //acumulador

                            memcpy(&tensaoInversor_float, &msg_recebida.data[0], sizeof(float));
                            memcpy(&tensaoHV_float, &msg_recebida.data[4], sizeof(float));

                            modelListener->updateTensaoHVValue((float)tensaoHV_float);
                            modelListener->updateTensaoInversorValue((float)tensaoInversor_float);
                            break;
                        }


//                case 0x000: { //velocidade e distancia SA vai mandar pra mim olhar com o carlos ou pedro quando ficar pronto

//                    float RodaDianteiraEsq = 0.0f;
//                    float RodaDianteiraDir = 0.0f;

//					  memcpy(&RodaDianteiraEsq, &msg_recebida.data[4], sizeof(float));
//            		  memcpy(&RodaDianteiraDir, &msg_recebida.data[0], sizeof(float));


//            			// calculo velocidade media
//					  float VelMediaDianteira = (RodaDianteiraEsq + RodaDianteiraDir)/2;


//                    modelListener->updateSpeedValue((float)VelMediaDianteira);
//                    modelListener->updateDistanciaValue(valor);
//                    break;

//								}




	}
void Model::reportCurrentScreen(ScreenID screenId)
{
	if (estadoPB11 == true)
	    {
	        estadoPB11 = false;

	        can_msg_t msg_reset;
	        msg_reset.id = 0x541; // IMPORTANTE: Escolha o ID CAN para essa mensagem! Usei 0x441 como exemplo.
	        msg_reset.data[0] = 0;

	        // Envia para o FreeRTOS
	        osMessageQueuePut(Queue_CAN_TXHandle, &msg_reset, 0, 0);
	    }

	currentScreen = screenId;

	    can_msg_t msg_tx;
	    msg_tx.id = 0x341;
	  //  msg_tx.dlc = 1;
	    msg_tx.data[0] = (uint8_t)currentScreen;

	    // Coloca na fila de transmissão.
	    // O timeout 0 garante que a UI não trave se a fila estiver cheia.
	    osMessageQueuePut(Queue_CAN_TXHandle, &msg_tx, 0, 0);
}
