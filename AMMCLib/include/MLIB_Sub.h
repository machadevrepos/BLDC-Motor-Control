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
* @file       MLIB_Sub.h
*
* @brief      Header file for MLIB_Sub function
*
******************************************************************************/
#ifndef MLIB_SUB_H
#define MLIB_SUB_H
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
  #define MLIB_Sub(...)     macro_dispatcher(MLIB_Sub, __VA_ARGS__)(__VA_ARGS__)     /* This function subtracts the second parameter from the first one. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00069 */
    #define MLIB_Sub_Dsptchr_2(In1,In2)     MLIB_Sub_Dsptchr_3(In1,In2,F32)     /* Function dispatcher for MLIB_Sub_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00069 */
    #define MLIB_Sub_Dsptchr_2(In1,In2)     MLIB_Sub_Dsptchr_3(In1,In2,F16)     /* Function dispatcher for MLIB_Sub_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DMLIB00069 */
    #define MLIB_Sub_Dsptchr_2(In1,In2)     MLIB_Sub_Dsptchr_3(In1,In2,FLT)     /* Function dispatcher for MLIB_Sub_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */

  #define MLIB_Sub_Dsptchr_3(In1,In2,Impl)    MLIB_Sub_Dsptchr_(In1,In2,Impl)     /* Function dispatcher for MLIB_Sub_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00071 */
  #define MLIB_Sub_Dsptchr_(In1,In2,Impl)     MLIB_Sub_##Impl(In1,In2)            /* Function dispatcher for MLIB_Sub_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

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

@functionality MLIB_Sub

@param[in]    f32In1     Operand is a 32-bit number normalized between[-1,1).

@param[in]    f32In2     Operand is a 32-bit number normalized between[-1,1).

@return       The subtraction of the second argument from the first argument.

@details      The input values as well as output value are considered as 32-bit fractional data
              type. The output saturation is not implemented in this function, thus in case the
              subtraction of input parameters is outside the
              [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Sub_F32
              \image rtf subF32Eq1.math "MLIB_Sub_F32_Eq1"

@note         This function is implemented as inline and thus is
              not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac32 f32In2;
tFrac32 f32Out;

void main(void)
{
  // first input = 0.5
  f32In1 = FRAC32(0.5);

  // second input = 0.25
  f32In2 = FRAC32(0.25);

  // output should be 0x20000000
  f32Out = MLIB_Sub_F32(f32In1,f32In2);

  // output should be 0x20000000
  f32Out = MLIB_Sub(f32In1,f32In2,F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x20000000
  f32Out = MLIB_Sub(f32In1,f32In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00070, DMLIB00063, DMLIB00066, DMLIB00068 */
SWLIBS_INLINE tFrac32 MLIB_Sub_F32(register tFrac32 f32In1,register tFrac32 f32In2)
{
  /* @remarks Implements DMLIB00067 */
  return((tFrac32)((tU32)f32In1 - (tU32)f32In2));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Sub

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       The subtraction of the second argument from the first argument.

@details      The input values as well as output value are considered as 16-bit fractional data
              type. The output saturation is not implemented in this function, thus in case the
              subtraction of input parameters is outside the [-1, 1) interval, the output value will
              overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Sub_F16
              \image rtf subF16Eq1.math "MLIB_Sub_F16_Eq1"

@note         This function is implemented as inline and thus is
              not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac16 f16Out;

void main(void)
{
  // first input = 0.5
  f16In1 = FRAC16(0.5);

  // second input = 0.25
  f16In2 = FRAC16(0.25);

  // output should be 0x2000
  f16Out = MLIB_Sub_F16(f16In1,f16In2);

  // output should be 0x2000
  f16Out = MLIB_Sub(f16In1,f16In2,F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x20000000
  f16Out = MLIB_Sub(f16In1,f16In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00070, DMLIB00063, DMLIB00065, DMLIB00068 */
SWLIBS_INLINE tFrac16 MLIB_Sub_F16(register tFrac16 f16In1,register tFrac16 f16In2)
{
  /* @remarks Implements DMLIB00067 */
  return((tFrac16)((tU16)f16In1 - (tU16)f16In2));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Sub

@param[in]    fltIn1     Operand is a single precision floating point number.

@param[in]    fltIn2     Operand is a single precision floating point number.

@return       The subtraction of the second argument from the first argument.

@details      The input value as well as output value is considered as single precision floating
              point data type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Sub_FLT
              \image rtf subFLTEq1.math "MLIB_Sub_FLT_Eq1"

*/
/**
@note         The function may raise floating-point exceptions (invalid operation,
              overflow, underflow, inexact, input denormal). The floating-point unit must be enabled
              in CPACR register to prevent NOCP UsageFault exception.
*/
/**
@note         This function is implemented as inline and thus is
              not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFloat fltIn1;
tFloat fltIn2;
tFloat fltOut;

void main(void)
{
  // first input = 50.5
  fltIn1 = (tFloat)50.5;

  // second input = 25.25
  fltIn2 = (tFloat)25.25;

  // output should be 25.25
  fltOut = MLIB_Sub_FLT(fltIn1,fltIn2);

  // output should be 25.25
  fltOut = MLIB_Sub(fltIn1,fltIn2,FLT);

  // ##############################################################
  // Available only if single precision floating point
  // implementation selected as default
  // ##############################################################

  // output should be 25.25
  fltOut = MLIB_Sub(fltIn1,fltIn2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00070, DMLIB00063, DMLIB00064, DMLIB00068 */
SWLIBS_INLINE tFloat MLIB_Sub_FLT(register tFloat fltIn1,register tFloat fltIn2)
{
  /* @remarks Implements DMLIB00067 */
  return((tFloat)(fltIn1 - fltIn2));
}

#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_SUB_H */
