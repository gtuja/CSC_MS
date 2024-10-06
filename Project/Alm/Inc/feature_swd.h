/**
 * @file    feature_swd.h
 * @brief   This file is used to ... 
 * @author  Gtuja
 * @date    Oct 6, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef FEATURE_SWD_H_
#define FEATURE_SWD_H_

/* Includes ------------------------------------------------------------------*/
#include "feature.h"
#include "cmsis_os.h"
#include "queue.h"
#include <stdio.h>

/* Exported defines ----------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
extern char gpcSwdLog[SWD_LOG_MAX][SWD_LOG_LEN];
extern uint8_t gu8SwdLogIndex;
extern osMessageQueueId_t queSwdTaskHandle;

/* Exported macro ------------------------------------------------------------*/
#define SWD_LOG_ISR(fmt, ...) { \
  snprintf(gpcSwdLog[gu8SwdLogIndex], SWD_LOG_LEN, fmt, __VA_ARGS__);  \
  xQueueSendFromISR(queSwdTaskHandle, &gu8SwdLogIndex, NULL);  \
  if (++gu8SwdLogIndex >= SWD_LOG_MAX) gu8SwdLogIndex = 0; \
}

#define SWD_LOG_THREAD(fmt, ...) { \
  snprintf(gpcSwdLog[gu8SwdLogIndex], SWD_LOG_LEN, fmt, __VA_ARGS__);  \
  xQueueSendFromISR(queSwdTaskHandle, &gu8SwdLogIndex, NULL);  \
  if (++gu8SwdLogIndex >= SWD_LOG_MAX) gu8SwdLogIndex = 0; \
}

#define SWD_LOG(fmt, ...) { \
  if ((SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0) { \
    SWD_LOG_ISR(fmt, __VA_ARGS__); \
  } else {  \
    SWD_LOG_THREAD(fmt, __VA_ARGS__);  \
  } \
}

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/

#endif /* FEATURE_SWD_H_ */
