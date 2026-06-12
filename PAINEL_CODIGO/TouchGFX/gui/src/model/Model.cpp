//AQUI É GALO
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdbool.h>
#include <stdint.h>
#include "cmsis_os2.h"
#include "can_types.h"
#include <cstring>
#include "stm32u5xx_hal.h"
#include <string.h>
#include <main.h>

#define CAN_ID_RTD  0x141  // ID do botao RTD
#define CAN_ID_PAG  0x54B  // ID das paginas //0x54B original qualquer outro é teste
#define CAN_ID_SA  0x347  // ID do modo de prova do sistema autonomo

//botao RTD
static uint8_t  btn_contador = 0; //pra evitar de apertar o botao sem querer e ruido
static uint8_t  btn_apertado  = 0;
#define BTN_TICKS  5      // ticks necessarios pra confirmar a leitura do botao

uint8_t CAN_rtd_msg = 1;   // valor enviado enquanto botao rtd pressionado

//botao 1 *^* triangulo
static uint8_t  btn_contador_1 = 0; //pra evitar de apertar o botao sem querer e ruido
static uint8_t  btn_apertado_1  = 0;

//botao 2 *o* bolinha
static uint8_t  btn_contador_2 = 0; //pra evitar de apertar o botao sem querer e ruido
static uint8_t  btn_apertado_2  = 0;

//botao 3 *x* xis
static uint8_t  btn_contador_3 = 0; //pra evitar de apertar o botao sem querer e ruido
static uint8_t  btn_apertado_3  = 0;


typedef struct {
    uint32_t id;
    uint8_t data[8];
} CAN_Message_t;

extern "C" osMessageQueueId_t msg_canHandle;

extern "C" {
	//can
	extern FDCAN_HandleTypeDef hfdcan1;
	extern FDCAN_TxHeaderTypeDef TxHeader;
	extern FDCAN_RxHeaderTypeDef RxHeader;

	//mando
	extern volatile uint8_t pagina_atual;
	extern volatile uint8_t start_autonomo;

	//recebo
    extern uint8_t falha_inversor;
    extern uint8_t readtodrive_led;
    extern uint8_t readtodrive_botao;
    extern uint8_t falha_tms;
    extern uint16_t falha_ecu;
    extern uint8_t tensao_cel_min;
    extern uint8_t tensao_cel_max;
    extern uint8_t soc;
    extern uint8_t acelerador;
    extern uint8_t freio;
    extern uint8_t temperatura_acc;
    extern float correnteHV;
    extern float corrente_inv;
    extern uint16_t rpm;
    extern uint16_t temperatura_motor;
    extern uint16_t temperatura_inv;
    extern float tensao_inv;
    extern float tensaoHV;
}

Model::Model() : modelListener(0)
{

}

void Model::idpagina(uint8_t pag_atual)
{
	pagina_atual = pag_atual;
}
void Model::startautonomos(uint8_t sa)
{
	start_autonomo = sa;
}

