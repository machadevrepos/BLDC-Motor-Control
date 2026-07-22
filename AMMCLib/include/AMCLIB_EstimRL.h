/******************************************************************************
*
*   Copyright 2021-2026 NXP
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
* @file       AMCLIB_EstimRL.h
*
* @brief      Header file for AMCLIB_EstimRL function
*
******************************************************************************/
#ifndef AMCLIB_ESTIMRL_H
#define AMCLIB_ESTIMRL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "GDFLIB_FilterMA.h"
#include "GFLIB_ControllerPIpAW.h"
#include "GMCLIB_ElimDcBusRip.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define AMCLIB_EstimRLInit(...)     macro_dispatcher(AMCLIB_EstimRLInit, __VA_ARGS__)(__VA_ARGS__)     /* This function initializes the state of the AMCLIB_EstimRL. */
  #define AMCLIB_EstimRL(...)     macro_dispatcher(AMCLIB_EstimRL, __VA_ARGS__)(__VA_ARGS__)     /* This function calculates the AMCLIB_EstimRL. */
  
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    #define AMCLIB_ESTIMRL_T                                        AMCLIB_ESTIMRL_T_FLT
    #define ESTIMRL_INIT_DEFAULT                                        ESTIMRL_INIT_DEFAULT_FLT
    #define ESTIMRL_INIT_CFG1                                        ESTIMRL_INIT_CFG1_FLT
    #define ESTIMRL_INIT_CFG2                                        ESTIMRL_INIT_CFG2_FLT
    #define ESTIMRL_INIT_CFG3                                        ESTIMRL_INIT_CFG3_FLT
    #define ESTIMRL_RUN_DEFAULT                                        ESTIMRL_RUN_DEFAULT_FLT
    #define ESTIMRL_RUN_CFG1                                        ESTIMRL_RUN_CFG1_FLT
    #define ESTIMRL_RUN_CFG2                                        ESTIMRL_RUN_CFG2_FLT
    #define ESTIMRL_RUN_CFG3                                        ESTIMRL_RUN_CFG3_FLT
    /* @remarks Implements DAMCLIB00171 */
    #define AMCLIB_EstimRLInit_Dsptchr_7(SamplingFreq,pCtrl,IDcMax,LdqNumMeas,IDcLd,IDcLq,IDcNegMax)     AMCLIB_EstimRLInit_Dsptchr_8(SamplingFreq,pCtrl,IDcMax,LdqNumMeas,IDcLd,IDcLq,IDcNegMax,FLT)     /* Function dispatcher for AMCLIB_EstimRLInit_Dsptchr_7, do not modify!!! */
    /* @remarks Implements DAMCLIB00171 */
    #define AMCLIB_EstimRL_Dsptchr_10(pUAlBeReq,pIAlBeFbck,UDcBus,pCtrl,pLdqTable,IDcDReq,IDcQReq,IAcReq,FAc,LdqSwitch)     AMCLIB_EstimRL_Dsptchr_11(pUAlBeReq,pIAlBeFbck,UDcBus,pCtrl,pLdqTable,IDcDReq,IDcQReq,IAcReq,FAc,LdqSwitch,FLT)     /* Function dispatcher for AMCLIB_EstimRL_Dsptchr_10, do not modify!!! */
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT */
  
  #define AMCLIB_EstimRLInit_Dsptchr_8(SamplingFreq,pCtrl,IDcMax,LdqNumMeas,IDcLd,IDcLq,IDcNegMax,Impl)    AMCLIB_EstimRLInit_Dsptchr_(SamplingFreq,pCtrl,IDcMax,LdqNumMeas,IDcLd,IDcLq,IDcNegMax,Impl)     /* Function dispatcher for AMCLIB_EstimRLInit_Dsptchr_8, do not modify!!! */
  /* @remarks Implements DAMCLIB00173 */
  #define AMCLIB_EstimRLInit_Dsptchr_(SamplingFreq,pCtrl,IDcMax,LdqNumMeas,IDcLd,IDcLq,IDcNegMax,Impl)     AMCLIB_EstimRLInit_##Impl(SamplingFreq,pCtrl,IDcMax,LdqNumMeas,IDcLd,IDcLq,IDcNegMax)            /* Function dispatcher for AMCLIB_EstimRLInit_Dsptchr_, do not modify!!! */
  
  #define AMCLIB_EstimRL_Dsptchr_11(pUAlBeReq,pIAlBeFbck,UDcBus,pCtrl,pLdqTable,IDcDReq,IDcQReq,IAcReq,FAc,LdqSwitch,Impl)    AMCLIB_EstimRL_Dsptchr_(pUAlBeReq,pIAlBeFbck,UDcBus,pCtrl,pLdqTable,IDcDReq,IDcQReq,IAcReq,FAc,LdqSwitch,Impl)     /* Function dispatcher for AMCLIB_EstimRL_Dsptchr_11, do not modify!!! */
  /* @remarks Implements DAMCLIB00173 */
  #define AMCLIB_EstimRL_Dsptchr_(pUAlBeReq,pIAlBeFbck,UDcBus,pCtrl,pLdqTable,IDcDReq,IDcQReq,IAcReq,FAc,LdqSwitch,Impl)     AMCLIB_EstimRL_##Impl(pUAlBeReq,pIAlBeFbck,UDcBus,pCtrl,pLdqTable,IDcDReq,IDcQReq,IAcReq,FAc,LdqSwitch)            /* Function dispatcher for AMCLIB_EstimRL_Dsptchr_, do not modify!!! */
