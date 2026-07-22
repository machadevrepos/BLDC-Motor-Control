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
* @file       MLIB_Norm.h
*
* @brief      Header file for MLIB_Norm function
*
******************************************************************************/
#ifndef MLIB_NORM_H
#define MLIB_NORM_H
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
  #include "MLIB_ShL.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_ShR.h"
  #include "CCOV_MLIB_ShL.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_Norm(...)     macro_dispatcher(MLIB_Norm, __VA_ARGS__)(__VA_ARGS__)     /* This function returns the number of left shifts needed to normalize the input parameter. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00195 */
    #define MLIB_Norm_Dsptchr_1(In)     MLIB_Norm_Dsptchr_2(In,F32)     /* Function dispatcher for MLIB_Norm_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00195 */
    #define MLIB_Norm_Dsptchr_1(In)     MLIB_Norm_Dsptchr_2(In,F16)     /* Function dispatcher for MLIB_Norm_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */

  #define MLIB_Norm_Dsptchr_2(In,Impl)    MLIB_Norm_Dsptchr_(In,Impl)   /* Function dispatcher for MLIB_Norm_Dsptchr_2, do not modify!!! */
  
  /* @remarks Implements DMLIB00197 */
  #define MLIB_Norm_Dsptchr_(In,Impl)     MLIB_Norm_##Impl(In)          /* Function dispatcher for MLIB_Norm_Dsptchr_, do not modify!!! */
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
/* MLIB_Norm_F32 implementation variant - C */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tU16 Norm_F32_C(register tFrac32 f32In)
{
  register tU16 u16ShiftCount = (tU16)0;
  register tU16 u16Return;
  register tFrac32 f32InTmp;
  
  f32InTmp = f32In;
  if(f32InTmp == (tFrac32)0)
  {
    u16Return = (tU16)0;
  }
  else
  {
    if(f32InTmp > (tFrac32)0)
    {
      if (f32InTmp < (tFrac32)0x00FF0000u)
      {
        do
        {
          f32InTmp = MLIB_ShR_F32(f32InTmp,(tU16)1);
          u16ShiftCount += (tU16)1;
        } while(f32InTmp > (tFrac32)0);
        u16Return = (tU16)31-u16ShiftCount;
      }
      else
      {
        while(((f32InTmp & 0x40000000)==0))
        {
          f32InTmp = MLIB_ShL_F32(f32InTmp,(tU16)1);
          u16ShiftCount += (tU16)1;
        }
        u16Return = (tU16)u16ShiftCount;
      }  
    }
    else
    {
      if (f32InTmp > (tFrac32)0xFF000000u)
      {
        if(f32InTmp == (tFrac32)-1)
        {
          u16Return = (tU16)31;    
        }
        else
        {
          do
          {
            f32InTmp = MLIB_ShR_F32(f32InTmp,(tU16)1);
            u16ShiftCount += (tU16)1;
          } while(f32InTmp != (tFrac32)-1);
          u16Return = (tU16)31-u16ShiftCount;
        }
      }
      else
      {
        while((f32InTmp | (tFrac32)0xBFFFFFFFu) != (tFrac32)0xBFFFFFFFu)
        {
          f32InTmp = MLIB_ShL_F32(f32InTmp,(tU16)1);
          u16ShiftCount += (tU16)1;
        }
        u16Return = (tU16)u16ShiftCount;
      }  
    }
  }
  return(u16Return);
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
SWLIBS_INLINE tU16 Norm_F32_ASM_ARMV7(register tFrac32 f32In)
{
  register tFrac32 f32Tmp;
  register tU16 u16Return;

  if(f32In == (tFrac32)0)
  {
    u16Return = (tU16)0;
  }
  else
  {
    if(f32In == (tFrac32)-1)
    {
      u16Return = (tU16)31;
    }
    else
    {
      #ifdef __ghs__
        #pragma ghs optasm
      #endif
      SWLIBS_ASM(" movs %0,%1": "=r"(f32Tmp): "r"(f32In));
      #ifdef __ghs__
        #pragma ghs optasm
      #endif
      /* Compiler_Warning: The code is correct and verified by testing. */
      SWLIBS_ASM(" itt mi\n"
          " rsbmi %0,%0,#0\n"
          " submi %0,%0,#1"  : "+r"(f32Tmp): );
      #ifdef __ghs__
        #pragma ghs optasm
      #endif
      SWLIBS_ASM(" lsl %0,%0,#1"  : "+r"(f32Tmp): );
      #ifdef __ghs__
        #pragma ghs optasm
      #endif
      SWLIBS_ASM(" clz %0,%0": "+r"(f32Tmp): );
      u16Return = (tU16)f32Tmp;
    }
  }
  return(u16Return);
}
#endif /* MLIB_ARMV7_ASM */
/* MLIB_Norm_F16 implementation variant - C */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tU16 Norm_F16_C(register tFrac16 f16In)
{
  register tU16 u16Return = (tU16)0;
  register tFrac16 f16InTmp;

  f16InTmp = f16In;
  if(f16InTmp > (tFrac16)0)
  {
    if (f16InTmp < (tFrac16)0x00FF)
    {
      do
      {
        f16InTmp = MLIB_ShR_F16(f16InTmp,(tU16)1);
        u16Return += (tU16)1;
      } while(f16InTmp > (tFrac16)0);
      u16Return = (tU16)15-u16Return;
    }
    else
    {
      while(((f16InTmp & 0x4000)==0))
      {
        f16InTmp = MLIB_ShL_F16(f16InTmp,(tU16)1);
        u16Return += (tU16)1;
      }
    }  
  }
  else
  {
    if (f16InTmp < (tFrac16)0)
    {
      if (f16InTmp > (tFrac16)0xFF00u)
      {
        if(f16InTmp == (tFrac16)0xFFFFu)
        {
          u16Return = (tU16)15;    
        }
        else
        {
          do
          {
            f16InTmp = MLIB_ShR_F16(f16InTmp,(tU16)1);
            u16Return += (tU16)1;
          } while(f16InTmp != (tFrac16)0xFFFFu);
          u16Return = (tU16)15-u16Return;
        }
      }
      else
      {
        while((f16InTmp | (tFrac16)0xBFFFu) != (tFrac16)0xBFFFu)
        {
          f16InTmp = MLIB_ShL_F16(f16InTmp,(tU16)1);
          u16Return += (tU16)1;
        }
      }
    }
  }
  return(u16Return);
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
SWLIBS_INLINE tU16 Norm_F16_ASM_ARMV7(register tFrac16 f16In)
{
  register tFrac32 f32Tmp;
  register tU16 u16Return;

  if(f16In == (tFrac16)0)
  {
    u16Return = (tU16)0;
  }
  else
  {
    if(f16In == (tFrac16)0xFFFFu)
    {
      u16Return = (tU16)15;
    }
    else
    {
      #ifdef __ghs__
        #pragma ghs optasm
      #endif
      SWLIBS_ASM(" movs %0,%1,lsl #16": "=r"(f32Tmp): "r"(f16In));
      #ifdef __ghs__
        #pragma ghs optasm
      #endif
      /* Compiler_Warning: The code is correct and verified by testing. */
      SWLIBS_ASM(" itt mi\n"
          " rsbmi %0,%0,#0\n"
          " submi %0,%0,#1": "+r"(f32Tmp): );
      #ifdef __ghs__
        #pragma ghs optasm
      #endif
      SWLIBS_ASM(" lsl %0,%0,#1": "+r"(f32Tmp): );
      #ifdef __ghs__
        #pragma ghs optasm
      #endif
      SWLIBS_ASM(" clz %0,%0": "+r"(f32Tmp): );
      u16Return = (tU16)f32Tmp;
    }
  }
  return(u16Return);
}
#endif /* MLIB_ARMV7_ASM */





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Norm

@param[in]         f32In     The first value to be normalized.

@return       The number of left shift needed to normalize the argument.

*/
/**
@note         This function is implemented as inline and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In;
tU16 u16Out;

void main(void)
{
    // first input = 0.00005
    f32In = FRAC32(0.00005);

    // output should be 14
    u16Out = MLIB_Norm_F32(f32In);

    // output should be 14
    u16Out = MLIB_Norm(f32In,F32);

    // ##############################################################
    // Available only if 32-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be 14
    u16Out = MLIB_Norm(f32In);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00196, DMLIB00189, DMLIB00192, DMLIB00194 */
SWLIBS_INLINE tU16 MLIB_Norm_F32(register tFrac32 f32In)
{
  #ifdef MLIB_ARMV7_ASM
    /* @remarks Implements DMLIB00193 */
    return(Norm_F32_ASM_ARMV7(f32In));
  #else
    /* @remarks Implements DMLIB00193 */
    return(Norm_F32_C(f32In));
  #endif /* MLIB_ARMV7_ASM */
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Norm

@param[in]         f16In     The first value to be normalized.

@return       The number of left shift needed to normalize the argument.

*/
/**
@note         This function is implemented as inline and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In;
tU16 u16Out;

void main(void)
{
    // first input = 0.00005
    f16In = FRAC16(0.00005);

    // output should be 14
    u16Out = MLIB_Norm_F16(f16In);

    // output should be 14
    u16Out = MLIB_Norm(f16In,F16);

    // ##############################################################
    // Available only if 16-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be 14
    u16Out = MLIB_Norm(f16In);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00196, DMLIB00189, DMLIB00191, DMLIB00194 */
SWLIBS_INLINE tU16 MLIB_Norm_F16(register tFrac16 f16In)
{
  #ifdef MLIB_ARMV7_ASM
    /* @remarks Implements DMLIB00193 */
    return(Norm_F16_ASM_ARMV7(f16In));
  #else
    /* @remarks Implements DMLIB00193 */
    return(Norm_F16_C(f16In));
  #endif /* MLIB_ARMV7_ASM */
}

#ifdef __cplusplus
}
#endif

#endif /* MLIB_NORM_H */
