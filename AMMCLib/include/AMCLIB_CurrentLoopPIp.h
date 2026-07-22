/******************************************************************************
*
*   Copyright 2021-2026 NXP
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
* @file       AMCLIB_CurrentLoopPIp.h
*
* @brief      Header file for AMCLIB_CurrentLoopPIp function
*
******************************************************************************/
#ifndef AMCLIB_CURRENTLOOPPIP_H
#define AMCLIB_CURRENTLOOPPIP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "GFLIB_ControllerPIpAW.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define AMCLIB_CurrentLoopPIpInit(...)     macro_dispatcher(AMCLIB_CurrentLoopPIpInit, __VA_ARGS__)(__VA_ARGS__)
  #define AMCLIB_CurrentLoopPIpSetState(...)     macro_dispatcher(AMCLIB_CurrentLoopPIpSetState, __VA_ARGS__)(__VA_ARGS__)
  #define AMCLIB_CurrentLoopPIp(...)     macro_dispatcher(AMCLIB_CurrentLoopPIp, __VA_ARGS__)(__VA_ARGS__)

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define AMCLIB_CURRENT_LOOP_PIP_T                                        AMCLIB_CURRENT_LOOP_PIP_T_F32
    /* @remarks Implements DAMMCLIB00075 */
    #define AMCLIB_CurrentLoopPIpInit_Dsptchr_1(pCtrl)     AMCLIB_CurrentLoopPIpInit_Dsptchr_2(pCtrl,F32)     /* Function dispatcher, do not modify!!! */
    /* @remarks Implements DAMMCLIB00082 */
    #define AMCLIB_CurrentLoopPIpSetState_Dsptchr_3(ControllerPIpAWDOut,ControllerPIpAWQOut,pCtrl)     AMCLIB_CurrentLoopPIpSetState_Dsptchr_4(ControllerPIpAWDOut,ControllerPIpAWQOut,pCtrl,F32)     /* Function dispatcher for AMCLIB_CurrentLoopPIpSetState_Dsptchr_5, do not modify!!! */
    /* @remarks Implements DAMMCLIB00068 */
    #define AMCLIB_CurrentLoopPIp_Dsptchr_3(UDcBus,pUDQReq,pCtrl)     AMCLIB_CurrentLoopPIp_Dsptchr_4(UDcBus,pUDQReq,pCtrl,F32)     /* Function dispatcher for AMCLIB_CurrentLoopPIp_Dsptchr_5, do not modify!!! */
  #endif 
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define AMCLIB_CURRENT_LOOP_PIP_T                                        AMCLIB_CURRENT_LOOP_PIP_T_F16
    /* @remarks Implements DAMMCLIB00075 */
    #define AMCLIB_CurrentLoopPIpInit_Dsptchr_1(pCtrl)     AMCLIB_CurrentLoopPIpInit_Dsptchr_2(pCtrl,F16)     /* Function dispatcher, do not modify!!! */
    /* @remarks Implements DAMMCLIB00082 */
    #define AMCLIB_CurrentLoopPIpSetState_Dsptchr_3(ControllerPIpAWDOut,ControllerPIpAWQOut,pCtrl)     AMCLIB_CurrentLoopPIpSetState_Dsptchr_4(ControllerPIpAWDOut,ControllerPIpAWQOut,pCtrl,F16)     /* Function dispatcher, do not modify!!! */
    /* @remarks Implements DAMMCLIB00068 */
    #define AMCLIB_CurrentLoopPIp_Dsptchr_3(UDcBus,pUDQReq,pCtrl)     AMCLIB_CurrentLoopPIp_Dsptchr_4(UDcBus,pUDQReq,pCtrl,F16)     /* Function dispatcher, do not modify!!! */
  #endif 
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_CURRENT_LOOP_PIP_T                                        AMCLIB_CURRENT_LOOP_PIP_T_FLT
    /* @remarks Implements DAMMCLIB00075 */
    #define AMCLIB_CurrentLoopPIpInit_Dsptchr_1(pCtrl)     AMCLIB_CurrentLoopPIpInit_Dsptchr_2(pCtrl,FLT)     /* Function dispatcher, do not modify!!! */
    /* @remarks Implements DAMMCLIB00082 */
    #define AMCLIB_CurrentLoopPIpSetState_Dsptchr_3(ControllerPIpAWDOut,ControllerPIpAWQOut,pCtrl)     AMCLIB_CurrentLoopPIpSetState_Dsptchr_4(ControllerPIpAWDOut,ControllerPIpAWQOut,pCtrl,FLT)     /* Function dispatcher, do not modify!!! */
    /* @remarks Implements DAMMCLIB00068 */
    #define AMCLIB_CurrentLoopPIp_Dsptchr_3(UDcBus,pUDQReq,pCtrl)     AMCLIB_CurrentLoopPIp_Dsptchr_4(UDcBus,pUDQReq,pCtrl,FLT)     /* Function dispatcher, do not modify!!! */
  #endif 
  
  #define AMCLIB_CurrentLoopPIpInit_Dsptchr_2(pCtrl,Impl)    AMCLIB_CurrentLoopPIpInit_Dsptchr_(pCtrl,Impl)     /* Function dispatcher, do not modify!!! */
  /* @remarks Implements DAMMCLIB00077 */
  #define AMCLIB_CurrentLoopPIpInit_Dsptchr_(pCtrl,Impl)     AMCLIB_CurrentLoopPIpInit_##Impl(pCtrl)            /* Function dispatcher, do not modify!!! */
  
  #define AMCLIB_CurrentLoopPIpSetState_Dsptchr_4(ControllerPIpAWDOut,ControllerPIpAWQOut,pCtrl,Impl)    AMCLIB_CurrentLoopPIpSetState_Dsptchr_(ControllerPIpAWDOut,ControllerPIpAWQOut,pCtrl,Impl)     /* Function dispatcher, do not modify!!! */
  /* @remarks Implements DAMMCLIB00084 */
  #define AMCLIB_CurrentLoopPIpSetState_Dsptchr_(ControllerPIpAWDOut,ControllerPIpAWQOut,pCtrl,Impl)     AMCLIB_CurrentLoopPIpSetState_##Impl(ControllerPIpAWDOut,ControllerPIpAWQOut,pCtrl)            /* Function dispatcher, do not modify!!! */

  #define AMCLIB_CurrentLoopPIp_Dsptchr_4(UDcBus,pUDQReq,pCtrl,Impl)    AMCLIB_CurrentLoopPIp_Dsptchr_(UDcBus,pUDQReq,pCtrl,Impl)     /* Function dispatcher, do not modify!!! */
  /* @remarks Implements DAMMCLIB00070 */
  #define AMCLIB_CurrentLoopPIp_Dsptchr_(UDcBus,pUDQReq,pCtrl,Impl)     AMCLIB_CurrentLoopPIp_##Impl(UDcBus,pUDQReq,pCtrl)            /* Function dispatcher, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/
