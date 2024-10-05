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
#include "alm_def.h"

/* Exported defines ----------------------------------------------------------*/
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
  U8* pu8Log;               /**< The logs set by XBM through tpfXbmNotifyCallback. */
} tstrXbmNotifyArgs;

/** tpfXbmNotifyCallback shall be implemented in ISB and callback by XBM. */
typedef void (*tpfXbmNotifyCallback)(tstrXbmNotifyArgs* pstrArgs);

/* Exported constants --------------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/
EXTERN void vidIsbInitialize(void* pvArgs);
EXTERN void vidIsbService(void* pvArgs);
EXTERN tenuIsbEvent enuIsbGetEvent(void);

EXTERN void vidIslInitialize(void* pvArgs);
EXTERN void vidIslService(void* pvArgs);

#endif /* ALM_INC_ALM_API_H_ */
