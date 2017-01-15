/*******************************************************************************
 :* @file		app_common_para_def.h
 * @brief		global common parameter definition for all applications
 * @version		0.1
 * @warning		file fmt - unix, encoding fmt: ANSI
 * @instruct.	It is not allowed to change this file arbitrarily
 *					without permission.
 *				If you have a good way to change to a better direction,
 *					please contact me.
 * @author		Jin, Soonjong (soonjong.jin@gmail.com)
 * @date		revision history
 *				2017.01/04 - v0.1: files is created by Jin, Soonjong
 ******************************************************************************/
#ifndef _APP_COMMON_PARA_DEF_H_
#define _APP_COMMON_PARA_DEF_H_
/*******************************************************************************
 * including header files
 ******************************************************************************/
#include "app_common_def.h"
/*******************************************************************************
 * global common parameters
 ******************************************************************************/

/***************************/
/* User defined parameters */
/***************************/

/*	If you want to show large amounts of text information on the screen, set the option "SHOW_VERBOSE" to (YES). 
	If you set it to (NO), you can see only simple/essential information. 
	On other OS platforms except windows and linux, it is automatically set to (NO) even if you set it to (YES) because of its high complexity to show.
	If you want to display all information (even if it is inconvenient and uncontrollable) on a platform other than windows and linux, disable the next option at the bottom of this file (That part is near "check verbose definition").
*/
#define SHOW_VERBOSE       			(YES)



/*	Set the option "USE_NEON_COPROCESSOR" to (YES) if you want to use the neon parallel processor on the ARM platform, or if you want to verify the neon code on windows or linux platforms by simulation.
	If it is an arm platform without neon parallel processor, set it to (NO).
*/
#define USE_NEON_COPROCESSOR		(YES)



/*	If you want to save the file for debugging purposes, set the "SAVE_DEBUG_FILE" option to (YES). 
	This option requires the openCV library and works only on linux or windows OS platforms.
*/
#define SAVE_DEBUG_FILE				(YES)



/*	If you want to use pre fetch (PLD) instruction to maximize the speed optimization purposes, set the "USE_BUILTIN_PREFETCH" option to (YES). 
	This option requires the PLD (or PLDW) instruction and works only on linux or ARM OS platforms.
*/
#define USE_BUILTIN_PREFETCH		(YES)



/*	
	To support unaligned access, set the "SUPPORT_UNALIGNED_ACCESS" option to (YES).
	On the arm os platform, in here, it is forced to support only aligned access for speed performance issues.
	If you want to use unaligned access on the arm os platform, you should also refer to the "check unaligned access definition" section at the bottom of this file.
	If you want to use unaligned access, you have to use the builtin function __builtin_assume_aligned on the linux os platform.
	If you select that only aligned access is supported, it is always checked that the starting position of the array is aligned to SZ_BIGGEST_ALIGNMENT size.
*/
#define SUPPORT_UNALIGNED_ACCESS	(YES)



/*	For the array, set the "ASSUME_ALL_ARRAY_IS_ALIGNED" option to (YES), if you want the array start position and size to be in multiples of SZ_BIGGEST_ALIGNMENT.
*/
#define ASSUME_ALL_ARRAY_IS_ALIGNED	(YES)



/* set the size for the biggest alignmemt */
#ifndef SZ_BIGGEST_ALIGNMENT
#define SZ_BIGGEST_ALIGNMENT		(32) /* in bytes, power of 2 only */
#elif (32 > SZ_BIGGEST_ALIGNMENT)
#undef SZ_BIGGEST_ALIGNMENT
#define SZ_BIGGEST_ALIGNMENT		(32) /* in bytes, power of 2 only */
#endif


/****************************************************/
/* calculated parameters by user-defined parameters */
/****************************************************/

/* application os platform definition */
#ifdef PLATFORM_WINDOWS
#define APP_OS_PLATFORM             			(APP_OS_PLATFORM_WINDOWS)
#elif defined PLATFORM_LINUX
#define APP_OS_PLATFORM							(APP_OS_PLATFORM_LINUX)
#elif defined PLATFORM_ARM
#define APP_OS_PLATFORM							(APP_OS_PLATFORM_ARM)
#else
#define APP_OS_PLATFORM							(APP_OS_PLATFORM_COMMON)
#endif

/* check debugging file definition */
#if ((YES == SAVE_DEBUG_FILE) && ((APP_OS_PLATFORM_WINDOWS != APP_OS_PLATFORM) && (APP_OS_PLATFORM_LINUX != APP_OS_PLATFORM)))
/* saving debugging file is only for windows or linux mode because of its a lot of complexity. */
#undef  SAVE_DEBUG_FILE
#define SAVE_DEBUG_FILE (NO)
#endif

