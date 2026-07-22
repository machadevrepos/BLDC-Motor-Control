/******************************************************************************
*
*   Copyright 2017-2026 NXP
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
* @file       AMCLIB_FWSpeedLoop.h
*
* @brief      Header file for AMCLIB_FWSpeedLoop function
*
******************************************************************************/
#ifndef AMCLIB_FWSPEEDLOOP_H
#define AMCLIB_FWSPEEDLOOP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "GFLIB_Ramp.h"
#include "GDFLIB_FilterMA.h"
#include "GFLIB_ControllerPIpAW.h"
#include "GFLIB_Sign.h"
#include "GFLIB_SinCos.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define AMCLIB_FWSpeedLoopInit(...)     macro_dispatcher(AMCLIB_FWSpeedLoopInit, __VA_ARGS__)(__VA_ARGS__)     /* This function clears the AMCLIB_FWSpeedLoop state variables. */
  #define AMCLIB_FWSpeedLoopSetState(...)     macro_dispatcher(AMCLIB_FWSpeedLoopSetState, __VA_ARGS__)(__VA_ARGS__)     /* This function initializes the AMCLIB_FWSpeedLoop state variables to achieve the required output values. */
  #define AMCLIB_FWSpeedLoop(...)     macro_dispatcher(AMCLIB_FWSpeedLoop, __VA_ARGS__)(__VA_ARGS__)     /* This function adjusts the torque of the motor to achieve the required speed. The function employs the Field Weakening technique to extend the available speed range. */
  #define AMCLIB_FWSpeedLoopDebug(...)     macro_dispatcher(AMCLIB_FWSpeedLoopDebug, __VA_ARGS__)(__VA_ARGS__)     /* This function adjusts the torque of the motor to achieve the required speed. The function employs the Field Weakening technique to extend the available speed range. Debugging information is provided. */
  
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define AMCLIB_FW_SPEED_LOOP_T                                        AMCLIB_FW_SPEED_LOOP_T_F32
    /* @remarks Implements DAMCLIB00096 */
    #define AMCLIB_FWSpeedLoopInit_Dsptchr_1(pCtrl)     AMCLIB_FWSpeedLoopInit_Dsptchr_2(pCtrl,F32)     /* Function dispatcher for AMCLIB_FWSpeedLoopInit_Dsptchr_1, do not modify!!! */
    /* @remarks Implements DAMCLIB00103 */
    #define AMCLIB_FWSpeedLoopSetState_Dsptchr_6(f32FilterMAWOut,f32FilterMAFWOut,f32ControllerPIpAWQOut,f32ControllerPIpAWFWOut,f32RampOut,pCtrl)     AMCLIB_FWSpeedLoopSetState_Dsptchr_7(f32FilterMAWOut,f32FilterMAFWOut,f32ControllerPIpAWQOut,f32ControllerPIpAWFWOut,f32RampOut,pCtrl,F32)     /* Function dispatcher for AMCLIB_FWSpeedLoopSetState_Dsptchr_6, do not modify!!! */
    /* @remarks Implements DAMCLIB00089 */
    #define AMCLIB_FWSpeedLoop_Dsptchr_4(f32VelocityReq,f32VelocityFbck,pIDQReq,pCtrl)     AMCLIB_FWSpeedLoop_Dsptchr_5(f32VelocityReq,f32VelocityFbck,pIDQReq,pCtrl,F32)     /* Function dispatcher for AMCLIB_FWSpeedLoop_Dsptchr_4, do not modify!!! */
    /* @remarks Implements DAMCLIB00141 */
    #define AMCLIB_FWSpeedLoopDebug_Dsptchr_4(f32VelocityReq,f32VelocityFbck,pIDQReq,pCtrl)     AMCLIB_FWSpeedLoopDebug_Dsptchr_5(f32VelocityReq,f32VelocityFbck,pIDQReq,pCtrl,F32)     /* Function dispatcher for AMCLIB_FWSpeedLoopDebug_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define AMCLIB_FW_SPEED_LOOP_T                                        AMCLIB_FW_SPEED_LOOP_T_F16
    /* @remarks Implements DAMCLIB00096 */
    #define AMCLIB_FWSpeedLoopInit_Dsptchr_1(pCtrl)     AMCLIB_FWSpeedLoopInit_Dsptchr_2(pCtrl,F16)     /* Function dispatcher for AMCLIB_FWSpeedLoopInit_Dsptchr_1, do not modify!!! */
    /* @remarks Implements DAMCLIB00103 */
    #define AMCLIB_FWSpeedLoopSetState_Dsptchr_6(f16FilterMAWOut,f16FilterMAFWOut,f16ControllerPIpAWQOut,f16ControllerPIpAWFWOut,f32RampOut,pCtrl)     AMCLIB_FWSpeedLoopSetState_Dsptchr_7(f16FilterMAWOut,f16FilterMAFWOut,f16ControllerPIpAWQOut,f16ControllerPIpAWFWOut,f32RampOut,pCtrl,F16)     /* Function dispatcher for AMCLIB_FWSpeedLoopSetState_Dsptchr_6, do not modify!!! */
    /* @remarks Implements DAMCLIB00089 */
    #define AMCLIB_FWSpeedLoop_Dsptchr_4(f16VelocityReq,f16VelocityFbck,pIDQReq,pCtrl)     AMCLIB_FWSpeedLoop_Dsptchr_5(f16VelocityReq,f16VelocityFbck,pIDQReq,pCtrl,F16)     /* Function dispatcher for AMCLIB_FWSpeedLoop_Dsptchr_4, do not modify!!! */
    /* @remarks Implements DAMCLIB00141 */
    #define AMCLIB_FWSpeedLoopDebug_Dsptchr_4(f16VelocityReq,f16VelocityFbck,pIDQReq,pCtrl)     AMCLIB_FWSpeedLoopDebug_Dsptchr_5(f16VelocityReq,f16VelocityFbck,pIDQReq,pCtrl,F16)     /* Function dispatcher for AMCLIB_FWSpeedLoopDebug_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_FW_SPEED_LOOP_T                                        AMCLIB_FW_SPEED_LOOP_T_FLT
    /* @remarks Implements DAMCLIB00096 */
    #define AMCLIB_FWSpeedLoopInit_Dsptchr_1(pCtrl)     AMCLIB_FWSpeedLoopInit_Dsptchr_2(pCtrl,FLT)     /* Function dispatcher for AMCLIB_FWSpeedLoopInit_Dsptchr_1, do not modify!!! */
    /* @remarks Implements DAMCLIB00103 */
    #define AMCLIB_FWSpeedLoopSetState_Dsptchr_6(fltFilterMAWOut,fltFilterMAFWOut,fltControllerPIpAWQOut,fltControllerPIpAWFWOut,fltRampOut,pCtrl)     AMCLIB_FWSpeedLoopSetState_Dsptchr_7(fltFilterMAWOut,fltFilterMAFWOut,fltControllerPIpAWQOut,fltControllerPIpAWFWOut,fltRampOut,pCtrl,FLT)     /* Function dispatcher for AMCLIB_FWSpeedLoopSetState_Dsptchr_6, do not modify!!! */
    /* @remarks Implements DAMCLIB00089 */
    #define AMCLIB_FWSpeedLoop_Dsptchr_4(fltVelocityReq,fltVelocityFbck,pIDQReq,pCtrl)     AMCLIB_FWSpeedLoop_Dsptchr_5(fltVelocityReq,fltVelocityFbck,pIDQReq,pCtrl,FLT)     /* Function dispatcher for AMCLIB_FWSpeedLoop_Dsptchr_4, do not modify!!! */
    /* @remarks Implements DAMCLIB00141 */
    #define AMCLIB_FWSpeedLoopDebug_Dsptchr_4(fltVelocityReq,fltVelocityFbck,pIDQReq,pCtrl)     AMCLIB_FWSpeedLoopDebug_Dsptchr_5(fltVelocityReq,fltVelocityFbck,pIDQReq,pCtrl,FLT)     /* Function dispatcher for AMCLIB_FWSpeedLoopDebug_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
  
  #define AMCLIB_FWSpeedLoopInit_Dsptchr_2(pCtrl,Impl)    AMCLIB_FWSpeedLoopInit_Dsptchr_(pCtrl,Impl)     /* Function dispatcher for AMCLIB_FWSpeedLoopInit_Dsptchr_2, do not modify!!! */
  /* @remarks Implements DAMCLIB00098 */
  #define AMCLIB_FWSpeedLoopInit_Dsptchr_(pCtrl,Impl)     AMCLIB_FWSpeedLoopInit_##Impl(pCtrl)            /* Function dispatcher for AMCLIB_FWSpeedLoopInit_Dsptchr_, do not modify!!! */
  
  #define AMCLIB_FWSpeedLoopSetState_Dsptchr_7(FilterMAWOut,FilterMAFWOut,ControllerPIpAWQOut,ControllerPIpAWFWOut,RampOut,pCtrl,Impl)    AMCLIB_FWSpeedLoopSetState_Dsptchr_(FilterMAWOut,FilterMAFWOut,ControllerPIpAWQOut,ControllerPIpAWFWOut,RampOut,pCtrl,Impl)     /* Function dispatcher for AMCLIB_FWSpeedLoopSetState_Dsptchr_7, do not modify!!! */
  /* @remarks Implements DAMCLIB00105 */
  #define AMCLIB_FWSpeedLoopSetState_Dsptchr_(FilterMAWOut,FilterMAFWOut,ControllerPIpAWQOut,ControllerPIpAWFWOut,RampOut,pCtrl,Impl)     AMCLIB_FWSpeedLoopSetState_##Impl(FilterMAWOut,FilterMAFWOut,ControllerPIpAWQOut,ControllerPIpAWFWOut,RampOut,pCtrl)            /* Function dispatcher for AMCLIB_FWSpeedLoopSetState_Dsptchr_, do not modify!!! */
  
  #define AMCLIB_FWSpeedLoop_Dsptchr_5(VelocityReq,VelocityFbck,pIDQReq,pCtrl,Impl)    AMCLIB_FWSpeedLoop_Dsptchr_(VelocityReq,VelocityFbck,pIDQReq,pCtrl,Impl)     /* Function dispatcher for AMCLIB_FWSpeedLoop_Dsptchr_5, do not modify!!! */
  /* @remarks Implements DAMCLIB00091 */
  #define AMCLIB_FWSpeedLoop_Dsptchr_(VelocityReq,VelocityFbck,pIDQReq,pCtrl,Impl)     AMCLIB_FWSpeedLoop_##Impl(VelocityReq,VelocityFbck,pIDQReq,pCtrl)            /* Function dispatcher for AMCLIB_FWSpeedLoop_Dsptchr_, do not modify!!! */
  
  #define AMCLIB_FWSpeedLoopDebug_Dsptchr_5(VelocityReq,VelocityFbck,pIDQReq,pCtrl,Impl)    AMCLIB_FWSpeedLoopDebug_Dsptchr_(VelocityReq,VelocityFbck,pIDQReq,pCtrl,Impl)     /* Function dispatcher for AMCLIB_FWSpeedLoopDebug_Dsptchr_5, do not modify!!! */
  /* @remarks Implements DAMCLIB00143 */
  #define AMCLIB_FWSpeedLoopDebug_Dsptchr_(VelocityReq,VelocityFbck,pIDQReq,pCtrl,Impl)     AMCLIB_FWSpeedLoopDebug_##Impl(VelocityReq,VelocityFbck,pIDQReq,pCtrl)            /* Function dispatcher for AMCLIB_FWSpeedLoopDebug_Dsptchr_, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define AMCLIB_FW_SPEED_LOOP_DEFAULT_F32 {0,0, \
                                            0,0, \
                                            (tFrac32)0,(tFrac32)0,(tS32)0,(tS32)0,SWLIBS_INT32_MIN,SWLIBS_INT32_MAX,(tFrac32)0,(tFrac32)0,(tU16)0, \
                                            (tFrac32)0,(tFrac32)0,(tS32)0,(tS32)0,SWLIBS_INT32_MIN,SWLIBS_INT32_MAX,(tFrac32)0,(tFrac32)0,(tU16)0, \
                                            (tFrac32)0,(tFrac32)0,(tFrac32)0, \
                                            (tFrac32 *)0, \
                                            (tFrac32 *)0, \
                                            (tFrac32 *)0}               /**< Default value for AMCLIB_FW_SPEED_LOOP_T_F32. */

  /************************************************************************/
  /**
  @struct AMCLIB_FW_SPEED_LOOP_T_F32 "\AMCLIB_FWSpeedLoop.h" 

  @brief  FWSpeedLoop configuration structure.
  *//**********************************************************************/
  /* @remarks Implements DAMCLIB00088 */
  typedef struct
  {
    GDFLIB_FILTER_MA_T_F32 pFilterW;  /**< Velocity FilterMA paremeters structure. */
    GDFLIB_FILTER_MA_T_F32 pFilterFW;  /**< Field weakening angle FilterMA paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_F32 pPIpAWQ;  /**< Q-axis ControllerPIpAW paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_F32 pPIpAWFW;  /**< Field weakening angle ControllerPIpAW paremeters structure. */
    GFLIB_RAMP_T_F32 pRamp;  /**< Speed ramp paremeters structure. */
    tFrac32 *pIQFbck;  /**< Pointer to the q-axis component of the feedback current in the two-phase rotational orthogonal system (d-q). */
    tFrac32 *pUQReq;  /**< Pointer to the q-axis component of the required voltage in the two-phase rotational orthogonal system (d-q). */
    tFrac32 *pUQLim;  /**< Pointer to the q-axis voltage controller upper limit (should point to the AMCLIB_CURRENT_LOOP_T_F32 structure element pPIrAWQ.f32UpperLimit). The limit must be a positive value. */
  }AMCLIB_FW_SPEED_LOOP_T_F32;

  /************************************************************************/
  /**
  @struct AMCLIB_FW_SPEED_LOOP_DEBUG_T_F32 "\AMCLIB_FWSpeedLoop.h" 

  @brief  FWSpeedLoop configuration structure with debugging information.
  *//**********************************************************************/
  /* @remarks Implements DAMCLIB00140 */
  typedef struct
  {
    GDFLIB_FILTER_MA_T_F32 pFilterW;         /**< Velocity FilterMA paremeters structure. */
    GDFLIB_FILTER_MA_T_F32 pFilterFW;        /**< Field weakening angle FilterMA paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_F32 pPIpAWQ;   /**< Q-axis ControllerPIpAW paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_F32 pPIpAWFW;  /**< Field weakening angle ControllerPIpAW paremeters structure. */
    GFLIB_RAMP_T_F32 pRamp;                  /**< Speed ramp paremeters structure. */
    tFrac32 *pIQFbck;                        /**< Pointer to the q-axis component of the feedback current in the two-phase rotational orthogonal system (d-q). */
    tFrac32 *pUQReq;                         /**< Pointer to the q-axis component of the required voltage in the two-phase rotational orthogonal system (d-q). */
    tFrac32 *pUQLim;                         /**< Pointer to the q-axis voltage controller upper limit (should point to the AMCLIB_CURRENT_LOOP_T_F32 structure element pPIrAWQ.f32UpperLimit). The limit must be a positive value. */
    tFrac32 f32WReqFilt;                     /**< SpeedLoop - Filtered value of the required angular velocity. */
    tFrac32 f32WErr;                         /**< SpeedLoop - Velocity deviation. */
    tFrac32 f32WFbckFilt;                    /**< SpeedLoop - Filtered value of the measured angular velocity. */
    tFrac32 f32IDQReqAmp;                    /**< SpeedLoop - Required current amplitude. */
    tFrac32 f32IQErrSign;                    /**< FW - Current deviation after sign elimination. */
    tFrac32 f32FWErr;                        /**< FW - Current deviation. */
    tFrac32 f32IQErr;                        /**< FW - Field weakening feedback control variable. */
    tFrac32 f32UQErr;                        /**< FW - Voltage deviation. */
    tFrac32 f32FWErrFilt;                    /**< FW - Filtered field weakening feedback control variable. */
    tFrac32 f32FWAngle;                      /**< FW - Field weakening angle. */
    tFrac32 f32FWSin;                        /**< FW - Q-axis unity current phasor component. */
    tFrac32 f32FWCos;                        /**< FW - D-axis unity current phasor component. */
  }
  AMCLIB_FW_SPEED_LOOP_DEBUG_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_FWSpeedLoopInit_F32(AMCLIB_FW_SPEED_LOOP_T_F32 *const pCtrl);
  extern void AMCLIB_FWSpeedLoopSetState_F32(tFrac32 f32FilterMAWOut, tFrac32 f32FilterMAFWOut,
    tFrac32 f32ControllerPIpAWQOut, tFrac32 f32ControllerPIpAWFWOut, tFrac32 f32RampOut,
    AMCLIB_FW_SPEED_LOOP_T_F32 *pCtrl);
  extern void AMCLIB_FWSpeedLoop_F32(tFrac32 f32VelocityReq, tFrac32 f32VelocityFbck,
    SWLIBS_2Syst_F32 *const pIDQReq, AMCLIB_FW_SPEED_LOOP_T_F32 *pCtrl);
  extern void AMCLIB_FWSpeedLoopDebug_F32(tFrac32 f32VelocityReq, tFrac32 f32VelocityFbck,
    SWLIBS_2Syst_F32 *const pIDQReq, AMCLIB_FW_SPEED_LOOP_DEBUG_T_F32 *pCtrl);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)

  #define AMCLIB_FW_SPEED_LOOP_DEFAULT_F16 {0,0, \
                                            0,0, \
                                            (tFrac16)0,(tFrac16)0,(tS16)0,(tS16)0,SWLIBS_INT16_MIN,SWLIBS_INT16_MAX,(tFrac32)0,(tFrac16)0,(tU16)0, \
                                            (tFrac16)0,(tFrac16)0,(tS16)0,(tS16)0,SWLIBS_INT16_MIN,SWLIBS_INT16_MAX,(tFrac32)0,(tFrac16)0,(tU16)0, \
                                            (tFrac32)0,(tFrac32)0,(tFrac32)0, \
                                            (tFrac16 *)0, \
                                            (tFrac16 *)0, \
                                            (tFrac16 *)0}               /**< Default value for AMCLIB_FW_SPEED_LOOP_T_F16. */
  
  /************************************************************************/
  /**
  @struct AMCLIB_FW_SPEED_LOOP_T_F16 "\AMCLIB_FWSpeedLoop.h" 

  @brief  FWSpeedLoop configuration structure.
  *//**********************************************************************/
  /* @remarks Implements DAMCLIB00088 */
  typedef struct
  {
    GDFLIB_FILTER_MA_T_F16 pFilterW;  /**< Velocity FilterMA paremeters structure. */
    GDFLIB_FILTER_MA_T_F16 pFilterFW;  /**< Field weakening angle FilterMA paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_F16 pPIpAWQ;  /**< Q-axis ControllerPIpAW paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_F16 pPIpAWFW;  /**< Field weakening angle ControllerPIpAW paremeters structure. */
    GFLIB_RAMP_T_F32 pRamp;  /**< Speed ramp paremeters structure. */
    tFrac16 *pIQFbck;  /**< Pointer to the q-axis component of the feedback current in the two-phase rotational orthogonal system (d-q). */
    tFrac16 *pUQReq;  /**< Pointer to the q-axis component of the required voltage in the two-phase rotational orthogonal system (d-q). */
    tFrac16 *pUQLim;  /**< Pointer to the q-axis voltage controller upper limit (should point to the AMCLIB_CURRENT_LOOP_T_F16 structure element pPIrAWQ.f16UpperLimit). The limit must be a positive value. */
  }AMCLIB_FW_SPEED_LOOP_T_F16;
  
  /************************************************************************/
  /**
  @struct AMCLIB_FW_SPEED_LOOP_DEBUG_T_F16 "\AMCLIB_FWSpeedLoop.h" 

  @brief  FWSpeedLoop configuration structure with debugging information.
  *//**********************************************************************/
  /* @remarks Implements DAMCLIB00140 */
  typedef struct
  {
    GDFLIB_FILTER_MA_T_F16 pFilterW;         /**< Velocity FilterMA paremeters structure. */
    GDFLIB_FILTER_MA_T_F16 pFilterFW;        /**< Field weakening angle FilterMA paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_F16 pPIpAWQ;   /**< Q-axis ControllerPIpAW paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_F16 pPIpAWFW;  /**< Field weakening angle ControllerPIpAW paremeters structure. */
    GFLIB_RAMP_T_F32 pRamp;                  /**< Speed ramp paremeters structure. */
    tFrac16 *pIQFbck;                        /**< Pointer to the q-axis component of the feedback current in the two-phase rotational orthogonal system (d-q). */
    tFrac16 *pUQReq;                         /**< Pointer to the q-axis component of the required voltage in the two-phase rotational orthogonal system (d-q). */
    tFrac16 *pUQLim;                         /**< Pointer to the q-axis voltage controller upper limit (should point to the AMCLIB_CURRENT_LOOP_T_F16 structure element pPIrAWQ.f16UpperLimit). The limit must be a positive value. */
    tFrac16 f16WReqFilt;                     /**< SpeedLoop - Filtered value of the required angular velocity. */
    tFrac16 f16WErr;                         /**< SpeedLoop - Velocity deviation. */
    tFrac16 f16IDQReqAmp;                    /**< SpeedLoop - Filtered value of the measured angular velocity. */
    tFrac16 f16WFbckFilt;                    /**< SpeedLoop - Required current amplitude. */
    tFrac16 f16IQErrSign;                    /**< FW - Current deviation after sign elimination. */
    tFrac16 f16FWErr;                        /**< FW - Current deviation. */
    tFrac16 f16IQErr;                        /**< FW - Field weakening feedback control variable. */
    tFrac16 f16UQErr;                        /**< FW - Voltage deviation. */
    tFrac16 f16FWErrFilt;                    /**< FW - Filtered field weakening feedback control variable. */
    tFrac16 f16FWAngle;                      /**< FW - Field weakening angle. */
    tFrac16 f16FWSin;                        /**< FW - Q-axis unity current phasor component. */
    tFrac16 f16FWCos;                        /**< FW - D-axis unity current phasor component. */
  }
  AMCLIB_FW_SPEED_LOOP_DEBUG_T_F16;
  
