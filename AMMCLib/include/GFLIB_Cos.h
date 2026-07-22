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
* @file       GFLIB_Cos.h
*
* @brief      Header file for GFLIB_Cos function
*
******************************************************************************/
#ifndef GFLIB_COS_H
#define GFLIB_COS_H

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
  #define GFLIB_Cos(...)     macro_dispatcher(GFLIB_Cos, __VA_ARGS__)(__VA_ARGS__)     /* This function implements polynomial approximation of cosine function. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define GFLIB_COS_T                        GFLIB_COS_T_F32                           /**< Definition of GFLIB_COS_T as alias for GFLIB_COS_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    #define GFLIB_COS_DEFAULT                  GFLIB_COS_DEFAULT_F32                     /**< Definition of GFLIB_COS_DEFAULT as alias for GFLIB_COS_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    #define GFLIB_Cos_Dsptchr_2(In,pParam)     GFLIB_Cos_Dsptchr_3(In,pParam,F32)        /* Function dispatcher for GFLIB_Cos_Dsptchr_2, do not modify!!! */    
    /* @remarks Implements DGFLIB00022 */
    #define GFLIB_Cos_Dsptchr_1(In)            GFLIB_Cos_Dsptchr_2(In,GFLIB_COS_DEFAULT) /* Function dispatcher for GFLIB_Cos_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define GFLIB_COS_T                        GFLIB_COS_T_F16                           /**< Definition of GFLIB_COS_T as alias for GFLIB_COS_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    #define GFLIB_COS_DEFAULT                  GFLIB_COS_DEFAULT_F16                     /**< Definition of GFLIB_COS_DEFAULT as alias for GFLIB_COS_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    #define GFLIB_Cos_Dsptchr_2(In,pParam)     GFLIB_Cos_Dsptchr_3(In,pParam,F16)        /* Function dispatcher for GFLIB_Cos_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGFLIB00022 */
    #define GFLIB_Cos_Dsptchr_1(In)            GFLIB_Cos_Dsptchr_2(In,GFLIB_COS_DEFAULT) /* Function dispatcher for GFLIB_Cos_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GFLIB_COS_T                        GFLIB_COS_T_FLT                           /**< Definition of GFLIB_COS_T as alias for GFLIB_COS_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define GFLIB_COS_DEFAULT                  GFLIB_COS_DEFAULT_FLT                     /**< Definition of GFLIB_COS_DEFAULT as alias for GFLIB_COS_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    #define GFLIB_Cos_Dsptchr_2(In,pParam)     GFLIB_Cos_Dsptchr_3(In,pParam,FLT)        /* Function dispatcher for GFLIB_Cos_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGFLIB00022 */
    #define GFLIB_Cos_Dsptchr_1(In)            GFLIB_Cos_Dsptchr_2(In,GFLIB_COS_DEFAULT) /* Function dispatcher for GFLIB_Cos_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */

  #define GFLIB_Cos_Dsptchr_3(In,pParam,Impl)    GFLIB_Cos_Dsptchr_(In,pParam,Impl)     /* Function dispatcher for GFLIB_Cos_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DGFLIB00024 */
  #define GFLIB_Cos_Dsptchr_(In,pParam,Impl)     GFLIB_Cos_##Impl(In,pParam)            /* Function dispatcher for GFLIB_Cos_Dsptchr_, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define GFLIB_COS_DEFAULT_F32 &f32gflibCosCoef     /**< Default approximation coefficients for GFLIB_Cos_F32 function. */

  /************************************************************************/
  /**
  @struct GFLIB_COS_T_F32 "\GFLIB_Cos.h" 

  @brief  Array of five 32-bit elements for storing coefficients of the Taylor polynomial.
  *//**********************************************************************/
  typedef struct{
    tFrac32  f32A[5];
  }GFLIB_COS_T_F32;

  /************************************************************************/
  /**
  @brief  Default approximation coefficients for cosine approximation.
  *//**********************************************************************/
  extern const GFLIB_COS_T_F32 f32gflibCosCoef;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac32 GFLIB_Cos_F32(tFrac32 f32In, const GFLIB_COS_T_F32 *const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  #define GFLIB_COS_DEFAULT_F16 &f16gflibCosCoef     /**< Default approximation coefficients for GFLIB_Cos_F32 function. */

  /************************************************************************/
  /**
  @struct GFLIB_COS_T_F16 "\GFLIB_Cos.h" 

  @brief  Array of four 16-bit elements for storing coefficients of the Taylor polynomial.
  *//**********************************************************************/
  typedef struct{
    tFrac16  f16A[4];
  }GFLIB_COS_T_F16;

  /************************************************************************/
  /**
  @brief  Default approximation coefficients for cosine approximation.
  *//**********************************************************************/
  extern const GFLIB_COS_T_F16 f16gflibCosCoef;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac16 GFLIB_Cos_F16(tFrac16 f16In, const GFLIB_COS_T_F16 *const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GFLIB_COS_DEFAULT_FLT &fltgflibCosCoef     /**< Default approximation coefficients for GFLIB_Cos_FLT function. */

  /************************************************************************/
  /**
  @struct GFLIB_COS_T_FLT "\GFLIB_Cos.h" 

  @brief  Array of three single precision floating point elements for storing coefficients of the floating point
          optimized minimax approximation polynomial.
  *//**********************************************************************/
  typedef struct{
    tFloat  fltA[3];
  }GFLIB_COS_T_FLT;
  
  /************************************************************************/
  /**
  @brief  Default approximation coefficients for cosine approximation.
  *//**********************************************************************/
  extern const GFLIB_COS_T_FLT fltgflibCosCoef;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFloat GFLIB_Cos_FLT(tFloat fltIn, const GFLIB_COS_T_FLT *const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_COS_H */