#endif /* !(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/
/************************************************************************//**
@enum   AMCLIB_ESTIMRLINIT_RET_T

@brief  Enum type of the AMCLIB_EstimRLInit return value.
*//*************************************************************************/
typedef enum
{
  RET_INIT_OK = 0,  /**< Initialization successful. */
  RET_INIT_ERROR = 1,  /**< Invalid inputs. */
  /* Compiler_Warning: False positive. */
} AMCLIB_ESTIMRLINIT_RET_T;

/************************************************************************//**
@enum   AMCLIB_ESTIMRL_RET_T

@brief  Enum type of the AMCLIB_EstimRL return value.
*//*************************************************************************/
typedef enum
{
  RET_IN_PROGRESS = 0,  /**< Parameter estimation is in progress. The AMCLIB_EstimRL must be called again in the next sampling period. */
  RET_DONE = 1,  /**< Parameter estimation has finished. */
  RET_ERROR = 2,  /**< Parameter estimation has failed. */
  /* Compiler_Warning: False positive. */
} AMCLIB_ESTIMRL_RET_T;

/************************************************************************//**
@enum   AMCLIB_ESTIMRL_STATE_T

@brief  Enum type of the AMCLIB_EstimRL internal state.
*//*************************************************************************/
typedef enum
{
  STATE_UNINITIALIZED = 0, /**< RL estimator is not initialized. */
  STATE_MEAS_LD, /**< Measurement of d-axis inductance. */
  STATE_MEAS_LQ, /**< Measurement of q-axis inductance. */
  STATE_LD_TO_LQ, /**< Transition between axes. */
  STATE_POSTPROCESS_LD, /**< Postprocessing of accumulated values for d-axis measurement. */
  STATE_POSTPROCESS_LQ, /**< Postprocessing of accumulated values for q-axis measurement. */
  STATE_UNWIND, /**< Gradual turn-off of the DC current at the end of measurement. */
  STATE_DONE, /**< Measurement finished. */
  STATE_ERROR, /**< Failure. */
  /* Compiler_Warning: False positive. */
} AMCLIB_ESTIMRL_STATE_T;

