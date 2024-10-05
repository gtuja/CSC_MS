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
typedef enum {
  XBM_EVT_NA = 0,
  XBM_EVT_RLS,
  XBM_EVT_PSH,
  XBM_EVT_MAX,
} tenuXbmEvt;

typedef enum {
  XBM_STT_NA = 0,
  XBM_STT_RLS,
  XBM_STT_PSH_CFM,
  XBM_STT_PSH,
  XBM_STT_RLS_CFM,
  XBM_STT_MAX,
} tenuXbmState;

typedef enum {
  XBM_STT_FTN_ENTRY = 0,
  XBM_STT_FTN_DO,
  XBM_STT_FTN_EXIT,
  XBM_STT_FTN_MAX,
} tenuXbmStateFunction;

typedef void (*tpfXbmStateFunction)(void* pvArgs);
typedef struct {
  tpfXbmStateFunction pfEntry;
  tpfXbmStateFunction pfDo;
  tpfXbmStateFunction pfExit;
} tstrXbmStateFunction;

typedef struct {
  tstrXbmRegisterArgs strArgs;
  U32                 u32MatchCounter;
  U32                 u32PressCounter;
  tenuXbmState        enuStateCurrent;
  tenuXbmState        enuStatePrevious;
} tstrXbmControl;



/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
PRIVATE void vidXbmTransit(tenuXbmState enuStateNext, void* pvArgs);

PRIVATE void vidXbmRlsEntry(void* pvArgs);
PRIVATE void vidXbmRlsDo(void* pvArgs);
PRIVATE void vidXbmRlsExit(void* pvArgs);

PRIVATE void vidXbmPshCfmEntry(void* pvArgs);
PRIVATE void vidXbmPshCfmDo(void* pvArgs);
PRIVATE void vidXbmPshCfmExit(void* pvArgs);

PRIVATE void vidXbmPshEntry(void* pvArgs);
PRIVATE void vidXbmPshDo(void* pvArgs);
PRIVATE void vidXbmPshExit(void* pvArgs);

PRIVATE void vidXbmRlsCfmEntry(void* pvArgs);
PRIVATE void vidXbmRlsCfmDo(void* pvArgs);
PRIVATE void vidXbmRlsCfmExit(void* pvArgs);

/* Private variables ---------------------------------------------------------*/
PRIVATE tstrXbmControl gstrControl;
PRIVATE const tpfXbmStateFunction gpfXmbStateFunctionTable[XBM_STT_MAX][XBM_STT_FTN_MAX] = {
                        /*  XBM_STT_FTN_ENTRY   XBM_STT_FTN_DO  XBM_STT_FTN_EXIT  */
  /* XBM_STT_NA */      {   NULL,               NULL,           NULL              },
  /* XBM_STT_RLS */     {   vidXbmRlsEntry,     vidXbmRlsDo,    vidXbmRlsExit     },
  /* XBM_STT_PSH_CFM */ {   vidXbmPshCfmEntry,  vidXbmPshCfmDo, vidXbmPshCfmExit  },
  /* XBM_STT_PSH */     {   vidXbmPshEntry,     vidXbmPshDo,    vidXbmPshExit     },
  /* XBM_STT_RLS_CFM */ {   vidXbmRlsCfmEntry,  vidXbmRlsCfmDo, vidXbmRlsCfmExit  },
};

PRIVATE const tenuXbmState gstrXbmTransitionTbl[XBM_STT_MAX][XBM_EVT_MAX] = 
{
                        /* XBM_EVT_NA  XBM_EVT_PSH      XBM_EVT_RLS */
  /* XBM_STT_NA */      {  XBM_STT_NA, XBM_STT_NA,      XBM_STT_NA      },
  /* XBM_STT_RLS */     {  XBM_STT_NA, XBM_STT_PSH_CFM, XBM_STT_NA      },
  /* XBM_STT_PSH_CFM */ {  XBM_STT_NA, XBM_STT_NA,      XBM_STT_RLS     },
  /* XBM_STT_PSH */     {  XBM_STT_NA, XBM_STT_NA,      XBM_STT_RLS_CFM }, 
  /* XBM_STT_RLS_CFM */ {  XBM_STT_NA, XBM_STT_RLS,     XBM_STT_NA      },
};

