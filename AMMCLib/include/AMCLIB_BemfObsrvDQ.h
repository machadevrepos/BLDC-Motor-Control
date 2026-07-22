/******************************************************************************
*
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
* @file       AMCLIB_BemfObsrvDQ.h
*
* @brief      Header file for AMCLIB_BemfObsrvDQ function
*
******************************************************************************/
#ifndef AMCLIB_BEMFOBSRVDQ_H
#define AMCLIB_BEMFOBSRVDQ_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "GFLIB_ControllerPIrAW.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define AMCLIB_BemfObsrvDQInit(...)     macro_dispatcher(AMCLIB_BemfObsrvDQInit, __VA_ARGS__)(__VA_ARGS__)     /* This function initializes the state of the BEMF observer. */
  #define AMCLIB_BemfObsrvDQSetState(...)     macro_dispatcher(AMCLIB_BemfObsrvDQSetState, __VA_ARGS__)(__VA_ARGS__)     /* This function initializes states of the BEMF observer to the predefined values. */
  #define AMCLIB_BemfObsrvDQ(...)     macro_dispatcher(AMCLIB_BemfObsrvDQ, __VA_ARGS__)(__VA_ARGS__)     /* This function calculates the algorithm of back electro-motive force observer in rotating reference frame. */
  
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define AMCLIB_BEMF_OBSRV_DQ_T                                        AMCLIB_BEMF_OBSRV_DQ_T_F32
    /* @remarks Implements DAMCLIB00016 */
    #define AMCLIB_BemfObsrvDQInit_Dsptchr_1(pCtrl)     AMCLIB_BemfObsrvDQInit_Dsptchr_2(pCtrl,F32)     /* Function dispatcher for AMCLIB_BemfObsrvDQInit_Dsptchr_1, do not modify!!! */
    /* @remarks Implements DAMCLIB00163 */
    #define AMCLIB_BemfObsrvDQSetState_Dsptchr_5(pIAB,pUAB,Velocity,pPhaseErr,pCtrl)     AMCLIB_BemfObsrvDQSetState_Dsptchr_6(pIAB,pUAB,Velocity,pPhaseErr,pCtrl,F32)     /* Function dispatcher for AMCLIB_BemfObsrvDQSetState_Dsptchr_5, do not modify!!! */
    /* @remarks Implements DAMCLIB00007 */
    #define AMCLIB_BemfObsrvDQ_Dsptchr_5(pIAB,pUAB,Velocity,pPhaseErr,pCtrl)     AMCLIB_BemfObsrvDQ_Dsptchr_6(pIAB,pUAB,Velocity,pPhaseErr,pCtrl,F32)     /* Function dispatcher for AMCLIB_BemfObsrvDQ_Dsptchr_5, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define AMCLIB_BEMF_OBSRV_DQ_T                                        AMCLIB_BEMF_OBSRV_DQ_T_F16
    /* @remarks Implements DAMCLIB00016 */
    #define AMCLIB_BemfObsrvDQInit_Dsptchr_1(pCtrl)     AMCLIB_BemfObsrvDQInit_Dsptchr_2(pCtrl,F16)     /* Function dispatcher for AMCLIB_BemfObsrvDQInit_Dsptchr_1, do not modify!!! */
    /* @remarks Implements DAMCLIB00163 */
    #define AMCLIB_BemfObsrvDQSetState_Dsptchr_5(pIAB,pUAB,Velocity,pPhaseErr,pCtrl)     AMCLIB_BemfObsrvDQSetState_Dsptchr_6(pIAB,pUAB,Velocity,pPhaseErr,pCtrl,F16)     /* Function dispatcher for AMCLIB_BemfObsrvDQSetState_Dsptchr_5, do not modify!!! */
    /* @remarks Implements DAMCLIB00007 */
    #define AMCLIB_BemfObsrvDQ_Dsptchr_5(pIAB,pUAB,Velocity,pPhaseErr,pCtrl)     AMCLIB_BemfObsrvDQ_Dsptchr_6(pIAB,pUAB,Velocity,pPhaseErr,pCtrl,F16)     /* Function dispatcher for AMCLIB_BemfObsrvDQ_Dsptchr_5, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_BEMF_OBSRV_DQ_T                                        AMCLIB_BEMF_OBSRV_DQ_T_FLT
    /* @remarks Implements DAMCLIB00016 */
    #define AMCLIB_BemfObsrvDQInit_Dsptchr_1(pCtrl)     AMCLIB_BemfObsrvDQInit_Dsptchr_2(pCtrl,FLT)     /* Function dispatcher for AMCLIB_BemfObsrvDQInit_Dsptchr_1, do not modify!!! */
    /* @remarks Implements DAMCLIB00163 */
    #define AMCLIB_BemfObsrvDQSetState_Dsptchr_5(pIAB,pUAB,Velocity,pPhaseErr,pCtrl)     AMCLIB_BemfObsrvDQSetState_Dsptchr_6(pIAB,pUAB,Velocity,pPhaseErr,pCtrl,FLT)     /* Function dispatcher for AMCLIB_BemfObsrvDQSetState_Dsptchr_5, do not modify!!! */
    /* @remarks Implements DAMCLIB00007 */
    #define AMCLIB_BemfObsrvDQ_Dsptchr_5(pIAB,pUAB,Velocity,pPhaseErr,pCtrl)     AMCLIB_BemfObsrvDQ_Dsptchr_6(pIAB,pUAB,Velocity,pPhaseErr,pCtrl,FLT)     /* Function dispatcher for AMCLIB_BemfObsrvDQ_Dsptchr_5, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
  
  #define AMCLIB_BemfObsrvDQInit_Dsptchr_2(pCtrl,Impl)    AMCLIB_BemfObsrvDQInit_Dsptchr_(pCtrl,Impl)     /* Function dispatcher for AMCLIB_BemfObsrvDQInit_Dsptchr_2, do not modify!!! */
  /* @remarks Implements DAMCLIB00018 */
  #define AMCLIB_BemfObsrvDQInit_Dsptchr_(pCtrl,Impl)     AMCLIB_BemfObsrvDQInit_##Impl(pCtrl)            /* Function dispatcher for AMCLIB_BemfObsrvDQInit_Dsptchr_, do not modify!!! */
  
  #define AMCLIB_BemfObsrvDQSetState_Dsptchr_6(pIAB,pUAB,Velocity,pPhaseErr,pCtrl,Impl)    AMCLIB_BemfObsrvDQSetState_Dsptchr_(pIAB,pUAB,Velocity,pPhaseErr,pCtrl,Impl)     /* Function dispatcher for AMCLIB_BemfObsrvDQSetState_Dsptchr_6, do not modify!!! */
  /* @remarks Implements DAMCLIB00165 */
  #define AMCLIB_BemfObsrvDQSetState_Dsptchr_(pIAB,pUAB,Velocity,pPhaseErr,pCtrl,Impl)     AMCLIB_BemfObsrvDQSetState_##Impl(pIAB,pUAB,Velocity,pPhaseErr,pCtrl)            /* Function dispatcher for AMCLIB_BemfObsrvDQSetState_Dsptchr_, do not modify!!! */

  #define AMCLIB_BemfObsrvDQ_Dsptchr_6(pIAB,pUAB,Velocity,pPhaseErr,pCtrl,Impl)    AMCLIB_BemfObsrvDQ_Dsptchr_(pIAB,pUAB,Velocity,pPhaseErr,pCtrl,Impl)     /* Function dispatcher for AMCLIB_BemfObsrvDQ_Dsptchr_6, do not modify!!! */
  /* @remarks Implements DAMCLIB00009 */
  #define AMCLIB_BemfObsrvDQ_Dsptchr_(pIAB,pUAB,Velocity,pPhaseErr,pCtrl,Impl)     AMCLIB_BemfObsrvDQ_##Impl(pIAB,pUAB,Velocity,pPhaseErr,pCtrl)            /* Function dispatcher for AMCLIB_BemfObsrvDQ_Dsptchr_, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)

  #define AMCLIB_BEMF_OBSRV_DQ_DEFAULT_F32 {(tFrac32)0,(tFrac32)0, \
                                            (tFrac32)0,(tFrac32)0, \
                                            (tFrac32)0,(tFrac32)0,(tFrac32)0,(tFrac32)0,SWLIBS_INT32_MIN,SWLIBS_INT32_MAX,(tU16)0, \
                                            (tFrac32)0,(tFrac32)0,(tFrac32)0,(tFrac32)0,SWLIBS_INT32_MIN,SWLIBS_INT32_MAX,(tU16)0, \
                                            (tFrac32)0,(tFrac32)0, \
                                            (tFrac16)0,(tFrac16)0, \
                                            (tFrac32)0,(tFrac32)0,(tFrac32)0,(tFrac32)0,(tS16)0}               /**< Default value for AMCLIB_BEMF_OBSRV_DQ_T_F32. */
  
  /************************************************************************/
  /**
  @struct AMCLIB_BEMF_OBSRV_DQ_T_F32 "\AMCLIB_BemfObsrvDQ.h" 

  @brief  Observer configuration structure.
  *//**********************************************************************/
  typedef struct
  {
    SWLIBS_2Syst_F32  pEObsrv;  /**< Estimated BEMF - D/Q. */
    SWLIBS_2Syst_F32  pIObsrv;  /**< Estimated current - D/Q. */
    GFLIB_CONTROLLER_PIAW_R_T_F32   pParamD;    /**< Observer parameters for D-axis controller. */
    GFLIB_CONTROLLER_PIAW_R_T_F32   pParamQ;    /**< Observer parameters for Q-axis controller. */
    SWLIBS_2Syst_F32  pIObsrvIn_1L;  /**< Inputs of RL circuit at step k-1 - low word */
    SWLIBS_2Syst_F16  pIObsrvIn_1H;  /**< Inputs of RL circuit at step k-1 - high word */
    tFrac32 f32IGain;  /**< Scaled RL circuit constant, fractional format normalized to fit into (-\f$2^{31}\f$, \f$2^{31}\f$-1). */
    tFrac32 f32UGain;  /**< Scaled voltage cross-coupling constant, fractional format normalized to fit into (-\f$2^{31}\f$, \f$2^{31}\f$-1). */
    tFrac32 f32WIGain; /**< Scaled angular velocity cross-coupling constant, fractional format normalized to fit into (-\f$2^{31}\f$, \f$2^{31}\f$-1). */
    tFrac32 f32EGain;  /**< Scaled back-EMF cross-coupling constant, fractional format normalized to fit into (-\f$2^{31}\f$, \f$2^{31}\f$-1). */
    tS16 s16Shift;     /**< Scaling bitwise shift applied to all cross-coupling constants, integer format in the range [-30, 30]. Function accuracy guaranteed only for range [-1, 1]. */
  }AMCLIB_BEMF_OBSRV_DQ_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_BemfObsrvDQInit_F32(AMCLIB_BEMF_OBSRV_DQ_T_F32 *const pCtrl);
  extern void AMCLIB_BemfObsrvDQSetState_F32(const SWLIBS_2Syst_F32 *const pIAB,
    const SWLIBS_2Syst_F32 *const pUAB, tFrac32 f32Velocity, tFrac32 f32Phase,
    AMCLIB_BEMF_OBSRV_DQ_T_F32 *const pCtrl);
  extern tFrac32 AMCLIB_BemfObsrvDQ_F32(const SWLIBS_2Syst_F32 *const pIAB,
    const SWLIBS_2Syst_F32 *const pUAB, tFrac32 f32Velocity, tFrac32 f32Phase,
    AMCLIB_BEMF_OBSRV_DQ_T_F32 *const pCtrl);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)

  #define AMCLIB_BEMF_OBSRV_DQ_DEFAULT_F16 {(tFrac16)0,(tFrac16)0, \
                                            (tFrac32)0,(tFrac32)0, \
                                            (tFrac16)0,(tFrac16)0,(tFrac32)0,(tFrac16)0,SWLIBS_INT16_MIN,SWLIBS_INT16_MAX,(tU16)0, \
                                            (tFrac16)0,(tFrac16)0,(tFrac32)0,(tFrac16)0,SWLIBS_INT16_MIN,SWLIBS_INT16_MAX,(tU16)0, \
                                            (tFrac32)0,(tFrac32)0, \
                                            (tFrac16)0,(tFrac16)0, \
                                            (tFrac16)0,(tFrac16)0,(tFrac16)0,(tFrac16)0,(tS16)0}               /**< Default value for AMCLIB_BEMF_OBSRV_DQ_T_F16. */
  
  /************************************************************************/
  /**
  @struct AMCLIB_BEMF_OBSRV_DQ_T_F16 "\AMCLIB_BemfObsrvDQ.h" 

  @brief  Observer configuration structure.
  *//**********************************************************************/
  typedef struct
  {
    SWLIBS_2Syst_F16  pEObsrv;  /**< Estimated BEMF - D/Q. */
    SWLIBS_2Syst_F32  pIObsrv;  /**< Estimated current - D/Q. */
    GFLIB_CONTROLLER_PIAW_R_T_F16   pParamD;    /**< Observer parameters for D-axis controller. */
    GFLIB_CONTROLLER_PIAW_R_T_F16   pParamQ;    /**< Observer parameters for Q-axis controller. */
    SWLIBS_2Syst_F32  pIObsrvIn_1L;  /**< Inputs of RL circuit at step k-1 - low word */
    SWLIBS_2Syst_F16  pIObsrvIn_1H;  /**< Inputs of RL circuit at step k-1 - high word */
    tFrac16 f16IGain;  /**< Scaled RL circuit constant, fractional format normalized to fit into (-\f$2^{15}\f$, \f$2^{15}\f$-1). */
    tFrac16 f16UGain;  /**< Scaled voltage cross-coupling constant, fractional format normalized to fit into (-\f$2^{15}\f$, \f$2^{15}\f$-1). */
    tFrac16 f16WIGain; /**< Scaled angular velocity cross-coupling constant, fractional format normalized to fit into (-\f$2^{15}\f$, \f$2^{15}\f$-1). */
    tFrac16 f16EGain;  /**< Scaled back-EMF cross-coupling constant, fractional format normalized to fit into (-\f$2^{15}\f$, \f$2^{15}\f$-1). */
    tS16 s16Shift;     /**< Scaling bitwise shift applied to all cross-coupling constants, integer format in the range [-14, 14]. Function accuracy guaranteed only for range [-1, 1]. */
  }AMCLIB_BEMF_OBSRV_DQ_T_F16;
  
