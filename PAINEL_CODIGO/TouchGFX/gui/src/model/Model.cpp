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



//botao 1 *^* triangulo
static uint8_t  btn_contador_1 = 0; //pra evitar de apertar o botao sem querer e ruido
static uint8_t  btn_apertado_1  = 0;

//botao 2 *o* bolinha
static uint8_t  btn_contador_2 = 0; //pra evitar de apertar o botao sem querer e ruido
static uint8_t  btn_apertado_2  = 0;

//botao 3 *x* xis
static uint8_t  btn_contador_3 = 0; //pra evitar de apertar o botao sem querer e ruido
static uint8_t  btn_apertado_3  = 0;

//distancia percorrida
//acumula em float pra nao perder as fracoes de metro a cada soma
static float distanciaAcum = 0.0f; //em metros


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
extern volatile uint8_t valorRTD;   // valor enviado enquanto botao rtd pressionado
//recebo
extern uint8_t falha_inversor;
extern uint8_t readtodrive_led;
extern uint8_t readtodrive_botao; //lembrar que por enquanto faz nada
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
extern int16_t rpm_bruto;
extern uint16_t control_word;      //0x120 bytes 7-6 - estados Sevcon
extern uint8_t inverter_status;    //0x120 byte 5
extern uint16_t torque_motor;      //0x420 bytes 5-4 (valor absoluto)
extern uint16_t temperatura_motor;
extern uint16_t temperatura_inv;
extern float tensao_inv;
extern float tensaoHV;
extern float velocidade;
extern int distancia;
}



Model::Model() : modelListener(0)
{

}

void Model::idpagina(int pag_atual)
{
	pagina_atual = pag_atual;
}
void Model::startautonomos(int sa)
{
	start_autonomo = sa;
}
void Model::resetDistancia() //botao1(triangulo) na pagina modo de prova
{
	distanciaAcum = 0.0f;
}

void Model::tick()
{
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
		//		uint8_t valorRTD = CAN_rtd_msg;
		//		TxHeader.Identifier = CAN_ID_RTD;
		//		HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, &valorRTD);
		valorRTD = 1;
		modelListener->RTDbotao(btn_apertado); //aqui vou mandar o valor do botão ate pq
		//se ele aperta vai mandar um msm mas o um é so pra conferir se apertou

	}
	else {
		btn_apertado = 0;
		//		CAN_rtd_msg = 0;
		//		uint8_t valorRTD = CAN_rtd_msg;
		//		TxHeader.Identifier = CAN_ID_RTD;
		//		HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, &valorRTD);
		valorRTD = 0;
		modelListener->RTDbotao(btn_apertado);
	}

	//ligar o led quando o botao rtd tiver apertado
	if (valorRTD == 1) {  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
	} else { HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);}

	//***** READ TO DRIVE END *****//

	//***** BOTAO 1 START *****//
	if (botao1 == GPIO_PIN_RESET)           // botão pressionado
	{
		if (btn_contador_1 < BTN_TICKS) // debounce: conta ticks pra confirmar a leitura
			btn_contador_1++;
	}
	else                                    // botão solto
	{
		btn_contador_1 = 0;
	}

	uint8_t pressed_1 = (btn_contador_1 >= BTN_TICKS) ? 1 : 0;
	if (pressed_1 && !btn_apertado_1)       // SÓ na borda de subida => 1 evento por aperto (obs: a leitura fisica ainda é na borda de descida)
	{
		modelListener->Botao1(1);
	}
	btn_apertado_1 = pressed_1;             // guarda o estado pro proximo tick
	//***** BOTAO 1 END *****//

	//***** BOTAO 2 START *****//
	if (botao2 == GPIO_PIN_RESET)           // botão pressionado
	{
		if (btn_contador_2 < BTN_TICKS) // debounce: conta ticks pra confirmar a leitura
			btn_contador_2++;
	}
	else                                    // botão solto
	{
		btn_contador_2 = 0;
	}

	uint8_t pressed_2 = (btn_contador_2 >= BTN_TICKS) ? 1 : 0;
	if (pressed_2 && !btn_apertado_2)       // SÓ na borda de subida  => 1 evento por aperto(obs: a leitura fisica ainda é na borda de descida)
	{
		modelListener->Botao2(1);
	}
	btn_apertado_2 = pressed_2;             // guarda o estado pro proximo tick
	//***** BOTAO 2 END *****//

	//***** BOTAO 3 START *****//
	if (botao3 == GPIO_PIN_RESET)           // botão pressionado
	{
		if (btn_contador_3 < BTN_TICKS) // debounce: conta ticks pra confirmar a leitura
			btn_contador_3++;
	}
	else                                    // botão solto
	{
		btn_contador_3 = 0;
	}

	uint8_t pressed_3 = (btn_contador_3 >= BTN_TICKS) ? 1 : 0;
	if (pressed_3 && !btn_apertado_3)       // SÓ na borda de subida => 1 evento por aperto(obs: a leitura fisica ainda é na borda de descida)
	{
		modelListener->Botao3(1);
	}
	btn_apertado_3 = pressed_3;             // guarda o estado pro proximo tick
	//***** BOTAO 3 END *****//

	//**mandar pro display as variaveis recebidas do can **//

	modelListener->updateFalhaTMS(falha_tms);
	modelListener->updateFalhaECU(falha_ecu);
	modelListener->updateFalhaINV(falha_inversor);
	modelListener->updateTensaoCelulaMin(tensao_cel_min);
	modelListener->updateTensaoCelulaMax(tensao_cel_max);
	modelListener->updateSOC(soc);
	modelListener->updateAcelerador(acelerador);
	modelListener->updateFreio(freio);
	modelListener->updateTempAcc(temperatura_acc);
	modelListener->updateCorrenteHV((float)correnteHV);
	modelListener->updateCorrenteInv((float)corrente_inv);
	modelListener->updateRPM(rpm);
	modelListener->updateTempMotor(temperatura_motor);
	modelListener->updateTempInversor(temperatura_inv);
	modelListener->updateTensaoHV((float)tensaoHV);
	modelListener->updateTensaoInversor((float)tensao_inv);

	//dados do inversor pra tela de testes
	modelListener->updateControlWord(control_word);
	modelListener->updateStatusInversor(inverter_status);
	modelListener->updateCurrentState(readtodrive_led); //current state (0x120 byte 3)
	modelListener->updateTorque(torque_motor);

	//potencia do motor (eletrica no inversor): tensao_inv * corrente_inv, sem filtro
	//regen -> a potencia fica verde e negativa
	modelListener->updatePotencia((tensao_inv * corrente_inv) / 1000.0f); //kw
	modelListener->updateVelocidade((float)velocidade);

	//**integrando a velocidade pra calcular a distancia percorrida**//

	if (velocidade > 0.0f) //ignora valor negativo
	{
		distanciaAcum += (velocidade * (1.0f / 60.0f));
	}
	modelListener->updateDistancia((int)distanciaAcum);

	//**integrando a velocidade pra calcular a distancia percorrida END**//


	//**mandar pro display as variaveis recebidas do can END**//

	//**ligar led verde quando entrar no modo de read to drive
	if ((readtodrive_led >= 2) or (tensaoHV >= 60)) {
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
	}
}

