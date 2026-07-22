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
* @file       MLIB_Convert.h
*
* @brief      Header file for MLIB_Convert function
*
******************************************************************************/
#ifndef MLIB_CONVERT_H
#define MLIB_CONVERT_H
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
  #include "MLIB_Mul.h"
  #include "MLIB_ShR.h"
  #include "MLIB_Div.h"
  #include "MLIB_MulSat.h"
  #include "MLIB_DivSat.h"
  #include "MLIB_Neg.h"
  #include "MLIB_NegSat.h"
  #include "MLIB_ConvertPU.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_ShL.h"
  #include "CCOV_MLIB_Mul.h"
  #include "CCOV_MLIB_ShR.h"
  #include "CCOV_MLIB_Div.h"
  #include "CCOV_MLIB_MulSat.h"
  #include "CCOV_MLIB_DivSat.h"
  #include "CCOV_MLIB_Neg.h"
  #include "CCOV_MLIB_NegSat.h"
  #include "CCOV_MLIB_ConvertPU.h"
#endif /* AMMCLIB_TESTING_ENV */

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_Convert(...)     macro_dispatcher(MLIB_Convert, __VA_ARGS__)(__VA_ARGS__)     /* This function converts the input value to different representation. */

  #define MLIB_Convert_Dsptchr_3(In1,In2,Impl)    MLIB_Convert_Dsptchr_(In1,In2,Impl)     /* Function dispatcher for MLIB_Convert_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00262*/
  #define MLIB_Convert_Dsptchr_(In1,In2,Impl)     MLIB_Convert_##Impl(In1,In2)            /* Function dispatcher for MLIB_Convert_Dsptchr_, do not modify!!! */
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

@functionality MLIB_Convert

@param[in]         f16In1     Input value in 16-bit fractional format to be converted.

@param[in]         f16In2     Scale factor in 16-bit fractional format.

@return       Converted input value in 32-bit fractional format.

@details      The input value is considered as 16-bit fractional data type and output value is
              considered as 32-bit fractional data type. The second argument is considered as 16-bit
              fractional data type. The sign of the second value represents the scale mechanism. In
              case the second value is positive the first input value is multiplied with the second
              one and converted to the output format. In case the second value is negative, the
              first input value is divided by absolute value of second input value and converted to
              the output format. The output saturation is not implemented in this function, thus in
              case the input value is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Convert_F32F16
              \image rtf convertF32F16Eq1.math "MLIB_Convert_F32F16_Eq1"

@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1, f16In2;
tFrac32 f32Out;

