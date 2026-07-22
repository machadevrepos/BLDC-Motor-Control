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

#ifndef DPGA_IP_PBCFG_H
#define DPGA_IP_PBCFG_H

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
#include "Dpga_Ip_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define  DPGA_IP_VENDOR_ID_PBCFG                    43
#define  DPGA_IP_AR_RELEASE_MAJOR_VERSION_PBCFG     4
#define  DPGA_IP_AR_RELEASE_MINOR_VERSION_PBCFG     9
#define  DPGA_IP_AR_RELEASE_REVISION_VERSION_PBCFG  0
#define  DPGA_IP_SW_MAJOR_VERSION_PBCFG             7
#define  DPGA_IP_SW_MINOR_VERSION_PBCFG             0
#define  DPGA_IP_SW_PATCH_VERSION_PBCFG             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Dpga_Ip_Types header file are of the same vendor */
#if (DPGA_IP_VENDOR_ID_PBCFG != DPGA_IP_VENDOR_ID_TYPES)
    #error "Dpga_Ip_PBcfg.h and Dpga_Ip_Types.h have different vendor ids"
#endif

/* Check if current file and Dpga_Ip_Types header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION_PBCFG     != DPGA_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION_PBCFG     != DPGA_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (DPGA_IP_AR_RELEASE_REVISION_VERSION_PBCFG  != DPGA_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Dpga_Ip_PBcfg.h and Dpga_Ip_Types.h are different"
#endif

/* Check if current file and Dpga_Ip_Types header file are of the same software version */
#if ((DPGA_IP_SW_MAJOR_VERSION_PBCFG != DPGA_IP_SW_MAJOR_VERSION_TYPES) || \
     (DPGA_IP_SW_MINOR_VERSION_PBCFG != DPGA_IP_SW_MINOR_VERSION_TYPES) || \
     (DPGA_IP_SW_PATCH_VERSION_PBCFG != DPGA_IP_SW_PATCH_VERSION_TYPES) \
    )
    #error "Software Version Numbers of Dpga_Ip_PBcfg.h and Dpga_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define DPGA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dpga_MemMap.h"

/**
* @brief Dpga Ip Channel 0 Config for configuration variant .
*/
extern const Dpga_Ip_ConfigType Dpga_Ip_Config;

#define DPGA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dpga_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define DPGA_START_SEC_CODE
#include "Dpga_MemMap.h"

/**
* @brief Dpga Callback Function.
*/
extern void Dpga_Callback(Dpga_Ip_EventType Event);

#define DPGA_STOP_SEC_CODE
#include "Dpga_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DPGA_IP_PBCFG_H */

