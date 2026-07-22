/******************************************************************************
*
*   Copyright 2020-2026 NXP
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
* @file       GMCLIB_SvmStd6Ph.h
*
* @brief      Header file for GMCLIB_SvmStd6Ph function
*
******************************************************************************/
#ifndef GMCLIB_SVMSTD6PH_H
#define GMCLIB_SVMSTD6PH_H

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
  #define GMCLIB_SvmStd6PhInit(...)     macro_dispatcher(GMCLIB_SvmStd6PhInit, __VA_ARGS__)(__VA_ARGS__)     /* This function calculates the duty-cycle ratios using the Standard Space Vector Modulation technique. */
  #define GMCLIB_SvmStd6Ph(...)     macro_dispatcher(GMCLIB_SvmStd6Ph, __VA_ARGS__)(__VA_ARGS__)     /* This function calculates the duty-cycle ratios using the Standard Space Vector Modulation technique. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define GMCLIB_SVMSTD_6PH_T                             GMCLIB_SVMSTD_6PH_T_F32
    /* @remarks Implements DGMCLIB00166 */
    #define GMCLIB_SvmStd6PhInit_Dsptchr_2(pParam,In)       GMCLIB_SvmStd6PhInit_Dsptchr_3(pParam,In,F32)     /* Function dispatcher for GMCLIB_SvmStd6PhInit_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGMCLIB00159 */
    #define GMCLIB_SvmStd6Ph_Dsptchr_4(pOut1,pOut2,pIn,pParam)     GMCLIB_SvmStd6Ph_Dsptchr_5(pOut1,pOut2,pIn,pParam,F32)     /* Function dispatcher for GMCLIB_SvmStd6Ph_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define GMCLIB_SVMSTD_6PH_T                             GMCLIB_SVMSTD_6PH_T_F16
    /* @remarks Implements DGMCLIB00166 */
    #define GMCLIB_SvmStd6PhInit_Dsptchr_2(pParam,In)       GMCLIB_SvmStd6PhInit_Dsptchr_3(pParam,In,F16)     /* Function dispatcher for GMCLIB_SvmStd6PhInit_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGMCLIB00159 */
    #define GMCLIB_SvmStd6Ph_Dsptchr_4(pOut1,pOut2,pIn,pParam)     GMCLIB_SvmStd6Ph_Dsptchr_5(pOut1,pOut2,pIn,pParam,F16)     /* Function dispatcher for GMCLIB_SvmStd6Ph_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GMCLIB_SVMSTD_6PH_T                             GMCLIB_SVMSTD_6PH_T_FLT
    /* @remarks Implements DGMCLIB00166 */
    #define GMCLIB_SvmStd6PhInit_Dsptchr_2(pParam,In)       GMCLIB_SvmStd6PhInit_Dsptchr_3(pParam,In,FLT)     /* Function dispatcher for GMCLIB_SvmStd6PhInit_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGMCLIB00159 */
    #define GMCLIB_SvmStd6Ph_Dsptchr_4(pOut1,pOut2,pIn,pParam)     GMCLIB_SvmStd6Ph_Dsptchr_5(pOut1,pOut2,pIn,pParam,FLT)     /* Function dispatcher for GMCLIB_SvmStd6Ph_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */

  #define GMCLIB_SvmStd6PhInit_Dsptchr_3(pParam,pIn,Impl)    GMCLIB_SvmStd6PhInit_Dsptchr_(pParam,pIn,Impl)     /* Function dispatcher for GMCLIB_SvmStd6Ph_Dsptchr_4, do not modify!!! */
  
  /* @remarks Implements DGMCLIB00168 */
  #define GMCLIB_SvmStd6PhInit_Dsptchr_(pParam,pIn,Impl)     GMCLIB_SvmStd6PhInit_##Impl(pParam,pIn)            /* Function dispatcher for GMCLIB_SvmStd6Ph_Dsptchr_, do not modify!!! */
  
  #define GMCLIB_SvmStd6Ph_Dsptchr_5(pOut1,pOut2,pIn,pParam,Impl)    GMCLIB_SvmStd6Ph_Dsptchr_(pOut1,pOut2,pIn,pParam,Impl)     /* Function dispatcher for GMCLIB_SvmStd6Ph_Dsptchr_4, do not modify!!! */
  
  /* @remarks Implements DGMCLIB00161 */
  #define GMCLIB_SvmStd6Ph_Dsptchr_(pOut1,pOut2,pIn,pParam,Impl)     GMCLIB_SvmStd6Ph_##Impl(pOut1,pOut2,pIn,pParam)            /* Function dispatcher for GMCLIB_SvmStd6Ph_Dsptchr_, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
