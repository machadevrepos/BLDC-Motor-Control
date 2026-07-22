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
* @file       MLIB_MulSat.h
*
* @brief      Header file for MLIB_MulSat function
*
******************************************************************************/
#ifndef MLIB_MULSAT_H
#define MLIB_MULSAT_H
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
  #include "MLIB_Mul.h"
  #include "MLIB_ConvertPU.h"
#else
  /* Following include serves for NXP internal testing purposes only. 
  *  This header is not part of the release. */
  #include "CCOV_MLIB_Mul.h"
  #include "CCOV_MLIB_ConvertPU.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_MulSat(...)     macro_dispatcher(MLIB_MulSat, __VA_ARGS__)(__VA_ARGS__)     /* This function multiply two input parameters and saturate if necessary. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00101 */
    #define MLIB_MulSat_Dsptchr_2(In1,In2)     MLIB_MulSat_Dsptchr_3(In1,In2,F32)     /* Function dispatcher for MLIB_MulSat_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00101 */
    #define MLIB_MulSat_Dsptchr_2(In1,In2)     MLIB_MulSat_Dsptchr_3(In1,In2,F16)     /* Function dispatcher for MLIB_MulSat_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */

  #define MLIB_MulSat_Dsptchr_3(In1,In2,Impl)    MLIB_MulSat_Dsptchr_(In1,In2,Impl)     /* Function dispatcher for MLIB_MulSat_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00103 */
  #define MLIB_MulSat_Dsptchr_(In1,In2,Impl)     MLIB_MulSat_##Impl(In1,In2)            /* Function dispatcher for MLIB_MulSat_Dsptchr_, do not modify!!! */
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
SWLIBS_INLINE tFrac32 MulSat_F32_C(register tFrac32 f32In1,register tFrac32 f32In2)
{
  register tS32 s32Temp;

  s32Temp = F32TOINT32(MLIB_Mul_F32(f32In1, f32In2));
    s32Temp = (s32Temp == SWLIBS_INT32_MIN) ? SWLIBS_INT32_MAX : s32Temp;
  return(INT32TOF32(s32Temp));
}
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac32 MulSat_F32F16F16_C(register tFrac16 f16In1,register tFrac16 f16In2)
{
  register tS32 s32Temp;

  s32Temp = F32TOINT32(MLIB_Mul_F32F16F16(f16In1, f16In2));
  s32Temp = (s32Temp == SWLIBS_INT32_MIN) ? SWLIBS_INT32_MAX : s32Temp;
  return(INT32TOF32(s32Temp));
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
SWLIBS_INLINE tFrac32 MulSat_F32_ASM_DSP(register tFrac32 f32In1,register tFrac32 f32In2)
{
  register tFrac32 f32Low, f32High, f32Return;

  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" smull %0,%1,%2,%3": "=r"(f32Low), "=r"(f32High): "r"(f32In1), "r"(f32In2));
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" lsr %0,%1,#31": "=r"(f32Return): "r"(f32Low));
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
   SWLIBS_ASM(" qdadd %0,%0,%1": "+r"(f32Return): "r"(f32High));
  return(f32Return);
}
#endif /* MLIB_ARM_DSP_ASM */
#ifdef MLIB_ARM_DSP_ASM
  #ifdef __ghs__
    #pragma ghs static_call 0
    #pragma ghs extra_stack 0
  #endif
  #ifdef __IAR_SYSTEMS_ICC__
    #pragma inline=forced
  #endif
/* Target-specific implementation */
SWLIBS_INLINE tFrac32 MulSat_F32F16F16_ASM_DSP(register tFrac16 f16In1,register tFrac16 f16In2)
{
  register tFrac32 f32Return;

  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" smulbb %0,%1,%2": "=r"(f32Return): "r"(f16In1), "r"(f16In2));
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" qadd %0,%0,%0": "+r"(f32Return): );
  return(f32Return);
}
#endif /* MLIB_ARM_DSP_ASM */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac16 MulSat_F16_C(register tFrac16 f16In1,register tFrac16 f16In2)
{
  register tS16 s16Temp;

  s16Temp = F16TOINT16(MLIB_Mul_F16(f16In1, f16In2));
  s16Temp = (s16Temp == SWLIBS_INT16_MIN) ? SWLIBS_INT16_MAX : s16Temp;
  return(INT16TOF16(s16Temp));
}





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_MulSat

