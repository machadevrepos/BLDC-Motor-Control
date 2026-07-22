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
#include "Lcu_Ip_Cfg.h"

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_SA_PBCFG_VENDOR_ID_C                        43
#define LCU_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C         4
#define LCU_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C         9
#define LCU_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION_C      0
#define LCU_IP_SA_PBCFG_SW_MAJOR_VERSION_C                 7
#define LCU_IP_SA_PBCFG_SW_MINOR_VERSION_C                 0
#define LCU_IP_SA_PBCFG_SW_PATCH_VERSION_C                 0
/* Check if Lcu_Ip_Sa_PBcfg.c file and Lcu_Ip_Cfg.h file are of the same vendor */
#if (LCU_IP_SA_PBCFG_VENDOR_ID_C != LCU_IP_CFG_VENDOR_ID)
    #error "Lcu_Ip_Sa_PBcfg.c and Lcu_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Lcu_Ip_Sa_PBcfg.c file and Lcu_Ip_Cfg.h file are of the same Autosar version */
#if ((LCU_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C != LCU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C != LCU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION_C != LCU_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Sa_PBcfg.c and Lcu_Ip_Cfg.h are different"
#endif

/* Check if Lcu_Ip_Sa_PBcfg.c file and Lcu_Ip_Cfg.h file are of the same Software version */
#if ((LCU_IP_SA_PBCFG_SW_MAJOR_VERSION_C != LCU_IP_CFG_SW_MAJOR_VERSION) || \
     (LCU_IP_SA_PBCFG_SW_MINOR_VERSION_C != LCU_IP_CFG_SW_MINOR_VERSION) || \
     (LCU_IP_SA_PBCFG_SW_PATCH_VERSION_C != LCU_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Sa_PBcfg.c and Lcu_Ip_Cfg.h are different"
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


#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref LCU_IP_SA_PBCFG_C_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

/* LCU Logic Instance Configuration */
/* LCU Logic Instance 0 Configuration */
static const Lcu_Ip_LogicInstanceType LcuLogicInstance0ConfigPB =
{
    /* uint8 HwInstId             */ LCU_IP_HW_INST_0,
    /* uint8 NumLogicCellConfig   */ 0U,
    /* ppxLogicCellConfigArray    */ NULL_PTR,
    /* uint8 OperationMode        */ LCU_IP_INTERRUPT_MODE,
};

/* LCU Logic Instance 1 Configuration */
static const Lcu_Ip_LogicInstanceType LcuLogicInstance1ConfigPB =
{
    /* uint8 HwInstId             */ LCU_IP_HW_INST_1,
    /* uint8 NumLogicCellConfig   */ 0U,
    /* ppxLogicCellConfigArray    */ NULL_PTR,
    /* uint8 OperationMode        */ LCU_IP_INTERRUPT_MODE,
};

/* LCU Logic Instance Array Configuration */
static const Lcu_Ip_LogicInstanceType * const Lcu_Ip_ppxLogicInstanceArrayPB[2U] =
{
    &LcuLogicInstance0ConfigPB,
    &LcuLogicInstance1ConfigPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput0CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_2,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput0PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_0,
        /* uint8 HwLcInputId   */ 2U,
    },
    &LogicInput0CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput1CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_3,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput1PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_0,
        /* uint8 HwLcInputId   */ 3U,
    },
    &LogicInput1CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput2CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_8,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput2PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_0,
        /* uint8 HwLcInputId   */ 8U,
    },
    &LogicInput2CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput3CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_9,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput3PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_0,
        /* uint8 HwLcInputId   */ 9U,
    },
    &LogicInput3CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput4CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_0,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput4PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_0,
        /* uint8 HwLcInputId   */ 0U,
    },
    &LogicInput4CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput5CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_1,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput5PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_0,
        /* uint8 HwLcInputId   */ 1U,
    },
    &LogicInput5CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput6CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_4,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput6PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_0,
        /* uint8 HwLcInputId   */ 4U,
    },
    &LogicInput6CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput7CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_5,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput7PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_0,
        /* uint8 HwLcInputId   */ 5U,
    },
    &LogicInput7CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput8CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_6,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput8PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_0,
        /* uint8 HwLcInputId   */ 6U,
    },
    &LogicInput8CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput9CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_7,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput9PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_0,
        /* uint8 HwLcInputId   */ 7U,
    },
    &LogicInput9CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput10CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_OUT_4,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput10PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_0,
        /* uint8 HwLcInputId   */ 11U,
    },
    &LogicInput10CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput11CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_10,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput11PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_0,
        /* uint8 HwLcInputId   */ 10U,
    },
    &LogicInput11CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput12CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_0,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput12PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_1,
        /* uint8 HwLcInputId   */ 0U,
    },
    &LogicInput12CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput13CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_IN_1,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput13PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_1,
        /* uint8 HwLcInputId   */ 1U,
    },
    &LogicInput13CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput14CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_OUT_0,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput14PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_1,
        /* uint8 HwLcInputId   */ 2U,
    },
    &LogicInput14CfgPB,
};


