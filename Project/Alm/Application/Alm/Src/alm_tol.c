/**
 * @file    alm_tol.c
 * @brief   This file is used for implementing TOL (Task Of LED, TSK_LED).
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Includes -------------------------------------------------------- */
#include "feature.h"
#include "cmsis_os.h"
#include "queue.h"
#include "alm_api.h"

/* External variables ---------------------------------------------- */
extern osMessageQueueId_t queLedTaskHandle;

/* Private define -------------------------------------------------- */
/* Private typedef ------------------------------------------------- */
/* Private function prototypes ------------------------------------- */
/* Private variables ----------------------------------------------- */
/* Public functions ------------------------------------------------ */
PUBLIC void vidTaskLedInitialize(void) {
}

PUBLIC void vidTaskLedProcess(void) {
  BaseType_t xStatus;
  uint8_t u8Received;

  xStatus = xQueueReceive(queLedTaskHandle, &u8Received, portMAX_DELAY);
  if (xStatus == pdPASS)
  {
    /* TBD */
  }
}

/* Private functions ----------------------------------------------- */
