/******************************************************************************
*
*   Copyright 2021-2023 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms.  By expressly accepting such
*   terms or by downloading, installing, activating and/or otherwise using the software, you are
*   agreeing that you have read, and that you agree to comply with and are bound by, such license
*   terms. If you do not agree to be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
******************************************************************************/
/**
*
* @file       GMCLIB_SpreadPWM.h
*
* @brief      Header file for GMCLIB_SpreadPWM function
*
******************************************************************************/
#ifndef GMCLIB_SPREADPWM_H
#define GMCLIB_SPREADPWM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/************************************************************************/
/**
@struct GMCLIB_SPREADPWM_T "\GMCLIB_SpreadPWM.h"

@brief  Structure containing parameters and states of GMCLIB_SpreadPWM.
*//**********************************************************************/
typedef struct{
  tU32 u32Rnd;       /**< Generated 32-bit random number. This value is updated in every iteration of GMCLIB_SpreadPWM. */
  tU16 u16ModMin;    /**< PWM counter minimum modulus (corresponds to the highest PWM frequency). This value is calculated in GMCLIB_SpreadPWMInit. Do not edit. */
  tU16 u16ModMax;    /**< PWM counter maximum modulus (corresponds to the lowest PWM frequency). This value is calculated in GMCLIB_SpreadPWMInit. Do not edit. */
  tU16 u16CntK1;     /**< PWM counter modulus in previous iteration. Do not edit. */
  tFrac16 f16Inc;    /**< Internal variable. Do not edit.  */
  tU16 u16DevConst;  /**< Internal variable. Do not edit.  */
}GMCLIB_SPREADPWM_T;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
extern void GMCLIB_SpreadPWMInit(tU32 u32PWMFreq, tU16 u16Mod, tU32 u32SpreadFreq, tU8 u8FreqDev, GMCLIB_SPREADPWM_T *const pParam);
extern tU16 GMCLIB_SpreadPWM(GMCLIB_SPREADPWM_T *const pParam);

#ifdef __cplusplus
}
#endif

#endif /* GMCLIB_SPREADPWM_H */
