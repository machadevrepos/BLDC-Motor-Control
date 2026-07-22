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
* @file       MLIB_Msu.h
*
* @brief      Header file for MLIB_Msu function
*
******************************************************************************/
#ifndef MLIB_MSU_H
#define MLIB_MSU_H
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
  #include "MLIB_Sub.h"
  #include "MLIB_Mul.h"
  #include "MLIB_ConvertPU.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_Sub.h"
  #include "CCOV_MLIB_Mul.h"
  #include "CCOV_MLIB_ConvertPU.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_Msu(...)     macro_dispatcher(MLIB_Msu, __VA_ARGS__)(__VA_ARGS__)     /* This function implements the multiply accumulate function. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00271 */
    #define MLIB_Msu_Dsptchr_3(In1,In2,In3)     MLIB_Msu_Dsptchr_4(In1,In2,In3,F32)     /* Function dispatcher for MLIB_Msu_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00271 */
    #define MLIB_Msu_Dsptchr_3(In1,In2,In3)     MLIB_Msu_Dsptchr_4(In1,In2,In3,F16)     /* Function dispatcher for MLIB_Msu_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DMLIB00271 */
    #define MLIB_Msu_Dsptchr_3(In1,In2,In3)     MLIB_Msu_Dsptchr_4(In1,In2,In3,FLT)     /* Function dispatcher for MLIB_Msu_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */

  #define MLIB_Msu_Dsptchr_4(In1,In2,In3,Impl)    MLIB_Msu_Dsptchr_(In1,In2,In3,Impl)     /* Function dispatcher for MLIB_Msu_Dsptchr_5, do not modify!!! */

  /* @remarks Implements DMLIB00273 */
  #define MLIB_Msu_Dsptchr_(In1,In2,In3,Impl)     MLIB_Msu_##Impl(In1,In2,In3)            /* Function dispatcher for MLIB_Msu_Dsptchr_, do not modify!!! */
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
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac32 Msu_F32_C(register tFrac32 f32In1,register tFrac32 f32In2,register tFrac32 f32In3)
{
  tFrac32 f32Temp;

  f32Temp = MLIB_Mul_F32(f32In2,f32In3);
  return(MLIB_Sub_F32(f32In1, f32Temp));
} 
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac32 Msu_F32F16F16_C(register tFrac32 f32In1,register tFrac16 f16In2,register tFrac16 f16In3)
{
  tFrac32 f32Temp;

  f32Temp = MLIB_Mul_F32F16F16(f16In2,f16In3);
  return(MLIB_Sub_F32(f32In1, f32Temp));
}
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac16 Msu_F16_C(register tFrac16 f16In1,register tFrac16 f16In2,register tFrac16 f16In3)
{
  tFrac32 f32Temp;

  f32Temp = MLIB_Mul_F32F16F16(f16In2,f16In3);
  return(MLIB_ConvertPU_F16F32(MLIB_Sub_F32(MLIB_ConvertPU_F32F16(f16In1),f32Temp)));
}
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFloat Msu_FLT_C(register tFloat fltIn1,register tFloat fltIn2,register tFloat fltIn3)
{
  return((tFloat)((tDouble)fltIn1 - ((tDouble)fltIn2 * (tDouble)fltIn3)));
}
#ifdef MLIB_ARMV7_ASM
  #ifdef __ghs__
    #pragma ghs static_call 0
    #pragma ghs extra_stack 0
  #endif
  #ifdef __IAR_SYSTEMS_ICC__
    #pragma inline=forced
  #endif
  /* Target-specific implementation */
  SWLIBS_INLINE tFloat Msu_FLT_ASM_ARMV7(register tFloat fltIn1,register tFloat fltIn2,register tFloat fltIn3)
  {
    register tFloat fltReturn;
    fltReturn = fltIn1;
    #ifdef __ghs__
      #pragma ghs optasm
      SWLIBS_ASM(" vfms.f32 %0,%1,%2": "+f"(fltReturn): "f"(fltIn2), "f"(fltIn3));
    #else
      SWLIBS_ASM(" vfms.f32 %0,%1,%2": "+t"(fltReturn): "t"(fltIn2), "t"(fltIn3));
    #endif
    return((tFloat)fltReturn);     
  }
