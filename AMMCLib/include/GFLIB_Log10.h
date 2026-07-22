/******************************************************************************
*
*   Copyright 2013-2015 Freescale Semiconductor
*   Copyright 2016-2026 NXP
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
* @file       GFLIB_Log10.h
*
* @brief      Header file for GFLIB_Log10 function
*
******************************************************************************/
#ifndef GFLIB_LOG10_H
#define GFLIB_LOG10_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define GFLIB_Log10(...)     macro_dispatcher(GFLIB_Log10, __VA_ARGS__)(__VA_ARGS__)

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GFLIB_LOG10_T                        GFLIB_LOG10_T_FLT                           /**< Definition of GFLIB_LOG10_T as alias for GFLIB_LOG10_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define GFLIB_LOG10_DEFAULT                  GFLIB_LOG10_DEFAULT_FLT                     /**< Definition of GFLIB_LOG10_DEFAULT as alias for GFLIB_LOG10_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    #define GFLIB_Log10_Dsptchr_2(In,pParam)     GFLIB_Log10_Dsptchr_3(In,pParam,FLT)        /* Function dispatcher for GFLIB_Log10_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGFLIB00341 */
    #define GFLIB_Log10_Dsptchr_1(In)            GFLIB_Log10_Dsptchr_2(In,GFLIB_LOG10_DEFAULT) /* Function dispatcher for GFLIB_Log10_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
  
  #define GFLIB_Log10_Dsptchr_3(In,pParam,Impl)    GFLIB_Log10_Dsptchr_(In,pParam,Impl)     /* Function dispatcher for GFLIB_Log10_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DGFLIB00343 */
  #define GFLIB_Log10_Dsptchr_(In,pParam,Impl)     GFLIB_Log10_##Impl(In,pParam)            /* Function dispatcher for GFLIB_Log10_Dsptchr_, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GFLIB_LOG10_DEFAULT_FLT &fltgflibLog10Coef     /**< Default approximation coefficients for GFLIB_Log10_FLT function. */

  /************************************************************************/
  /**
  @struct GFLIB_LOG10_T_FLT "\GFLIB_Log10.h" 

  @brief  Array of single precision floating point elements for storing the coefficients of the
          floating point log10 approximation polynomial.
  *//**********************************************************************/
  typedef struct{
    tFloat  fltA[5];
  }GFLIB_LOG10_T_FLT;
  
  /************************************************************************/
  /**
  @brief  Default approximation coefficients for cosine approximation.
  *//**********************************************************************/
  extern const GFLIB_LOG10_T_FLT fltgflibLog10Coef;

  /****************************************************************************
  * Exported function prototypes
  ****************************************************************************/
  extern tFloat GFLIB_Log10_FLT(tFloat fltIn, const GFLIB_LOG10_T_FLT *const pParam);

#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_LOG10_H */
