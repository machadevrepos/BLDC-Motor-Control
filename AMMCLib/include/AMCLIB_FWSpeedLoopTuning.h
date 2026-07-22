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
* @file       AMCLIB_FWSpeedLoopTuning.h
*
* @brief      Header file for AMCLIB_FWSpeedLoopTuning function
*
******************************************************************************/
#ifndef AMCLIB_FWSPEEDLOOPTUNING_H
#define AMCLIB_FWSPEEDLOOPTUNING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "AMCLIB_FWSpeedLoop.h"
#include "GDFLIB_FilterMATuning.h"
#include "GFLIB_RampTuning.h"
#include "GFLIB_Acos.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define AMCLIB_FWSpeedLoopTuning(...)     macro_dispatcher(AMCLIB_FWSpeedLoopTuning, __VA_ARGS__)(__VA_ARGS__)     /* The function calculates the parameters of speed-loop with field-weakening function (D-axis PI controller, Q-axis PI controller). */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_FW_SPEED_LOOP_TUNING_T                        AMCLIB_FW_SPEED_LOOP_TUNING_T_FLT                        /**< Definition of AMCLIB_FW_SPEED_LOOP_TUNING_T as alias for AMCLIB_FW_SPEED_LOOP_TUNING_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define AMCLIB_FW_SPEED_LOOP_TUNING_DEFAULT                  AMCLIB_FW_SPEED_LOOP_TUNING_DEFAULT_FLT                  /**< Definition of AMCLIB_FW_SPEED_LOOP_TUNING_DEFAULT as alias for AMCLIB_FW_SPEED_LOOP_TUNING_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DAMMCLIB00139 */
    #define AMCLIB_FWSpeedLoopTuning_Dsptchr_2(pCtrl,pParam)     AMCLIB_FWSpeedLoopTuning_Dsptchr_3(pCtrl,pParam,FLT)     /* Function dispatcher for AMCLIB_FWSpeedLoopTuning_Dsptchr_2, do not modify!!! */
  #endif

  #define AMCLIB_FWSpeedLoopTuning_Dsptchr_3(pCtrl,pParam,Impl)    AMCLIB_FWSpeedLoopTuning_Dsptchr_(pCtrl,pParam,Impl)     /* Function dispatcher for AMCLIB_FWSpeedLoopTuning_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DAMMCLIB00137 */
  #define AMCLIB_FWSpeedLoopTuning_Dsptchr_(pCtrl,pParam,Impl)     AMCLIB_FWSpeedLoopTuning_##Impl(pCtrl,pParam)            /* Function dispatcher for AMCLIB_FWSpeedLoopTuning_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/************************************************************************//**
@enum   AMCLIB_FW_SPEED_LOOP_TUNING_TNGMTD_T