/* LCU Logic Input Configuration */
static const Lcu_Ip_LogicInputConfigType LogicInput15CfgPB =
{
    /* uint8 MuxSel         */ LCU_IP_MUX_SEL_LU_OUT_1,
    /* uint8 SwValue        */ LCU_IP_SW_OVERRIDE_LOGIC_LOW,
};

static const Lcu_Ip_LogicInputType LogicInput15PB =
{
    {
        /* uint8 HwInstId      */ LCU_IP_HW_INST_1,
        /* uint8 HwLcInputId   */ 3U,
    },
    &LogicInput15CfgPB,
};

static const Lcu_Ip_LogicInputType * const Lcu_Ip_ppxLogicInputArrayPB[16U] =
{
    &LogicInput0PB,
    &LogicInput1PB,
    &LogicInput2PB,
    &LogicInput3PB,
    &LogicInput4PB,
    &LogicInput5PB,
    &LogicInput6PB,
    &LogicInput7PB,
    &LogicInput8PB,
    &LogicInput9PB,
    &LogicInput10PB,
    &LogicInput11PB,
    &LogicInput12PB,
    &LogicInput13PB,
    &LogicInput14PB,
    &LogicInput15PB,
};

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref LCU_IP_SA_PBCFG_C_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"



/* LCU Hardware output state */

#define MCL_START_SEC_VAR_CLEARED_UNSPECIFIED
/* @violates @ref LCU_IP_SA_PBCFG_C_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"
static Lcu_Ip_HwOutputStateType HwOutput0StatePB;

static Lcu_Ip_HwOutputStateType HwOutput1StatePB;

static Lcu_Ip_HwOutputStateType HwOutput2StatePB;

static Lcu_Ip_HwOutputStateType HwOutput3StatePB;

static Lcu_Ip_HwOutputStateType HwOutput4StatePB;

static Lcu_Ip_HwOutputStateType HwOutput5StatePB;

static Lcu_Ip_HwOutputStateType HwOutput6StatePB;

static Lcu_Ip_HwOutputStateType HwOutput7StatePB;

static Lcu_Ip_HwOutputStateType HwOutput8StatePB;

static Lcu_Ip_HwOutputStateType HwOutput9StatePB;

static Lcu_Ip_HwOutputStateType HwOutput10StatePB;

static Lcu_Ip_HwOutputStateType HwOutput11StatePB;

#define MCL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"


#define MCL_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref LCU_IP_SA_PBCFG_C_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"
static Lcu_Ip_HwOutputStateType * Lcu_Ip_ppxHwOutputStateArrayPB[12U] =
{
    &HwOutput0StatePB,
    &HwOutput1StatePB,
    &HwOutput2StatePB,
    &HwOutput3StatePB,
    &HwOutput4StatePB,
    &HwOutput5StatePB,
    &HwOutput6StatePB,
    &HwOutput7StatePB,
    &HwOutput8StatePB,
    &HwOutput9StatePB,
    &HwOutput10StatePB,
    &HwOutput11StatePB,
};

#define MCL_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"


#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref LCU_IP_SA_PBCFG_C_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

/* LCU Logic Output Configuration */
static const Lcu_Ip_LogicOutputConfigType LogicOutput0CfgPB =
{
    /* boolean EnDebugMode   */ (boolean)FALSE,
    /* uint16 LutControl     */ 0X0FFFU,
    /* uint16 LutRiseFilt    */ 75U,
    /* uint16 LutFallFilt    */ 0U,
    /* boolean EnLutDma      */ (boolean)FALSE,
    /* boolean EnForceDma    */ (boolean)FALSE,
    /* boolean EnLutInt      */ (boolean)FALSE,
    /* boolean EnForceInt    */ (boolean)FALSE,
    /* boolean InvertOutput  */ (boolean)FALSE,
    /* uint8 ForceSignalSel  */ 0U,
    /* uint8 ClearForceMode  */ LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE,
    /* uint8 ForceSyncSel    */ LCU_IP_SYNC_SEL_INPUT0,
};

