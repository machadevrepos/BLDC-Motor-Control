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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Aec_Ip_Types.h"
#include "Aec_Ip_Cfg.h"

#include "Lpspi_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_SA_PBCFG_VENDOR_ID_C                     43
#define AEC_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define AEC_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C      9
#define AEC_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define AEC_IP_SA_PBCFG_SW_MAJOR_VERSION_C              7
#define AEC_IP_SA_PBCFG_SW_MINOR_VERSION_C              0
#define AEC_IP_SA_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip_Types.h */
#if (AEC_IP_SA_PBCFG_VENDOR_ID_C != AEC_IP_TYPES_VENDOR_ID)
    #error "Aec_Ip_Sa_PBcfg.c and Aec_Ip_Types.h have different vendor ids"
#endif
#if ((AEC_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION_C != AEC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Sa_PBcfg.c and Aec_Ip_Types.h are different"
#endif
#if ((AEC_IP_SA_PBCFG_SW_MAJOR_VERSION_C != AEC_IP_TYPES_SW_MAJOR_VERSION) || \
     (AEC_IP_SA_PBCFG_SW_MINOR_VERSION_C != AEC_IP_TYPES_SW_MINOR_VERSION) || \
     (AEC_IP_SA_PBCFG_SW_PATCH_VERSION_C != AEC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aec_Ip_Sa_PBcfg.c and Aec_Ip_Types.h are different"
#endif

/* Checks against Aec_Ip_Cfg.h */
#if (AEC_IP_SA_PBCFG_VENDOR_ID_C != AEC_IP_CFG_VENDOR_ID)
    #error "Aec_Ip_Sa_PBcfg.c and Aec_Ip_Cfg.h have different vendor ids"
#endif
#if ((AEC_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION_C != AEC_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Sa_PBcfg.c and Aec_Ip_Cfg.h are different"
#endif
#if ((AEC_IP_SA_PBCFG_SW_MAJOR_VERSION_C != AEC_IP_CFG_SW_MAJOR_VERSION) || \
     (AEC_IP_SA_PBCFG_SW_MINOR_VERSION_C != AEC_IP_CFG_SW_MINOR_VERSION) || \
     (AEC_IP_SA_PBCFG_SW_PATCH_VERSION_C != AEC_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aec_Ip_Sa_PBcfg.c and Aec_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((AEC_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != LPSPI_IP_AR_RELEASE_MAJOR_VERSION) || \
        (AEC_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C     != LPSPI_IP_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip_Sa_PBcfg.c and Lpspi_Ip.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

static const Aec_Ip_SpiConfigType AecConfigSpi =
{
    /*.SpiSync = */(boolean)TRUE,
    /*.SpiTimeout = */(uint32)50000U,
    /*.SpiDevice = */&Lpspi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_1
};


#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

const Aec_Ip_ConfigType Aec_Ip_aConfigPB =
{
    /*.SpidConfig = */&AecConfigSpi
};


#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