/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  /************************************************************************/
  /**
  @struct AMCLIB_ESTIMRL_INNERST_T_FLT "\AMCLIB_EstimRL.h"

  @brief  Internal state of the RL estimator. No user-editable values.
  *//**********************************************************************/
  typedef struct
  {
    AMCLIB_ESTIMRL_STATE_T pState;  /**< RL estimator state */
    tFrac32 f32FAc;       /**< Normalized fraction of the AC current frequency to be integrated in each iteration */
    tFloat fltIDcMax;     /**< Maximum DC of current */
    tFloat fltIDcNegMax;  /**< Maximum allowed negative DC current */
    tFloat fltIDcMaxInv;  /**< Inverse of the maximum DC current */
    tFloat fltIAcReq;     /**< Amplitude of the required AC current */
    tFloat fltIAcReqInv;  /**< Inverse of the amplitude of the required AC current */
    tFloat fltIDcDReq;    /**< Required DC current in D axis */
    tFloat fltIDcDReqk_1; /**< Required DC current in previous step in D axis */
    tFloat fltIDcQReq;    /**< Required DC current in Q axis */
    tFloat fltIDcQReqk_1; /**< Required DC current in previous step in Q axis */
    tFloat fltIDcReqStep; /**< Measurement step of the required DC current */
    tFloat fltIAlBeEstErr;       /**< Current estimation error */
    SWLIBS_2Syst_FLT pIAlBeAc;   /**< Alpha/beta components of the estimated AC current */
    SWLIBS_2Syst_FLT pSinCosEst; /**< Sine/Cosine of the estimated current phase */
    SWLIBS_2Syst_FLT pIDQAcRaw;  /**< d/q components of the estimated AC current */
    SWLIBS_2Syst_FLT pIDQAcFilt; /**< Filtered d/q components of the estimated AC current */
    GDFLIB_FILTER_MA_T_FLT pDAxisFilter;  /**< Parameters structure of the MA filter in the d axis in the PLL */
    GDFLIB_FILTER_MA_T_FLT pQAxisFilter;  /**< Parameters structure of pDcFilter in the PLL */
    GDFLIB_FILTER_MA_T_FLT pDcFilter;     /**< Parameters structure of the MA filter filtering the DC current in PLL */
    GDFLIB_FILTER_MA_T_FLT pStdFilter;    /**< Parameters structure of the MA filter filtering the standard deviation of current noise */
    tFloat fltPLLPropGain;  /**< Gain of the P controller in the PLL */
    tFrac32 f32ThAc;        /**< High-frequency AC voltage phase; <-PI, PI) range normalized into <-1, 1) */
    tFrac32 f32ThEst;       /**< Estimated AC current phase; <-PI, PI) range normalized into <-1, 1) */
    tFloat fltIDcD;         /**< Estimated DC current in D axis */
    tFloat fltIDcQ;         /**< Estimated DC current in Q axis */
    tFloat fltIDcDAvg;      /**< Averaging accumulator for the estimated DC current in D axis */
    tFloat fltIDcDAvgk_1;   /**< Averaged estimated DC current in D axis in the last step */
    tFloat fltPhComp;       /**< Compensation of phase error due to sampling lag */
    tS32 s32ConvDetState;   /**< Convergence detector state */
    tS32 s32ConvDetStateLimL;  /**< Convergence detector lower limit */
    tS32 s32ConvDetStateLimH;  /**< Convergence detector coarse/fine tracking threshold */
    tU32 u32ConvDetToutCnt;    /**< Convergence detector timeout counter */
    tU32 u32ConvDetToutReload; /**< Convergence detector counter reload value */
    tU32 u32AvgCnt;            /**< Noise averaging counter */
    tU32 u32AvgN;              /**< Noise averaging window length */
    tFloat fltAvgNInv;         /**< Reciprocal of the noise averaging inverse window length */
    tFloat fltAvgNInvMaxDelta; /**< Difference of reciprocals of the noise averaging inverse window length (max/nominal) */
    tU32 u32AvgCntMax;         /**< Maximum length of the noise averaging window */
    tFloat fltPhAvg;           /**< Averaging accumulator for phase shift */
    tFloat fltIAcAvg;          /**< Averaging accumulator for AC current */
    tFloat fltUAcAvg;          /**< Averaging accumulator for AC voltage */
    tFloat fltAvgMul;          /**< Averaging window length multiplier */
    tFloat fltAvgMin;          /**< Averaging window minimum length */
    tU16 u16LdqNumMeas;        /**< Number of Ld/Lq table measurements */
    tU32 u32TblCounter;        /**< Ld/Lq table counter */
    tU8 u8RotorFixed;          /**< 0 == rotor is not mechanically fixed, 1 == rotor is mechanically fixed */
    tFloat fltIDcRampCoef;     /**< DC current ramp coefficient */
    tFloat fltIDcRampCoefMax;  /**< Maximum DC current ramp coefficient */
    tFloat fltIDcDRampAcc;     /**< DC current ramp accumulator in D axis */
    tFloat fltIDcQRampAcc;     /**< DC current ramp accumulator in Q axis */
    tFloat fltUDcDAcc;         /**< DC voltage integrator in D axis */
    tFloat fltUDcDAccAvg;      /**< Averaging accumulator for DC voltage in D axis */
    tFloat fltUDcDAccAvgk_1;   /**< Averaged DC voltage in D axis in previous step */
    tFloat fltUDcQAcc;         /**< DC voltage integrator in Q axis */
    tFloat fltUAcAcc;          /**< AC voltage integrator  */
    tFloat fltUDcKi;           /**< DC voltage integrator gain */
    tFloat fltUAcKi;           /**< AC voltage integrator gain */
    tFloat fltUDcKiNominal;    /**< Nominal DC voltage integrator gain */
    tFloat fltUAcKiNominal;    /**< Nominal AC voltage integrator gain */
    tU16 u16RampSteady;        /**< Indicator of the steady state of the voltage controller ramp */
    tU16 u16DcbLimitFlag;      /**< DC bus voltage limitation indicator */
    tU16 u16DcbLimitFlagk_1;   /**< DC bus voltage limitation indicator in previous step */
    tU16 u16DcbLimitCnt;       /**< DC bus voltage limitation counter */
    tFloat fltPhaseShift;      /**< Voltage/current phase shift */
    tFloat fltUdcHalf;         /**< Minimum DC bus voltage, halved and divided by modulation index */
    tFloat fltFsInv;           /**< Inverse of the sampling frequency */
    tFloat fltImpConst;        /**< Constant used for calculation of impedance */
    tFloat fltLdk_1;           /**< Estimated d-axis inductance in previous step */
    tFloat fltLqk_1;           /**< Estimated q-axis inductance in previous step */
    tFloat fltIDcLd;           /**< DC current level to use for measurement of scalar Ld */
    tFloat fltIDcLq;           /**< DC current level to use for measurement of scalar Lq */
    tFloat fltUdtAcc;          /**< Dead time voltage drop averaging accumulator */
    tFloat fltRAcc;            /**< Resistance averaging accumulator */
    tU16 u16LdqNumMeasR;       /**< Number of measurements of R */
    tFloat fltUDcBusMax;       /**< Maximum observed DC bus voltage */
  } AMCLIB_ESTIMRL_INNERST_T_FLT;

  /************************************************************************/
  /**
  @struct AMCLIB_ESTIMRL_T_FLT "\AMCLIB_EstimRL.h"

  @brief  Estimator configuration structure.
  *//**********************************************************************/
  typedef struct
  {
    tFloat fltLd;  /**< Estimated d-axis inductance at zero DC current [H]. */
    tFloat fltLq;  /**< Estimated q-axis inductance at maximal DC current [H]. */
    tFloat fltR;  /**< Estimated resistance [Ohm]. */
    tFloat fltUdt;  /**< Estimated dead time voltage drop of the power stage [V]. */
    AMCLIB_ESTIMRL_INNERST_T_FLT pInnerState;  /**< Internal state of the RL estimator. No user-editable values. */
  } AMCLIB_ESTIMRL_T_FLT;

  /************************************************************************/
  /**
  @struct AMCLIB_ESTIMRL_INIT_T_FLT "\AMCLIB_EstimRL.h"

  @brief  Initialization parameters of the RL estimator.
  *//**********************************************************************/
  typedef struct
  {
    tFloat fltIDcMax;  /**< Maximum DC current [A]. */
    tU16 u16LdqNumMeas;  /**< Number of measured d-axis DC current levels. If this parameter is not 1, the function will perform automatic measurement for a range of DC currents. Otherwise, only one measurement will be performed. */
    tFloat fltIDcLd;  /**< DC current used for Ld measurement [A]. */
    tFloat fltIDcLq;  /**< DC current used for Lq measurement [A]. */
    tFloat fltIDcNegMax;  /**< Maximum allowed negative d-axis DC current [A]. Note that too large negative DC current can cause permanent damage to the motor. Setting fltIDcNegMax to a safe value prevents irreversible demagnetization of the PMSM's magnets. The value of fltIDcNegMax must be negative or zero. */
  } AMCLIB_ESTIMRL_INIT_T_FLT;

