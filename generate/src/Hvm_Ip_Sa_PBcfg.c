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
*   @addtogroup HVM_DRIVER_CONFIGURATION HVM Driver Configuration
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
#include "Hvm_Ip_Types.h"
#include "Hvm_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HVM_IP_SA_PBCFG_VENDOR_ID_C                     43
#define HVM_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define HVM_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C      9
#define HVM_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define HVM_IP_SA_PBCFG_SW_MAJOR_VERSION_C              7
#define HVM_IP_SA_PBCFG_SW_MINOR_VERSION_C              0
#define HVM_IP_SA_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Hvm_Ip_Types.h */
#if (HVM_IP_SA_PBCFG_VENDOR_ID_C != HVM_IP_TYPES_VENDOR_ID)
    #error "Hvm_Ip_Sa_PBcfg.c and Hvm_Ip_Types.h have different vendor ids"
#endif
#if ((HVM_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != HVM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (HVM_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C    != HVM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (HVM_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION_C != HVM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip_Sa_PBcfg.c and Hvm_Ip_Types.h are different"
#endif
#if ((HVM_IP_SA_PBCFG_SW_MAJOR_VERSION_C != HVM_IP_TYPES_SW_MAJOR_VERSION) || \
     (HVM_IP_SA_PBCFG_SW_MINOR_VERSION_C != HVM_IP_TYPES_SW_MINOR_VERSION) || \
     (HVM_IP_SA_PBCFG_SW_PATCH_VERSION_C != HVM_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Hvm_Ip_Sa_PBcfg.c and Hvm_Ip_Types.h are different"
#endif

/* Checks against Hvm_Ip_Cfg.h */
#if (HVM_IP_SA_PBCFG_VENDOR_ID_C != HVM_IP_CFG_VENDOR_ID)
    #error "Hvm_Ip_Sa_PBcfg.c and Hvm_Ip_Cfg.h have different vendor ids"
#endif
#if ((HVM_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != HVM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (HVM_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C    != HVM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (HVM_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION_C != HVM_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip_Sa_PBcfg.c and Hvm_Ip_Cfg.h are different"
#endif
#if ((HVM_IP_SA_PBCFG_SW_MAJOR_VERSION_C != HVM_IP_CFG_SW_MAJOR_VERSION) || \
     (HVM_IP_SA_PBCFG_SW_MINOR_VERSION_C != HVM_IP_CFG_SW_MINOR_VERSION) || \
     (HVM_IP_SA_PBCFG_SW_PATCH_VERSION_C != HVM_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Hvm_Ip_Sa_PBcfg.c and Hvm_Ip_Cfg.h are different"
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
*                                   STATE STRUCTURE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

static const Ae_HviChannelConfig Ae_HviChannelConfigInit[1U] =
{
        {
            {
                /* .HviInstance */0U,
                /* .PullUpEn */(boolean)FALSE,
                /* .PullDownEn */(boolean)FALSE,
                /* .HviDivSelect */HVI_VOLTAGE_DIVISION_2
            },
            /* .HviDigitalInputEn */(boolean)FALSE,
            /* .HviDigitalInputPol */HVI_DIGITAL_INPUT_POLARITY_PULLDOWN,
            /* .InterruptDigitalEn */(boolean)FALSE
        } 
};

static const Ae_VmConfig Ae_VmConfigInit =
{
    /* .VoltageMonitorInput */VM_HIGH_VOLTAGE_INPUT,
    /* .VmHighVolDetectEn */(boolean)FALSE,
    /* .VmLowVolDetectEn */(boolean)FALSE,
    /* .IntHighVolDetectEn */(boolean)FALSE,
    /* .IntLowVolDetectEn */(boolean)FALSE,
    /* .VmHighVolRef */VM_HBI1,
    /* .VmLowVolRef */VM_LBI1
};

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

const Hvm_Ip_ConfigType Hvm_Ip_aConfigPB =
{
    /* .HvmAnalogChanel */(uint8)HVI0_CHANNEL,
    /* .HvmAnalogInput */(uint8)HVI_ANALOG_OUT_OHMIC,
    &Ae_HviChannelConfigInit[0U],
    &Ae_VmConfigInit
};

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

