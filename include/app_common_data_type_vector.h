/*******************************************************************************
 :* @file		app_common_data_type_vector.h
 * @brief		global common vector data type definition for all applications
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
#ifndef _APP_COMMON_DATA_TYPE_VECTOR_H_
#define _APP_COMMON_DATA_TYPE_VECTOR_H_
/*******************************************************************************
 * including header files
 ******************************************************************************/
#include "app_common_para_def.h"
#if ((YES == USE_NEON_COPROCESSOR) && (APP_OS_PLATFORM_ARM == APP_OS_PLATFORM))
#include "arm_neon.h"
#endif

/*******************************************************************************
 * global arm neon type definition
 ******************************************************************************/

 /**************************/
/* case for real arm neon */
/**************************/
#if ((YES == USE_NEON_COPROCESSOR) && (APP_OS_PLATFORM_ARM == APP_OS_PLATFORM))
#ifndef APP_COMMON_DATA_TYPE_VECTOR
#define APP_COMMON_DATA_TYPE_VECTOR
#endif

typedef int8ux8_t	INTU08X8;


/*****************************/
/* case for virtual arm neon */
/*****************************/
#elif ((YES == USE_NEON_COPROCESSOR) && (APP_OS_PLATFORM_ARM != APP_OS_PLATFORM))

#ifndef APP_COMMON_DATA_TYPE_VECTOR
#define APP_COMMON_DATA_TYPE_VECTOR
#endif
#ifndef UNIONDEF_VEC64
#define UNIONDEF_VEC64
union struct _VEC64
{
	INT08U u08[8];
	INT08S s08[8];
	INT16U u16[4];
	INT16S s16[4];
	INT32U u32[2];
	INT32S s32[2];
	INT64U u64;
	INT64S s64;
} VEC64;
#endif
#ifndef UNIONDEF_VEC128
#define UNIONDEF_VEC128
union struct _VEC128
{
	INT08U u08[16];
	INT08S s08[16];
	INT16U u16[ 8];
	INT16S s16[ 8];
	INT32U u32[ 4];
	INT32S s32[ 4];
	INT64U u64[ 2];
	INT64S s64[ 2];
} VEC128;
#endif

#ifndef TYPEDEF_INT08UX8
#define TYPEDEF_INT08UX8
typedef struct _INT08UX8
{
	INT08U	u08[8];
} INT08UX8;
#endif


/**********************************/
/* end of arm neon type defintion */
/**********************************/
#endif
/*******************************************************************************
 * END OF FILE
 ******************************************************************************/
#endif
