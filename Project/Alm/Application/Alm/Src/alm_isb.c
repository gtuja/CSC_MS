/**
 * @file    alm_isb.c
 * @brief   This file is used to implement ISB (Interrupt Service for Button).
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"
#include "feature.h"
#include "alm_api.h"
#include "xlm_api.h"
#include <string.h>

/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
typedef struct {
  tenuIsbEvent enuEvent;
} tstrIsbControl;

/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
PRIVATE void vidXbmNotifyCallback(tenuXbmNotify enuType, tstrXbmNotifyArgs* pArgs);

/* Private variables ---------------------------------------------------------*/
PRIVATE tstrIsbControl gstrControl;

/* Public functions ----------------------------------------------------------*/
PUBLIC void vidIsbInitialize(void* pvArgs) {
  tstrXbmRegisterArgs strArgs;

  vidXbmInitialize();

  memset(&gstrControl, 0, sizeof(gstrControl));
  strArgs.u16MatchCount = (U16)XBM_MATCH_CNT;
  strArgs.u16EventThreshHold = (U16)XBM_EVT_TH;
  strArgs.pfXbmNotifyCallback = vidXbmNotifyCallback;
  vidXbmRegister(&strArgs);
}

PUBLIC void vidIsbService(void* pvArgs) {
  BOOL bIsPushed;

  /* use GPIOC, GPIO_PIN_13 to reduce dependencies. */
  bIsPushed = (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) ? FALSE : TRUE;
  vidXbmProcess(bIsPushed);
}

PUBLIC tenuIsbEvent enuIsbGetEvent(void) {
  return gstrControl.enuEvent;
}

PRIVATE void vidXbmNotifyCallback(tenuXbmNotify enuType, tstrXbmNotifyArgs* pArgs) {
  switch(enuType) {
  case XBM_NTF_EVT :
    gstrControl.enuEvent = pArgs->enuEvent;
    break;
  case XBM_NTF_LOG :
    break;
  default :
    break;
  }
}
