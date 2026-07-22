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
* @file       GFLIB_IntegratorTR.h
*
* @brief      Header file for GFLIB_IntegratorTR function
*
******************************************************************************/
#ifndef GFLIB_INTEGRATORTR_H
#define GFLIB_INTEGRATORTR_H

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
  #define GFLIB_IntegratorTRSetState(...)     macro_dispatcher(GFLIB_IntegratorTRSetState, __VA_ARGS__)(__VA_ARGS__)     /* The function sets the state variables of the integrator. */
  #define GFLIB_IntegratorTR(...)     macro_dispatcher(GFLIB_IntegratorTR, __VA_ARGS__)(__VA_ARGS__)     /* The function calculates a discrete implementation of the integrator (sum), discretized using a trapezoidal (Bilinear) transformation. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define GFLIB_INTEGRATOR_TR_T                       GFLIB_INTEGRATOR_TR_T_F32                       /**< Definition of GFLIB_INTEGRATOR_TR_T as alias for GFLIB_INTEGRATOR_TR_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    #define GFLIB_INTEGRATOR_TR_DEFAULT                 GFLIB_INTEGRATOR_TR_DEFAULT_F32                 /**< Definition of GFLIB_INTEGRATOR_TR_DEFAULT as alias for GFLIB_INTEGRATOR_TR_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    /* @remarks Implements DGFLIB00453 */
    #define GFLIB_IntegratorTRSetState_Dsptchr_2(IntegratorTROut,pParam)     GFLIB_IntegratorTRSetState_Dsptchr_3(IntegratorTROut,pParam,F32)     /* Function dispatcher for GFLIB_IntegratorTRSetState_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGFLIB00261 */
    #define GFLIB_IntegratorTR_Dsptchr_2(In,pParam)     GFLIB_IntegratorTR_Dsptchr_3(In,pParam,F32)     /* Function dispatcher for GFLIB_IntegratorTR_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define GFLIB_INTEGRATOR_TR_T                       GFLIB_INTEGRATOR_TR_T_F16                       /**< Definition of GFLIB_INTEGRATOR_TR_T as alias for GFLIB_INTEGRATOR_TR_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    #define GFLIB_INTEGRATOR_TR_DEFAULT                 GFLIB_INTEGRATOR_TR_DEFAULT_F16                 /**< Definition of GFLIB_INTEGRATOR_TR_DEFAULT as alias for GFLIB_INTEGRATOR_TR_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    /* @remarks Implements DGFLIB00453 */
    #define GFLIB_IntegratorTRSetState_Dsptchr_2(IntegratorTROut,pParam)     GFLIB_IntegratorTRSetState_Dsptchr_3(IntegratorTROut,pParam,F16)     /* Function dispatcher for GFLIB_IntegratorTRSetState_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGFLIB00261 */
    #define GFLIB_IntegratorTR_Dsptchr_2(In,pParam)     GFLIB_IntegratorTR_Dsptchr_3(In,pParam,F16)     /* Function dispatcher for GFLIB_IntegratorTR_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GFLIB_INTEGRATOR_TR_T                       GFLIB_INTEGRATOR_TR_T_FLT                       /**< Definition of GFLIB_INTEGRATOR_TR_T as alias for GFLIB_INTEGRATOR_TR_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define GFLIB_INTEGRATOR_TR_DEFAULT                 GFLIB_INTEGRATOR_TR_DEFAULT_FLT                 /**< Definition of GFLIB_INTEGRATOR_TR_DEFAULT as alias for GFLIB_INTEGRATOR_TR_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DGFLIB00453 */
    #define GFLIB_IntegratorTRSetState_Dsptchr_2(IntegratorTROut,pParam)     GFLIB_IntegratorTRSetState_Dsptchr_3(IntegratorTROut,pParam,FLT)     /* Function dispatcher for GFLIB_IntegratorTRSetState_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGFLIB00261 */
    #define GFLIB_IntegratorTR_Dsptchr_2(In,pParam)     GFLIB_IntegratorTR_Dsptchr_3(In,pParam,FLT)     /* Function dispatcher for GFLIB_IntegratorTR_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */

  #define GFLIB_IntegratorTR_Dsptchr_3(In,pParam,Impl)    GFLIB_IntegratorTR_Dsptchr_(In,pParam,Impl)     /* Function dispatcher for GFLIB_IntegratorTR_Dsptchr_3, do not modify!!! */
  
  #define GFLIB_IntegratorTRSetState_Dsptchr_3(IntegratorTROut,pParam,Impl)    GFLIB_IntegratorTRSetState_Dsptchr_(IntegratorTROut,pParam,Impl)     /* Function dispatcher for GFLIB_IntegratorTRSetState_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DGFLIB00455 */
  #define GFLIB_IntegratorTRSetState_Dsptchr_(IntegratorTROut,pParam,Impl)     GFLIB_IntegratorTRSetState_##Impl(IntegratorTROut,pParam)            /* Function dispatcher for GFLIB_IntegratorTRSetState_Dsptchr_, do not modify!!! */
  
  /* @remarks Implements DGFLIB00263 */
  #define GFLIB_IntegratorTR_Dsptchr_(In,pParam,Impl)     GFLIB_IntegratorTR_##Impl(In,pParam)            /* Function dispatcher for GFLIB_IntegratorTR_Dsptchr_, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define GFLIB_INTEGRATOR_TR_DEFAULT_F32 {(tFrac32)0,(tFrac32)0,(tFrac32)0,(tU16)0}     /**< Default value for GFLIB_INTEGRATOR_TR_T_F32. */

  /************************************************************************/
  /**
  @struct GFLIB_INTEGRATOR_TR_T_F32 "\GFLIB_IntegratorTR.h" 

  @brief  Structure containing integrator parameters and coefficients.
  *//**********************************************************************/
  /* @remarks Implements DGFLIB00264 */
  typedef struct{
    tFrac32 f32State;       /**< State variable - integrator state value. */
    tFrac32 f32InK1;        /**< State variable - input value in step k-1. */
    tFrac32 f32C1;          /**< Integrator coefficient = (\f$E_{MAX}\f$/\f$T_{s}\f$)(\f$U_{MAX}\f$*2)*(\f$2^{-u16NShift}\f$). */
    tU16    u16NShift;      /**< Scaling bitwise shift applied to the integrator coefficient f32C1, integer format [0, 15]. */
  }GFLIB_INTEGRATOR_TR_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GFLIB_IntegratorTRSetState_F32(tFrac32 f32IntegratorTROut, GFLIB_INTEGRATOR_TR_T_F32 *const pParam);
  extern tFrac32 GFLIB_IntegratorTR_F32(tFrac32 f32In, GFLIB_INTEGRATOR_TR_T_F32 *const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  #define GFLIB_INTEGRATOR_TR_DEFAULT_F16 {(tFrac32)0,(tFrac16)0,(tFrac16)0,(tU16)0}     /**< Default value for GFLIB_INTEGRATOR_TR_T_F16. */

  /************************************************************************/
  /**
  @struct GFLIB_INTEGRATOR_TR_T_F16 "\GFLIB_IntegratorTR.h" 

  @brief  Structure containing integrator parameters and coefficients.
  *//**********************************************************************/
  /* @remarks Implements DGFLIB00264 */
  typedef struct{
    tFrac32 f32State;       /**< State variable - integrator state value. */
    tFrac16 f16InK1;        /**< State variable - input value in step k-1. */
    tFrac16 f16C1;          /**< Integrator coefficient = (\f$E_{MAX}\f$/\f$T_{s}\f$)(\f$U_{MAX}\f$*2)*(\f$2^{-u16NShift}\f$). */
    tU16    u16NShift;      /**< Scaling bitwise shift applied to the integrator coefficient f16C1, integer format [0, 15]. */
  }GFLIB_INTEGRATOR_TR_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GFLIB_IntegratorTRSetState_F16(tFrac16 f16IntegratorTROut, GFLIB_INTEGRATOR_TR_T_F16 *const pParam);
  extern tFrac16 GFLIB_IntegratorTR_F16(tFrac16 f16In, GFLIB_INTEGRATOR_TR_T_F16 *const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GFLIB_INTEGRATOR_TR_DEFAULT_FLT {(tFloat)0,(tFloat)0,(tFloat)0}     /**< Default value for GFLIB_INTEGRATOR_TR_T_FLT. */

  /************************************************************************/
  /**
  @struct GFLIB_INTEGRATOR_TR_T_FLT "\GFLIB_IntegratorTR.h" 

  @brief  Structure containing integrator parameters and coefficients.
  *//**********************************************************************/
  /* @remarks Implements DGFLIB00264 */
  typedef struct{
    tFloat fltState;     /**< State variable - integrator state value, single precision floating point format. */
    tFloat fltInK1;      /**< State variable - input value in step k-1, single precision floating point format. */
    tFloat fltC1;        /**< Integrator coefficient, single precision floating point format. */
  }GFLIB_INTEGRATOR_TR_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GFLIB_IntegratorTRSetState_FLT(tFloat fltIntegratorTROut, GFLIB_INTEGRATOR_TR_T_FLT *const pParam);
  extern tFloat GFLIB_IntegratorTR_FLT(tFloat fltIn, GFLIB_INTEGRATOR_TR_T_FLT *const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_INTEGRATORTR_H */
