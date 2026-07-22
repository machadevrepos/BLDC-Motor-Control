/*==================================================================================================
*   Project              : RTD AUTOSAR 4.9
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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

#ifndef SIUL2_ICU_IP_H
#define SIUL2_ICU_IP_H

/**
 *     @file
 *
 *     @addtogroup siul2_icu_ip SIUL2 IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Siul2_Icu_Ip_Cfg.h"

#if (STD_ON == SIUL2_ICU_IP_USED)
    #if (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT)
        #include "Reg_eSys.h"
    #endif
#endif /* SIUL2_ICU_IP_USED */
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IP_VENDOR_ID                    43
#define SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION     4
#define SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION     9
#define SIUL2_ICU_IP_AR_RELEASE_REVISION_VERSION  0
#define SIUL2_ICU_IP_SW_MAJOR_VERSION             7
#define SIUL2_ICU_IP_SW_MINOR_VERSION             0
#define SIUL2_ICU_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IP_VENDOR_ID != SIUL2_ICU_IP_CFG_VENDOR_ID)
    #error "Siul2_Icu_Ip.h and Siul2_Icu_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION  != SIUL2_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION  != SIUL2_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_AR_RELEASE_REVISION_VERSION   != SIUL2_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip.h and Siul2_Icu_Ip_Cfg.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IP_SW_MAJOR_VERSION  != SIUL2_ICU_IP_CFG_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_SW_MINOR_VERSION  != SIUL2_ICU_IP_CFG_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_SW_PATCH_VERSION  != SIUL2_ICU_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Siul2_Icu_Ip.h and Siul2_Icu_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == SIUL2_ICU_IP_USED)
        #if (SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
        /* Check if header file and Reg_eSys.h file are of the same Autosar version */
            #if ((SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
                (SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Siul2_Icu_Ip.h and Reg_eSys.h are different"
            #endif
        #endif
    #endif /* SIUL2_ICU_IP_USED */
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
#if (STD_ON == SIUL2_ICU_IP_USED)

#if (defined SIUL2_ICU_CONFIG_EXT)
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/* Macro used to import SIUL2 PB generated configurations. */
SIUL2_ICU_CONFIG_EXT

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
#endif /* defined SIUL2_ICU_CONFIG_EXT */
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ICU_START_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

/* Table of base addresses for SUIL2 instances. */
#if(SIUL2_ICU_IP_VIRTWRAPPER_SUPPORT == STD_ON)
extern SIUL2_Type * const Siul2_Icu_Ip_apxBase[][SIUL2_ICU_IP_NUM_PDAC_SLOT];
#else
extern SIUL2_Type * const Siul2_Icu_Ip_apxBase[];
#endif

#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

#if (SIUL2_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_INIT_8_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_INIT_8
#endif
#include "Icu_MemMap.h"
/* This array stores the positions in the Siul2_Icu_Ip_axChannelState array of the configured Siul2 channels. */
extern uint8 Siul2_Icu_Ip_au8IndexInChState[SIUL2_ICU_IP_NUM_OF_INSTANCES][SIUL2_ICU_IP_NUM_OF_CHANNELS];
#if (SIUL2_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_INIT_8
#endif
#include "Icu_MemMap.h"

#if (SIUL2_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"
/* Store channel state for each SIUL2. */
extern Siul2_Icu_Ip_State Siul2_Icu_Ip_axChannelState[SIUL2_ICU_IP_NUM_OF_CHANNELS_USED];
#if (SIUL2_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"

#if (SIUL2_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_8
#endif
#include "Icu_MemMap.h"
#if (SIUL2_ICU_IP_VIRTWRAPPER_SUPPORT == STD_ON)
/* PDAC slot index for each SIUL2 instance in Virtual Wrapper mode */
extern uint8 Siul2_Icu_Ip_au8InterruptPdacSlot[SIUL2_ICU_IP_NUM_OF_INSTANCES];
#endif
#if (SIUL2_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_8
#endif
#include "Icu_MemMap.h"
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#if (SIUL2_ICU_IP_DEINIT_API == STD_ON)
/**
 * @brief      Deinitialize SIUL2 ICU IP instance
 * @details    Resets all configured channels for the specified SIUL2 instance to their default state.
 *             Disables interrupts, clears registers, and resets channel state information.
 *
 * @param[in]  instance - SIUL2 hardware instance number
 *
 * @return     Siul2_Icu_Ip_StatusType
 * @retval     SIUL2_ICU_IP_SUCCESS - Deinitialization completed successfully
 * @retval     SIUL2_ICU_IP_ERROR   - Deinitialization failed
 *
 */
Siul2_Icu_Ip_StatusType Siul2_Icu_Ip_DeInit(uint8 instance);
#endif /* SIUL2_ICU_IP_DEINIT_API == STD_ON */

/**
 * @brief      Driver function that initializes SIUL2 hardware instance.
 * @details    This function:
 *              - Configures interrupt filter clock prescaler
 *              - Sets up channel callbacks and notifications
 *              - Configures interrupt filter maximum counter
 *              - Sets digital filter enable/disable
 *              - Sets activation condition (rising/falling/both edges)
 *              - Clears interrupt flags
 *              - Initially disables interrupts for all channels
 *              - Marks channels as initialized
 *
 * @param[in]  instance   - Hardware instance of SIUL2 used.
 * @param[in]  userConfig - Pointer to instance configuration structure.
 *
 * @return     Siul2_Icu_Ip_StatusType - The status of initialization
 *
 */
Siul2_Icu_Ip_StatusType Siul2_Icu_Ip_Init(uint8 instance, const Siul2_Icu_Ip_ConfigType* userConfig);

/**
 * @brief      Driver function that sets activation condition for SIUL2 hardware channel.
 * @details    This function enables the requested activation condition(rising, falling or
 *             both edges) for corresponding SIUL2 channels.
 *
 * @param[in]  instance   Hardware instance of SIUL2 used.
 * @param[in]  hwChannel  Hardware channel of SIUL2 used.
 * @param[in]  edge       Edge activation type used.
 *
 * @return     void
 *
 */
void Siul2_Icu_Ip_SetActivationCondition(uint8 instance, uint8 hwChannel, Siul2_Icu_Ip_EdgeType edge);

#if (SIUL2_ICU_IP_GET_INPUT_STATE_API == STD_ON)
/**
 * @brief      ICU driver function that gets input state of SIUL2 channel.
 * @details    This function checks if an interrupt condition has been activated for the
 *             corresponding SIUL2 channel when interrupt is disabled. It reads the interrupt
 *             status flag and clears it if found active.
 *
 * @param[in]  instance   - Hardware instance of SIUL2 used.
 * @param[in]  hwChannel  - Hardware channel of SIUL2 used.
 *
 * @return     boolean - Input state.
 * @retval     TRUE    - Interrupt was detected while interrupt enable bit was not set and
 *                       the pending interrupt flag was cleared
 * @retval     FALSE   - No interrupt condition or interrupt is enabled
 *
 */
boolean Siul2_Icu_Ip_GetInputState(uint8 instance, uint8 hwChannel);
#endif  /* SIUL2_ICU_IP_GET_INPUT_STATE_API */

/**
 * @brief      ICU driver function that enables interrupt for SIUL2 hardware channel.
 * @details    This function:
 *             - Clears any pending interrupt flag in DISR0 register
 *             - Sets the corresponding bit in DIRER0 register to enable interrupt
 *
 * @param[in]  instance   - Hardware instance of SIUL2 used.
 * @param[in]  hwChannel  - Hardware channel of SIUL2 used.
 *
 * @return     void
 *
 */
void Siul2_Icu_Ip_EnableInterrupt(uint8 instance, uint8 hwChannel);

/**
 * @brief      ICU driver function that disables interrupt for SIUL2 hardware channel.
 * @details    This function:
 *             - Clears the corresponding bit in DIRER0 register to disable interrupt
 *             - Clears any pending interrupt flag in DISR0 register
 *
 * @param[in]  - instance   Hardware instance of SIUL2 used.
 * @param[in]  - hwChannel  Hardware channel of SIUL2 used.
 *
 * @return     void
 *
 */
void Siul2_Icu_Ip_DisableInterrupt(uint8 instance, uint8 hwChannel);

#if (SIUL2_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
/**
 * @brief      Icu driver function used to set the clock mode of a SIUL2 module.
 * @details    This function:
 *             - Selects between normal and alternate clock prescaler values
 *             - Sets IFCPR register with the corresponding prescaler value
 *
 * @param[in]  instance   - Hardware instance of SIUL2 used.
 * @param[in]  mode       - Clock mode type (normal or alternate) for the SIUL2 module.
 *
 * @return     void
 *
 */
void Siul2_Icu_Ip_SetClockMode(uint8 instance, Siul2_Icu_Ip_ClockModeType mode);
#endif  /* SIUL2_ICU_IP_DUAL_CLOCK_MODE_API */

/**
 * @brief      ICU driver function that enables notification for SIUL2 hardware channel.
 * @details    This function:
 *             - Sets the notification Enable to TRUE
 *             - Allows calling notification function when an interrupt occurs
 *
 * @param[in]  instance   - Hardware instance of SIUL2 used.
 * @param[in]  hwChannel  - Hardware channel of SIUL2 used.
 *
 * @return     void
 *
 */
void Siul2_Icu_Ip_EnableNotification(uint8 instance, uint8 hwChannel);

/**
 * @brief      ICU driver function that disables notification for SIUL2 hardware channel.
 * @details    This function:
 *             - Sets the notification Enable to FALSE
 *             - Do not Allow calling notification function when an interrupt occurs
 *
 * @param[in]  instance   - Hardware instance of SIUL2 used.
 * @param[in]  hwChannel  - Hardware channel of SIUL2 used.
 *
 * @return     void
 *
 */
void Siul2_Icu_Ip_DisableNotification(uint8 instance, uint8 hwChannel);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_H */
