/**
 * @file    alm_tob.c
 * @brief   This file is used for implementing TOB (Task Of Button, TSK_BTN).
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Includes ------------------------------------------------------------------*/
#include "feature.h"
#include "cmsis_os.h"
#include "queue.h"
#include "alm_api.h"

/* External variables --------------------------------------------------------*/
extern osMessageQueueId_t queBtnTaskHandle;

/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

PUBLIC void vidTaskBtnInitialize(void) {
}

PUBLIC void vidTaskBtnProcess(void) {
  BaseType_t xStatus;
  uint8_t u8Received;

  xStatus = xQueueReceive(queBtnTaskHandle, &u8Received, portMAX_DELAY);
  if (xStatus == pdPASS)
  {
    /* TBD */
  }
}
