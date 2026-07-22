/******************************************************************************
*
*   Copyright 2025-2026 NXP
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
* @file       GFLIB_RampTuning.h
*
* @brief      Header file for GFLIB_RampTuning function
*
******************************************************************************/
#ifndef GFLIB_RAMPTUNING_H
#define GFLIB_RAMPTUNING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "GFLIB_Ramp.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define GFLIB_RampTuning(...)     macro_dispatcher(GFLIB_RampTuning, __VA_ARGS__)(__VA_ARGS__)     /* The function calculates the up/down ramp with the step increment/decrement defined in the pParam structure. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GFLIB_RAMPTUNING_T                        GFLIB_RAMPTUNING_T_FLT                        /**< Definition of GFLIB_RAMPTUNING_T as alias for GFLIB_RAMPTUNING_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define GFLIB_RAMPTUNING_DEFAULT                  GFLIB_RAMPTUNING_DEFAULT_FLT                  /**< Definition of GFLIB_RAMPTUNING_DEFAULT as alias for GFLIB_RAMPTUNING_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DAMMCLIB00103 */
    #define GFLIB_RampTuning_Dsptchr_2(pCtrl,pParam)     GFLIB_RampTuning_Dsptchr_3(pCtrl,pParam,FLT)     /* Function dispatcher for GFLIB_RampTuning_Dsptchr_2, do not modify!!! */
  #endif

  #define GFLIB_RampTuning_Dsptchr_3(pCtrl,pParam,Impl)    GFLIB_RampTuning_Dsptchr_(pCtrl,pParam,Impl)     /* Function dispatcher for GFLIB_RampTuning_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DAMMCLIB00101 */
  #define GFLIB_RampTuning_Dsptchr_(pCtrl,pParam,Impl)     GFLIB_RampTuning_##Impl(pCtrl,pParam)            /* Function dispatcher for GFLIB_RampTuning_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GFLIB_RAMPTUNING_DEFAULT_FLT {(tU32)0, (tFloat)0, (tFloat)0, (tBool)FALSE}     /**< Default value for GFLIB_RAMPTUNING_T_FLT. */

  /*************************************************************************/
  /**
  @struct GFLIB_RAMPTUNING_T_FLT "\GFLIB_RampTuning.h" 

  @brief  Structure containing sampling frequency, ramp increment/decrement coefficients per second and limit flag for the ramp tuning function implemented in GFLIB_RampTuning.
  *//***********************************************************************/
  /* @remarks Implements DAMMCLIB00100, DAMMCLIB00099 */
  typedef struct{
    tU32   u32Fs; /**< Ramp sampling frequency [Hz]. Should not be negative or equal to 0. */
    tFloat fltRampUpCoefPSec; /**< Ramp up increment coefficient per second. */
    tFloat fltRampDownCoefPSec; /**< Ramp down decrement coefficient per second. */
    tBool  bLimitFlag; /**< Ramp tuning limitation flag. */
  }GFLIB_RAMPTUNING_T_FLT;
  

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GFLIB_RampTuning_FLT(GFLIB_RAMP_T_FLT *const pCtrl, GFLIB_RAMPTUNING_T_FLT *pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_RAMPTUNING_H */