/* check verbose definition */
#if ((YES == SHOW_VERBOSE) && ((APP_OS_PLATFORM_WINDOWS != APP_OS_PLATFORM) && (APP_OS_PLATFORM_LINUX != APP_OS_PLATFORM)))
/* show verbose is only for windows or linux mode because of its a lot of complexity. */
#undef  SHOW_VERBOSE
#define SHOW_VERBOSE (NO)
#endif

/* check prefetch builtin function - only for linux os */
#if ((YES == USE_BUILTIN_PREFETCH) && ((APP_OS_PLATFORM_LINUX != APP_OS_PLATFORM) && (APP_OS_PLATFORM_ARM != APP_OS_PLATFORM)))
#undef  USE_BUILTIN_PREFETCH
#define USE_BUILTIN_PREFETCH	(NO)
#endif

/* check assume all array is aligned - only for linux os */
#if ((YES == ASSUME_ALL_ARRAY_IS_ALIGNED) && (APP_OS_PLATFORM_LINUX != APP_OS_PLATFORM))
#undef  ASSUME_ALL_ARRAY_IS_ALIGNED
#define ASSUME_ALL_ARRAY_IS_ALIGNED	(NO)
#endif

/* check unaligned access definition */
#if ((YES == SUPPORT_UNALIGNED_ACCESS) && (APP_OS_PLATFORM_ARM == APP_OS_PLATFORM))
#undef  SUPPORT_UNALIGNED_ACCESS
#define SUPPORT_UNALIGNED_ACCESS	(NO) /* performance issue only */
#endif

/***************************************/
/* macro function definition - VERBOSE */
/***************************************/
#if (YES == SHOW_VERBOSE)
#define VERBOSE(...)		printf(__VA_ARGS__)
#else
#define VERBOSE(fmt, ...)	((void)(0))
#endif

/****************************************/
/* macro function definition - ROUND_UP */
/****************************************/
#if (YES == ASSUME_ALL_ARRAY_IS_ALIGNED)
#define ROUND_UP(sz_arr)	((a + SZ_BIGGEST_ALIGNMENT - 1) & (~(SZ_BIGGEST_ALIGNMENT - 1)))
#define ALIGNED_ARRAY		__attribute__(aligned(SZ_BIGGEST_ALIGNMENT))
#else
#define ROUND_UP(sz_arr)	(sz_arr)
#define ALIGNED_ARRAY		
#endif

/********************************************/
/* macro function definition - PRE_FETCH_?? */
/********************************************/
#if (YES == USE_BUILTIN_PREFETCH)
#define PRE_FETCH_BF_LOOP(p_arr)	__buintin_prefetch(p_arr, 0, 2)
#define PRE_FETCH_IN_LOOP(p_arr)	__buintin_prefetch(p_arr, 0, 2) /* check */
#else
#define PRE_FETCH_BF_LOOP(p_arr)	((void)(0))
#define PRE_FETCH_IN_LOOP(p_arr)	((void)(0))
#endif

/**********************************************/
/* macro function definition - ASSUME_ALIGNED */
/**********************************************/
#if (APP_OS_PLATFORM_LINUX == APP_OS_PLATFORM)
#if (YES == SUPPORT_UNALIGNED_ACCESS)
#define ASSUME_ALIGNED(p_arr, sz_align, sz_offset)	__builtin_assume_aligned(p_arr, sz_align, sz_offset)
#else
#define ASSUME_ALIGNED(p_arr, sz_align, sz_offset)	__builtin_assume_aligned(p_arr, sz_align)
#endif
#else
#define ASSUME_ALIGNED(p_arr, sz_align, sz_offset)	(p_arr)
#endif	

/********************************************/
/* macro definition - INLINE, FORCED_INLINE */
/********************************************/
#if(APP_OS_PLATFORM_WINDOWS == APP_OS_PLATFORM)
#define INLINE			__inline
#define FORCED_INLINE	__forceinline
#else
#define INLINE			inline
#define FORCED_INLINE	__attribute__((always_inline))
#endif

/*******************************/
/* macro definition - RESTRICT */
/*******************************/
#if(APP_OS_PLATFORM_WINDOWS == APP_OS_PLATFORM)
#define RESTRICT		__restrict
#else
#define RESTRICT		__restrict
#endif

/*******************************************************************************
 * END OF FILE
 ******************************************************************************/
#endif