@brief  Enum type of speed-loop with field-weakening tuning method for the #AMCLIB_FWSpeedLoopTuning_FLT.
*//*************************************************************************/
  typedef enum
  {
    AMCLIB_FWSL_POLE_PLACEMENT = 0,  /**< Pole-placement tuning method for speed-loop with field-weakening (default) */
  }AMCLIB_FW_SPEED_LOOP_TUNING_TNGMTD_T;
  
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define AMCLIB_FW_SPEED_LOOP_TUNING_DEFAULT_FLT {(AMCLIB_FW_SPEED_LOOP_TUNING_TNGMTD_T)0, (AMCLIB_FW_SPEED_LOOP_TUNING_TNGMTD_T)0, (tFloat)0, (tFloat)0, (tFloat)0, (tU32)0, (tU32)0, (tFloat)0, (tFloat)0, (tBool)FALSE, (tU32)0, (tFloat)0, (tBool)FALSE, (tU32)0, (tFloat)0, (tBool)FALSE, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tU32)0, (tBool)FALSE, (tBool)FALSE, (tBool)FALSE, (tBool)FALSE, (tBool)FALSE, (tAmmclibTuningMode)0, (tAmmclibTuningMode)0}     /**< Default value for AMCLIB_FW_SPEED_LOOP_TUNING_T_FLT. */
  /*************************************************************************/
  /**
  @struct AMCLIB_FW_SPEED_LOOP_TUNING_MOTPRM_T_FLT "\AMCLIB_FWSpeedLoopTuning.h" 

  @brief  Structure containing motor electrical parameters pp, Kt, J, B for the speed-loop with field-weakening tuning function implemented in #AMCLIB_FWSpeedLoopTuning_FLT.
  *//***********************************************************************/
  typedef struct{    
    tFloat             fltKt; /**< Torque constant [Nm/A]. Should not be negative or equal to 0. */
    tFloat             fltJ; /**< Moment of inertia [kg.m2]. Should not be negative or equal to 0.*/
    tFloat             fltB; /**< Viscous friction [Nm.s/rad]. Should not be negative.  */
    tU32               u32pp; /**< Number of motor pole-pairs [-]. Should not be negative or equal to 0. */
  }AMCLIB_FW_SPEED_LOOP_TUNING_MOTPRM_T_FLT;

  /*************************************************************************/
  /**
  @struct AMCLIB_FW_SPEED_LOOP_TUNING_T_FLT "\AMCLIB_FWSpeedLoopTuning.h" 

  @brief  Structure containing speed-loop with field-weakening tuning mode and tuning method configuration, motor parameters, limitation flags, min max limits for f0, sampling frequency, bandwidth frequencies, attenuations, ramp parameters, MA filters parameters, field-weakening parametrs for the speed-loop with field-weakening tuning function implemented in #AMCLIB_FWSpeedLoopTuning_FLT.
  *//***********************************************************************/
  /* @remarks Implements DAMMCLIB00136, DAMMCLIB00135 */
  typedef struct{
    AMCLIB_FW_SPEED_LOOP_TUNING_TNGMTD_T  pSlTuningMethod;  /**< Speed-loop tuning method. */
    AMCLIB_FW_SPEED_LOOP_TUNING_TNGMTD_T  pFwTuningMethod;  /**< Field-weakening tuning method. */
    AMCLIB_FW_SPEED_LOOP_TUNING_MOTPRM_T_FLT  pMotorParam;  /**< Speed-loop with FW motor parameters. */
    GFLIB_RAMPTUNING_T_FLT  pSlRamp;  /**< Speed-loop ramp control structure. */
    GDFLIB_FILTER_MA_TUNING_T_FLT  pSpdFiltMA;  /**< Speed-loop speed feedback MA filter control structure. */
    GDFLIB_FILTER_MA_TUNING_T_FLT  pFwFiltMA;  /**< Speed-loop field-weakening MA filter control structure. */ 
    tFloat  fltSlF0Min;  /**< Speed-loop f0 min limit -> informative intermediate calculation. */
    tFloat  fltFwF0Min;  /**< Field-weakening f0 min limit -> informative intermediate calculation. */
    tFloat  fltF0Max;  /**< Speed-loop f0 max limit -> informative intermediate calculation. */
    tFloat  fltSlF0;  /**< Speed-loop bandwidth frequency [Hz]. Should not be negative. */
    tFloat  fltFwF0;  /**< Field-weakening bandwidth frequency [Hz]. Should not be negative. */
    tFloat  fltSlAtten;  /**< Speed-loop attenuation [-]. Should not be negative. */
    tFloat  fltFwAtten;  /**< Field-weakening attenuation [-]. Should not be negative. */
    tFloat  fltRampUpMechRPMpSec; /**< Speed-loop feed-forward ramp-up coefficient in mechanical RPM/sec. */
    tFloat  fltRampDownMechRPMpSec; /**< Speed-loop feed-forward ramp-down coefficient in mechanical RPM/sec. */
    tFloat  fltSpdFiltMAcutoffFreq; /**< Feedback speed MA filter cut-off frequency [Hz]. Should not be negative. */
    tFloat  fltFwFiltMAcutoffFreq; /**< Field-weakening MA filter cut-off frequency [Hz]. Should not be negative. */
    tFloat  fltSpeedPIUpLim; /**< Speed-loop PI controller upper limit [A]. Should be bigger than fltSpeedPILoLim or equal. */
    tFloat  fltSpeedPILoLim; /**< Speed-loop PI controller lower limit [A]. Should be smaller than fltSpeedPIUpLim or equal. */
    tFloat  fltIDMax; /**< Maximum permitted negative d-axis current for field weakening [A]. */
    tFloat  fltUDCBMax; /**< Maximum DC bus voltage scale [V]. Should not be negative. */
    tFloat  fltIMax; /**< Maximum phase current [A]. Should not be negative. */
    tFloat  fltSlZCCutoffFreq; /**< Speed-loop zero-cancellation filter cut-off frequency [Hz]. */  
    tU32  u32Fs; /**< Speed-loop with FW sampling frequency [Hz]. Should not be negative or equal to 0. */   
    tBool  bSlAtnLimitFlag; /**< Speed-loop attenuation limit reached - flag. */
    tBool  bFwAtnLimitFlag; /**< Field-weakening attenuation limit reached - flag. */
    tBool  bSlF0LimitFlag;  /**< Speed-loop f0 limit reached - flag. */
    tBool  bFwF0LimitFlag;  /**< Field-weakening f0 limit reached - flag. */
    tBool  bFwiNotPlauFlag; /**< Field-weakening controller parameters IMax and IDMax are not plausible - flag. */    
    tAmmclibTuningMode  pSlTuningMode; /**< Tuning mode for speed-loop -> 0: AMMCLIB_TUNING_MODE_BASIC (f0 and attenuation set by algorithm); 1: AMMCLIB_TUNING_MODE_EXPERT (f0 and attenuation set by user). */
    tAmmclibTuningMode  pFwTuningMode; /**< Tuning mode for field-weakening -> 0: AMMCLIB_TUNING_MODE_BASIC (f0 and attenuation set by algorithm); 1: AMMCLIB_TUNING_MODE_EXPERT (f0 and attenuation set by user). */ 
  }AMCLIB_FW_SPEED_LOOP_TUNING_T_FLT;
  

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_FWSpeedLoopTuning_FLT(AMCLIB_FW_SPEED_LOOP_T_FLT *const pCtrl, AMCLIB_FW_SPEED_LOOP_TUNING_T_FLT * pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* AMCLIB_FWSPEEDLOOPTUNING_H */
