/*==================================================================================================
*   Project              : RTD AUTOSAR 4.9
*   Platform             : CORTEXM
*   Peripheral           : DPGA
*   Dependencies         : none
*
*   Autosar Version      : 4.9.0
*   Autosar Revision     : ASR_REL_4_9_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 7.0.0
*   Build Version        : S32K3_RTD_7_0_0_QLP03_D2512_ASR_REL_4_9_REV_0000_20251210
*
*   Copyright 2020 - 2025 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms. By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms. If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/


#ifndef DPGA_IP_CFGDEFINES_H
#define DPGA_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup dpga_ip_config Dpga IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "OsIf.h"
#include "S32M27x_DPGA_AE.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_IP_VENDOR_ID_CFGDEFINES                    43
#define DPGA_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     4
#define DPGA_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES     9
#define DPGA_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES  0
#define DPGA_IP_SW_MAJOR_VERSION_CFGDEFINES             7
#define DPGA_IP_SW_MINOR_VERSION_CFGDEFINES             0
#define DPGA_IP_SW_PATCH_VERSION_CFGDEFINES             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Std_Types header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     != STD_AR_RELEASE_MAJOR_VERSION) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES     != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Dpga_Ip_CfgDefines.h and Std_Types.h are different"
#endif

/* Check if current file and OsIf header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES     != OSIF_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Dpga_Ip_CfgDefines.h and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define DPGA_IP_DEV_ERROR_DETECT                (STD_OFF)
#define DPGA_IP_TIMEOUT_TYPE                    (OSIF_COUNTER_DUMMY)
#define DPGA_IP_TIMEOUT_VALUE                   (65535U)
#define DPGA_IP_VOLTAGE_MONITOR_SELF_TEST_API   (STD_OFF)
#define DPGA_IP_AMPLIFIER_SELF_TEST_API         (STD_OFF)
/**
* @brief  If Voltage Monitoring is enbaled, this define is (STD_ON). Otherwise, this define is (STD_OFF).
*/
#define DPGA_IP_ENABLE_VOLTAGE_MONITORING       (STD_ON)

/**
* @brief  Maximum number of Blanking Time triggers.
*/
#define DPGA_IP_BT_NUM_OF_TRIGGERS              (6U)

#if (STD_ON == DPGA_IP_AMPLIFIER_SELF_TEST_API)

/**
* @brief  Selects standard input ADC for conversion.
*/
#define DPGA_IP_SELFTEST_ADC_CMR_MASK           {0U,1U,0U}
/**
* @brief  ADC instance.
*/
#define DPGA_IP_SELFTEST_ADC_INSTANCE_USED      (1U)

/**
* @brief  ADC channel.
*/
#define DPGA_IP_SELFTEST_ADC_CHANNEL_USED       (32U)

/**
* @brief  The tolerance to check the result of ADC measurement.
*/
#define DPGA_IP_AMPLIFIER_SELFTEST_TOLERANCE    (100U)

/**
* @brief  The max value of Adc with selected resolution.
*/
#define DPGA_IP_SELFTEST_ADC_MAX_VALUE          (16383U)

/**
* @brief  The gain array.
*/
#define DPGA_IP_GAIN_ARRAY                      {8U,16U,24U,32U,40U,50U,65U,80U}

/**
* @brief  The offset array.
*/
#define DPGA_IP_OFFSET_ARRAY                    {0U,3U,6U,9U,12U,15U,18U,21U,0U,3U,6U,9U,12U,15U,18U,21U}

/**
* @brief  Dpga max reference voltage in mV.
*/
#define DPGA_IP_MAX_REFERENCE_VOLTAGE           (3300U)

#endif /*STD_ON == DPGA_IP_AMPLIFIER_SELF_TEST_API*/


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DPGA_IP_CFGDEFINES_H */

