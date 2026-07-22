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
* @file       MLIB_ShLSat.h
*
* @brief      Header file for MLIB_ShLSat function
*
******************************************************************************/
#ifndef MLIB_SHLSAT_H
#define MLIB_SHLSAT_H
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
  #include "MLIB_ShR.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_ShL.h"
  #include "CCOV_MLIB_ShR.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_ShLSat(...)     macro_dispatcher(MLIB_ShLSat, __VA_ARGS__)(__VA_ARGS__)     /* This function shifts the first parameter to left by number defined by second parameter and saturate if necessary. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00174 */
    #define MLIB_ShLSat_Dsptchr_2(In1,In2)     MLIB_ShLSat_Dsptchr_3(In1,In2,F32)     /* Function dispatcher for MLIB_ShLSat_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00174 */
    #define MLIB_ShLSat_Dsptchr_2(In1,In2)     MLIB_ShLSat_Dsptchr_3(In1,In2,F16)     /* Function dispatcher for MLIB_ShLSat_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */

  #define MLIB_ShLSat_Dsptchr_3(In1,In2,Impl)    MLIB_ShLSat_Dsptchr_(In1,In2,Impl)   /* Function dispatcher for MLIB_ShLSat_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00176 */
  #define MLIB_ShLSat_Dsptchr_(In1,In2,Impl)     MLIB_ShLSat_##Impl(In1,In2)          /* Function dispatcher for MLIB_ShLSat_Dsptchr_, do not modify!!! */
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
/* MLIB_ShLSat_F32 implementation variant - C */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac32 ShLSat_F32_C(register tFrac32 f32In,register tU16 u16In)
{
  register tFrac32 f32Out;
  register tFrac32 f32Temp;

  f32Out = MLIB_ShL_F32(f32In, u16In);
  f32Temp = MLIB_ShR_F32(f32Out, u16In);
  if(f32In != f32Temp){
    f32Temp = MLIB_ShR_F32(f32In, 31u);
    f32Out = f32Temp ^ SWLIBS_INT32_MAX;
  }
  return(f32Out);
}
/* MLIB_ShLSat_F16 implementation variant - C */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac16 ShLSat_F16_C(register tFrac16 f16In,register tU16 u16In)
{
  register tFrac16 f16Out;
  register tFrac16 f16Temp;

  f16Out = MLIB_ShL_F16(f16In, u16In);
  f16Temp = MLIB_ShR_F16(f16Out, u16In);
  if(f16In != f16Temp){
    f16Temp = MLIB_ShR_F16(f16In, 15u);
    f16Out = f16Temp ^ SWLIBS_INT16_MAX;
  }
  return(f16Out);
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
SWLIBS_INLINE tFrac16 ShLSat_F16_ASM_ARMV7(register tFrac16 f16In,register tU16 u16In)
{
  register tFrac32 f32Return, f32Temp, f32OutMax,f32In;
  register tFrac16 f16Return;

  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" lsl %0,%1,#16"  : "=r"(f32In): "r"(f16In));
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" ubfx %0,%1,#31,#1": "=r"(f32Return): "r"(f32In));
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" mvn %0,#0x80000000": "=r"(f32OutMax) :);
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" add %0,%1": "+r"(f32OutMax): "r"(f32Return));
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" lsl %0,%2,%3\n"
      " asr %1,%0,%3": "+&r"(f32Return), "=r"(f32Temp): "r"(f32In), "r"(u16In): "cc");
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" cmp %1,%3\n"
      " it ne\n"
      " movne %0,%2": "+r"(f32Return): "r"(f32Temp), "r"(f32OutMax), "r"(f32In): "cc");
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" asr %0,%1,#16"  : "=r"(f16Return): "r"(f32Return));
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" sxth %0,%0": "+r"(f16Return): ); 
  return(f16Return);
}
#endif /* MLIB_ARMV7_ASM */





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_ShLSat

@param[in]         f32In1     First value to be left shift.

@param[in]         u16In2     The shift amount value.

@return       32-bit fractional value shifted to left by the shift amount.
              The bits beyond the 32-bit boundary are discarded.

*/
/**
@note         The shift amount cannot exceed in magnitude the bit-width of the
              shift value, that means must be within the range 0...31. Otherwise
              the result of the function is undefined.
              This function is implemented as inline assembly,
              and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac32 f32Out;
tU16 u16In2;

void main(void)
{
    // first input = 0.25
    f32In1 = FRAC32(0.25);
    // second input = 1
    u16In2 = (tU16)1;

    // output should be 0x40000000 ~ FRAC32(0.5)
    f32Out = MLIB_ShLSat_F32(f32In1, u16In2);

    // output should be 0x40000000 ~ FRAC32(0.5)
    f32Out = MLIB_ShLSat(f32In1, u16In2, F32);

    // ##############################################################
    // Available only if 32-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be 0x40000000 ~ FRAC32(0.5)
    f32Out = MLIB_ShLSat(f32In1, u16In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00175, DMLIB00169, DMLIB00173, DMLIB00178 */
SWLIBS_INLINE tFrac32 MLIB_ShLSat_F32(register tFrac32 f32In1,register tU16 u16In2)
{
  /* @remarks Implements DMLIB00171, DMLIB00172 */
  return(ShLSat_F32_C(f32In1,u16In2));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_ShLSat

@param[in]         f16In1     First value to be left shift.

@param[in]         u16In2     The shift amount value.

@return       16-bit fractional value shifted to left by the shift amount.
              The bits beyond the 16-bit boundary are discarded.

*/
/**
@note         The shift amount cannot exceed in magnitude the bit-width of the
              shift value, that means must be within the range 0...15. Otherwise
              the result of the function is undefined.
              This function is implemented as inline assembly,
              and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16Out;
tU16 u16In2;

void main(void)
{
    // first input = 0.25
    f16In1 = FRAC16(0.25);
    // second input = 1
    u16In2 = (tU16)1;

    // output should be 0x4000 ~ FRAC16(0.5)
    f16Out = MLIB_ShLSat_F16(f16In1, u16In2);

    // output should be 0x4000 ~ FRAC16(0.5)
    f16Out = MLIB_ShLSat(f16In1, u16In2, F16);

    // ##############################################################
    // Available only if 16-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be 0x4000 ~ FRAC16(0.5)
    f16Out = MLIB_ShLSat(f16In1, u16In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00175, DMLIB00169, DMLIB00173, DMLIB00179 */
SWLIBS_INLINE tFrac16 MLIB_ShLSat_F16(register tFrac16 f16In1,register tU16 u16In2)
{
  /* @remarks Implements DMLIB00170, DMLIB00172 */
  return(ShLSat_F16_C(f16In1,u16In2));
}

#ifdef __cplusplus
}
#endif

#endif /* MLIB_SHLSAT_H */
