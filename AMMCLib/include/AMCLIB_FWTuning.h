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
* @file       AMCLIB_FWTuning.h
*
* @brief      Header file for AMCLIB_FWTuning function
*
******************************************************************************/
#ifndef AMCLIB_FWTUNING_H
#define AMCLIB_FWTUNING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "AMCLIB_FW.h"
#include "GDFLIB_FilterMATuning.h"
#include "GFLIB_Acos.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define AMCLIB_FWTuning(...)     macro_dispatcher(AMCLIB_FWTuning, __VA_ARGS__)(__VA_ARGS__)     /* The function calculates the parameters of field-weakening function. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_FW_TUNING_T                        AMCLIB_FW_TUNING_T_FLT                        /**< Definition of AMCLIB_FW_TUNING_T as alias for AMCLIB_FW_TUNING_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define AMCLIB_FW_TUNING_DEFAULT                  AMCLIB_FW_TUNING_DEFAULT_FLT                  /**< Definition of AMCLIB_FW_TUNING_DEFAULT as alias for AMCLIB_FW_TUNING_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DAMMCLIB00157 */
    #define AMCLIB_FWTuning_Dsptchr_2(pCtrl,pParam)     AMCLIB_FWTuning_Dsptchr_3(pCtrl,pParam,FLT)     /* Function dispatcher for AMCLIB_FWTuning_Dsptchr_2, do not modify!!! */
  #endif

  #define AMCLIB_FWTuning_Dsptchr_3(pCtrl,pParam,Impl)    AMCLIB_FWTuning_Dsptchr_(pCtrl,pParam,Impl)     /* Function dispatcher for AMCLIB_FWTuning_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DAMMCLIB00155 */
  #define AMCLIB_FWTuning_Dsptchr_(pCtrl,pParam,Impl)     AMCLIB_FWTuning_##Impl(pCtrl,pParam)            /* Function dispatcher for AMCLIB_FWTuning_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/************************************************************************//**
@enum   AMCLIB_FW_TUNING_TNGMTD_T

@brief  Enum type of field-weakening tuning method for the #AMCLIB_FWTuning_FLT.
*//*************************************************************************/
  typedef enum
  {
    AMCLIB_FW_POLE_PLACEMENT = 0,  /**< Pole-placement tuning method for field-weakening (default) */
  }AMCLIB_FW_TUNING_TNGMTD_T;
  
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define AMCLIB_FW_TUNING_DEFAULT_FLT {(AMCLIB_FW_TUNING_TNGMTD_T)0, (tFloat)0, (tFloat)0, (tFloat)0, (tU32)0, (tU32)0, (tFloat)0, (tBool)FALSE, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tU32)0, (tBool)FALSE, (tBool)FALSE, (tBool)FALSE, (tAmmclibTuningMode)0}     /**< Default value for AMCLIB_FW_TUNING_T_FLT. */
  /*************************************************************************/
  /**
  @struct AMCLIB_FW_TUNING_MOTPRM_T_FLT "\AMCLIB_FWTuning.h" 

  @brief  Structure containing motor electrical parameters pp, Kt, J, B for the field-weakening tuning function implemented in #AMCLIB_FWTuning_FLT.
  *//***********************************************************************/
  typedef struct{    
    tFloat             fltKt; /**< Torque constant [Nm/A]. Should not be negative or equal to 0. */
    tFloat             fltJ; /**< Moment of inertia [kg.m2]. Should not be negative or equal to 0.*/
    tFloat             fltB; /**< Viscous friction [Nm.s/rad]. Should not be negative.  */
    tU32               u32pp; /**< Number of motor pole-pairs [-]. Should not be negative or equal to 0. */
  }AMCLIB_FW_TUNING_MOTPRM_T_FLT;

  /*************************************************************************/
  /**
  @struct AMCLIB_FW_TUNING_T_FLT "\AMCLIB_FWTuning.h" 

  @brief  Structure containing field-weakening tuning mode and tuning method configuration, motor parameters, limitation flags, min max limits for f0, sampling frequency, bandwidth frequencies, attenuations, MA filter parameters, field-weakening parametrs for the field-weakening tuning function implemented in #AMCLIB_FWTuning_FLT.
  *//***********************************************************************/
  /* @remarks Implements DAMMCLIB00154, DAMMCLIB00153 */
  typedef struct{
    AMCLIB_FW_TUNING_TNGMTD_T  pTuningMethod;  /**< Field-weakening tuning method. */
    AMCLIB_FW_TUNING_MOTPRM_T_FLT  pMotorParam;  /**< Field-weakening motor parameters. */
    GDFLIB_FILTER_MA_TUNING_T_FLT  pFwFiltMA;  /**< Field-weakening MA filter control structure. */
    tFloat  fltF0Min;  /**< Field-weakening f0 min limit -> informative intermediate calculation. */
    tFloat  fltF0Max;  /**< Field-weakening f0 max limit -> informative intermediate calculation. */
    tFloat  fltF0;  /**< Field-weakening bandwidth frequency [Hz]. Should not be negative. */
    tFloat  fltAtten;  /**< Field-weakening attenuation [-]. Should not be negative. */
    tFloat  fltFwFiltMAcutoffFreq; /**< Field-weakening MA filter cut-off frequency [Hz]. Should not be negative. */
    tFloat  fltIDMax; /**< Maximum permitted negative d-axis current for field weakening [A]. */
    tFloat  fltUDCBMax; /**< Maximum DC bus voltage scale [V]. Should not be negative. */
    tFloat  fltIMax; /**< Maximum phase current [A]. Should not be negative. */
    tU32  u32Fs; /**< FW sampling frequency [Hz]. Should not be negative or equal to 0. */   
    tBool  bAtnLimitFlag; /**< Field-weakening attenuation limit reached - flag. */
    tBool  bF0LimitFlag;  /**< Field-weakening f0 limit reached - flag. */
    tBool  bFwiNotPlauFlag; /**< Field-weakening controller parameters IMax and IDMax are not plausible - flag. */    
    tAmmclibTuningMode  pTuningMode; /**< Tuning mode for field-weakening -> 0: AMMCLIB_TUNING_MODE_BASIC (f0 and attenuation set by algorithm); 1: AMMCLIB_TUNING_MODE_EXPERT (f0 and attenuation set by user). */ 
  }AMCLIB_FW_TUNING_T_FLT;
  

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_FWTuning_FLT(AMCLIB_FW_T_FLT *const pCtrl, AMCLIB_FW_TUNING_T_FLT * pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* AMCLIB_FWTUNING_H */
