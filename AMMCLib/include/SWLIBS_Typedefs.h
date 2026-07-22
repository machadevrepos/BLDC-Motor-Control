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
* @file     SWLIBS_Typedefs.h
* 
* @brief    Basic types definition file.
*
*******************************************************************************
*
******************************************************************************/


#ifndef SWLIBS_TYPEDEFS_H
#define SWLIBS_TYPEDEFS_H

#include "SWLIBS_Config.h"
#include "SWLIBS_MacroDisp.h"

/******************************************************************************
* Implementation configuration checking            (scope: module-global)
******************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #ifndef SWLIBS_DEFAULT_IMPLEMENTATION
    #error "Please select the default implementation in the file SWLIBS_Config.h."
  #else
    #if((SWLIBS_DEFAULT_IMPLEMENTATION != SWLIBS_DEFAULT_IMPLEMENTATION_F32)&& \
        (SWLIBS_DEFAULT_IMPLEMENTATION != SWLIBS_DEFAULT_IMPLEMENTATION_F16)&& \
        (SWLIBS_DEFAULT_IMPLEMENTATION != SWLIBS_DEFAULT_IMPLEMENTATION_FLT))
      #error "Please select the default implementation in the file SWLIBS_Config.h."
    #endif
  #endif

  #if((SWLIBS_SUPPORT_F32 == SWLIBS_STD_OFF)&&(SWLIBS_SUPPORT_F16 == SWLIBS_STD_OFF)&&(SWLIBS_SUPPORT_FLT == SWLIBS_STD_OFF))
    #error "Define at least one supported implementation in SWLIBS_Config.h file."
  #endif

  #if((SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)&&(SWLIBS_SUPPORT_F32 == SWLIBS_STD_OFF))
    #error "Set the SWLIBS_SUPPORT_F32 to SWLIBS_STD_ON in SWLIBS_Config.h file to support FRAC32 default implementation."
  #endif

  #if((SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)&&(SWLIBS_SUPPORT_F16 == SWLIBS_STD_OFF))
    #error "Set the SWLIBS_SUPPORT_F16 to SWLIBS_STD_ON in SWLIBS_Config.h file to support FRAC16 default implementation."
  #endif

  #if((SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)&&(SWLIBS_SUPPORT_FLT == SWLIBS_STD_OFF))
    #error "Set the SWLIBS_SUPPORT_FLT to SWLIBS_STD_ON in SWLIBS_Config.h file to support FLOAT default implementation."
  #endif
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
#ifndef NULL
  #ifdef __cplusplus
    #define NULL ((void*)0)
  #else
    #define NULL 0
  #endif
#endif /* NULL */


/******************************************************************************
* Defines and macros            (scope: module-global)
******************************************************************************/

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
#ifdef TRUE
  #undef TRUE
#endif
#ifdef FALSE
  #undef FALSE
#endif
/************************************************************************//**
@enum   tBool

@brief  Enum representing basic boolean type.
*//*************************************************************************/
typedef enum
{
  FALSE = 0,                                /**< Boolean type FALSE constant */
  TRUE  = 1                                 /**< Boolean type TRUE constant */
} tBool;

#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/************************************************************************//**
@enum   tAmmclibTuningMode

@brief  Enum representing tuning mode for AMMCLIB tuning functions.
*//*************************************************************************/
typedef enum
{
  AMMCLIB_TUNING_MODE_BASIC = 0,  /**< Tuning mode: BASIC -> automatic tuning of function bandwidth and attenuation. */
  AMMCLIB_TUNING_MODE_EXPERT = 1  /**< Tuning mode: EXPERT -> manual tuning of function bandwidth and attenuation. */
} tAmmclibTuningMode;
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */


#ifndef __SIZEOF_LONG__
  #define __SIZEOF_LONG__ 4
#endif
#if (__SIZEOF_LONG__ == 8)
  typedef unsigned int        tU32;           /**< unsigned 32-bit integer type */
  typedef signed int          tS32;           /**< signed 32-bit integer type */
  typedef signed long         tS64;           /**< signed 64-bit integer type */
  typedef unsigned long       tU64;           /**< unsigned 64-bit integer type */
#else

#if (!(defined(__cevacxd__) || defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE) || defined(__DCC__) || defined(__ghs__)))
  typedef unsigned long       tU32;           /**< unsigned 32-bit integer type */
  typedef signed long         tS32;           /**< signed 32-bit integer type */
#else
  typedef unsigned int        tU32;           /**< unsigned 32-bit integer type */
  typedef signed int          tS32;           /**< signed 32-bit integer type */