/* Default configurations for AMCLIB_ESTIMRL_INIT_T_FLT */
/** Default configuration for #AMCLIB_EstimRLInit_FLT. Use this macro to fill the structure pParam in the function API.
 Arguments must adhere to the data types of \ref AMCLIB_ESTIMRL_INIT_T_FLT.
 \param fltINominal Nominal current of the motor [A]. */
#define ESTIMRL_INIT_DEFAULT_FLT(fltINominal)  (AMCLIB_ESTIMRL_INIT_T_FLT){(fltINominal),0u,0.0f,0.0f,0.0f}
/** Custom configuration set 1 for #AMCLIB_EstimRLInit_FLT. Use this macro to fill the structure pParam in the function API.
 Arguments must adhere to the data types of \ref AMCLIB_ESTIMRL_INIT_T_FLT.
 \param fltIDcMax Maximum DC current [A].
 \param u16LdqNumMeas Number of measured DC current levels.
 \param fltIDcLq  DC current [A] for which the q-axis inductance is measured. */
#define ESTIMRL_INIT_CFG1_FLT(fltIDcMax, u16LdqNumMeas, fltIDcLq)  (AMCLIB_ESTIMRL_INIT_T_FLT){(fltIDcMax),(u16LdqNumMeas),0.0f,(fltIDcLq),0.0f}
/** Custom configuration set 2 for #AMCLIB_EstimRLInit_FLT. Use this macro to fill the structure pParam in the function API.
 Arguments must adhere to the data types of \ref AMCLIB_ESTIMRL_INIT_T_FLT.
 \param fltIDcMax Maximum DC current [A].
 \param u16LdqNumMeas Number of measured DC current levels.
 \param fltIDcLd  DC current [A] for which the d-axis inductance is measured.
 \param fltIDcLq  DC current [A] for which the q-axis inductance is measured.
 \param fltIDcNegMax  Maximum negative DC current [A]. */
