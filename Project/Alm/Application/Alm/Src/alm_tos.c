/**
 * @file    alm_tos.c
 * @brief   This file is used for implementing TOS (Task Of SWD, TSK_SWD).
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Includes -------------------------------------------------------- */
#include "feature.h"
#include "feature_swd.h"
#include "alm_api.h"
#include <string.h>

/* External variables ---------------------------------------------- */
extern osMessageQueueId_t queSwdTaskHandle;

/* Private define -------------------------------------------------- */
/* Private typedef ------------------------------------------------- */
/* Private function prototypes ------------------------------------- */
/* Private variables ----------------------------------------------- */
PUBLIC char gpcSwdLog[SWD_LOG_MAX][SWD_LOG_LEN];
PUBLIC uint8_t gu8SwdLogIndex;

/* Public functions ------------------------------------------------ */
PUBLIC void vidTaskSwdInitialize(void) {
  setbuf(stdout, NULL);
  gu8SwdLogIndex = 0;
  memset(gpcSwdLog, 0, sizeof(gpcSwdLog));
}

/* Private functions ----------------------------------------------- */
PUBLIC void vidTaskSwdProcess(void) {
  BaseType_t xStatus;
  uint8_t u8Received;

  xStatus = xQueueReceive(queSwdTaskHandle, &u8Received, portMAX_DELAY);
  if (xStatus == pdPASS)
  {
    printf("[%02d] %s\r\n", u8Received, gpcSwdLog[u8Received]);
  }
}