#endif /* MLIB_ARMV7_ASM */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Msu

@param[in]    f32In1     Input value from which to subtract.

@param[in]    f32In2     First value to be multiplied.

@param[in]    f32In3     Second value to be multiplied.

@return       First input value from which the multiplication result of the second and third
              input values is subtracted.

@details      The input values as well as output value is considered as 32-bit fractional values.
              The output saturation is not implemented in this function, thus in case the output
              value is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Msu_F32
              \image rtf msuF32Eq1.math "MLIB_Msu_F32_Eq1"

*/
/**
@note         This function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac32 f32In2;
tFrac32 f32In3;
tFrac32 f32Out;

void main(void)
{
  // input1 value = 0.25
  f32In1 = FRAC32(0.25);

  // input2 value = 0.5
  f32In2 = FRAC32(0.5);

  // input3 value = 0.125
  f32In3 = FRAC32(0.125);

  // output should be FRAC32(0.1875) = 0x18000000
  f32Out = MLIB_Msu_F32(f32In1, f32In2, f32In3);

  // output should be FRAC32(0.1875) = 0x18000000
  f32Out = MLIB_Msu(f32In1, f32In2, f32In3, F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC32(0.1875) = 0x18000000
  f32Out = MLIB_Msu(f32In1, f32In2, f32In3);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00272, DMLIB00264, DMLIB00267, DMLIB00270 */
SWLIBS_INLINE tFrac32 MLIB_Msu_F32(register tFrac32 f32In1,register tFrac32 f32In2,register tFrac32 f32In3)
{
  /* @remarks Implements DMLIB00268 */
  return(Msu_F32_C(f32In1,f32In2,f32In3));
}





/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Msu

@param[in]    f32In1     Input value from which to subtract.

@param[in]    f16In2     First value to be multiplied.

@param[in]    f16In3     Second value to be multiplied.

@return       First input value from which the multiplication result of the second and third
              input values is subtracted.

@details      The first input value as well as output value is considered as 32-bit fractional
              values. The second and third input values are considered as 16-bit fractional values.
              The output saturation is not implemented in this function, thus in case the output
              value is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Msu_F32F16F16
              \image rtf msuF32F16F16Eq1.math "MLIB_Msu_F32F16F16_Eq1"

              This implementation is available if 32-bit fractional implementations are enabled. However it is not
              possible to use the default implementation based function call, thus the implementation post-fix or additional
              parameter function call shall be used.

