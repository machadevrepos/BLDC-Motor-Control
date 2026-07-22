/*==================================================================================================
*   Project              : RTD AUTOSAR 4.9
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms. By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms. If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/* Prevention from multiple including the same header */
#ifndef LCU_IP_CFG_H_
#define LCU_IP_CFG_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Included files
 ******************************************************************************/

#include "Lcu_Ip_Sa_PBcfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_CFG_VENDOR_ID                       43
#define LCU_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define LCU_IP_CFG_AR_RELEASE_MINOR_VERSION        9
#define LCU_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define LCU_IP_CFG_SW_MAJOR_VERSION                7
#define LCU_IP_CFG_SW_MINOR_VERSION                0
#define LCU_IP_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Lcu_Ip_Sa_PBcfg.h file are of the same vendor */
#if (LCU_IP_CFG_VENDOR_ID != LCU_IP_SA_PBCFG_VENDOR_ID)
    #error "Lcu_Ip_Cfg.h and Lcu_Ip_Sa_PBcfg.h have different vendor ids"
#endif
/* Check if header file and Lcu_Ip_Sa_PBcfg.h file are of the same Autosar version */
#if ((LCU_IP_CFG_AR_RELEASE_MAJOR_VERSION != LCU_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
        (LCU_IP_CFG_AR_RELEASE_MINOR_VERSION != LCU_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION) || \
        (LCU_IP_CFG_AR_RELEASE_REVISION_VERSION != LCU_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Cfg.h and Lcu_Ip_Sa_PBcfg.h are different"
#endif
/* Check if header file and Lcu_Ip_Sa_PBcfg.h file are of the same Software version */
#if ((LCU_IP_CFG_SW_MAJOR_VERSION != LCU_IP_SA_PBCFG_SW_MAJOR_VERSION) || \
        (LCU_IP_CFG_SW_MINOR_VERSION != LCU_IP_SA_PBCFG_SW_MINOR_VERSION) || \
        (LCU_IP_CFG_SW_PATCH_VERSION != LCU_IP_SA_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Cfg.h and Lcu_Ip_Sa_PBcfg.h are different"
#endif
    
/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/

/* Number Of Configured Standard Alone Logic Instances */
#define SA_LCU_IP_NOF_CFG_LOGIC_INSTANCES    ((uint32)2U)

/* Standard Alone Logic Instance 0 */
#define LCU_LOGIC_INSTANCE_0              ((uint32)0U)

/* Standard Alone Logic Instance 1 */
#define LCU_LOGIC_INSTANCE_1              ((uint32)1U)


/* Number Of Configured Standard Alone Logic Inputs */
#define SA_LCU_IP_NOF_CFG_LOGIC_INPUTS       ((uint32)16U)

/* Standard Alone Logic Input 0 */
#define LCU_LOGIC_INPUT_0                 ((uint32)0U)

/* Standard Alone Logic Input 1 */
#define LCU_LOGIC_INPUT_1                 ((uint32)1U)

/* Standard Alone Logic Input 2 */
#define LCU_LOGIC_INPUT_2                 ((uint32)2U)

/* Standard Alone Logic Input 3 */
#define LCU_LOGIC_INPUT_3                 ((uint32)3U)

/* Standard Alone Logic Input 4 */
#define LCU_LOGIC_INPUT_4                 ((uint32)4U)

/* Standard Alone Logic Input 5 */
#define LCU_LOGIC_INPUT_5                 ((uint32)5U)

/* Standard Alone Logic Input 6 */
#define LCU_LOGIC_INPUT_6                 ((uint32)6U)

/* Standard Alone Logic Input 7 */
#define LCU_LOGIC_INPUT_7                 ((uint32)7U)

/* Standard Alone Logic Input 8 */
#define LCU_LOGIC_INPUT_8                 ((uint32)8U)

/* Standard Alone Logic Input 9 */
#define LCU_LOGIC_INPUT_9                 ((uint32)9U)

/* Standard Alone Logic Input 10 */
#define LCU_LOGIC_INPUT_10                 ((uint32)10U)

/* Standard Alone Logic Input 11 */
#define LCU_LOGIC_INPUT_11                 ((uint32)11U)

/* Standard Alone Logic Input 12 */
#define LCU_LOGIC_INPUT_12                 ((uint32)12U)

/* Standard Alone Logic Input 13 */
#define LCU_LOGIC_INPUT_13                 ((uint32)13U)

/* Standard Alone Logic Input 14 */
#define LCU_LOGIC_INPUT_14                 ((uint32)14U)

/* Standard Alone Logic Input 15 */
#define LCU_LOGIC_INPUT_15                 ((uint32)15U)


/* Number Of Configured Standard Alone Logic Outputs */
#define SA_LCU_IP_NOF_CFG_LOGIC_OUTPUTS      ((uint32)12U)

/* Standard Alone Logic Output 0 */
#define LCU_LOGIC_OUTPUT_0                ((uint32)0U)

/* Standard Alone Logic Output 1 */
#define LCU_LOGIC_OUTPUT_1                ((uint32)1U)

/* Standard Alone Logic Output 2 */
#define LCU_LOGIC_OUTPUT_2                ((uint32)2U)

/* Standard Alone Logic Output 3 */
#define LCU_LOGIC_OUTPUT_3                ((uint32)3U)

/* Standard Alone Logic Output 4 */
#define LCU_LOGIC_OUTPUT_4                ((uint32)4U)

/* Standard Alone Logic Output 5 */
#define LCU_LOGIC_OUTPUT_5                ((uint32)5U)

/* Standard Alone Logic Output 6 */
#define LCU_LOGIC_OUTPUT_6                ((uint32)6U)

/* Standard Alone Logic Output 7 */
#define LCU_LOGIC_OUTPUT_7                ((uint32)7U)

/* Standard Alone Logic Output 8 */
#define LCU_LOGIC_OUTPUT_8                ((uint32)8U)

/* Standard Alone Logic Output 9 */
#define LCU_LOGIC_OUTPUT_9                ((uint32)9U)

/* Standard Alone Logic Output 10 */
#define LCU_LOGIC_OUTPUT_10                ((uint32)10U)

/* Standard Alone Logic Output 11 */
#define LCU_LOGIC_OUTPUT_11                ((uint32)11U)

#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Lcu_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

extern const Lcu_Ip_InitType Lcu_Ip_Sa_xLcuInitPB;

/* LCU Input De-Initialization Structure */
extern const Lcu_Ip_LogicInputConfigType Lcu_Ip_xLogicInputResetConfig;

/* LCU Output De-Initialization Structure */
extern const Lcu_Ip_LogicOutputConfigType Lcu_Ip_xLogicOutputResetConfig;

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Lcu_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

#define MCL_START_SEC_CODE
/* @violates @ref Mcl_Lcu_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

ISR(Lcu0_Ip_IRQHandler);

ISR(Lcu1_Ip_IRQHandler);

#define MCL_STOP_SEC_CODE
/* @violates @ref Mcl_Lcu_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"
#ifdef __cplusplus
}
#endif

#endif  /* #ifndef LCU_IP_CFG_H_ */

