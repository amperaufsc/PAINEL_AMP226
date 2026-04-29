/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
#include "cmsis_os2.h" // Para as funções de Queue do RTOS
#include "can_types.h"
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
extern FDCAN_HandleTypeDef hfdcan1;
volatile uint8_t flagEnviarCAN = 0;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
volatile uint32_t can_envios_count = 0;
volatile uint32_t can_recepcoes_count = 0;
volatile uint32_t ultimo_id_recebido = 0;
volatile uint32_t erro_fila_count = 0;
volatile uint8_t debug = 0;
volatile uint32_t debug_id_isr = 0;
volatile uint8_t estadoBotaoAtual = 0;
volatile uint8_t ultimoEstadoEnviado = 2;
volatile uint8_t ID_DA_PAGINA = 0;
volatile uint8_t START_AUTONOMOS = 0;
int valorSoc = 0;
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for GUI_Task */
osThreadId_t GUI_TaskHandle;
const osThreadAttr_t GUI_Task_attributes = {
  .name = "GUI_Task",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 8192 * 4
};
/* Definitions for Task_CAN */
osThreadId_t Task_CANHandle;
const osThreadAttr_t Task_CAN_attributes = {
  .name = "Task_CAN",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 1024 * 4
};
/* Definitions for READYTODRIVE */
osThreadId_t READYTODRIVEHandle;
const osThreadAttr_t READYTODRIVE_attributes = {
  .name = "READYTODRIVE",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};
/* Definitions for QueueButton */
osMessageQueueId_t QueueButtonHandle;
const osMessageQueueAttr_t QueueButton_attributes = {
  .name = "QueueButton"
};
/* Definitions for Queue_CAN_RX */
osMessageQueueId_t Queue_CAN_RXHandle;
const osMessageQueueAttr_t Queue_CAN_RX_attributes = {
  .name = "Queue_CAN_RX"
};
/* Definitions for FilaReady */
osMessageQueueId_t FilaReadyHandle;
const osMessageQueueAttr_t FilaReady_attributes = {
  .name = "FilaReady"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
extern portBASE_TYPE IdleTaskHook(void* p);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
extern void TouchGFX_Task(void *argument);
void StartTaskCAN(void *argument);
void ReadyToDrive(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationIdleHook(void);

/* USER CODE BEGIN 2 */
void vApplicationIdleHook( void )
{
   /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
   task. It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()). If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
  
   vTaskSetApplicationTaskTag(NULL, IdleTaskHook);
}
/* USER CODE END 2 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */
  /* creation of QueueButton */
  QueueButtonHandle = osMessageQueueNew (16, sizeof(uint32_t), &QueueButton_attributes);
  /* creation of Queue_CAN_RX */
  Queue_CAN_RXHandle = osMessageQueueNew (16, sizeof(can_msg_t), &Queue_CAN_RX_attributes);
  /* creation of FilaReady */
  FilaReadyHandle = osMessageQueueNew (16, sizeof(uint16_t), &FilaReady_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of GUI_Task */
  GUI_TaskHandle = osThreadNew(TouchGFX_Task, NULL, &GUI_Task_attributes);

  /* creation of Task_CAN */
  Task_CANHandle = osThreadNew(StartTaskCAN, NULL, &Task_CAN_attributes);

  /* creation of READYTODRIVE */
  READYTODRIVEHandle = osThreadNew(ReadyToDrive, NULL, &READYTODRIVE_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}
/* USER CODE BEGIN Header_StartDefaultTask */
/**
* @brief Function implementing the defaultTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN defaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END defaultTask */
}

/* USER CODE BEGIN Header_StartTaskCAN */
/**
* @brief Function implementing the Task_CAN thread.
* @param argument: Not used
* @retval None
*/

/* USER CODE END Header_StartTaskCAN */
void StartTaskCAN(void *argument)
{
  /* USER CODE BEGIN Task_CAN */
	FDCAN_TxHeaderTypeDef TxHeader;

	uint8_t TxData[8];

	//uint32_t valorRPM = 0;

	//uint32_t valorVelocidade = 0;



	// Configurações base do Header

	memset(&TxHeader, 0, sizeof(TxHeader));

	TxHeader.IdType = FDCAN_STANDARD_ID;

	TxHeader.TxFrameType = FDCAN_DATA_FRAME;

	TxHeader.DataLength = FDCAN_DLC_BYTES_8;

	TxHeader.FDFormat = FDCAN_CLASSIC_CAN;




	/* Infinite loop */
	for(;;)

	{

	//  MODO DE PROVA

	TxHeader.Identifier = 0x341;
	TxData[0] = ID_DA_PAGINA;
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

	osDelay(211); //pra debug depois tem que mudar pra 200


	//  SISTEMAS AUTONOMOS
	TxHeader.Identifier = 0x541;
	TxData[0] = START_AUTONOMOS;
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

	osDelay(181); //pra debug depois tem que mudar pra 200




	// READY TO DRIVE
	uint32_t state = !(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8));
	TxHeader.Identifier = 0x241;
	TxData[0] = (uint8_t)state;
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

	osDelay(199);  //pra debug depois tem que mudar pra 200



	// TESTE ANTIGO RPM (ID 0x123 ) ---

	//valorRPM++;

	//if(valorRPM > 8) valorRPM = 0;



	//TxHeader.Identifier = 0x123;

	//TxData[0] = (uint8_t)valorRPM;

	//HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);



	//osDelay(250); // Pequeno intervalo entre mensagens


	 // testes
	// ACELERADOR  ---
    static uint8_t acelerador = 0;
	acelerador += 2;
	if(acelerador > 100) acelerador = 0;
	TxHeader.Identifier = 0x121;
	memset(TxData, 0, 8);
	TxData[4] = acelerador;
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

	//FREIO  ---
	static uint8_t freio = 0;
	freio += 2;
	if(freio > 100) freio = 0;
	TxHeader.Identifier = 0x121;
	memset(TxData, 0, 8);
	TxData[5] = freio;
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

//	//TEMPERATURA ACUMULADOR  ---
//	static uint8_t tempacumulador = 0;
//	tempacumulador += 1;
//	if(tempacumulador > 70) tempacumulador = 0;
//	TxHeader.Identifier = 0x121;
//	memset(TxData, 0, 8);
//	TxData[7] = tempacumulador;
//	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

	// RPM  ---
	static uint16_t rpm = 0;
	rpm += 123;
	if(rpm > 9000) rpm = 0;
	TxHeader.Identifier = 0x420;
	TxData[0] = (uint8_t)(rpm >> 8);
	TxData[1] = (uint8_t)rpm;
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

	//TEMPERATURA MOTOR ---
	static uint16_t tempmotor = 0;
	tempmotor += 29;
	if(tempmotor > 1000) tempmotor = 0;
	TxHeader.Identifier = 0x420;
	TxData[2] = (uint8_t)(tempmotor >> 8);
	TxData[3] = (uint8_t)tempmotor;
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

	//TEMPERATURA INVERSOR  ---
	static uint16_t tempinversor = 0;
	tempinversor += 37;
	if(tempinversor > 900) tempinversor = 0;
	TxHeader.Identifier = 0x420;
	TxData[6] = (uint8_t)(tempinversor >> 8);
	TxData[7] = (uint8_t)tempinversor;
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

	//TENSAO INVERSOR  ---
	static float tensaoInversor = 0.0f;
	tensaoInversor += 50.5f;
	if(tensaoInversor > 700.0f) tensaoInversor = 0.0f;
	TxHeader.Identifier = 0x421;
	memset(TxData, 0, 8); // Zera o pacote para limpar lixo de memória
	memcpy(&TxData[0], &tensaoInversor, sizeof(float));
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

	//TENSAO ACUMULADOR(HV)  ---
	static float acumuladorhv = 0.0f;
	acumuladorhv += 5.5f;
	if(acumuladorhv > 700.0f) acumuladorhv = 0.0f;
	TxHeader.Identifier = 0x421;
	memset(TxData, 0, 8); // Zera o pacote para limpar lixo de memória
	memcpy(&TxData[4], &acumuladorhv, sizeof(float));
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

	//FALHA ECU  ---
	static uint16_t ecu = 0;
	ecu += 10;
	if(ecu > 260) ecu = 0;
	TxHeader.Identifier = 0x120;
	TxData[1] = (uint8_t)(ecu >> 8);
	TxData[2] = (uint8_t)ecu;
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

	 // FALHA TMS  ---
    static uint8_t tms = 0;
    tms += 2;
	if(tms > 16) tms = 0;
	TxHeader.Identifier = 0x120;
	TxData[4] = tms;
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

	 // FALHA INVERSOR  ---
    static uint8_t INV = 0;
    INV += 2;
	if(INV > 16) INV = 0;
	TxHeader.Identifier = 0x120;
	TxData[0] = INV;
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);




	osDelay(100);






	// --- ENVIO 3: SOC (ID 0x125 ) ---
//
//	valorSoc += 1;
//
//	if(valorSoc > 100) valorSoc = 0;
//
//
//
//	TxHeader.Identifier = 0x125;
//
//	TxData[0] = (uint8_t)valorSoc;
//
//	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);



	//osDelay(250);

	}
  /* USER CODE END Task_CAN */
}

