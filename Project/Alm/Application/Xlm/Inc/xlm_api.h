/**
 * @file    xlm_api.h
 * @brief   This file provides XBM and XLM defines, types and interfaces to ALM modules. 
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XLM_INC_XLM_API_H_
#define XLM_INC_XLM_API_H_

/* Includes ------------------------------------------------------------------*/
#include "alm_api.h"

/* Exported defines ----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/

typedef struct {
  U16 u16MatchCount;
  U16 u16EventThreshHold;
  tpfXbmNotifyCallback pfXbmNotifyCallback;
} tstrXbmRegisterArgs;

/* Exported constants --------------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/

EXTERN void vidXbmInitialize(void);
EXTERN void vidXbmRegister(tstrXbmRegisterArgs* pstrArgs);
EXTERN void vidXbmProcess(BOOL bIsPushed);

#endif /* XLM_INC_XLM_API_H_ */
