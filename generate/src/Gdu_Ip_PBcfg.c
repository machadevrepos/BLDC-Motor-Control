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
*   @file    Gdu_Ip_PBcfg.c
*   @version 7.0.0
*
*   @brief   AUTOSAR Gdu - IPV_GDU postbuild configuration.
*
*   @addtogroup IPV_GDU
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
#include "Gdu_Ip_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_IP_PBCFG_VENDOR_ID_C                     43
#define GDU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define GDU_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C      9
#define GDU_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define GDU_IP_PBCFG_SW_MAJOR_VERSION_C              7
#define GDU_IP_PBCFG_SW_MINOR_VERSION_C              0
#define GDU_IP_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (GDU_IP_PBCFG_VENDOR_ID_C != GDU_IP_PBCFG_VENDOR_ID)
    #error "Gdu_Ip_PBcfg.c and Gdu_Ip_PBcfg.h have different vendor ids"
#endif
#if ((GDU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != GDU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != GDU_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (GDU_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != GDU_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gdu_Ip_PBcfg.c and Gdu_Ip_PBcfg.h are different"
#endif
#if ((GDU_IP_PBCFG_SW_MAJOR_VERSION_C != GDU_IP_PBCFG_SW_MAJOR_VERSION) || \
     (GDU_IP_PBCFG_SW_MINOR_VERSION_C != GDU_IP_PBCFG_SW_MINOR_VERSION) || \
     (GDU_IP_PBCFG_SW_PATCH_VERSION_C != GDU_IP_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gdu_Ip_PBcfg.c and Gdu_Ip_PBcfg.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/** These bits are set at reset, and are not configured by the driver */
#define GDU_IP_PBCFG_REG_CTL_RESET_VAL  0x00C3u

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define GDU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gdu_MemMap.h"

/* VariantPostBuild or more than 1 configured variant */
const Gdu_Ip_ConfigType Gdu_Ip_xConfig =
{
/** INTF */       0U,
/** RESERVED_0 */ {0U},
/** INTEN */      (GDU_AE_INTEN_HDHVDIE(1U) | GDU_AE_INTEN_DHSIE2(1U) | GDU_AE_INTEN_DHSIE1(1U) | GDU_AE_INTEN_DHSIE0(1U) | GDU_AE_INTEN_DLSIE2(1U) | GDU_AE_INTEN_DLSIE1(1U) | GDU_AE_INTEN_DLSIE0(1U)),
/** RESERVED_1 */ {0U},
/** STAT */       0U,
/** CTL */        (GDU_AE_CTL_BOOSTEN(0U) | GDU_AE_CTL_IRTSW(0U) | GDU_IP_PBCFG_REG_CTL_RESET_VAL),
/** CFG */        (GDU_AE_CFG_SYNCEN(1U) | GDU_AE_CFG_HDHSDIV(0U) | GDU_AE_CFG_HDHVDCFG(0U)),
/** RESERVED_2 */ {0U},
/** EACFG */      (GDU_AE_EACFG_DSA(1U) | GDU_AE_EACFG_OCA(1U)  | GDU_AE_EACFG_HVDA(0U)),
/** RESERVED_3 */ {0U},
/** BOOSTCFG */   (GDU_AE_BOOSTCFG_BOCL(GDU_ICOIL_0) | GDU_AE_BOOSTCFG_BOCD(1U) | GDU_AE_BOOSTCFG_BODC((uint8)GDU_DUTY_CYCLE_3_DIV_4)),
/** BTCFG */      (GDU_AE_BTCFG_BT(200U)),
/** HSSRON */     (GDU_AE_HSSRON_HSTONT_P2(2U) | GDU_AE_HSSRON_HSTONT_P1(4U) | GDU_AE_HSSRON_HSTONC_P3(23U) | GDU_AE_HSSRON_HSTONC_P2(2U) | GDU_AE_HSSRON_HSTONC_P1(20U)),
/** HSSROFF */    (GDU_AE_HSSROFF_HSTOFFT_P2(2U) | GDU_AE_HSSROFF_HSTOFFT_P1(4U) | GDU_AE_HSSROFF_HSTOFFC_P3(23U) | GDU_AE_HSSROFF_HSTOFFC_P2(2U) | GDU_AE_HSSROFF_HSTOFFC_P1(20U)),
/** LSSRON */     (GDU_AE_LSSRON_LSTONT_P2(2U) | GDU_AE_LSSRON_LSTONT_P1(4U) | GDU_AE_LSSRON_LSTONC_P3(23U) | GDU_AE_LSSRON_LSTONC_P2(2U) | GDU_AE_LSSRON_LSTONC_P1(20U)),
/** LSSROFF */    (GDU_AE_LSSROFF_LSTOFFT_P2(2U) | GDU_AE_LSSROFF_LSTOFFT_P1(4U) | GDU_AE_LSSROFF_LSTOFFC_P3(23U) | GDU_AE_LSSROFF_LSTOFFC_P2(2U) | GDU_AE_LSSROFF_LSTOFFC_P1(20U)),
/** OFFSDCFG */   0U,
/** RESERVED_3 */ {0U},
/** DSCFG */      (GDU_AE_DSCFG_DSFHS(GDU_DS_FILTER_1400ns) | GDU_AE_DSCFG_DSFLS(GDU_DS_FILTER_1400ns) | GDU_AE_DSCFG_DSLHS(GDU_DS_LEVEL_1450mV)  | GDU_AE_DSCFG_DSLLS(GDU_DS_LEVEL_1450mV)),
/** RESERVED_5 */ {0U},
/** CPCFG */      (GDU_AE_CPCFG_CPCDT(GDU_CP_DISCHARGE_500ns) | GDU_AE_CPCFG_CPT(0U) | GDU_AE_CPCFG_CPCD(160U)),
/** DLYMR */      0U,
/** DLYMCFG */    0U,
/** SUPCFG */     (GDU_AE_SUPCFG_SUP(1U)),
/** RESERVED_5 */ {0U},
/** IRT */        (GDU_AE_IRT_IRT1P2(GDU_IP_IREF_TRIM_000) | GDU_AE_IRT_IRT0P2(GDU_IP_IREF_TRIM_000) | GDU_AE_IRT_IRT1P1(GDU_IP_IREF_TRIM_000) | GDU_AE_IRT_IRT0P1(GDU_IP_IREF_TRIM_000) | GDU_AE_IRT_IRT1P0(GDU_IP_IREF_TRIM_000) | GDU_AE_IRT_IRT0P0(GDU_IP_IREF_TRIM_000))
};
#define GDU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gdu_MemMap.h"

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