static const Lcu_Ip_LogicOutputType LogicOutput0PB =
{
    {
        /* uint8 HwInstId               */ LCU_IP_HW_INST_0,
        /* uint8 HwLcOutputId           */ 2U,
        /* Lcu_Ip_Callback IntCallback  */ NULL_PTR,
    },
    &LogicOutput0CfgPB,
};


/* LCU Logic Output Configuration */
static const Lcu_Ip_LogicOutputConfigType LogicOutput1CfgPB =
{
    /* boolean EnDebugMode   */ (boolean)FALSE,
    /* uint16 LutControl     */ 0XF000U,
    /* uint16 LutRiseFilt    */ 75U,
    /* uint16 LutFallFilt    */ 0U,
    /* boolean EnLutDma      */ (boolean)FALSE,
    /* boolean EnForceDma    */ (boolean)FALSE,
    /* boolean EnLutInt      */ (boolean)FALSE,
    /* boolean EnForceInt    */ (boolean)FALSE,
    /* boolean InvertOutput  */ (boolean)FALSE,
    /* uint8 ForceSignalSel  */ 0U,
    /* uint8 ClearForceMode  */ LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE,
    /* uint8 ForceSyncSel    */ LCU_IP_SYNC_SEL_INPUT0,
};

static const Lcu_Ip_LogicOutputType LogicOutput1PB =
{
    {
        /* uint8 HwInstId               */ LCU_IP_HW_INST_0,
        /* uint8 HwLcOutputId           */ 3U,
        /* Lcu_Ip_Callback IntCallback  */ NULL_PTR,
    },
    &LogicOutput1CfgPB,
};


/* LCU Logic Output Configuration */
static const Lcu_Ip_LogicOutputConfigType LogicOutput2CfgPB =
{
    /* boolean EnDebugMode   */ (boolean)FALSE,
    /* uint16 LutControl     */ 0X7777U,
    /* uint16 LutRiseFilt    */ 75U,
    /* uint16 LutFallFilt    */ 0U,
    /* boolean EnLutDma      */ (boolean)FALSE,
    /* boolean EnForceDma    */ (boolean)FALSE,
    /* boolean EnLutInt      */ (boolean)FALSE,
    /* boolean EnForceInt    */ (boolean)FALSE,
    /* boolean InvertOutput  */ (boolean)FALSE,
    /* uint8 ForceSignalSel  */ 0U,
    /* uint8 ClearForceMode  */ LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE,
    /* uint8 ForceSyncSel    */ LCU_IP_SYNC_SEL_INPUT0,
};

static const Lcu_Ip_LogicOutputType LogicOutput2PB =
{
    {
        /* uint8 HwInstId               */ LCU_IP_HW_INST_0,
        /* uint8 HwLcOutputId           */ 8U,
        /* Lcu_Ip_Callback IntCallback  */ NULL_PTR,
    },
    &LogicOutput2CfgPB,
};


/* LCU Logic Output Configuration */
static const Lcu_Ip_LogicOutputConfigType LogicOutput3CfgPB =
{
    /* boolean EnDebugMode   */ (boolean)FALSE,
    /* uint16 LutControl     */ 0X8888U,
    /* uint16 LutRiseFilt    */ 75U,
    /* uint16 LutFallFilt    */ 0U,
    /* boolean EnLutDma      */ (boolean)FALSE,
    /* boolean EnForceDma    */ (boolean)FALSE,
    /* boolean EnLutInt      */ (boolean)FALSE,
    /* boolean EnForceInt    */ (boolean)FALSE,
    /* boolean InvertOutput  */ (boolean)FALSE,
    /* uint8 ForceSignalSel  */ 0U,
    /* uint8 ClearForceMode  */ LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE,
    /* uint8 ForceSyncSel    */ LCU_IP_SYNC_SEL_INPUT0,
};

