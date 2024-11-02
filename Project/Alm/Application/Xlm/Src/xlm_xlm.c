/**
 * @file    xlm_xlm.c
 * @brief   This file is used to implement XLM (eXtension LED Module).
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Includes -------------------------------------------------------- */
#include "feature.h"
#include "feature_periodic.h"
#include "feature_swd.h"
#include "alm_api.h"
#include "xlm_api.h"
#include <string.h>

/* External variables ---------------------------------------------- */
/* Private define -------------------------------------------------- */
/* Private typedef ------------------------------------------------- */
/** Private tenuXlmState, with inline docs. */
typedef enum {
  XLM_STT_NA = 0,   /**< XLM state, not available. */
  XLM_STT_OFF,      /**< XLM state, LED is off. */
  XLM_STT_FADE_IN,  /**< XLM state, LED is under fade in. */
  XLM_STT_ON,       /**< XLM state, LED is on. */
  XLM_STT_FADE_OUT, /**< XLM state, LED is under fade out. */
  XLM_STT_MAX,      /**< XLM maximum state. */
} tenuXlmState;

/** Private tenuXlmStateFunction, with inline docs. */
typedef enum {
  XLM_STT_FTN_ENTRY = 0,  /**< XLM state function, entry. */
  XLM_STT_FTN_DO,         /**< XLM state function, do. */
  XLM_STT_FTN_EXIT,       /**< XLM state function, exit. */
  XLM_STT_FTN_MAX,        /**< XLM maximum state function. */
} tenuXlmStateFunction;

/** Private typedef XBM state functions */
typedef void (*tpfXlmStateFunction)(void* pvArgs);

/** Private tstrXlmStateFunction, with inline docs. */
typedef struct {
  tpfXlmStateFunction pfEntry;  /**< XLM state function, entry. */
  tpfXlmStateFunction pfDo;     /**< XLM state function, do. */
  tpfXlmStateFunction pfExit;   /**< XLM state function, exit. */
} tstrXlmStateFunction;

/** tstrXlmControl is holding information controlled by XLM. */
typedef struct {
  tstrXlmRegisterArgs strArgs;            /**< strArgs is XLM feature set by ISL with XLM API vidXlmRegister. */
  U32                 u32FadeCounter;     /**< u32MatchCounter is used for chattering prevention within XLM state machine. */
  U32                 u32FadeCounterMax;  /**< u32MatchCounter is used for chattering prevention within XLM state machine. */
  U32                 u32FadeDutyDiff;    /**< u32MatchCounter is used for chattering prevention within XLM state machine. */
  tenuXlmState        enuStateCurrent;    /**< The current XLM state. */
  tenuXlmState        enuStatePrevious;   /**< The previous XLM state. */
  tenuIsbEvent        enuEventCurrent;    /**< The current ISB event. */
  tenuIsbEvent        enuEventPrevious;   /**< The previous ISB event. */
} tstrXlmControl;

/* Private function prototypes ------------------------------------- */
PRIVATE void vidXlmTransit(tenuXlmState enuStateNext, void* pvArgs);

PRIVATE void vidXlmOffEntry(void* pvArgs);
PRIVATE void vidXlmOffDo(void* pvArgs);
PRIVATE void vidXlmOffExit(void* pvArgs);

PRIVATE void vidXlmFadeInEntry(void* pvArgs);
PRIVATE void vidXlmFadeInDo(void* pvArgs);
PRIVATE void vidXlmFadeInExit(void* pvArgs);

PRIVATE void vidXlmOnEntry(void* pvArgs);
PRIVATE void vidXlmOnDo(void* pvArgs);
PRIVATE void vidXlmOnExit(void* pvArgs);

PRIVATE void vidXlmFadeOffEntry(void* pvArgs);
PRIVATE void vidXlmFadeOffDo(void* pvArgs);
PRIVATE void vidXlmFadeOffExit(void* pvArgs);

PRIVATE void vidXlmOutput(U16 u16Duty);

/* Private variables ----------------------------------------------- */
PRIVATE tstrXlmControl gstrControl;  /** gstrControl is a private variable holding information controlled by XLM. */

/** gpfXlmStateFunctionTable is a private const table holding XLM state functions. */
PRIVATE const tpfXlmStateFunction gpfXlmStateFunctionTable[XLM_STT_MAX][XLM_STT_FTN_MAX] = {
                          /*  XLM_STT_FTN_ENTRY   LM_STT_FTN_DO     XLM_STT_FTN_EXIT  */
  /* XLM_STT_NA */        {   NULL,               NULL,             NULL              },
  /* XLM_STT_OFF */       {   vidXlmOffEntry,     vidXlmOffDo,      vidXlmOffExit     },
  /* XLM_STT_FADE_IN */   {   vidXlmFadeInEntry,  vidXlmFadeInDo,   vidXlmFadeInExit  },
  /* XLM_STT_ON */        {   vidXlmOnEntry,      vidXlmOnDo,       vidXlmOnExit      },
  /* XLM_STT_FADE_OUT */  {   vidXlmFadeOffEntry, vidXlmFadeOffDo,  vidXlmFadeOffExit },
};

