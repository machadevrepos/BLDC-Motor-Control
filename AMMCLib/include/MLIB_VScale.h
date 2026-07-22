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
* @file       MLIB_VScale.h
*
* @brief      Header file for MLIB_VScale function
*
******************************************************************************/
#ifndef MLIB_VSCALE_H
#define MLIB_VSCALE_H
/**
@if MLIB_GROUP
    @addtogroup MLIB_GROUP
@else
    @defgroup MLIB_GROUP   MLIB
@endif
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Defines.h"
#ifndef AMMCLIB_TESTING_ENV
  #include "MLIB_MulSat.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_Mul.h"
  #include "CCOV_MLIB_MulSat.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_VScale(...)     macro_dispatcher(MLIB_VScale, __VA_ARGS__)(__VA_ARGS__)     /* This function returns sum of two input parameters. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00309 */
    #define MLIB_VScale_Dsptchr_3(Out,In1,In2)     MLIB_VScale_Dsptchr_4(Out,In1,In2,F32)       /* Function dispatcher for MLIB_VScale_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00309 */
    #define MLIB_VScale_Dsptchr_3(Out,In1,In2)     MLIB_VScale_Dsptchr_4(Out,In1,In2,F16)       /* Function dispatcher for MLIB_VScale_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DMLIB00309 */
    #define MLIB_VScale_Dsptchr_3(Out,In1,In2)     MLIB_VScale_Dsptchr_4(Out,In1,In2,FLT)       /* Function dispatcher for MLIB_VScale_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
  #define MLIB_VScale_Dsptchr_4(Out,In1,In2,Impl)    MLIB_VScale_Dsptchr_(Out,In1,In2,Impl)     /* Function dispatcher for MLIB_VScale_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00311*/
  #define MLIB_VScale_Dsptchr_(Out,In1,In2,Impl)     MLIB_VScale_##Impl(Out,In1,In2)            /* Function dispatcher for MLIB_VScale_Dsptchr_, do not modify!!! */
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
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE void VScale_F32_C(SWLIBS_2Syst_F32 *const f32OutVec, const SWLIBS_2Syst_F32 *const f32InVec, tFrac32 f32InScale)
{
  f32OutVec->f32Arg1 = MLIB_MulSat_F32(f32InVec->f32Arg1, f32InScale);
  f32OutVec->f32Arg2 = MLIB_MulSat_F32(f32InVec->f32Arg2, f32InScale);
}
#endif /* (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON) */
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE void VScale_F16_C(SWLIBS_2Syst_F16 *const f16OutVec, const SWLIBS_2Syst_F16 *const f16InVec, tFrac16 f16InScale)
{
  f16OutVec->f16Arg1 = MLIB_MulSat_F16(f16InVec->f16Arg1, f16InScale);
  f16OutVec->f16Arg2 = MLIB_MulSat_F16(f16InVec->f16Arg2, f16InScale);
}
#endif /* (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON) */

#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_VScale

@param[out]        f32OutVec  Scaled vector.

@param[in]         f32InVec   Input vector to be scaled.

@param[in]         f32InScale Scaling coefficient.

@details      The first input as well as output value are considered as vectors defined by two 
              32-bit fractional coordinates stored in SWLIBS_2Syst_F32 structure. Input vector
              is scaled by second scalar input in 32-bit fractional format.
              If the output value should be outside the [-1,1) interval, the value is saturated.

@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

SWLIBS_2Syst_F32 f32InVec;
tFrac32 f32InScale;
SWLIBS_2Syst_F32 f32Out;

