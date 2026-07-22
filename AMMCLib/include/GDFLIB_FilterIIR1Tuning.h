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
* @file       GDFLIB_FilterIIR1Tuning.h
*
* @brief      Header file for GDFLIB_FilterIIR1Tuning function
*
******************************************************************************/
#ifndef GDFLIB_FILTERIIR1TUNING_H
#define GDFLIB_FILTERIIR1TUNING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "GDFLIB_FilterIIR1.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define GDFLIB_FilterIIR1Tuning(...)     macro_dispatcher(GDFLIB_FilterIIR1Tuning, __VA_ARGS__)(__VA_ARGS__)     /* The function calculates the IIR1 filter coefficients B0, B1, A1 based on cutoff frequency f0 defined in the pParam structure. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GDFLIB_FILTER_IIR1_TUNING_T                        GDFLIB_FILTER_IIR1_TUNING_T_FLT                        /**< Definition of GDFLIB_FILTER_IIR1_TUNING_T as alias for GDFLIB_FILTER_IIR1_TUNING_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define GDFLIB_FILTER_IIR1_TUNING_DEFAULT                  GDFLIB_FILTER_IIR1_TUNING_DEFAULT_FLT                  /**< Definition of GDFLIB_FILTER_IIR1_TUNING_DEFAULT as alias for GDFLIB_FILTER_IIR1_TUNING_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DAMMCLIB00115 */
    #define GDFLIB_FilterIIR1Tuning_Dsptchr_2(pCtrl,pParam)     GDFLIB_FilterIIR1Tuning_Dsptchr_3(pCtrl,pParam,FLT)     /* Function dispatcher for GDFLIB_FilterIIR1Tuning_Dsptchr_2, do not modify!!! */
  #endif

  #define GDFLIB_FilterIIR1Tuning_Dsptchr_3(pCtrl,pParam,Impl)    GDFLIB_FilterIIR1Tuning_Dsptchr_(pCtrl,pParam,Impl)     /* Function dispatcher for GDFLIB_FilterIIR1Tuning_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DAMMCLIB00113 */
  #define GDFLIB_FilterIIR1Tuning_Dsptchr_(pCtrl,pParam,Impl)     GDFLIB_FilterIIR1Tuning_##Impl(pCtrl,pParam)            /* Function dispatcher for GDFLIB_FilterIIR1Tuning_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/************************************************************************//**
@enum   GDFLIB_FILTER_IIR1_TUNING_FILTYPE_T

@brief  Enum type of IIR1 filter type configuration for the GDFLIB_FilterIIR1Tuning.
*//*************************************************************************/
  typedef enum
  {
    LPF = 0,  /**< IIR1 configured as low-pass filter (default). */
    HPF = 1,  /**< IIR1 configured as high-pass filter. */
  } GDFLIB_FILTER_IIR1_TUNING_FILTYPE_T;

/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GDFLIB_FILTER_IIR1_TUNING_DEFAULT_FLT {(GDFLIB_FILTER_IIR1_TUNING_FILTYPE_T)0, (tU32)0, (tFloat)0}     /**< Default value for GDFLIB_FILTER_IIR1_TUNING_T_FLT. */

  /*************************************************************************/
  /**
  @struct GDFLIB_FILTER_IIR1_TUNING_T_FLT "\GDFLIB_FilterIIR1Tuning.h" 

  @brief  Structure containing IIR1 filter type configuration, sampling frequency, cutoff frequency and limit flag for the IIR1 filter tuning function implemented in #GDFLIB_FilterIIR1Tuning_FLT.
  *//***********************************************************************/
  /* @remarks Implements DAMMCLIB00112, DAMMCLIB00111 */
  typedef struct{
    GDFLIB_FILTER_IIR1_TUNING_FILTYPE_T pIIR1FiltType; /**< IIR1 filter type configuration (LPF(0) or HPF(1)). */
    tU32   u32Fs; /**< IIR1 filter sampling frequency [Hz]. Should not be negative or equal to 0. */
    tFloat fltF0; /**< IIR1 filter cutoff frequency [Hz]. Should not be negative. */
  }GDFLIB_FILTER_IIR1_TUNING_T_FLT;
  

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GDFLIB_FilterIIR1Tuning_FLT(GDFLIB_FILTER_IIR1_T_FLT *const pCtrl, const GDFLIB_FILTER_IIR1_TUNING_T_FLT *const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GDFLIB_FILTERIIR1TUNING_H */
