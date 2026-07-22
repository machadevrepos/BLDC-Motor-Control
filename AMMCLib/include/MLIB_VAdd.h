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
* @file       MLIB_VAdd.h
*
* @brief      Header file for MLIB_VAdd function
*
******************************************************************************/
#ifndef MLIB_VADD_H
#define MLIB_VADD_H
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
  #include "MLIB_AddSat.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_Add.h"
  #include "CCOV_MLIB_AddSat.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_VAdd(...)     macro_dispatcher(MLIB_VAdd, __VA_ARGS__)(__VA_ARGS__)     /* This function returns sum of two input parameters. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00295 */
    #define MLIB_VAdd_Dsptchr_3(Out,In1,In2)     MLIB_VAdd_Dsptchr_4(Out,In1,In2,F32)       /* Function dispatcher for MLIB_VAdd_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00295 */
    #define MLIB_VAdd_Dsptchr_3(Out,In1,In2)     MLIB_VAdd_Dsptchr_4(Out,In1,In2,F16)       /* Function dispatcher for MLIB_VAdd_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DMLIB00295 */
    #define MLIB_VAdd_Dsptchr_3(Out,In1,In2)     MLIB_VAdd_Dsptchr_4(Out,In1,In2,FLT)       /* Function dispatcher for MLIB_VAdd_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
  #define MLIB_VAdd_Dsptchr_4(Out,In1,In2,Impl)    MLIB_VAdd_Dsptchr_(Out,In1,In2,Impl)     /* Function dispatcher for MLIB_VAdd_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00297*/
  #define MLIB_VAdd_Dsptchr_(Out,In1,In2,Impl)     MLIB_VAdd_##Impl(Out,In1,In2)            /* Function dispatcher for MLIB_VAdd_Dsptchr_, do not modify!!! */
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
SWLIBS_INLINE void VAdd_F32_C(SWLIBS_2Syst_F32 *const f32Out, const SWLIBS_2Syst_F32 *const f32In1, const SWLIBS_2Syst_F32 *const f32In2)
{
  f32Out->f32Arg1 = MLIB_AddSat_F32(f32In1->f32Arg1, f32In2->f32Arg1);
  f32Out->f32Arg2 = MLIB_AddSat_F32(f32In1->f32Arg2, f32In2->f32Arg2);
}
#endif /* (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON) */
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE void VAdd_F16_C(SWLIBS_2Syst_F16 *const f16Out, const SWLIBS_2Syst_F16 *const f16In1, const SWLIBS_2Syst_F16 *const f16In2)
{
  f16Out->f16Arg1 = MLIB_AddSat_F16(f16In1->f16Arg1, f16In2->f16Arg1);
  f16Out->f16Arg2 = MLIB_AddSat_F16(f16In1->f16Arg2, f16In2->f16Arg2);
}
#endif /* (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON) */
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_VAdd

@param[out]        f32Out     Sum of two input vectors.

@param[in]         f32In1     First vector to be added.

@param[in]         f32In2     Second vector to be added.

@details      The input values as well as output value is considered as vectors defined by two 
              32-bit fractional coordinates stored in SWLIBS_2Syst_F32 structure.

@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

SWLIBS_2Syst_F32 f32In1, f32In2;
SWLIBS_2Syst_F32 f32Out;