void main(void)
{
  // input vector = (0.5,0.5)
  f32InVec.f32Arg1 = FRAC32(0.5);
  f32InVec.f32Arg2 = FRAC32(0.5);
  // input scale = 0.5
  f32InScale = FRAC32(0.5);

  // Both f32Out.f32Arg1 and f32Out.f32Arg2 should be FRAC32(0.25) = 0x20000000
  MLIB_VScale_F32(&f32Out, &f32InVec, f32InScale);

  // Both f32Out.f32Arg1 and f32Out.f32Arg2 should be FRAC32(0.25) = 0x20000000
  MLIB_VScale(&f32Out, &f32InVec, f32InScale, F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // Both f32Out.f32Arg1 and f32Out.f32Arg2 should be FRAC32(0.25) = 0x20000000
  MLIB_VScale(&f32Out, &f32InVec, f32InScale);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00305, DMLIB00308, DMLIB00310 */
SWLIBS_INLINE void MLIB_VScale_F32(SWLIBS_2Syst_F32 *const f32OutVec, const SWLIBS_2Syst_F32 *const f32InVec, tFrac32 f32InScale)
{
  VScale_F32_C(f32OutVec, f32InVec, f32InScale);
}





#endif /* (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON) */
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_VScale

@param[out]        f16OutVec  Scaled vector.

@param[in]         f16InVec   Input vector to be scaled.

@param[in]         f16InScale Scaling coefficient.

@details      The first input as well as output value are considered as vectors defined by two 
              16-bit fractional coordinates stored in SWLIBS_2Syst_F16 structure. Input vector
              is scaled by second scalar input in 16-bit fractional format.
              If the output value should be outside the [-1,1) interval, the value is saturated.

@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

SWLIBS_2Syst_F16 f16InVec;
tFrac16 f16InScale;
SWLIBS_2Syst_F16 f16Out;

void main(void)
{
  // input vector 1 = (0.5,0.5)
  f16InVec.f16Arg1 = FRAC16(0.5);
  f16InVec.f16Arg2 = FRAC16(0.5);
  // input scale = 0.5
  f16InScale = FRAC16(0.5);

  // Both f16Out.f16Arg1 and f16Out.f16Arg2 should be FRAC16(0.25) = 0x2000
  MLIB_VScale_F16(&f16Out, &f16InVec, f16InScale);

  // Both f16Out.f16Arg1 and f16Out.f16Arg2 should be FRAC16(0.25) = 0x2000
  MLIB_VScale(&f16Out, &f16InVec, f16InScale, F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // Both f16Out.f16Arg1 and f16Out.f16Arg2 should be FRAC16(0.25) = 0x2000
  MLIB_VScale(&f16Out, &f16InVec, f16InScale);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00305, DMLIB00307, DMLIB00310 */
SWLIBS_INLINE void MLIB_VScale_F16(SWLIBS_2Syst_F16 *const f16OutVec, const SWLIBS_2Syst_F16 *const f16InVec, tFrac16 f16InScale)
{
  VScale_F16_C(f16OutVec, f16InVec, f16InScale);
}





#endif /* (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON) */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_VScale

@param[out]        fltOutVec  Scaled vector.

@param[in]         fltInVec   Input vector to be scaled.

@param[in]         fltInScale Scaling coefficient.

@details      The first input as well as output value are considered as vectors defined by two 
              single precision floating-point coordinates stored in SWLIBS_2Syst_FLT structure.
              Input vector is scaled by second scalar input in single precision floating-point
              format.

*/
/**
@note         The function may raise floating-point exceptions (invalid operation,
              overflow, underflow, inexact, input denormal). The floating-point unit must be enabled
              in CPACR register to prevent NOCP UsageFault exception.
*/
/**
@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

SWLIBS_2Syst_FLT fltInVec;
tFloat fltInScale;
SWLIBS_2Syst_FLT fltOut;

void main(void)
{
  // input vector 1 = (0.5,0.5)
  fltInVec.fltArg1 = 0.5;
  fltInVec.fltArg2 = 0.5;
  // input scale = 0.5
  fltInScale = 0.5;

  // Both fltOut.fltArg1 and fltOut.fltArg2 should be 0.25
  MLIB_VScale_FLT(&fltOut, &fltInVec, fltInScale);

  // Both fltOut.fltArg1 and fltOut.fltArg2 should be 0.25
  MLIB_VScale(&fltOut, &fltInVec, fltInScale, FLT);

  // ##############################################################
  // Available only if single precision floating-point
  // implementation selected as default
  // ##############################################################

  // Both fltOut.fltArg1 and fltOut.fltArg2 should be 0.25
  MLIB_VScale(&fltOut, &fltInVec, fltInScale);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00305, DMLIB00306, DMLIB00310 */
SWLIBS_INLINE void MLIB_VScale_FLT(SWLIBS_2Syst_FLT *const fltOutVec, const SWLIBS_2Syst_FLT *const fltInVec, tFloat fltInScale)
{
  fltOutVec->fltArg1 = MLIB_Mul_FLT(fltInVec->fltArg1, fltInScale);
  fltOutVec->fltArg2 = MLIB_Mul_FLT(fltInVec->fltArg2, fltInScale);
}

#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_VSCALE_H */
