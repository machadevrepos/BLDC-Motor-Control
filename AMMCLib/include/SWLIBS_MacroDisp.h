/******************************************************************************
*
*   Copyright 2013-2015 Freescale Semiconductor
*   Copyright 2016-2023 NXP
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
* @file     SWLIBS_MacroDisp.h
*
* @brief    AMMCLIB dispatcher header file.
*
******************************************************************************/


#ifndef SWLIBS_MACRODISP_H_
#define SWLIBS_MACRODISP_H_

#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define _ARG2(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25,...) _25
  #define VA_NUM_ARGS(...) _ARG2(__VA_ARGS__,25, 24 ,23 ,22 ,21 ,20 ,19 ,18 ,17 ,16 ,15 ,14 ,13, 12 , 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
  #define macro_dispatcher(func, ...) macro_dispatcher_(func, VA_NUM_ARGS(__VA_ARGS__))
  #define macro_dispatcher_(func, nargs) macro_dispatcher__(func, nargs)
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */
#define macro_dispatcher__(func, nargs) func##_Dsptchr_## nargs


#endif /* SWLIBS_MACRODISP_H_ */
