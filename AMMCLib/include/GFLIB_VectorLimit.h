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
* @file       GFLIB_VectorLimit.h
*
* @brief      Header file for GFLIB_VectorLimit function
*
******************************************************************************/
#ifndef GFLIB_VECTORLIMIT_H
#define GFLIB_VECTORLIMIT_H

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
  #define GFLIB_VectorLimit(...)     macro_dispatcher(GFLIB_VectorLimit, __VA_ARGS__)(__VA_ARGS__)     /* This function limits the magnitude of the input vector. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define GFLIB_VECTORLIMIT_T                              GFLIB_VECTORLIMIT_T_F32                              /**< Definition of GFLIB_VECTORLIMIT_T as alias for GFLIB_VECTORLIMIT_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    #define GFLIB_VECTORLIMIT_DEFAULT                        GFLIB_VECTORLIMIT_DEFAULT_F32                        /**< Definition of GFLIB_VECTORLIMIT_DEFAULT as alias for GFLIB_VECTORLIMIT_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    /* @remarks Implements DGFLIB00248 */
    #define GFLIB_VectorLimit_Dsptchr_3(pOut,pIn,pParam)     GFLIB_VectorLimit_Dsptchr_4(pOut,pIn,pParam,F32)     /* Function dispatcher for GFLIB_VectorLimit_Dsptchr_3, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define GFLIB_VECTORLIMIT_T                              GFLIB_VECTORLIMIT_T_F16                              /**< Definition of GFLIB_VECTORLIMIT_T as alias for GFLIB_VECTORLIMIT_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    #define GFLIB_VECTORLIMIT_DEFAULT                        GFLIB_VECTORLIMIT_DEFAULT_F16                        /**< Definition of GFLIB_VECTORLIMIT_DEFAULT as alias for GFLIB_VECTORLIMIT_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    /* @remarks Implements DGFLIB00248 */
    #define GFLIB_VectorLimit_Dsptchr_3(pOut,pIn,pParam)     GFLIB_VectorLimit_Dsptchr_4(pOut,pIn,pParam,F16)     /* Function dispatcher for GFLIB_VectorLimit_Dsptchr_3, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GFLIB_VECTORLIMIT_T                              GFLIB_VECTORLIMIT_T_FLT                             /**< Definition of GFLIB_VECTORLIMIT_T as alias for GFLIB_VECTORLIMIT_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define GFLIB_VECTORLIMIT_DEFAULT                        GFLIB_VECTORLIMIT_DEFAULT_FLT                       /**< Definition of GFLIB_VECTORLIMIT_DEFAULT as alias for GFLIB_VECTORLIMIT_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DGFLIB00248 */
    #define GFLIB_VectorLimit_Dsptchr_3(pOut,pIn,pParam)     GFLIB_VectorLimit_Dsptchr_4(pOut,pIn,pParam,FLT)    /* Function dispatcher for GFLIB_VectorLimit_Dsptchr_3, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */

  #define GFLIB_VectorLimit_Dsptchr_4(pOut,pIn,pParam,Impl)  GFLIB_VectorLimit_Dsptchr_(pOut,pIn,pParam,Impl)    /* Function dispatcher for GFLIB_VectorLimit_Dsptchr_4, do not modify!!! */
  
  /* @remarks Implements DGFLIB00250 */
  #define GFLIB_VectorLimit_Dsptchr_(pOut,pIn,pParam,Impl)   GFLIB_VectorLimit_##Impl(pOut,pIn,pParam)           /* Function dispatcher for GFLIB_VectorLimit_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define GFLIB_VECTORLIMIT_DEFAULT_F32 {(tFrac32)0}     /**< Default value for GFLIB_VECTORLIMIT_T_F32. */

  /*************************************************************************/
  /**
  @struct GFLIB_VECTORLIMIT_T_F32 "\GFLIB_VectorLimit.h" 

  @brief  Structure containing the limit.
  *//***********************************************************************/
  /* @remarks Implements DGFLIB00325 */
  typedef struct{    
    tFrac32 f32Limit; /**< The maximum magnitude of the input vector. The defined magnitude must be positive and equal to or greater than F32_MAX value. */ 
  }GFLIB_VECTORLIMIT_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tBool GFLIB_VectorLimit_F32(SWLIBS_2Syst_F32 *const pOut, const SWLIBS_2Syst_F32 *const pIn, const GFLIB_VECTORLIMIT_T_F32 *const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  #define GFLIB_VECTORLIMIT_DEFAULT_F16 {(tFrac16)0}     /**< Default value for GFLIBVECTORLIMIT_T_F16. */

  /*************************************************************************/
  /**
  @struct GFLIB_VECTORLIMIT_T_F16 "\GFLIB_VectorLimit.h" 

  @brief  Structure containing the limit.
  *//***********************************************************************/
  /* @remarks Implements DGFLIB00324 */
  typedef struct{    
    tFrac16 f16Limit; /**< The maximum magnitude of the input vector. The defined magnitude must be positive and equal to or greater than F16_MAX value. */ 
  }GFLIB_VECTORLIMIT_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tBool GFLIB_VectorLimit_F16(SWLIBS_2Syst_F16 *const pOut, const SWLIBS_2Syst_F16 *const pIn, const GFLIB_VECTORLIMIT_T_F16 *const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GFLIB_VECTORLIMIT_DEFAULT_FLT {(tFloat)0}     /**< Default value for GFLIB_VECTORLIMIT_T_FLT. */

  /*************************************************************************/
  /**
  @struct GFLIB_VECTORLIMIT_T_FLT "\GFLIB_VectorLimit.h" 

  @brief  Structure containing the limit.
  *//***********************************************************************/
  /* @remarks Implements DGFLIB00323 */
  typedef struct{
    tFloat fltLimit; /**< The maximum magnitude of the input vector. The defined magnitude must be positive and equal to or greater than FLT_MAX value. */
  }GFLIB_VECTORLIMIT_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tBool GFLIB_VectorLimit_FLT(SWLIBS_2Syst_FLT *const pOut, const SWLIBS_2Syst_FLT *const pIn, const GFLIB_VECTORLIMIT_T_FLT *const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_VECTORLIMIT_H */