#endif /* !(defined(__cevacxd__) || defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE) || defined(__DCC__) || defined(__ghs__)) */
  typedef signed long long    tS64;           /**< signed 64-bit integer type */
  typedef unsigned long long  tU64;           /**< unsigned 64-bit integer type */
#endif /* __SIZEOF_LONG__ == 8 */
typedef unsigned char       tU8;            /**< unsigned 8-bit integer type */
typedef signed char         tS8;            /**< signed 8-bit integer type */
typedef unsigned short      tU16;           /**< unsigned 16-bit integer type */
typedef signed short        tS16;           /**< signed 16-bit integer type */
typedef tS16                tFrac16;        /**< 16-bit signed fractional Q1.15 type */
typedef tS32                tFrac32;        /**< 32-bit Q1.31 type */
typedef float               tFloat;         /**< single precision float type */
typedef double              tDouble;        /**< double precision float type */

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define SWLIBS_2Syst    SWLIBS_2Syst_F32                        /**< Definition of SWLIBS_2Syst as alias for SWLIBS_2Syst_F32 array in case the 32-bit fractional implementation is selected. */
    #define SWLIBS_3Syst    SWLIBS_3Syst_F32                        /**< Definition of SWLIBS_3Syst as alias for SWLIBS_3Syst_F32 array in case the 32-bit fractional implementation is selected. */
    #define SWLIBS_6Syst    SWLIBS_6Syst_F32                        /**< Definition of SWLIBS_6Syst as alias for SWLIBS_3Syst_F32 array in case the 32-bit fractional implementation is selected. */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define SWLIBS_2Syst    SWLIBS_2Syst_F16                        /**< Definition of SWLIBS_2Syst as alias for SWLIBS_2Syst_F16 array in case the 16-bit fractional implementation is selected. */
    #define SWLIBS_3Syst    SWLIBS_3Syst_F16                        /**< Definition of SWLIBS_3Syst as alias for SWLIBS_3Syst_F16 array in case the 16-bit fractional implementation is selected. */
    #define SWLIBS_6Syst    SWLIBS_6Syst_F16                        /**< Definition of SWLIBS_6Syst as alias for SWLIBS_3Syst_F16 array in case the 16-bit fractional implementation is selected. */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define SWLIBS_2Syst    SWLIBS_2Syst_FLT                        /**< Definition of SWLIBS_2Syst as alias for SWLIBS_2Syst_FLT array in case the single precision floating point implementation is selected. */
    #define SWLIBS_3Syst    SWLIBS_3Syst_FLT                        /**< Definition of SWLIBS_3Syst as alias for SWLIBS_3Syst_FLT array in case the single precision floating point implementation is selected. */
    #define SWLIBS_6Syst    SWLIBS_6Syst_FLT                        /**< Definition of SWLIBS_6Syst as alias for SWLIBS_3Syst_FLT array in case the single precision floating point implementation is selected. */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */


#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
/************************************************************************//**
@struct SWLIBS_6Syst_F32 "\SWLIBS_Typedefs.h"

@brief  Array of six standard 32-bit fractional arguments.
*//*************************************************************************/
  typedef struct
  {
    tFrac32 f32Arg1;   /**< First argument */
    tFrac32 f32Arg2;   /**< Second argument */
    tFrac32 f32Arg3;   /**< Third argument */
    tFrac32 f32Arg4;   /**< Fourth argument */
    tFrac32 f32Arg5;   /**< Fifth argument */
    tFrac32 f32Arg6;   /**< Sixth argument */
  } SWLIBS_6Syst_F32;
  
/************************************************************************//**
@struct SWLIBS_3Syst_F32 "\SWLIBS_Typedefs.h"

@brief  Array of three standard 32-bit fractional arguments.
*//*************************************************************************/
  typedef struct
  {
    tFrac32 f32Arg1;   /**< First argument */
    tFrac32 f32Arg2;   /**< Second argument */
    tFrac32 f32Arg3;   /**< Third argument */
  } SWLIBS_3Syst_F32;

/************************************************************************//**
@struct SWLIBS_2Syst_F32 "\SWLIBS_Typedefs.h"

@brief  Array of two standard 32-bit fractional arguments.
*//*************************************************************************/
  typedef struct
  {
    tFrac32 f32Arg1;   /**< First argument */
    tFrac32 f32Arg2;   /**< Second argument */
  } SWLIBS_2Syst_F32;
  
