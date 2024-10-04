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

PRIVATE U32 gu32SysTickCounter;

PRIVATE const tstrPeriodicService gstrPeriodicServiceTable[PRD_SRV_MAX] = {
  { PRD_SRV_HIGH, vidIsbInitialize,  vidIsbService  },
  { PRD_SRV_HIGH, vidIslInitialize,  vidIslService  },
};

/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
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

