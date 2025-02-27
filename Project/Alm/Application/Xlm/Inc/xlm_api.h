/**
 * @file    xlm_api.h
 * @brief   This file provides XBM and XLM defines, types and interfaces to ALM modules. 
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Define to prevent recursive inclusion --------------------------- */
#ifndef XLM_INC_XLM_API_H_
#define XLM_INC_XLM_API_H_

/* Includes -------------------------------------------------------- */
/* Exported defines ------------------------------------------------ */
/* Exported types -------------------------------------------------- */
/* Exported functions prototypes ----------------------------------- */
#include "alm_api.h"

/* Exported defines ------------------------------------------------ */
/* Exported types -------------------------------------------------- */
/** tstrXbmRegisterArgs shall be passed by ISB to configure XBM feature. */
typedef struct {
  U16 u16MatchCount;                        /**< The match count of button for chattering prevention. */
  U16 u16EventThreshHold;                   /**< The threshold press time to distinguish short-press from long-press. */
  tpfXbmNotifyCallback pfXbmNotifyCallback; /**< Callback notification for XBM. */
} tstrXbmRegisterArgs;

/** tstrXbmProcessArgs shall be passed by ISB to extract event by XBM. */
typedef struct {
  BOOL bIsPushed;                           /**< Button is pushed or not. */
} tstrXbmProcessArgs;

/** tstrXlmRegisterArgs shall be passed by ISB to configure XBM feature. */
typedef struct {
  U16 u16Cycle;                             /**< The periodic cycle for fading. */
  U16 u16FadeInTimeOut;                     /**< The fade in timeout. */
  U16 u16FadeOutTimeOut;                    /**< The fade out timeout. */
  tpfXlmNotifyCallback pfXlmNotifyCallback; /**< Callback notification for XLM. */
} tstrXlmRegisterArgs;

/** tstrXlmProcessArgs shall be passed by ISB to extract event by XBM. */
typedef struct {
  tenuIsbEvent enuEvent;
} tstrXlmProcessArgs;

/* Exported functions prototypes ----------------------------------- */
EXTERN void vidXbmInitialize(void);
EXTERN void vidXbmRegister(tstrXbmRegisterArgs* pstrArgs);
EXTERN void vidXbmProcess(tstrXbmProcessArgs* pstrArgs);

EXTERN void vidXlmInitialize(void);
EXTERN void vidXlmRegister(tstrXlmRegisterArgs* pstrArgs);
EXTERN void vidXlmProcess(tstrXlmProcessArgs* pstrArgs);

#endif /* XLM_INC_XLM_API_H_ */
