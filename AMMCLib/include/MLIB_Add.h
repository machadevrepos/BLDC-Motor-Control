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
* @file       MLIB_Add.h
*
* @brief      Header file for MLIB_Add function
*
******************************************************************************/
#ifndef MLIB_ADD_H
#define MLIB_ADD_H
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

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_Add(...)     macro_dispatcher(MLIB_Add, __VA_ARGS__)(__VA_ARGS__)     /* This function returns sum of two input parameters. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00048 */
    #define MLIB_Add_Dsptchr_2(In1,In2)     MLIB_Add_Dsptchr_3(In1,In2,F32)       /* Function dispatcher for MLIB_Add_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00048 */
    #define MLIB_Add_Dsptchr_2(In1,In2)     MLIB_Add_Dsptchr_3(In1,In2,F16)       /* Function dispatcher for MLIB_Add_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DMLIB00048 */
    #define MLIB_Add_Dsptchr_2(In1,In2)     MLIB_Add_Dsptchr_3(In1,In2,FLT)       /* Function dispatcher for MLIB_Add_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
  #define MLIB_Add_Dsptchr_3(In1,In2,Impl)    MLIB_Add_Dsptchr_(In1,In2,Impl)     /* Function dispatcher for MLIB_Add_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00050*/
  #define MLIB_Add_Dsptchr_(In1,In2,Impl)     MLIB_Add_##Impl(In1,In2)            /* Function dispatcher for MLIB_Add_Dsptchr_, do not modify!!! */
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
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Add

@param[in]         f32In1     First value to be add.

@param[in]         f32In2     Second value to be add.

@return       Sum of two input values.

@details      The input values as well as output value is considered as 32-bit fractional data type.
              The output saturation is not implemented in this function, thus in case the sum of
              input values is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Add_F32
              \image rtf addF32Eq1.math "MLIB_Add_F32_Eq1"

@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1, f32In2;
tFrac32 f32Out;

void main(void)
{
  // input value 1 = 0.25
  f32In1 = FRAC32(0.25);
  // input value 2 = 0.25
  f32In2 = FRAC32(0.25);

  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_Add_F32(f32In1, f32In2);

  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_Add(f32In1, f32In2, F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_Add(f32In1, f32In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00049, DMLIB00042, DMLIB00045, DMLIB00047 */
SWLIBS_INLINE tFrac32 MLIB_Add_F32(register tFrac32 f32In1, register tFrac32 f32In2)
{
  /* @remarks Implements DMLIB00046 */
  return((tFrac32)((tU32)f32In1 + (tU32)f32In2));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Add

@param[in]         f16In1     First value to be add.

@param[in]         f16In2     Second value to be add.

@return       Sum of two input values.

@details      The input values as well as output value is considered as 16-bit fractional values.
              The output saturation is not implemented in this function, thus in case the sum of
              input values is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Add_F16
              \image rtf addF16Eq1.math "MLIB_Add_F16_Eq1"

@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1, f16In2;
tFrac16 f16Out;

void main(void)
{
  // input value 1 = 0.25
  f16In1 = FRAC16(0.25);
  // input value 2 = 0.25
  f16In2 = FRAC16(0.25);

  // output should be FRAC16(0.5) = 0x4000
  f16Out = MLIB_Add_F16(f16In1, f16In2);

  // output should be FRAC16(0.5) = 0x4000
  f16Out = MLIB_Add(f16In1, f16In2, F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC16(0.5) = 0x4000
  f16Out = MLIB_Add(f16In1, f16In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00049, DMLIB00042, DMLIB00044, DMLIB00047 */
SWLIBS_INLINE tFrac16 MLIB_Add_F16(register tFrac16 f16In1, register tFrac16 f16In2)
{
  /* @remarks Implements DMLIB00046 */
  return((tFrac16)((tU16)f16In1 + (tU16)f16In2));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Add

@param[in]         fltIn1     First value to be add.

@param[in]         fltIn2     Second value to be add.

@return       Sum of two input values.

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

tFloat fltIn1, fltIn2;
tFloat fltOut;

void main(void)
{
  // input value 1 = 0.25
  fltIn1 = (tFloat)0.25;
  // input value 2 = 0.25
  fltIn2 = (tFloat)0.25;

  // output should be 0.5
  fltOut = MLIB_Add_FLT(fltIn1, fltIn2);

  // output should be 0.5
  fltOut = MLIB_Add(fltIn1, fltIn2, FLT);

  // ##############################################################
  // Available only if single precision floating point
  // implementation selected as default
  // ##############################################################

  // output should be 0.5
  fltOut = MLIB_Add(fltIn1, fltIn2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00049, DMLIB00042, DMLIB00043, DMLIB00047 */
SWLIBS_INLINE tFloat MLIB_Add_FLT(register tFloat fltIn1, register tFloat fltIn2)
{
  /* @remarks Implements DMLIB00046 */
  return((tFloat)(fltIn1 + fltIn2));
}

#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_ADD_H */