@param[in]    f32In1     Operand is a 32-bit number normalized between [-1,1).

@param[in]    f32In2     Operand is a 32-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      The input values as well as output value are considered as 32-bit fractional data
              type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_MulSat_F32
              \image rtf mulsatF32Eq1.math "MLIB_MulSat_F32_Eq1"

*/
/**
@note         This function is implemented as inline assembly and thus is not ANSI-C compliant.
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
  // first input = 0.8
  f32In1 = FRAC32(0.8);

  // second input = 0.75
  f32In2 = FRAC32(0.75);

  // output should be 0x4ccccccc = FRAC32(0.6)
  f32Out = MLIB_MulSat_F32(f32In1,f32In2);

  // output should be 0x4ccccccc = FRAC32(0.6)
  f32Out = MLIB_MulSat(f32In1,f32In2,F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x4ccccccc = FRAC32(0.6)
  f32Out = MLIB_MulSat(f32In1,f32In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00102, DMLIB00095, DMLIB00097, DMLIB00100, DMLIB00105 */
SWLIBS_INLINE tFrac32 MLIB_MulSat_F32(register tFrac32 f32In1,register tFrac32 f32In2)
{
  #ifdef MLIB_ARM_DSP_ASM
    /* @remarks Implements DMLIB00098 */
    return(MulSat_F32_ASM_DSP(f32In1,f32In2));
  #else
    /* @remarks Implements DMLIB00098 */
    return(MulSat_F32_C(f32In1,f32In2));
  #endif /* MLIB_ARM_DSP_ASM */
}





/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_MulSat

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      The input values are considered as 16-bit fractional data type and the output value is
              considered as 32-bit fractional data type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_MulSat_F32F16F16
              \image rtf mulsatF32F16F16Eq1.math "MLIB_MulSat_F32F16F16_Eq1"

*/
/**
@note         This function is implemented as inline assembly and thus is not ANSI-C compliant.
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
  // first input = 0.8
  f16In1 = FRAC16(0.8);

  // second input = 0.75
  f16In2 = FRAC16(0.75);

  // output should be 0x4ccccccc = FRAC32(0.6)
  f32Out = MLIB_MulSat_F32F16F16(f16In1,f16In2);

  // output should be 0x4ccccccc = FRAC32(0.6)
  f32Out = MLIB_MulSat(f32In1,f32In2,F32F16f16);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00102, DMLIB00095, DMLIB00099, DMLIB00100, DMLIB00105 */
SWLIBS_INLINE tFrac32 MLIB_MulSat_F32F16F16(register tFrac16 f16In1,register tFrac16 f16In2)
{
  #ifdef MLIB_ARM_DSP_ASM
    /* @remarks Implements DMLIB00098 */
    return(MulSat_F32F16F16_ASM_DSP(f16In1,f16In2));
  #else
    /* @remarks Implements DMLIB00098 */
    return(MulSat_F32F16F16_C(f16In1,f16In2));
  #endif /* MLIB_ARM_DSP_ASM */
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_MulSat

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      The input values as well as output value are considered as 16-bit fractional data
              type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_MulSat_F16
              \image rtf mulsatF16Eq1.math "MLIB_MulSat_F16_Eq1"

*/
/**
@note         This function is implemented as inline and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac16 f16Out;

void main(void)
{
  // first input = 0.8
  f16In1 = FRAC16(0.8);

  // second input = 0.75
  f16In2 = FRAC16(0.75);

  // output should be 0x4ccc = FRAC16(0.6)
  f16Out = MLIB_MulSat_F16(f16In1,f16In2);

  // output should be 0x4ccc = FRAC16(0.6)
  f16Out = MLIB_MulSat(f16In1,f16In2,F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x4ccc = FRAC32(0.6)
  f16Out = MLIB_MulSat(f16In1,f16In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00102, DMLIB00095, DMLIB00096, DMLIB00100, DMLIB00106 */
SWLIBS_INLINE tFrac16 MLIB_MulSat_F16(register tFrac16 f16In1,register tFrac16 f16In2)
{
  /* @remarks Implements DMLIB00098 */
  return(MulSat_F16_C(f16In1,f16In2));
}


#ifdef __cplusplus
}
#endif

#endif /* MLIB_MULSAT_H */
