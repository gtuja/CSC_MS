/**
 * @file    feature.h
 * @brief   This file is used to ... 
 * @author  Gtuja
 * @date    Oct 5, 2024
 * @note    Copyleft, All rights reversed.
 */

#ifndef FEATURE_H_
#define FEATURE_H_

/* Includes ------------------------------------------------------------------*/
/* Exported defines ----------------------------------------------------------*/
#define XBM_MATCH_CNT     5     /**< match count to confirm push or release. */
#define XBM_EVT_TH        1000  /**< threshold time(milliseconds) to determine short or long press. */

#define XLM_FADE_IN_TMO   1000  /**< fade in time(milliseconds). */
#define XLM_FADE_OUT_TMO  2000  /**< fade out time(milliseconds). */

#define XLM_DUTY_MIN      0     /**< minimum LED duty. */
#define XLM_DUTY_MAX      65535 /**< TBD : maximum LED duty. */

#define SWD_LOG_MAX       72

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/

#endif /* FEATURE_H_ */

