/**
 * @file    xlm_xbm.c
 * @brief   This file is used to implement XBM (eXtension Button Module).
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

/** Private tenuXbmEvt, with inline docs. */
typedef enum {
  XBM_EVT_NA = 0, /**< XBM event, not available. */
  XBM_EVT_RLS,    /**< XBM event, button is released. */
  XBM_EVT_PSH,    /**< XBM event, button is pushed. */
  XBM_EVT_MAX,    /**< XBM maximum event.  */
} tenuXbmEvt;

/** Private tenuXbmState, with inline docs. */
typedef enum {
  XBM_STT_NA = 0,   /**< XBM state, not available. */
  XBM_STT_RLS,      /**< XBM state, button is released. */
  XBM_STT_PSH_CFM,  /**< XBM state, button is pushed, but under confirmation. */
  XBM_STT_PSH,      /**< XBM state, button is pushed. */
  XBM_STT_RLS_CFM,  /**< XBM state, button is pushed, but under confirmation. */
  XBM_STT_MAX,      /**< XBM maximum state.  */
} tenuXbmState;

/** Private tenuXbmStateFunction, with inline docs. */
typedef enum {
  XBM_STT_FTN_ENTRY = 0,  /**< XBM state function, entry. */
  XBM_STT_FTN_DO,         /**< XBM state function, do. */
  XBM_STT_FTN_EXIT,       /**< XBM state function, exit. */
  XBM_STT_FTN_MAX,        /**< XBM maximum state function. */
} tenuXbmStateFunction;

/** Private typedef XBM state functions */
typedef void (*tpfXbmStateFunction)(void* pvArgs);

/** Private tstrXbmStateFunction, with inline docs. */
typedef struct {
  tpfXbmStateFunction pfEntry;  /**< XBM state function, entry. */
  tpfXbmStateFunction pfDo;     /**< XBM state function, do. */
  tpfXbmStateFunction pfExit;   /**< XBM state function, exit. */
} tstrXbmStateFunction;

/** tstrIsbControl is holding information controlled by XBM. */
typedef struct {
  tstrXbmRegisterArgs strArgs;          /**< strArgs is XBM feature set by ISB with XBM API vidXbmRegister. */
  U32                 u32MatchCounter;  /**< u32MatchCounter is used for chattering prevention within XBM state machine. */
  U32                 u32PressCounter;  /**< u32PressCounter is used for fetching ISB event(tenuIsbEvent) within XBM state machine. */
  tenuXbmState        enuStateCurrent;  /**< The current XBM state. */
  tenuXbmState        enuStatePrevious; /**< The previous XBM state. */
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
PRIVATE tstrXbmControl gstrControl;  /** gstrControl is a private variable holding information controlled by XBM. */

/** gpfXbmStateFunctionTable is a private const table holding XBM state functions. */
PRIVATE const tpfXbmStateFunction gpfXbmStateFunctionTable[XBM_STT_MAX][XBM_STT_FTN_MAX] = {
                        /*  XBM_STT_FTN_ENTRY   XBM_STT_FTN_DO  XBM_STT_FTN_EXIT  */
  /* XBM_STT_NA */      {   NULL,               NULL,           NULL              },
  /* XBM_STT_RLS */     {   vidXbmRlsEntry,     vidXbmRlsDo,    vidXbmRlsExit     },
  /* XBM_STT_PSH_CFM */ {   vidXbmPshCfmEntry,  vidXbmPshCfmDo, vidXbmPshCfmExit  },
  /* XBM_STT_PSH */     {   vidXbmPshEntry,     vidXbmPshDo,    vidXbmPshExit     },
  /* XBM_STT_RLS_CFM */ {   vidXbmRlsCfmEntry,  vidXbmRlsCfmDo, vidXbmRlsCfmExit  },
};

/** gstrXbmTransitionTbl is a private const table holding state transition information with each event. */
PRIVATE const tenuXbmState gstrXbmTransitionTbl[XBM_STT_MAX][XBM_EVT_MAX] = {
                        /* XBM_EVT_NA  XBM_EVT_PSH      XBM_EVT_RLS */
  /* XBM_STT_NA */      {  XBM_STT_NA, XBM_STT_NA,      XBM_STT_NA      },
  /* XBM_STT_RLS */     {  XBM_STT_NA, XBM_STT_PSH_CFM, XBM_STT_NA      },
  /* XBM_STT_PSH_CFM */ {  XBM_STT_NA, XBM_STT_NA,      XBM_STT_RLS     },
  /* XBM_STT_PSH */     {  XBM_STT_NA, XBM_STT_NA,      XBM_STT_RLS_CFM }, 
  /* XBM_STT_RLS_CFM */ {  XBM_STT_NA, XBM_STT_RLS,     XBM_STT_NA      },
};

/* Public functions ----------------------------------------------------------*/
/**
 * @brief   Public function that initialize XBM called by ISB.
 * @param   void
 * @sa      vidIsbInitialize
 * @return  void
 */
PUBLIC void vidXbmInitialize(void) {
  memset(&gstrControl, 0, sizeof(gstrControl));
  gstrControl.enuStateCurrent = XBM_STT_RLS;
  gstrControl.enuStatePrevious = XBM_STT_NA;
}

/**
 * @brief   Public function that register XBM features by ISB.
 * @param   pstrArgs  XBM features set by ISB.
 * @sa      vidIsbInitialize
 * @sa      tstrXbmRegisterArgs
 * @return  void
 */
PUBLIC void vidXbmRegister(tstrXbmRegisterArgs* pstrArgs) {
  memcpy(&gstrControl.strArgs, pstrArgs, sizeof(tstrXbmRegisterArgs));
}

/**
 * @brief   Public function that process XBM called by ISB.
 * @param   void
 * @sa      vidIsbService
 * @return  void
 */
PUBLIC void vidXbmProcess(tstrXbmProcessArgs* pstrArgs) {
  tenuXbmEvt enuEvent;
  tenuXbmState enuStateNext;

  /* Get the next state with data passed and event extracted. */
  enuEvent = (pstrArgs->bIsPushed == TRUE) ? XBM_EVT_PSH : XBM_EVT_RLS;
  enuStateNext = gstrXbmTransitionTbl[(U16)gstrControl.enuStateCurrent][(U16)enuEvent];

  /* Transit states if needed. */
  if (enuStateNext != XBM_STT_NA || enuStateNext != XBM_STT_MAX) {
    vidXbmTransit(enuStateNext, NULL);
  }

  /* Process the do state function. */
  if (gpfXbmStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XBM_STT_FTN_DO] != NULL) {
    gpfXbmStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XBM_STT_FTN_DO](NULL);
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
    if (gpfXbmStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XBM_STT_FTN_EXIT] != NULL) {
      gpfXbmStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XBM_STT_FTN_EXIT](NULL);
    }
    /* Transit states. */
    gstrControl.enuStatePrevious = gstrControl.enuStateCurrent;
    gstrControl.enuStateCurrent = enuStateNext;

    /* Process the entry state function of the next state. */
    if (gpfXbmStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XBM_STT_FTN_ENTRY] != NULL) {
      gpfXbmStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XBM_STT_FTN_ENTRY](NULL);
    }
  } 
}

