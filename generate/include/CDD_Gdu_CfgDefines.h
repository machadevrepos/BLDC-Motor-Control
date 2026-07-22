
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

#ifndef CDD_GDU_CFGDEFINES_H
#define CDD_GDU_CFGDEFINES_H

/**
*   @file    CDD_Gdu_CfgDefines.h
*   @version 7.0.0
*
*   @brief   AUTOSAR Gdu - CDD_GDU configuration macros.
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

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_CFGDEFINES_VENDOR_ID                    43
#define GDU_CFGDEFINES_AR_RELEASE_MAJOR_VERSION     4
#define GDU_CFGDEFINES_AR_RELEASE_MINOR_VERSION     9
#define GDU_CFGDEFINES_AR_RELEASE_REVISION_VERSION  0
#define GDU_CFGDEFINES_SW_MAJOR_VERSION             7
#define GDU_CFGDEFINES_SW_MINOR_VERSION             0
#define GDU_CFGDEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** Switch between precompile/postbuild configurations */
#define GDU_PRECOMPILE_SUPPORT          STD_OFF
/** Toggle the availability of the Gdu_GetVersionInfo API */
#define GDU_VERSION_INFO_API            STD_OFF
/** Toggle the assertion of development errors */
#define GDU_DEV_ERROR_DETECT            STD_OFF
/** Toggle the user mode support */
#define GDU_ENABLE_USER_MODE_SUPPORT    STD_OFF

/** MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined when enabling user mode support at driver scope. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == GDU_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled, but GDU_ENABLE_USER_MODE_SUPPORT is!
    #endif /* (STD_ON == GDU_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

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

#endif /* CDD_GDU_CFGDEFINES_H */

