/******************************************************************************
*
*   Copyright 2021-2026 NXP
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
* @file       AMCLIB_FluxEstimAB.h
*
* @brief      Header file for AMCLIB_FluxEstimAB function
*
******************************************************************************/
#ifndef AMCLIB_FLUXESTIMAB_H
#define AMCLIB_FLUXESTIMAB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "GFLIB_AtanYX.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define AMCLIB_FluxEstimAB(...)     macro_dispatcher(AMCLIB_FluxEstimAB, __VA_ARGS__)(__VA_ARGS__)

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define AMCLIB_FLUXESTIMAB_T                                        AMCLIB_FLUXESTIMAB_T_F32
    /* @remarks Implements DAMMCLIB00089 */
    #define AMCLIB_FluxEstimAB_Dsptchr_4(Velocity,pIAB,pUAB,pParam)     AMCLIB_FluxEstimAB_Dsptchr_5(Velocity,pIAB,pUAB,pParam,F32)     /* Function dispatcher for AMCLIB_FluxEstimAB_Dsptchr_5, do not modify!!! */
  #endif 
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define AMCLIB_FLUXESTIMAB_T                                        AMCLIB_FLUXESTIMAB_T_F16
    /* @remarks Implements DAMMCLIB00089 */
    #define AMCLIB_FluxEstimAB_Dsptchr_4(Velocity,pIAB,pUAB,pParam)     AMCLIB_FluxEstimAB_Dsptchr_5(Velocity,pIAB,pUAB,pParam,F16)     /* Function dispatcher, do not modify!!! */
  #endif 
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_FLUXESTIMAB_T                                        AMCLIB_FLUXESTIMAB_T_FLT
    /* @remarks Implements DAMMCLIB00089 */
    #define AMCLIB_FluxEstimAB_Dsptchr_4(Velocity,pIAB,pUAB,pParam)     AMCLIB_FluxEstimAB_Dsptchr_5(Velocity,pIAB,pUAB,pParam,FLT)     /* Function dispatcher, do not modify!!! */
  #endif 
  
  

  #define AMCLIB_FluxEstimAB_Dsptchr_5(Velocity,pIAB,pUAB,pParam,Impl)    AMCLIB_FluxEstimAB_Dsptchr_(Velocity,pIAB,pUAB,pParam,Impl)     /* Function dispatcher, do not modify!!! */
  /* @remarks Implements DAMMCLIB00091 */
  #define AMCLIB_FluxEstimAB_Dsptchr_(Velocity,pIAB,pUAB,pParam,Impl)     AMCLIB_FluxEstimAB_##Impl(Velocity,pIAB,pUAB,pParam)            /* Function dispatcher, do not modify!!! */
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
  @struct AMCLIB_FLUXESTIMAB_T_F32 "\AMCLIB_FluxEstimAB.h" 

  @brief  Structure containing coefficients for calculation of the flux estimator.
  *//**********************************************************************/
  typedef struct
  {
    tFrac32 f32KRs;  /**< Coefficient \f$K_{Rs}\f$ derived from stator resistance. */
    tFrac32 f32KLs;  /**< Coefficient \f$K_{Ls}\f$ derived from stator inductance. */
    tU16 u16NShift;  /**< Scaling coefficient. */
  }AMCLIB_FLUXESTIMAB_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac32 AMCLIB_FluxEstimAB_F32(tFrac32 f32Velocity, const SWLIBS_2Syst_F32 *const pIAB, const SWLIBS_2Syst_F32 *const pUAB, const AMCLIB_FLUXESTIMAB_T_F32 *const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */

/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)  
  /************************************************************************/
  /**
  @struct AMCLIB_FLUXESTIMAB_T_F16 "\AMCLIB_FluxEstimAB.h" 

  @brief  Structure containing coefficients for calculation of the flux estimator.
  *//**********************************************************************/
  typedef struct
  {
    tFrac16 f16KRs;  /**< Coefficient \f$K_{Rs}\f$ derived from stator resistance. */
    tFrac16 f16KLs;  /**< Coefficient \f$K_{Ls}\f$ derived from stator inductance. */
    tU16 u16NShift;  /**< Scaling coefficient. */
  }AMCLIB_FLUXESTIMAB_T_F16;
  
/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac16 AMCLIB_FluxEstimAB_F16(tFrac16 f16Velocity, const SWLIBS_2Syst_F16 *const pIAB, const SWLIBS_2Syst_F16 *const pUAB, const AMCLIB_FLUXESTIMAB_T_F16 *const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */

/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  /************************************************************************/
  /**
  @struct AMCLIB_FLUXESTIMAB_T_FLT "\AMCLIB_FluxEstimAB.h"

  @brief  Structure containing coefficients for calculation of the flux estimator.
  *//**********************************************************************/
  typedef struct
  {
    tFloat fltRs;  /**< Stator resistance [Ohm]. */
    tFloat fltLs;  /**< Stator inductance [H]. */
  }AMCLIB_FLUXESTIMAB_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFloat AMCLIB_FluxEstimAB_FLT(tFloat fltVelocity, const SWLIBS_2Syst_FLT *const pIAB, const SWLIBS_2Syst_FLT *const pUAB, const AMCLIB_FLUXESTIMAB_T_FLT *const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif/* AMCLIB_FLUXESTIMAB_H */
