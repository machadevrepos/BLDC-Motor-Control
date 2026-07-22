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
* @file       MLIB_Div.h
*
* @brief      Header file for MLIB_Div function
*
******************************************************************************/
#ifndef MLIB_DIV_H
#define MLIB_DIV_H
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
  #include "MLIB_ShL.h"
  #include "MLIB_ShLSat.h"
  #include "MLIB_ShR.h"
  #include "MLIB_AbsSat.h"
  #include "MLIB_Norm.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_ShL.h"
  #include "CCOV_MLIB_ShLSat.h"
  #include "CCOV_MLIB_ShR.h"
  #include "CCOV_MLIB_AbsSat.h"
  #include "CCOV_MLIB_Norm.h"
#endif /* AMMCLIB_TESTING_ENV */

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_Div(...)     macro_dispatcher(MLIB_Div,__VA_ARGS__)(__VA_ARGS__)     /* This function divides the first parameter by the second one. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00119 */
    #define MLIB_Div_Dsptchr_2(In1,In2)     MLIB_Div_Dsptchr_3(In1,In2,F32)       /* Function dispatcher for MLIB_Div_Dsptchr_2,do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00119 */
    #define MLIB_Div_Dsptchr_2(In1,In2)     MLIB_Div_Dsptchr_3(In1,In2,F16)       /* Function dispatcher for MLIB_Div_Dsptchr_2,do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DMLIB00119 */
    #define MLIB_Div_Dsptchr_2(In1,In2)     MLIB_Div_Dsptchr_3(In1,In2,FLT)       /* Function dispatcher for MLIB_Div_Dsptchr_2,do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */

  #define MLIB_Div_Dsptchr_3(In1,In2,Impl)    MLIB_Div_Dsptchr_(In1,In2,Impl)     /* Function dispatcher for MLIB_Div_Dsptchr_3,do not modify!!! */
  
  /* @remarks Implements DMLIB00121 */
  #define MLIB_Div_Dsptchr_(In1,In2,Impl)     MLIB_Div_##Impl(In1,In2)            /* Function dispatcher for MLIB_Div_Dsptchr_,do not modify!!! */
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
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac32 Div_F32_C(register tFrac32 f32In1,register tFrac32 f32In2)
{
  register tU32 u32X, u32D, u32R, u32Temp, u32i;
  register tFrac32 f32Return, f32Neg;
  
  f32Neg = (tFrac32)(f32In1 ^ f32In2) >> 31;
  u32Temp = 0u - (tU32)f32In1;
  u32X = ((tFrac32)u32Temp > (tFrac32)0) ? u32Temp : (tU32)f32In1;
  u32Temp = 0u - (tU32)f32In2;
  u32D = ((tFrac32)u32Temp > (tFrac32)0) ? u32Temp : (tU32)f32In2;
  if(u32X >= u32D)
  {
    u32D = 0u;
  }
  if(0u == u32D)
  {
    u32R = 0x7FFFFFFFu;
  }
  else
  {
    u32Temp = u32D;
    if (u32Temp < 0x00FF0000u)
    {
      u32i = 32u;
      do
      {
        u32Temp = u32Temp >> 1u;
        u32i--;
      } while(u32Temp > 0u);
    }
    else
    {
      u32i = 0u;
      while(((u32Temp & 0x80000000u)==0u))
      {
        u32Temp = u32Temp << 1u;
        u32i++;
      }
    }
    u32X =  u32X << u32i;
    if (u32i>16u)
    {
      u32D = u32D << (u32i - 16u);
    }
    else
    {
      u32D = u32D >> (16u - u32i);
    }    
    u32R = (u32X / u32D);
    u32R = (u32R > 0xFFFFu) ? 0x7FFFFFFFu : (u32R << 15u);
  }
  u32R = u32R ^ (tU32)f32Neg;
  f32Return = (tFrac32)u32R;
  
  return(f32Return);
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
  SWLIBS_INLINE tFrac32 Div_F32_ASM_ARMV7(register tFrac32 f32In1,register tFrac32 f32In2)
  {
    register tU32 u32X, u32D, u32R, u32i, u32Temp;
    register tFrac32 f32Return, f32Neg;
    
    f32Neg = (tFrac32)(f32In1 ^ f32In2) >> 31;
    u32Temp = 0u - (tU32)f32In1;
    u32X = ((tFrac32)u32Temp > (tFrac32)0) ? u32Temp : (tU32)f32In1;
    u32Temp = 0u - (tU32)f32In2;
    u32D = ((tFrac32)u32Temp > (tFrac32)0) ? u32Temp : (tU32)f32In2;
    if (u32D == 0u)
    {
      u32R = 0x7FFFFFFFu;
    }
    else
    {
      #ifdef __ghs__
        #pragma ghs optasm
      #endif
      SWLIBS_ASM(" clz %0,%1": "=r"(u32i): "r"(u32D));
      u32X =  u32X << u32i;
      if (u32i>16u)
      {
        u32D = u32D << (u32i - 16u);
      }
      else
      {
        u32D = u32D >> (16u - u32i);
      }    
      u32R = (u32X / u32D) << 15u;
    }
    u32R = u32R ^ (tU32)f32Neg;
    f32Return = (tFrac32)u32R;
    
    return(f32Return);
  }
#endif /* MLIB_ARMV7_ASM */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac16 Div_F16_C(register tFrac16 f16In1,register tFrac16 f16In2)
{
  register tFrac16 f16Return;

  if (f16In2 == (tFrac16)0)
  {
    f16Return = (f16In1 > (tFrac16)0) ? INT16TOF16(SWLIBS_INT16_MAX) : INT16TOF16(SWLIBS_INT16_MIN);
  }
  else
  {
    f16Return = INT16TOF16(INT32TOINT16((F16TOINT32(f16In1)<<(tU16)15)/F16TOINT32(f16In2)));
  }
  return(f16Return);
}





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Div

@param[in]         f32In1     Numerator of division.

@param[in]         f32In2     Denominator of division.

@return       Division of two input values.

@details      The input values as well as output value is considered as 32-bit fractional data type.
              The output saturation is not implemented in this function, thus in case the
              numerator is greater or equal to denominator, the output value is undefined. The
              function will never cause division by zero exception. This is the fastest variant
              of the 32-bit division and should be used only if the inputs are limited elsewhere
              to prevent overflow. Note that only the most significant 16 bits of the result
              are accurate. Use #MLIB_DivSat_F32 instead if the inputs to the function can cause
              overflow. If full 32-bit accuracy of the result is needed, use #MLIB_DivSatAccurate_F32
              (note that the accurate variant consumes more clock cycles).
              \par              
              The output of the function is defined by the following simple equation:
              \anchor eq1_Div_F32
              \image rtf divF32Eq1.math "MLIB_Div_F32_Eq1"

*/
/**
@note         This function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1,f32In2;
tFrac32 f32Out;

void main(void)
{
  // input value 1 = 0.25
  f32In1 = FRAC32(0.25);
  // input value 2 = 0.5
  f32In2 = FRAC32(0.5);

  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_Div_F32(f32In1,f32In2);

  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_Div(f32In1,f32In2,F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_Div(f32In1,f32In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00120, DMLIB00107, DMLIB00116, DMLIB00118, DMLIB00108, DMLIB00111 */
SWLIBS_INLINE tFrac32 MLIB_Div_F32(register tFrac32 f32In1,register tFrac32 f32In2)
{
  #ifdef MLIB_ARMV7_ASM
    /* @remarks Implements DMLIB00117 */
    return(Div_F32_ASM_ARMV7(f32In1,f32In2));
  #else
    /* @remarks Implements DMLIB00117 */
    return(Div_F32_C(f32In1,f32In2));
  #endif
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Div

@param[in]         f16In1     Numerator of division.

@param[in]         f16In2     Denominator of division.

@return       Division of two input values.

@details      The input values as well as output value is considered as 16-bit fractional data type.
              The output saturation is not implemented in this function, thus in case the numerator
              is greater or equal to denominator, the output value is undefined. The function will
              never cause division by zero exception. This is the fastest variant of the 16-bit
              division and should be used only if the inputs are limited elsewhere to prevent
              overflow. Use #MLIB_DivSat_F16 instead if the inputs to the function can cause
              overflow.
              \par              
              The output of the function is defined by the following simple equation:
              \anchor eq1_Div_F16
              \image rtf divF16Eq1.math "MLIB_Div_F16_Eq1"

*/
/**
@note         This function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1,f16In2;
tFrac16 f16Out;

void main(void)
{
  // input value 1 = 0.25
  f16In1 = FRAC16(0.25);
  // input value 2 = 0.5
  f16In2 = FRAC16(0.5);

  // output should be FRAC16(0.5) = 0x4000
  f16Out = MLIB_Div_F16(f16In1,f16In2);

  // output should be FRAC16(0.5) = 0x4000
  f16Out = MLIB_Div(f16In1,f16In2,F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC16(0.5) = 0x4000
  f16Out = MLIB_Div(f16In1,f16In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00120, DMLIB00107, DMLIB00115, DMLIB00118, DMLIB00109, DMLIB00112 */
SWLIBS_INLINE tFrac16 MLIB_Div_F16(register tFrac16 f16In1,register tFrac16 f16In2)
{
  /* @remarks Implements DMLIB00117 */
  return(Div_F16_C(f16In1,f16In2));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Div

@param[in]         fltIn1     Numerator of division.

@param[in]         fltIn2     Denominator of division.

@return       Division of two input values.

@details      The input values as well as output value is considered as single  precision floating point data type. Testing of input values for division by zero is not implemented in this function.
              \par
              The output of the function is defined by the following simple equation:
              \anchor eq1_Div_FLT
              \image rtf divFLTEq1.math "MLIB_Div_FLT_Eq1"

*/
/**
@note         The function may raise floating-point exceptions (invalid operation,division by zero,
              overflow,underflow,inexact,input denormal). The floating-point unit must be enabled
              in CPACR register to prevent NOCP UsageFault exception.
*/
/**
@note         This function is implemented as inline, and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFloat fltIn1,fltIn2;
tFloat fltOut;

void main(void)
{
  // input value 1 = 0.25
  fltIn1 = (tFloat)0.25;
  // input value 2 = 0.5
  fltIn2 = (tFloat)0.5;

  // output should be 0.5
  fltOut = MLIB_Div_FLT(fltIn1,fltIn2);

  // output should be 0.5
  fltOut = MLIB_Div(fltIn1,fltIn2,FLT);

  // ##############################################################
  // Available only if single precision floating point
  // implementation selected as default
  // ##############################################################

  // output should be 0.5
  fltOut = MLIB_Div(fltIn1,fltIn2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00120, DMLIB00107, DMLIB00114, DMLIB00118, DMLIB00110, DMLIB00113 */
SWLIBS_INLINE tFloat MLIB_Div_FLT(register tFloat fltIn1,register tFloat fltIn2)
{
  /* @remarks Implements DMLIB00117 */
  return((tFloat)(fltIn1 / fltIn2));
}


#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_DIV_H */
