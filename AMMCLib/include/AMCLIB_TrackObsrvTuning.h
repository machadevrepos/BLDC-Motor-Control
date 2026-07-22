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
* @file       AMCLIB_TrackObsrvTuning.h
*
* @brief      Header file for AMCLIB_TrackObsrvTuning function
*
******************************************************************************/
#ifndef AMCLIB_TRACKOBSRVTUNING_H
#define AMCLIB_TRACKOBSRVTUNING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "AMCLIB_TrackObsrv.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define AMCLIB_TrackObsrvTuning(...)     macro_dispatcher(AMCLIB_TrackObsrvTuning, __VA_ARGS__)(__VA_ARGS__)     /* The function calculates the parameters of tracking observer (CC1, CC2, C1, UpperLimit, LowerLimit). */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_TRACK_OBSRV_TUNING_T                        AMCLIB_TRACK_OBSRV_TUNING_T_FLT                        /**< Definition of AMCLIB_TRACK_OBSRV_TUNING_T as alias for AMCLIB_TRACK_OBSRV_TUNING_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define AMCLIB_TRACK_OBSRV_TUNING_DEFAULT                  AMCLIB_TRACK_OBSRV_TUNING_DEFAULT_FLT                  /**< Definition of AMCLIB_TRACK_OBSRV_TUNING_DEFAULT as alias for AMCLIB_TRACK_OBSRV_TUNING_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DAMMCLIB00121 */
    #define AMCLIB_TrackObsrvTuning_Dsptchr_2(pCtrl,pParam)     AMCLIB_TrackObsrvTuning_Dsptchr_3(pCtrl,pParam,FLT)     /* Function dispatcher for AMCLIB_TrackObsrvTuning_Dsptchr_2, do not modify!!! */
  #endif

  #define AMCLIB_TrackObsrvTuning_Dsptchr_3(pCtrl,pParam,Impl)    AMCLIB_TrackObsrvTuning_Dsptchr_(pCtrl,pParam,Impl)     /* Function dispatcher for AMCLIB_TrackObsrvTuning_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DAMMCLIB00119 */
  #define AMCLIB_TrackObsrvTuning_Dsptchr_(pCtrl,pParam,Impl)     AMCLIB_TrackObsrvTuning_##Impl(pCtrl,pParam)            /* Function dispatcher for AMCLIB_TrackObsrvTuning_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define AMCLIB_TRACK_OBSRV_TUNING_DEFAULT_FLT {(tAmmclibTuningMode)0, (tU32)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0, (tFloat)0}     /**< Default value for AMCLIB_TRACK_OBSRV_TUNING_T_FLT. */

  /*************************************************************************/
  /**
  @struct AMCLIB_TRACK_OBSRV_TUNING_T_FLT "\AMCLIB_TrackObsrvTuning.h" 

  @brief  Structure containing tracking observer tuning mode configuration, sampling frequency, bandwidth frequency, attenuation, upper/lower limit and Kp, Ki internal calculations for the tracking observer tuning function implemented in #AMCLIB_TrackObsrvTuning_FLT.
  *//***********************************************************************/
  /* @remarks Implements DAMMCLIB00118, DAMMCLIB00117 */
  typedef struct{
    tAmmclibTuningMode pTuningMode; /**< Tracking observer tuning mode configuration (AMMCLIB_TUNING_MODE_BASIC(0) or AMMCLIB_TUNING_MODE_EXPERT(1)). */
    tU32   u32Fs; /**< Tracking observer sampling frequency [Hz]. Should not be negative or equal to 0. */
    tFloat fltF0; /**< Tracking observer bandwidth frequency [Hz]. Should not be negative. */
    tFloat fltAtten; /**< Tracking observer attenuation [-]. Should not be negative. */
    tFloat fltPIUpLim; /**< Tracking observer PI controller upper limit. Should be bigger than fltPILoLim or equal. */
    tFloat fltPILoLim; /**< Tracking observer PI controller lower limit. Should be smaller than fltPIUpLim or equal.*/
    tFloat fltKp; /**< Proportional gain of tracking observer PI controller - informative intermediate calculation. */
    tFloat fltKi; /**< Integral gain of tracking observer PI controller - informative intermediate calculation. */
  }AMCLIB_TRACK_OBSRV_TUNING_T_FLT;
  

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_TrackObsrvTuning_FLT(AMCLIB_TRACK_OBSRV_T_FLT *const pCtrl, AMCLIB_TRACK_OBSRV_TUNING_T_FLT *pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* AMCLIB_TRACKOBSRVTUNING_H */
