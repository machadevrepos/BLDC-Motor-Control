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

/**
*   @file    CDD_Gdu_PBcfg.c
*   @version 7.0.0
*
*   @brief   AUTOSAR Gdu - HLD postbuild configuration.
*
*   @addtogroup CDD_GDU
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
#include "Gdu_Ip_PBcfg.h"
#include "CDD_Gdu_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_PBCFG_VENDOR_ID_C                     43
#define GDU_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define GDU_PBCFG_AR_RELEASE_MINOR_VERSION_C      9
#define GDU_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define GDU_PBCFG_SW_MAJOR_VERSION_C              7
#define GDU_PBCFG_SW_MINOR_VERSION_C              0
#define GDU_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (GDU_PBCFG_VENDOR_ID_C != GDU_IP_PBCFG_VENDOR_ID)
    #error "CDD_GDU_PBcfg.c and Gdu_Ip_PBcfg.h have different vendor ids"
#endif
#if ((GDU_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != GDU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_PBCFG_AR_RELEASE_MINOR_VERSION_C    != GDU_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (GDU_PBCFG_AR_RELEASE_REVISION_VERSION_C != GDU_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_GDU_PBcfg.c and Gdu_Ip_PBcfg.h are different"
#endif
#if ((GDU_PBCFG_SW_MAJOR_VERSION_C != GDU_IP_PBCFG_SW_MAJOR_VERSION) || \
     (GDU_PBCFG_SW_MINOR_VERSION_C != GDU_IP_PBCFG_SW_MINOR_VERSION) || \
     (GDU_PBCFG_SW_PATCH_VERSION_C != GDU_IP_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_GDU_PBcfg.c and Gdu_Ip_PBcfg.h are different"
#endif

/* Checks against CDD_Gdu__PBcfg.h */
#if (GDU_PBCFG_VENDOR_ID_C != GDU_PBCFG_VENDOR_ID)
    #error "CDD_Gdu_PBcfg.c and CDD_Gdu_PBcfg.h have different vendor ids"
#endif
#if ((GDU_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != GDU_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_PBCFG_AR_RELEASE_MINOR_VERSION_C    != GDU_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (GDU_PBCFG_AR_RELEASE_REVISION_VERSION_C != GDU_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of CDD_Gdu_PBcfg.c and CDD_Gdu_PBcfg.h are different"
#endif
#if ((GDU_PBCFG_SW_MAJOR_VERSION_C != GDU_PBCFG_SW_MAJOR_VERSION) || \
     (GDU_PBCFG_SW_MINOR_VERSION_C != GDU_PBCFG_SW_MINOR_VERSION) || \
     (GDU_PBCFG_SW_PATCH_VERSION_C != GDU_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Gdu_PBcfg.c and CDD_Gdu_PBcfg.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

