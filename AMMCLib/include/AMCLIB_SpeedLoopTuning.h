/******************************************************************************
*
*   Copyright 2025-2026 NXP
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
* @file       AMCLIB_SpeedLoopTuning.h
*
* @brief      Header file for AMCLIB_SpeedLoopTuning function
*
******************************************************************************/
#ifndef AMCLIB_SPEEDLOOPTUNING_H
#define AMCLIB_SPEEDLOOPTUNING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "AMCLIB_SpeedLoop.h"
#include "GDFLIB_FilterMATuning.h"
#include "GFLIB_RampTuning.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define AMCLIB_SpeedLoopTuning(...)     macro_dispatcher(AMCLIB_SpeedLoopTuning, __VA_ARGS__)(__VA_ARGS__)     /* The function calculates the parameters of speed-loop function (Q-axis PI controller). */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_SPEED_LOOP_TUNING_T                        AMCLIB_SPEED_LOOP_TUNING_T_FLT                        /**< Definition of AMCLIB_SPEED_LOOP_TUNING_T as alias for AMCLIB_SPEED_LOOP_TUNING_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define AMCLIB_SPEED_LOOP_TUNING_DEFAULT                  AMCLIB_SPEED_LOOP_TUNING_DEFAULT_FLT                  /**< Definition of AMCLIB_SPEED_LOOP_TUNING_DEFAULT as alias for AMCLIB_SPEED_LOOP_TUNING_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DAMMCLIB00151 */
    #define AMCLIB_SpeedLoopTuning_Dsptchr_2(pCtrl,pParam)     AMCLIB_SpeedLoopTuning_Dsptchr_3(pCtrl,pParam,FLT)     /* Function dispatcher for AMCLIB_SpeedLoopTuning_Dsptchr_2, do not modify!!! */
  #endif

  #define AMCLIB_SpeedLoopTuning_Dsptchr_3(pCtrl,pParam,Impl)    AMCLIB_SpeedLoopTuning_Dsptchr_(pCtrl,pParam,Impl)     /* Function dispatcher for AMCLIB_SpeedLoopTuning_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DAMMCLIB00149 */
  #define AMCLIB_SpeedLoopTuning_Dsptchr_(pCtrl,pParam,Impl)     AMCLIB_SpeedLoopTuning_##Impl(pCtrl,pParam)            /* Function dispatcher for AMCLIB_SpeedLoopTuning_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/************************************************************************//**
@enum   AMCLIB_SPEED_LOOP_TUNING_TNGMTD_T