/* Public functions ----------------------------------------------------------*/

PUBLIC void vidXbmInitialize(void) {
  memset(&gstrControl, 0, sizeof(gstrControl));
}

PUBLIC void vidXbmRegister(tstrXbmRegisterArgs* pstrArgs) {
  memcpy(&gstrControl.strArgs, pstrArgs, sizeof(tstrXbmRegisterArgs));
}

PUBLIC void vidXbmProcess(BOOL bIsPushed) {
  tenuXbmEvt enuEvent;
  tenuXbmState enuStateNext;

  /* Get the next state with data passed. */
  enuEvent = (bIsPushed == TRUE) ? XBM_EVT_PSH : XBM_EVT_RLS;
  enuStateNext = gstrXbmTransitionTbl[(U16)gstrControl.enuStateCurrent][(U16)enuEvent];

  /* Transit states if needed. */
  if (enuStateNext != XBM_STT_NA || enuStateNext != XBM_STT_MAX) {
    vidXbmTransit(enuStateNext, NULL);
  }

  /* Process the do state function. */
  if (gpfXmbStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XBM_STT_FTN_DO] != NULL) {
    gpfXmbStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XBM_STT_FTN_DO](NULL);
  }
}

/* Private functions ---------------------------------------------------------*/

/**
 * @brief   Private function that transit state on XBM.
 * @param   enuStateNext  The next state to transit.
 * @param   pvArgs        Arguments shall be set if needed.
 * @return  void
 */
PRIVATE void vidXbmTransit(tenuXbmState enuStateNext, void* pvArgs) {
  if (enuStateNext != XBM_STT_NA || enuStateNext != XBM_STT_MAX) {
    /* Process the exit state function of the current state. */
    if (gpfXmbStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XBM_STT_FTN_EXIT] != NULL) {
      gpfXmbStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XBM_STT_FTN_EXIT](NULL);
    }
    /* Transit states. */
    gstrControl.enuStatePrevious = gstrControl.enuStateCurrent;
    gstrControl.enuStateCurrent = enuStateNext;

    /* Process the entry state function of the next state. */
    if (gpfXmbStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XBM_STT_FTN_ENTRY] != NULL) {
      gpfXmbStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XBM_STT_FTN_ENTRY](NULL);
    }
  } 
}

/**
 * @brief   Private entry function that is processed when the state is transited to XBM_STT_RLS.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmRlsEntry(void* pvArgs) {
}

/**
 * @brief   Private do function that is processed on XBM_STT_RLS.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmRlsDo(void* pvArgs) {
}

/**
 * @brief   Private exit function that is processed when the state go out from XBM_STT_RLS.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmRlsExit(void* pvArgs) {
}

/**
 * @brief   Private entry function that is processed when the state is transited to XBM_STT_PRS_CFM.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmPshCfmEntry(void* pvArgs) {
}

/**
 * @brief   Private do function that is processed on XBM_STT_PRS_CFM.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmPshCfmDo(void* pvArgs) {
}

/**
 * @brief   Private exit function that is processed when the state go out from XBM_STT_PRS_CFM.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmPshCfmExit(void* pvArgs) {
}

/**
 * @brief   Private entry function that is processed when the state is transited to XBM_STT_PRS.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmPshEntry(void* pvArgs) {
}

/**
 * @brief   Private do function that is processed on XBM_STT_PRS.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmPshDo(void* pvArgs) {
}

/**
 * @brief   Private exit function that is processed when the state go out from XBM_STT_PRS.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmPshExit(void* pvArgs) {
}

/**
 * @brief   Private entry function that is processed when the state is transited to XBM_STT_RLS_CFM.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmRlsCfmEntry(void* pvArgs) {
}

/**
 * @brief   Private do function that is processed on XBM_STT_RLS_CFM.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmRlsCfmDo(void* pvArgs) {
}

/**
 * @brief   Private exit function that is processed when the state go out from XBM_STT_RLS_CFM.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmRlsCfmExit(void* pvArgs) {
}


