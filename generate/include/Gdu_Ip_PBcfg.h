/*==================================================================================================
*   Project              : RTD AUTOSAR 4.9
*   Platform             : CORTEXM
*   Peripheral           : IPV_GDU
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
#ifndef GDU_IP_PBCFG_H
#define GDU_IP_PBCFG_H

/**
*   @file    Gdu_Ip_PBcfg.h
*   @version 7.0.0
*
*   @brief   AUTOSAR Gdu - IPV_GDU postbuild configuration header.
*
*   @addtogroup IPV_GDU
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
#include "Gdu_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_IP_PBCFG_VENDOR_ID                     43
#define GDU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define GDU_IP_PBCFG_AR_RELEASE_MINOR_VERSION      9
#define GDU_IP_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define GDU_IP_PBCFG_SW_MAJOR_VERSION              7
#define GDU_IP_PBCFG_SW_MINOR_VERSION              0
#define GDU_IP_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (GDU_IP_PBCFG_VENDOR_ID != GDU_IP_TYPES_VENDOR_ID)
    #error "Gdu_Ip_PBcfg.h and Gdu_Ip_Types.h have different vendor ids"
#endif
#if ((GDU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION    != GDU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_IP_PBCFG_AR_RELEASE_MINOR_VERSION    != GDU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GDU_IP_PBCFG_AR_RELEASE_REVISION_VERSION != GDU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gdu_Ip_PBcfg.h and Gdu_Ip_Types.h are different"
#endif
#if ((GDU_IP_PBCFG_SW_MAJOR_VERSION != GDU_IP_TYPES_SW_MAJOR_VERSION) || \
     (GDU_IP_PBCFG_SW_MINOR_VERSION != GDU_IP_TYPES_SW_MINOR_VERSION) || \
     (GDU_IP_PBCFG_SW_PATCH_VERSION != GDU_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gdu_Ip_PBcfg.h and Gdu_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
#define GDU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gdu_MemMap.h"


#define GDU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gdu_MemMap.h"

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

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* GDU_IP_PBCFG_H */