/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  /************************************************************************/
  /**
  @struct AMCLIB_CURRENT_LOOP_PIP_T_F32 "\AMCLIB_CurrentLoopPIp.h" 

  @brief  ADD BRIEF DESCRIPTION.
  *//**********************************************************************/
  typedef struct
  {
    GFLIB_CONTROLLER_PIAW_P_T_F32 pPIpAWD;  /**< D-axis ControllerPIpAW paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_F32 pPIpAWQ;  /**< Q-axis ControllerPIpAW paremeters structure. */
    SWLIBS_2Syst_F32 *pIDQReq;              /**< Pointer to the structure with the required current. */
    SWLIBS_2Syst_F32 *pIDQFbck;             /**< Pointer to the structure with the feedback current. */
  }AMCLIB_CURRENT_LOOP_PIP_T_F32;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_CurrentLoopPIpInit_F32(AMCLIB_CURRENT_LOOP_PIP_T_F32 *const pCtrl);
  extern void AMCLIB_CurrentLoopPIpSetState_F32(tFrac32 f32ControllerPIpAWDOut, tFrac32 f32ControllerPIpAWQOut, AMCLIB_CURRENT_LOOP_PIP_T_F32 *pCtrl);
  extern void AMCLIB_CurrentLoopPIp_F32(tFrac32 f32UDcBus, SWLIBS_2Syst_F32 *const pUDQReq, AMCLIB_CURRENT_LOOP_PIP_T_F32 *pCtrl);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */

/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)  
  /************************************************************************/
  /**
  @struct AMCLIB_CURRENT_LOOP_PIP_T_F16 "\AMCLIB_CurrentLoopPIp.h" 

  @brief  ADD BRIEF DESCRIPTION.
  *//**********************************************************************/
  typedef struct
  {
    GFLIB_CONTROLLER_PIAW_P_T_F16 pPIpAWD;  /**< D-axis ControllerPIpAW paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_F16 pPIpAWQ;  /**< Q-axis ControllerPIpAW paremeters structure. */
    SWLIBS_2Syst_F16 *pIDQReq;              /**< Pointer to the structure with the required current. */
    SWLIBS_2Syst_F16 *pIDQFbck;             /**< Pointer to the structure with the feedback current. */
  }AMCLIB_CURRENT_LOOP_PIP_T_F16;
  
/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_CurrentLoopPIpInit_F16(AMCLIB_CURRENT_LOOP_PIP_T_F16 *const pCtrl);
  extern void AMCLIB_CurrentLoopPIpSetState_F16(tFrac16 f16ControllerPIpAWDOut, tFrac16 f16ControllerPIpAWQOut, AMCLIB_CURRENT_LOOP_PIP_T_F16 *pCtrl);
  extern void AMCLIB_CurrentLoopPIp_F16(tFrac16 f16UDcBus, SWLIBS_2Syst_F16 *const pUDQReq, AMCLIB_CURRENT_LOOP_PIP_T_F16 *pCtrl);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */

/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  /************************************************************************/
  /**
  @struct AMCLIB_CURRENT_LOOP_PIP_T_FLT "\AMCLIB_CurrentLoopPIp.h"

  @brief  ADD BRIEF DESCRIPTION.
  *//**********************************************************************/
  typedef struct
  {
    GFLIB_CONTROLLER_PIAW_P_T_FLT pPIpAWD;  /**< D-axis ControllerPIpAW paremeters structure. */
    GFLIB_CONTROLLER_PIAW_P_T_FLT pPIpAWQ;  /**< Q-axis ControllerPIpAW paremeters structure. */
    SWLIBS_2Syst_FLT *pIDQReq;              /**< Pointer to the structure with the required current. */
    SWLIBS_2Syst_FLT *pIDQFbck;             /**< Pointer to the structure with the feedback current. */
  }AMCLIB_CURRENT_LOOP_PIP_T_FLT;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void AMCLIB_CurrentLoopPIpInit_FLT(AMCLIB_CURRENT_LOOP_PIP_T_FLT *const pCtrl);
  extern void AMCLIB_CurrentLoopPIpSetState_FLT(tFloat fltControllerPIpAWDOut, tFloat fltControllerPIpAWQOut, AMCLIB_CURRENT_LOOP_PIP_T_FLT *pCtrl);
  extern void AMCLIB_CurrentLoopPIp_FLT(tFloat fltUDcBus, SWLIBS_2Syst_FLT *const pUDQReq, AMCLIB_CURRENT_LOOP_PIP_T_FLT *pCtrl);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif/* AMCLIB_CURRENTLOOPPIP_H */