/** gstrXlmTransitionTbl is a private const table holding state transition information with each event. */
PRIVATE const tenuXlmState gstrXlmTransitionTbl[XLM_STT_MAX][ISB_EVT_MAX] = 
{
                          /* ISB_EVT_NA  ISB_EVT_SHORT      ISB_EVT_LONG  */
  /* XLM_STT_NA */        {  XLM_STT_NA, XLM_STT_NA,        XLM_STT_NA,   },
  /* XLM_STT_OFF */       {  XLM_STT_NA, XLM_STT_FADE_IN,   XLM_STT_ON,   },
  /* XLM_STT_FADE_IN */   {  XLM_STT_NA, XLM_STT_NA,        XLM_STT_OFF,  },
  /* XLM_STT_ON */        {  XLM_STT_NA, XLM_STT_FADE_OUT,  XLM_STT_OFF,  }, 
  /* XLM_STT_FADE_OUT */  {  XLM_STT_NA, XLM_STT_NA,        XLM_STT_OFF,  },
};

/** gpcXbmStateNameTable and gpcXbmEventNameTable are state name for notification. */
PRIVATE const char* gpcXlmStateNameTable[XLM_STT_MAX] = {
  "XLM_STT_NA",
  "XLM_STT_OFF",
  "XLM_STT_FADE_IN",
  "XLM_STT_ON",
  "XLM_STT_FADE_OUT",
};

PRIVATE const char* gpcXlmEventNameTable[ISB_EVT_MAX] = {
  "ISB_EVT_NA",
  "ISB_EVT_SHORT",
  "ISB_EVT_LONG",
};

/* Public functions ------------------------------------------------ */
/**
 * @brief   Public function that initialize XLM called by ISL.
 * @param   void
 * @sa      vidIslInitialize
 * @return  void
 */
PUBLIC void vidXlmInitialize(void) {
  memset(&gstrControl, 0, sizeof(gstrControl));
  gstrControl.enuStateCurrent = XLM_STT_OFF;
  gstrControl.enuStatePrevious = XLM_STT_NA;
}

/**
 * @brief   Public function that register XLM features by ISL.
 * @param   pstrArgs  XLM features set by ISL.
 * @sa      vidIslInitialize
 * @sa      tstrXlmRegisterArgs
 * @return  void
 */
PUBLIC void vidXlmRegister(tstrXlmRegisterArgs* pstrArgs) {
  memcpy(&gstrControl.strArgs, pstrArgs, sizeof(tstrXlmRegisterArgs));
}

/**
 * @brief   Public function that process XLM called by ISL.
 * @param   void
 * @sa      vidIslService
 * @return  void
 */
PUBLIC void vidXlmProcess(tstrXlmProcessArgs* pstrArgs) {
  tenuXlmState enuStateNext;

  /* Update events. */
  gstrControl.enuEventPrevious = gstrControl.enuEventCurrent;
  gstrControl.enuEventCurrent = pstrArgs->enuEvent;
  
  /* Proceed if event is changed. */
  if (gstrControl.enuEventCurrent != gstrControl.enuEventPrevious) {
    if ((gstrControl.enuEventCurrent != ISB_EVT_NA) && (gstrControl.enuEventCurrent != ISB_EVT_MAX)) {
      enuStateNext = gstrXlmTransitionTbl[(U16)gstrControl.enuStateCurrent][(U16)gstrControl.enuEventCurrent];
      
      /* Transit states if needed. */
      if (enuStateNext != XLM_STT_NA || enuStateNext != XLM_STT_MAX) {
        vidXlmTransit(enuStateNext, NULL);
      }
    }
  }

  /* Process the do state function. */
  if (gpfXlmStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XLM_STT_FTN_DO] != NULL) {
    gpfXlmStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XLM_STT_FTN_DO](NULL);
  }
}

/* Private functions ----------------------------------------------- */
/**
 * @brief   Private function that transit state on XLM.
 * @param   enuStateNext  The next state to transit.
 * @param   pvArgs        Arguments shall be set if needed.
 * @return  void
 */
PRIVATE void vidXlmTransit(tenuXlmState enuStateNext, void* pvArgs) {
  tstrXlmNotifyArgs strArgs;

  if (enuStateNext != XLM_STT_NA || enuStateNext != XLM_STT_MAX) {
    /* Process the exit state function of the current state. */
    if (gpfXlmStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XLM_STT_FTN_EXIT] != NULL) {
      gpfXlmStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XLM_STT_FTN_EXIT](NULL);
    }

    /* Transit states. */
    gstrControl.enuStatePrevious = gstrControl.enuStateCurrent;
    gstrControl.enuStateCurrent = enuStateNext;

    /* Process the entry state function of the next state. */
    if (gpfXlmStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XLM_STT_FTN_ENTRY] != NULL) {
      gpfXlmStateFunctionTable[(U16)gstrControl.enuStateCurrent][(U16)XLM_STT_FTN_ENTRY](NULL);
    }
    
    /* Notify state transition. */
    strArgs.enuNotify = XLM_NTF_LOG; 
    snprintf(strArgs.pu8Log, SWD_LOG_LEN, "State changed [%s]->[%s] by [%s]", \
                                          gpcXlmStateNameTable[gstrControl.enuStatePrevious], \
                                          gpcXlmStateNameTable[gstrControl.enuStateCurrent],  \
                                          gpcXlmEventNameTable[gstrControl.enuEventCurrent]);
    if (gstrControl.strArgs.pfXlmNotifyCallback != NULL) {
      gstrControl.strArgs.pfXlmNotifyCallback(&strArgs);
    }
  } 
}

