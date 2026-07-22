/******************************************************************************
*
*   Copyright 2019-2026 NXP
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
* @file       GMCLIB_BetaProjection3Ph.h
*
* @brief      Header file for GSWLIBS_BetaProjection3Ph function
*
******************************************************************************/
#ifndef GMCLIB_BETAPROJECTION3PH_H
#define GMCLIB_BETAPROJECTION3PH_H

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
  #define GMCLIB_BetaProjection3Ph(...)     macro_dispatcher(GMCLIB_BetaProjection3Ph, __VA_ARGS__)(__VA_ARGS__)     /* This function implements the Beta Projection transformation. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DAMMCLIB00011 */
    #define GMCLIB_BetaProjection3Ph_Dsptchr_2(pOut,pIn)     GMCLIB_BetaProjection3Ph_Dsptchr_3(pOut,pIn,F32)     /* Function dispatcher for GMCLIB_BetaProjection3Ph_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DAMMCLIB00011 */
    #define GMCLIB_BetaProjection3Ph_Dsptchr_2(pOut,pIn)     GMCLIB_BetaProjection3Ph_Dsptchr_3(pOut,pIn,F16)     /* Function dispatcher for GMCLIB_BetaProjection3Ph_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DAMMCLIB00011 */
    #define GMCLIB_BetaProjection3Ph_Dsptchr_2(pOut,pIn)     GMCLIB_BetaProjection3Ph_Dsptchr_3(pOut,pIn,FLT)     /* Function dispatcher for GMCLIB_BetaProjection3Ph_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */

  #define GMCLIB_BetaProjection3Ph_Dsptchr_3(pOut,pIn,Impl)    GMCLIB_BetaProjection3Ph_Dsptchr_(pOut,pIn,Impl)   /* Function dispatcher for GMCLIB_BetaProjection3Ph_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DAMMCLIB00013 */
  #define GMCLIB_BetaProjection3Ph_Dsptchr_(pOut,pIn,Impl)     GMCLIB_BetaProjection3Ph_##Impl(pOut,pIn)          /* Function dispatcher for GMCLIB_BetaProjection3Ph_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GMCLIB_BetaProjection3Ph_F32(SWLIBS_3Syst_F32 *const pOut, const SWLIBS_3Syst_F32 *const pIn);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GMCLIB_BetaProjection3Ph_F16(SWLIBS_3Syst_F16 *const pOut, const SWLIBS_3Syst_F16 *const pIn);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GMCLIB_BetaProjection3Ph_FLT(SWLIBS_3Syst_FLT *const pOut, const SWLIBS_3Syst_FLT *const pIn);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GMCLIB_BETAPROJECTION3PH_H */
