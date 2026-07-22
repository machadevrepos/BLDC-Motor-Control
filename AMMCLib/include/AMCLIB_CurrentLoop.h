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
* @file       AMCLIB_CurrentLoop.h
*
* @brief      Header file for AMCLIB_CurrentLoop function
*
******************************************************************************/
#ifndef AMCLIB_CURRENTLOOP_H
#define AMCLIB_CURRENTLOOP_H

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
  #define AMCLIB_CurrentLoopInit(...)     macro_dispatcher(AMCLIB_CurrentLoopInit, __VA_ARGS__)(__VA_ARGS__)     /* This function clears the AMCLIB_CurrentLoop state variables. */
  #define AMCLIB_CurrentLoopSetState(...)     macro_dispatcher(AMCLIB_CurrentLoopSetState, __VA_ARGS__)(__VA_ARGS__)     /* This function initializes the AMCLIB_CurrentLoop state variables to achieve the required output values. */
  #define AMCLIB_CurrentLoop(...)     macro_dispatcher(AMCLIB_CurrentLoop, __VA_ARGS__)(__VA_ARGS__)     /* This function adjusts the torque of the motor to achieve the required speed. The function employs the Field Weakening technique to extend the available speed range. */
  
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define AMCLIB_CURRENT_LOOP_T                                        AMCLIB_CURRENT_LOOP_T_F32
    /* @remarks Implements DAMCLIB00052 */
    #define AMCLIB_CurrentLoopInit_Dsptchr_1(pCtrl)     AMCLIB_CurrentLoopInit_Dsptchr_2(pCtrl,F32)     /* Function dispatcher for AMCLIB_CurrentLoopInit_Dsptchr_1, do not modify!!! */
    /* @remarks Implements DAMCLIB00059 */
    #define AMCLIB_CurrentLoopSetState_Dsptchr_3(arg1,arg2,pCtrl)     AMCLIB_CurrentLoopSetState_Dsptchr_4(arg1,arg2,pCtrl,F32)     /* Function dispatcher for AMCLIB_CurrentLoopSetState_Dsptchr_3, do not modify!!! */
    /* @remarks Implements DAMCLIB00045 */
    #define AMCLIB_CurrentLoop_Dsptchr_3(f32UDcBus,pUDQReq,pCtrl)     AMCLIB_CurrentLoop_Dsptchr_4(f32UDcBus,pUDQReq,pCtrl,F32)     /* Function dispatcher for AMCLIB_CurrentLoop_Dsptchr_3, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define AMCLIB_CURRENT_LOOP_T                                        AMCLIB_CURRENT_LOOP_T_F16
    /* @remarks Implements DAMCLIB00052 */
    #define AMCLIB_CurrentLoopInit_Dsptchr_1(pCtrl)     AMCLIB_CurrentLoopInit_Dsptchr_2(pCtrl,F16)     /* Function dispatcher for AMCLIB_CurrentLoopInit_Dsptchr_1, do not modify!!! */
    /* @remarks Implements DAMCLIB00059 */
    #define AMCLIB_CurrentLoopSetState_Dsptchr_3(arg1,arg2,pCtrl)     AMCLIB_CurrentLoopSetState_Dsptchr_4(arg1,arg2,pCtrl,F16)     /* Function dispatcher for AMCLIB_CurrentLoopSetState_Dsptchr_3, do not modify!!! */
    /* @remarks Implements DAMCLIB00045 */
    #define AMCLIB_CurrentLoop_Dsptchr_3(f16UDcBus,pUDQReq,pCtrl)     AMCLIB_CurrentLoop_Dsptchr_4(f16UDcBus,pUDQReq,pCtrl,F16)     /* Function dispatcher for AMCLIB_CurrentLoop_Dsptchr_3, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_CURRENT_LOOP_T                                        AMCLIB_CURRENT_LOOP_T_FLT
    /* @remarks Implements DAMCLIB00052 */
    #define AMCLIB_CurrentLoopInit_Dsptchr_1(pCtrl)     AMCLIB_CurrentLoopInit_Dsptchr_2(pCtrl,FLT)     /* Function dispatcher for AMCLIB_CurrentLoopInit_Dsptchr_1, do not modify!!! */
    /* @remarks Implements DAMCLIB00059 */
    #define AMCLIB_CurrentLoopSetState_Dsptchr_3(arg1,arg2,pCtrl)     AMCLIB_CurrentLoopSetState_Dsptchr_4(arg1,arg2,pCtrl,FLT)     /* Function dispatcher for AMCLIB_CurrentLoopSetState_Dsptchr_3, do not modify!!! */
    /* @remarks Implements DAMCLIB00045 */
    #define AMCLIB_CurrentLoop_Dsptchr_3(fltUDcBus,pUDQReq,pCtrl)     AMCLIB_CurrentLoop_Dsptchr_4(fltUDcBus,pUDQReq,pCtrl,FLT)     /* Function dispatcher for AMCLIB_CurrentLoop_Dsptchr_3, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
  
  #define AMCLIB_CurrentLoopInit_Dsptchr_2(pCtrl,Impl)    AMCLIB_CurrentLoopInit_Dsptchr_(pCtrl,Impl)     /* Function dispatcher for AMCLIB_CurrentLoopInit_Dsptchr_2, do not modify!!! */
  /* @remarks Implements DAMCLIB00054 */
  #define AMCLIB_CurrentLoopInit_Dsptchr_(pCtrl,Impl)     AMCLIB_CurrentLoopInit_##Impl(pCtrl)            /* Function dispatcher for AMCLIB_CurrentLoopInit_Dsptchr_, do not modify!!! */
  
  #define AMCLIB_CurrentLoopSetState_Dsptchr_4(ControllerPIrAWDOut,ControllerPIrAWQOut,pCtrl,Impl)    AMCLIB_CurrentLoopSetState_Dsptchr_(ControllerPIrAWDOut,ControllerPIrAWQOut,pCtrl,Impl)     /* Function dispatcher for AMCLIB_CurrentLoopSetState_Dsptchr_4, do not modify!!! */
  /* @remarks Implements DAMCLIB00061 */
  #define AMCLIB_CurrentLoopSetState_Dsptchr_(ControllerPIrAWDOut,ControllerPIrAWQOut,pCtrl,Impl)     AMCLIB_CurrentLoopSetState_##Impl(ControllerPIrAWDOut,ControllerPIrAWQOut,pCtrl)            /* Function dispatcher for AMCLIB_CurrentLoopSetState_Dsptchr_, do not modify!!! */
  
  #define AMCLIB_CurrentLoop_Dsptchr_4(UDcBus,pUDQReq,pCtrl,Impl)    AMCLIB_CurrentLoop_Dsptchr_(UDcBus,pUDQReq,pCtrl,Impl)     /* Function dispatcher for AMCLIB_CurrentLoop_Dsptchr_4, do not modify!!! */
  /* @remarks Implements DAMCLIB00047 */
  #define AMCLIB_CurrentLoop_Dsptchr_(UDcBus,pUDQReq,pCtrl,Impl)     AMCLIB_CurrentLoop_##Impl(UDcBus,pUDQReq,pCtrl)            /* Function dispatcher for AMCLIB_CurrentLoop_Dsptchr_, do not modify!!! */
  
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define AMCLIB_CURRENT_LOOP_DEFAULT_F32 { \
    (tFrac32)0,(tFrac32)0,(tS32)0,(tS32)0,SWLIBS_INT32_MIN,SWLIBS_INT32_MAX,(tFrac32)0,(tFrac32)0,(tU16)0, \
    (tFrac32)0,(tFrac32)0,(tS32)0,(tS32)0,SWLIBS_INT32_MIN,SWLIBS_INT32_MAX,(tFrac32)0,(tFrac32)0,(tU16)0, \
    (tFrac32)0,(tFrac32)0, \
    (tFrac32)0,(tFrac32)0,} /**< Default value for AMCLIB_CURRENT_LOOP_T_F32. */

  /************************************************************************/
  /**
  @struct AMCLIB_CURRENT_LOOP_T_F32 "\AMCLIB_CurrentLoop.h" 

  @brief  CurrentLoop configuration structure.
  *//**********************************************************************/
  /* @remarks Implements DAMCLIB00044 */
  typedef struct
  {
    GFLIB_CONTROLLER_PIAW_R_T_F32 pPIrAWD;  /**< D-axis ControllerPIrAW paremeters structure. */
    GFLIB_CONTROLLER_PIAW_R_T_F32 pPIrAWQ;  /**< Q-axis ControllerPIrAW paremeters structure. */
    SWLIBS_2Syst_F32 *pIDQReq;              /**< Pointer to the structure with the required current. */
    SWLIBS_2Syst_F32 *pIDQFbck;             /**< Pointer to the structure with the feedback current. */
  }AMCLIB_CURRENT_LOOP_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_CurrentLoopInit_F32(AMCLIB_CURRENT_LOOP_T_F32 *const pCtrl);
  extern void AMCLIB_CurrentLoopSetState_F32(tFrac32 f32ControllerPIrAWDOut,
    tFrac32 f32ControllerPIrAWQOut, AMCLIB_CURRENT_LOOP_T_F32 *pCtrl);
  extern void AMCLIB_CurrentLoop_F32(tFrac32 f32UDcBus,
    SWLIBS_2Syst_F32 *const pUDQReq, AMCLIB_CURRENT_LOOP_T_F32 *pCtrl);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)

  #define AMCLIB_CURRENT_LOOP_DEFAULT_F16 { \
    (tFrac16)0,(tFrac16)0,(tS16)0,(tS16)0,SWLIBS_INT16_MIN,SWLIBS_INT16_MAX,(tFrac32)0,(tFrac16)0,(tU16)0, \
    (tFrac16)0,(tFrac16)0,(tS16)0,(tS16)0,SWLIBS_INT16_MIN,SWLIBS_INT16_MAX,(tFrac32)0,(tFrac16)0,(tU16)0, \
    (tFrac16)0,(tFrac16)0, \
    (tFrac16)0,(tFrac16)0,}               /**< Default value for AMCLIB_CURRENT_LOOP_T_F16. */
  
  /************************************************************************/
  /**
  @struct AMCLIB_CURRENT_LOOP_T_F16 "\AMCLIB_CurrentLoop.h" 

  @brief  CurrentLoop configuration structure.
  *//**********************************************************************/
  /* @remarks Implements DAMCLIB00044 */
  typedef struct
  {
    GFLIB_CONTROLLER_PIAW_R_T_F16 pPIrAWD;  /**< D-axis ControllerPIrAW paremeters structure. */
    GFLIB_CONTROLLER_PIAW_R_T_F16 pPIrAWQ;  /**< Q-axis ControllerPIrAW paremeters structure. */
    SWLIBS_2Syst_F16 *pIDQReq;              /**< Pointer to the structure with the required current. */
    SWLIBS_2Syst_F16 *pIDQFbck;             /**< Pointer to the structure with the feedback current. */
  }AMCLIB_CURRENT_LOOP_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_CurrentLoopInit_F16(AMCLIB_CURRENT_LOOP_T_F16 *const pCtrl);
  extern void AMCLIB_CurrentLoopSetState_F16(tFrac16 f16ControllerPIrAWDOut,
    tFrac16 f16ControllerPIrAWQOut, AMCLIB_CURRENT_LOOP_T_F16 *pCtrl);
  extern void AMCLIB_CurrentLoop_F16(tFrac16 f16UDcBus,
    SWLIBS_2Syst_F16 *const pUDQReq, AMCLIB_CURRENT_LOOP_T_F16 *pCtrl);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)

  #define AMCLIB_CURRENT_LOOP_DEFAULT_FLT { \
    (tFloat)0,(tFloat)0,FLOAT_MIN,FLOAT_MAX,(tFloat)0,(tFloat)0,(tU16)0, \
    (tFloat)0,(tFloat)0,FLOAT_MIN,FLOAT_MAX,(tFloat)0,(tFloat)0,(tU16)0, \
    (tFloat)0,(tFloat)0, \
    (tFloat)0,(tFloat)0}               /**< Default value for AMCLIB_CURRENT_LOOP_T_FLT. */

  /************************************************************************/
  /**
  @struct AMCLIB_CURRENT_LOOP_T_FLT "\AMCLIB_CurrentLoop.h"

  @brief  CurrentLoop configuration structure.
  *//**********************************************************************/
  /* @remarks Implements DAMCLIB00044 */
  typedef struct
  {
    GFLIB_CONTROLLER_PIAW_R_T_FLT pPIrAWD;  /**< D-axis ControllerPIrAW paremeters structure. */
    GFLIB_CONTROLLER_PIAW_R_T_FLT pPIrAWQ;  /**< Q-axis ControllerPIrAW paremeters structure. */
    SWLIBS_2Syst_FLT *pIDQReq;              /**< Pointer to the structure with the required current. */
    SWLIBS_2Syst_FLT *pIDQFbck;             /**< Pointer to the structure with the feedback current. */
  }AMCLIB_CURRENT_LOOP_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_CurrentLoopInit_FLT(AMCLIB_CURRENT_LOOP_T_FLT *const pCtrl);
  extern void AMCLIB_CurrentLoopSetState_FLT(tFloat fltControllerPIrAWDOut,
    tFloat fltControllerPIrAWQOut, AMCLIB_CURRENT_LOOP_T_FLT *pCtrl);
  extern void AMCLIB_CurrentLoop_FLT(tFloat fltUDcBus,
    SWLIBS_2Syst_FLT *const pUDQReq, AMCLIB_CURRENT_LOOP_T_FLT *pCtrl);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif/* AMCLIB_CURRENTLOOP_H */
