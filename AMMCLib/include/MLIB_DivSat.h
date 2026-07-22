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
* @file       MLIB_DivSat.h
*
* @brief      Header file for MLIB_DivSat function
*
******************************************************************************/
#ifndef MLIB_DIVSAT_H
#define MLIB_DIVSAT_H
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
  #include "MLIB_Div.h"
  #include "MLIB_AbsSat.h"
  #include "MLIB_ShR.h"
  #include "MLIB_ShL.h"
  #include "MLIB_ShLSat.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_Div.h"
  #include "CCOV_MLIB_AbsSat.h"
  #include "CCOV_MLIB_ShR.h"
  #include "CCOV_MLIB_ShL.h"
  #include "CCOV_MLIB_ShLSat.h"
#endif /* AMMCLIB_TESTING_ENV */

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_DivSat(...)     macro_dispatcher(MLIB_DivSat, __VA_ARGS__)(__VA_ARGS__)     /* This function divides the first parameter by the second one as saturate. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00134 */
    #define MLIB_DivSat_Dsptchr_2(In1,In2)     MLIB_DivSat_Dsptchr_3(In1,In2,F32)     /* Function dispatcher for MLIB_DivSat_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00134 */
    #define MLIB_DivSat_Dsptchr_2(In1,In2)     MLIB_DivSat_Dsptchr_3(In1,In2,F16)     /* Function dispatcher for MLIB_DivSat_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */

  #define MLIB_DivSat_Dsptchr_3(In1,In2,Impl)    MLIB_DivSat_Dsptchr_(In1,In2,Impl)     /* Function dispatcher for MLIB_DivSat_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00136 */
  #define MLIB_DivSat_Dsptchr_(In1,In2,Impl)     MLIB_DivSat_##Impl(In1,In2)            /* Function dispatcher for MLIB_DivSat_Dsptchr_, do not modify!!! */
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

