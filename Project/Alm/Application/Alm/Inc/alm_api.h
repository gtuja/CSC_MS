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
#include "feature.h"
#include "alm_def.h"

/* Exported defines ----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/
EXTERN void vidIsbInitialize(void* pvArgs);
EXTERN void vidIsbService(void* pvArgs);
EXTERN void vidIslInitialize(void* pvArgs);
EXTERN void vidIslService(void* pvArgs);

#endif /* ALM_INC_ALM_API_H_ */