void main(void)
{
    // input value = 0.25 = 0x2000
    f16In1 = FRAC16(0.25);
    
    // scale value = 0.5 = 0x4000
    f16In2 = FRAC16(0.5);

    // output should be FRAC32(0.125) = 0x10000000
    f32Out = MLIB_Convert_F32F16(f16In1, f16In2);

    // output should be FRAC32(0.125) = 0x10000000
    f32Out = MLIB_Convert(f16In1, f16In2, F32F16);
    
    // scale value = -0.5 = 0xC000
    f16In2 = FRAC16(-0.5);

    // output should be FRAC32(0.5) = 0x40000000
    f32Out = MLIB_Convert_F32F16(f16In1, f16In2);

    // output should be FRAC32(0.5) = 0x40000000
    f32Out = MLIB_Convert(f16In1, f16In2, F32F16);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00261, DMLIB00257, DMLIB00260 */
SWLIBS_INLINE tFrac32 MLIB_Convert_F32F16(register tFrac16 f16In1,register tFrac16 f16In2)
{
  /* @remarks Implements DMLIB00257 */
  return((f16In2>=(tFrac16)0) ? MLIB_Mul_F32F16F16(f16In1, f16In2) : MLIB_DivSat_F32(MLIB_ShL_F32((tFrac32)f16In1,(tU16)16), MLIB_ShL_F32((tFrac32)MLIB_NegSat_F16(f16In2),(tU16)16)));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Convert

@param[in]         fltIn1     Input value in single precision floating point format to be converted.

@param[in]         fltIn2     Scale factor in single precision floating point format.

@return       Converted input value in 32-bit fractional format.

@details      The input value is considered as single precision floating point data type and output
              value is considered as 32-bit fractional data type. The second argument is considered
              as single precision floating point data type. The output saturation is implemented in
              this function, thus in case the input value is outside the [-1, 1) interval, the
              output value is limited to the boundary value.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Convert_F32FLT
              \image rtf convertF32FLTEq1.math "MLIB_Convert_F32FLT_Eq1"

*/
/**
@note         The function may raise floating-point exceptions (invalid operation,
              overflow, underflow, inexact, input denormal). The floating-point unit must be enabled
              in CPACR register to prevent NOCP UsageFault exception.
*/
/**
@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFloat fltIn1, fltIn2;
tFrac32 f32Out;

void main(void)
{
    // input value = 0.25
    fltIn1 = (tFloat)0.25;

    // scale value = 0.5
    fltIn2 = (tFloat)0.5;

    // output should be FRAC32(0.125) = 0x10000000
    f32Out = MLIB_Convert_F32FLT(fltIn1, fltIn2);

    // output should be FRAC32(0.125) = 0x10000000
    f32Out = MLIB_Convert(fltIn1, fltIn2, F32FLT);

    // scale value = 2
    fltIn2 = (tFloat)2;

    // output should be FRAC32(0.5) = 0x40000000
    f32Out = MLIB_Convert_F32FLT(fltIn1, fltIn2);

    // output should be FRAC32(0.5) = 0x40000000
    f32Out = MLIB_Convert(fltIn1, fltIn2, F32FLT);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00261, DMLIB00258, DMLIB00260 */
SWLIBS_INLINE tFrac32 MLIB_Convert_F32FLT(register tFloat fltIn1,register tFloat fltIn2)
{
  register tFloat fltInScaled;
  
  fltInScaled = MLIB_Mul_FLT(fltIn1, fltIn2);
  /* @remarks Implements DMLIB00258 */
  return((fltInScaled>=1.0f) ? (tFrac32)SWLIBS_INT32_MAX : ((fltInScaled<-1.0f) ? (tFrac32)SWLIBS_INT32_MIN : (tFrac32)MLIB_Mul_FLT(fltInScaled,((tFloat)SWLIBS_INT32_MAX)+1.0f)));
}





#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Convert

@param[in]         f32In1     Input value in 32-bit fractional format to be converted.

@param[in]         f32In2     Scale factor in 32-bit fractional format.

@return       Converted input value in 16-bit fractional format.

@details      The input value is considered as 32-bit fractional data type and output value is 
              considered as 16-bit fractional data type. The second value is considered as 32-bit
              fractional data type. The sign of the second value represents the scale mechanism. In
              case the second value is positive the first input value is multiplied with the second
              one and converted to the output format. In case the second value is negative, the
              first input value is divided by absolute value of second input value and converted to
              the output format. The output saturation is not implemented in this function, thus in
              case the input value is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Convert_F16F32
              \image rtf convertF16F32Eq1.math "MLIB_Convert_F16F32_Eq1"

@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1, f32In2;
tFrac16 f16Out;

void main(void)
{
    // input value = 0.25 = 0x20000000
    f32In1 = FRAC32(0.25);

    // scale value = 0.5 = 0x40000000
    f32In2 = FRAC32(0.5);

    // output should be FRAC16(0.125) = 0x1000
    f16Out = MLIB_Convert_F16F32(f32In1, f32In2);

    // output should be FRAC16(0.125) = 0x1000
    f16Out = MLIB_Convert(f32In1, f32In2, F16F32);

    // scale value = -0.5 = 0xC0000000
    f32In2 = FRAC32(-0.5);

    // output should be FRAC16(0.5) = 0x4000
    f16Out = MLIB_Convert_F16F32(f32In1, f32In2);

    // output should be FRAC16(0.5) = 0x4000
    f16Out = MLIB_Convert(f32In1, f32In2, F16F32);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00261, DMLIB00254, DMLIB00260 */
SWLIBS_INLINE tFrac16 MLIB_Convert_F16F32(register tFrac32 f32In1,register tFrac32 f32In2)
{
  /* @remarks Implements DMLIB00254 */
  return((f32In2>=(tFrac32)0) ? (tFrac16)MLIB_ShR_F32(MLIB_Mul_F32(f32In1, f32In2),(tU16)16) : (tFrac16)MLIB_ShR_F32(MLIB_DivSat_F32(f32In1, MLIB_NegSat_F32(f32In2)),(tU16)16));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Convert

@param[in]         fltIn1     Input value in single precision floating point format to be converted.

@param[in]         fltIn2     Scale factor in single precision floating point format.

@return       Converted input value in 16-bit fractional format.

@details      The input value is considered as single precision floating point data type and output
              value is considered as 16-bit fractional data type. The second value is considered as
              single precision floating point data type. The output saturation is implemented in
              this function, thus in case the input value is outside the [-1, 1) interval, the
              output value is limited to the boundary value.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Convert_F16FLT
              \image rtf convertF16FLTEq1.math "MLIB_Convert_F16FLT_Eq1"

*/
/**
@note         The function may raise floating-point exceptions (invalid operation,
              overflow, underflow, inexact, input denormal). The floating-point unit must be enabled
              in CPACR register to prevent NOCP UsageFault exception.
*/
/**
@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFloat fltIn1, fltIn2;
tFrac16 f16Out;

void main(void)
{
    // input value = 0.25
    fltIn1 = (tFloat)0.25;

    // scale value = 0.5
    fltIn2 = (tFloat)0.5;

    // output should be FRAC16(0.125) = 0x1000
    f16Out = MLIB_Convert_F16FLT(fltIn1, fltIn2);

    // output should be FRAC16(0.125) = 0x1000
    f16Out = MLIB_Convert(fltIn1, fltIn2, F16FLT);

    // scale value = 2
    fltIn2 = (tFloat)2;

    // output should be FRAC16(0.5) = 0x4000
    f16Out = MLIB_Convert_F16FLT(fltIn1, fltIn2);

    // output should be FRAC16(0.5) = 0x4000
    f16Out = MLIB_Convert(fltIn1, fltIn2, F16FLT);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00261, DMLIB00259, DMLIB00260 */
SWLIBS_INLINE tFrac16 MLIB_Convert_F16FLT(register tFloat fltIn1,register tFloat fltIn2)
{
  register tFloat fltInScaled;

  fltInScaled = MLIB_Mul_FLT(fltIn1, fltIn2);
  
  /* @remarks Implements DMLIB00259 */
  return((fltInScaled>=1.0f) ? (tFrac16)SWLIBS_INT16_MAX : ((fltInScaled<-1.0f) ? (tFrac16)SWLIBS_INT16_MIN : (tFrac16)MLIB_Mul_FLT(fltInScaled,((tFloat)SWLIBS_INT16_MAX)+1.0f)));
}





#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Convert

@param[in]         f16In1     Input value in 16-bit fractional format to be converted.

@param[in]         f16In2     Scale factor in 16-bit fractional format.

@return       Converted input value in single precision floating point format.

@details      The input value is considered as 16-bit fractional data type and output value is
              considered as single precision floating point data type. The second value is
              considered as 16-bit fractional data type. The sign of the second value represents the
              scale mechanism. In case the second value is positive the first input value is
              multiplied with the second one and converted to the output format. In case the second
              value is negative, the first input value is divided by absolute value of second input
              value and converted to the output format. The output saturation is not implemented
              in this function.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Convert_FLTF16
              \image rtf convertFLTF16Eq1.math "MLIB_Convert_FLTF16_Eq1"
              
*/
/**
@note         The function may raise floating-point exceptions (invalid operation, division by zero,
              overflow, underflow, inexact, input denormal). The floating-point unit must be enabled
              in CPACR register to prevent NOCP UsageFault exception.
*/
/**
@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tF16 f16In1, f16In2;
tFloat fltOut;

void main(void)
{
    // input value = 0.25 = 0x2000
    f16In1 = FRAC16(0.25);
    
    // scale value = 0.5 = 0x4000
    f16In2 = FRAC16(0.5);

    // output should be 0.125
    fltOut = MLIB_Convert_FLTF16(f16In1, f16In2);

    // output should be 0.125
    fltOut = MLIB_Convert(f16In1, f16In2, FLTF16);
    
    // scale value = -0.5 = 0xC000
    f16In2 = FRAC16(-0.5);

    // output should be 0.5
    fltOut = MLIB_Convert_FLTF16(f16In1, f16In2);

    // output should be 0.5
    fltOut = MLIB_Convert(f16In1, f16In2, FLTF16);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00261, DMLIB00256, DMLIB00260 */
SWLIBS_INLINE tFloat MLIB_Convert_FLTF16(register tFrac16 f16In1,register tFrac16 f16In2)
{
  /* @remarks Implements DMLIB00256 */
  return((f16In2>=(tFrac16)0) ? MLIB_Div_FLT((tFloat)MLIB_Mul_F32F16F16(f16In1,f16In2),(((tFloat)(SWLIBS_INT32_MAX))+1.0f))
                              :((f16In1 >= MLIB_NegSat_F16(f16In2))?1.0f
                              :((f16In1 <= f16In2)?-1.0f
                              :MLIB_Div_FLT(MLIB_ConvertPU_FLTF16(f16In1),MLIB_ConvertPU_FLTF16(MLIB_NegSat_F16(f16In2))))));  
}





#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Convert

@param[in]         f32In1     Input value in 32-bit fractional format to be converted.

@param[in]         f32In2     Scale factor in 32-bit fractional format.

@return       Converted input value in single precision floating point format.

@details      The input value is considered as 32-bit fractional data type and output value is
              considered as single precision floating point data type. The second value is
              considered as 32-bit fractional data type. The sign of the second value represents
              the scale mechanism. In case the second value is positive the first input value is
              multiplied with the second one and converted to the output format. In case the second
              value is negative, the first input value is divided by absolute value of second input
              value and converted to the output format. The output saturation is not implemented in
              this function.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Convert_FLTF32
              \image rtf convertFLTF32Eq1.math "MLIB_Convert_FLTF32_Eq1"

*/
/**
@note         The function may raise floating-point exceptions (invalid operation, division by zero,
              overflow, underflow, inexact, input denormal). The floating-point unit must be enabled
              in CPACR register to prevent NOCP UsageFault exception.
*/
/**
@note         This function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tF32 f32In1, f32In2;
tFloat fltOut;

void main(void)
{
    // input value = 0.25 = 0x2000
    f32In1 = FRAC32(0.25);

    // scale value = 0.5 = 0x4000
    f32In2 = FRAC32(0.5);

    // output should be 0.125
    fltOut = MLIB_Convert_FLTF32(f32In1, f32In2);

    // output should be 0.125
    fltOut = MLIB_Convert(f32In1, f32In2, FLTF32);

    // scale value = -0.5 = 0xC000
    f32In2 = FRAC32(-0.5);

    // output should be 0.5
    fltOut = MLIB_Convert_FLTF32(f32In1, f32In2);

    // output should be 0.5
    fltOut = MLIB_Convert(f32In1, f32In2, FLTF32);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
#ifdef __IAR_SYSTEMS_ICC__
  #pragma inline=forced
#endif
/* @remarks Implements DMLIB00261, DMLIB00255, DMLIB00260 */
SWLIBS_INLINE tFloat MLIB_Convert_FLTF32(register tFrac32 f32In1,register tFrac32 f32In2)
{
  /* @remarks Implements DMLIB00255 */
  return((f32In2>=(tFrac32)0) ? MLIB_Div_FLT((tFloat)(((tS64)f32In1*(tS64)f32In2)<<1),((tFloat)(((tS64)SWLIBS_INT32_MAX) << (tU16)32)))
                              :((f32In1 >= MLIB_NegSat_F32(f32In2))?1.0f
                              :((f32In1 <= f32In2)?-1.0f
                              :MLIB_Div_FLT(MLIB_ConvertPU_FLTF32(f32In1),MLIB_ConvertPU_FLTF32(MLIB_NegSat_F32(f32In2))))));
}

#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_CONVERT_H */