/* MLIB_DivSat_F32 implementation variant - C */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac32 DivSat_F32_C(register tFrac32 f32In1,register tFrac32 f32In2)
{
  register tU32 u32N, u32D, u32R, u32Temp, u32i;
  register tFrac32 f32Return, f32Neg;
  
  f32Neg = (tFrac32)(f32In1 ^ f32In2) >> 31;
  u32Temp = 0u - (tU32)f32In1;
  u32N = ((tFrac32)u32Temp > (tFrac32)0) ? u32Temp : (tU32)f32In1;
  u32Temp = 0u - (tU32)f32In2;
  u32D = ((tFrac32)u32Temp > (tFrac32)0) ? u32Temp : (tU32)f32In2;
  if(u32N >= u32D)
  {
    /* overflow */
    u32R = (tU32)f32Neg ^ 0x7FFFFFFFu;
    f32Return = (tFrac32)u32R;
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
    u32N =  u32N << u32i;
    if (u32i>16u)
    {
      u32D = u32D << (u32i - 16u);
    }
    else
    {
      u32D = u32D >> (16u - u32i);
    }    
    u32R = (u32N / u32D);
    u32R = (u32R > 0xFFFFu) ? 0x7FFFFFFFu : (u32R << 15u);
    u32R = u32R ^ (tU32)f32Neg;
    f32Return = (tFrac32)u32R;
  }
  
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
  SWLIBS_INLINE tFrac32 DivSat_F32_ASM_ARMV7(register tFrac32 f32In1,register tFrac32 f32In2)
  {
    register tU32 u32N, u32D, u32R, u32i, u32Temp;
    register tFrac32 f32Return, f32Neg;
    
    f32Neg = (tFrac32)(f32In1 ^ f32In2) >> 31;
    u32Temp = 0u - (tU32)f32In1;
    u32N = ((tFrac32)u32Temp > (tFrac32)0) ? u32Temp : (tU32)f32In1;
    u32Temp = 0u - (tU32)f32In2;
    u32D = ((tFrac32)u32Temp > (tFrac32)0) ? u32Temp : (tU32)f32In2;
    if (u32N >= u32D)
    {
      /* overflow */
      u32R = (tU32)f32Neg ^ 0x7FFFFFFFu;
      f32Return = (tFrac32)u32R;
    }
    else
    {
      #ifdef __ghs__
        #pragma ghs optasm
      #endif
      SWLIBS_ASM(" clz %0,%1": "=r"(u32i): "r"(u32D));
      u32N =  u32N << u32i;
      if (u32i>16u)
      {
        u32D = u32D << (u32i - 16u);
      }
      else
      {
        u32D = u32D >> (16u - u32i);
      }    
      u32R = (u32N / u32D);
      u32R = (u32R > 0xFFFFu) ? 0x7FFFFFFFu : (u32R << 15u);
      u32R = u32R ^ (tU32)f32Neg;
      f32Return = (tFrac32)u32R;
    }
    
    return(f32Return);
  }
#endif /* MLIB_ARMV7_ASM */

/* MLIB_DivSatAccurate_F32 implementation variant - C */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac32 DivSatAccurate_F32_C(register tFrac32 f32In1,register tFrac32 f32In2)
{
  register tFrac32 f32Return, f32Neg;
  register tU32 u32N, u32D, u32R, u32Temp, u32Rem, u32Qdtmp, u32Q1, u32N0;
  register tU16 u16D1, u16D0, u16Q1, u16Q0, u16Rem;
  register tU32 u32i;

  f32Neg = (tFrac32)(f32In1 ^ f32In2) >> 31u;
  u32Temp = 0u - (tU32)f32In1;
  u32N = ((tFrac32)u32Temp > (tFrac32)0) ? u32Temp : (tU32)f32In1;
  u32Temp = 0u - (tU32)f32In2;
  u32D = ((tFrac32)u32Temp > (tFrac32)0) ? u32Temp : (tU32)f32In2;
  if(u32N >= u32D)
  {
    /* overflow */
    u32R = (tU32)f32Neg ^ 0x7FFFFFFFu;
    f32Return = (tFrac32)u32R;
  }
  else
  {
    /* normalization */
    u32Temp = u32D;
    if (u32Temp < 0x00010000u)
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
    u32N <<= u32i;
    u32D <<= u32i;
    /* 32-bit divisor is split into 16-bit words */
    u16D0 = (tU16)(u32D & 0xFFFFu);
    u16D1 = (tU16)(u32D >> 16u);
    /* high word result */
    u32Q1 = u32N/u16D1;
    u32Rem = u32N % u16D1;
    u32Qdtmp = u32Q1*u16D0;
    if(u32Qdtmp > (u32Rem << 16u))
    {
      u32Q1--;
      u32Rem += u16D1;
      if(u32Rem <= 0xFFFFu)
      {
        u32Qdtmp -= u16D0;
        if(u32Qdtmp > (u32Rem << 16u))
        {
          u32Q1--;
        }
      }
    }
    u16Q1 = (tU16)u32Q1;
    /* intermediate result is subtracted */
    u32N0 = (u32N << 16u) - (u16Q1*u32D);
    /* low word result */
    u32N0 >>= 1u;
    u16Q0 = (tU16)(u32N0/u16D1);
    u16Rem = (tU16)(u32N0 % u16D1);
    u32Qdtmp = (tU32)u16Q0*u16D0;
    if(u32Qdtmp > ((tU32)u16Rem << 16u))
    {
      u16Q0--;
    }
    /* combination of the 16-bit words into 32-bit result */
    u32R = ((tU32)u16Q1 << 15u) + u16Q0;
    /* sign adjustment */
    u32R ^= (tU32)f32Neg;
    u32R += ((tU32)f32Neg >> 31u);
    f32Return = (tFrac32)u32R;
  }
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
  SWLIBS_INLINE tFrac32 DivSatAccurate_F32_ASM_ARMV7(register tFrac32 f32In1,register tFrac32 f32In2)
  {
    register tFrac32 f32Return, f32Neg;
    register tU32 u32N, u32D, u32R, u32Temp, u32Rem, u32Qdtmp, u32Q1, u32N0;
    register tU16 u16D1, u16D0, u16Q1, u16Q0, u16Rem;
    register tU32 u32i;

    f32Neg = (tFrac32)(f32In1 ^ f32In2) >> 31u;
    u32Temp = 0u - (tU32)f32In1;
    u32N = ((tFrac32)u32Temp > (tFrac32)0) ? u32Temp : (tU32)f32In1;
    u32Temp = 0u - (tU32)f32In2;
    u32D = ((tFrac32)u32Temp > (tFrac32)0) ? u32Temp : (tU32)f32In2;
    if(u32N >= u32D)
    {
      /* overflow */
      u32R = (tU32)f32Neg ^ 0x7FFFFFFFu;
      f32Return = (tFrac32)u32R;
    }
    else
    {
      /* normalization */
      #ifdef __ghs__
        #pragma ghs optasm
      #endif
      SWLIBS_ASM(" clz %0,%1": "=r"(u32i): "r"(u32D));
      u32N <<= u32i;
      u32D <<= u32i;
      /* 32-bit divisor is split into 16-bit words */
      u16D0 = (tU16)(u32D & 0xFFFFu);
      u16D1 = (tU16)(u32D >> 16u);
      /* high word result */
      u32Q1 = u32N/u16D1;
      u32Rem = u32N % u16D1;
      u32Qdtmp = u32Q1*u16D0;
      if(u32Qdtmp > (u32Rem << 16u))
      {
        u32Q1--;
        u32Rem += u16D1;
        if(u32Rem <= 0xFFFFu)
        {
          u32Qdtmp -= u16D0;
          if(u32Qdtmp > (u32Rem << 16u))
          {
            u32Q1--;
          }
        }
      }
      u16Q1 = (tU16)u32Q1;
      /* intermediate result is subtracted */
      u32N0 = (u32N << 16u) - (u16Q1*u32D);
      /* low word result */
      u32N0 >>= 1u;
      u16Q0 = (tU16)(u32N0/u16D1);
      u16Rem = (tU16)(u32N0 % u16D1);
      u32Qdtmp = (tU32)u16Q0*u16D0;
      if(u32Qdtmp > ((tU32)u16Rem << 16u))
      {
        u16Q0--;
      }
      /* combination of the 16-bit words into 32-bit result */
      u32R = ((tU32)u16Q1 << 15u) + u16Q0;
      /* sign adjustment */
      u32R ^= (tU32)f32Neg;
      u32R += ((tU32)f32Neg >> 31u);
      f32Return = (tFrac32)u32R;
    }
    return(f32Return);
  }
#endif /* MLIB_ARMV7_ASM */

/* MLIB_DivSat_F16 implementation variant - C */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* C implementation */
SWLIBS_INLINE tFrac16 DivSat_F16_C(register tFrac16 f16In1,register tFrac16 f16In2)
{
  register tFrac16 f16Return;

  if (f16In2 == (tFrac16)0){
    f16Return = (f16In1 > (tFrac16)0) ? INT16TOF16(SWLIBS_INT16_MAX) : INT16TOF16(SWLIBS_INT16_MIN);
  }else{
    f16Return = (MLIB_AbsSat_F16(f16In1) >= MLIB_AbsSat_F16(f16In2)) ? ((((SWLIBS_INT16_MIN & f16In1)^(SWLIBS_INT16_MIN & f16In2)) == SWLIBS_INT16_MIN) ? INT16TOF16(SWLIBS_INT16_MIN) : INT16TOF16(SWLIBS_INT16_MAX)) : MLIB_Div_F16(f16In1, f16In2);
  }
  return(f16Return);
}



/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_DivSat

@param[in]         f32In1     Numerator of division.

@param[in]         f32In2     Denominator of division.

@return       Fast division of two input values, saturated if necessary.

@details      The input values as well as output value is considered as 32-bit fractional data 
              type. This is a fast variant of the 32-bit division with only the most significant
              16 bits of the result being accurate. If full 32-bit accuracy of the result is needed,
              use #MLIB_DivSatAccurate_F32 (note that the accurate variant consumes more clock
              cycles).

              \par
              
              The output of the function is defined by the following simple equation:
              \anchor eq1_DivSat_F32
              \image rtf divsatF32Eq1.math "MLIB_DivSat_F32_Eq1"

*/
/**
@note         This function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1, f32In2;
tFrac32 f32Out;

void main(void)
{
  // input value 1 = 0.25
  f32In1 = FRAC32(0.25);
  // input value 2 = 0.5
  f32In2 = FRAC32(0.5);

  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_DivSat_F32(f32In1, f32In2);

  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_DivSat(f32In1, f32In2, F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_DivSat(f32In1, f32In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00135, DMLIB00123, DMLIB00131, DMLIB00133, DMLIB00138 */
SWLIBS_INLINE tFrac32 MLIB_DivSat_F32(register tFrac32 f32In1,register tFrac32 f32In2)
{
  #ifdef MLIB_ARMV7_ASM
    /* @remarks Implements DMLIB00124, DMLIB00127, DMLIB00132 */
    return(DivSat_F32_ASM_ARMV7(f32In1,f32In2));
  #else
    /* @remarks Implements DMLIB00124, DMLIB00127, DMLIB00132 */
    return(DivSat_F32_C(f32In1,f32In2));
  #endif
}


/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_DivSat

@param[in]         f32In1     Numerator of division.

@param[in]         f32In2     Denominator of division.

@return       Accurate division of two input values, saturated if necessary.

@details      The input values as well as output value is considered as 32-bit fractional data 
              type. This variant provides full 32-bit accuracy of the result at the cost of
              consuming more clock cycles. If only the most significant 16 bits of the result
              need to be accurate, use the faster variant #MLIB_DivSat_F32.

              \par
              
              The output of the function is defined by the following simple equation:
              \anchor eq1_DivSat_F32
              \image rtf divsatF32Eq1.math "MLIB_DivSat_F32_Eq1"

@note         Only the implementation suffix-based format of the API is provided.
*/
/**
@note         This function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1, f32In2;
tFrac32 f32Out;

void main(void)
{
  // input value 1 = 0.25
  f32In1 = FRAC32(0.25);
  // input value 2 = 0.5
  f32In2 = FRAC32(0.5);

  // Note: Only the implementation suffix-based format of the API is provided.
  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_DivSatAccurate_F32(f32In1, f32In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00312 */
SWLIBS_INLINE tFrac32 MLIB_DivSatAccurate_F32(register tFrac32 f32In1,register tFrac32 f32In2)
{
  #ifdef MLIB_ARMV7_ASM
    return(DivSatAccurate_F32_ASM_ARMV7(f32In1,f32In2));
  #else
    return(DivSatAccurate_F32_C(f32In1,f32In2));
  #endif
}


/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_DivSat

@param[in]         f16In1     Numerator of division.

@param[in]         f16In2     Denominator of division.

@return       Division of two input values, saturated if necessary.

@details      The input values as well as output value is considered as 16-bit fractional data 
              type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_DivSat_F16
              \image rtf divsatF16Eq1.math "MLIB_DivSat_F16_Eq1"

*/
/**
@note         This function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1, f16In2;
tFrac16 f16Out;

void main(void)
{
  // input value 1 = 0.25
  f16In1 = FRAC16(0.25);
  // input value 2 = 0.5
  f16In2 = FRAC16(0.5);

  // output should be FRAC16(0.5) = 0x4000
  f16Out = MLIB_DivSat_F16(f16In1, f16In2);

  // output should be FRAC16(0.5) = 0x4000
  f16Out = MLIB_DivSat(f16In1, f16In2, F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC16(0.5) = 0x4000
  f16Out = MLIB_DivSat(f16In1, f16In2);
}
\endcode
****************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00135, DMLIB00123, DMLIB00130, DMLIB00133, DMLIB00139 */
SWLIBS_INLINE tFrac16 MLIB_DivSat_F16(register tFrac16 f16In1,register tFrac16 f16In2)
{
  /* @remarks Implements DMLIB00125, DMLIB00128, DMLIB00132 */
  return(DivSat_F16_C(f16In1,f16In2));
}

#ifdef __cplusplus
}
#endif

#endif /* MLIB_DIVSAT_H */