/**
 * @brief   Private entry function that is processed when the state is transited to XLM_STT_RLS.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXlmOffEntry(void* pvArgs) {
  vidXlmOutput(XLM_DUTY_MIN);
}

/**
 * @brief   Private do function that is processed on XLM_STT_RLS.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXlmOffDo(void* pvArgs) {
}

/**
 * @brief   Private exit function that is processed when the state go out from XLM_STT_RLS.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXlmOffExit(void* pvArgs) {
}

/**
 * @brief   Private entry function that is processed when the state is transited to XLM_STT_FADE_IN.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXlmFadeInEntry(void* pvArgs) {
  gstrControl.u32FadeCounter = (U32)0;
  gstrControl.u32FadeDutyDiff = (U32)((U32)XLM_DUTY_MAX - (U32)XLM_DUTY_MIN);
  gstrControl.u32FadeCounterMax = (U32)((((U32)XLM_FADE_IN_TMO<<10)/(U32)PRD_SRV_HIGH)>>10);
}

/**
 * @brief   Private do function that is processed on XLM_STT_FADE_IN.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXlmFadeInDo(void* pvArgs) {
  U16 u16Duty;

  gstrControl.u32FadeCounter++;
  if (gstrControl.u32FadeCounter >= gstrControl.strArgs.u16FadeInTimeOut)
  {
    vidXlmTransit(XLM_STT_ON, NULL);
  } else {
    u16Duty = (U16)((((gstrControl.u32FadeDutyDiff<<10)/gstrControl.u32FadeCounterMax)*gstrControl.u32FadeCounter)>>10);
    vidXlmOutput(u16Duty);
  }
}

/**
 * @brief   Private exit function that is processed when the state go out from XLM_STT_FADE_IN.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXlmFadeInExit(void* pvArgs) {
  gstrControl.u32FadeCounter = (U32)0;
}

/**
 * @brief   Private entry function that is processed when the state is transited to XLM_STT_ON.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXlmOnEntry(void* pvArgs) {
  vidXlmOutput(XLM_DUTY_MAX);
}

/**
 * @brief   Private do function that is processed on XLM_STT_ON.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXlmOnDo(void* pvArgs) {
}

/**
 * @brief   Private exit function that is processed when the state go out from XLM_STT_ON.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXlmOnExit(void* pvArgs) {
}

/**
 * @brief   Private entry function that is processed when the state is transited to XLM_STT_FADE_OFF.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXlmFadeOffEntry(void* pvArgs) {
  gstrControl.u32FadeCounter = (U32)0;
  gstrControl.u32FadeDutyDiff = (U32)((U32)XLM_DUTY_MAX - (U32)XLM_DUTY_MIN);
  gstrControl.u32FadeCounterMax = (U32)((((U32)XLM_FADE_OUT_TMO<<10)/(U32)PRD_SRV_HIGH)>>10);
}

/**
 * @brief   Private do function that is processed on XLM_STT_FADE_OFF.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXlmFadeOffDo(void* pvArgs) {
  U16 u16Duty;

  gstrControl.u32FadeCounter++;
  if (gstrControl.u32FadeCounter >= gstrControl.strArgs.u16FadeInTimeOut)
  {
    vidXlmTransit(XLM_STT_OFF, NULL);
  } else {
    u16Duty = (U16)((((gstrControl.u32FadeDutyDiff<<10)/gstrControl.u32FadeCounterMax)*gstrControl.u32FadeCounter)>>10);
    u16Duty = (u16Duty < (U16)XLM_DUTY_MAX) ? ((U16)XLM_DUTY_MAX - u16Duty) : (U16)0;
    vidXlmOutput(u16Duty);
  }
}

/**
 * @brief   Private exit function that is processed when the state go out from XLM_STT_FADE_OFF.
 * @param   pvArgs  Arguments reserved.
 * @return  void
 */
PRIVATE void vidXlmFadeOffExit(void* pvArgs) {
  gstrControl.u32FadeCounter = (U32)0;
}

/**
 * @brief   Private exit function that output LED with pfXlmNotifyCallback.
 * @param   u16Duty LED duty to output.
 * @return  void
 */
PRIVATE void vidXlmOutput(U16 u16Duty) {
  tstrXlmNotifyArgs strArgs;

  strArgs.enuNotify = XLM_NTF_OUTPUT;
  strArgs.u16Duty = (u16Duty >= (U16)XLM_DUTY_MAX) ? (U16)XLM_DUTY_MAX : u16Duty;
  if (gstrControl.strArgs.pfXlmNotifyCallback != NULL) {
    gstrControl.strArgs.pfXlmNotifyCallback(&strArgs);
  }
}
