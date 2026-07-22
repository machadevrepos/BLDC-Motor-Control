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

#ifndef CDD_GDU_CFG_H
#define CDD_GDU_CFG_H

/**
*   @file    CDD_Gdu_Cfg.h
*   @version 7.0.0
*
*   @brief   AUTOSAR Gdu - HLD precompile configuration header.
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
#include "CDD_Gdu_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_CFG_VENDOR_ID                    43
#define GDU_CFG_AR_RELEASE_MAJOR_VERSION     4
#define GDU_CFG_AR_RELEASE_MINOR_VERSION     9
#define GDU_CFG_AR_RELEASE_REVISION_VERSION  0
#define GDU_CFG_SW_MAJOR_VERSION             7
#define GDU_CFG_SW_MINOR_VERSION             0
#define GDU_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and Gdu configuration header file are of the same vendor */
#if (GDU_CFG_VENDOR_ID != GDU_PBCFG_VENDOR_ID)
    #error "CDD_Gdu_Cfg.h and CDD_Gdu_PBcfg.h have different vendor ids"
#endif
 /* Check if header file and Gdu configuration header file are of the same Autosar version */
#if ((GDU_CFG_AR_RELEASE_MAJOR_VERSION    != GDU_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
    (GDU_CFG_AR_RELEASE_MINOR_VERSION    != GDU_PBCFG_AR_RELEASE_MINOR_VERSION) || \
    (GDU_CFG_AR_RELEASE_REVISION_VERSION != GDU_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Gdu_Cfg.h and CDD_Gdu_PBcfg.h are different"
#endif
/* Check if header file and Gdu configuration header file are of the same software version */
#if ((GDU_CFG_SW_MAJOR_VERSION != GDU_PBCFG_SW_MAJOR_VERSION) || \
    (GDU_CFG_SW_MINOR_VERSION != GDU_PBCFG_SW_MINOR_VERSION) || \
    (GDU_CFG_SW_PATCH_VERSION != GDU_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Gdu_Cfg.h and CDD_Gdu_PBcfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define GDU_CONFIG_EXT \
    GDU_CONFIG_PB

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

#endif /* GDU_CFG_H */

