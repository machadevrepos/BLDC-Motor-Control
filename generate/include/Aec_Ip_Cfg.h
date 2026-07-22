/*==================================================================================================
*   Project              : RTD AUTOSAR 4.9
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef AEC_IP_CFG_H
#define AEC_IP_CFG_H

/**
*   @file
*
*   @addtogroup AEC_DRIVER_CONFIGURATION AEC Driver Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Aec_Ip_Sa_PBcfg.h"

#include "Std_Types.h"
#include "Reg_eSys.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_CFG_VENDOR_ID                    43
#define AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define AEC_IP_CFG_AR_RELEASE_MINOR_VERSION     9
#define AEC_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define AEC_IP_CFG_SW_MAJOR_VERSION             7
#define AEC_IP_CFG_SW_MINOR_VERSION             0
#define AEC_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip_Sa_PBcfg.h */
#if (AEC_IP_CFG_VENDOR_ID != AEC_IP_SA_PBCFG_VENDOR_ID)
    #error "Aec_Ip_Cfg.h and Aec_Ip_Sa_PBcfg.h have different vendor ids"
#endif
#if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION    != AEC_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION    != AEC_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_REVISION_VERSION != AEC_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.h and Aec_Ip_Sa_PBcfg.h are different"
#endif
#if ((AEC_IP_CFG_SW_MAJOR_VERSION != AEC_IP_SA_PBCFG_SW_MAJOR_VERSION) || \
     (AEC_IP_CFG_SW_MINOR_VERSION != AEC_IP_SA_PBCFG_SW_MINOR_VERSION) || \
     (AEC_IP_CFG_SW_PATCH_VERSION != AEC_IP_SA_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Cfg.h and Aec_Ip_Sa_PBcfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Std_Types.h */
    #if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.h and Std_Types.h are different"
    #endif
    /* Checks against Reg_eSys.h */
    #if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.h and Reg_eSys.h are different"
    #endif
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define AEC_CONFIG_EXT \
    AEC_CONFIG_SA_PB 

#define AEC_IP_DEV_ERROR_DETECT            (STD_OFF)

#define AEC_IP_TIMEOUT_TYPE                (OSIF_COUNTER_DUMMY)

#define AEC_IP_TIMEOUT_VALUE_US            (1000U)

#define AEC_IP_EVENT_FAULT_NUM_MAX         (25U)

#define AEC_IP_GHS_NUM_MAX                 (4U)

#define AEC_IP_GHS_FAULT_HANDLER           (STD_OFF)

#define AEC_IP_EVENT_FAULT_FLAG_CLEAR      (STD_OFF)

#define AEC_IP_ENABLE_USER_MODE_SUPPORT     (STD_OFF)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Forward AEC structure declarations */
struct Aec_Ip_sSpiConfigType;
struct Aec_Ip_sIntRouteConfigType;
struct Aec_Ip_sGHSRouteConfigType;

/**
* @brief          Structure storing the list of routing configurations for all configured interrupts.
* @implements     Aec_Ip_GlobalRouteConfigType_typedef
*/
typedef struct
{
    /** @brief Faults enabled to raise interrupt */
    uint16 AecEnFaults;
    /** @brief Events enabled to raise interrupt */
    uint16 AecEnEvents;
    /** @brief List of interrupts configurations */
    const struct Aec_Ip_sIntRouteConfigType *aIntConfig;
} Aec_Ip_GlobalRouteConfigType;

/**
* @brief   The structure contains the hardware controller configuration type.
* @implements Aec_Ip_ConfigType_structure
*/
typedef struct Aec_Ip_sConfigType
{
    const struct Aec_Ip_sSpiConfigType *AeSpiConfig;
} Aec_Ip_ConfigType;

/**
* @brief          Structure storing the list of routing configurations for all configured interrupts.
*/
typedef struct
{
    /** @brief Faults enabled to raise interrupt */
    uint16 AecGHSFaults;
    /** @brief List of interrupts configurations */
    const struct Aec_Ip_sGHSRouteConfigType *aIntConfig;
} Aec_Ip_GlobalGHSRouteConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

extern const Aec_Ip_GlobalRouteConfigType Aec_intRouteConfig;
extern const Aec_Ip_GlobalGHSRouteConfigType Aec_GHSRouteConfig;

extern void undefined_handler(void);

extern void undefined_handler(void);

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AEC_IP_CFG_H */

