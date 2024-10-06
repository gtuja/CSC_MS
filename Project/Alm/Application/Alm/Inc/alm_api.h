/**
 * @file    alm_api.h
 * @brief   This file provides defines, types and interfaces between ALM and XLM modules.  
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

#ifndef ALM_INC_ALM_API_H_
#define ALM_INC_ALM_API_H_

/* Includes ------------------------------------------------------------------*/
#include "feature.h"
#include "alm_def.h"

/* Exported defines ----------------------------------------------------------*/
#define ALM_LOG_LEN   50  /* Log imitation, i.e., SWD_LOG_LEN - 21. */

/* Exported types ------------------------------------------------------------*/

/** tenuIsbEvent, with inline docs. */
typedef enum {
  ISB_EVT_NA = 0, /**< ISB event, not available. */
  ISB_EVT_SHORT,  /**< ISB event, short-press. @sa XBM_EVT_TH */
  ISB_EVT_LONG,   /**< ISB event, long-press. @sa XBM_EVT_TH */
  ISB_EVT_MAX,    /**< ISB maximum event. */
} tenuIsbEvent;

/** tenuXbmNotify, with inline docs. */
typedef enum {
  XBM_NTF_NA = 0, /**< XBM notification, not available. */
  XBM_NTF_EVT,    /**< XBM notification, tenuIsbEvent shall be set by XBM through tpfXbmNotifyCallback. */
  XBM_NTF_LOG,    /**< XBM notification, logs shall be set by XBM through tpfXbmNotifyCallback. */
  XBM_NTF_MAX,    /**< XBM maximum notification. */
} tenuXbmNotify;

/** tstrXbmNotifyArgs shall passed by XBM using tpfXbmNotifyCallback implemented in ISB. */
typedef struct {
  tenuXbmNotify enuNotify;  /**< The notification type from XBM. */
  tenuIsbEvent enuEvent;    /**< The ISB event set by XBM through tpfXbmNotifyCallback. */
  char pu8Log[ALM_LOG_LEN]; /**< The logs set by XBM through tpfXbmNotifyCallback. */
} tstrXbmNotifyArgs;

/** tpfXbmNotifyCallback shall be implemented in ISB and callback by XBM. */
typedef void (*tpfXbmNotifyCallback)(tstrXbmNotifyArgs* pstrArgs);

/** tenuXlmNotify, with inline docs. */
typedef enum {
  XLM_NTF_NA = 0, /**< XLM notification, not available. */
  XLM_NTF_OUTPUT, /**< XLM notification, LED duty shall be set by XLM through tpfXlmNotifyCallback. */
  XLM_NTF_LOG,    /**< XLM notification, logs shall be set by XBM through tpfXlmNotifyCallback. */
  XLM_NTF_MAX,    /**< XLM maximum notification. */
} tenuXlmNotify;

/** tstrXlmNotifyArgs shall passed by XBM using tpfXlmNotifyCallback implemented in ISB. */
typedef struct {
  tenuXlmNotify enuNotify;  /**< The notification type from XLM. */
  U16 u16Duty;              /**< The LED duty set by XLM through tpfXlmNotifyCallback. */
  char pu8Log[ALM_LOG_LEN]; /**< The logs set by XLM through tpfXlmNotifyCallback. */
} tstrXlmNotifyArgs;

/** tpfXlmNotifyCallback shall be implemented in ISB and callback by XBM. */
typedef void (*tpfXlmNotifyCallback)(tstrXlmNotifyArgs* pstrArgs);

/* Exported constants --------------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/
EXTERN void vidIsbInitialize(void* pvArgs);
EXTERN void vidIsbService(void* pvArgs);
EXTERN tenuIsbEvent enuIsbGetEvent(void);

EXTERN void vidIslInitialize(void* pvArgs);
EXTERN void vidIslService(void* pvArgs);

EXTERN void vidTaskBtnInitialize(void);
EXTERN void vidTaskLedInitialize(void);
EXTERN void vidTaskSwdInitialize(void);

EXTERN void vidTaskBtnProcess(void);
EXTERN void vidTaskLedProcess(void);
EXTERN void vidTaskSwdProcess(void);

#endif /* ALM_INC_ALM_API_H_ */
