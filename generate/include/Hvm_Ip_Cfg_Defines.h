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

#ifndef HVM_IP_CFG_DEFINES_H
#define HVM_IP_CFG_DEFINES_H

/**
*   @file Hvm_Ip_Cfg_Defines.h
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
#include "S32M27x_HVI_AE.h" 

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HVM_IP_CFG_DEFINES_VENDOR_ID                     43
#define HVM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION      4
#define HVM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION      9
#define HVM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION   0
#define HVM_IP_CFG_DEFINES_SW_MAJOR_VERSION              7
#define HVM_IP_CFG_DEFINES_SW_MINOR_VERSION              0
#define HVM_IP_CFG_DEFINES_SW_PATCH_VERSION              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define HVM_IP_YOUNG_FELLOW (STD_OFF)
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

#endif /* HVM_IP_CFG_DEFINES_H */

