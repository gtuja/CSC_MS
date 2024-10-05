/**
 * @file    alm_api.h
 * @brief   This file provides defines, types and interfaces between ALM modules.  
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

typedef enum {
  ISB_EVT_NA = 0,
  ISB_EVT_SHORT,
  ISB_EVT_LONG,
  ISB_EVT_MAX,
} tenuIsbEvent;

typedef enum {
  XBM_NTF_NA = 0,
  XBM_NTF_EVT,
  XBM_NTF_LOG,
  XBM_NTF_MAX,
} tenuXbmNotify;

typedef struct {
  tenuXbmNotify enuNotify;
  tenuIsbEvent enuEvent;
  U8* pu8Log;
} tstrXbmNotifyArgs;

typedef void (*tpfXbmNotifyCallback)(tenuXbmNotify enuType, tstrXbmNotifyArgs* pArgs);

/* Exported constants --------------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/
EXTERN void vidIsbInitialize(void* pvArgs);
EXTERN void vidIsbService(void* pvArgs);
EXTERN void vidIslInitialize(void* pvArgs);
EXTERN void vidIslService(void* pvArgs);

#endif /* ALM_INC_ALM_API_H_ */
