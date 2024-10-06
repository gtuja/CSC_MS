/**
 * @file    alm_isl.c
 * @brief   This file is used for implementing ISL (Interrupt Service for LED).
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"
#include "feature.h"
#include "feature_periodic.h"
#include "alm_api.h"
#include "xlm_api.h"
#include <string.h>

/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/** Private tstrIsbControl is holding information controlled by ISL. */

/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
PRIVATE void vidXlmNotifyCallback(tstrXlmNotifyArgs* pstrArgs);

/* Public functions ----------------------------------------------------------*/
/**
 * @brief   Public function that initialize ISL.
 * @param   pvArgs  Arguments shall be set if needed.
 * @sa      vidXlmInitialize
 * @sa      tstrXlmRegisterArgs
 * @sa      vidXlmRegister
 * @return  void
 */
PUBLIC void vidIslInitialize(void* pvArgs) {
  tstrXlmRegisterArgs strArgs;

  vidXlmInitialize();

  strArgs.u16Cycle = (U16)PRD_SRV_HIGH;
  strArgs.u16FadeInTimeOut = (U16)XLM_FADE_IN_TMO;
  strArgs.u16FadeOutTimeOut = (U16)XLM_FADE_OUT_TMO;
  strArgs.pfXlmNotifyCallback = vidXlmNotifyCallback;
  vidXlmRegister(&strArgs);
}

/**
 * @brief   Public function that process ISL features as a periodic service.
 * @param   pvArgs  Arguments shall be set if needed.
 * @note    This function shall be called every PRD_SRV_HIGH by vApplicationTickHook.
 *          In this function, ISL shall get button event and pass it with XLM API vidXlmProcess.
 * @sa      tstrXlmProcessArgs
 * @sa      vidXlmProcess
 * @return  void
 */
PUBLIC void vidIslService(void* pvArgs) {
  tstrXlmProcessArgs strArgs;
  strArgs.enuEvent = enuIsbGetEvent();

  vidXlmProcess(&strArgs);
}

/**
 * @brief   Public function to fetch the LED state.
 * @param   void
 * @sa      vidIslService
 * @sa      vidXlmProcess
 * @return  BOOL  TRUE if LED duty > 0.
 */
PUBLIC BOOL bIslIsLedOn(void) {
  /* TBD : return TRUE if LED duty is on(>0). */
  return FALSE;
}

/**
 * @brief   Private callback function called by XLM to notify something, e.g., LED duty, logs, etc.
 * @param   pstrArgs  Arguments from XLM.
 * @sa      tstrXlmNotifyArgs
 * @sa      vidXlmProcess
 * @return  void
 */
PRIVATE void vidXlmNotifyCallback(tstrXlmNotifyArgs* pstrArgs) {
  switch(pstrArgs->enuNotify) {
  case XLM_NTF_OUTPUT :
    /* TBD : LED output with duty passed by XLM. */
    break;
  case XLM_NTF_LOG :
    /* TBD : log output with string passed by XLM. */
    break;
  default :
    break;
  }
}