/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_FWSpeedLoopInit_F16(AMCLIB_FW_SPEED_LOOP_T_F16 *const pCtrl);
  extern void AMCLIB_FWSpeedLoopSetState_F16(tFrac16 f16FilterMAWOut, tFrac16 f16FilterMAFWOut,
    tFrac16 f16ControllerPIpAWQOut, tFrac16 f16ControllerPIpAWFWOut, tFrac32 f32RampOut,
    AMCLIB_FW_SPEED_LOOP_T_F16 *pCtrl);
  extern void AMCLIB_FWSpeedLoop_F16(tFrac16 f16VelocityReq, tFrac16 f16VelocityFbck,
    SWLIBS_2Syst_F16 *const pIDQReq, AMCLIB_FW_SPEED_LOOP_T_F16 *pCtrl);
  extern void AMCLIB_FWSpeedLoopDebug_F16(tFrac16 f16VelocityReq, tFrac16 f16VelocityFbck,
    SWLIBS_2Syst_F16 *const pIDQReq, AMCLIB_FW_SPEED_LOOP_DEBUG_T_F16 *pCtrl);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)

  #define AMCLIB_FW_SPEED_LOOP_DEFAULT_FLT {0,0 \
                                            0,0 \
                                            (tFloat)0,(tFloat)0,FLOAT_MIN,FLOAT_MAX,(tFloat)0,(tFloat)0,(tU16)0, \
                                            (tFloat)0,(tFloat)0,FLOAT_MIN,FLOAT_MAX,(tFloat)0,(tFloat)0,(tU16)0, \
                                            (tFloat)0,(tFloat)0,(tFloat)0, \
                                            (tFloat *)0, \
                                            (tFloat *)0, \
                                            (tFloat *)0}               /**< Default value for AMCLIB_FW_SPEED_LOOP_T_FLT. */

  /************************************************************************/
  /**
  @struct AMCLIB_FW_SPEED_LOOP_T_FLT "\AMCLIB_FWSpeedLoop.h"

  @brief  FWSpeedLoop configuration structure.
  *//**********************************************************************/
  /* @remarks Implements DAMCLIB00088 */
  typedef struct
  {
    GDFLIB_FILTER_MA_T_FLT pFilterW;  /**< Velocity FilterMA paremeters structure. */
    GDFLIB_FILTER_MA_T_FLT pFilterFW;  /**< Field weakening angle FilterMA paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_FLT pPIpAWQ;  /**< Q-axis ControllerPIpAW paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_FLT pPIpAWFW;  /**< Field weakening angle ControllerPIpAW paremeters structure. */
    GFLIB_RAMP_T_FLT pRamp;  /**< Speed ramp paremeters structure. */
    tFloat *pIQFbck;  /**< Pointer to the q-axis component of the feedback current in the two-phase rotational orthogonal system (d-q). */
    tFloat *pUQReq;  /**< Pointer to the q-axis component of the required voltage in the two-phase rotational orthogonal system (d-q). */
    tFloat *pUQLim;  /**< Pointer to the q-axis voltage controller upper limit (should point to the AMCLIB_CURRENT_LOOP_T_FLT structure element pPIrAWQ.fltUpperLimit). The limit must be a positive value. */
    tFloat fltUmaxDivImax;  /**< Maximal coil voltage divided by the maximal coil current. */
  }AMCLIB_FW_SPEED_LOOP_T_FLT;

  /************************************************************************/
  /**
  @struct AMCLIB_FW_SPEED_LOOP_DEBUG_T_FLT "\AMCLIB_FWSpeedLoop.h"

  @brief  FWSpeedLoop configuration structure with debugging information.
  *//**********************************************************************/
  /* @remarks Implements DAMCLIB00140 */
  typedef struct
  {
    GDFLIB_FILTER_MA_T_FLT pFilterW;         /**< Velocity FilterMA paremeters structure. */
    GDFLIB_FILTER_MA_T_FLT pFilterFW;        /**< Field weakening angle FilterMA paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_FLT pPIpAWQ;   /**< Q-axis ControllerPIpAW paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_FLT pPIpAWFW;  /**< Field weakening angle ControllerPIpAW paremeters structure. */
    GFLIB_RAMP_T_FLT pRamp;                  /**< Speed ramp paremeters structure. */
    tFloat *pIQFbck;                         /**< Pointer to the q-axis component of the feedback current in the two-phase rotational orthogonal system (d-q). */
    tFloat *pUQReq;                          /**< Pointer to the q-axis component of the required voltage in the two-phase rotational orthogonal system (d-q). */
    tFloat *pUQLim;                          /**< Pointer to the q-axis voltage controller upper limit (should point to the AMCLIB_CURRENT_LOOP_T_FLT structure element pPIrAWQ.fltUpperLimit). The limit must be a positive value. */
    tFloat fltUmaxDivImax;                   /**< Maximal coil voltage divided by the maximal coil current. */
    tFloat fltWReqFilt;                      /**< SpeedLoop - Filtered value of the required angular velocity. */
    tFloat fltWErr;                          /**< SpeedLoop - Velocity deviation. */
    tFloat fltIDQReqAmp;                     /**< SpeedLoop - Filtered value of the measured angular velocity. */
    tFloat fltWFbckFilt;                     /**< SpeedLoop - Required current amplitude. */
    tFloat fltIQErrSign;                     /**< FW - Current deviation after sign elimination. */
    tFloat fltFWErr;                         /**< FW - Current deviation. */
    tFloat fltIQErr;                         /**< FW - Field weakening feedback control variable. */
    tFloat fltUQErr;                         /**< FW - Voltage deviation. */
    tFloat fltFWErrFilt;                     /**< FW - Filtered field weakening feedback control variable. */
    tFloat fltFWAngle;                       /**< FW - Field weakening angle. */
    tFloat fltFWSin;                         /**< FW - Q-axis unity current phasor component. */
    tFloat fltFWCos;                         /**< FW - D-axis unity current phasor component. */
  }
  AMCLIB_FW_SPEED_LOOP_DEBUG_T_FLT;
  
/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_FWSpeedLoopInit_FLT(AMCLIB_FW_SPEED_LOOP_T_FLT *const pCtrl);
  extern void AMCLIB_FWSpeedLoopSetState_FLT(tFloat fltFilterMAWOut, tFloat fltFilterMAFWOut,
    tFloat fltControllerPIpAWQOut, tFloat fltControllerPIpAWFWOut, tFloat fltRampOut,
    AMCLIB_FW_SPEED_LOOP_T_FLT *pCtrl);
  extern void AMCLIB_FWSpeedLoop_FLT(tFloat fltVelocityReq, tFloat fltVelocityFbck,
    SWLIBS_2Syst_FLT *const pIDQReq, AMCLIB_FW_SPEED_LOOP_T_FLT *pCtrl);
  extern void AMCLIB_FWSpeedLoopDebug_FLT(tFloat fltVelocityReq, tFloat fltVelocityFbck,
    SWLIBS_2Syst_FLT *const pIDQReq, AMCLIB_FW_SPEED_LOOP_DEBUG_T_FLT *pCtrl);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif/* AMCLIB_FWSPEEDLOOP_H */
