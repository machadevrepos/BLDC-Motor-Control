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

#ifndef SIUL2_ICU_IP_TYPES
#define SIUL2_ICU_IP_TYPES

/**
 *     @file
 *
 *     @addtogroup siul2_icu_ip SIUL2 IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Siul2_Icu_Ip_Defines.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IP_TYPES_VENDOR_ID                   43
#define SIUL2_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION    4
#define SIUL2_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION    9
#define SIUL2_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION 0
#define SIUL2_ICU_IP_TYPES_SW_MAJOR_VERSION            7
#define SIUL2_ICU_IP_TYPES_SW_MINOR_VERSION            0
#define SIUL2_ICU_IP_TYPES_SW_PATCH_VERSION            0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IP_TYPES_VENDOR_ID != SIUL2_ICU_IP_DEFINES_VENDOR_ID)
    #error "Siul2_Icu_Ip_Types.h and Siul2_Icu_Ip_Defines.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION  != SIUL2_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION  != SIUL2_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION   != SIUL2_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_Types.h and Siul2_Icu_Ip_Defines.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IP_TYPES_SW_MAJOR_VERSION  != SIUL2_ICU_IP_DEFINES_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_TYPES_SW_MINOR_VERSION  != SIUL2_ICU_IP_DEFINES_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_TYPES_SW_PATCH_VERSION  != SIUL2_ICU_IP_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Siul2_Icu_Ip_Types.h and Siul2_Icu_Ip_Defines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
#if (STD_ON == SIUL2_ICU_IP_USED)

#if (SIUL2_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
/**
 * @enum Siul2_Icu_Ip_ClockModeType
 * @brief Defines the clock mode type for SIUL2 channels.
 * @details This enumeration specifies the prescaler type for SIUL2:
 *          normal clock mode or alternate clock mode for dual clock functionality.
 */
typedef enum
{
    SIUL2_ICU_NORMAL_CLK        = 0x0U,  /**< @brief Normal prescaler         */
    SIUL2_ICU_ALTERNATE_CLK     = 0x1U,  /**< @brief Alternate prescaler      */
} Siul2_Icu_Ip_ClockModeType;
#endif

/**
 * @enum Siul2_Icu_Ip_EdgeType
 * @brief Defines the edge detection type for SIUL2 channels.
 * @details This enumeration specifies the activation type for interrupts on SIUL2 channels:
 *          disable, rising edge, falling edge, or both edges detection.
 */
typedef enum
{
    SIUL2_ICU_DISABLE           = 0x0U,  /**< @brief Interrupt disable.         */
    SIUL2_ICU_RISING_EDGE       = 0x1U,  /**< @brief Interrupt on rising edge.  */
    SIUL2_ICU_FALLING_EDGE      = 0x2U,  /**< @brief Interrupt on falling edge. */
    SIUL2_ICU_BOTH_EDGES        = 0x3U   /**< @brief Interrupt on either edge.  */
} Siul2_Icu_Ip_EdgeType;

/**
 * @enum Siul2_Icu_Ip_StatusType
 * @brief Defines the operation status type for SIUL2 layer functions.
 * @details This enumeration represents the execution status returned by SIUL2 APIs.
 *          It indicates whether the requested operation completed successfully or encountered an error
 *          during execution.
 */
typedef enum
{
    SIUL2_ICU_IP_SUCCESS     = 0x0U, /**< @brief Status for success operation return. */
    SIUL2_ICU_IP_ERROR       = 0x1U  /**< @brief General error return status.         */
}Siul2_Icu_Ip_StatusType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @typedef Siul2_Icu_Ip_NotifyType
 * @brief Function pointer type for notification callbacks.
 * @details The notification functions shall have no parameters and no return value.
 */
typedef void (*Siul2_Icu_Ip_NotifyType)(void);

/**
 * @typedef Siul2_Icu_Ip_CallbackType
 * @brief Function pointer type for interrupt callbacks.
 * @details Callback signature used for each channel with an active interrupt.
 *          It receives two parameters: a 16-bit value and a boolean flag.
 */
typedef void (*Siul2_Icu_Ip_CallbackType)(uint16 callbackParam1, boolean callbackParam2);

/**
 * @struct Siul2_Icu_Ip_ChannelConfigType
 * @brief Defines the channel configuration structure for SIUL2.
 * @details This structure contains all configuration parameters for a SIUL2 channel:
 *          hardware channel index, digital filter settings, edge detection type,
 *          callback functions, and notification parameters.
 */
typedef struct
{
    uint8                           hwChannel;      /**< @brief The interrupt pin index                      */
    boolean                         digFilterEn;    /**< @brief Enables digital filter                       */
    uint8                           maxFilterCnt;   /**< @brief Maximum interrupt filter value               */
    Siul2_Icu_Ip_EdgeType           intEdgeSel;     /**< @brief The type of edge event                       */
    Siul2_Icu_Ip_CallbackType       callback;       /**< @brief Pointer to the callback function.            */
    Siul2_Icu_Ip_NotifyType         Siul2ChannelNotification; /**< @brief The notification functions shall have no parameters and no return value.*/
    uint8                           callbackParam;            /**< @brief The logic channel for which callback is set. */
} Siul2_Icu_Ip_ChannelConfigType;

/**
 * @struct Siul2_Icu_Ip_InstanceConfigType
 * @brief Defines the instance configuration structure for SIUL2.
 * @details This structure contains the clock prescaler configuration parameters for SIUL2 instance:
 *          normal interrupt filter clock and alternate interrupt filter clock settings.
 */
typedef struct
{
    uint8                           intFilterClk;       /**< @brief Siul2 interrupt clock prescaller digital filter */
    uint8                           altIntFilterClk;    /**< @brief Siul2 interrupt clock prescaller digital filter */
} Siul2_Icu_Ip_InstanceConfigType;

/**
 * @struct Siul2_Icu_Ip_State
 * @brief Defines the state structure for SIUL2 internal logic.
 * @details This structure contains the runtime state information for SIUL2 channels:
 *          initialization status, callback functions, notification settings, and channel parameters
 *          used by the IPL driver for internal state management.
 */
typedef struct
{
    boolean                   chInit;                   /**< @brief Initialization state. */
    Siul2_Icu_Ip_CallbackType callback;                 /**< @brief Pointer to the callback function. */
    Siul2_Icu_Ip_NotifyType   Siul2ChannelNotification; /**< @brief The notification functions for SIGNAL_EDGE_DETECT mode. */
    uint16                    callbackParam;            /**< @brief The logic channel for which callback is set. */
    boolean                   notificationEnable;       /**< @brief State of the notification. */
} Siul2_Icu_Ip_State;


/**
 * @struct Siul2_Icu_Ip_ConfigType
 * @brief Defines the main configuration structure for SIUL2 layer.
 * @details This structure contains the complete configuration for SIUL2 driver:
 *          number of channels, instance configuration, and channel-specific configurations
 *          for driver initialization and operation.
 */
typedef struct
{
    uint8                                   numChannels;            /**< @brief Number of channels in the configuration. */
#if (STD_ON == SIUL2_ICU_IP_VIRTWRAPPER_SUPPORT)
    uint8                                   interruptPdacSlot;      /**< @brief Configures Siul2 Interrupt PDAC Slot for VirtWrapper. */
#endif
    const Siul2_Icu_Ip_InstanceConfigType   *pInstanceConfig;       /**< @brief Pointer to the instance configuration.   */
    const Siul2_Icu_Ip_ChannelConfigType    (*pChannelsConfig)[];   /**< @brief Pointer to the channels configuration.   */
} Siul2_Icu_Ip_ConfigType;

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_TYPES */