/************************************************************************/
/**
@struct GMCLIB_SVMSTD_6PH_T_F32 "\GMCLIB_SvmStd6Ph.h" 

@brief  Parameters structure for 6-phase SvmStd function containing transformation
        coefficients calculated by GMCLIB_SvmStd6PhInit function.
*//**********************************************************************/
  typedef struct
  {
    tFrac32 f32AlphaD;  /**< Transformation coefficient AlphaD */
    tFrac32 f32AlphaE;  /**< Transformation coefficient AlphaE */
    tFrac32 f32AlphaF;  /**< Transformation coefficient AlphaF */
    tFrac32 f32BetaD;   /**< Transformation coefficient BetaD */
    tFrac32 f32BetaE;   /**< Transformation coefficient BetaE */
    tFrac32 f32BetaF;   /**< Transformation coefficient BetaF */
  }GMCLIB_SVMSTD_6PH_T_F32;
  
/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GMCLIB_SvmStd6PhInit_F32(GMCLIB_SVMSTD_6PH_T_F32 *const pParam, tFrac32 f32WindingShift);
  extern void GMCLIB_SvmStd6Ph_F32(SWLIBS_6Syst_F32 *const pOutPwm, SWLIBS_2Syst_U32 *const pOutSector, const SWLIBS_2Syst_F32 *const pIn, const GMCLIB_SVMSTD_6PH_T_F32 *const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
/************************************************************************/
/**
@struct GMCLIB_SVMSTD_6PH_T_F16 "\GMCLIB_SvmStd6Ph.h" 

@brief  Parameters structure for 6-phase SvmStd function containing transformation
        coefficients calculated by GMCLIB_SvmStd6PhInit function.
*//**********************************************************************/
  typedef struct
  {
    tFrac16 f16AlphaD;  /**< Transformation coefficient AlphaD */
    tFrac16 f16AlphaE;  /**< Transformation coefficient AlphaE */
    tFrac16 f16AlphaF;  /**< Transformation coefficient AlphaF */
    tFrac16 f16BetaD;   /**< Transformation coefficient BetaD */
    tFrac16 f16BetaE;   /**< Transformation coefficient BetaE */
    tFrac16 f16BetaF;   /**< Transformation coefficient BetaF */
  }GMCLIB_SVMSTD_6PH_T_F16;
  
/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GMCLIB_SvmStd6PhInit_F16(GMCLIB_SVMSTD_6PH_T_F16 *const pParam, tFrac16 f16WindingShift);
  extern void GMCLIB_SvmStd6Ph_F16(SWLIBS_6Syst_F16 *const pOutPwm, SWLIBS_2Syst_U16 *const pOutSector, const SWLIBS_2Syst_F16 *const pIn, const GMCLIB_SVMSTD_6PH_T_F16 *const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/************************************************************************/
/**
@struct GMCLIB_SVMSTD_6PH_T_FLT "\GMCLIB_SvmStd6Ph.h" 

@brief  Parameters structure for 6-phase SvmStd function containing transformation
        coefficients calculated by GMCLIB_SvmStd6PhInit function.
*//**********************************************************************/
  typedef struct
  {
    tFloat fltAlphaD;  /**< Transformation coefficient AlphaD */
    tFloat fltAlphaE;  /**< Transformation coefficient AlphaE */
    tFloat fltAlphaF;  /**< Transformation coefficient AlphaF */
    tFloat fltBetaD;   /**< Transformation coefficient BetaD */
    tFloat fltBetaE;   /**< Transformation coefficient BetaE */
    tFloat fltBetaF;   /**< Transformation coefficient BetaF */
  }GMCLIB_SVMSTD_6PH_T_FLT;
  
/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GMCLIB_SvmStd6PhInit_FLT(GMCLIB_SVMSTD_6PH_T_FLT *const pParam, tFloat fltWindingShift);
  extern void GMCLIB_SvmStd6Ph_FLT(SWLIBS_6Syst_FLT *const pOutPwm, SWLIBS_2Syst_U32 *const pOutSector, const SWLIBS_2Syst_FLT *const pIn, const GMCLIB_SVMSTD_6PH_T_FLT *const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GMCLIB_SVMSTD6PH_H */
