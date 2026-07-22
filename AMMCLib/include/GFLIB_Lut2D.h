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
* @file       GFLIB_Lut2D.h
*
* @brief      Header file for GFLIB_Lut2D function
*
******************************************************************************/
#ifndef GFLIB_LUT2D_H
#define GFLIB_LUT2D_H

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
  #define GFLIB_Lut2D(...)     macro_dispatcher(GFLIB_Lut2D, __VA_ARGS__)(__VA_ARGS__)     /* This function implements the two-dimensional look-up table. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define GFLIB_LUT2D_T                             GFLIB_LUT2D_T_F32                             /**< Definition of GFLIB_LUT2D_T as alias for GFLIB_LUT2D_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    #define GFLIB_LUT2D_DEFAULT                       GFLIB_LUT2D_DEFAULT_F32                       /**< Definition of GFLIB_LUT2D_DEFAULT as alias for GFLIB_LUT2D_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    /* @remarks Implements DGFLIB00156 */
    #define GFLIB_Lut2D_Dsptchr_3(In1,In2,pParam)     GFLIB_Lut2D_Dsptchr_4(In1,In2,pParam,F32)     /* Function dispatcher for GFLIB_Lut2D_Dsptchr_3, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define GFLIB_LUT2D_T                             GFLIB_LUT2D_T_F16                             /**< Definition of GFLIB_LUT2D_T as alias for GFLIB_LUT2D_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    #define GFLIB_LUT2D_DEFAULT                       GFLIB_LUT2D_DEFAULT_F16                       /**< Definition of GFLIB_LUT2D_DEFAULT as alias for GFLIB_LUT2D_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    /* @remarks Implements DGFLIB00156 */
    #define GFLIB_Lut2D_Dsptchr_3(In1,In2,pParam)     GFLIB_Lut2D_Dsptchr_4(In1,In2,pParam,F16)     /* Function dispatcher for GFLIB_Lut2D_Dsptchr_3, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GFLIB_LUT2D_T                             GFLIB_LUT2D_T_FLT                             /**< Definition of GFLIB_LUT2D_T as alias for GFLIB_LUT2D_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define GFLIB_LUT2D_DEFAULT                       GFLIB_LUT2D_DEFAULT_FLT                       /**< Definition of GFLIB_LUT2D_DEFAULT as alias for GFLIB_LUT2D_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DGFLIB00156 */
    #define GFLIB_Lut2D_Dsptchr_3(In1,In2,pParam)     GFLIB_Lut2D_Dsptchr_4(In1,In2,pParam,FLT)     /* Function dispatcher for GFLIB_Lut2D_Dsptchr_3, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */

  #define GFLIB_Lut2D_Dsptchr_4(In1,In2,pParam,Impl)    GFLIB_Lut2D_Dsptchr_(In1,In2,pParam,Impl)   /* Function dispatcher for GFLIB_Lut2D_Dsptchr_4, do not modify!!! */
  
  /* @remarks Implements DGFLIB00158 */
  #define GFLIB_Lut2D_Dsptchr_(In1,In2,pParam,Impl)     GFLIB_Lut2D_##Impl(In1,In2,pParam)          /* Function dispatcher for GFLIB_Lut2D_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define GFLIB_LUT2D_DEFAULT_F32 {(tU32)0,(tU32)0,(tFrac32*)0}     /**< Default value for GFLIB_LUT2D_T_F32. */

  /************************************************************************//**
  @struct GFLIB_LUT2D_T_F32 "\GFLIB_Lut2D.h" 

  @brief  Structure containing 2D look-up table parameters.
  *//*************************************************************************/
  /* @remarks Implements DGFLIB00163, DGFLIB00159 */
  typedef struct{
    tU32 u32ShamOffset1; /**< u32ShamOffset1 = log2(N - 1), where N is number of columns in the table, e.g. {N = 3, u32ShamOffset1 = 1}, {N = 5, u32ShamOffset1 = 2}, {N = 9, u32ShamOffset1 = 3}, {N = 17, u32ShamOffset1 = 4}, etc. */
    tU32 u32ShamOffset2; /**< u32ShamOffset2 = log2(M - 1), where M is number of rows in the table, e.g. {M = 3, u32ShamOffset2 = 1}, {M = 5, u32ShamOffset2 = 2}, {M = 9, u32ShamOffset2 = 3}, {M = 17, u32ShamOffset2 = 4}, etc. */
    const tFrac32 *pf32Table; /**< Pointer to a look-up table holding 32-bit fractional values arranged in a uniform grid. The table is stored in column-major format. */
  }GFLIB_LUT2D_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac32 GFLIB_Lut2D_F32(tFrac32 f32In1,tFrac32 f32In2, const GFLIB_LUT2D_T_F32 *const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  #define GFLIB_LUT2D_DEFAULT_F16 {(tU16)0,(tU16)0,(tFrac16*)0}     /**< Default value for GFLIB_LUT2D_T_F16. */

  /************************************************************************//**
  @struct GFLIB_LUT2D_T_F16 "\GFLIB_Lut2D.h" 

  @brief  Structure containing 2D look-up table parameters.
  *//*************************************************************************/
  /* @remarks Implements DGFLIB00163, DGFLIB00160 */
  typedef struct{
    tU16 u16ShamOffset1; /**< u16ShamOffset1 = log2(N - 1), where N is number of columns in the table, e.g. {N = 3, u16ShamOffset1 = 1}, {N = 5, u16ShamOffset1 = 2}, {N = 9, u16ShamOffset1 = 3}, {N = 17, u16ShamOffset1 = 4}, etc. */
    tU16 u16ShamOffset2; /**< u16ShamOffset2 = log2(M - 1), where M is number of rows in the table, e.g. {M = 3, u16ShamOffset2 = 1}, {M = 5, u16ShamOffset2 = 2}, {M = 9, u16ShamOffset2 = 3}, {M = 17, u16ShamOffset2 = 4}, etc. */
    const tFrac16 *pf16Table; /**< Pointer to a look-up table holding 16-bit fractional values arranged in a uniform grid. The table is stored in column-major format. */
  }GFLIB_LUT2D_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac16 GFLIB_Lut2D_F16(tFrac16 f16In1,tFrac16 f16In2, const GFLIB_LUT2D_T_F16 *const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GFLIB_LUT2D_DEFAULT_FLT {(tU32)0,(tU32)0,(tFloat*)0}     /**< Default value for GFLIB_LUT2D_T_FLT. */

  /************************************************************************//**
  @struct GFLIB_LUT2D_T_FLT "\GFLIB_Lut2D.h" 

  @brief  Structure containing 2D look-up table parameters.
  *//*************************************************************************/
  /* @remarks Implements DGFLIB00163, DGFLIB00161 */
  typedef struct{
    tU32 u32ShamOffset1; /**< u32ShamOffset1 = log2(N - 1), where N is number of columns in the table, e.g. {N = 3, u32ShamOffset1 = 1}, {N = 5, u32ShamOffset1 = 2}, {N = 9, u32ShamOffset1 = 3}, {N = 17, u32ShamOffset1 = 4}, etc. */
    tU32 u32ShamOffset2; /**< u32ShamOffset2 = log2(M - 1), where M is number of rows in the table, e.g. {M = 3, u32ShamOffset2 = 1}, {M = 5, u32ShamOffset2 = 2}, {M = 9, u32ShamOffset2 = 3}, {M = 17, u32ShamOffset2 = 4}, etc. */
    const tFloat *pfltTable; /**< Pointer to a look-up table holding single precision floating-point values arranged in a uniform grid. The table is stored in column-major format. */
  }GFLIB_LUT2D_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFloat GFLIB_Lut2D_FLT(tFloat fltIn1,tFloat fltIn2, const GFLIB_LUT2D_T_FLT *const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_LUT2D_H */