static const Lcu_Ip_LogicOutputType LogicOutput3PB =
{
    {
        /* uint8 HwInstId               */ LCU_IP_HW_INST_0,
        /* uint8 HwLcOutputId           */ 9U,
        /* Lcu_Ip_Callback IntCallback  */ NULL_PTR,
    },
    &LogicOutput3CfgPB,
};


/* LCU Logic Output Configuration */
static const Lcu_Ip_LogicOutputConfigType LogicOutput4CfgPB =
{
    /* boolean EnDebugMode   */ (boolean)FALSE,
    /* uint16 LutControl     */ 0X7777U,
    /* uint16 LutRiseFilt    */ 75U,
    /* uint16 LutFallFilt    */ 0U,
    /* boolean EnLutDma      */ (boolean)FALSE,
    /* boolean EnForceDma    */ (boolean)FALSE,
    /* boolean EnLutInt      */ (boolean)FALSE,
    /* boolean EnForceInt    */ (boolean)FALSE,
    /* boolean InvertOutput  */ (boolean)FALSE,
    /* uint8 ForceSignalSel  */ 0U,
    /* uint8 ClearForceMode  */ LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE,
    /* uint8 ForceSyncSel    */ LCU_IP_SYNC_SEL_INPUT0,
};

static const Lcu_Ip_LogicOutputType LogicOutput4PB =
{
    {
        /* uint8 HwInstId               */ LCU_IP_HW_INST_0,
        /* uint8 HwLcOutputId           */ 0U,
        /* Lcu_Ip_Callback IntCallback  */ NULL_PTR,
    },
    &LogicOutput4CfgPB,
};


/* LCU Logic Output Configuration */
static const Lcu_Ip_LogicOutputConfigType LogicOutput5CfgPB =
{
    /* boolean EnDebugMode   */ (boolean)FALSE,
    /* uint16 LutControl     */ 0X8888U,
    /* uint16 LutRiseFilt    */ 75U,
    /* uint16 LutFallFilt    */ 0U,
    /* boolean EnLutDma      */ (boolean)FALSE,
    /* boolean EnForceDma    */ (boolean)FALSE,
    /* boolean EnLutInt      */ (boolean)FALSE,
    /* boolean EnForceInt    */ (boolean)FALSE,
    /* boolean InvertOutput  */ (boolean)FALSE,
    /* uint8 ForceSignalSel  */ 0U,
    /* uint8 ClearForceMode  */ LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE,
    /* uint8 ForceSyncSel    */ LCU_IP_SYNC_SEL_INPUT0,
};

static const Lcu_Ip_LogicOutputType LogicOutput5PB =
{
    {
        /* uint8 HwInstId               */ LCU_IP_HW_INST_0,
        /* uint8 HwLcOutputId           */ 1U,
        /* Lcu_Ip_Callback IntCallback  */ NULL_PTR,
    },
    &LogicOutput5CfgPB,
};


/* LCU Logic Output Configuration */
static const Lcu_Ip_LogicOutputConfigType LogicOutput6CfgPB =
{
    /* boolean EnDebugMode   */ (boolean)FALSE,
    /* uint16 LutControl     */ 0X0116U,
    /* uint16 LutRiseFilt    */ 0U,
    /* uint16 LutFallFilt    */ 0U,
    /* boolean EnLutDma      */ (boolean)FALSE,
    /* boolean EnForceDma    */ (boolean)FALSE,
    /* boolean EnLutInt      */ (boolean)FALSE,
    /* boolean EnForceInt    */ (boolean)FALSE,
    /* boolean InvertOutput  */ (boolean)FALSE,
    /* uint8 ForceSignalSel  */ 0U,
    /* uint8 ClearForceMode  */ LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE,
    /* uint8 ForceSyncSel    */ LCU_IP_SYNC_SEL_INPUT0,
};

static const Lcu_Ip_LogicOutputType LogicOutput6PB =
{
    {
        /* uint8 HwInstId               */ LCU_IP_HW_INST_0,
        /* uint8 HwLcOutputId           */ 4U,
        /* Lcu_Ip_Callback IntCallback  */ NULL_PTR,
    },
    &LogicOutput6CfgPB,
};


