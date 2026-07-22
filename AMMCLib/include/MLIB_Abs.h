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
* @file       MLIB_Abs.h
* 
* @brief      Header file for MLIB_Abs function
*
******************************************************************************/
#ifndef MLIB_ABS_H
#define MLIB_ABS_H
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
  #define MLIB_Abs(...)     macro_dispatcher(MLIB_Abs, __VA_ARGS__)(__VA_ARGS__)     /* This function returns absolute value of input parameter. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00006 */  
    #define MLIB_Abs_Dsptchr_1(In)     MLIB_Abs_Dsptchr_2(In,F32)     /* Function dispatcher for MLIB_Abs_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00006 */
    #define MLIB_Abs_Dsptchr_1(In)     MLIB_Abs_Dsptchr_2(In,F16)     /* Function dispatcher for MLIB_Abs_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DMLIB00006 */
    #define MLIB_Abs_Dsptchr_1(In)     MLIB_Abs_Dsptchr_2(In,FLT)     /* Function dispatcher for MLIB_Abs_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */

  #define MLIB_Abs_Dsptchr_2(In,Impl)    MLIB_Abs_Dsptchr_(In,Impl)     /* Function dispatcher for MLIB_Abs_Dsptchr_2, do not modify!!! */
  
  /* @remarks Implements DMLIB00008 */
  #define MLIB_Abs_Dsptchr_(In,Impl)     MLIB_Abs_##Impl(In)            /* Function dispatcher for MLIB_Abs_Dsptchr_, do not modify!!! */
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
/* MLIB_Abs_F32 implementation variant - C */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac32 Abs_F32_C(register tFrac32 f32In)
{
  #if (defined(__DCC__))
    /* Workaround for diab - this compiler can optimize out the case with signed overflow */
    tFrac32 f32Return;
    if (f32In == (tFrac32)0x80000000u)
    {
      f32Return = (tFrac32)0x80000000u;
    }
    else if (f32In < (tFrac32)0)
    {
      f32Return = -f32In;
    }
    else
    {
      f32Return = f32In;
    }
    return(f32Return);
  #else
  return((f32In < (tFrac32)0) ? (-f32In) : (f32In));
  #endif /* __DCC__ */
}
/* MLIB_Abs_F16 implementation variant - C */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac16 Abs_F16_C(register tFrac16 f16In)
{
  #if (defined(__DCC__))
    /* Workaround for diab - this compiler can optimize out the case with signed overflow */
    tFrac16 f16Return;
    if (f16In == (tFrac16)0x8000u)
    {
      f16Return = (tFrac16)0x8000u;
    }
    else if (f16In < (tFrac16)0)
    {
      f16Return = -f16In;
    }
    else
    {
      f16Return = f16In;
    }
    return(f16Return);
  #else
  return((f16In < (tFrac16)0) ? (-f16In) : (f16In));
  #endif /* __DCC__ */
}
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/* MLIB_Abs_FLT implementation variant - C */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFloat Abs_FLT_C(register tFloat fltIn)
{
  return((fltIn<(tFloat)0) ? (-fltIn) : (fltIn));
}
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Abs

@param[in]    f32In      Input value.

@return       Absolute value of input parameter.

@details      The input value as well as output value is considered as 32-bit fractional data type.
              The output saturation is not implemented in this function, thus in case the absolute
              value of input parameter is outside the [-1, 1) interval, the output value will
              overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Abs_F32
              \image rtf absF32Eq1.math "MLIB_Abs_F32_Eq1"

*/
/**
@note         This function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In;
tFrac32 f32Out;

void main(void)
{
    // input value = -0.25
    f32In = FRAC32(-0.25);

    // output should be FRAC32(0.25)
    f32Out = MLIB_Abs_F32(f32In);

    // output should be FRAC32(0.25)
    f32Out = MLIB_Abs(f32In, F32);

    // ##############################################################
    // Available only if 32-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be FRAC32(0.25)
    f32Out = MLIB_Abs(f32In);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00007, DMLIB00000, DMLIB00003, DMLIB00005 */
SWLIBS_INLINE tFrac32 MLIB_Abs_F32(register tFrac32 f32In)
{
  /* @remarks Implements DMLIB00004 */
  return(Abs_F32_C(f32In));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Abs

@param[in]    f16In      Input value.

@return       Absolute value of input parameter.

@details      The input value as well as output value is considered as 16-bit fractional data type.
              The output saturation is not implemented in this function, thus in case the absolute
              value of input parameter is outside the [-1, 1) interval, the output value will
              overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Abs_F16
              \image rtf absF16Eq1.math "MLIB_Abs_F16_Eq1"

*/
/**
@note         This function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In;
tFrac16 f16Out;

void main(void)
{
    // input value = -0.25
    f16In = FRAC16(-0.25);

    // output should be FRAC16(0.25)
    f16Out = MLIB_Abs_F16(f16In);

    // output should be FRAC16(0.25)
    f16Out = MLIB_Abs(f16In, F16);

    // ##############################################################
    // Available only if 16-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be FRAC16(0.25)
    f16Out = MLIB_Abs(f16In);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00007, DMLIB00000, DMLIB00002, DMLIB00005 */
SWLIBS_INLINE tFrac16 MLIB_Abs_F16(register tFrac16 f16In)
{
  /* @remarks Implements DMLIB00004 */
  return(Abs_F16_C(f16In));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Abs

@param[in]    fltIn      Input value.

@return       Absolute value of input parameter.

@details      The input value as well as output value is considered as single precision floating
              point data type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Abs_FLT
              \image rtf absFLTEq1.math "MLIB_Abs_FLT_Eq1"

*/
/**
@note         The function may raise floating-point exceptions (invalid operation,
              overflow, underflow, inexact, input denormal). The floating-point unit must be enabled
              in CPACR register to prevent NOCP UsageFault exception.
*/
/**
@note         This function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFloat fltIn;
tFloat fltOut;

void main(void)
{
    // input value = -0.25
    fltIn = (tFloat)-0.25;

    // output should be 0.25
    fltOut = MLIB_Abs_FLT(fltIn);

    // output should be 0.25
    fltOut = MLIB_Abs(fltIn, FLT);

    // ##############################################################
    // Available only if single precision floating point
    // implementation selected as default
    // ##############################################################

    // output should be 0.25
    fltOut = MLIB_Abs(fltIn);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00007, DMLIB00000, DMLIB00001, DMLIB00005 */
SWLIBS_INLINE tFloat MLIB_Abs_FLT(register tFloat fltIn)
{
  /* @remarks Implements DMLIB00004 */
  return(Abs_FLT_C(fltIn));
}


#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_ABS_H */
