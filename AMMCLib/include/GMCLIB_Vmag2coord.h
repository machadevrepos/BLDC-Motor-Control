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
* @file       GMCLIB_Vmag2coord.h
*
* @brief      Header file for GMCLIB_Vmag2coord function
*
******************************************************************************/
#ifndef GMCLIB_VMAG2COORD_H
#define GMCLIB_VMAG2COORD_H
/**
@if GMCLIB_GROUP
    @addtogroup GMCLIB_GROUP
@else
    @defgroup GMCLIB_GROUP   GMCLIB
@endif
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Defines.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define GMCLIB_Vmag2coord(...)     macro_dispatcher(GMCLIB_Vmag2coord, __VA_ARGS__)(__VA_ARGS__)     /* This function returns sum of two input parameters. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DGMCLIB00138 */
    #define GMCLIB_Vmag2coord_Dsptchr_2(In1,In2)     GMCLIB_Vmag2coord_Dsptchr_3(In1,In2,F32)       /* Function dispatcher for GMCLIB_Vmag2coord_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DGMCLIB00138 */
    #define GMCLIB_Vmag2coord_Dsptchr_2(In1,In2)     GMCLIB_Vmag2coord_Dsptchr_3(In1,In2,F16)       /* Function dispatcher for GMCLIB_Vmag2coord_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DGMCLIB00138 */
    #define GMCLIB_Vmag2coord_Dsptchr_2(In1,In2)     GMCLIB_Vmag2coord_Dsptchr_3(In1,In2,FLT)       /* Function dispatcher for GMCLIB_Vmag2coord_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
  #define GMCLIB_Vmag2coord_Dsptchr_3(In1,In2,Impl)    GMCLIB_Vmag2coord_Dsptchr_(In1,In2,Impl)     /* Function dispatcher for GMCLIB_Vmag2coord_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DGMCLIB00140*/
  #define GMCLIB_Vmag2coord_Dsptchr_(In1,In2,Impl)     GMCLIB_Vmag2coord_##Impl(In1,In2)            /* Function dispatcher for GMCLIB_Vmag2coord_Dsptchr_, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* Inline functions
****************************************************************************/


/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
extern tFrac32 GMCLIB_Vmag2coord_F32(tFrac32 f32InMag, tFrac32 f32InCoord);

#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */
/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
extern tFrac16 GMCLIB_Vmag2coord_F16(tFrac16 f16InMag, tFrac16 f16InCoord);

#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
extern tFloat GMCLIB_Vmag2coord_FLT(tFloat fltInMag, tFloat fltInCoord);

#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* GMCLIB_VMAG2COORD_H */
