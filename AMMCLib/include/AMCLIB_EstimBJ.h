/******************************************************************************
*
*   Copyright 2023-2026 NXP
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
* @file       AMCLIB_EstimBJ.h
*
* @brief      Header file for AMCLIB_EstimBJ function
*
******************************************************************************/
#ifndef AMCLIB_ESTIMBJ_H
#define AMCLIB_ESTIMBJ_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "GFLIB_Ramp.h"
#include "GFLIB_IntegratorTR.h"
#include "GDFLIB_FilterMA.h"
#include "GFLIB_ControllerPIpAW.h"
#include "GFLIB_ControllerPIrAW.h"
#include "AMCLIB_FluxEstimAB.h"
#include "AMCLIB_TrackObsrv.h"
#include "AMCLIB_CurrentLoop.h"
#include "GFLIB_Atan.h"
#include "GFLIB_AtanYX.h"
#include "GFLIB_SinCos.h"
#include "GFLIB_Sin.h"
#include "GFLIB_Cos.h"
#include "GFLIB_Sqrt.h"
#include "GMCLIB_Park.h"
#include "GMCLIB_ParkInv.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define AMCLIB_EstimBJInit(...)     macro_dispatcher(AMCLIB_EstimBJInit, __VA_ARGS__)(__VA_ARGS__)     /* This function initializes the state of the AMCLIB_EstimBJ. */
  #define AMCLIB_EstimBJ(...)         macro_dispatcher(AMCLIB_EstimBJ, __VA_ARGS__)(__VA_ARGS__)     /* This function calculates the AMCLIB_EstimBJ. */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_ESTIMBJ_T      AMCLIB_ESTIMBJ_T_FLT
    #define ESTIMBJ_INIT_DEFAULT  ESTIMBJ_INIT_DEFAULT_FLT
    #define ESTIMBJ_INIT_CFG1     ESTIMBJ_INIT_CFG1_FLT
    #define ESTIMBJ_INIT_CFG2     ESTIMBJ_INIT_CFG2_FLT
    /* @remarks Implements DAMMCLIB00095 */
    #define AMCLIB_EstimBJInit_Dsptchr_19(pCtrl,estB,fs,In,Wn,pp,Ld,Lq,Rs,Udt,ap1,ap2,ap3,ap4,ap5,ap6,ap7,ap8,ap9)     AMCLIB_EstimBJInit_Dsptchr_20(pCtrl,estB,fs,In,Wn,pp,Ld,Lq,Rs,Udt,ap1,ap2,ap3,ap4,ap5,ap6,ap7,ap8,ap9,FLT)     /* Function dispatcher for AMCLIB_EstimBJInit_Dsptchr_19, do not modify!!! */
    /* @remarks Implements DAMMCLIB00095 */
    #define AMCLIB_EstimBJ_Dsptchr_4(pUAlBeReq,pIAlBeFbck,UDcBus,pCtrl)     AMCLIB_EstimBJ_Dsptchr_5(pUAlBeReq,pIAlBeFbck,UDcBus,pCtrl,FLT)     /* Function dispatcher for AMCLIB_EstimBJ_Dsptchr_5, do not modify!!! */
    #endif
  #define AMCLIB_EstimBJInit_Dsptchr_20(pCtrl,estB,fs,In,Wn,pp,Ld,Lq,Rs,Udt,ap1,ap2,ap3,ap4,ap5,ap6,ap7,ap8,ap9,Impl)    AMCLIB_EstimBJInit_Dsptchr_(pCtrl,estB,fs,In,Wn,pp,Ld,Lq,Rs,Udt,ap1,ap2,ap3,ap4,ap5,ap6,ap7,ap8,ap9,Impl)     /* Function dispatcher for AMCLIB_EstimBJInit_Dsptchr_20, do not modify!!! */
  /* @remarks Implements DAMMCLIB00097 */
  #define AMCLIB_EstimBJInit_Dsptchr_(pCtrl,estB,fs,In,Wn,pp,Ld,Lq,Rs,Udt,ap1,ap2,ap3,ap4,ap5,ap6,ap7,ap8,ap9,Impl)     AMCLIB_EstimBJInit_##Impl(pCtrl,estB,fs,In,Wn,pp,Ld,Lq,Rs,Udt,ap1,ap2,ap3,ap4,ap5,ap6,ap7,ap8,ap9)            /* Function dispatcher for AMCLIB_EstimBJInit_Dsptchr_, do not modify!!! */
  #define AMCLIB_EstimBJ_Dsptchr_5(pUAlBeReq,pIAlBeFbck,UDcBus,pCtrl,Impl)  AMCLIB_EstimBJ_Dsptchr_(pUAlBeReq,pIAlBeFbck,UDcBus,pCtrl,Impl)     /* Function dispatcher for AMCLIB_EstimBJ_Dsptchr_5, do not modify!!! */
  /* @remarks Implements DAMMCLIB00097 */
  #define AMCLIB_EstimBJ_Dsptchr_(pUAlBeReq,pIAlBeFbck,UDcBus,pCtrl,Impl)   AMCLIB_EstimBJ_##Impl(pUAlBeReq,pIAlBeFbck,UDcBus,pCtrl)            /* Function dispatcher for AMCLIB_EstimBJ_Dsptchr_, do not modify!!! */
  #define ESTIMBJ_INIT_CFG1_FLT(...) macro_dispatcher(ESTIMBJ_INIT_CFG1_FLT, __VA_ARGS__)(__VA_ARGS__)
  
  #define ESTIMBJ_INIT_CFG1_FLT_Dsptchr_8(ESTIMBJ_FS,ESTIMBJ_IN,ESTIMBJ_WN,ESTIMBJ_PP,ESTIMBJ_LD,ESTIMBJ_LQ,ESTIMBJ_RS,ESTIMBJ_UDT) \
          (AMCLIB_ESTIMBJ_INIT_T_FLT){FALSE,((unsigned int)ESTIMBJ_FS),((float)ESTIMBJ_IN),((float)ESTIMBJ_WN),((float)ESTIMBJ_PP),((float)ESTIMBJ_LD), \
                                      ((float)ESTIMBJ_LQ),((float)ESTIMBJ_RS),((float)ESTIMBJ_UDT),0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}
  #define ESTIMBJ_INIT_CFG1_FLT_Dsptchr_5(ESTIMBJ_FS,ESTIMBJ_IN,ESTIMBJ_WN,ESTIMBJ_PP,ESTIMRL_STRUCT) \
          ESTIMBJ_INIT_CFG1_FLT_Dsptchr_8(ESTIMBJ_FS,ESTIMBJ_IN,ESTIMBJ_WN,ESTIMBJ_PP,ESTIMRL_STRUCT.fltLd,ESTIMRL_STRUCT.fltLq,ESTIMRL_STRUCT.fltR,ESTIMRL_STRUCT.fltUdt)
  
  #define ESTIMBJ_INIT_CFG2_FLT(...)   macro_dispatcher(ESTIMBJ_INIT_CFG2_FLT, __VA_ARGS__)(__VA_ARGS__)
  #define ESTIMBJ_INIT_CFG2_FLT_Dsptchr_8(ESTIMBJ_FS,ESTIMBJ_IN,ESTIMBJ_WN,ESTIMBJ_PP,ESTIMBJ_LD,ESTIMBJ_LQ,ESTIMBJ_RS,ESTIMBJ_UDT) \
          (AMCLIB_ESTIMBJ_INIT_T_FLT){TRUE,((unsigned int)ESTIMBJ_FS),((float)ESTIMBJ_IN),((float)ESTIMBJ_WN),((float)ESTIMBJ_PP),((float)ESTIMBJ_LD), \
                                      ((float)ESTIMBJ_LQ),((float)ESTIMBJ_RS),((float)ESTIMBJ_UDT),0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}
  #define ESTIMBJ_INIT_CFG2_FLT_Dsptchr_5(ESTIMBJ_FS,ESTIMBJ_IN,ESTIMBJ_WN,ESTIMBJ_PP,ESTIMRL_STRUCT) \
          ESTIMBJ_INIT_CFG2_FLT_Dsptchr_8(ESTIMBJ_FS,ESTIMBJ_IN,ESTIMBJ_WN,ESTIMBJ_PP,ESTIMRL_STRUCT.fltLd,ESTIMRL_STRUCT.fltLq,ESTIMRL_STRUCT.fltR,ESTIMRL_STRUCT.fltUdt)
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/************************************************************************//**
@enum   AMCLIB_ESTIMBJINIT_RET_T

@brief  Enum type of the AMCLIB_EstimBJInit return value.
*//*************************************************************************/
  typedef enum
  {
    ESTIMBJ_RET_INIT_OK = 0,     /**< Initialization successful. */
    ESTIMBJ_RET_INIT_ERROR = 1,  /**< Invalid inputs. */
  } AMCLIB_ESTIMBJINIT_RET_T;

