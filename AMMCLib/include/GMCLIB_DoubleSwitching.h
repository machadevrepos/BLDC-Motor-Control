/******************************************************************************
*
*   Copyright 2020-2026 NXP
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
* @file       GMCLIB_DoubleSwitching.h
*
* @brief      Header file for GMCLIB_DoubleSwitching function
*
******************************************************************************/
#ifndef GMCLIB_DOUBLESWITCHING_H
#define GMCLIB_DOUBLESWITCHING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define GMCLIB_DoubleSwitching(...)     macro_dispatcher(GMCLIB_DoubleSwitching, __VA_ARGS__)(__VA_ARGS__)     /* This function implements the Beta Projection transformation. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DGMCLIB00131 */
    #define GMCLIB_DoubleSwitching_Dsptchr_5(OutEdges,OutTriggers,InPwm,Sector,pParam)     GMCLIB_DoubleSwitching_Dsptchr_6(OutEdges,OutTriggers,InPwm,Sector,pParam,F16)     /* Function dispatcher for GMCLIB_DoubleSwitching_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */

  #define GMCLIB_DoubleSwitching_Dsptchr_6(OutEdges,OutTriggers,InPwm,Sector,pParam,Impl)    GMCLIB_DoubleSwitching_Dsptchr_(OutEdges,OutTriggers,InPwm,Sector,pParam,Impl)   /* Function dispatcher for GMCLIB_DoubleSwitching_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DGMCLIB00133 */
  #define GMCLIB_DoubleSwitching_Dsptchr_(OutEdges,OutTriggers,InPwm,Sector,pParam,Impl)     GMCLIB_DoubleSwitching_##Impl(OutEdges,OutTriggers,InPwm,Sector,pParam)          /* Function dispatcher for GMCLIB_DoubleSwitching_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
/************************************************************************/
/**
@struct GMCLIB_DOUBLESWITCHING_EDGES_T_F16 "\GMCLIB_DoubleSwitching.h" 

@brief  Structure of PWM edges for two modulators.
*//**********************************************************************/
typedef struct GMCLIB_DOUBLESWITCHING_EDGES_T_F16
{
	tFrac16		f16Edge1; /**< First edge for the first modulator */
	tFrac16		f16Edge2; /**< Second edge for the first modulator */
  tFrac16		f16Edge3; /**< First edge for the second modulator */
	tFrac16		f16Edge4; /**< Second edge for the second modulator */
}GMCLIB_DOUBLESWITCHING_EDGES_T_F16;

/**
@struct GMCLIB_DOUBLESWITCHING_3PH_EDGES_T_F16 "\GMCLIB_DoubleSwitching.h" 

@brief  Structure of PWM edges for each phase of the three-phase system.
*//**********************************************************************/
typedef struct GMCLIB_DOUBLESWITCHING_3PH_EDGES_T_F16
{
	GMCLIB_DOUBLESWITCHING_EDGES_T_F16	pPhA; /**< PWM edges for phase A */
	GMCLIB_DOUBLESWITCHING_EDGES_T_F16	pPhB; /**< PWM edges for phase B */
	GMCLIB_DOUBLESWITCHING_EDGES_T_F16	pPhC; /**< PWM edges for phase C */
}GMCLIB_DOUBLESWITCHING_3PH_EDGES_T_F16;

/**
@struct GMCLIB_DOUBLESWITCHING_TRIGGERS_T_F16 "\GMCLIB_DoubleSwitching.h" 

@brief  Structure of ADC triggers for triggering unit.
*//**********************************************************************/
typedef struct GMCLIB_DOUBLESWITCHING_TRIGGERS_T_F16
{
  tU16	u16Trigger1; /**< First trigger */
  tU16	u16Trigger2; /**< Second trigger */
  tU16	u16Trigger3; /**< Third trigger */
  tU16	u16Trigger4; /**< Fourth trigger */
}GMCLIB_DOUBLESWITCHING_TRIGGERS_T_F16;

/**
@struct GMCLIB_DOUBLESWITCHING_T_F16 "\GMCLIB_DoubleSwitching.h" 

@brief  Configuration structure for double switching algorithm.
*//**********************************************************************/
typedef struct GMCLIB_DOUBLESWITCHING_T_F16
{
  tFrac16 f16MinZeroPulse;      /**< The minimal pulse inserted to the middle of the PWM period
                                     of double-switching signal. User has to consider at least one deadtime
                                     to be included in this value. Value is stored as 16-bit fixed point number. */
  tFrac16 f16MinSamplingPulse;  /**< Represents at least the minimal conversion time of ADC (is a sum
                                     of "sample&hold" time and "successive approximation" time). Additional
                                     delays such as ADC pre-trigger delay or delays between two subsequent
                                     triggers caused by the triggering unit should be included as well.
                                     Value is stored as 16-bit fixed point number. */
  tFrac16 f16SampleNhold;       /**< The minimal "sample&hold" time of the ADC represented by 16-bit fixed point value. */
}GMCLIB_DOUBLESWITCHING_T_F16;
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */

/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/****************************************************************************
* Exported function prototypes
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
extern void GMCLIB_DoubleSwitching_F16(GMCLIB_DOUBLESWITCHING_3PH_EDGES_T_F16 *const pOutEdges, GMCLIB_DOUBLESWITCHING_TRIGGERS_T_F16 *const pOutTriggers, const SWLIBS_3Syst_F16 *const pInPwm, tU16 u16Sector, const GMCLIB_DOUBLESWITCHING_T_F16 *const pParam);

#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */

/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GMCLIB_DOUBLESWITCHING_H */
