/**
 * @file    feature_periodic.h
 * @brief   This file is used to periodic process, i.e., SysTick.
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef FEATURE_PERIODIC_H_
#define FEATURE_PERIODIC_H_

/* Includes ------------------------------------------------------------------*/
/* Exported defines ----------------------------------------------------------*/
#define PRD_SRV_HIGH  (unsigned short)1                   /* Service performed every minimum cycle */
#define PRD_SRV_MED   (unsigned short)(10*PRD_SRV_HIGH)   /* Service performed every GSL_SRV_PRD_HIGH*10 */
#define PRD_SRV_LOW   (unsigned short)(100*PRD_SRV_HIGH)  /* Service performed every GSL_SRV_PRD_HIGH*100 */

/* Exported types ------------------------------------------------------------*/
typedef void (*tpfPeriodicServiceInitialize)(void* pvArgs);
typedef void (*tpfPeriodicService)(void* pvArgs);

typedef enum {
  PRD_SRV_MIN = 0,
  PRD_SRV_BTN = PRD_SRV_MIN,
  PRD_SRV_LED,
  PRD_SRV_MAX,
} tenuAlmServiceType;

typedef struct {
  unsigned short                u16Period;
  tpfPeriodicServiceInitialize  pfInitialize;
  tpfPeriodicService            pfService;
} tstrPeriodicService;

/* Exported constants --------------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/
extern void vidPeriodicServiceInitialize(void);

#endif /* FEATURE_PERIODIC_H_ */