/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_BemfObsrvDQInit_F16(AMCLIB_BEMF_OBSRV_DQ_T_F16 *const pCtrl);
  extern void AMCLIB_BemfObsrvDQSetState_F16(const SWLIBS_2Syst_F16 *const pIAB,
    const SWLIBS_2Syst_F16 *const pUAB, tFrac16 f16Velocity, tFrac16 f16Phase,
    AMCLIB_BEMF_OBSRV_DQ_T_F16 *const pCtrl);
  extern tFrac16 AMCLIB_BemfObsrvDQ_F16(const SWLIBS_2Syst_F16 *const pIAB,
    const SWLIBS_2Syst_F16 *const pUAB, tFrac16 f16Velocity, tFrac16 f16Phase,
    AMCLIB_BEMF_OBSRV_DQ_T_F16 *const pCtrl);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)

  #define AMCLIB_BEMF_OBSRV_DQ_DEFAULT_FLT {(tFloat)0,(tFloat)0, \
                                            (tFloat)0,(tFloat)0, \
                                            (tFloat)0,(tFloat)0,(tFloat)0,(tFloat)0,FLOAT_MIN,FLOAT_MAX, \
                                            (tFloat)0,(tFloat)0,(tFloat)0,(tFloat)0,FLOAT_MIN,FLOAT_MAX, \
                                            (tFloat)0,(tFloat)0, \
                                            (tFloat)0,(tFloat)0,(tFloat)0,(tFloat)0}               /**< Default value for AMCLIB_BEMF_OBSRV_DQ_T_FLT. */

  /************************************************************************/
  /**
  @struct AMCLIB_BEMF_OBSRV_DQ_T_FLT "\AMCLIB_BemfObsrvDQ.h"

  @brief  Observer configuration structure.
  *//**********************************************************************/
  typedef struct
  {
    SWLIBS_2Syst_FLT  pEObsrv;  /**< Estimated BEMF - D/Q. */
    SWLIBS_2Syst_FLT  pIObsrv;  /**< Estimated current - D/Q. */
    GFLIB_CONTROLLER_PIAW_R_T_FLT   pParamD;    /**< Observer parameters for D-axis controller. */
    GFLIB_CONTROLLER_PIAW_R_T_FLT   pParamQ;    /**< Observer parameters for Q-axis controller. */
    SWLIBS_2Syst_FLT  pIObsrvIn_1;  /**< Inputs of RL circuit at step k-1 */
    tFloat fltIGain;  /**< RL circuit constant, single precision floating point format. */
    tFloat fltUGain;  /**< Voltage cross-coupling constant, single precision floating point format. */
    tFloat fltWIGain; /**< Angular velocity cross-coupling constant, single precision floating point format. */
    tFloat fltEGain;  /**< Back-EMF cross-coupling constant, single precision floating point format. */
  }AMCLIB_BEMF_OBSRV_DQ_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_BemfObsrvDQInit_FLT(AMCLIB_BEMF_OBSRV_DQ_T_FLT *const pCtrl);
  extern void AMCLIB_BemfObsrvDQSetState_FLT(const SWLIBS_2Syst_FLT *const pIAB,
    const SWLIBS_2Syst_FLT *const pUAB, tFloat fltVelocity, tFloat fltPhase,
    AMCLIB_BEMF_OBSRV_DQ_T_FLT *const pCtrl);
  extern tFloat AMCLIB_BemfObsrvDQ_FLT(const SWLIBS_2Syst_FLT *const pIAB,
    const SWLIBS_2Syst_FLT *const pUAB, tFloat fltVelocity, tFloat fltPhase,
    AMCLIB_BEMF_OBSRV_DQ_T_FLT *const pCtrl);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif/* AMCLIB_BEMFOBSRVDQ_H */