/************************************************************************//**
@enum   AMCLIB_ESTIMBJ_RET_T

@brief  Enum type of the AMCLIB_EstimBJ return value.
*//*************************************************************************/
  typedef enum
  {
    ESTIMBJ_RET_IN_PROGRESS = 0,  /**< Parameter estimation is in progress. The AMCLIB_EstimBJ must be called again in the next sampling period. */
    ESTIMBJ_RET_DONE = 1,         /**< Parameter estimation has finished. */
    ESTIMBJ_RET_ERROR = 2,        /**< Parameter estimation has failed. */
  } AMCLIB_ESTIMBJ_RET_T;

/************************************************************************//**
@enum   AMCLIB_ESTIMBJ_STATE_T

@brief  Enum type of the AMCLIB_EstimBJ internal state.
*//*************************************************************************/
  typedef enum
  {
    ESTIMBJ_STATE_UNINITIALIZED = 0, /**< BJ estimator is not initialized. */
    ESTIMBJ_STATE_ROTOR_ALIGN,       /**< Rotor alignment. */
    ESTIMBJ_STATE_OL_STARTUP,        /**< Open loop startup. */
    ESTIMBJ_STATE_FLUX_ESTIM,        /**< Closed loop control. */
    ESTIMBJ_STATE_FREQ_SELECT,       /**< Selection of injected frequency. */
    ESTIMBJ_STATE_PARAM_EST_MEAS,    /**< Measurement of meachanical parameters. */
    ESTIMBJ_STATE_DONE,              /**< Measurement finished. */
    ESTIMBJ_STATE_ERROR,             /**< Failure. */
  } AMCLIB_ESTIMBJ_STATE_T;

