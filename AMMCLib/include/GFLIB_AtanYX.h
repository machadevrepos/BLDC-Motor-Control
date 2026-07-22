/******************************************************************************
*
*   Copyright 2013-2015 Freescale Semiconductor
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
* @file       GFLIB_AtanYX.h
*
* @brief      Header file for GFLIB_AtanYX function
*
******************************************************************************/
#ifndef GFLIB_ATANYX_H
#define GFLIB_ATANYX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "GFLIB_Atan.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define GFLIB_AtanYX(...)     macro_dispatcher(GFLIB_AtanYX, __VA_ARGS__)(__VA_ARGS__)     /* This function calculate the angle between the positive x-axis and the direction of a vector given by the (x, y) coordinates. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DGFLIB00087 */
    #define GFLIB_AtanYX_Dsptchr_2(InY,InX)     GFLIB_AtanYX_Dsptchr_3(InY,InX,F32)     /* Function dispatcher for GFLIB_AtanYX_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DGFLIB00087 */
    #define GFLIB_AtanYX_Dsptchr_2(InY,InX)     GFLIB_AtanYX_Dsptchr_3(InY,InX,F16)     /* Function dispatcher for GFLIB_AtanYX_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DGFLIB00087 */
    #define GFLIB_AtanYX_Dsptchr_2(InY,InX)     GFLIB_AtanYX_Dsptchr_3(InY,InX,FLT)     /* Function dispatcher for GFLIB_AtanYX_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */

  #define GFLIB_AtanYX_Dsptchr_3(InY,InX,Impl)    GFLIB_AtanYX_Dsptchr_(InY,InX,Impl)     /* Function dispatcher for GFLIB_AtanYX_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DGFLIB00089 */
  #define GFLIB_AtanYX_Dsptchr_(InY,InX,Impl)     GFLIB_AtanYX_##Impl(InY,InX)            /* Function dispatcher for GFLIB_AtanYX_Dsptchr_, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */
 
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
  extern tFrac32 GFLIB_AtanYX_F32(tFrac32 f32InY,tFrac32 f32InX);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac16 GFLIB_AtanYX_F16(tFrac16 f16InY,tFrac16 f16InX);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFloat GFLIB_AtanYX_FLT(tFloat fltInY,tFloat fltInX);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_ATANYX_H */