#define ESTIMRL_INIT_CFG2_FLT(fltIDcMax, u16LdqNumMeas, fltIDcLd, fltIDcLq, fltIDcNegMax)  (AMCLIB_ESTIMRL_INIT_T_FLT){(fltIDcMax),(u16LdqNumMeas),(fltIDcLd),(fltIDcLq),(fltIDcNegMax)}
/** Custom configuration set 3 for #AMCLIB_EstimRLInit_FLT for fully manual measurement. Use this
 macro to fill the structure pParam in the function API. All parameters will be specified in the API
 of the function AMCLIB_EstimRL_FLT during run-time. */
#define ESTIMRL_INIT_CFG3_FLT  (AMCLIB_ESTIMRL_INIT_T_FLT){0.0f,1u,0.0f,0.0f,0.0f}

  /************************************************************************/
  /**
  @struct AMCLIB_ESTIMRL_RUN_T_FLT "\AMCLIB_EstimRL.h"

  @brief  Run-time parameters of the RL estimator.
  *//**********************************************************************/
  typedef struct
  {
    tFloat *pLdqTable;  /**< Pointer to a table with measured values. The table has 3 rows and u16LdqNumMeas columns stored in column-major order. Parameter u16LdqNumMeas of the init function AMCLIB_EstimRLInit_FLT determines the number of used DC current levels. The array pointed to by pLdqTable must provide room for 3*u16LdqNumMeas 32-bit values. The first row of the table contains the DC current levels [A], the second row contains the estimated d-axis inductances, and the third row contains the estimated q-axis inductances. The inductances are calculated in [H]. */
    tFloat fltIDcDReq;  /**< Required DC current in the d-axis [A] */
    tFloat fltIDcQReq;  /**< Required DC current in the q-axis [A] */
    tFloat fltIAcReq;  /**< Amplitude of the required AC current [A] */
    tU16 u16FAc;  /**< AC current frequency [Hz] */
    tU8 u8LdqSwitch;  /**< Switches between Ld (u8LdqSwitch = 0) and Lq (u8LdqSwitch = 1) measurement */
  } AMCLIB_ESTIMRL_RUN_T_FLT;