/* USER CODE BEGIN Header_ReadyToDrive */
/**
* @brief Function implementing the READYTODRIVE thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_ReadyToDrive */
void ReadyToDrive(void *argument)
{
  /* USER CODE BEGIN READYTODRIVE */
  /* Infinite loop */
  for(;;)
  {
	//uint32_t state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);
	//osMessageQueuePut(QueueButtonHandle, &state, 0, 0);
    osDelay(1);
  }
  /* USER CODE END READYTODRIVE */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
  if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != 0)
  {
    FDCAN_RxHeaderTypeDef RxHeader;
    can_msg_t msg_recebida;

    // 1. Limpa as estruturas para garantir que não estamos lendo lixo de memória
      memset(&RxHeader, 0, sizeof(RxHeader));
      memset(&msg_recebida, 0, sizeof(msg_recebida));
//
//    // 2. Tenta ler o hardware e captura o status
      HAL_StatusTypeDef status = HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, msg_recebida.data);
//
//    // 3. Só prossegue se a leitura foi 100% bem-sucedida
    if (status == HAL_OK)
    {
//        can_recepcoes_count++;
        msg_recebida.id = RxHeader.Identifier;
        debug_id_isr = msg_recebida.id;

        // Agora sim, garantimos que o ID é real
        if (osMessageQueuePut(Queue_CAN_RXHandle, &msg_recebida, 0, 0) != osOK)
        {
            erro_fila_count++;
        }
    }

    else
    {
        // Debug: Se cair aqui, a função HAL falhou
    	debug++;
        // Isso explica por que o ID era um contador:
        // o código ignorava que a leitura falhou e lia memória vazia.
    }
  }
}
/* USER CODE END Application */

