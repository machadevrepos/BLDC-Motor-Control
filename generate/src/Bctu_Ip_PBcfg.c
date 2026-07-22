/*==================================================================================================
*   Project              : RTD AUTOSAR 4.9
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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
*   @addtogroup bctu_ip_driver_config Bctu IPL Configuration
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
#include "Bctu_Ip_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define BCTU_IP_VENDOR_ID_PBCFG_C                      43
#define BCTU_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C       4
#define BCTU_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C       9
#define BCTU_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C    0
#define BCTU_IP_SW_MAJOR_VERSION_PBCFG_C               7
#define BCTU_IP_SW_MINOR_VERSION_PBCFG_C               0
#define BCTU_IP_SW_PATCH_VERSION_PBCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Bctu_Ip_PBcfg.c file and Bctu_Ip_PBcfg.h file are of the same vendor */
#if (BCTU_IP_VENDOR_ID_PBCFG_C != BCTU_IP_VENDOR_ID_PBCFG)
    #error "Bctu_Ip_PBcfg.c and Bctu_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if Bctu_Ip_PBcfg.c file and Bctu_Ip_PBcfg.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C != BCTU_IP_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C != BCTU_IP_AR_RELEASE_MINOR_VERSION_PBCFG) || \
     (BCTU_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C != BCTU_IP_AR_RELEASE_REVISION_VERSION_PBCFG) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_PBcfg.c and Bctu_Ip_PBcfg.h are different"
#endif

/* Check if Bctu_Ip_PBcfg.c file and Bctu_Ip_PBcfg.h file are of the same Software version */
#if ((BCTU_IP_SW_MAJOR_VERSION_PBCFG_C != BCTU_IP_SW_MAJOR_VERSION_PBCFG) || \
     (BCTU_IP_SW_MINOR_VERSION_PBCFG_C != BCTU_IP_SW_MINOR_VERSION_PBCFG) || \
     (BCTU_IP_SW_PATCH_VERSION_PBCFG_C != BCTU_IP_SW_PATCH_VERSION_PBCFG) \
    )
  #error "Software Version Numbers of Bctu_Ip_PBcfg.c and Bctu_Ip_PBcfg.h are different"
#endif

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define ADC_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Adc_MemMap.h"
/*
* @brief        Bctu User Dma Fifo Buffers.
* @details      Dma will transfer data from Fifo to this buffer.
                This is Raw Data from Fifo, user should mask to get expected value.
*/
#define ADC_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Adc_MemMap.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

static const Bctu_Ip_TrigConfigType BctuHwUnit_0_aTrigConfigPB[2] =
{
    {
        23U, /* TrigIndex - BCTU_Trg23 */
        (boolean)FALSE, /* LoopEn */
        BCTU_IP_DATA_DEST_FIFO1, /* DataDest */
        (boolean)TRUE, /* HwTriggersEn */
        BCTU_IP_TRIG_TYPE_LIST, /* TrigType */
        2U, /* AdcTargetMask */
        0U /* AdcChanOrListStart - Start index in BCTU LIST, because trigger is configured in LIST mode */
    },
    {
        17U, /* TrigIndex - BCTU_EMIOS_0_17 */
        (boolean)FALSE, /* LoopEn */
        BCTU_IP_DATA_DEST_ADC_DATA_REG, /* DataDest */
        (boolean)TRUE, /* HwTriggersEn */
        BCTU_IP_TRIG_TYPE_SINGLE, /* TrigType */
        2U, /* AdcTargetMask */
        32U /* AdcChanOrListStart - Adc channel ID, because trigger is configured in single mode */
    }
};

static const Bctu_Ip_ListItemConfigType BctuHwUnit_0_aItemConfigPB[5] =
{
    { /* Command List Index: 0 - BctuListItems_0 */
        (boolean)TRUE, /* NextChanWaitOnTrig */
        32U, /* AdcChanIndex */
        (boolean)FALSE /* LastChanInList */
    },
    { /* Command List Index: 1 - BctuListItems_1 */
        (boolean)TRUE, /* NextChanWaitOnTrig */
        32U, /* AdcChanIndex */
        (boolean)FALSE /* LastChanInList */
    },
    { /* Command List Index: 2 - BctuListItems_2 */
        (boolean)TRUE, /* NextChanWaitOnTrig */
        42U, /* AdcChanIndex */
        (boolean)FALSE /* LastChanInList */
    },
    { /* Command List Index: 3 - BctuListItems_3 */
        (boolean)TRUE, /* NextChanWaitOnTrig */
        32U, /* AdcChanIndex */
        (boolean)FALSE /* LastChanInList */
    },
    { /* Command List Index: 4 - BctuListItems_4 */
        (boolean)FALSE, /* NextChanWaitOnTrig */
        32U, /* AdcChanIndex */
        (boolean)TRUE /* LastChanInList */
    }
};

static const Bctu_Ip_FifoConfigType BctuHwUnit_0_aFifoConfigPB[1] =
{
    /* Configuration for BCTU_FIFO1 */
    {
        0U, /* FifoIndex */
        4U, /* WatermarkValue */
        (boolean)FALSE, /* FifoDmaRawEnable */
        (boolean)FALSE, /* FifoDmaEnable */
        0U, /* FifoDmaChannel */
        NULL_PTR, /* UserFifoBuffer */
        (boolean)TRUE, /* bEnNotif */
        Bctu_FIFO1_WatermarkNotification, /* WatermarkNotification */
        NULL_PTR, /* UnderrunNotification */
        NULL_PTR /* OverrunNotification */
    }
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

const Bctu_Ip_ConfigType BctuHwUnit_0 =
{
    (boolean)FALSE, /* LowPowerModeEn */
    (boolean)TRUE, /* GlobalHwTriggersEn */
    0U, /* NewDataDmaEnMask */
    NULL_PTR, /* TriggerNotification */
    { { NULL_PTR, NULL_PTR, NULL_PTR }, { NULL_PTR, NULL_PTR, NULL_PTR } }, /* AdcNotifications */
    2U, /* NumTrigConfigs */
    BctuHwUnit_0_aTrigConfigPB, /* TrigConfigs */
    5U, /* NumListItems */
    BctuHwUnit_0_aItemConfigPB, /* ListItemConfigs */
    1U, /* NumFifoConfigs */
    BctuHwUnit_0_aFifoConfigPB /* FifoConfigs */
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

