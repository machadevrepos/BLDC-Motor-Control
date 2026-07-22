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
* @file       MLIB_Round.h
*
* @brief      Header file for MLIB_Round function
*
******************************************************************************/
#ifndef MLIB_ROUND_H
#define MLIB_ROUND_H
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
  #include "MLIB_AddSat.h"
  #include "MLIB_ShL.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_AddSat.h"
  #include "CCOV_MLIB_ShL.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_Round(...)     macro_dispatcher(MLIB_Round, __VA_ARGS__)(__VA_ARGS__)     /* This function rounds the first input value for number of digits defined by second parameter and saturate automatically. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00205 */
    #define MLIB_Round_Dsptchr_2(In1,In2)     MLIB_Round_Dsptchr_3(In1,In2,F32)     /* Function dispatcher for MLIB_Round_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00205 */
    #define MLIB_Round_Dsptchr_2(In1,In2)     MLIB_Round_Dsptchr_3(In1,In2,F16)     /* Function dispatcher for MLIB_Round_Dsptchr_2, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */

  #define MLIB_Round_Dsptchr_3(In1,In2,Impl)    MLIB_Round_Dsptchr_(In1,In2,Impl)   /* Function dispatcher for MLIB_Round_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00207 */
  #define MLIB_Round_Dsptchr_(In1,In2,Impl)     MLIB_Round_##Impl(In1,In2)          /* Function dispatcher for MLIB_Round_Dsptchr_, do not modify!!! */
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





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Round

@param[in]         f32In1     The value to be rounded.

@param[in]         u16In2     The number of trailing zeros in the rounded result.

@return       Rounded 32-bit fractional value. 

@note         The second input argument must not exceed 30 for positive and 31 for negative
              f32In1, respectively, otherwise the result is undefined.
              This function is implemented as inline
              and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac32 f32Out;
tU16 u16In2;

void main(void)
{
    // Example no. 1
    // first input = 0.25
    f32In1 = FRAC32(0.25);
    // second input = 29
    u16In2 = (tU16)29;

    // output should be 0x20000000 ~ FRAC32(0.25)
    f32Out = MLIB_Round_F32(f32In1,u16In2);

    // output should be 0x20000000 ~ FRAC32(0.25)
    f32Out = MLIB_Round(f32In1,u16In2,F32);

    // ##############################################################
    // Available only if 32-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be 0x20000000 ~ FRAC32(0.25)
    f32Out = MLIB_Round(f32In1,u16In2);


    // Example no. 2
    // first input = 0.375
    f32In1 = FRAC32(0.375);
    // second input = 29
    u16In2 = (tU16)29;

    // output should be 0x40000000 ~ FRAC32(0.5)
    f32Out = MLIB_Round_F32(f32In1,u16In2);


    // Example no. 3
    // first input = -0.375
    f32In1 = FRAC32(-0.375);
    // second input = 29
    u16In2 = (tU16)29;

    // output should be 0xE0000000 ~ FRAC32(-0.25)
    f32Out = MLIB_Round_F32(f32In1,u16In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00206, DMLIB00199, DMLIB00204 */
SWLIBS_INLINE tFrac32 MLIB_Round_F32(register tFrac32 f32In1,register tU16 u16In2)
{
    /* @remarks Implements DMLIB00202, DMLIB00203 */
    return(MLIB_AddSat_F32(f32In1, (tFrac32)((tU32)MLIB_ShL_F32((tFrac32)1u, u16In2) >> 1u)) & MLIB_ShL_F32((tFrac32)0xFFFFFFFFu, u16In2));
}




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Round

@param[in]         f16In1     The value to be rounded.

@param[in]         u16In2     The number of trailing zeros in the rounded result.

@return       Rounded 16-bit fractional value.

@note         The second input argument must not exceed 14 for positive and 15 for negative
              f16In1, respectively, otherwise the result is undefined.
              This function is implemented as inline
              and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16Out;
tU16 u16In2;

void main(void)
{
    // Example no. 1
    // first input = 0.25
    f16In1 = FRAC16(0.25);
    // second input = 13
    u16In2 = (tU16)13;

    // output should be 0x2000 ~ FRAC16(0.25)
    f16Out = MLIB_Round_F16(f16In1,u16In2);

    // output should be 0x2000 ~ FRAC16(0.25)
    f16Out = MLIB_Round(f16In1,u16In2,F16);

    // ##############################################################
    // Available only if 16-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be 0x2000 ~ FRAC16(0.25)
    f16Out = MLIB_Round(f16In1,u16In2);


    // Example no. 2
    // first input = 0.375
    f16In1 = FRAC16(0.375);
    // second input = 13
    u16In2 = (tU16)13;

    // output should be 0x4000 ~ FRAC16(0.5)
    f16Out = MLIB_Round_F16(f16In1,u16In2);


    // Example no. 3
    // first input = -0.375
    f16In1 = FRAC16(-0.375);
    // second input = 13
    u16In2 = (tU16)13;

    // output should be 0xE000 ~ FRAC16(-0.25)
    f16Out = MLIB_Round_F16(f16In1,u16In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00206, DMLIB00199, DMLIB00204 */
SWLIBS_INLINE tFrac16 MLIB_Round_F16(register tFrac16 f16In1,register tU16 u16In2)
{
    /* @remarks Implements DMLIB00201, DMLIB00203 */
    return(MLIB_AddSat_F16(f16In1, (tFrac16)((tU16)MLIB_ShL_F16((tFrac16)1u, u16In2) >> 1u)) & MLIB_ShL_F16((tFrac16)0xFFFFu, u16In2));
}

#ifdef __cplusplus
}
#endif

#endif /* MLIB_ROUND_H */
