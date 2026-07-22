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
* @file       MLIB_Mul.h
*
* @brief      Header file for MLIB_Mul function
*
******************************************************************************/
#ifndef MLIB_MUL_H
#define MLIB_MUL_H
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
  #include "MLIB_ShR.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_ShR.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_Mul(...)     macro_dispatcher(MLIB_Mul, __VA_ARGS__)(__VA_ARGS__)     /* This function multiply two input parameters. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00091 */
    #define MLIB_Mul_Dsptchr_2(In1,In2)     MLIB_Mul_Dsptchr_3(In1,In2,F32)     /* Function dispatcher for MLIB_Mul_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00091 */
    #define MLIB_Mul_Dsptchr_2(In1,In2)     MLIB_Mul_Dsptchr_3(In1,In2,F16)     /* Function dispatcher for MLIB_Mul_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DMLIB00091 */
    #define MLIB_Mul_Dsptchr_2(In1,In2)     MLIB_Mul_Dsptchr_3(In1,In2,FLT)     /* Function dispatcher for MLIB_Mul_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */

  #define MLIB_Mul_Dsptchr_3(In1,In2,Impl)    MLIB_Mul_Dsptchr_(In1,In2,Impl)     /* Function dispatcher for MLIB_Mul_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00093 */
  #define MLIB_Mul_Dsptchr_(In1,In2,Impl)     MLIB_Mul_##Impl(In1,In2)            /* Function dispatcher for MLIB_Mul_Dsptchr_, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* inline functions
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac32 Mul_F32_C(register tFrac32 f32In1,register tFrac32 f32In2)
{
  /* Compiler_Warning: This cast is necessary for fractional arithmetics. */
  return((tFrac32) ((F32TOINT64(f32In1)*F32TOINT64(f32In2))>>31));
}

#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac32 Mul_F32F16F16_C(register tFrac16 f16In1,register tFrac16 f16In2)
{
  return(INT32TOF32((F16TOINT32(f16In1)*F16TOINT32(f16In2))<<1));
}

#ifdef MLIB_ARM_DSP_ASM
  #ifdef __ghs__
    #pragma ghs static_call 0
    #pragma ghs extra_stack 0
  #endif
  #ifdef __IAR_SYSTEMS_ICC__
    #pragma inline=forced
  #endif
/* Target-specific implementation */
SWLIBS_INLINE tFrac32 Mul_F32F16F16_ASM_DSP(register tFrac16 f16In1,register tFrac16 f16In2)
{
  register tFrac32 f32Return;

  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" smulbb %0,%1,%2": "=r"(f32Return): "r"(f16In1), "r"(f16In2));
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" lsl %0,%0,#1": "+r"(f32Return): );
  return(f32Return);
}
#endif /* MLIB_ARM_DSP_ASM */





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Mul

@param[in]    f32In1     Operand is a 32-bit number normalized between [-1,1).

@param[in]    f32In2     Operand is a 32-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      The input values as well as output value is considered as 32-bit fractional values.
              The output saturation is not implemented in this function, thus in case the
              multiplication of input values is outside the [-1, 1) interval, the output value will
              overflow.
              
              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Mul_F32
              \image rtf mulF32Eq1.math "MLIB_Mul_F32_Eq1"

*/
/**
@note         Overflow is not detected. This function is implemented as inline assembly and
              thus is not ANSI-C compliant.
*/
/**

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

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul_F32(f32In1,f32In2);

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul(f32In1,f32In2,F32);


  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul(f32In1,f32In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00092, DMLIB00084, DMLIB00087, DMLIB00090 */
SWLIBS_INLINE tFrac32 MLIB_Mul_F32(register tFrac32 f32In1,register tFrac32 f32In2)
{
  /* @remarks Implements DMLIB00089 */
  return(Mul_F32_C(f32In1,f32In2));
}





/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Mul

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      The input values are considered as 16-bit fractional values and the output value is
              considered as 32-bit fractional value. The output saturation is not implemented in
              this function, thus in case the multiplication of input values is outside the [-1, 1)
              interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Mul_F32F16F16
              \image rtf mulF32F16F16Eq1.math "MLIB_Mul_F32F16F16_Eq1"

*/
/**
@note         Overflow is not detected. This function is implemented as inline assembly and
              thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac32 f32Out;

void main(void)
{
  // first input = 0.5
  f16In1 = FRAC16(0.5);

  // second input = 0.25
  f16In2 = FRAC16(0.25);

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul_F32F16F16(f16In1, f16In2);

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul(f16In1, f16In2, F32F16F16);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00092, DMLIB00084, DMLIB00088, DMLIB00090 */
SWLIBS_INLINE tFrac32 MLIB_Mul_F32F16F16(register tFrac16 f16In1,register tFrac16 f16In2)
{
  #ifdef MLIB_ARM_DSP_ASM
    /* @remarks Implements DMLIB00089 */
    return(Mul_F32F16F16_ASM_DSP(f16In1,f16In2));
  #else
    /* @remarks Implements DMLIB00089 */
    return(Mul_F32F16F16_C(f16In1,f16In2));
  #endif /* MLIB_ARM_DSP_ASM */
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Mul

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      The input values as well as output value is considered as 16-bit fractional values.
              The output saturation is not implemented in this function, thus in case the
              multiplication of input values is outside the [-1, 1) interval, the output value will
              overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Mul_F16
              \image rtf mulF16Eq1.math "MLIB_Mul_F16_Eq1"

@note         This function is implemented as inline and thus is not ANSI-C compliant.

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

  // output should be 0x1000 = FRAC16(0.125)
  f16Out = MLIB_Mul_F16(f16In1,f16In2);

  // output should be 0x1000 = FRAC16(0.125)
  f16Out = MLIB_Mul(f16In1,f16In2,F16);


  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x1000 = FRAC16(0.125)
  f16Out = MLIB_Mul(f16In1,f16In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00092, DMLIB00084, DMLIB00086, DMLIB00090 */
SWLIBS_INLINE tFrac16 MLIB_Mul_F16(register tFrac16 f16In1,register tFrac16 f16In2)
{
  return(INT32TOF16((F16TOINT32(f16In1)*F16TOINT32(f16In2))>>15));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Mul

@param[in]    fltIn1     Operand is a single precision floating point number.

@param[in]    fltIn2     Operand is a single precision floating point number.

@return       Floating point multiplication of the input arguments.

@details      The input values as well as output value is considered as single precision floating
              point data type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Mul_FLT
              \image rtf mulFLTEq1.math "MLIB_Mul_FLT_Eq1"

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

tFloat fltIn1;
tFloat fltIn2;
tFloat fltOut;

void main(void)
{
  // first input = 50.5
  fltIn1 = (tFloat)50.5;

  // second input = 25.25
  fltIn2 = (tFloat)25.25;

  // output should be 1275.125
  fltOut = MLIB_Mul_FLT(fltIn1,fltIn2);

  // output should be 1275.125
  fltOut = MLIB_Mul(fltIn1,fltIn2,FLT);


  // ##############################################################
  // Available only if single precision floating point
  // implementation selected as default
  // ##############################################################

  // output should be 1275.125
  fltOut = MLIB_Mul(fltIn1,fltIn2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00092, DMLIB00084, DMLIB00085, DMLIB00090 */
SWLIBS_INLINE tFloat MLIB_Mul_FLT(register tFloat fltIn1,register tFloat fltIn2)
{
  /* @remarks Implements DMLIB00089 */
  return(fltIn1 * fltIn2);
}


#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_MUL_H */
