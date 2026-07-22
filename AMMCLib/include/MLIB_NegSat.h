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
* @file       MLIB_NegSat.h
*
* @brief      Header file for MLIB_NegSat function
*
******************************************************************************/
#ifndef MLIB_NEGSAT_H
#define MLIB_NEGSAT_H
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
  #include "MLIB_Neg.h"
#else
  /* Following include serves for NXP internal testing purposes only. 
  *  This header is not part of the release. */
  #include "CCOV_MLIB_Neg.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_NegSat(...)     macro_dispatcher(MLIB_NegSat, __VA_ARGS__)(__VA_ARGS__)     /* This function returns negative value of input parameter and saturate if necessary. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00036 */
    #define MLIB_NegSat_Dsptchr_1(In)     MLIB_NegSat_Dsptchr_2(In,F32)     /* Function dispatcher for MLIB_NegSat_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00036 */
    #define MLIB_NegSat_Dsptchr_1(In)     MLIB_NegSat_Dsptchr_2(In,F16)     /* Function dispatcher for MLIB_NegSat_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */

  #define MLIB_NegSat_Dsptchr_2(In,Impl)    MLIB_NegSat_Dsptchr_(In,Impl)     /* Function dispatcher for MLIB_NegSat_Dsptchr_2, do not modify!!! */
  
  /* @remarks Implements DMLIB00038 */
  #define MLIB_NegSat_Dsptchr_(In,Impl)     MLIB_NegSat_##Impl(In)            /* Function dispatcher for MLIB_NegSat_Dsptchr_, do not modify!!! */
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
SWLIBS_INLINE tFrac32 NegSat_F32_C(register tFrac32 f32In)
{
  register tFrac32 f32Out;
  
  if (f32In == INT32TOF32(SWLIBS_INT32_MIN)){
    f32Out = INT32TOF32(SWLIBS_INT32_MAX);
  }else{
    f32Out = MLIB_Neg_F32(f32In);
  }
  return(INT32TOF32(f32Out));  
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
SWLIBS_INLINE tFrac32 NegSat_F32_ASM_DSP(register tFrac32 f32In)
{
  register tFrac32 f32Return;

  f32Return = (tFrac32)0;
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" qsub %0,%0,%1": "+r"(f32Return): "r"(f32In));
  return(f32Return);
}
#endif /* MLIB_ARM_DSP_ASM */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac16 NegSat_F16_C(register tFrac16 f16In)
{
  register tFrac16 f16Out;
  
  if (f16In == INT16TOF16(SWLIBS_INT16_MIN)){
    f16Out = INT16TOF16(SWLIBS_INT16_MAX);
  }else{
    f16Out = MLIB_Neg_F16(f16In);
  }
  return(f16Out);
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
SWLIBS_INLINE tFrac16 NegSat_F16_ASM_DSP(register tFrac16 f16In)
{
  register tFrac16 f16Return;

  f16Return = (tFrac16)0;
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" qsub16 %0,%0,%1": "+r"(f16Return): "r"(f16In));
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" sxth %0,%0": "+r"(f16Return): );
  return(f16Return);
}
#endif /* MLIB_ARM_DSP_ASM */





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_NegSat

@param[in]    f32In      Input value which negative value should be returned.

@return       Negative value of input parameter.

@details      The input values as well as output value is considered as 32-bit fractional data 
              type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_NegSat_F32
              \image rtf negsatF32Eq1.math "MLIB_NegSat_F32_Eq1"

*/
/**
@note         This function is implemented as inline assembly, and thus is not ANSI-C compliant.
*/
/**

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
  f32Out = MLIB_NegSat_F32(f32In);

  // output should be FRAC32(-0.25) = 0xA0000000
  f32Out = MLIB_NegSat(f32In, F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC32(-0.25) = 0xA0000000
  f32Out = MLIB_NegSat(f32In);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00037, DMLIB00031, DMLIB00033, DMLIB00035, DMLIB00040 */
SWLIBS_INLINE tFrac32 MLIB_NegSat_F32(register tFrac32 f32In)
{
  #ifdef MLIB_ARM_DSP_ASM
    /* @remarks Implements DMLIB00034 */
    return(NegSat_F32_ASM_DSP(f32In));
  #else
    /* @remarks Implements DMLIB00034 */
    return(NegSat_F32_C(f32In));
  #endif /* MLIB_ARM_DSP_ASM */
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_NegSat

@param[in]    f16In      Input value which negative value should be returned.

@return       Negative value of input parameter.

@details      The input values as well as output value is considered as 16-bit fractional data 
              type.

              \par

              The output of the function is defined by the following simple equation:

              \anchor eq1_NegSat_F16
              \image rtf negsatF16Eq1.math "MLIB_NegSat_F16_Eq1"

*/
/**
@note         This function is implemented as inline assembly, and thus is not ANSI-C compliant.
*/
/**

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
  f16Out = MLIB_NegSat_F16(f16In);

  // output should be FRAC16(-0.25) = 0xA000
  f16Out = MLIB_NegSat(f16In, F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC16(-0.25) = 0xA000
  f16Out = MLIB_NegSat(f16In);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00037, DMLIB00031, DMLIB00032, DMLIB00035, DMLIB00041 */
SWLIBS_INLINE tFrac16 MLIB_NegSat_F16(register tFrac16 f16In)
{
  #ifdef MLIB_ARM_DSP_ASM
    /* @remarks Implements DMLIB00034 */
    return(NegSat_F16_ASM_DSP(f16In));
  #else
    /* @remarks Implements DMLIB00034 */
    return(NegSat_F16_C(f16In));
  #endif /* MLIB_ARM_DSP_ASM */
}


#ifdef __cplusplus
}
#endif

#endif /* MLIB_NEGSAT_H */
