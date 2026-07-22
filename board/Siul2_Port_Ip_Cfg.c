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
*   @file      Siul2_Port_Ip_Cfg.h
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
#include "Siul2_Port_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_VENDOR_ID_CFG_C                       43
#define SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_C        4
#define SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_C        9
#define SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_C     0
#define SIUL2_PORT_IP_SW_MAJOR_VERSION_CFG_C                7
#define SIUL2_PORT_IP_SW_MINOR_VERSION_CFG_C                0
#define SIUL2_PORT_IP_SW_PATCH_VERSION_CFG_C                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Siul2_Port_Ip_Cfg.c and Siul2_Port_Ip_Cfg.h are of the same vendor */
#if (SIUL2_PORT_IP_VENDOR_ID_CFG_C != SIUL2_PORT_IP_VENDOR_ID_CFG_H)
    #error "Siul2_Port_Ip_Cfg.c and Siul2_Port_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Siul2_Port_Ip_Cfg.c and Siul2_Port_Ip_Cfg.h are of the same Autosar version */
#if ((SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_C    != SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
    (SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_C    != SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
    (SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_C != SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Siul2_Port_Ip_Cfg.c and Siul2_Port_Ip_Cfg.h are different"
#endif
/* Check if Siul2_Port_Ip_Cfg.c and Siul2_Port_Ip_Cfg.h are of the same Software version */
#if ((SIUL2_PORT_IP_SW_MAJOR_VERSION_CFG_C != SIUL2_PORT_IP_SW_MAJOR_VERSION_CFG_H) || \
    (SIUL2_PORT_IP_SW_MINOR_VERSION_CFG_C != SIUL2_PORT_IP_SW_MINOR_VERSION_CFG_H) || \
    (SIUL2_PORT_IP_SW_PATCH_VERSION_CFG_C != SIUL2_PORT_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Siul2_Port_Ip_Cfg.c and Siul2_Port_Ip_Cfg.h are different"
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

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*! @brief Array of pin configuration structures */
const Siul2_Port_Ip_PinSettingsConfig g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals[NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals] =
{
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 75u,
        .mux                         = PORT_MUX_ALT8,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 74u,
        .mux                         = PORT_MUX_ALT8,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 3u,
        .mux                         = PORT_MUX_ALT4,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 2u,
        .mux                         = PORT_MUX_ALT6,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 43u,
        .mux                         = PORT_MUX_ALT5,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 42u,
        .mux                         = PORT_MUX_ALT6,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 6u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 45u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 49u,
        .mux                         = PORT_MUX_ALT3,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 47u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .inputMuxReg                 = {
                                         239u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT1,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 46u,
        .mux                         = PORT_MUX_ALT3,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 48u,
        .mux                         = PORT_MUX_ALT3,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 66u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_SLOWEST,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .inputMuxReg                 = {
                                         187u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT3,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 67u,
        .mux                         = PORT_MUX_ALT4,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_SLOWEST,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 143u,
        .mux                         = PORT_MUX_ALT7,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 144u,
        .mux                         = PORT_MUX_ALT7,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 97u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .inputMuxReg                 = {
                                         350u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 139u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .inputMuxReg                 = {
                                         352u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 5u,
        .mux                         = PORT_MUX_ALT7,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 99u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .inputMuxReg                 = {
                                         27u
                                       },
        .inputMux                    = { 
                                         PORT_INPUT_MUX_ALT3,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 2u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 112u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 0u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 15u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 0u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 96u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_NOT_AVAILABLE,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
        .initValue                   = 0u
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 111u,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_NOT_AVAILABLE,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_FASTEST,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = { MUX_MODE_NOT_AVAILABLE, MUX_MODE_NOT_AVAILABLE },
        .initValue                   = 0u
    },
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

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
