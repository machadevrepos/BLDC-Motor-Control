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
* @file       GFLIB_Limit.h
*
* @brief      Header file for GFLIB_Limit function
*
******************************************************************************/
#ifndef GFLIB_LIMIT_H
#define GFLIB_LIMIT_H

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
  #define GFLIB_Limit(...)     macro_dispatcher(GFLIB_Limit, __VA_ARGS__)(__VA_ARGS__)     /* This function tests whether the input value is within the upper and lower limits. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define GFLIB_LIMIT_T                        GFLIB_LIMIT_T_F32                        /**< Definition of GFLIB_LIMIT_T as alias for GFLIB_LIMIT_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    #define GFLIB_LIMIT_DEFAULT                  GFLIB_LIMIT_DEFAULT_F32                  /**< Definition of GFLIB_LIMIT_DEFAULT as alias for GFLIB_LIMIT_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    /* @remarks Implements DGFLIB00208 */
    #define GFLIB_Limit_Dsptchr_2(In,pParam)     GFLIB_Limit_Dsptchr_3(In,pParam,F32)     /* Function dispatcher for GFLIB_Limit_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define GFLIB_LIMIT_T                        GFLIB_LIMIT_T_F16                        /**< Definition of GFLIB_LIMIT_T as alias for GFLIB_LIMIT_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    #define GFLIB_LIMIT_DEFAULT                  GFLIB_LIMIT_DEFAULT_F16                  /**< Definition of GFLIB_LIMIT_DEFAULT as alias for GFLIB_LIMIT_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    /* @remarks Implements DGFLIB00208 */
    #define GFLIB_Limit_Dsptchr_2(In,pParam)     GFLIB_Limit_Dsptchr_3(In,pParam,F16)     /* Function dispatcher for GFLIB_Limit_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GFLIB_LIMIT_T                        GFLIB_LIMIT_T_FLT                        /**< Definition of GFLIB_LIMIT_T as alias for GFLIB_LIMIT_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define GFLIB_LIMIT_DEFAULT                  GFLIB_LIMIT_DEFAULT_FLT                  /**< Definition of GFLIB_LIMIT_DEFAULT as alias for GFLIB_LIMIT_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DGFLIB00208 */
    #define GFLIB_Limit_Dsptchr_2(In,pParam)     GFLIB_Limit_Dsptchr_3(In,pParam,FLT)     /* Function dispatcher for GFLIB_Limit_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */

  #define GFLIB_Limit_Dsptchr_3(In,pParam,Impl)    GFLIB_Limit_Dsptchr_(In,pParam,Impl)     /* Function dispatcher for GFLIB_Limit_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DGFLIB00213*/
  #define GFLIB_Limit_Dsptchr_(In,pParam,Impl)     GFLIB_Limit_##Impl(In,pParam)            /* Function dispatcher for GFLIB_Limit_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define GFLIB_LIMIT_DEFAULT_F32 {SWLIBS_INT32_MIN,SWLIBS_INT32_MAX}     /**< Default value for GFLIB_LIMIT_T_F32. */

  /*************************************************************************/
  /**
  @struct GFLIB_LIMIT_T_F32 "\GFLIB_Limit.h" 

  @brief  Structure containing the limits.
  *//***********************************************************************/
  /* @remarks Implements DGFLIB00214, DGFLIB00211 */
  typedef struct{
    tFrac32 f32LowerLimit; /**< Value determining the lower limit threshold. */
    tFrac32 f32UpperLimit; /**< Value determining the upper limit threshold. */
  }GFLIB_LIMIT_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac32 GFLIB_Limit_F32(tFrac32 f32In, const GFLIB_LIMIT_T_F32 *const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  #define GFLIB_LIMIT_DEFAULT_F16 {SWLIBS_INT16_MIN,SWLIBS_INT16_MAX}     /**< Default value for GFLIB_LIMIT_T_F16. */

  /*************************************************************************/
  /**
  @struct GFLIB_LIMIT_T_F16 "\GFLIB_Limit.h" 

  @brief  Structure containing the limits.
  *//***********************************************************************/
  /* @remarks Implements DGFLIB00214, DGFLIB00210 */
  typedef struct{
    tFrac16 f16LowerLimit; /**< Value determining the lower limit threshold. */
    tFrac16 f16UpperLimit; /**< Value determining the upper limit threshold. */
  }GFLIB_LIMIT_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac16 GFLIB_Limit_F16(tFrac16 f16In, const GFLIB_LIMIT_T_F16 *const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GFLIB_LIMIT_DEFAULT_FLT {FLOAT_MIN,FLOAT_MAX}     /**< Default value for GFLIB_LIMIT_T_FLT. */

  /*************************************************************************/
  /**
  @struct GFLIB_LIMIT_T_FLT "\GFLIB_Limit.h" 

  @brief  Structure containing the limits.
  *//***********************************************************************/
  /* @remarks Implements DGFLIB00214, DGFLIB00209 */
  typedef struct{
    tFloat fltLowerLimit; /**< Value determining the lower limit threshold. */
    tFloat fltUpperLimit; /**< Value determining the upper limit threshold. */
  }GFLIB_LIMIT_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFloat GFLIB_Limit_FLT(tFloat fltIn, const GFLIB_LIMIT_T_FLT *const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_LIMIT_H */
