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

/**
*   @file
*
*   @addtogroup HVM_DRIVER HVM Driver
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
#include "Hvm_Ip_Hw_Access.h"
#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HVM_IP_HW_ACCESS_VENDOR_ID_C                      43
#define HVM_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define HVM_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C       9
#define HVM_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define HVM_IP_HW_ACCESS_SW_MAJOR_VERSION_C               7
#define HVM_IP_HW_ACCESS_SW_MINOR_VERSION_C               0
#define HVM_IP_HW_ACCESS_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Hvm_Ip_Hw_Access.h */
#if (HVM_IP_HW_ACCESS_VENDOR_ID_C != HVM_IP_HW_ACCESS_VENDOR_ID)
    #error "Hvm_Ip_Hw_Access.c and Hvm_Ip_Hw_Access.h have different vendor ids"
#endif
#if ((HVM_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != HVM_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (HVM_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C    != HVM_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (HVM_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C != HVM_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip_Hw_Access.c and Hvm_Ip_Hw_Access.h are different"
#endif
#if ((HVM_IP_HW_ACCESS_SW_MAJOR_VERSION_C != HVM_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (HVM_IP_HW_ACCESS_SW_MINOR_VERSION_C != HVM_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (HVM_IP_HW_ACCESS_SW_PATCH_VERSION_C != HVM_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip_Hw_Access.c and Hvm_Ip_Hw_Access.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against OsIf.h */
    #if (( HVM_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        ( HVM_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C     != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Hvm_Ip_Hw_Access.c and OsIf.h are different"
    #endif
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/* Maximum timeout value that can be configured on the interface. */
#define HVM_IP_UINT32_MAX_VALUE                          (0xFFFFFFFFU)
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

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
#if(defined(HVM_IP_YOUNG_FELLOW) && (STD_ON != HVM_IP_YOUNG_FELLOW))
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

/*!
 * @brief Initializes a starting reference point for timeout
 *
 * @param[out] StartTimeOut    The starting time from which elapsed time is measured
 * @param[out] ElapsedTimeOut  The elapsed time to be passed to HVM_TimeoutExpired
 * @param[out] TimeoutTicksOut The timeout value (in ticks) to be passed to HVM_TimeoutExpired
 * @param[in]  TimeoutUs       The timeout value (in microseconds)
 */
void HVM_StartTimeout(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs)
{
    *StartTimeOut    = OsIf_GetCounter(HVM_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, HVM_TIMEOUT_TYPE);
}

/*!
 * @brief Checks for timeout condition.
 *
 * @param[in,out] StartTimeInOut    The starting time from which elapsed time is measured
 * @param[in,out] ElapsedTimeInOut  The accumulated elapsed time from the starting time reference
 * @param[in]     TimeoutTicks      The timeout limit (in ticks)
 */
boolean HVM_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks)
{
    boolean RetVal = FALSE;
    uint32 u32Elapsed = OsIf_GetElapsed(StartTimeInOut, HVM_TIMEOUT_TYPE);

    /* Prevent overflow before addition */
    if ((HVM_IP_UINT32_MAX_VALUE - *ElapsedTimeInOut) < u32Elapsed)
    {
        /* Assign to maximum value */
        *ElapsedTimeInOut = HVM_IP_UINT32_MAX_VALUE;
    }
    else
    {
        *ElapsedTimeInOut += u32Elapsed;
    }

    if (*ElapsedTimeInOut >= TimeoutTicks)
    {
        RetVal = TRUE;
    }
    return RetVal;
}

#if (STD_OFF == HVM_CONTROL_CALLBACK_FUNC)
/**
 * @brief Empty Callback function.
 * @implements Hvm_Ip_ReportEventsCallback_Activity
 */
void Hvm_Ip_ReportEventsCallback(uint8 Instance, Hvm_Ip_OutputStatusType Event)
{
    /* No implementation */
    (void)Instance;
    (void)Event;
}
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/


#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"

#endif

#ifdef __cplusplus
}
#endif
/** @} */
