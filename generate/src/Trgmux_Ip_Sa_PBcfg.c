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

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Trgmux_Ip_Cfg.h"

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_SA_PBCFG_VENDOR_ID_C                     43
#define TRGMUX_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define TRGMUX_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C      9
#define TRGMUX_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define TRGMUX_IP_SA_PBCFG_SW_MAJOR_VERSION_C              7
#define TRGMUX_IP_SA_PBCFG_SW_MINOR_VERSION_C              0
#define TRGMUX_IP_SA_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Trgmux_Ip_Sa_PBcfg.c file and Trgmux_Ip_Cfg.h file are of the same vendor */
#if (TRGMUX_IP_SA_PBCFG_VENDOR_ID_C != TRGMUX_IP_CFG_VENDOR_ID)
    #error "Trgmux_Ip_Sa_PBcfg.c and Trgmux_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Trgmux_Ip_Sa_PBcfg.c file and Trgmux_Ip_Cfg.h file are of the same Autosar version */
#if ((TRGMUX_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C != TRGMUX_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C != TRGMUX_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION_C != TRGMUX_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_Sa_PBcfg.c and Trgmux_Ip_Cfg.h are different"
#endif

/* Check if Trgmux_Ip_Sa_PBcfg.c file and Trgmux_Ip_Cfg.h file are of the same Software version */
#if ((TRGMUX_IP_SA_PBCFG_SW_MAJOR_VERSION_C != TRGMUX_IP_CFG_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_SA_PBCFG_SW_MINOR_VERSION_C != TRGMUX_IP_CFG_SW_MINOR_VERSION) || \
     (TRGMUX_IP_SA_PBCFG_SW_PATCH_VERSION_C != TRGMUX_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_Sa_PBcfg.c and Trgmux_Ip_Cfg.h are different"
#endif


/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define MCL_START_SEC_CONST_8
#include "Mcl_MemMap.h"
static const uint8 Trgmux_Ip_InstanceArr[1U]= {TRGMUX_IP_HW_INST_0};

#define MCL_STOP_SEC_CONST_8
#include "Mcl_MemMap.h"

#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"
/* TRGMUX Logic Trigger Configuration */

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger0ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_0_TRIGGER_0,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU0_0_INP_I2,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_EMIOS0_IPP_CH9,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger1ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_0_TRIGGER_1,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU0_0_INP_I3,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_EMIOS0_IPP_CH10,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger2ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_0_TRIGGER_2,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU0_0_INP_I0,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_EMIOS0_IPP_CH13,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger3ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_0_TRIGGER_3,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU0_0_INP_I1,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_EMIOS0_IPP_CH14,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger4ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_1_TRIGGER_0,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU0_2_INP_I8,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_EMIOS0_IPP_CH11,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger5ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_1_TRIGGER_1,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU0_2_INP_I9,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_EMIOS0_IPP_CH12,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger6ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_1_TRIGGER_2,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU0_2_INP_I10,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_EMIOS0_IPP_CH5,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger7ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_2_TRIGGER_0,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_BCTU_TRG23,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_LCU0_LC2_OUT_I2,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger8ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_3_TRIGGER_0,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU0_1_INP_I4,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_EMIOS0_IPP_CH1,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger9ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_3_TRIGGER_1,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU0_1_INP_I5,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_EMIOS0_IPP_CH2,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger10ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_3_TRIGGER_2,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU0_1_INP_I6,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_EMIOS0_IPP_CH3,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger11ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_3_TRIGGER_3,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU0_1_INP_I7,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_EMIOS0_IPP_CH4,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger12ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_4_TRIGGER_0,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU1_0_INP_I0,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_SIUL2_IN6,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger13ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_4_TRIGGER_1,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_LCU1_0_INP_I1,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_SIUL2_IN8,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger14ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_5_TRIGGER_0,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_EMIOS0_CH5_9_IPP_IND_CH6,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_LCU1_LC0_OUT_I2,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger15ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_5_TRIGGER_1,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_EMIOS0_CH5_9_IPP_IND_CH7,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_LCU1_LC0_OUT_I3,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger16ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_6_TRIGGER_0,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_SIUL2_4_7_OUT6,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_LCU0_LC2_OUT_I2,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

static const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger17ConfigPB =
{
    /* uint8 LogicChannel; */   (uint8)TRGMUX_LOGIC_GROUP_6_TRIGGER_1,
    /* uint8 Output; */         (uint8)TRGMUX_IP_OUTPUT_SIUL2_4_7_OUT7,
    /* uint8 Input; */          (uint8)TRGMUX_IP_INPUT_LOGIC0_VSS,
    /* uint8 HwInstId; */       (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */         (boolean)FALSE,
};

/* Trgmux_Ip_LogicTriggerType * paxLogicTrigger[] */

static const Trgmux_Ip_LogicTriggerType * const LogicTriggerArray[18U] =
{
    		&Trgmux_Ip_LogicTrigger0ConfigPB,
		&Trgmux_Ip_LogicTrigger1ConfigPB,
		&Trgmux_Ip_LogicTrigger2ConfigPB,
		&Trgmux_Ip_LogicTrigger3ConfigPB,
		&Trgmux_Ip_LogicTrigger4ConfigPB,
		&Trgmux_Ip_LogicTrigger5ConfigPB,
		&Trgmux_Ip_LogicTrigger6ConfigPB,
		&Trgmux_Ip_LogicTrigger7ConfigPB,
		&Trgmux_Ip_LogicTrigger8ConfigPB,
		&Trgmux_Ip_LogicTrigger9ConfigPB,
		&Trgmux_Ip_LogicTrigger10ConfigPB,
		&Trgmux_Ip_LogicTrigger11ConfigPB,
		&Trgmux_Ip_LogicTrigger12ConfigPB,
		&Trgmux_Ip_LogicTrigger13ConfigPB,
		&Trgmux_Ip_LogicTrigger14ConfigPB,
		&Trgmux_Ip_LogicTrigger15ConfigPB,
		&Trgmux_Ip_LogicTrigger16ConfigPB,
		&Trgmux_Ip_LogicTrigger17ConfigPB,
};

/* TRGMUX Initialization Structure */
const Trgmux_Ip_InitType Trgmux_Ip_Sa_xTrgmuxInitPB =
{
    &LogicTriggerArray[0],                /* const Trgmux_Ip_LogicTriggerType * const * paxLogicTrigger */
    18U,                            /* uint8 NumOfLogicTriger */
    Trgmux_Ip_InstanceArr,                /* const uint8 * paxLogicInstance */
    1U        /* uint8 NumOfLogicInstance */
};
#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"



#ifdef __cplusplus
}
#endif