/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  /************************************************************************/
  /**
  @struct AMCLIB_ESTIMBJ_INNERST_T_FLT "\AMCLIB_EstimBJ.h"

  @brief  Internal state of the RL estimator. No user-editable values.
  *//**********************************************************************/
  typedef struct
  {
    AMCLIB_ESTIMBJ_STATE_T pState;                  /**< Mechanical parameters estimator state */
    tBool bTwoPointMeas;                            /**< Indicator of the advanced mode measurement */
    tBool bFoundInjFreq;                            /**< Indicator that injected frequency was found */
    tU32 u32AlignTimer;                             /**< Rotor alignment timer */
    tU32 u32TimerPreset;                            /**< Rotor alignment timer */
    tFloat fltIReq;                                 /**< Required current in open loop */
    tFloat fltDCWReq1;                              /**< Required DC speed point 1 for measurement */
    tFloat fltDCWReq2;                              /**< Required DC speed point 2 for measurement */
    tFloat fltACWReq;                               /**< Required amplitude of the injected AC speed */
    tFloat fltWMax;                                 /**< RMaximal velocty */
    tFloat fltPP;                                   /**< Number of pole pairs */
    tFloat fltTs;                                   /**< Sampling frequency */
    tFloat fltFInj;                                 /**< Injected frequency */
    tFloat fltWInj;                                 /**< Injected angular frequency */
    /* Open Loop */               
    tFloat fltWOl;                                  /**< Open loop velocity */
    tFloat fltThOl;                                 /**< Open loop position */
    GFLIB_RAMP_T_FLT pOLRamp;                       /**< Parameter structure for open loop ramp */
    GFLIB_INTEGRATOR_TR_T_F32 pOLInteg;             /**< Parameter structure for open loop integrator */
    GDFLIB_FILTER_MA_T_FLT pIqMAFilter;             /**< Parameter structure for open loop MA filter */
    SWLIBS_2Syst_FLT pThRealTransform;              /**< Structure to contain sine and cosine value of real rotor position */
    SWLIBS_2Syst_FLT pIDQRealFbck;                  /**< Real DQ feedback currents */
    /* Speed modulation */
    tFloat fltWDcReq;                               /**< Required DC speed */
    tFloat fltWAcMaxReq;                            /**< Required amplitude of AC speed */
    tFloat fltIqDcReq;                              /**< Required Q current based on DC speed regulator */
    tFloat fltIqAcReq;                              /**< Required Q current amplitude based on AC speed regulator */
    tFloat fltIqAcMaxReq;                           /**< Maximal required Q current based on AC speed regulator */
    GFLIB_RAMP_T_FLT pWDcReqRamp;                   /**< Ramp for required DC speed */
    GFLIB_RAMP_T_FLT pWAcMaxReqRamp;                /**< Ramp for required AC speed */
    GFLIB_CONTROLLER_PIAW_P_T_FLT pWDcPI;           /**< DC speed controller */
    GFLIB_CONTROLLER_PIAW_P_T_FLT pWAcMaxPI;        /**< AC speed controller */
    tFloat fltWDcErr;                               /**< DC speed error */
    tFloat fltWAcMaxErr;                            /**< Input error for AC speed controller */
    tFrac32 f32Theta;                               /**< Modulated AC signals phase */
    /* Current control */
    SWLIBS_2Syst_FLT pUDQReq;                       /**< Required DQ voltage */
    AMCLIB_CURRENT_LOOP_T_FLT pCurrentLoop;         /**< Parameter structure for current loop */
    SWLIBS_2Syst_FLT pIDQReqCLoop;                  /**< Required DQ current */
    SWLIBS_2Syst_FLT pIDQFbckCLoop;                 /**< Measured DQ current */
    tFloat fltThEl;                                 /**< Rotor angular position */
    SWLIBS_2Syst_FLT pThTransform;                  /**< Structure to store sine and cosine of rotor angular posion */
    /* PLL */
    tFloat fltDcRaw;                                /**< Demodulated DC speed */
    SWLIBS_2Syst_FLT pWABAcRaw;                     /**< Demodulated AC speed */
    SWLIBS_2Syst_FLT pPllSinCosEst;                 /**< Structure to store sine and cosine of PLL's internal phase */
    tFloat fltDcFilt;                               /**< Filtered demodulated DC speed */
    tFloat fltAcFilt;                               /**< Filtered demodulated AC speed */
    tFloat fltWABEstErr;                            /**< PLL error */
    GDFLIB_FILTER_MA_T_FLT pPllDMAFilter;           /**< MA filter for D component of AC speed */
    GDFLIB_FILTER_MA_T_FLT pPllQMAFilter;           /**< MA filter for Q component of AC speed */
    GDFLIB_FILTER_MA_T_FLT pPllDcMAFilter;          /**< MA filter for DC speed  */
    tFloat fltPllPiPropGain;                        /**< Proportional gain of PLL's P controller */
    tFrac32 f32ThAcEst;                             /**< PLL's internal phase with corretion from P controller */
    tFrac32 f32ThAcInc;                             /**< PLL's internal phase increment */
    tFloat fltAcOffset;                             /**< Detected offset of AC speed */
    /* Flux estimator */
    AMCLIB_FLUXESTIMAB_T_FLT pFluxEstim;            /**< Parameter structure for flux estimator */
    tFloat fltLd;                                   /**< D inductance of the motor */
    tFloat fltLq;                                   /**< Q inductance of the motor */
    tFloat fltWEl;                                  /**< State variable to store motor velocity */
    tFloat fltThErr;                                /**< Position error for ATO */
    tFloat fltThEstim;                              /**< Estimated angular position filtered by ATO */
    tFloat fltWEstim;                               /**< Estimated velocity filtered by ATO */
    AMCLIB_TRACK_OBSRV_T_FLT pTrackObsrv;           /**< Parameter structure for ATO */
    tFloat fltPsiRaw;                               /**< Estimated rotor flux */
    tFloat fltPsiFilt;                              /**< Filtered rotor flux */
    tFloat fltDtVDrop;                              /**< Dead time voltage drop */
    GDFLIB_FILTER_MA_T_FLT pFluxMAFilter;           /**< Parameter structure for MA filter for flux fitering */
    /* Steady state */
    tU32 u32SSTimeoutCnt;                           /**< Steady state timeout counter */
    tU32 u32SSBandCnt;                              /**< Steady state in band counter */
    tU32 u32SSTimeoutTime;                          /**< Steady state timeout */
    tU32 u32SSTime;                                 /**< Minimal time needed for stable behaviour */
    tFloat fltSSBandHalfMax;                        /**< Half of maximal deviation from mean steady value */
    tFloat fltSSBandHalf;                           /**< Half of allowed deviation from mean steady value */
    /* Measured data */
    tU16 u16MeasNum;                                /**< Number of current measuement */
    tFloat fltInertia;                              /**< Actual value of J */
    tFloat fltMeDcArr[2];                           /**< Array to store measuder values of Me */
    tFloat fltWDcArr[2];                            /**< Array to store measuder values of W */
    tFloat fltInertiaArr[2];                        /**< Array to store measuder values of J */
    tFloat fltGainFOC;                              /**< Correction coefficient for FOC gain */
    tFloat fltInvGainATO;                           /**< Correction coefficient for ATO gain */
    tFloat fltPhShiftCorr;                          /**< Correction coefficient for FOC and ATO phase shift */
  } AMCLIB_ESTIMBJ_INNERST_T_FLT;

