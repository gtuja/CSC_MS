/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "alm_api.h"
#include "feature_periodic.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

PRIVATE U32 gu32SysTickCounter; /**< The base counter for frequency division for each periodic service. */

/** gstrXlmTransitionTbl is a private const table holding periodic service information. */
PRIVATE const tstrPeriodicService gstrPeriodicServiceTable[PRD_SRV_MAX] = {
  { PRD_SRV_HIGH, vidIsbInitialize,  vidIsbService  },
  { PRD_SRV_HIGH, vidIslInitialize,  vidIslService  },
};

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for TSK_LED */
osThreadId_t TSK_LEDHandle;
const osThreadAttr_t TSK_LED_attributes = {
  .name = "TSK_LED",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 256 * 4
};
/* Definitions for TSK_BTN */
osThreadId_t TSK_BTNHandle;
const osThreadAttr_t TSK_BTN_attributes = {
  .name = "TSK_BTN",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 256 * 4
};
/* Definitions for TSK_SWD */
osThreadId_t TSK_SWDHandle;
const osThreadAttr_t TSK_SWD_attributes = {
  .name = "TSK_SWD",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 256 * 4
};
/* Definitions for queLedTask */
osMessageQueueId_t queLedTaskHandle;
const osMessageQueueAttr_t queLedTask_attributes = {
  .name = "queLedTask"
};
/* Definitions for queBtnTask */
osMessageQueueId_t queBtnTaskHandle;
const osMessageQueueAttr_t queBtnTask_attributes = {
  .name = "queBtnTask"
};
/* Definitions for queSwdTask */
osMessageQueueId_t queSwdTaskHandle;
const osMessageQueueAttr_t queSwdTask_attributes = {
  .name = "queSwdTask"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void vidTaskLed(void *argument);
void vidTaskButton(void *argument);
void vidTaskSwd(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

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

  /* Create the queue(s) */
  /* creation of queLedTask */
  queLedTaskHandle = osMessageQueueNew (20, sizeof(uint8_t), &queLedTask_attributes);

  /* creation of queBtnTask */
  queBtnTaskHandle = osMessageQueueNew (20, sizeof(uint8_t), &queBtnTask_attributes);

  /* creation of queSwdTask */
  queSwdTaskHandle = osMessageQueueNew (20, sizeof(uint8_t), &queSwdTask_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of TSK_LED */
  TSK_LEDHandle = osThreadNew(vidTaskLed, NULL, &TSK_LED_attributes);

  /* creation of TSK_BTN */
  TSK_BTNHandle = osThreadNew(vidTaskButton, NULL, &TSK_BTN_attributes);

  /* creation of TSK_SWD */
  TSK_SWDHandle = osThreadNew(vidTaskSwd, NULL, &TSK_SWD_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_vidTaskLed */
/**
* @brief Function implementing the TSK_LED thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_vidTaskLed */
void vidTaskLed(void *argument)
{
  /* USER CODE BEGIN vidTaskLed */
  /* Infinite loop */
  for(;;)
  {
    vidTaskLedProcess();
  }
  /* USER CODE END vidTaskLed */
}

/* USER CODE BEGIN Header_vidTaskButton */
/**
* @brief Function implementing the TSK_BTN thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_vidTaskButton */
void vidTaskButton(void *argument)
{
  /* USER CODE BEGIN vidTaskButton */
  /* Infinite loop */
  for(;;)
  {
    vidTaskBtnProcess();
  }
  /* USER CODE END vidTaskButton */
}

/* USER CODE BEGIN Header_vidTaskSwd */
/**
* @brief Function implementing the TSK_SWD thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_vidTaskSwd */
void vidTaskSwd(void *argument)
{
  /* USER CODE BEGIN vidTaskSwd */
  /* Infinite loop */
  for(;;)
  {
    vidTaskSwdProcess();
  }
  /* USER CODE END vidTaskSwd */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/**
 * @brief   Public function that initialize periodic services.
 * @param   void
 * @sa      gstrPeriodicServiceTable
 * @return  void
 */
PUBLIC void vidPeriodicServiceInitialize(void) {
  uint16_t i;
  const tstrPeriodicService* pService;

  gu32SysTickCounter = 0;
  pService = &(gstrPeriodicServiceTable[0]);
  for (i=0; i<(uint16_t)PRD_SRV_MAX; i++) {
    if (pService->pfInitialize != NULL) {
      pService->pfInitialize(NULL);
    }
    pService++;
  }
}

/**
 * @brief   Public function that process periodic services every SysTick(1ms).
 * @param   void
 * @sa      gstrPeriodicServiceTable
 * @return  void
 */
void vApplicationTickHook(void) {
  uint16_t i;
  const tstrPeriodicService* pService;

  gu32SysTickCounter++;
  pService = &(gstrPeriodicServiceTable[0]);
  for (i=0; i<(uint16_t)PRD_SRV_MAX; i++) {
    if ((gu32SysTickCounter % pService->u16Period) == 0) {
      if (pService->pfService != NULL) {
        pService->pfService(NULL);
      }
    }
    pService++;
  }
}


/* USER CODE END Application */

