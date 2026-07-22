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
* @file       AMCLIB_BemfObsrvDQTuning.h
*
* @brief      Header file for AMCLIB_BemfObsrvDQTuning function
*
******************************************************************************/
#ifndef AMCLIB_BEMFOBSRVDQTUNING_H
#define AMCLIB_BEMFOBSRVDQTUNING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "AMCLIB_BemfObsrvDQ.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define AMCLIB_BemfObsrvDQTuning(...)     macro_dispatcher(AMCLIB_BemfObsrvDQTuning, __VA_ARGS__)(__VA_ARGS__)     /* The function calculates the parameters of BEMF observer function (D-axis PI controller, Q-axis PI controller). */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_BEMF_OBSRV_DQ_TUNING_T                        AMCLIB_BEMF_OBSRV_DQ_TUNING_T_FLT                        /**< Definition of AMCLIB_BEMF_OBSRV_DQ_TUNING_T as alias for AMCLIB_BEMF_OBSRV_DQ_TUNING_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define AMCLIB_BEMF_OBSRV_DQ_TUNING_DEFAULT                  AMCLIB_BEMF_OBSRV_DQ_TUNING_DEFAULT_FLT                  /**< Definition of AMCLIB_BEMF_OBSRV_DQ_TUNING_DEFAULT as alias for AMCLIB_BEMF_OBSRV_DQ_TUNING_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DAMMCLIB00133 */
    #define AMCLIB_BemfObsrvDQTuning_Dsptchr_2(pCtrl,pParam)     AMCLIB_BemfObsrvDQTuning_Dsptchr_3(pCtrl,pParam,FLT)     /* Function dispatcher for AMCLIB_BemfObsrvDQTuning_Dsptchr_2, do not modify!!! */
  #endif

  #define AMCLIB_BemfObsrvDQTuning_Dsptchr_3(pCtrl,pParam,Impl)    AMCLIB_BemfObsrvDQTuning_Dsptchr_(pCtrl,pParam,Impl)     /* Function dispatcher for AMCLIB_BemfObsrvDQTuning_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DAMMCLIB00131 */
  #define AMCLIB_BemfObsrvDQTuning_Dsptchr_(pCtrl,pParam,Impl)     AMCLIB_BemfObsrvDQTuning_##Impl(pCtrl,pParam)            /* Function dispatcher for AMCLIB_BemfObsrvDQTuning_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/************************************************************************//**
@enum   AMCLIB_BEMF_OBSRV_DQ_TUNING_TNGMTD_T

@brief  Enum type of BEMF observer tuning method for the #AMCLIB_BemfObsrvDQTuning.
*//*************************************************************************/
  typedef enum
  {
    AMCLIB_BEMF_OBSRV_INVERSE_DYNAMIC = 0,  /**< Tuning method: Inverse dynamic (default) */
    AMCLIB_BEMF_OBSRV_POLE_PLACEMENT = 1,  /**< Tuning method: Pole placement */
  }AMCLIB_BEMF_OBSRV_DQ_TUNING_TNGMTD_T;  
  
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define AMCLIB_BEMF_OBSRV_DQ_TUNING_DEFAULT_FLT {(tAmmclibTuningMode)0, (AMCLIB_BEMF_OBSRV_DQ_TUNING_TNGMTD_T)0, (tFloat)0, (tFloat)0, (tFloat)0, (tBool)FALSE, (tBool)FALSE, (tFloat)0, (tFloat)0, (tU32)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0}     /**< Default value for AMCLIB_BEMF_OBSRV_DQ_TUNING_T_FLT. */
  /*************************************************************************/
  /**
  @struct AMCLIB_BEMF_OBSRV_DQ_TUNING_MOTPRM_T_FLT "\AMCLIB_BemfObsrvDQTuning.h" 

  @brief  Structure containing motor parameters used by BEMF observer tuning function.
  *//***********************************************************************/
  typedef struct{
    tFloat fltRs; /**< Resistance of one stator phase [[Ω]]. Should not be negative. */
    tFloat fltLd; /**< d-axis inductance [H]. Should not be negative. */
    tFloat fltLq; /**< q-axis inductance [H]. Should not be negative. */
  }AMCLIB_BEMF_OBSRV_DQ_TUNING_MOTPRM_T_FLT;

  /*************************************************************************/
  /**
  @struct AMCLIB_BEMF_OBSRV_DQ_TUNING_T_FLT "\AMCLIB_BemfObsrvDQTuning.h" 

  @brief  Structure containing BEMF observer tuning mode and tuning method configuration, motor parameters, limitation flags, min max limits for f0, sampling frequency, bandwidth frequency, attenuation and Kp, Ki internal calculations for the BEMF observer tuning function in both dq axis implemented in #AMCLIB_BemfObsrvDQTuning_FLT.
  *//***********************************************************************/
  /* @remarks Implements DAMMCLIB00130, DAMMCLIB00129 */
  typedef struct{
    tAmmclibTuningMode pTuningMode; /**< BEMF observer tuning mode configuration (AMMCLIB_TUNING_MODE_BASIC(0) or AMMCLIB_TUNING_MODE_EXPERT(1)). */
    AMCLIB_BEMF_OBSRV_DQ_TUNING_TNGMTD_T pTuningMethod; /**< BEMF observer tuning method configuration (Inverse dynamic(0) or Pole-placement(1)). */
    AMCLIB_BEMF_OBSRV_DQ_TUNING_MOTPRM_T_FLT pMotorParam; /**< Motor parameters structure (Rs, Ld, Lq) required for BEMF observer tuning. Should not be negative or equal to 0. */
    tBool  bAtnLimitFlag; /**< Attenuation limitation flag. */  
    tBool  bF0LimitFlag; /**< f0 limitation flag. */
    tFloat fltF0Min; /**< f0 min limit -> informative intermediate calculation. */
    tFloat fltF0Max; /**< f0 max limit -> informative intermediate calculation. */
    tU32   u32Fs; /**< BEMF observer sampling frequency [Hz]. Should not be negative or equal to 0. */
    tFloat fltF0; /**< BEMF observer bandwidth frequency [Hz]. Should not be negative. */
    tFloat fltAtten; /**< BEMF observer attenuation [-]. Should not be negative. */
    tFloat fltKpDQ; /**< Proportional gain of BEMF observer PI controller in D-axis -> informative intermediate calculation. */
    tFloat fltKiDQ; /**< Integral gain of BEMF observer PI controller in D-axis -> informative intermediate calculation. */
    tFloat fltPIUpLim; /**< BEMF observer PI controller upper limit. Should be bigger than fltPILoLim or equal. */
    tFloat fltPILoLim; /**< BEMF observer PI controller lower limit. Should be smaller than fltPIUpLim or equal.*/
  }AMCLIB_BEMF_OBSRV_DQ_TUNING_T_FLT;
  

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_BemfObsrvDQTuning_FLT(AMCLIB_BEMF_OBSRV_DQ_T_FLT *const pCtrl, AMCLIB_BEMF_OBSRV_DQ_TUNING_T_FLT *pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* AMCLIB_BEMFOBSRVDQTUNING_H */
