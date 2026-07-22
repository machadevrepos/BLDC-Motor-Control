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
* @file       MLIB_VMac.h
*
* @brief      Header file for MLIB_VMac function
*
******************************************************************************/
#ifndef MLIB_VMAC_H
#define MLIB_VMAC_H

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
  #include "MLIB_Add.h"
  #include "MLIB_Mul.h"
  #include "MLIB_MulSat.h"
  #include "MLIB_Mnac.h"
  #include "MLIB_ConvertPU.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_Add.h"
  #include "CCOV_MLIB_Mul.h"
  #include "CCOV_MLIB_MulSat.h"
  #include "CCOV_MLIB_Mnac.h"
  #include "CCOV_MLIB_ConvertPU.h"
#endif /* AMMCLIB_TESTING_ENV */

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_VMac(...)     macro_dispatcher(MLIB_VMac, __VA_ARGS__)(__VA_ARGS__)     /* This function implements the vector multiply accumulate function. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00240 */
    #define MLIB_VMac_Dsptchr_4(In1,In2,In3,In4)     MLIB_VMac_Dsptchr_5(In1,In2,In3,In4,F32)     /* Function dispatcher for MLIB_VMac_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00240 */
    #define MLIB_VMac_Dsptchr_4(In1,In2,In3,In4)     MLIB_VMac_Dsptchr_5(In1,In2,In3,In4,F16)     /* Function dispatcher for MLIB_VMac_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DMLIB00240 */
    #define MLIB_VMac_Dsptchr_4(In1,In2,In3,In4)     MLIB_VMac_Dsptchr_5(In1,In2,In3,In4,FLT)     /* Function dispatcher for MLIB_VMac_Dsptchr_4, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */

  #define MLIB_VMac_Dsptchr_5(In1,In2,In3,In4,Impl)    MLIB_VMac_Dsptchr_(In1,In2,In3,In4,Impl)     /* Function dispatcher for MLIB_VMac_Dsptchr_5, do not modify!!! */

  /* @remarks Implements DMLIB00242 */
  #define MLIB_VMac_Dsptchr_(In1,In2,In3,In4,Impl)     MLIB_VMac_##Impl(In1,In2,In3,In4)            /* Function dispatcher for MLIB_VMac_Dsptchr_, do not modify!!! */
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
SWLIBS_INLINE tFrac32 VMac_F32_C(register tFrac32 f32In1,register tFrac32 f32In2,register tFrac32 f32In3,register tFrac32 f32In4)
{
  return(MLIB_Add_F32(MLIB_MulSat_F32(f32In1,f32In2),MLIB_MulSat_F32(f32In3,f32In4)));
} 
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac32 VMac_F32F16F16_C(register tFrac16 f16In1,register tFrac16 f16In2,register tFrac16 f16In3,register tFrac16 f16In4)
{
  return(MLIB_Add_F32(MLIB_MulSat_F32F16F16(f16In1,f16In2),MLIB_MulSat_F32F16F16(f16In3,f16In4)));
}
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac16 VMac_F16_C(register tFrac16 f16In1,register tFrac16 f16In2,register tFrac16 f16In3,register tFrac16 f16In4)
{
  return(MLIB_ConvertPU_F16F32(MLIB_Add_F32(MLIB_MulSat_F32F16F16(f16In1,f16In2),MLIB_MulSat_F32F16F16(f16In3,f16In4))));
}
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFloat VMac_FLT_C(register tFloat fltIn1,register tFloat fltIn2,register tFloat fltIn3,register tFloat fltIn4)
{
  tFloat fltReturn, fltTemp1, fltTemp2;

  fltTemp1 = MLIB_Mul_FLT(fltIn1,fltIn2);
  fltTemp2 = MLIB_Mul_FLT(fltIn3,fltIn4);
  fltReturn = MLIB_Add_FLT(fltTemp1,fltTemp2);
  fltTemp1 = MLIB_Mnac_FLT(fltTemp1,fltIn1,fltIn2);
  fltTemp2 = MLIB_Mnac_FLT(fltTemp2,fltIn3,fltIn4);
  fltTemp1 = MLIB_Add_FLT(fltTemp1,fltTemp2);
  fltReturn = MLIB_Add_FLT(fltReturn,fltTemp1);
  return(fltReturn);
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
  SWLIBS_INLINE tFloat VMac_FLT_ASM_ARMV7(register tFloat fltIn1,register tFloat fltIn2,register tFloat fltIn3,register tFloat fltIn4)
  {
    tFloat fltReturn, fltTemp1, fltTemp2;

    #ifdef __ghs__
      #pragma ghs optasm
    #endif
      SWLIBS_ASM(" vmul.f32 %[fltTemp1],%[fltIn1],%[fltIn2]       \n"
          " vmul.f32 %[fltTemp2],%[fltIn3],%[fltIn4]       \n"
          " vadd.f32 %[fltReturn],%[fltTemp1],%[fltTemp2]  \n"
          " vfnms.f32 %[fltTemp1],%[fltIn1],%[fltIn2]      \n"
          " vfnms.f32 %[fltTemp2],%[fltIn3],%[fltIn4]      \n"
          " vadd.f32 %[fltTemp1],%[fltTemp1],%[fltTemp2]   \n"
          " vadd.f32 %[fltReturn],%[fltReturn],%[fltTemp1] \n"
    #ifdef __ghs__
      /* Compiler_Warning: The value is set inside inline assembly block. */
      : [fltReturn]"+f"(fltReturn), [fltTemp1]"+f"(fltTemp1), [fltTemp2]"+f"(fltTemp2): [fltIn1]"f"(fltIn1), [fltIn2]"f"(fltIn2), [fltIn3]"f"(fltIn3), [fltIn4]"f"(fltIn4));
    #else
      /* Compiler_Warning: The value is set inside inline assembly block. */
      : [fltReturn]"+t"(fltReturn), [fltTemp1]"+t"(fltTemp1), [fltTemp2]"+t"(fltTemp2): [fltIn1]"t"(fltIn1), [fltIn2]"t"(fltIn2), [fltIn3]"t"(fltIn3), [fltIn4]"t"(fltIn4));
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

@functionality MLIB_VMac

@param[in]    f32In1     First input value to first multiplication.

@param[in]    f32In2     Second input value to first multiplication.

@param[in]    f32In3     First input value to second multiplication.

@param[in]    f32In4     Second input value to second multiplication.

@return       Vector multiplied input values with addition.

@details      The input values as well as output value is considered as 32-bit fractional values.
              The output saturation is implemented only for multiplication result inside this function.
              The output saturation is not implemented for addition in this function, thus in case
              the add of input values is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_VMac_F32
              \image rtf vmacF32Eq1.math "MLIB_VMac_F32_Eq1"

*/
/**
@note         This function is implemented as inline and thus is not
              ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac32 f32In2;
tFrac32 f32In3;
tFrac32 f32In4;
tFrac32 f32Out;

void main(void)
{
  // input1 value = 0.25
  f32In1 = FRAC32(0.25);

  // input2 value = 0.15
  f32In2 = FRAC32(0.15);

  // input3 value = 0.35
  f32In3 = FRAC32(0.35);
  
  // input4 value = 0.45
  f32In4 = FRAC32(0.45);

  // output should be FRAC32(0.195) = 0x18F5C28F
  f32Out = MLIB_VMac_F32(f32In1,f32In2,f32In3,f32In4);

  // output should be FRAC32(0.195) = 0x18F5C28F
  f32Out = MLIB_VMac(f32In1,f32In2,f32In3,f32In4, F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC32(0.195) = 0x18F5C28F
  f32Out = MLIB_VMac(f32In1,f32In2,f32In3,f32In4);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00241, DMLIB00233, DMLIB00236, DMLIB00239 */
SWLIBS_INLINE tFrac32 MLIB_VMac_F32(register tFrac32 f32In1,register tFrac32 f32In2,register tFrac32 f32In3,register tFrac32 f32In4)
{
  /* @remarks Implements DMLIB00238 */
  return(VMac_F32_C(f32In1,f32In2,f32In3,f32In4));
}





/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_VMac

@param[in]    f16In1     First input value to first multiplication.

@param[in]    f16In2     Second input value to first multiplication.

@param[in]    f16In3     First input value to second multiplication.

@param[in]    f16In4     Second input value to second multiplication.

@return       Vector multiplied input values with addition.

@details      The input values are considered as 16-bit fractional values and the output value is
              considered as 32-bit fractional value. The output saturation is implemented only for
              multiplication result inside this function. The output saturation is not implemented
              for addition in this function, thus in case the add of input values is outside the
              [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_VMac_F32F16F16
              \image rtf vmacF32F16F16Eq1.math "MLIB_VMac_F32F16F16_Eq1"

*/
/**
@note         This function is implemented as inline and thus is
              not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac16 f16In3;
tFrac16 f16In4;
tFrac32 f32Out;

void main(void)
{
  // input1 value = 0.25
  f16In1 = FRAC16(0.25);

  // input2 value = 0.15
  f16In2 = FRAC16(0.15);

  // input3 value = 0.35
  f16In3 = FRAC16(0.35);

  // input4 value = 0.45
  f16In4 = FRAC16(0.45);

  // output should be FRAC32(0.195) = 0x18F5C28F
  f32Out = MLIB_VMac_F32F16F16(f16In1,f16In2,f16In3,f16In4);

  // output should be FRAC32(0.195) = 0x18F5C28F
  f32Out = MLIB_VMac(f16In1,f16In2,f16In3,f16In4, F32F16F16);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00241, DMLIB00233, DMLIB00237, DMLIB00239 */
SWLIBS_INLINE tFrac32 MLIB_VMac_F32F16F16(register tFrac16 f16In1,register tFrac16 f16In2,register tFrac16 f16In3,register tFrac16 f16In4)
{
  /* @remarks Implements DMLIB00238 */
  return(VMac_F32F16F16_C(f16In1,f16In2,f16In3,f16In4));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_VMac

@param[in]    f16In1     First input value to first multiplication.

@param[in]    f16In2     Second input value to first multiplication.

@param[in]    f16In3     First input value to second multiplication.

@param[in]    f16In4     Second input value to second multiplication.

@return       Vector multiplied input values with addition.

@details      The input values as well as output value is considered as 16-bit fractional values.
              The output saturation is implemented only for multiplication result inside this function.
              The output saturation is not implemented for addition in this function, thus in case
              the add of input values is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_VMac_F16
              \image rtf vmacF16Eq1.math "MLIB_VMac_F16_Eq1"

*/
/**
@note         This function is implemented as inline and thus is
              not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac16 f16In3;
tFrac16 f16In4;
tFrac16 f16Out;

void main(void)
{
  // input1 value = 0.25
  f16In1 = FRAC16(0.25);

  // input2 value = 0.15
  f16In2 = FRAC16(0.15);

  // input3 value = 0.35
  f16In3 = FRAC16(0.35);

  // input4 value = 0.45
  f16In4 = FRAC16(0.45);

  // output should be FRAC16(0.195) = 0x18F5
  f16Out = MLIB_VMac_F16(f16In1,f16In2,f16In3,f16In4);

  // output should be FRAC16(0.195) = 0x18F5
  f16Out = MLIB_VMac(f16In1,f16In2,f16In3,f16In4, F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC16(0.195) = 0x18F5
  f16Out = MLIB_VMac(f16In1,f16In2,f16In3,f16In4);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00241, DMLIB00233, DMLIB00235, DMLIB00239 */
SWLIBS_INLINE tFrac16 MLIB_VMac_F16(register tFrac16 f16In1,register tFrac16 f16In2,register tFrac16 f16In3,register tFrac16 f16In4)
{
  /* @remarks Implements DMLIB00238 */
  return(VMac_F16_C(f16In1,f16In2,f16In3,f16In4));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_VMac

@param[in]    fltIn1     First input value to first multiplication.

@param[in]    fltIn2     Second input value to first multiplication.

@param[in]    fltIn3     First input value to second multiplication.

@param[in]    fltIn4     Second input value to second multiplication.

@return       Vector multiplied input values with addition.

@details      The input values as well as output value is considered as single precision floating
              point values.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_VMac_FLT
              \image rtf vmacFLTEq1.math "MLIB_VMac_FLT_Eq1"

*/
/**
@note         The function may raise floating-point exceptions (invalid operation,
              overflow, underflow, inexact, input denormal). The floating-point unit must be enabled
              in CPACR register to prevent NOCP UsageFault exception.
*/
/**
@note         This function is implemented as inline assembly and
              thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFloat fltIn1;
tFloat fltIn2;
tFloat fltIn3;
tFloat fltIn4;
tFloat fltOut;

void main(void)
{
  // input1 value = 0.25
  fltIn1 = (tFloat)0.25;

  // input2 value = 0.15
  fltIn2 = (tFloat)0.15;

  // input3 value = 0.35
  fltIn3 = (tFloat)0.35;

  // input4 value = 0.45
  fltIn4 = (tFloat)0.45;

  // output should be 0.195
  fltOut = MLIB_VMac_FLT(fltIn1,fltIn2,fltIn3,fltIn4);

  // output should be 0.195
  fltOut = MLIB_VMac(fltIn1,fltIn2,fltIn3,fltIn4, FLT);

  // ##############################################################
  // Available only if single precision floating point
  // implementation selected as default
  // ##############################################################

  // output should be 0.195
  fltOut = MLIB_VMac(fltIn1,fltIn2,fltIn3,fltIn4);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00241, DMLIB00233, DMLIB00234, DMLIB00239 */
SWLIBS_INLINE tFloat MLIB_VMac_FLT(register tFloat fltIn1,register tFloat fltIn2,register tFloat fltIn3,register tFloat fltIn4)
{
  #if (defined(MLIB_ARMV7_ASM) && defined(__ghs__))
    /* @remarks Implements DMLIB00238 */
    return(VMac_FLT_ASM_ARMV7(fltIn1,fltIn2,fltIn3,fltIn4));
  #else
    /* @remarks Implements DMLIB00238 */
    return(VMac_FLT_C(fltIn1,fltIn2,fltIn3,fltIn4));
  #endif
}

#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_VMAC_H */
