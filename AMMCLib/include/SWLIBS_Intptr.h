/******************************************************************************
*
*   Copyright 2025-2026 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms.  By expressly accepting such
*   terms or by downloading, installing, activating and/or otherwise using the software, you are
*   agreeing that you have read, and that you agree to comply with and are bound by, such license
*   terms. If you do not agree to be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
******************************************************************************/
/**
*
* @file     SWLIBS_Intptr.h
*
* @brief    Provides conversion routines for pointers.
*
*******************************************************************************
*
******************************************************************************/

#ifndef SWLIBS_INTPTR_H
#define SWLIBS_INTPTR_H


#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"

/******************************************************************************
* Inline functions
******************************************************************************/
  /* Cast of pointer to unsigned integer of appropriate size */
  SWLIBS_INLINE tU32 SWLIBS_uintptr(const void *pIn)
  {
    return((tU32)pIn);
  }
  /* Cast of pointer to signed integer of appropriate size */
  SWLIBS_INLINE tS32 SWLIBS_intptr(const void *pIn)
  {
    return((tS32)pIn);
  }
#endif /* SWLIBS_INTPTR_H */
