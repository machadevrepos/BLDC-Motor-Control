/*==================================================================================================
*   Project              : RTD AUTOSAR 4.9 
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
*   Dependencies         : none
*
*   Autosar Version      : 4.9.0
*   Autosar Revision     : ASR_REL_4_9_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 7.0.0
*   Build Version        : S32K3_S32M27x_Real-Time_Drivers_AUTOSAR_R23-11_Version_7_0_0_QLP03_D2512_ASR_REL_4_9_REV_0000_20251210
*
*   Copyright 2020 - 2025 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file      Tspc_Port_Ip_Cfg.h
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Tspc_Port_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TSPC_PORT_IP_VENDOR_ID_CFG_C                       43
#define TSPC_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_C        4
#define TSPC_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_C        9
#define TSPC_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_C     0
#define TSPC_PORT_IP_SW_MAJOR_VERSION_CFG_C                7
#define TSPC_PORT_IP_SW_MINOR_VERSION_CFG_C                0
#define TSPC_PORT_IP_SW_PATCH_VERSION_CFG_C                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Tspc_Port_Ip_Cfg.c and Tspc_Port_Ip_Cfg.h are of the same vendor */
#if (TSPC_PORT_IP_VENDOR_ID_CFG_C != TSPC_PORT_IP_VENDOR_ID_CFG_H)
    #error "Tspc_Port_Ip_Cfg.c and Tspc_Port_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Tspc_Port_Ip_Cfg.c and Tspc_Port_Ip_Cfg.h are of the same Autosar version */
#if ((TSPC_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_C    != TSPC_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
    (TSPC_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_C    != TSPC_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
    (TSPC_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_C != TSPC_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Tspc_Port_Ip_Cfg.c and Tspc_Port_Ip_Cfg.h are different"
#endif
/* Check if Tspc_Port_Ip_Cfg.c and Tspc_Port_Ip_Cfg.h are of the same Software version */
#if ((TSPC_PORT_IP_SW_MAJOR_VERSION_CFG_C != TSPC_PORT_IP_SW_MAJOR_VERSION_CFG_H) || \
    (TSPC_PORT_IP_SW_MINOR_VERSION_CFG_C != TSPC_PORT_IP_SW_MINOR_VERSION_CFG_H) || \
    (TSPC_PORT_IP_SW_PATCH_VERSION_CFG_C != TSPC_PORT_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Tspc_Port_Ip_Cfg.c and Tspc_Port_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                             LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                             LOCAL MACROS
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

/* clang-format off */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
PortContainer_0_BOARD_InitPeripherals:
- options: {callFromInitBoot: 'true', coreID: M7_0}
- pin_list:
  - {pin_num: '83', peripheral: LCU0, signal: lcu0_out0, pin_signal: PTC11}
  - {pin_num: '82', peripheral: LCU0, signal: lcu0_out1, pin_signal: PTC10}
  - {pin_num: '66', peripheral: LCU0, signal: lcu0_out2, pin_signal: PTA3}
  - {pin_num: '88', peripheral: LCU0, signal: lcu0_out3, pin_signal: PTA2}
  - {pin_num: '73', peripheral: LCU0, signal: lcu0_out8, pin_signal: PTB11}
  - {pin_num: '72', peripheral: LCU0, signal: lcu0_out9, pin_signal: PTB10}
  - {pin_num: '67', peripheral: ADC1, signal: adc1_s18, pin_signal: PTA6}
  - {pin_num: '75', peripheral: ADC1, signal: adc1_s8, pin_signal: PTB13}
  - {pin_num: '79', peripheral: LPSPI1, signal: lpspi1_pcs3, pin_signal: PTB17, direction: OUTPUT}
  - {pin_num: '77', peripheral: LPSPI1, signal: lpspi1_sin, pin_signal: PTB15, direction: INPUT}
  - {pin_num: '76', peripheral: LPSPI1, signal: lpspi1_sck, pin_signal: PTB14, direction: OUTPUT}
  - {pin_num: '78', peripheral: LPSPI1, signal: lpspi1_sout, pin_signal: PTB16, direction: OUTPUT}
  - {pin_num: '36', peripheral: LPUART0, signal: lpuart0_rx, pin_signal: PTC2}
  - {pin_num: '35', peripheral: LPUART0, signal: lpuart0_tx, pin_signal: PTC3, direction: OUTPUT}
  - {pin_num: '19', peripheral: TRGMUX, signal: trgmux_out6, pin_signal: PTE15}
  - {pin_num: '18', peripheral: TRGMUX, signal: trgmux_out7, pin_signal: PTE16}
  - {pin_num: '20', peripheral: TRGMUX, signal: trgmux_in6, pin_signal: PTD1, inputBufferEnable: enabled}
  - {pin_num: '22', peripheral: TRGMUX, signal: trgmux_in8, pin_signal: PTE11}
  - {pin_num: '16', peripheral: SYSTEM, signal: reset_b, pin_signal: PTA5, direction: INPUT/OUTPUT}
  - {pin_num: '85', peripheral: SIUL2, signal: 'eirq, 11', pin_signal: PTD3}
  - {pin_num: '31', peripheral: SIUL2, signal: 'gpio, 112', pin_signal: PTD16, identifier: TST_GPIO_D16, direction: OUTPUT}
  - {pin_num: '10', peripheral: SIUL2, signal: 'gpio, 15', pin_signal: PTA15, direction: INPUT}
  - {pin_num: '21', peripheral: SIUL2, signal: 'gpio, 96', pin_signal: PTD0, direction: INPUT}
  - {pin_num: '32', peripheral: SIUL2, signal: 'gpio, 111', pin_signal: PTD15, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* No registers that support TSPC were configured*/

/*==================================================================================================
                                      LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                           LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                           GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