/* Default configurations for AMCLIB_ESTIMRL_RUN_T_FLT */
/** Default configuration for #AMCLIB_EstimRL_FLT. Use this macro to fill the structure pParam in the function API. */
#define ESTIMRL_RUN_DEFAULT_FLT  (AMCLIB_ESTIMRL_RUN_T_FLT){NULL,0.0f,0.0f,0.0f,0u,0u}
/** Custom configuration set 1 for #AMCLIB_EstimRL_FLT. Use this macro to fill the structure pParam in the function API.
 Arguments must adhere to the data types of \ref AMCLIB_ESTIMRL_RUN_T_FLT.
 \param pLdqTable Pointer to the table of measured inductances. The table has
 3 rows and u16LdqNumMeas columns stored in column-major order. Parameter u16LdqNumMeas of the init
 function AMCLIB_EstimRLInit_FLT determines the number of used DC current levels. The array pointed
 to by pLdqTable must provide room for 3*u16LdqNumMeas 32-bit values. The first row of the table
 contains the DC current levels [A], the second row contains the estimated d-axis inductances, and the
 third row contains the estimated q-axis inductances. The inductances are calculated in [H]. */
#define ESTIMRL_RUN_CFG1_FLT(pLdqTable)  (AMCLIB_ESTIMRL_RUN_T_FLT){(pLdqTable),0.0f,0.0f,0.0f,0u,0u}
/** Custom configuration set 2 for #AMCLIB_EstimRL_FLT. Use this macro to fill the structure pParam in the function API.
 Arguments must adhere to the data types of \ref AMCLIB_ESTIMRL_RUN_T_FLT.
 \param pLdqTable Pointer to the table of measured inductances. The table has
 3 rows and u16LdqNumMeas columns stored in column-major order. Parameter u16LdqNumMeas of the init
 function AMCLIB_EstimRLInit_FLT determines the number of used DC current levels. The array pointed
 to by pLdqTable must provide room for 3*u16LdqNumMeas 32-bit values. The first row of the table
 contains the DC current levels [A], the second row contains the estimated d-axis inductances, and the
 third row contains the estimated q-axis inductances. The inductances are calculated in [H]. */
#define ESTIMRL_RUN_CFG2_FLT(pLdqTable)  (AMCLIB_ESTIMRL_RUN_T_FLT){(pLdqTable),0.0f,0.0f,0.0f,0u,0u}
/**
 Custom configuration set 3 for #AMCLIB_EstimRL_FLT. Use this macro to fill the structure pParam in the function API.
 Arguments must adhere to the data types of \ref AMCLIB_ESTIMRL_RUN_T_FLT.
 \param fltIDcDReq Required DC current in the d-axis [A].
 \param fltIDcQReq Required DC current in the q-axis [A].
 \param fltIAcReq  Required amplitude of the injected high-frequency AC current (default: 10% of IDc) [A].
 \param u16FAc     Required frequency of the injected high-frequency AC current (default: 500) [Hz]. Must not exceed 25% of the sampling frequency.
 \param u8LdqSwitch  Switches between d-axis measurement (0) and q-axis measurement (1). */
#define ESTIMRL_RUN_CFG3_FLT(fltIDcDReq, fltIDcQReq, fltIAcReq, u16FAc, u8LdqSwitch)  (AMCLIB_ESTIMRL_RUN_T_FLT){NULL,(fltIDcDReq),(fltIDcQReq),(fltIAcReq),(u16FAc),(u8LdqSwitch)}
  
/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern AMCLIB_ESTIMRLINIT_RET_T AMCLIB_EstimRLInit_FLT(tU32 u32SamplingFreq,
    AMCLIB_ESTIMRL_T_FLT *const pCtrl, AMCLIB_ESTIMRL_INIT_T_FLT pParam);
  extern AMCLIB_ESTIMRL_RET_T AMCLIB_EstimRL_FLT(SWLIBS_2Syst_FLT *const pUAlBeReq,
    const SWLIBS_2Syst_FLT *const pIAlBeFbck, tFloat fltUDcBus, AMCLIB_ESTIMRL_T_FLT *const pCtrl,
    AMCLIB_ESTIMRL_RUN_T_FLT pParam);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif/* AMCLIB_ESTIMRL_H */
