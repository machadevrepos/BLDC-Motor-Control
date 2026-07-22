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
* @file       AMCLIB_TrackObsrv.h
*
* @brief      Header file for AMCLIB_TrackObsrv function
*
******************************************************************************/
#ifndef AMCLIB_TRACKOBSRV_H
#define AMCLIB_TRACKOBSRV_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "GFLIB_ControllerPIrAW.h"
#include "GFLIB_IntegratorTR.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define AMCLIB_TrackObsrv(...)     macro_dispatcher(AMCLIB_TrackObsrv, __VA_ARGS__)(__VA_ARGS__)                      /* This function calculates tracking observer for determination angular speed and position of input error functional signal */
  
  #define AMCLIB_TrackObsrvInit(...)     macro_dispatcher(AMCLIB_TrackObsrvInit, __VA_ARGS__)(__VA_ARGS__)              /* This function initialize tracking observer */

  #define AMCLIB_TrackObsrvSetState(...)     macro_dispatcher(AMCLIB_TrackObsrvSetState, __VA_ARGS__)(__VA_ARGS__)              /* This function sets the tracking observer state variables to predefined values */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define AMCLIB_TRACK_OBSRV_T                                  AMCLIB_TRACK_OBSRV_T_F32                              /**< Definition of AMCLIB_TRACK_OBSRV_T as alias for AMCLIB_TRACK_OBSRV_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    #define AMCLIB_TRACK_OBSRV_DEFAULT                            AMCLIB_TRACK_OBSRV_DEFAULT_F32                        /**< Definition of AMCLIB_TRACK_OBSRV_DEFAULT as alias for AMCLIB_TRACK_OBSRV_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    /* @remarks Implements DAMCLIB00027 */
    #define AMCLIB_TrackObsrv_Dsptchr_4(PhaseErr,PosEst,VelEst,pCtrl)          AMCLIB_TrackObsrv_Dsptchr_5(PhaseErr,PosEst,VelEst,pCtrl,F32)        /* Function dispatcher for AMCLIB_TrackObsrv_Dsptchr_2, do not modify!!! */
    
    /* @remarks Implements DAMCLIB00036 */
    #define AMCLIB_TrackObsrvInit_Dsptchr_1(pCtrl)     AMCLIB_TrackObsrvInit_Dsptchr_2(pCtrl,F32)                 /* Function dispatcher for AMCLIB_TrackObsrvInit_Dsptchr_2, do not modify!!! */
    
    /* @remarks Implements DAMCLIB00156 */
    #define AMCLIB_TrackObsrvSetState_Dsptchr_3(PosOut,VelocityOut,pCtrl)     AMCLIB_TrackObsrvSetState_Dsptchr_4(PosOut,VelocityOut,pCtrl,F32)                 /* Function dispatcher for AMCLIB_TrackObsrvSetState_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define AMCLIB_TRACK_OBSRV_T                                  AMCLIB_TRACK_OBSRV_T_F16                              /**< Definition of AMCLIB_TRACK_OBSRV_T as alias for AMCLIB_TRACK_OBSRV_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    #define AMCLIB_TRACK_OBSRV_DEFAULT                            AMCLIB_TRACK_OBSRV_DEFAULT_F16                        /**< Definition of AMCLIB_TRACK_OBSRV_DEFAULT as alias for AMCLIB_TRACK_OBSRV_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    /* @remarks Implements DAMCLIB00027 */
    #define AMCLIB_TrackObsrv_Dsptchr_4(PhaseErr,PosEst,VelEst,pCtrl)          AMCLIB_TrackObsrv_Dsptchr_5(PhaseErr,PosEst,VelEst,pCtrl,F16)        /* Function dispatcher for AMCLIB_TrackObsrv_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DAMCLIB00036 */
    #define AMCLIB_TrackObsrvInit_Dsptchr_1(pCtrl)      AMCLIB_TrackObsrvInit_Dsptchr_2(pCtrl,F16)                /* Function dispatcher for AMCLIB_TrackObsrvInit_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DAMCLIB00156 */
    #define AMCLIB_TrackObsrvSetState_Dsptchr_3(PosOut,VelocityOut,pCtrl)      AMCLIB_TrackObsrvSetState_Dsptchr_4(PosOut,VelocityOut,pCtrl,F16)                /* Function dispatcher for AMCLIB_TrackObsrvSetState_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_TRACK_OBSRV_T                                  AMCLIB_TRACK_OBSRV_T_FLT                              /**< Definition of AMCLIB_TRACK_OBSRV_T as alias for AMCLIB_TRACK_OBSRV_T_FLT datatype in case the single precision floating point implementation is selected. */
    #define AMCLIB_TRACK_OBSRV_DEFAULT                            AMCLIB_TRACK_OBSRV_DEFAULT_FLT                        /**< Definition of AMCLIB_TRACK_OBSRV_DEFAULT as alias for AMCLIB_TRACK_OBSRV_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /* @remarks Implements DAMCLIB00027 */
    #define AMCLIB_TrackObsrv_Dsptchr_4(PhaseErr,PosEst,VelEst,pCtrl)          AMCLIB_TrackObsrv_Dsptchr_5(PhaseErr,PosEst,VelEst,pCtrl,FLT)        /* Function dispatcher for AMCLIB_TrackObsrv_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DAMCLIB00036 */
    #define AMCLIB_TrackObsrvInit_Dsptchr_1(pCtrl)           AMCLIB_TrackObsrvInit_Dsptchr_2(pCtrl,FLT)           /* Function dispatcher for AMCLIB_TrackObsrvInit_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DAMCLIB00156 */
    #define AMCLIB_TrackObsrvSetState_Dsptchr_3(PosOut,VelocityOut,pCtrl)           AMCLIB_TrackObsrvSetState_Dsptchr_4(PosOut,VelocityOut,pCtrl,FLT)           /* Function dispatcher for AMCLIB_TrackObsrvSetState_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
  
  #define AMCLIB_TrackObsrv_Dsptchr_5(PhaseErr,PosEst,VelEst,pCtrl,Impl)       AMCLIB_TrackObsrv_Dsptchr_(PhaseErr,PosEst,VelEst,pCtrl,Impl)        /* Function dispatcher for AMCLIB_TrackObsrv_Dsptchr_3, do not modify!!! */
  
  #define AMCLIB_TrackObsrvInit_Dsptchr_2(pCtrl,Impl)         AMCLIB_TrackObsrvInit_Dsptchr_(pCtrl,Impl)          /* Function dispatcher for AMCLIB_TrackObsrvInit_Dsptchr_2, do not modify!!! */
  
  #define AMCLIB_TrackObsrvSetState_Dsptchr_4(PosOut,VelocityOut,pCtrl,Impl)         AMCLIB_TrackObsrvSetState_Dsptchr_(PosOut,VelocityOut,pCtrl,Impl)          /* Function dispatcher for AMCLIB_TrackObsrvSetState_Dsptchr_4, do not modify!!! */

  /* @remarks Implements DAMCLIB00029 */
  #define AMCLIB_TrackObsrv_Dsptchr_(PhaseErr,PosEst,VelEst,pCtrl,Impl)        AMCLIB_TrackObsrv_##Impl(PhaseErr,PosEst,VelEst,pCtrl)               /* Function dispatcher for AMCLIB_TrackObsrv_Dsptchr_, do not modify!!! */
  
  /* @remarks Implements DAMCLIB00038 */
  #define AMCLIB_TrackObsrvInit_Dsptchr_(pCtrl,Impl)          AMCLIB_TrackObsrvInit_##Impl(pCtrl)                 /* Function dispatcher for AMCLIB_TrackObsrvInit_Dsptchr_, do not modify!!! */
  
  /* @remarks Implements DAMCLIB00158 */
  #define AMCLIB_TrackObsrvSetState_Dsptchr_(PosOut,VelocityOut,pCtrl,Impl)          AMCLIB_TrackObsrvSetState_##Impl(PosOut,VelocityOut,pCtrl)                 /* Function dispatcher for AMCLIB_TrackObsrvSetState_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define AMCLIB_TRACK_OBSRV_DEFAULT_F32 {(tFrac32)0,(tFrac32)0,(tFrac32)0,(tFrac32)0,SWLIBS_INT32_MIN,SWLIBS_INT32_MAX,(tU16)0, \
                                          (tFrac32)0,(tFrac32)0,(tFrac32)0,(tU16)0}     /**< Default value for AMCLIB_TRACK_OBSRV_T_F32. */

  /************************************************************************/
  /**
  @struct AMCLIB_TRACK_OBSRV_T_F32 "\AMCLIB_TrackObsrv.h"

  @brief  Structure containing the estimated position, estimated velocity and the algorithm parameters.
  *//*************************************************************************/
  /* @remarks Implements DAMCLIB00026, DAMCLIB00035 */
  typedef struct{
    GFLIB_CONTROLLER_PIAW_R_T_F32 pParamPI; /**< Observer PIrAW controller parameters. */
    GFLIB_INTEGRATOR_TR_T_F32 pParamInteg;  /**< Observer integrator parameters. */
  }AMCLIB_TRACK_OBSRV_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_TrackObsrvInit_F32(AMCLIB_TRACK_OBSRV_T_F32 *pCtrl);
  extern void AMCLIB_TrackObsrvSetState_F32(tFrac32 f32PosOut, tFrac32 f32VelocityOut, AMCLIB_TRACK_OBSRV_T_F32 *pCtrl);
  extern void AMCLIB_TrackObsrv_F32(tFrac32 f32PhaseErr, tFrac32 *pPosEst, tFrac32 *pVelocityEst, AMCLIB_TRACK_OBSRV_T_F32 *pCtrl);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  #define AMCLIB_TRACK_OBSRV_DEFAULT_F16 {(tFrac16)0,(tFrac16)0,(tFrac32)0,(tFrac16)0,SWLIBS_INT16_MIN,SWLIBS_INT16_MAX,(tU16)0, \
                                          (tFrac32)0,(tFrac16)0,(tFrac16)0,(tU16)0}     /**< Default value for AMCLIB_TRACK_OBSRV_T_F16. */

  /************************************************************************/
  /**
  @struct AMCLIB_TRACK_OBSRV_T_F16 "\AMCLIB_TrackObsrv.h"

  @brief  Structure containing the estimated position, estimated velocity and the algorithm parameters.
  *//*************************************************************************/
  /* @remarks Implements DAMCLIB00026, DAMCLIB00035 */
  typedef struct{
    GFLIB_CONTROLLER_PIAW_R_T_F16 pParamPI; /**< Observer PIrAW controller parameters. */
    GFLIB_INTEGRATOR_TR_T_F16 pParamInteg;  /**< Observer integrator parameters. */
  }AMCLIB_TRACK_OBSRV_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_TrackObsrvInit_F16(AMCLIB_TRACK_OBSRV_T_F16 *pCtrl);
  extern void AMCLIB_TrackObsrvSetState_F16(tFrac16 f16PosOut, tFrac16 f16VelocityOut, AMCLIB_TRACK_OBSRV_T_F16 *pCtrl);
  extern void AMCLIB_TrackObsrv_F16(tFrac16 f16PhaseErr, tFrac16 *pPosEst, tFrac16 *pVelocityEst, AMCLIB_TRACK_OBSRV_T_F16 *pCtrl);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define AMCLIB_TRACK_OBSRV_DEFAULT_FLT {(tFloat)0,(tFloat)0,(tFloat)0,(tFloat)0,FLOAT_MIN,FLOAT_MAX, \
                                          (tFloat)0,(tFloat)0,(tFloat)0}     /**< Default value for AMCLIB_TRACK_OBSRV_T_FLT. */

  /************************************************************************/
  /**
  @struct AMCLIB_TRACK_OBSRV_T_FLT "\AMCLIB_TrackObsrv.h"

  @brief  Structure containing the estimated position, estimated velocity and the algorithm parameters.
  *//*************************************************************************/
  /* @remarks Implements DAMCLIB00026, DAMCLIB00035 */
  typedef struct{
    GFLIB_CONTROLLER_PIAW_R_T_FLT pParamPI; /**< Observer PIrAW controller parameters. */
    GFLIB_INTEGRATOR_TR_T_FLT pParamInteg;  /**< Observer integrator parameters. */
  }AMCLIB_TRACK_OBSRV_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_TrackObsrvInit_FLT(AMCLIB_TRACK_OBSRV_T_FLT *pCtrl);
  extern void AMCLIB_TrackObsrvSetState_FLT(tFloat fltPosOut, tFloat fltVelocityOut, AMCLIB_TRACK_OBSRV_T_FLT *pCtrl);
  extern void AMCLIB_TrackObsrv_FLT(tFloat fltPhaseErr, tFloat *pPosEst, tFloat *pVelocityEst, AMCLIB_TRACK_OBSRV_T_FLT *pCtrl);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif/* AMCLIB_TRACKOBSRV_H */