@brief  Enum type of speed-loop tuning method for the #AMCLIB_SpeedLoopTuning_FLT.
*//*************************************************************************/
  typedef enum
  {
    AMCLIB_SL_POLE_PLACEMENT = 0,  /**< Pole-placement tuning method for speed-loop (default) */
  }AMCLIB_SPEED_LOOP_TUNING_TNGMTD_T;
  
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define AMCLIB_SPEED_LOOP_TUNING_DEFAULT_FLT {(AMCLIB_SPEED_LOOP_TUNING_TNGMTD_T)0, (tFloat)0, (tFloat)0, (tFloat)0, (tU32)0, (tU32)0, (tFloat)0, (tFloat)0, (tBool)FALSE, (tU32)0, (tFloat)0, (tBool)FALSE, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tU32)0, (tBool)FALSE, (tBool)FALSE, (tAmmclibTuningMode)0}     /**< Default value for AMCLIB_SPEED_LOOP_TUNING_T_FLT. */
  /*************************************************************************/
  /**
  @struct AMCLIB_SPEED_LOOP_TUNING_MOTPRM_T_FLT "\AMCLIB_SpeedLoopTuning.h" 

  @brief  Structure containing motor electrical parameters pp, Kt, J, B for the speed-loop tuning function implemented in #AMCLIB_SpeedLoopTuning_FLT.
  *//***********************************************************************/
  typedef struct{    
    tFloat             fltKt; /**< Torque constant [Nm/A]. Should not be negative or equal to 0. */
    tFloat             fltJ; /**< Moment of inertia [kg.m2]. Should not be negative or equal to 0.*/
    tFloat             fltB; /**< Viscous friction [Nm.s/rad]. Should not be negative.  */
    tU32               u32pp; /**< Number of motor pole-pairs [-]. Should not be negative or equal to 0. */
  }AMCLIB_SPEED_LOOP_TUNING_MOTPRM_T_FLT;

  /*************************************************************************/
  /**
  @struct AMCLIB_SPEED_LOOP_TUNING_T_FLT "\AMCLIB_SpeedLoopTuning.h" 

  @brief  Structure containing speed-loop tuning mode and tuning method configuration, motor parameters, limitation flags, min max limits for f0, sampling frequency, bandwidth frequencies, attenuations, ramp parameters, MA filter parameters for the speed-loop tuning function implemented in #AMCLIB_SpeedLoopTuning_FLT.
  *//***********************************************************************/
  /* @remarks Implements DAMMCLIB00148, DAMMCLIB00147 */
  typedef struct{
    AMCLIB_SPEED_LOOP_TUNING_TNGMTD_T  pTuningMethod;  /**< Speed-loop tuning method. */
    AMCLIB_SPEED_LOOP_TUNING_MOTPRM_T_FLT  pMotorParam;  /**< Speed-loop motor parameters. */
    GFLIB_RAMPTUNING_T_FLT  pSlRamp;  /**< Speed-loop ramp control structure. */
    GDFLIB_FILTER_MA_TUNING_T_FLT  pSpdFiltMA;  /**< Speed-loop speed feedback MA filter control structure. */
    tFloat  fltF0Min;  /**< Speed-loop f0 min limit -> informative intermediate calculation. */
    tFloat  fltF0Max;  /**< Speed-loop f0 max limit -> informative intermediate calculation. */
    tFloat  fltF0;  /**< Speed-loop bandwidth frequency [Hz]. Should not be negative. */
    tFloat  fltAtten;  /**< Speed-loop attenuation [-]. Should not be negative. */
    tFloat  fltRampUpMechRPMpSec; /**< Speed-loop feed-forward ramp-up coefficient in mechanical RPM/sec. */
    tFloat  fltRampDownMechRPMpSec; /**< Speed-loop feed-forward ramp-down coefficient in mechanical RPM/sec. */
    tFloat  fltSpdFiltMAcutoffFreq; /**< Feedback speed MA filter cut-off frequency [Hz]. Should not be negative. */
    tFloat  fltSpeedPIUpLim; /**< Speed-loop PI controller upper limit [A]. Should be bigger than fltSpeedPILoLim or equal. */
    tFloat  fltSpeedPILoLim; /**< Speed-loop PI controller lower limit [A]. Should be smaller than fltSpeedPIUpLim or equal. */
    tFloat  fltSlZCCutoffFreq; /**< Speed-loop zero-cancellation filter cut-off frequency [Hz]. */  
    tU32  u32Fs; /**< Speed-loop sampling frequency [Hz]. Should not be negative or equal to 0. */   
    tBool  bAtnLimitFlag; /**< Speed-loop attenuation limit reached - flag. */
    tBool  bF0LimitFlag;  /**< Speed-loop f0 limit reached - flag. */
    tAmmclibTuningMode  pTuningMode; /**< Tuning mode for speed-loop -> 0: AMMCLIB_TUNING_MODE_BASIC (f0 and attenuation set by algorithm); 1: AMMCLIB_TUNING_MODE_EXPERT (f0 and attenuation set by user). */
  }AMCLIB_SPEED_LOOP_TUNING_T_FLT;
  

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_SpeedLoopTuning_FLT(AMCLIB_SPEED_LOOP_T_FLT *const pCtrl, AMCLIB_SPEED_LOOP_TUNING_T_FLT * pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* AMCLIB_SPEEDLOOPTUNING_H */
