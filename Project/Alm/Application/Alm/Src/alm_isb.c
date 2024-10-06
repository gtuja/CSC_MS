/**
 * @file    alm_isb.c
 * @brief   This file is used for implementing ISB (Interrupt Service for Button).
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"
#include "feature.h"
#include "feature_swd.h"
#include "alm_api.h"
#include "xlm_api.h"
#include <string.h>

/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/

/** Private tstrIsbControl is holding information controlled by ISB. */
typedef struct {
  tenuIsbEvent enuEvent;  /**< enuEvent might be set by XBM and referenced by ISL. */
} tstrIsbControl;

/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
PRIVATE void vidXbmNotifyCallback(tstrXbmNotifyArgs* pstrArgs);

/* Private variables ---------------------------------------------------------*/
PRIVATE tstrIsbControl gstrControl;  /** gstrControl is a private variable holding information controlled by ISB. */

/* Public functions ----------------------------------------------------------*/
/**
 * @brief   Public function that initialize ISB.
 * @param   pvArgs  Arguments shall be set if needed.
 * @sa      vidXbmInitialize
 * @sa      tstrXbmRegisterArgs
 * @sa      vidXbmRegister
 * @return  void
 */
PUBLIC void vidIsbInitialize(void* pvArgs) {
  tstrXbmRegisterArgs strArgs;

  vidXbmInitialize();

  memset(&gstrControl, 0, sizeof(gstrControl));
  strArgs.u16MatchCount = (U16)XBM_MATCH_CNT;
  strArgs.u16EventThreshHold = (U16)XBM_EVT_TH;
  strArgs.pfXbmNotifyCallback = vidXbmNotifyCallback;
  vidXbmRegister(&strArgs);
}

/**
 * @brief   Public function that process ISB features as a periodic service.
 * @param   pvArgs  Arguments shall be set if needed.
 * @note    This function shall be called every PRD_SRV_HIGH by vApplicationTickHook.
 *          In this function, ISB shall retrieve button state and pass it with XBM API vidXbmProcess.
 * @sa      tstrXbmProcessArgs
 * @sa      vidXbmProcess
 * @return  void
 */
PUBLIC void vidIsbService(void* pvArgs) {
  tstrXbmProcessArgs strArgs;
  
  gstrControl.enuEvent = ISB_EVT_NA;  /* Clear event to prevent duplicate processing. */

  /* Retrieve GPIO state and use GPIOC, GPIO_PIN_13 to reduce dependencies. */
  strArgs.bIsPushed = (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) ? FALSE : TRUE;
  vidXbmProcess(&strArgs);
}

/**
 * @brief   Public function to get the gstrControl.enuEvent.
 * @param   void
 * @note    gstrControl.enuEvent might be set by vidXbmProcess with vidXbmNotifyCallback, if needed.
 *          gstrControl.enuEvent shall be initialized before vidXbmProcess to prevent duplicate processing.
 * @sa      vidIslService
 * @sa      vidXlmProcess
 * @return  tenuIsbEvent  The current ISB event.
 */
PUBLIC tenuIsbEvent enuIsbGetEvent(void) {
  return gstrControl.enuEvent;
}

/**
 * @brief   Private callback function called by XBM to notify something, e.g., ISB event, logs, etc.
 * @param   pstrArgs  Arguments from XBM.
 * @sa      tstrXbmNotifyArgs
 * @sa      vidXbmProcess
 * @return  void
 */
PRIVATE void vidXbmNotifyCallback(tstrXbmNotifyArgs* pstrArgs) {
  switch(pstrArgs->enuNotify) {
  case XBM_NTF_EVT :
    gstrControl.enuEvent = pstrArgs->enuEvent;
    break;
  case XBM_NTF_LOG :
    SWD_LOG("[%2d][XBM] %s", gu8SwdLogIndex, (char*)pstrArgs->pu8Log);
    break;
  default :
    break;
  }
}