/**
 * @brief   Private entry function that is processed when the state is transited to XBM_STT_RLS.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmRlsEntry(void* pvArgs) {
  tstrXbmNotifyArgs strArgs;

  if ((gstrControl.u32PressCounter != (U32)0) && (gstrControl.u32PressCounter <= (U32)gstrControl.strArgs.u16EventThreshHold)) {
    strArgs.enuNotify = XBM_NTF_EVT;
    strArgs.enuEvent = ISB_EVT_SHORT;
    if (gstrControl.strArgs.pfXbmNotifyCallback != NULL) {
      gstrControl.strArgs.pfXbmNotifyCallback(&strArgs);
    }
  }
  gstrControl.u32PressCounter = (U32)0;
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
  gstrControl.u32MatchCounter = (U32)0;
}

/**
 * @brief   Private do function that is processed on XBM_STT_PRS_CFM.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmPshCfmDo(void* pvArgs) {
  gstrControl.u32MatchCounter++;

  if (gstrControl.u32MatchCounter > gstrControl.strArgs.u16MatchCount)
  {
    vidXbmTransit(XBM_STT_PSH, NULL);
  }
}

/**
 * @brief   Private exit function that is processed when the state go out from XBM_STT_PRS_CFM.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmPshCfmExit(void* pvArgs) {
  gstrControl.u32MatchCounter = (U32)0;
}

/**
 * @brief   Private entry function that is processed when the state is transited to XBM_STT_PRS.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmPshEntry(void* pvArgs) {
  gstrControl.u32PressCounter = (U32)0;
}

/**
 * @brief   Private do function that is processed on XBM_STT_PRS.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmPshDo(void* pvArgs) {
  tstrXbmNotifyArgs strArgs; 
  
  gstrControl.u32PressCounter++;
  if (gstrControl.u32PressCounter > (U32)gstrControl.strArgs.u16EventThreshHold) {
    strArgs.enuNotify = XBM_NTF_EVT;
    strArgs.enuEvent = ISB_EVT_LONG;
    if (gstrControl.strArgs.pfXbmNotifyCallback != NULL) {
      gstrControl.strArgs.pfXbmNotifyCallback(&strArgs);
    }
  }
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
  gstrControl.u32MatchCounter = (U32)0;
}

/**
 * @brief   Private do function that is processed on XBM_STT_RLS_CFM.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmRlsCfmDo(void* pvArgs) {
  gstrControl.u32MatchCounter++;

  if (gstrControl.u32MatchCounter > gstrControl.strArgs.u16MatchCount)
  {
    vidXbmTransit(XBM_STT_RLS, NULL);
  }
}

/**
 * @brief   Private exit function that is processed when the state go out from XBM_STT_RLS_CFM.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXbmRlsCfmExit(void* pvArgs) {
  gstrControl.u32MatchCounter = (U32)0;
}
