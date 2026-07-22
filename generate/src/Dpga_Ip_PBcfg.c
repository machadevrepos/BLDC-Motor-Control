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
#include "Dpga_Ip_PBcfg.h"


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_IP_VENDOR_ID_PBCFG_C                      43
#define DPGA_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C       4
#define DPGA_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C       9
#define DPGA_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C    0
#define DPGA_IP_SW_MAJOR_VERSION_PBCFG_C               7
#define DPGA_IP_SW_MINOR_VERSION_PBCFG_C               0
#define DPGA_IP_SW_PATCH_VERSION_PBCFG_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Dpga_Ip_PBcfg header file are of the same vendor */
#if (DPGA_IP_VENDOR_ID_PBCFG_C != DPGA_IP_VENDOR_ID_PBCFG)
    #error "Dpga_Ip_PBcfg.c and Dpga_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if current file and Dpga_Ip_PBcfg header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C     != DPGA_IP_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C     != DPGA_IP_AR_RELEASE_MINOR_VERSION_PBCFG) || \
     (DPGA_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C  != DPGA_IP_AR_RELEASE_REVISION_VERSION_PBCFG) \
    )
    #error "AutoSar Version Numbers of Dpga_Ip_PBcfg.c and Dpga_Ip_PBcfg.h are different"
#endif

/* Check if current file and Dpga_Ip_PBcfg header file are of the same software version */
#if ((DPGA_IP_SW_MAJOR_VERSION_PBCFG_C != DPGA_IP_SW_MAJOR_VERSION_PBCFG) || \
     (DPGA_IP_SW_MINOR_VERSION_PBCFG_C != DPGA_IP_SW_MINOR_VERSION_PBCFG) || \
     (DPGA_IP_SW_PATCH_VERSION_PBCFG_C != DPGA_IP_SW_PATCH_VERSION_PBCFG) \
    )
    #error "Software Version Numbers of Dpga_Ip_PBcfg.c and Dpga_Ip_PBcfg.h are different"
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
#define DPGA_START_SEC_VAR_INIT_UNSPECIFIED
#include "Dpga_MemMap.h"

/**
* @brief Amplifier configuration structure for configuration variant .
*/
static Dpga_Ip_AmplifierConfigType Dpga_Ip_AmplifierConfig =
{
    1U,    /* .AmplifierGain - amplify by 16 */
    3U,    /* .OutCommonModeVoltage - Vref / 2 */
    0U,    /* .AmplifierOffset - see RM for detailed description of this value significance */
    2U,    /* .InCommonModeCoarse - shift with 100 uA current out of both inputs */
    2U     /* .InCommonModeFine - see RM for detailed description of this value significance */
};

#define DPGA_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Dpga_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define DPGA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dpga_MemMap.h"

/**
* @brief Dpga configuration structure for configuration variant .
*/
const Dpga_Ip_ConfigType Dpga_Ip_Config =
{
    &Dpga_Ip_AmplifierConfig,    /* .AmplifierConfig */
    0U,    /* .BlankingTimeDuration */
    /* .BTTriggerStateArray */
    {
        0U,    /* Trigger 1 - this trigger cannot start the BT counter */
        0U,    /* Trigger 2 - this trigger cannot start the BT counter */
        0U,    /* Trigger 3 - this trigger cannot start the BT counter */
        0U,    /* Trigger 4 - this trigger cannot start the BT counter */
        0U,    /* Trigger 5 - this trigger cannot start the BT counter */
        0U    /* Trigger 6 - this trigger cannot start the BT counter */
    },
#if (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING)
    (boolean)TRUE,    /* .BipolarInputModeEnable */
    0U,    /* .LowDetectLimit */
    255U,    /* .HighDetectLimit */
    255U,    /* .LowDetectFilterDuration */
    255U,    /* .HighDetectFilterDuration */
#endif /* (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING) */
    (Dpga_Ip_CallbackType)&Dpga_Callback    /* .DpgaCallback */
};

#define DPGA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dpga_MemMap.h"

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