/************************************************************************/
  /**
  @struct AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT "\AMCLIB_EstimBJ.h"

  @brief  Internal structure for Matlab Simulink rapid accelerator. No user-editable values.
  *//**********************************************************************/
  typedef struct
  {
    AMCLIB_ESTIMBJ_STATE_T pState;
    tBool bTwoPointMeas;
    tBool bFoundInjFreq;
    tU32 u32AlignTimer;
    tU32 u32TimerPreset;
    tFloat fltIReq;
    tFloat fltDCWReq1;
    tFloat fltDCWReq2;
    tFloat fltACWReq;
    tFloat fltWMax;
    tFloat fltPP;
    tFloat fltTs;
    tFloat fltFInj;
    tFloat fltWInj;
    /* Open Loop */
    tFloat fltWOl;
    tFloat fltThOl;
    GFLIB_RAMP_T_FLT pOLRamp;
    GFLIB_INTEGRATOR_TR_T_F32 pOLInteg;
    GDFLIB_FILTER_MA_T_FLT pIqMAFilter;
    SWLIBS_2Syst_FLT pThRealTransform;
    SWLIBS_2Syst_FLT pIDQRealFbck;
    /* Speed modulation */
    tFloat fltWDcReq;
    tFloat fltWAcMaxReq;
    tFloat fltIqDcReq;
    tFloat fltIqAcReq;
    tFloat fltIqAcMaxReq;
    GFLIB_RAMP_T_FLT pWDcReqRamp;
    GFLIB_RAMP_T_FLT pWAcMaxReqRamp;
    GFLIB_CONTROLLER_PIAW_P_T_FLT pWDcPI;
    GFLIB_CONTROLLER_PIAW_P_T_FLT pWAcMaxPI;
    tFloat fltWDcErr;
    tFloat fltWAcMaxErr;
    tFrac32 f32Theta;
    /* Current control */
    SWLIBS_2Syst_FLT pUDQReq;
    GFLIB_CONTROLLER_PIAW_R_T_FLT pCloopDPI;
    GFLIB_CONTROLLER_PIAW_R_T_FLT pCloopQPI;
    SWLIBS_2Syst_FLT pIDQReqCLoop;
    SWLIBS_2Syst_FLT pIDQFbckCLoop;
    tFloat fltThEl;
    SWLIBS_2Syst_FLT pThTransform;
    /* PLL */
    tFloat fltDcRaw;
    SWLIBS_2Syst_FLT pWABAcRaw;
    SWLIBS_2Syst_FLT pPllSinCosEst;
    tFloat fltDcFilt;
    tFloat fltAcFilt;
    tFloat fltWABEstErr;
    GDFLIB_FILTER_MA_T_FLT pPllDMAFilter;
    GDFLIB_FILTER_MA_T_FLT pPllQMAFilter;
    GDFLIB_FILTER_MA_T_FLT pPllDcMAFilter;
    tFloat fltPllPiPropGain;
    tFrac32 f32ThAcEst;
    tFrac32 f32ThAcInc;
    tFloat fltAcOffset;
    /* Flux estimator */
    AMCLIB_FLUXESTIMAB_T_FLT pFluxEstim;
    tFloat fltLd;
    tFloat fltLq;
    tFloat fltWEl;
    tFloat fltThErr;
    tFloat fltThEstim;
    tFloat fltWEstim;
    AMCLIB_TRACK_OBSRV_T_FLT pTrackObsrv;
    tFloat fltPsiFilt;
    tFloat fltPsiRaw;
    tFloat fltDtVDrop;
    GDFLIB_FILTER_MA_T_FLT pFluxMAFilter;
    /* Steady state */
    tU32 u32SSTimeoutCnt;
    tU32 u32SSBandCnt;
    tU32 u32SSTimeoutTime;
    tU32 u32SSTime;
    tFloat fltSSBandHalfMax;
    tFloat fltSSBandHalf;
    /* Measured data */
    tU16 u16MeasNum;
    tFloat fltInertia;
    tFloat fltMeDcArr[2];
    tFloat fltWDcArr[2];
    tFloat fltInertiaArr[2];
    tFloat fltGainFOC;
    tFloat fltInvGainATO;
    tFloat fltPhShiftCorr;
    tFloat fltKt;
    tFloat fltJ;
    tFloat fltA;
    tFloat fltB;
  } AMCLIB_ESTIMBJ_INNERST_SIM_T_FLT;

  /************************************************************************/
  /**
  @struct AMCLIB_ESTIMBJ_T_FLT "\AMCLIB_EstimBJ.h"

  @brief  Estimator configuration structure.
  *//**********************************************************************/
  typedef struct
  {
    tFloat fltKt; /**< Estimated torque constant [N·m/A]. */
    tFloat fltJ;  /**< Estimated moment of inertia [kg·m^2]. */
    tFloat fltA;  /**< Estimated static friction torque [N·m]. In "basic" mode returns zero. */
    tFloat fltB;  /**< Estimated friction coefficient [N·m·s/rad]. In "basic" mode returns zero. */
    AMCLIB_ESTIMBJ_INNERST_T_FLT pInnerState;  /**< Internal state of the RL estimator. No user-editable values. */
  } AMCLIB_ESTIMBJ_T_FLT;

