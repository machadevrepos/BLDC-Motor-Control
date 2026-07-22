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
* @file       GFLIB_Atan.h
*
* @brief      Header file for GFLIB_Atan function
*
******************************************************************************/
#ifndef GFLIB_ATAN_H
#define GFLIB_ATAN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define GFLIB_Atan(...)     macro_dispatcher(GFLIB_Atan, __VA_ARGS__)(__VA_ARGS__)     /* This function implements polynomial approximation of arctangent function. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define GFLIB_ATAN_T                        GFLIB_ATAN_T_F32                            /**< Definition of GFLIB_ATAN_T as alias for GFLIB_ATAN_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    #define GFLIB_ATAN_DEFAULT                  GFLIB_ATAN_DEFAULT_F32                      /**< Definition of GFLIB_ATAN_DEFAULT as alias for GFLIB_ATAN_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    #define GFLIB_Atan_Dsptchr_2(In,pParam)     GFLIB_Atan_Dsptchr_3(In,pParam,F32)         /* Function dispatcher for GFLIB_Atan_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGFLIB00074 */
    #define GFLIB_Atan_Dsptchr_1(In)            GFLIB_Atan_Dsptchr_2(In,GFLIB_ATAN_DEFAULT) /* Function dispatcher for GFLIB_Atan_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define GFLIB_ATAN_T                        GFLIB_ATAN_T_F16                            /**< Definition of GFLIB_ATAN_T as alias for GFLIB_ATAN_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    #define GFLIB_ATAN_DEFAULT                  GFLIB_ATAN_DEFAULT_F16                      /**< Definition of GFLIB_ATAN_DEFAULT as alias for GFLIB_ATAN_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    #define GFLIB_Atan_Dsptchr_2(In,pParam)     GFLIB_Atan_Dsptchr_3(In,pParam,F16)         /* Function dispatcher for GFLIB_Atan_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGFLIB00074 */
    #define GFLIB_Atan_Dsptchr_1(In)            GFLIB_Atan_Dsptchr_2(In,GFLIB_ATAN_DEFAULT) /* Function dispatcher for GFLIB_Atan_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GFLIB_ATAN_T                        GFLIB_ATAN_T_FLT                            /**< Definition of GFLIB_ATAN_T as alias for GFLIB_ATAN_T_FLT datatype in case the Single precision floating point implementation is selected. */
    #define GFLIB_ATAN_DEFAULT                  GFLIB_ATAN_DEFAULT_FLT                      /**< Definition of GFLIB_ATAN_DEFAULT as alias for GFLIB_ATAN_DEFAULT_FLT default value in case the Single precision floating point implementation is selected. */
    #define GFLIB_Atan_Dsptchr_2(In,pParam)     GFLIB_Atan_Dsptchr_3(In,pParam,FLT)         /* Function dispatcher for GFLIB_Atan_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGFLIB00074 */
    #define GFLIB_Atan_Dsptchr_1(In)            GFLIB_Atan_Dsptchr_2(In,GFLIB_ATAN_DEFAULT) /* Function dispatcher for GFLIB_Atan_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */

  #define GFLIB_Atan_Dsptchr_3(In,pParam,Impl)    GFLIB_Atan_Dsptchr_(In,pParam,Impl)     /* Function dispatcher for GFLIB_Atan_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DGFLIB00076 */
  #define GFLIB_Atan_Dsptchr_(In,pParam,Impl)     GFLIB_Atan_##Impl(In,pParam)            /* Function dispatcher for GFLIB_Atan_Dsptchr_, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define GFLIB_ATAN_DEFAULT_F32 &f32gflibAtanCoef     /**< Default approximation coefficients for GFLIB_Atan_F32 function. */

  /************************************************************************/
  /**
  @struct GFLIB_ATAN_TAYLOR_COEF_T_F32 "\GFLIB_Atan.h"

  @brief  Array of minimax polynomial approximation coefficients for one sub-interval.

  @details  Output of arctan(f32In) for interval [0, 1) of the input ratio is divided
            into eight sub-sectors. Minimax polynomial approximation is done using a 3rd order polynomial, for each sub-sector
            respectively. Three coefficients for a single sub-interval are stored in this (#GFLIB_ATAN_TAYLOR_COEF_T_F32)
            structure.
  *//**********************************************************************/
  typedef struct{
    const tFrac32  f32A[3];
  }GFLIB_ATAN_TAYLOR_COEF_T_F32;
  
  /************************************************************************/
  /**
  @struct GFLIB_ATAN_T_F32 "\GFLIB_Atan.h"

  @brief    Structure containing eight sub-structures with polynomial coefficients to cover all sub-intervals.

  @details  Output of arctan(f32In) for interval [0, 1) of the input ratio is divided
            into eight sub-sectors. Polynomial approximation is done using a 3rd order polynomial, for each sub-sector
            respectively. Eight arrays, each including three polynomial coefficients for each sub-interval, are stored
            in this (#GFLIB_ATAN_T_F32) structure.
  *//**********************************************************************/
  typedef struct{
    const GFLIB_ATAN_TAYLOR_COEF_T_F32  GFLIB_ATAN_SECTOR[8];
  }GFLIB_ATAN_T_F32;

  /************************************************************************/
  /**
  @brief  Default approximation coefficients for arctangent approximation.
  *//**********************************************************************/

  extern const GFLIB_ATAN_T_F32 f32gflibAtanCoef;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac32 GFLIB_Atan_F32(tFrac32 f32In, const GFLIB_ATAN_T_F32 *const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  #define GFLIB_ATAN_DEFAULT_F16 &f16gflibAtanCoef     /**< Default approximation coefficients for GFLIB_Atan_F16 function. */

  /************************************************************************/
  /**
  @struct GFLIB_ATAN_TAYLOR_COEF_T_F16 "\GFLIB_Atan.h"

  @brief  Array of polynomial approximation coefficients for one sub-interval.

  @details  Output of arctan(f16In) for interval [0, 1) of the input ratio is divided
            into eight sub-sectors. Polynomial approximation is done using a 3rd order polynomial, for each sub-sector
            respectively. Three coefficients for a single sub-interval are stored in this (#GFLIB_ATAN_TAYLOR_COEF_T_F16)
            structure.
  *//**********************************************************************/
  typedef struct{
    const tFrac16  f16A[3];
  }GFLIB_ATAN_TAYLOR_COEF_T_F16;

  /************************************************************************/
  /**
  @struct GFLIB_ATAN_T_F16 "\GFLIB_Atan.h"

  @brief    Structure containing eight sub-structures with polynomial coefficients to cover all sub-intervals.

  @details  Output of arctan(f16In) for interval [0, 1) of the input ratio is divided
            into eight sub-sectors. Polynomial approximation is done using a 3rd order polynomial, for each sub-sector
            respectively. Eight arrays, each including three polynomial coefficients for each sub-interval, are stored
            in this (#GFLIB_ATAN_T_F16) structure.
  *//**********************************************************************/
  typedef struct{
    const GFLIB_ATAN_TAYLOR_COEF_T_F16  GFLIB_ATAN_SECTOR[8];
  }GFLIB_ATAN_T_F16;

  /************************************************************************/
  /**
  @brief  Default approximation coefficients for arctangent approximation.
  *//**********************************************************************/

  extern const GFLIB_ATAN_T_F16 f16gflibAtanCoef;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFrac16 GFLIB_Atan_F16(tFrac16 f16In, const GFLIB_ATAN_T_F16 *const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GFLIB_ATAN_DEFAULT_FLT &fltgflibAtanCoef     /**< Default approximation coefficients for GFLIB_Atan_FLT function. */

  /************************************************************************/
  /**
  @struct GFLIB_ATAN_T_FLT "\GFLIB_Atan.h"
   
  @brief    Structure containing the approximation coefficients.

  @details  The approximation uses the rational polynomial approximation which is based on the division of two rational
            polynomials. The essential assumption of this approach is the fast calculation of a two floating point values
            division. The approximation polynomial coefficients assume the input argument in the interval
            (-\f$2^{128}\f$, \f$2^{128}\f$).
  *//**********************************************************************/
  typedef struct{
    const tFloat  fltA[6];
  }GFLIB_ATAN_T_FLT;
  
  /************************************************************************/
  /**
  @brief  Default approximation coefficients for arctangent approximation.
  *//**********************************************************************/

  extern const GFLIB_ATAN_T_FLT fltgflibAtanCoef;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern tFloat GFLIB_Atan_FLT(tFloat fltIn, const GFLIB_ATAN_T_FLT *const pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_ATAN_H */
