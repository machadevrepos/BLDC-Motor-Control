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
* @file       GFLIB_Asin.h
*
* @brief      Header file for GFLIB_Asin function
*
******************************************************************************/
#ifndef GFLIB_ASIN_H
#define GFLIB_ASIN_H

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
  #define GFLIB_Asin(...)     macro_dispatcher(GFLIB_Asin, __VA_ARGS__)(__VA_ARGS__)     /* This function implements polynomial approximation of arcsine function. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    #define GFLIB_ASIN_T                        GFLIB_ASIN_T_F32                            /**< Definition of GFLIB_ASIN_T as alias for GFLIB_ASIN_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    #define GFLIB_ASIN_DEFAULT                  GFLIB_ASIN_DEFAULT_F32                      /**< Definition of GFLIB_ASIN_DEFAULT as alias for GFLIB_ASIN_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    #define GFLIB_Asin_Dsptchr_2(In,pParam)     GFLIB_Asin_Dsptchr_3(In,pParam,F32)         /* Function dispatcher for GFLIB_Asin_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGFLIB00048 */
    #define GFLIB_Asin_Dsptchr_1(In)            GFLIB_Asin_Dsptchr_2(In,GFLIB_ASIN_DEFAULT) /* Function dispatcher for GFLIB_Asin_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    #define GFLIB_ASIN_T                        GFLIB_ASIN_T_F16                            /**< Definition of GFLIB_ASIN_T as alias for GFLIB_ASIN_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    #define GFLIB_ASIN_DEFAULT                  GFLIB_ASIN_DEFAULT_F16                      /**< Definition of GFLIB_ASIN_DEFAULT as alias for GFLIB_ASIN_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    #define GFLIB_Asin_Dsptchr_2(In,pParam)     GFLIB_Asin_Dsptchr_3(In,pParam,F16)         /* Function dispatcher for GFLIB_Asin_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGFLIB00048 */
    #define GFLIB_Asin_Dsptchr_1(In)            GFLIB_Asin_Dsptchr_2(In,GFLIB_ASIN_DEFAULT) /* Function dispatcher for GFLIB_Asin_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16 */
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define GFLIB_ASIN_T                        GFLIB_ASIN_T_FLT                            /**< Definition of GFLIB_ASIN_T as alias for GFLIB_ASIN_T_FLT datatype in case the Single precision floating point implementation is selected. */
    #define GFLIB_ASIN_DEFAULT                  GFLIB_ASIN_DEFAULT_FLT                      /**< Definition of GFLIB_ASIN_DEFAULT as alias for GFLIB_ASIN_DEFAULT_FLT default value in case the Single precision floating point implementation is selected. */
    #define GFLIB_Asin_Dsptchr_2(In,pParam)     GFLIB_Asin_Dsptchr_3(In,pParam,FLT)         /* Function dispatcher for GFLIB_Asin_Dsptchr_2, do not modify!!! */
    /* @remarks Implements DGFLIB00048 */
    #define GFLIB_Asin_Dsptchr_1(In)            GFLIB_Asin_Dsptchr_2(In,GFLIB_ASIN_DEFAULT) /* Function dispatcher for GFLIB_Asin_Dsptchr_1, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */

  #define GFLIB_Asin_Dsptchr_3(In,pParam,Impl)    GFLIB_Asin_Dsptchr_(In,pParam,Impl)     /* Function dispatcher for GFLIB_Asin_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DGFLIB00050 */
  #define GFLIB_Asin_Dsptchr_(In,pParam,Impl)     GFLIB_Asin_##Impl(In,pParam)            /* Function dispatcher for GFLIB_Asin_Dsptchr_, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  #define GFLIB_ASIN_DEFAULT_F32 &f32gflibAsinCoef     /**< Default approximation coefficients for GFLIB_Asin_F32 function. */

  /************************************************************************/
  /**
  @struct GFLIB_ASIN_TAYLOR_COEF_T_F32 "\GFLIB_Asin.h"

  @brief  Array of approximation coefficients for piece-wise polynomial.

  @details  Output of arcsin(f32In) for interval [0, 1) of the input ratio is divided
            into three sub-sectors. Polynomial approximation is done using a 5th order polynomial, for each sub-sector
            respectively. Five coefficients for a single sub-interval are stored in this
            (#GFLIB_ASIN_TAYLOR_COEF_T_F32) structure.
  *//**********************************************************************/
  typedef struct{
    const tFrac32  f32A[5];  /**< Array of five 32-bit elements for storing coefficients of the piece-wise polynomial. */
  }GFLIB_ASIN_TAYLOR_COEF_T_F32;

  /************************************************************************/
  /**
  @struct GFLIB_ASIN_T_F32 "\GFLIB_Asin.h"

  @brief  Default approximation coefficients datatype for arcsine approximation.

  @details  Output of arcsin(f32In) for interval [0, 1) of the input ratio is divided
            into three sub-sectors. Polynomial approximation is done using a 5th order polynomial, for each sub-sector
            respectively. Five coefficients for a single sub-interval are stored in #GFLIB_ASIN_TAYLOR_COEF_T_F32 structure.
  *//**********************************************************************/
  typedef struct{
    GFLIB_ASIN_TAYLOR_COEF_T_F32  GFLIB_ASIN_SECTOR[3];
  }GFLIB_ASIN_T_F32;

  /************************************************************************/
  /**
  @brief  Default approximation coefficients for arcsine approximation.
  *//**********************************************************************/

  extern const GFLIB_ASIN_T_F32 f32gflibAsinCoef;

  /****************************************************************************
  * Exported function prototypes
  ****************************************************************************/
  extern tFrac32 GFLIB_Asin_F32(tFrac32 f32In, const GFLIB_ASIN_T_F32 *const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  #define GFLIB_ASIN_DEFAULT_F16 &f16gflibAsinCoef     /**< Default approximation coefficients for GFLIB_Asin_F16 function. */

  /************************************************************************/
  /**
  @struct GFLIB_ASIN_TAYLOR_COEF_T_F16 "\GFLIB_Asin.h"

  @brief  Array of approximation coefficients for piece-wise polynomial.

  @details  Output of arcsin(f16In) for interval [0, 1) of the input ratio is divided
            into two sub-sectors. Polynomial approximation is done using a 5th order polynomial, for each sub-sector
            respectively. Five coefficients for a single sub-interval are stored in this
            (#GFLIB_ASIN_TAYLOR_COEF_T_F16) structure.
  *//**********************************************************************/
  typedef struct{
    const tFrac16  f16A[5];
  }GFLIB_ASIN_TAYLOR_COEF_T_F16;

  /************************************************************************/
  /**
  @struct GFLIB_ASIN_T_F16 "\GFLIB_Asin.h"

  @brief  Default approximation coefficients datatype for arcsine approximation.

  @details  Output of arcsin(f16In) for interval [0, 1) of the input ratio is divided
            into two sub-sectors. Polynomial approximation is done using a 5th order polynomial, for each sub-sector
            respectively. Five coefficients for a single sub-interval are stored in #GFLIB_ASIN_TAYLOR_COEF_T_F16 structure.
  *//**********************************************************************/
  typedef struct{
    GFLIB_ASIN_TAYLOR_COEF_T_F16  GFLIB_ASIN_SECTOR[2];
  }GFLIB_ASIN_T_F16;

  /************************************************************************/
  /**
  @brief  Default approximation coefficients for arcsine approximation.
  *//**********************************************************************/

  extern const GFLIB_ASIN_T_F16 f16gflibAsinCoef;

  /****************************************************************************
  * Exported function prototypes
  ****************************************************************************/
  extern tFrac16 GFLIB_Asin_F16(tFrac16 f16In, const GFLIB_ASIN_T_F16 *const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #define GFLIB_ASIN_DEFAULT_FLT &fltgflibAsinCoef     /**< Default approximation coefficients for GFLIB_Asin_FLT function. */

  /************************************************************************/
  /**
  @struct GFLIB_ASIN_T_FLT "\GFLIB_Asin.h"

  @brief  Default approximation coefficients datatype for arcsine approximation.

  @details  The polynomial approximation is done using the square root function of the input parameter. The essential
            assumption of this approach is a fast H/W based calculation of the square root operation. The approximation
            polynomial coefficients assume an input argument in the [-\f$\Pi\f$, \f$\Pi\f$] interval.
  *//**********************************************************************/
  typedef struct{
    const tFloat  fltA[7];
  }GFLIB_ASIN_T_FLT;

  /************************************************************************/
  /**
  @brief  Default approximation coefficients for arcsine approximation.
  *//**********************************************************************/

  extern const GFLIB_ASIN_T_FLT fltgflibAsinCoef;

  /****************************************************************************
  * Exported function prototypes
  ****************************************************************************/
  extern tFloat GFLIB_Asin_FLT(tFloat fltIn, const GFLIB_ASIN_T_FLT *const pParam);

#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_ASIN_H */
