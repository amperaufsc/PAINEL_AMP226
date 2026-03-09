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

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
extern portBASE_TYPE IdleTaskHook(void* p);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
extern void TouchGFX_Task(void *argument);
void StartTaskCAN(void *argument);

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

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of GUI_Task */
  GUI_TaskHandle = osThreadNew(TouchGFX_Task, NULL, &GUI_Task_attributes);

  /* creation of Task_CAN */
  Task_CANHandle = osThreadNew(StartTaskCAN, NULL, &Task_CAN_attributes);

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
  FDCAN_TxHeaderTypeDef TxHeader;
  uint8_t TxData[1];
  uint32_t valorRPM = 0;
  uint32_t valorVelocidade = 0;

  // Configurações base do Header
  memset(&TxHeader, 0, sizeof(TxHeader));
  TxHeader.IdType = FDCAN_STANDARD_ID;
  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  TxHeader.DataLength = FDCAN_DLC_BYTES_1;
  TxHeader.FDFormat = FDCAN_CLASSIC_CAN;

  for(;;)
  {
    // RPM (ID 0x123 ) ---
    valorRPM++;
    if(valorRPM > 8) valorRPM = 0;

    TxHeader.Identifier = 0x123;
    TxData[0] = (uint8_t)valorRPM;
    HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

    osDelay(250); // Pequeno intervalo entre mensagens

    // VELOCIDADE (ID 0x124 ) ---
    valorVelocidade += 10;
    if(valorVelocidade > 80) valorVelocidade = 0;

    TxHeader.Identifier = 0x124;
    TxData[0] = (uint8_t)valorVelocidade;
    HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

    osDelay(250);
    // --- ENVIO 3: SOC (ID 0x125 ) ---
    valorSoc += 1;
    if(valorSoc > 100) valorSoc = 0;

    TxHeader.Identifier = 0x125;
    TxData[0] = (uint8_t)valorSoc;
    HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);

    osDelay(250);
  }
}
  /* USER CODE END Task_CAN */

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
    }

    else
    {
        // Debug: Se cair aqui, a função HAL falhou
    	debug++;
        // Isso explica por que o seu ID era um contador:
        // o código ignorava que a leitura falhou e lia memória vazia.
    }
  }
}
/* USER CODE END Application */

