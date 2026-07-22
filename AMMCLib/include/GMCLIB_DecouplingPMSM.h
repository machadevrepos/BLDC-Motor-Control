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
* @file       GMCLIB_DecouplingPMSM.h
*
* @brief      Header file for GMCLIB_DecouplingPMSM function
*
******************************************************************************/
#ifndef GMCLIB_DECOUPLINGPMSM_H
#define GMCLIB_DECOUPLINGPMSM_H

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
  #define GMCLIB_DecouplingPMSM(...)     macro_dispatcher(GMCLIB_DecouplingPMSM, __VA_ARGS__)(__VA_ARGS__)     /* This function calculates the cross-coupling voltages to eliminate the dq axis coupling causing non-linearity of the field oriented control. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define GMCLIB_DECOUPLINGPMSM_T                                                  GMCLIB_DECOUPLINGPMSM_T_F32                                           /**< Definition of GMCLIB_DECOUPLINGPMSM_T as alias for GMCLIB_DECOUPLINGPMSM_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    #define GMCLIB_DECOUPLINGPMSM_DEFAULT                                            GMCLIB_DECOUPLINGPMSM_DEFAULT_F32                                     /**< Definition of GMCLIB_DECOUPLINGPMSM_DEFAULT as alias for GMCLIB_DECOUPLINGPMSM_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    /* @remarks Implements DGMCLIB00059 */
    #define GMCLIB_DecouplingPMSM_Dsptchr_5(pUdqDec,pUdq,pIdq,AngularVel,pParam)     GMCLIB_DecouplingPMSM_Dsptchr_6(pUdqDec,pUdq,pIdq,AngularVel,pParam,F32)     /* Function dispatcher for GMCLIB_DecouplingPMSM_Dsptchr_5, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define GMCLIB_DECOUPLINGPMSM_T                                                  GMCLIB_DECOUPLINGPMSM_T_F16                                           /**< Definition of GMCLIB_DECOUPLINGPMSM_T as alias for GMCLIB_DECOUPLINGPMSM_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    #define GMCLIB_DECOUPLINGPMSM_DEFAULT                                            GMCLIB_DECOUPLINGPMSM_DEFAULT_F16                                     /**< Definition of GMCLIB_DECOUPLINGPMSM_DEFAULT as alias for GMCLIB_DECOUPLINGPMSM_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    /* @remarks Implements DGMCLIB00059 */
    #define GMCLIB_DecouplingPMSM_Dsptchr_5(pUdqDec,pUdq,pIdq,AngularVel,pParam)     GMCLIB_DecouplingPMSM_Dsptchr_6(pUdqDec,pUdq,pIdq,AngularVel,pParam,F16)     /* Function dispatcher for GMCLIB_DecouplingPMSM_Dsptchr_5, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GMCLIB_DECOUPLINGPMSM_T                                                  GMCLIB_DECOUPLINGPMSM_T_FLT                                           /**< Definition of GMCLIB_DECOUPLINGPMSM_T as alias for GMCLIB_DECOUPLINGPMSM_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define GMCLIB_DECOUPLINGPMSM_DEFAULT                                            GMCLIB_DECOUPLINGPMSM_DEFAULT_FLT                                     /**< Definition of GMCLIB_DECOUPLINGPMSM_DEFAULT as alias for GMCLIB_DECOUPLINGPMSM_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DGMCLIB00059 */
    #define GMCLIB_DecouplingPMSM_Dsptchr_5(pUdqDec,pUdq,pIdq,AngularVel,pParam)     GMCLIB_DecouplingPMSM_Dsptchr_6(pUdqDec,pUdq,pIdq,AngularVel,pParam,FLT)     /* Function dispatcher for GMCLIB_DecouplingPMSM_Dsptchr_5, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */

  #define GMCLIB_DecouplingPMSM_Dsptchr_6(pUdqDec,pUdq,pIdq,AngularVel,pParam,Impl)  GMCLIB_DecouplingPMSM_Dsptchr_(pUdqDec,pUdq,pIdq,AngularVel,pParam,Impl)     /* Function dispatcher for GMCLIB_DecouplingPMSM_Dsptchr_6, do not modify!!! */
  
  /* @remarks Implements DGMCLIB00065 */
  #define GMCLIB_DecouplingPMSM_Dsptchr_(pUdqDec,pUdq,pIdq,AngularVel,pParam,Impl)   GMCLIB_DecouplingPMSM_##Impl(pUdqDec,pUdq,pIdq,AngularVel,pParam)            /* Function dispatcher for GMCLIB_DecouplingPMSM_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define GMCLIB_DECOUPLINGPMSM_DEFAULT_F32 {(tFrac32)0,(tS16)0,(tFrac32)0,(tS16)0}     /**< Default value for GMCLIB_DECOUPLINGPMSM_T_F32. */

  /*************************************************************************/
  /**
  @struct GMCLIB_DECOUPLINGPMSM_T_F32 "\GMCLIB_DecouplingPMSM.h" 

  @brief  Structure containing coefficients for calculation of the decoupling.
  *//***********************************************************************/
  /* @remarks Implements DGMCLIB00067, DGMCLIB00063, DGMCLIB00062 */
  typedef struct{
    tFrac32 f32Kd; /**< Coefficient \f$k_{df}\f$. */
    tS16 s16KdShift; /**< Scaling coefficient \f$k_{d_shift}\f$. */
    tFrac32 f32Kq; /**< Coefficient \f$k_{qf}\f$. */
    tS16 s16KqShift; /**< Scaling coefficient \f$k_{q_shift}\f$. */
  }GMCLIB_DECOUPLINGPMSM_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GMCLIB_DecouplingPMSM_F32(SWLIBS_2Syst_F32 *const pUdqDec, \
                                        const SWLIBS_2Syst_F32 *const pUdq, \
                                        const SWLIBS_2Syst_F32 *const pIdq, \
                                        tFrac32 f32AngularVel, \
                                        const GMCLIB_DECOUPLINGPMSM_T_F32 *const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  #define GMCLIB_DECOUPLINGPMSM_DEFAULT_F16 {(tFrac16)0,(tS16)0,(tFrac16)0,(tS16)0}     /**< Default value for GMCLIB_DECOUPLINGPMSM_T_F16. */

  /*************************************************************************/
  /**
  @struct GMCLIB_DECOUPLINGPMSM_T_F16 "\GMCLIB_DecouplingPMSM.h" 

  @brief  Structure containing coefficients for calculation of the decoupling.
  *//***********************************************************************/
  /* @remarks Implements DGMCLIB00067, DGMCLIB00063, DGMCLIB00061 */
  typedef struct{
    tFrac16 f16Kd; /**< Coefficient \f$k_{df}\f$. */
    tS16 s16KdShift; /**< Scaling coefficient \f$k_{d_shift}\f$. */
    tFrac16 f16Kq; /**< Coefficient \f$k_{qf}\f$. */
    tS16 s16KqShift; /**< Scaling coefficient \f$k_{q_shift}\f$. */
  }GMCLIB_DECOUPLINGPMSM_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GMCLIB_DecouplingPMSM_F16(SWLIBS_2Syst_F16 *const pUdqDec, \
                                        const SWLIBS_2Syst_F16 *const pUdq, \
                                        const SWLIBS_2Syst_F16 *const pIdq, \
                                        tFrac16 f16AngularVel, \
                                        const GMCLIB_DECOUPLINGPMSM_T_F16 *const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GMCLIB_DECOUPLINGPMSM_DEFAULT_FLT {(tFloat)0,(tFloat)0}     /**< Default value for GMCLIB_DECOUPLINGPMSM_T_FLT. */

  /*************************************************************************/
  /**
  @struct GMCLIB_DECOUPLINGPMSM_T_FLT "\GMCLIB_DecouplingPMSM.h" 

  @brief  Structure containing coefficients for calculation of the decoupling.
  *//***********************************************************************/
  /* @remarks Implements DGMCLIB00067, DGMCLIB00063, DGMCLIB00060 */
  typedef struct{
    tFloat fltLD; /**< \f$L_{D}\f$ inductance [H]. */
    tFloat fltLQ; /**< \f$L_{Q}\f$ inductance [H]. */
  }GMCLIB_DECOUPLINGPMSM_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GMCLIB_DecouplingPMSM_FLT(SWLIBS_2Syst_FLT *const pUdqDec, \
                                        const SWLIBS_2Syst_FLT *const pUdq, \
                                        const SWLIBS_2Syst_FLT *const pIdq, \
                                        tFloat fltAngularVel, \
                                        const GMCLIB_DECOUPLINGPMSM_T_FLT *const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GMCLIB_DECOUPLINGPMSM_H */
