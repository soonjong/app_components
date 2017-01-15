/*******************************************************************************
 * @file		app_common_def.h
 * @brief		define common definition for all related sapplications
 * @version		0.1
 * @warning		file fmt - unix, encoding fmt: ANSI
 * @instruct.	It is not allowed to change this file arbitrarily
 *					without permission.
 *				If you have a good way to change to a better direction,
 *					please contact me.
 * @author		Jin, Soonjong (soonjong.jin@gmail.com)
 * @date		revision history
 *				2017.01/07 - v0.1: files is created by Jin, Soonjong
 ******************************************************************************/
#ifndef _APP_COMMON_DEF_H_
#define _APP_COMMON_DEF_H_
/*******************************************************************************
 * including header files
 ******************************************************************************/
#include "app_common_info.h"
/*******************************************************************************
 * global common definitions
 ******************************************************************************/

/*************/
/* YES or NO */
/*************/
#ifndef NO
#define NO (0)
#elif (0 != NO)
#undef NO
#define NO (0)
#endif

#ifndef YES
#define YES (1)
#elif (1 != YES)
#undef YES
#define YES (1)
#endif

/*****************/
/* platform mode */
/*****************/
#ifndef APP_OS_PLATFORM_MAX
#define APP_OS_PLATFORM_WINDOWS     (0)
#define APP_OS_PLATFORM_LINUX       (1)
#define APP_OS_PLATFORM_ARM         (2)
#define APP_OS_PLATFORM_COMMON		(3)
#define APP_OS_PLATFORM_MAX         (4)
#endif

/**************************/
/* camera sequence format */
/**************************/
#ifndef APP_CMR_SEQ_FMT_MAX
#define APP_CMR_SEQ_FMT_YUV422_ITRV_OYUYV		(0)
#define APP_CMR_SEQ_FMT_YUV422_ITRV_OYVYU		(1)
#define APP_CMR_SEQ_FMT_YUV422_ITRV_OUYVY		(2)
#define APP_CMR_SEQ_FMT_YUV422_ITRV_OVYUY		(3)
#define APP_CMR_SEQ_FMT_YUV422_PLNR_OYUV		(4)
#define APP_CMR_SEQ_FMT_YUV420_PLNR_OYUV		(5)
#define APP_CMR_SEQ_FMT_YUV444_ITRV_OYUV		(6)
#define APP_CMR_SEQ_FMT_YUV444_PLNR_OYUV		(7)
#define APP_CMR_SEQ_FMT_RGB444_ITRV_OBGR		(8)
#define APP_CMR_SEQ_FMT_RGB444_PLNR_OBGR		(9)
#define APP_CMR_SEQ_FMT_RGB444_ITRV_ORGB		(10)
#define APP_CMR_SEQ_FMT_RGB444_PLNR_ORGB		(11)
#define APP_CMR_SEQ_FMT_MAX						(12)
#endif

/*******************************************************************************
 * END OF FILE
 ******************************************************************************/
#endif