/************************************************************************//**
@struct SWLIBS_2Syst_U32 "\SWLIBS_Typedefs.h"

@brief  Array of two unsigned 32-bit integer arguments.
*//*************************************************************************/
  typedef struct
  {
    tU32 u32Arg1;   /**< First argument */
    tU32 u32Arg2;   /**< Second argument */
  } SWLIBS_2Syst_U32;
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */


#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
/************************************************************************//**
@struct SWLIBS_6Syst_F16 "\SWLIBS_Typedefs.h"

@brief  Array of six standard 16-bit fractional arguments.
*//*************************************************************************/
  typedef struct
  {
    tFrac16 f16Arg1;   /**< First argument */
    tFrac16 f16Arg2;   /**< Second argument */
    tFrac16 f16Arg3;   /**< Third argument */
    tFrac16 f16Arg4;   /**< Fourth argument */
    tFrac16 f16Arg5;   /**< Fifth argument */
    tFrac16 f16Arg6;   /**< Sixth argument */
  } SWLIBS_6Syst_F16;
  
/************************************************************************//**
@struct SWLIBS_3Syst_F16 "\SWLIBS_Typedefs.h"

@brief  Array of three standard 16-bit fractional arguments.
*//*************************************************************************/
  typedef struct
  {
    tFrac16 f16Arg1;   /**< First argument */
    tFrac16 f16Arg2;   /**< Second argument */
    tFrac16 f16Arg3;   /**< Third argument */
  } SWLIBS_3Syst_F16;

/************************************************************************//**
@struct SWLIBS_2Syst_F16 "\SWLIBS_Typedefs.h"

@brief  Array of two standard 16-bit fractional arguments.
*//*************************************************************************/
  typedef struct
  {
    tFrac16 f16Arg1;   /**< First argument */
    tFrac16 f16Arg2;   /**< Second argument */
  } SWLIBS_2Syst_F16;
  
/************************************************************************//**
@struct SWLIBS_2Syst_U16 "\SWLIBS_Typedefs.h"

@brief  Array of two unsigned 16-bit integer arguments.
*//*************************************************************************/
  typedef struct
  {
    tU16 u16Arg1;   /**< First argument */
    tU16 u16Arg2;   /**< Second argument */
  } SWLIBS_2Syst_U16;

/************************************************************************//**
@struct SWLIBS_3Syst_U16 "\SWLIBS_Typedefs.h"

@brief  Array of three unsigned 16-bit integer arguments.
*//*************************************************************************/
  typedef struct
  {
    tU16 u16Arg1;   /**< First argument */
    tU16 u16Arg2;   /**< Second argument */
    tU16 u16Arg3;   /**< Third argument */
  } SWLIBS_3Syst_U16;
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */


#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/************************************************************************//**
@struct SWLIBS_6Syst_FLT "\SWLIBS_Typedefs.h"

@brief  Array of three standard single precision floating point arguments.
*//*************************************************************************/
  typedef struct
  {
    tFloat fltArg1;   /**< First argument */
    tFloat fltArg2;   /**< Second argument */
    tFloat fltArg3;   /**< Third argument */
    tFloat fltArg4;   /**< Fourth argument */
    tFloat fltArg5;   /**< Fifth argument */
    tFloat fltArg6;   /**< Sixth argument */
  } SWLIBS_6Syst_FLT;
  
/************************************************************************//**
@struct SWLIBS_3Syst_FLT "\SWLIBS_Typedefs.h"

@brief  Array of three standard single precision floating point arguments.
*//*************************************************************************/
  typedef struct
  {
    tFloat fltArg1;   /**< First argument */
    tFloat fltArg2;   /**< Second argument */
    tFloat fltArg3;   /**< Third argument */
  } SWLIBS_3Syst_FLT;

/************************************************************************//**
@struct SWLIBS_2Syst_FLT "\SWLIBS_Typedefs.h"

@brief  Array of two standard single precision floating point arguments.
*//*************************************************************************/
  typedef struct
  {
    tFloat fltArg1;   /**< First argument */
    tFloat fltArg2;   /**< Second argument */
  } SWLIBS_2Syst_FLT;

/************************************************************************//**
@struct SWLIBS_Complex_FLT "\SWLIBS_Typedefs.h"

@brief  Two single precision floating point numbers representing the real and
        imaginary part of a complex number. The format is compatible with
        C99 complex type that some compilers define in complex.h.
*//*************************************************************************/
  typedef struct
  {
    tFloat Re;   /**< Real part */
    tFloat Im;   /**< Imaginary part */
  } SWLIBS_Complex_FLT;
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */


#endif /* SWLIBS_TYPEDEFS_H */