void main(void)
{
  // input vector 1 = (0.25,0.25)
  f32In1.f32Arg1 = FRAC32(0.25);
  f32In1.f32Arg2 = FRAC32(0.25);
  // input vector 2 = (0.25,0.25)
  f32In2.f32Arg1 = FRAC32(0.25);
  f32In2.f32Arg2 = FRAC32(0.25);

  // Both f32Out.f32Arg1 and f32Out.f32Arg2 should be FRAC32(0.5) = 0x40000000
  MLIB_VAdd_F32(&f32Out, &f32In1, &f32In2);

  // Both f32Out.f32Arg1 and f32Out.f32Arg2 should be FRAC32(0.5) = 0x40000000
  MLIB_VAdd(&f32Out, &f32In1, &f32In2, F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // Both f32Out.f32Arg1 and f32Out.f32Arg2 should be FRAC32(0.5) = 0x40000000
  MLIB_VAdd(&f32Out, &f32In1, &f32In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00291, DMLIB00294, DMLIB00296 */
SWLIBS_INLINE void MLIB_VAdd_F32(SWLIBS_2Syst_F32 *const f32Out, const SWLIBS_2Syst_F32 *const f32In1, const SWLIBS_2Syst_F32 *const f32In2)
{
  VAdd_F32_C(f32Out, f32In1, f32In2);
}





#endif /* (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON) */
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_VAdd

@param[out]        f16Out     Sum of two input vectors.

@param[in]         f16In1     First vector to be added.

@param[in]         f16In2     Second vector to be added.

@details      The input values as well as output value is considered as vectors defined by two 
              16-bit fractional coordinates stored in SWLIBS_2Syst_F16 structure.

@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

SWLIBS_2Syst_F16 f16In1, f16In2;
SWLIBS_2Syst_F16 f16Out;

void main(void)
{
  // input vector 1 = (0.25,0.25)
  f16In1.f16Arg1 = FRAC16(0.25);
  f16In1.f16Arg2 = FRAC16(0.25);
  // input vector 2 = (0.25,0.25)
  f16In2.f16Arg1 = FRAC16(0.25);
  f16In2.f16Arg2 = FRAC16(0.25);

  // Both f16Out.f16Arg1 and f16Out.f16Arg2 should be FRAC16(0.5) = 0x4000
  MLIB_VAdd_F16(&f16Out, &f16In1, &f16In2);

  // Both f16Out.f16Arg1 and f16Out.f16Arg2 should be FRAC16(0.5) = 0x4000
  MLIB_VAdd(&f16Out, &f16In1, &f16In2, F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // Both f16Out.f16Arg1 and f16Out.f16Arg2 should be FRAC16(0.5) = 0x4000
  MLIB_VAdd(&f16Out, &f16In1, &f16In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00291, DMLIB00293, DMLIB00296 */
SWLIBS_INLINE void MLIB_VAdd_F16(SWLIBS_2Syst_F16 *const f16Out, const SWLIBS_2Syst_F16 *const f16In1, const SWLIBS_2Syst_F16 *const f16In2)
{
  VAdd_F16_C(f16Out, f16In1, f16In2);
}





#endif /* (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON) */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_VAdd

@param[out]        fltOut     Sum of two input vectors.

@param[in]         fltIn1     First vector to be added.

@param[in]         fltIn2     Second vector to be added.

@details      The input values as well as output value is considered as vectors defined by two 
              single precision floating-point coordinates stored in SWLIBS_2Syst_FLT structure.

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

SWLIBS_2Syst_FLT fltIn1, fltIn2;
SWLIBS_2Syst_FLT fltOut;

void main(void)
{
  // input vector 1 = (0.25,0.25)
  fltIn1.fltArg1 = 0.25;
  fltIn1.fltArg2 = 0.25;
  // input vector 2 = (0.25,0.25)
  fltIn2.fltArg1 = 0.25;
  fltIn2.f1tArg2 = 0.25;

  // Both fltOut.fltArg1 and fltOut.fltArg2 should be 0.5
  MLIB_VAdd_FLT(&fltOut, &fltIn1, &fltIn2);

  // Both fltOut.fltArg1 and fltOut.fltArg2 should be 0.5
  MLIB_VAdd(&fltOut, &fltIn1, &fltIn2, FLT);

  // ##############################################################
  // Available only if single precision floating-point
  // implementation selected as default
  // ##############################################################

  // Both fltOut.fltArg1 and fltOut.fltArg2 should be 0.5
  MLIB_VAdd(&fltOut, &fltIn1, &fltIn2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00291, DMLIB00292, DMLIB00296 */
SWLIBS_INLINE void MLIB_VAdd_FLT(SWLIBS_2Syst_FLT *const fltOut, const SWLIBS_2Syst_FLT *const fltIn1, const SWLIBS_2Syst_FLT *const fltIn2)
{
  fltOut->fltArg1 = MLIB_Add_FLT(fltIn1->fltArg1, fltIn2->fltArg1);
  fltOut->fltArg2 = MLIB_Add_FLT(fltIn1->fltArg2, fltIn2->fltArg2);
}

#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_VADD_H */
