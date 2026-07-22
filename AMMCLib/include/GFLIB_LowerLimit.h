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
* @file       GFLIB_LowerLimit.h
*
* @brief      Header file for GFLIB_LowerLimit function
*
******************************************************************************/
#ifndef GFLIB_LOWERLIMIT_H
#define GFLIB_LOWERLIMIT_H

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
  #define GFLIB_LowerLimit(...)     macro_dispatcher(GFLIB_LowerLimit, __VA_ARGS__)(__VA_ARGS__)     /* This function tests whether the input value is above the lower limit. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define GFLIB_LOWERLIMIT_T                        GFLIB_LOWERLIMIT_T_F32                        /**< Definition of GFLIB_LOWERLIMIT_T as alias for GFLIB_LOWERLIMIT_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    #define GFLIB_LOWERLIMIT_DEFAULT                  GFLIB_LOWERLIMIT_DEFAULT_F32                  /**< Definition of GFLIB_LOWERLIMIT_DEFAULT as alias for GFLIB_LOWERLIMIT_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    /* @remarks Implements DGFLIB00223 */
    #define GFLIB_LowerLimit_Dsptchr_2(In,pParam)     GFLIB_LowerLimit_Dsptchr_3(In,pParam,F32)     /* Function dispatcher for GFLIB_LowerLimit_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define GFLIB_LOWERLIMIT_T                        GFLIB_LOWERLIMIT_T_F16                        /**< Definition of GFLIB_LOWERLIMIT_T as alias for GFLIB_LOWERLIMIT_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    #define GFLIB_LOWERLIMIT_DEFAULT                  GFLIB_LOWERLIMIT_DEFAULT_F16                  /**< Definition of GFLIB_LOWERLIMIT_DEFAULT as alias for GFLIB_LOWERLIMIT_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    /* @remarks Implements DGFLIB00223 */
    #define GFLIB_LowerLimit_Dsptchr_2(In,pParam)     GFLIB_LowerLimit_Dsptchr_3(In,pParam,F16)     /* Function dispatcher for GFLIB_LowerLimit_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GFLIB_LOWERLIMIT_T                        GFLIB_LOWERLIMIT_T_FLT                        /**< Definition of GFLIB_LOWERLIMIT_T as alias for GFLIB_LOWERLIMIT_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define GFLIB_LOWERLIMIT_DEFAULT                  GFLIB_LOWERLIMIT_DEFAULT_FLT                  /**< Definition of GFLIB_LOWERLIMIT_DEFAULT as alias for GFLIB_LOWERLIMIT_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DGFLIB00223 */
    #define GFLIB_LowerLimit_Dsptchr_2(In,pParam)     GFLIB_LowerLimit_Dsptchr_3(In,pParam,FLT)     /* Function dispatcher for GFLIB_LowerLimit_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */

  #define GFLIB_LowerLimit_Dsptchr_3(In,pParam,Impl)    GFLIB_LowerLimit_Dsptchr_(In,pParam,Impl)   /* Function dispatcher for GFLIB_LowerLimit_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DGFLIB00225 */
  #define GFLIB_LowerLimit_Dsptchr_(In,pParam,Impl)     GFLIB_LowerLimit_##Impl(In,pParam)          /* Function dispatcher for GFLIB_LowerLimit_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define GFLIB_LOWERLIMIT_DEFAULT_F32 {SWLIBS_INT32_MIN}     /**< Default value for GFLIB_LOWERLIMIT_T_F32. */

  /*************************************************************************/
  /**
  @struct GFLIB_LOWERLIMIT_T_F32 "\GFLIB_LowerLimit.h" 

  @brief  Structure containing the lower limit.
  *//***********************************************************************/
  /* @remarks Implements DGFLIB00320 */
  typedef struct{    
    tFrac32 f32LowerLimit; /**< Value determining the lower limit threshold. */
  }GFLIB_LOWERLIMIT_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac32 GFLIB_LowerLimit_F32(tFrac32 f32In, const GFLIB_LOWERLIMIT_T_F32 *const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  #define GFLIB_LOWERLIMIT_DEFAULT_F16 {SWLIBS_INT16_MIN}     /**< Default value for GFLIB_LOWERLIMIT_T_F16. */

  /*************************************************************************/
  /**
  @struct GFLIB_LOWERLIMIT_T_F16 "\GFLIB_LowerLimit.h" 

  @brief  Structure containing the lower limit.
  *//***********************************************************************/
  /* @remarks Implements DGFLIB00319 */
  typedef struct{    
    tFrac16 f16LowerLimit; /**< Value determining the lower limit threshold. */
  }GFLIB_LOWERLIMIT_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac16 GFLIB_LowerLimit_F16(tFrac16 f16In, const GFLIB_LOWERLIMIT_T_F16 *const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GFLIB_LOWERLIMIT_DEFAULT_FLT {FLOAT_MIN}     /**< Default value for GFLIB_LOWERLIMIT_T_FLT. */

  /*************************************************************************/
  /**
  @struct GFLIB_LOWERLIMIT_T_FLT "\GFLIB_LowerLimit.h" 

  @brief  Structure containing the lower limit.
  *//***********************************************************************/
  /* @remarks Implements DGFLIB00318 */
  typedef struct{    
    tFloat fltLowerLimit; /**< Value determining the lower limit threshold. */ 
  }GFLIB_LOWERLIMIT_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFloat GFLIB_LowerLimit_FLT(tFloat fltIn, const GFLIB_LOWERLIMIT_T_FLT *const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_LOWERLIMIT_H */
