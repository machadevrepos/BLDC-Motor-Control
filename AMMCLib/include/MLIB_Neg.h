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
* @file       MLIB_Neg.h
*
* @brief      Header file for MLIB_Neg function
*
******************************************************************************/
#ifndef MLIB_NEG_H
#define MLIB_NEG_H
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
  #define MLIB_Neg(...)     macro_dispatcher(MLIB_Neg, __VA_ARGS__)(__VA_ARGS__)    /* This function returns negative value of input parameter. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00027 */
    #define MLIB_Neg_Dsptchr_1(In)     MLIB_Neg_Dsptchr_2(In,F32)                   /* Function dispatcher for MLIB_Neg_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00027 */
    #define MLIB_Neg_Dsptchr_1(In)     MLIB_Neg_Dsptchr_2(In,F16)                   /* Function dispatcher for MLIB_Neg_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DMLIB00027 */
    #define MLIB_Neg_Dsptchr_1(In)     MLIB_Neg_Dsptchr_2(In,FLT)                   /* Function dispatcher for MLIB_Neg_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */

  #define MLIB_Neg_Dsptchr_2(In,Impl)    MLIB_Neg_Dsptchr_(In,Impl)     /* Function dispatcher for MLIB_Neg_Dsptchr_2, do not modify!!! */
  
  /* @remarks Implements DMLIB00029 */
  #define MLIB_Neg_Dsptchr_(In,Impl)     MLIB_Neg_##Impl(In)            /* Function dispatcher for MLIB_Neg_Dsptchr_, do not modify!!! */
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

@functionality MLIB_Neg

@param[in]    f32In      Input value which negative value should be returned.

@return       Negative value of input parameter.

@details      The input values as well as output value is considered as 32-bit fractional values.
              The output saturation is not implemented in this function, thus in case the negation
              of input values is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Neg_F32
              \image rtf negF32Eq1.math "MLIB_Neg_F32_Eq1"

@note         This function is implemented as inline, and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In;
tFrac32 f32Out;

void main(void)
{
  // input value = 0.25
  f32In = FRAC32(0.25);

  // output should be FRAC32(-0.25) = 0xA0000000
  f32Out = MLIB_Neg_F32(f32In);

  // output should be FRAC32(-0.25) = 0xA0000000
  f32Out = MLIB_Neg(f32In, F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC32(-0.25) = 0xA0000000
  f32Out = MLIB_Neg(f32In);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00028, DMLIB00021, DMLIB00024, DMLIB00026 */
SWLIBS_INLINE tFrac32 MLIB_Neg_F32(register tFrac32 f32In)
{
    /* @remarks Implements DMLIB00025 */
  #if (defined(__DCC__))
    /* Workaround for diab - this compiler can optimize out the case with signed overflow */
    return((f32In==(tFrac32)0x80000000u) ? ((tFrac32)0x80000000u) : ((tFrac32)(-f32In)));
  #else
    return((tFrac32)(-f32In));
  #endif
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Neg

@param[in]    f16In       Input value which negative value should be returned.

@return       Negative value of input parameter.

@details      The input values as well as output value is considered as 16-bit fractional values.
              The output saturation is not implemented in this function, thus in case the negation
              of input values is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Neg_F16
              \image rtf negF16Eq1.math "MLIB_Neg_F16_Eq1"

@note         This function is implemented as inline, and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In;
tFrac16 f16Out;

void main(void)
{
  // input value = 0.25
  f16In = FRAC16(0.25);

  // output should be FRAC16(-0.25) = 0xA000
  f16Out = MLIB_Neg_F16(f16In);

  // output should be FRAC16(-0.25) = 0xA000
  f16Out = MLIB_Neg(f16In, F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC16(-0.25) = 0xA000
  f16Out = MLIB_Neg(f16In);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00028, DMLIB00021, DMLIB00023, DMLIB00026 */
SWLIBS_INLINE tFrac16 MLIB_Neg_F16(register tFrac16 f16In)
{
    /* @remarks Implements DMLIB00025 */
  #if (defined(__DCC__))
    /* Workaround for diab - this compiler can optimize out the case with signed overflow */
    return((f16In==(tFrac16)0x8000u) ? ((tFrac16)0x8000u) : ((tFrac16)(-f16In)));
  #else
    return((tFrac16)(-f16In));
  #endif
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Neg

@param[in]    fltIn      Input value which negative value should be returned.

@return       Negative value of input parameter.

@details      The input values as well as output value is considered as single precision floating
              point data type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Neg_FLT
              \image rtf negFLTEq1.math "MLIB_Neg_FLT_Eq1"

@note         This function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**
@note         The function may raise floating-point exceptions (invalid operation,
              overflow, underflow, inexact, input denormal). The floating-point unit must be enabled
              in CPACR register to prevent NOCP UsageFault exception.
*/
/**
@par Code Example
\code
#include "mlib.h"

tFloat fltIn;
tFloat fltOut;

void main(void)
{
  // input value = 0.25
  fltIn = (tFloat)0.25;

  // output should be (-0.25)
  fltOut = MLIB_Neg_FLT(fltIn);

  // output should be (-0.25)
  fltOut = MLIB_Neg(fltIn, FLT);

  // ##############################################################
  // Available only if single precision floating point
  // implementation selected as default
  // ##############################################################

  // output should be (-0.25)
  fltOut = MLIB_Neg(fltIn);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00028, DMLIB00021, DMLIB00022, DMLIB00026 */
SWLIBS_INLINE tFloat MLIB_Neg_FLT(register tFloat fltIn)
{
  /* @remarks Implements DMLIB00025 */
  return((tFloat)(-fltIn));
}


#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_NEG_H */
