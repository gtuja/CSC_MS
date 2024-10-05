/**
 * @file    xlm_xbm.c
 * @brief   This file is used to implement XBM (Extension Button Module).
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Includes ------------------------------------------------------------------*/
#include "alm_api.h"
#include "xlm_api.h"
#include <string.h>

/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
typedef struct {
  tstrXbmRegisterArgs strArgs;
  U32                 u32MatchCounter;
  U32                 u32PressCounter;
} tstrXbmControl;

/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static tstrXbmControl gstrControl;

/* Public functions ----------------------------------------------------------*/

PUBLIC void vidXbmInitialize(void) {
  memset(&gstrControl, 0, sizeof(gstrControl));
}

PUBLIC void vidXbmRegister(tstrXbmRegisterArgs* pstrArgs) {
  memcpy(&gstrControl.strArgs, pstrArgs, sizeof(tstrXbmRegisterArgs));
}

PUBLIC void vidXbmProcess(BOOL bIsPushed) {

}

