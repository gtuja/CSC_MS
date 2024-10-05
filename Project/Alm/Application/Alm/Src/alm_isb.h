/**
 * @file    alm_isb.h
 * @brief   This file provides ISB defines, types and interfaces to ALM modules.  
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

#ifndef ALM_SRC_ALM_ISB_H_
#define ALM_SRC_ALM_ISB_H_

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

/* Exported constants --------------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/
EXTERN tenuIsbEvent enuIsbGetEvent(void);

#endif /* ALM_SRC_ALM_ISB_H_ */
