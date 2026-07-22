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
* @file       GDFLIB_FilterMATuning.h
*
* @brief      Header file for GDFLIB_FilterMATuning function
*
******************************************************************************/
#ifndef GDFLIB_FILTERMATUNING_H
#define GDFLIB_FILTERMATUNING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "GDFLIB_FilterMA.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define GDFLIB_FilterMATuning(...)     macro_dispatcher(GDFLIB_FilterMATuning, __VA_ARGS__)(__VA_ARGS__)     /* The function calculates the smoothing factor Lambda based on cutoff frequency f0 defined in the pParam structure. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GDFLIB_FILTER_MA_TUNING_T                        GDFLIB_FILTER_MA_TUNING_T_FLT                        /**< Definition of GDFLIB_FILTER_MA_TUNING_T as alias for GDFLIB_FILTER_MA_TUNING_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define GDFLIB_FILTER_MA_TUNING_DEFAULT                  GDFLIB_FILTER_MA_TUNING_DEFAULT_FLT                  /**< Definition of GDFLIB_FILTER_MA_TUNING_DEFAULT as alias for GDFLIB_FILTER_MA_TUNING_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DAMMCLIB00109 */
    #define GDFLIB_FilterMATuning_Dsptchr_2(pCtrl,pParam)     GDFLIB_FilterMATuning_Dsptchr_3(pCtrl,pParam,FLT)     /* Function dispatcher for GDFLIB_FilterMATuning_Dsptchr_2, do not modify!!! */
  #endif

  #define GDFLIB_FilterMATuning_Dsptchr_3(pCtrl,pParam,Impl)    GDFLIB_FilterMATuning_Dsptchr_(pCtrl,pParam,Impl)     /* Function dispatcher for GDFLIB_FilterMATuning_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DAMMCLIB00107 */
  #define GDFLIB_FilterMATuning_Dsptchr_(pCtrl,pParam,Impl)     GDFLIB_FilterMATuning_##Impl(pCtrl,pParam)            /* Function dispatcher for GDFLIB_FilterMATuning_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GDFLIB_FILTER_MA_TUNING_DEFAULT_FLT {(tU32)0,(tFloat)0,(tBool)FALSE}     /**< Default value for GDFLIB_FILTER_MA_TUNING_T_FLT. */

  /*************************************************************************/
  /**
  @struct GDFLIB_FILTER_MA_TUNING_T_FLT "\GDFLIB_FilterMATuning.h" 

  @brief  Structure containing MA filter sampling frequency, cutoff frequency and limitation flag for the MA filter tuning function implemented in #GDFLIB_FilterMATuning_FLT.
  *//***********************************************************************/
  /* @remarks Implements DAMMCLIB00106, DAMMCLIB00105 */
  typedef struct{
    tU32   u32Fs; /**< MA filter sampling frequency [Hz]. Should not be negative or equal to 0. */
    tFloat fltF0; /**< MA filter cutoff frequency [Hz]. Should not be negative.*/
    tBool  bLimitFlag; /**< MA filter tuning limitation flag. */
  }GDFLIB_FILTER_MA_TUNING_T_FLT;
  

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GDFLIB_FilterMATuning_FLT(GDFLIB_FILTER_MA_T_FLT *const pCtrl, GDFLIB_FILTER_MA_TUNING_T_FLT *pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GDFLIB_FILTERMATUNING_H */
