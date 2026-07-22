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
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_CFG_VENDOR_ID_C                     43
#define AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define AEC_IP_CFG_AR_RELEASE_MINOR_VERSION_C      9
#define AEC_IP_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define AEC_IP_CFG_SW_MAJOR_VERSION_C              7
#define AEC_IP_CFG_SW_MINOR_VERSION_C              0
#define AEC_IP_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip_Types.h */
#if (AEC_IP_CFG_VENDOR_ID_C != AEC_IP_TYPES_VENDOR_ID)
    #error "Aec_Ip_Cfg.c and Aec_Ip_Types.h have different vendor ids"
#endif
#if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_REVISION_VERSION_C != AEC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.c and Aec_Ip_Types.h are different"
#endif
#if ((AEC_IP_CFG_SW_MAJOR_VERSION_C != AEC_IP_TYPES_SW_MAJOR_VERSION) || \
     (AEC_IP_CFG_SW_MINOR_VERSION_C != AEC_IP_TYPES_SW_MINOR_VERSION) || \
     (AEC_IP_CFG_SW_PATCH_VERSION_C != AEC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aec_Ip_Cfg.c and Aec_Ip_Types.h are different"
#endif

/* Checks against Aec_Ip_Cfg.h */
#if (AEC_IP_CFG_VENDOR_ID_C != AEC_IP_CFG_VENDOR_ID)
    #error "Aec_Ip_Cfg.c and Aec_Ip_Cfg.h have different vendor ids"
#endif
#if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_REVISION_VERSION_C != AEC_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.c and Aec_Ip_Cfg.h are different"
#endif
#if ((AEC_IP_CFG_SW_MAJOR_VERSION_C != AEC_IP_CFG_SW_MAJOR_VERSION) || \
     (AEC_IP_CFG_SW_MINOR_VERSION_C != AEC_IP_CFG_SW_MINOR_VERSION) || \
     (AEC_IP_CFG_SW_PATCH_VERSION_C != AEC_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aec_Ip_Cfg.c and Aec_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.c and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"


/* List of configurations for routing interrupts */
static const Aec_Ip_IntRouteConfigType aIntRouteConfig[] =
{
    {AEC_AE_FAULTS_STATUS_GDU_FAULT_PROT_FL_MASK, 0U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_GDU_INT_FL_MASK, 1U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_DPGA_OC_NEG_FL_MASK, 2U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_DPGA_OC_POS_FL_MASK, 3U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_PMC_VLS_FL_MASK, 4U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_RAW_FAILED_FL_MASK, 5U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_CHKSUM_ERR_FL_MASK, 6U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_OBSCHK_ERR_FL_MASK, 7U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_XFER_ERR_FL_MASK, 8U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_EVENT_EXPIRED_FL_MASK, 9U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_MCU_SUPPLY_FL_MASK, 10U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_HVD_AE_INTERN_FL_MASK, 11U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_ILL_TEST_FL_MASK, 12U, NULL_PTR},
    {AEC_AE_FAULTS_STATUS_ALIVE_WDG_FL_MASK, 13U, NULL_PTR},
    {AEC_AE_EVENTS_STATUS_LIN_INT_FL_MASK, 14U, NULL_PTR},
    {AEC_AE_EVENTS_STATUS_OCD_VDDE_FL_MASK, 15U, NULL_PTR},
    {AEC_AE_EVENTS_STATUS_TEMP_WDG_PMC_FL_MASK, 16U, NULL_PTR},
    {AEC_AE_EVENTS_STATUS_TEMP_WDG_PHY_FL_MASK, 17U, NULL_PTR},
    {AEC_AE_EVENTS_STATUS_CAN_INT_FL_MASK, 18U, NULL_PTR},
    {AEC_AE_EVENTS_STATUS_LVD_VDDC_FL_MASK, 19U, NULL_PTR},
    {AEC_AE_EVENTS_STATUS_WAKEUP_FL_MASK, 20U, NULL_PTR},
    {AEC_AE_EVENTS_STATUS_HVI_ACTIVE_FL_MASK, 21U, NULL_PTR},
    {AEC_AE_EVENTS_STATUS_HVI_AE_SUPPLY_FL_MASK, 22U, NULL_PTR},
    {AEC_AE_EVENTS_STATUS_STATERESET_FL_MASK, 23U, NULL_PTR},
    {AEC_AE_EVENTS_STATUS_FRAMEWIDTH_FL_MASK, 24U, NULL_PTR},
};

/* List of configurations for routing interrupts */
static const Aec_Ip_GHSRouteConfigType aGHSRouteConfig[] =
{
    {AEC_STATUS_CLOCK_MISS, 0U, NULL_PTR},
    {AEC_STATUS_WRONG_ANSWER, 1U, NULL_PTR},
    {AEC_STATUS_FSM_STATUS, 2U, NULL_PTR},
    {AEC_STATUS_FRAME_COUNT, 3U, NULL_PTR},
};

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

/* Configuration structure for routing interrupt */
const Aec_Ip_GlobalRouteConfigType Aec_intRouteConfig =
{
    (uint16)(0U),
    (uint16)(0U),
    aIntRouteConfig
};

/* Configuration structure for routing interrupt */
const Aec_Ip_GlobalGHSRouteConfigType Aec_GHSRouteConfig =
{
    (uint16)(0U),
    aGHSRouteConfig
};

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