*/
/**
@note         This function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac16 f16In2;
tFrac16 f16In3;
tFrac32 f32Out;

void main(void)
{
  // input1 value = 0.25
  f32In1 = FRAC32(0.25);

  // input2 value = 0.5
  f16In2 = FRAC16(0.5);

  // input3 value = 0.125
  f16In3 = FRAC16(0.125);

  // output should be FRAC32(0.1875) = 0x18000000
  f32Out = MLIB_Msu_F32F16F16(f32In1, f16In2, f16In3);

  // output should be FRAC32(0.1875) = 0x18000000
  f32Out = MLIB_Msu(f32In1, f32In2, f32In3, F32F16F16);

}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00272, DMLIB00264, DMLIB00269, DMLIB00270 */
SWLIBS_INLINE tFrac32 MLIB_Msu_F32F16F16(register tFrac32 f32In1,register tFrac16 f16In2,register tFrac16 f16In3)
{
  /* @remarks Implements DMLIB00268 */
  return(Msu_F32F16F16_C(f32In1,f16In2,f16In3));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Msu

@param[in]    f16In1     Input value from which to subtract.

@param[in]    f16In2     First value to be multiplied.

@param[in]    f16In3     Second value to be multiplied.

@return       First input value from which the multiplication result of the second and third
              input values is subtracted.

@details      The input values as well as output value is considered as 16-bit fractional values.
              The output saturation is not implemented in this function, thus in case the output
              value is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Msu_F16
              \image rtf msuF16Eq1.math "MLIB_Msu_F16_Eq1"

@note         This function is implemented as inline, and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac16 f16In3;
tFrac16 f16Out;

void main(void)
{
  // input1 value = 0.25
  f16In1 = FRAC16(0.25);

  // input2 value = 0.5
  f16In2 = FRAC16(0.5);

  // input3 value = 0.125
  f16In3 = FRAC16(0.125);

  // output should be FRAC16(0.1875) = 0x1800
  f16Out = MLIB_Msu_F16(f16In1, f16In2, f16In3);

  // output should be FRAC16(0.1875) = 0x1800
  f16Out = MLIB_Msu(f16In1, f16In2, f16In3, F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC16(0.1875) = 0x1800
  f16Out = MLIB_Msu(f16In1, f16In2, f16In3);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00272, DMLIB00264, DMLIB00266, DMLIB00270 */
SWLIBS_INLINE tFrac16 MLIB_Msu_F16(register tFrac16 f16In1,register tFrac16 f16In2,register tFrac16 f16In3)
{
  /* @remarks Implements DMLIB00268 */
  return(Msu_F16_C(f16In1,f16In2,f16In3));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Msu

@param[in]    fltIn1     Input value from which to subtract.

@param[in]    fltIn2     First value to be multiplied.

@param[in]    fltIn3     Second value to be multiplied.

@return       First input value from which the multiplication result of the second and third
              input values is subtracted.

@details      The input values as well as output value are considered as single precision floating
              point data type. Intermediate results are computed in infinite precision.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Msu_FLT
              \image rtf msuFLTEq1.math "MLIB_Msu_FLT_Eq1"

*/
/**
@note         The function may raise floating-point exceptions (invalid operation,
              overflow, underflow, inexact, input denormal). The floating-point unit must be enabled
              in CPACR register to prevent NOCP UsageFault exception.
*/
/**
@note         This function is implemented as inline assembly, and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFloat fltIn1;
tFloat fltIn2;
tFloat fltIn3;
tFloat fltOut;

void main(void)
{
  // input1 value = 1.150236353278160e-01
  fltIn1 = (tFloat)1.150236353278160e-01f;

  // input2 value = 9.057919383049011e-01
  fltIn2 = (tFloat)9.057919383049011e-01f;

  // input3 value = 1.269868165254593e-01
  fltIn3 = (tFloat)1.269868165254593e-01f;

  // output should be 6.4805139e-10
  fltOut = MLIB_Msu_FLT(fltIn1, fltIn2, fltIn3);

  // output should be 6.4805139e-10
  fltOut = MLIB_Msu(fltIn1, fltIn2, fltIn3, FLT);

  // ##############################################################
  // Available only if single precision floating point
  // implementation selected as default
  // ##############################################################

  // output should be 6.4805139e-10
  fltOut = MLIB_Msu(fltIn1, fltIn2, fltIn3);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00272, DMLIB00264, DMLIB00265, DMLIB00270 */
SWLIBS_INLINE tFloat MLIB_Msu_FLT(register tFloat fltIn1,register tFloat fltIn2,register tFloat fltIn3)
{
  #ifdef MLIB_ARMV7_ASM
    /* @remarks Implements DMLIB00268 */
    return(Msu_FLT_ASM_ARMV7(fltIn1,fltIn2,fltIn3));
  #else
    /* @remarks Implements DMLIB00268 */
    return(Msu_FLT_C(fltIn1,fltIn2,fltIn3));
  #endif /* MLIB_ARMV7_ASM */
}


#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_MSU_H */