/************************************************************************/
/**
@struct AMCLIB_ESTIMBJ_INIT_T_FLT "\AMCLIB_EstimBJ.h"

@brief  Initialization parameters of the RL estimator.
*//**********************************************************************/
  typedef struct
  {
    tBool  bEstimateFriction;      /**< Enable friction estimation. [-]. */
    tU32   u32SamplingFreq;        /**< Sampling frequency [1/s]. */
    tFloat fltIN;                  /**< Nominal current [A]. */
    tFloat fltWN;                  /**< Nominal velocity [rpm]. */
    tFloat fltPP;                  /**< Number of pole pairs [-]. */
    tFloat fltLd;                  /**< D-axis inductance [H]. */
    tFloat fltLq;                  /**< Q-axis inductance [H]. */
    tFloat fltRs;                  /**< Stator resistance [Ohm]. */
    tFloat fltDtVDrop;             /**< Dead time voltage drop of the power stage [V]. */
    /* Advanced paramteres */ 
    tFloat fltAlignTime;           /**< Time needed for rotor alignment [s]. */
    tFloat fltIReqOl;              /**< Required d-axis current for open loop startup [A]. */
    tFloat fltWStepOl;             /**< Required speed step for ramp [delta rpm/s] */
    tFloat fltDCWReq1;             /**< Required speed for measurment point 1 [rpm] */
    tFloat fltDCWReq2;             /**< Required speed for measurment point 2 [rpm] */
    tFloat fltDcPiPropGain;        /**< Proportional gain of the speed loops DC controller [-]. */
    tFloat fltDcPiIntegGain;       /**< Inegral gain of the speed loops DC controller [-]. */
    tFloat fltAcPiPropGain;        /**< Proportional gain of the speed loops AC controller [-]. */
    tFloat fltAcPiIntegGain;       /**< Inegral gain of the speed loops AC controller [-]. */
  } AMCLIB_ESTIMBJ_INIT_T_FLT;