void Model::tick()
{
	//configurando frequencia de envio das mensagens
	//enviadas a cada 12 ticks ou 192ms ou 5hz
	static uint8_t frequenciapag = 0;
	static uint8_t frequenciaautonomos = 0;

	frequenciapag++;
	frequenciaautonomos++;
//	frequenciartd++;

	if (frequenciapag >= 14)
	{
		frequenciapag = 0;
		//id pagina
        TxHeader.Identifier = CAN_ID_PAG; //na main.h
        uint8_t dadoPag = pagina_atual;
        HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, &dadoPag);

	}
	if (frequenciaautonomos >= 13)
	{
		frequenciaautonomos = 0;
		//id pagina
        TxHeader.Identifier = CAN_ID_SA; //na main.h
        uint8_t dado_SA = start_autonomo;
        HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, &dado_SA);

	}


	 //*** configuração dos botoes pra serem lidos a cada tick(16ms) ***//
	GPIO_PinState estado = HAL_GPIO_ReadPin(botaortd_GPIO_Port, botaortd_Pin); //le o botao rtd
	GPIO_PinState botao1 = HAL_GPIO_ReadPin(botao1_GPIO_Port, botao1_Pin); //le o botao 1
	GPIO_PinState botao2 = HAL_GPIO_ReadPin(botao2_GPIO_Port, botao2_Pin); //le o botao 2
	GPIO_PinState botao3 = HAL_GPIO_ReadPin(botao3_GPIO_Port, botao3_Pin); //le o botao 3

	//***** READ TO DRIVE START *****//
	if (estado == GPIO_PIN_RESET)           // botão pressionado
	{
		if (btn_contador < BTN_TICKS) // se o botao tiver apertado enquanto o numero de ticks pra ler for menor
			btn_contador++; // entao aumento o valor desta variavel pra evitar toques acidentais

		if (btn_contador >= BTN_TICKS) //se atingiu o numero de ticks certo ele le o botao
			btn_apertado = 1; //aqui muda e confirma que o botao ta apertado

	}
	else                                    // botão solto
	{
		btn_contador  = 0;
		btn_apertado = 0;
	}

	if (btn_apertado == 1)
	{  // envio da mensagem no can
		uint8_t valorRTD = CAN_rtd_msg;
		TxHeader.Identifier = CAN_ID_RTD;
		HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, &valorRTD);
		modelListener->RTDbotao(btn_apertado); //aqui vou mandar o valor do botão ate pq
		//se ele aperta vai mandar um msm mas o um é so pra conferir se apertou


	}
		else {
		btn_apertado = 0;
		modelListener->RTDbotao(btn_apertado);
		}

	//***** READ TO DRIVE END *****//

	//***** BOTAO 1 START *****//
	if (botao1 == GPIO_PIN_RESET)           // botão pressionado
	{
		if (btn_contador_1 < BTN_TICKS) // se o botao tiver apertado enquanto o numero de ticks pra ler for menor
			btn_contador_1++; // entao aumento o valor desta variavel pra evitar toques acidentais

		if (btn_contador_1 >= BTN_TICKS) //se atingiu o numero de ticks certo ele le o botao
			btn_apertado_1 = 1; //aqui muda e confirma que o botao ta apertado

	}
	else                                    // botão solto
	{
		btn_contador_1   = 0;
		btn_apertado_1 = 0;
	}

	if (btn_apertado_1 == 1)
	{
		modelListener->Botao1(btn_apertado_1);

	}
	else { btn_apertado_1 = 0;
	modelListener->Botao1(btn_apertado_1);}
	//***** BOTAO 1 END *****//

	//***** BOTAO 2 START *****//
	    if (botao2 == GPIO_PIN_RESET)
	    {
	        if (btn_contador_2 < BTN_TICKS)
	        	btn_contador_2++;

	        if (btn_contador_2 >= BTN_TICKS)
	        	btn_apertado_2 = 1;
	    }
	    else
	    {
	        btn_contador_2 = 0;
	        btn_apertado_2 = 0;
	    }
	    if (btn_apertado_2 == 1)
	    {
	        modelListener->Botao2(btn_apertado_2);
	    }
	    else { btn_apertado_2 = 0;
	    modelListener->Botao2(btn_apertado_2);}
	    //***** BOTAO 2 END *****//

	    //***** BOTAO 3 START *****//

	    if (botao3 == GPIO_PIN_RESET)
	    {
	        if (btn_contador_3 < BTN_TICKS)
	        	btn_contador_3++;

	        if (btn_contador_3 >= BTN_TICKS)
	        	btn_apertado_3 = 1;

	    }
	    else
	    {
	        btn_contador_3 = 0;
	        btn_apertado_3 = 0;

	    }
	    if (btn_apertado_3 == 1)
	    {
	        modelListener->Botao3(btn_apertado_3);
	    }
	    else { btn_apertado_3 = 0;
	    modelListener-> btn_apertado_3;}

	    //***** BOTAO 3 END *****//

	CAN_Message_t msg_recebida;
		while (osMessageQueueGet(msg_canHandle, &msg_recebida, NULL, 0) == osOK)
		{
			switch (msg_recebida.id)
			{
			case 0x120: { //0x120 //0x141so pra teste
							falha_inversor = msg_recebida.data[0];
							readtodrive_led = msg_recebida.data[3];
							falha_tms = msg_recebida.data[4];
							falha_ecu = ((uint16_t)msg_recebida.data[1] << 8) | msg_recebida.data[2];
							if (readtodrive_led == 1) {  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
							} else { HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);}

							modelListener->updateFalhaTMS(falha_tms);
							modelListener->updateFalhaECU(falha_ecu);
							modelListener->updateFalhaINV(falha_inversor);

							break;
						 }
			case 0x121: {
							tensao_cel_min = msg_recebida.data[0];
							tensao_cel_max = msg_recebida.data[2];
							soc = msg_recebida.data[3];
							acelerador = msg_recebida.data[4];
							freio = msg_recebida.data[5];
							temperatura_acc = msg_recebida.data[7];

							modelListener->updateTensaoCelulaMin(tensao_cel_min);
							modelListener->updateTensaoCelulaMax(tensao_cel_max);
							modelListener->updateSOC(soc);
							modelListener->updateAcelerador(acelerador);
							modelListener->updateFreio(freio);
							modelListener->updateTempAcc(temperatura_acc);
							break;
						}

			case 0x220: {
							correnteHV = 0.0f; //acumulador
							corrente_inv = 0.0f; //inversor

							memcpy(&correnteHV, &msg_recebida.data[4], sizeof(float));
							memcpy(&corrente_inv, &msg_recebida.data[0], sizeof(float));
							modelListener->updateCorrenteHV((float)correnteHV);
							modelListener->updateCorrenteInv((float)corrente_inv);
							break;
						}
			case 0x420: {
							rpm = ((uint16_t)msg_recebida.data[0] << 8) | msg_recebida.data[1];
							temperatura_motor = ((uint16_t)msg_recebida.data[2] << 8) | msg_recebida.data[3];
							temperatura_inv = ((uint16_t)msg_recebida.data[6] << 8) | msg_recebida.data[7];

							modelListener->updateRPM(rpm);
							modelListener->updateTempMotor(temperatura_motor);
							modelListener->updateTempInversor(temperatura_inv);
							break;
						}
			case 0x421: {
							tensao_inv = 0.0f; //trifasico
							tensaoHV = 0.0f; //acumulador

							memcpy(&tensao_inv, &msg_recebida.data[0], sizeof(float));
							memcpy(&tensaoHV, &msg_recebida.data[4], sizeof(float));

							modelListener->updateTensaoHV((float)tensaoHV);
							modelListener->updateTensaoInversor((float)tensao_inv);
							break;
						}
			}
		}
}