/* LCU Logic Output Configuration */
static const Lcu_Ip_LogicOutputConfigType LogicOutput7CfgPB =
{
    /* boolean EnDebugMode   */ (boolean)FALSE,
    /* uint16 LutControl     */ 0X0FF0U,
    /* uint16 LutRiseFilt    */ 0U,
    /* uint16 LutFallFilt    */ 0U,
    /* boolean EnLutDma      */ (boolean)FALSE,
    /* boolean EnForceDma    */ (boolean)FALSE,
    /* boolean EnLutInt      */ (boolean)FALSE,
    /* boolean EnForceInt    */ (boolean)FALSE,
    /* boolean InvertOutput  */ (boolean)FALSE,
    /* uint8 ForceSignalSel  */ 0U,
    /* uint8 ClearForceMode  */ LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE,
    /* uint8 ForceSyncSel    */ LCU_IP_SYNC_SEL_INPUT0,
};

static const Lcu_Ip_LogicOutputType LogicOutput7PB =
{
    {
        /* uint8 HwInstId               */ LCU_IP_HW_INST_0,
        /* uint8 HwLcOutputId           */ 10U,
        /* Lcu_Ip_Callback IntCallback  */ NULL_PTR,
    },
    &LogicOutput7CfgPB,
};


/* LCU Logic Output Configuration */
static const Lcu_Ip_LogicOutputConfigType LogicOutput8CfgPB =
{
    /* boolean EnDebugMode   */ (boolean)FALSE,
    /* uint16 LutControl     */ 0XAAAAU,
    /* uint16 LutRiseFilt    */ 5U,
    /* uint16 LutFallFilt    */ 5U,
    /* boolean EnLutDma      */ (boolean)FALSE,
    /* boolean EnForceDma    */ (boolean)FALSE,
    /* boolean EnLutInt      */ (boolean)FALSE,
    /* boolean EnForceInt    */ (boolean)FALSE,
    /* boolean InvertOutput  */ (boolean)FALSE,
    /* uint8 ForceSignalSel  */ 0U,
    /* uint8 ClearForceMode  */ LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE,
    /* uint8 ForceSyncSel    */ LCU_IP_SYNC_SEL_INPUT0,
};

static const Lcu_Ip_LogicOutputType LogicOutput8PB =
{
    {
        /* uint8 HwInstId               */ LCU_IP_HW_INST_1,
        /* uint8 HwLcOutputId           */ 0U,
        /* Lcu_Ip_Callback IntCallback  */ NULL_PTR,
    },
    &LogicOutput8CfgPB,
};


/* LCU Logic Output Configuration */
static const Lcu_Ip_LogicOutputConfigType LogicOutput9CfgPB =
{
    /* boolean EnDebugMode   */ (boolean)FALSE,
    /* uint16 LutControl     */ 0XCCCCU,
    /* uint16 LutRiseFilt    */ 5U,
    /* uint16 LutFallFilt    */ 5U,
    /* boolean EnLutDma      */ (boolean)FALSE,
    /* boolean EnForceDma    */ (boolean)FALSE,
    /* boolean EnLutInt      */ (boolean)FALSE,
    /* boolean EnForceInt    */ (boolean)FALSE,
    /* boolean InvertOutput  */ (boolean)FALSE,
    /* uint8 ForceSignalSel  */ 0U,
    /* uint8 ClearForceMode  */ LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE,
    /* uint8 ForceSyncSel    */ LCU_IP_SYNC_SEL_INPUT0,
};

static const Lcu_Ip_LogicOutputType LogicOutput9PB =
{
    {
        /* uint8 HwInstId               */ LCU_IP_HW_INST_1,
        /* uint8 HwLcOutputId           */ 1U,
        /* Lcu_Ip_Callback IntCallback  */ NULL_PTR,
    },
    &LogicOutput9CfgPB,
};