/** Default configuration for #AMCLIB_EstimBJInit_FLT. This is legacy macro and it is present only to ensure backwards comaptibility. Use ESTIMBJ_INIT_CFG1_FLT or ESTIMBJ_INIT_CFG2_FLT instead.
 Arguments must adhere to the data types of \ref AMCLIB_ESTIMBJ_INIT_T_FLT.
 Arguments must adhere to the data types of \ref AMCLIB_ESTIMBJ_INIT_T_FLT.
 \param fs Sampling frequency [1/s].
 \param In Nominal current of the motor [A].
 \param Wn Nominal velocity of the motor [rpm].
 \param pp Number of pole pairs [-].
 \param Ld D-axis inductance [H].
 \param Lq Q-axis inductance [H].
 \param Rs Stator resistance [Ohm].
 \param Udt Dead time voltage drop of the power stage [V]. */
#define ESTIMBJ_INIT_DEFAULT_FLT(fs, In, Wn, pp, Ld, Lq, Rs, Udt)  (AMCLIB_ESTIMBJ_INIT_T_FLT){FALSE,((tU32)fs),((tFloat)In),((tFloat)Wn),((tFloat)pp),((tFloat)Ld),((tFloat)Lq),((tFloat)Rs),((tFloat)Udt),0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}

/****************************************************************************
* Exported function prototypes
****************************************************************************/
extern AMCLIB_ESTIMBJINIT_RET_T AMCLIB_EstimBJInit_FLT(AMCLIB_ESTIMBJ_T_FLT *const pCtrl, AMCLIB_ESTIMBJ_INIT_T_FLT pParam);

extern AMCLIB_ESTIMBJ_RET_T AMCLIB_EstimBJ_FLT(SWLIBS_2Syst_FLT *const pUAlBeReq,
    const SWLIBS_2Syst_FLT *const pIAlBeFbck, tFloat fltUDcBus, AMCLIB_ESTIMBJ_T_FLT *const pCtrl);

#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif/* AMCLIB_ESTIMBJ_H */