/* LCU Logic Output Configuration */
static const Lcu_Ip_LogicOutputConfigType LogicOutput10CfgPB =
{
    /* boolean EnDebugMode   */ (boolean)FALSE,
    /* uint16 LutControl     */ 0X4182U,
    /* uint16 LutRiseFilt    */ 4U,
    /* uint16 LutFallFilt    */ 4U,
    /* boolean EnLutDma      */ (boolean)FALSE,
    /* boolean EnForceDma    */ (boolean)FALSE,
    /* boolean EnLutInt      */ (boolean)FALSE,
    /* boolean EnForceInt    */ (boolean)FALSE,
    /* boolean InvertOutput  */ (boolean)FALSE,
    /* uint8 ForceSignalSel  */ 0U,
    /* uint8 ClearForceMode  */ LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE,
    /* uint8 ForceSyncSel    */ LCU_IP_SYNC_SEL_INPUT0,
};

static const Lcu_Ip_LogicOutputType LogicOutput10PB =
{
    {
        /* uint8 HwInstId               */ LCU_IP_HW_INST_1,
        /* uint8 HwLcOutputId           */ 2U,
        /* Lcu_Ip_Callback IntCallback  */ NULL_PTR,
    },
    &LogicOutput10CfgPB,
};


/* LCU Logic Output Configuration */
static const Lcu_Ip_LogicOutputConfigType LogicOutput11CfgPB =
{
    /* boolean EnDebugMode   */ (boolean)FALSE,
    /* uint16 LutControl     */ 0X2814U,
    /* uint16 LutRiseFilt    */ 4U,
    /* uint16 LutFallFilt    */ 4U,
    /* boolean EnLutDma      */ (boolean)FALSE,
    /* boolean EnForceDma    */ (boolean)FALSE,
    /* boolean EnLutInt      */ (boolean)FALSE,
    /* boolean EnForceInt    */ (boolean)FALSE,
    /* boolean InvertOutput  */ (boolean)FALSE,
    /* uint8 ForceSignalSel  */ 0U,
    /* uint8 ClearForceMode  */ LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE,
    /* uint8 ForceSyncSel    */ LCU_IP_SYNC_SEL_INPUT0,
};

static const Lcu_Ip_LogicOutputType LogicOutput11PB =
{
    {
        /* uint8 HwInstId               */ LCU_IP_HW_INST_1,
        /* uint8 HwLcOutputId           */ 3U,
        /* Lcu_Ip_Callback IntCallback  */ NULL_PTR,
    },
    &LogicOutput11CfgPB,
};

static const Lcu_Ip_LogicOutputType * const Lcu_Ip_ppxLogicOutputArrayPB[12U] =
{
    &LogicOutput0PB,
    &LogicOutput1PB,
    &LogicOutput2PB,
    &LogicOutput3PB,
    &LogicOutput4PB,
    &LogicOutput5PB,
    &LogicOutput6PB,
    &LogicOutput7PB,
    &LogicOutput8PB,
    &LogicOutput9PB,
    &LogicOutput10PB,
    &LogicOutput11PB,
};


/* LCU InitType Configuration */
const Lcu_Ip_InitType Lcu_Ip_Sa_xLcuInitPB =
{
    /* Lcu_Ip_HwOutputStateType ** ppxHwOutputStateArray;                       */ &Lcu_Ip_ppxHwOutputStateArrayPB[0],
    /* const Lcu_Ip_LogicInstanceType * const * ppxLogicInstanceConfigArray     */ &Lcu_Ip_ppxLogicInstanceArrayPB[0],
    /* const Lcu_Ip_LogicOutputConfigType * const pxLogicOutputResetConfigArray */ &Lcu_Ip_xLogicOutputResetConfig,
    /* const Lcu_Ip_LogicInputConfigType * const pxLogicInputResetConfigArray   */ &Lcu_Ip_xLogicInputResetConfig,
    /* const Lcu_Ip_LogicOutputType * const * ppxLogicOutputConfigArray         */ &Lcu_Ip_ppxLogicOutputArrayPB[0],
    /* const Lcu_Ip_LogicInputType * const * ppxLogicInputConfigArray           */ &Lcu_Ip_ppxLogicInputArrayPB[0],
    /* const uint8 NumOfLogicInstance                                           */ 2U,
    /* const uint8 NumOfLogicInput                                              */ 16U,
    /* const uint8 NumOfLogicOutput                                             */ 12U,
};

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref LCU_IP_SA_PBCFG_C_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"


#ifdef __cplusplus
}
#endif

