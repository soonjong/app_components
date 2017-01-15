/*******************************************************************************
 :* @file		app_common_util.h
 * @brief		global common utility definition for all applications
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
#ifndef _APP_COMMON_UTIL_H_
#define _APP_COMMON_UTIL_H_
/*******************************************************************************
 * including header files
 ******************************************************************************/
#include <limits.h>
#include "app_common_data_type.h"
#include "app_common_para_def.h"
/*******************************************************************************
* global common definitions
******************************************************************************/
#ifndef MIN_INT08S
#define MIN_INT08S	(SCHAR_MIN)
#endif
#ifndef MAX_INT08S
#define MAX_INT08S	(SCHAR_MAX)
#endif
#ifndef MIN_INT08U
#define MIN_INT08U	(0)
#endif
#ifndef MAX_INT08U
#define MAX_INT08U	(UCHAR_MAX)
#endif


#ifndef MIN_INT16S
#define MIN_INT16S	(SHRT_MIN)
#endif
#ifndef MAX_INT16S
#define MAX_INT16S	(SHRT_MAX)
#endif
#ifndef MIN_INT16U
#define MIN_INT16U	(0)
#endif
#ifndef MAX_INT16U
#define MAX_INT16U	(USHRT_MAX)
#endif


#ifndef MIN_INT32S
#define MIN_INT32S	(INT_MIN)
#endif
#ifndef MAX_INT32S
#define MAX_INT32S	(INT_MAX)
#endif
#ifndef MIN_INT32U
#define MIN_INT32U	(0)
#endif
#ifndef MAX_INT32U
#define MAX_INT32U	(UINT_MAX)
#endif


#ifndef MIN_INT64S
#define MIN_INT64S	(_I64_MIN)
#endif
#ifndef MAX_INT64S
#define MAX_INT64S	(_I64_MAX)
#endif
#ifndef MIN_INT64U
#define MIN_INT64U	(0)
#endif
#ifndef MAX_INT64U
#define MAX_INT64U	(_UI64_MAX)
#endif
/*******************************************************************************
 * global common utility functions
 ******************************************************************************/

/*******************************/
/* User defined function - min */
/*******************************/
static FORCED_INLINE INT08S cutil_min_s08(const INT08S inp_a_s08, const INT08S inp_b_s08){	return ((inp_a_s08 < inp_b_s08) ? inp_a_s08 : inp_b_s08);}
static FORCED_INLINE INT08U cutil_min_u08(const INT08U inp_a_u08, const INT08U inp_b_u08){	return ((inp_a_u08 < inp_b_u08) ? inp_a_u08 : inp_b_u08);}
static FORCED_INLINE INT16S cutil_min_s16(const INT16S inp_a_s16, const INT16S inp_b_s16){	return ((inp_a_s16 < inp_b_s16) ? inp_a_s16 : inp_b_s16);}
static FORCED_INLINE INT16U cutil_min_u16(const INT16U inp_a_u16, const INT16U inp_b_u16){	return ((inp_a_u16 < inp_b_u16) ? inp_a_u16 : inp_b_u16);}
static FORCED_INLINE INT32S cutil_min_s32(const INT32S inp_a_s32, const INT32S inp_b_s32){	return ((inp_a_s32 < inp_b_s32) ? inp_a_s32 : inp_b_s32);}
static FORCED_INLINE INT32U cutil_min_u32(const INT32U inp_a_u32, const INT32U inp_b_u32){	return ((inp_a_u32 < inp_b_u32) ? inp_a_u32 : inp_b_u32);}
static FORCED_INLINE INT64S cutil_min_s64(const INT64S inp_a_s64, const INT64S inp_b_s64){	return ((inp_a_s64 < inp_b_s64) ? inp_a_s64 : inp_b_s64);}
static FORCED_INLINE INT64U cutil_min_u64(const INT64U inp_a_u64, const INT64U inp_b_u64){	return ((inp_a_u64 < inp_b_u64) ? inp_a_u64 : inp_b_u64);}
static FORCED_INLINE FP32   cutil_min_f32(const FP32   inp_a_f32, const FP32   inp_b_f32){	return ((inp_a_f32 < inp_b_f32) ? inp_a_f32 : inp_b_f32);}
static FORCED_INLINE FP64   cutil_min_f64(const FP64   inp_a_f64, const FP64   inp_b_f64){	return ((inp_a_f64 < inp_b_f64) ? inp_a_f64 : inp_b_f64);}

/*******************************/
/* User defined function - max */
/*******************************/
static FORCED_INLINE INT08S cutil_max_s08(const INT08S inp_a_s08, const INT08S inp_b_s08){	return ((inp_a_s08 < inp_b_s08) ? inp_b_s08 : inp_a_s08);}
static FORCED_INLINE INT08U cutil_max_u08(const INT08U inp_a_u08, const INT08U inp_b_u08){	return ((inp_a_u08 < inp_b_u08) ? inp_b_u08 : inp_a_u08);}
static FORCED_INLINE INT16S cutil_max_s16(const INT16S inp_a_s16, const INT16S inp_b_s16){	return ((inp_a_s16 < inp_b_s16) ? inp_b_s16 : inp_a_s16);}
static FORCED_INLINE INT16U cutil_max_u16(const INT16U inp_a_u16, const INT16U inp_b_u16){	return ((inp_a_u16 < inp_b_u16) ? inp_b_u16 : inp_a_u16);}
static FORCED_INLINE INT32S cutil_max_s32(const INT32S inp_a_s32, const INT32S inp_b_s32){	return ((inp_a_s32 < inp_b_s32) ? inp_b_s32 : inp_a_s32);}
static FORCED_INLINE INT32U cutil_max_u32(const INT32U inp_a_u32, const INT32U inp_b_u32){	return ((inp_a_u32 < inp_b_u32) ? inp_b_u32 : inp_a_u32);}
static FORCED_INLINE INT64S cutil_max_s64(const INT64S inp_a_s64, const INT64S inp_b_s64){	return ((inp_a_s64 < inp_b_s64) ? inp_b_s64 : inp_a_s64);}
static FORCED_INLINE INT64U cutil_max_u64(const INT64U inp_a_u64, const INT64U inp_b_u64){	return ((inp_a_u64 < inp_b_u64) ? inp_b_u64 : inp_a_u64);}
static FORCED_INLINE FP32   cutil_max_f32(const FP32   inp_a_f32, const FP32   inp_b_f32){	return ((inp_a_f32 < inp_b_f32) ? inp_b_f32 : inp_a_f32);}
static FORCED_INLINE FP64   cutil_max_f64(const FP64   inp_a_f64, const FP64   inp_b_f64){	return ((inp_a_f64 < inp_b_f64) ? inp_b_f64 : inp_a_f64);}

/*******************************/
/* User defined function - abs */
/*******************************/
static FORCED_INLINE INT08U cutil_abs_s08(const INT08S inp_s08){	return ((inp_s08 < 0) ? (INT08U)(-inp_s08) : (INT08U)(inp_s08));}
static FORCED_INLINE INT08U cutil_abs_u08(const INT08U inp_u08){	return inp_u08;}
static FORCED_INLINE INT16U cutil_abs_s16(const INT16S inp_s16){	return ((inp_s16 < 0) ? (INT16U)(-inp_s16) : (INT16U)(inp_s16));}
static FORCED_INLINE INT16U cutil_abs_u16(const INT16U inp_u16){	return inp_u16;}
static FORCED_INLINE INT32U cutil_abs_s32(const INT32S inp_s32){	return ((inp_s32 < 0) ? (INT32U)(-inp_s32) : (INT32U)(inp_s32));}
static FORCED_INLINE INT32U cutil_abs_u32(const INT32U inp_u32){	return inp_u32;}
static FORCED_INLINE INT64U cutil_abs_s64(const INT64S inp_s64){	return ((inp_s64 < 0) ? (INT64U)(-inp_s64) : (INT64U)(inp_s64));}
static FORCED_INLINE INT64U cutil_abs_u64(const INT64U inp_u64){	return inp_u64;}
static FORCED_INLINE FP32   cutil_abs_f32(const FP32   inp_f32){	return ((inp_f32 < 0) ? (-inp_f32) : inp_f32);}
static FORCED_INLINE FP64   cutil_abs_f64(const FP64   inp_f64){	return ((inp_f64 < 0) ? (-inp_f64) : inp_f64);}

/*******************************/
/* User defined function - sat */
/*******************************/
static FORCED_INLINE INT08S cutil_sat_s08_to_s08(const INT08S inp_s08){	return ((inp_s08 < MIN_INT08S) ? (INT08S)MIN_INT08S : (inp_s08 > MAX_INT08S) ? (INT08S)MAX_INT08S : (INT08S)inp_s08);}
static FORCED_INLINE INT08U cutil_sat_s08_to_u08(const INT08S inp_s08){	return ((inp_s08 < MIN_INT08U) ? (INT08U)MIN_INT08U : (inp_s08 > MAX_INT08U) ? (INT08U)MAX_INT08U : (INT08U)inp_s08);}
static FORCED_INLINE INT16S cutil_sat_s08_to_s16(const INT08S inp_s08){	return ((inp_s08 < MIN_INT16S) ? (INT16S)MIN_INT16S : (inp_s08 > MAX_INT16S) ? (INT16S)MAX_INT16S : (INT16S)inp_s08);}
static FORCED_INLINE INT16U cutil_sat_s08_to_u16(const INT08S inp_s08){	return ((inp_s08 < MIN_INT16U) ? (INT16U)MIN_INT16U : (inp_s08 > MAX_INT16U) ? (INT16U)MAX_INT16U : (INT16U)inp_s08);}
static FORCED_INLINE INT32S cutil_sat_s08_to_s32(const INT08S inp_s08){	return ((inp_s08 < MIN_INT32S) ? (INT32S)MIN_INT32S : (inp_s08 > MAX_INT32S) ? (INT32S)MAX_INT32S : (INT32S)inp_s08);}
static FORCED_INLINE INT32U cutil_sat_s08_to_u32(const INT08S inp_s08){	return ((inp_s08 < MIN_INT32U) ? (INT32U)MIN_INT32U : (inp_s08 > MAX_INT32U) ? (INT32U)MAX_INT32U : (INT32U)inp_s08);}
static FORCED_INLINE INT64S cutil_sat_s08_to_s64(const INT08S inp_s08){	return ((inp_s08 < MIN_INT64S) ? (INT64S)MIN_INT64S : (inp_s08 > MAX_INT64S) ? (INT64S)MAX_INT64S : (INT64S)inp_s08);}
static FORCED_INLINE INT64U cutil_sat_s08_to_u64(const INT08S inp_s08){	return ((inp_s08 < MIN_INT64U) ? (INT64U)MIN_INT64U : (inp_s08 > MAX_INT64U) ? (INT64U)MAX_INT64U : (INT64U)inp_s08);}
static FORCED_INLINE INT08S cutil_sat_u08_to_s08(const INT08U inp_u08){	return ((inp_u08 < MIN_INT08S) ? (INT08S)MIN_INT08S : (inp_u08 > MAX_INT08S) ? (INT08S)MAX_INT08S : (INT08S)inp_u08);}
static FORCED_INLINE INT08U cutil_sat_u08_to_u08(const INT08U inp_u08){	return ((inp_u08 < MIN_INT08U) ? (INT08U)MIN_INT08U : (inp_u08 > MAX_INT08U) ? (INT08U)MAX_INT08U : (INT08U)inp_u08);}
static FORCED_INLINE INT16S cutil_sat_u08_to_s16(const INT08U inp_u08){	return ((inp_u08 < MIN_INT16S) ? (INT16S)MIN_INT16S : (inp_u08 > MAX_INT16S) ? (INT16S)MAX_INT16S : (INT16S)inp_u08);}
static FORCED_INLINE INT16U cutil_sat_u08_to_u16(const INT08U inp_u08){	return ((inp_u08 < MIN_INT16U) ? (INT16U)MIN_INT16U : (inp_u08 > MAX_INT16U) ? (INT16U)MAX_INT16U : (INT16U)inp_u08);}
static FORCED_INLINE INT32S cutil_sat_u08_to_s32(const INT08U inp_u08){	return ((inp_u08 < MIN_INT32S) ? (INT32S)MIN_INT32S : (inp_u08 > MAX_INT32S) ? (INT32S)MAX_INT32S : (INT32S)inp_u08);}
static FORCED_INLINE INT32U cutil_sat_u08_to_u32(const INT08U inp_u08){	return ((inp_u08 < MIN_INT32U) ? (INT32U)MIN_INT32U : (inp_u08 > MAX_INT32U) ? (INT32U)MAX_INT32U : (INT32U)inp_u08);}
static FORCED_INLINE INT64S cutil_sat_u08_to_s64(const INT08U inp_u08){	return ((inp_u08 < MIN_INT64S) ? (INT64S)MIN_INT64S : (inp_u08 > MAX_INT64S) ? (INT64S)MAX_INT64S : (INT64S)inp_u08);}
static FORCED_INLINE INT64U cutil_sat_u08_to_u64(const INT08U inp_u08){	return ((inp_u08 < MIN_INT64U) ? (INT64U)MIN_INT64U : (inp_u08 > MAX_INT64U) ? (INT64U)MAX_INT64U : (INT64U)inp_u08);}

static FORCED_INLINE INT08S cutil_sat_s16_to_s08(const INT16S inp_s16){	return ((inp_s16 < MIN_INT08S) ? (INT08S)MIN_INT08S : (inp_s16 > MAX_INT08S) ? (INT08S)MAX_INT08S : (INT08S)inp_s16);}
static FORCED_INLINE INT08U cutil_sat_s16_to_u08(const INT16S inp_s16){	return ((inp_s16 < MIN_INT08U) ? (INT08U)MIN_INT08U : (inp_s16 > MAX_INT08U) ? (INT08U)MAX_INT08U : (INT08U)inp_s16);}
static FORCED_INLINE INT16S cutil_sat_s16_to_s16(const INT16S inp_s16){	return ((inp_s16 < MIN_INT16S) ? (INT16S)MIN_INT16S : (inp_s16 > MAX_INT16S) ? (INT16S)MAX_INT16S : (INT16S)inp_s16);}
static FORCED_INLINE INT16U cutil_sat_s16_to_u16(const INT16S inp_s16){	return ((inp_s16 < MIN_INT16U) ? (INT16U)MIN_INT16U : (inp_s16 > MAX_INT16U) ? (INT16U)MAX_INT16U : (INT16U)inp_s16);}
static FORCED_INLINE INT32S cutil_sat_s16_to_s32(const INT16S inp_s16){	return ((inp_s16 < MIN_INT32S) ? (INT32S)MIN_INT32S : (inp_s16 > MAX_INT32S) ? (INT32S)MAX_INT32S : (INT32S)inp_s16);}
static FORCED_INLINE INT32U cutil_sat_s16_to_u32(const INT16S inp_s16){	return ((inp_s16 < MIN_INT32U) ? (INT32U)MIN_INT32U : (inp_s16 > MAX_INT32U) ? (INT32U)MAX_INT32U : (INT32U)inp_s16);}
static FORCED_INLINE INT64S cutil_sat_s16_to_s64(const INT16S inp_s16){	return ((inp_s16 < MIN_INT64S) ? (INT64S)MIN_INT64S : (inp_s16 > MAX_INT64S) ? (INT64S)MAX_INT64S : (INT64S)inp_s16);}
static FORCED_INLINE INT64U cutil_sat_s16_to_u64(const INT16S inp_s16){	return ((inp_s16 < MIN_INT64U) ? (INT64U)MIN_INT64U : (inp_s16 > MAX_INT64U) ? (INT64U)MAX_INT64U : (INT64U)inp_s16);}
static FORCED_INLINE INT08S cutil_sat_u16_to_s08(const INT16U inp_u16){	return ((inp_u16 < MIN_INT08S) ? (INT08S)MIN_INT08S : (inp_u16 > MAX_INT08S) ? (INT08S)MAX_INT08S : (INT08S)inp_u16);}
static FORCED_INLINE INT08U cutil_sat_u16_to_u08(const INT16U inp_u16){	return ((inp_u16 < MIN_INT08U) ? (INT08U)MIN_INT08U : (inp_u16 > MAX_INT08U) ? (INT08U)MAX_INT08U : (INT08U)inp_u16);}
static FORCED_INLINE INT16S cutil_sat_u16_to_s16(const INT16U inp_u16){	return ((inp_u16 < MIN_INT16S) ? (INT16S)MIN_INT16S : (inp_u16 > MAX_INT16S) ? (INT16S)MAX_INT16S : (INT16S)inp_u16);}
static FORCED_INLINE INT16U cutil_sat_u16_to_u16(const INT16U inp_u16){	return ((inp_u16 < MIN_INT16U) ? (INT16U)MIN_INT16U : (inp_u16 > MAX_INT16U) ? (INT16U)MAX_INT16U : (INT16U)inp_u16);}
static FORCED_INLINE INT32S cutil_sat_u16_to_s32(const INT16U inp_u16){	return ((inp_u16 < MIN_INT32S) ? (INT32S)MIN_INT32S : (inp_u16 > MAX_INT32S) ? (INT32S)MAX_INT32S : (INT32S)inp_u16);}
static FORCED_INLINE INT32U cutil_sat_u16_to_u32(const INT16U inp_u16){	return ((inp_u16 < MIN_INT32U) ? (INT32U)MIN_INT32U : (inp_u16 > MAX_INT32U) ? (INT32U)MAX_INT32U : (INT32U)inp_u16);}
static FORCED_INLINE INT64S cutil_sat_u16_to_s64(const INT16U inp_u16){	return ((inp_u16 < MIN_INT64S) ? (INT64S)MIN_INT64S : (inp_u16 > MAX_INT64S) ? (INT64S)MAX_INT64S : (INT64S)inp_u16);}
static FORCED_INLINE INT64U cutil_sat_u16_to_u64(const INT16U inp_u16){	return ((inp_u16 < MIN_INT64U) ? (INT64U)MIN_INT64U : (inp_u16 > MAX_INT64U) ? (INT64U)MAX_INT64U : (INT64U)inp_u16);}

static FORCED_INLINE INT08S cutil_sat_s32_to_s08(const INT32S inp_s32){	return ((inp_s32 < MIN_INT08S) ? (INT08S)MIN_INT08S : (inp_s32 > MAX_INT08S) ? (INT08S)MAX_INT08S : (INT08S)inp_s32);}
static FORCED_INLINE INT08U cutil_sat_s32_to_u08(const INT32S inp_s32){	return ((inp_s32 < MIN_INT08U) ? (INT08U)MIN_INT08U : (inp_s32 > MAX_INT08U) ? (INT08U)MAX_INT08U : (INT08U)inp_s32);}
static FORCED_INLINE INT16S cutil_sat_s32_to_s16(const INT32S inp_s32){	return ((inp_s32 < MIN_INT16S) ? (INT16S)MIN_INT16S : (inp_s32 > MAX_INT16S) ? (INT16S)MAX_INT16S : (INT16S)inp_s32);}
static FORCED_INLINE INT16U cutil_sat_s32_to_u16(const INT32S inp_s32){	return ((inp_s32 < MIN_INT16U) ? (INT16U)MIN_INT16U : (inp_s32 > MAX_INT16U) ? (INT16U)MAX_INT16U : (INT16U)inp_s32);}
static FORCED_INLINE INT32S cutil_sat_s32_to_s32(const INT32S inp_s32){	return ((inp_s32 < MIN_INT32S) ? (INT32S)MIN_INT32S : (inp_s32 > MAX_INT32S) ? (INT32S)MAX_INT32S : (INT32S)inp_s32);}
static FORCED_INLINE INT32U cutil_sat_s32_to_u32(const INT32S inp_s32){	return ((inp_s32 < MIN_INT32U) ? (INT32U)MIN_INT32U : (inp_s32 > MAX_INT32U) ? (INT32U)MAX_INT32U : (INT32U)inp_s32);}
static FORCED_INLINE INT64S cutil_sat_s32_to_s64(const INT32S inp_s32){	return ((inp_s32 < MIN_INT64S) ? (INT64S)MIN_INT64S : (inp_s32 > MAX_INT64S) ? (INT64S)MAX_INT64S : (INT64S)inp_s32);}
static FORCED_INLINE INT64U cutil_sat_s32_to_u64(const INT32S inp_s32){	return ((inp_s32 < MIN_INT64U) ? (INT64U)MIN_INT64U : (inp_s32 > MAX_INT64U) ? (INT64U)MAX_INT64U : (INT64U)inp_s32);}
static FORCED_INLINE INT08S cutil_sat_u32_to_s08(const INT32U inp_u32){	return ((inp_u32 < MIN_INT08S) ? (INT08S)MIN_INT08S : (inp_u32 > MAX_INT08S) ? (INT08S)MAX_INT08S : (INT08S)inp_u32);}
static FORCED_INLINE INT08U cutil_sat_u32_to_u08(const INT32U inp_u32){	return ((inp_u32 < MIN_INT08U) ? (INT08U)MIN_INT08U : (inp_u32 > MAX_INT08U) ? (INT08U)MAX_INT08U : (INT08U)inp_u32);}
static FORCED_INLINE INT16S cutil_sat_u32_to_s16(const INT32U inp_u32){	return ((inp_u32 < MIN_INT16S) ? (INT16S)MIN_INT16S : (inp_u32 > MAX_INT16S) ? (INT16S)MAX_INT16S : (INT16S)inp_u32);}
static FORCED_INLINE INT16U cutil_sat_u32_to_u16(const INT32U inp_u32){	return ((inp_u32 < MIN_INT16U) ? (INT16U)MIN_INT16U : (inp_u32 > MAX_INT16U) ? (INT16U)MAX_INT16U : (INT16U)inp_u32);}
static FORCED_INLINE INT32S cutil_sat_u32_to_s32(const INT32U inp_u32){	return ((inp_u32 < MIN_INT32S) ? (INT32S)MIN_INT32S : (inp_u32 > MAX_INT32S) ? (INT32S)MAX_INT32S : (INT32S)inp_u32);}
static FORCED_INLINE INT32U cutil_sat_u32_to_u32(const INT32U inp_u32){	return ((inp_u32 < MIN_INT32U) ? (INT32U)MIN_INT32U : (inp_u32 > MAX_INT32U) ? (INT32U)MAX_INT32U : (INT32U)inp_u32);}
static FORCED_INLINE INT64S cutil_sat_u32_to_s64(const INT32U inp_u32){	return ((inp_u32 < MIN_INT64S) ? (INT64S)MIN_INT64S : (inp_u32 > MAX_INT64S) ? (INT64S)MAX_INT64S : (INT64S)inp_u32);}
static FORCED_INLINE INT64U cutil_sat_u32_to_u64(const INT32U inp_u32){	return ((inp_u32 < MIN_INT64U) ? (INT64U)MIN_INT64U : (inp_u32 > MAX_INT64U) ? (INT64U)MAX_INT64U : (INT64U)inp_u32);}

static FORCED_INLINE INT08S cutil_sat_s64_to_s08(const INT64S inp_s64){	return ((inp_s64 < MIN_INT08S) ? (INT08S)MIN_INT08S : (inp_s64 > MAX_INT08S) ? (INT08S)MAX_INT08S : (INT08S)inp_s64);}
static FORCED_INLINE INT08U cutil_sat_s64_to_u08(const INT64S inp_s64){	return ((inp_s64 < MIN_INT08U) ? (INT08U)MIN_INT08U : (inp_s64 > MAX_INT08U) ? (INT08U)MAX_INT08U : (INT08U)inp_s64);}
static FORCED_INLINE INT16S cutil_sat_s64_to_s16(const INT64S inp_s64){	return ((inp_s64 < MIN_INT16S) ? (INT16S)MIN_INT16S : (inp_s64 > MAX_INT16S) ? (INT16S)MAX_INT16S : (INT16S)inp_s64);}
static FORCED_INLINE INT16U cutil_sat_s64_to_u16(const INT64S inp_s64){	return ((inp_s64 < MIN_INT16U) ? (INT16U)MIN_INT16U : (inp_s64 > MAX_INT16U) ? (INT16U)MAX_INT16U : (INT16U)inp_s64);}
static FORCED_INLINE INT32S cutil_sat_s64_to_s32(const INT64S inp_s64){	return ((inp_s64 < MIN_INT32S) ? (INT32S)MIN_INT32S : (inp_s64 > MAX_INT32S) ? (INT32S)MAX_INT32S : (INT32S)inp_s64);}
static FORCED_INLINE INT32U cutil_sat_s64_to_u32(const INT64S inp_s64){	return ((inp_s64 < MIN_INT32U) ? (INT32U)MIN_INT32U : (inp_s64 > MAX_INT32U) ? (INT32U)MAX_INT32U : (INT32U)inp_s64);}
static FORCED_INLINE INT64S cutil_sat_s64_to_s64(const INT64S inp_s64){	return ((inp_s64 < MIN_INT64S) ? (INT64S)MIN_INT64S : (inp_s64 > MAX_INT64S) ? (INT64S)MAX_INT64S : (INT64S)inp_s64);}
static FORCED_INLINE INT64U cutil_sat_s64_to_u64(const INT64S inp_s64){	return ((inp_s64 < MIN_INT64U) ? (INT64U)MIN_INT64U : (inp_s64 > MAX_INT64U) ? (INT64U)MAX_INT64U : (INT64U)inp_s64);}
static FORCED_INLINE INT08S cutil_sat_u64_to_s08(const INT64U inp_u64){	return ((inp_u64 < MIN_INT08S) ? (INT08S)MIN_INT08S : (inp_u64 > MAX_INT08S) ? (INT08S)MAX_INT08S : (INT08S)inp_u64);}
static FORCED_INLINE INT08U cutil_sat_u64_to_u08(const INT64U inp_u64){	return ((inp_u64 < MIN_INT08U) ? (INT08U)MIN_INT08U : (inp_u64 > MAX_INT08U) ? (INT08U)MAX_INT08U : (INT08U)inp_u64);}
static FORCED_INLINE INT16S cutil_sat_u64_to_s16(const INT64U inp_u64){	return ((inp_u64 < MIN_INT16S) ? (INT16S)MIN_INT16S : (inp_u64 > MAX_INT16S) ? (INT16S)MAX_INT16S : (INT16S)inp_u64);}
static FORCED_INLINE INT16U cutil_sat_u64_to_u16(const INT64U inp_u64){	return ((inp_u64 < MIN_INT16U) ? (INT16U)MIN_INT16U : (inp_u64 > MAX_INT16U) ? (INT16U)MAX_INT16U : (INT16U)inp_u64);}
static FORCED_INLINE INT32S cutil_sat_u64_to_s32(const INT64U inp_u64){	return ((inp_u64 < MIN_INT32S) ? (INT32S)MIN_INT32S : (inp_u64 > MAX_INT32S) ? (INT32S)MAX_INT32S : (INT32S)inp_u64);}
static FORCED_INLINE INT32U cutil_sat_u64_to_u32(const INT64U inp_u64){	return ((inp_u64 < MIN_INT32U) ? (INT32U)MIN_INT32U : (inp_u64 > MAX_INT32U) ? (INT32U)MAX_INT32U : (INT32U)inp_u64);}
static FORCED_INLINE INT64S cutil_sat_u64_to_s64(const INT64U inp_u64){	return ((inp_u64 < MIN_INT64S) ? (INT64S)MIN_INT64S : (inp_u64 > MAX_INT64S) ? (INT64S)MAX_INT64S : (INT64S)inp_u64);}
static FORCED_INLINE INT64U cutil_sat_u64_to_u64(const INT64U inp_u64){	return ((inp_u64 < MIN_INT64U) ? (INT64U)MIN_INT64U : (inp_u64 > MAX_INT64U) ? (INT64U)MAX_INT64U : (INT64U)inp_u64);}

/********************************/
/* User defined function - swap */
/********************************/
static FORCED_INLINE void cutil_swap_s08(INT08S *ino_a_s08, INT08S *ino_b_s08){	const INT08S tmp_s08 = *ino_b_s08;	*ino_b_s08 = *ino_a_s08;	*ino_a_s08 = tmp_s08;}
static FORCED_INLINE void cutil_swap_u08(INT08U *ino_a_u08, INT08U *ino_b_u08){	const INT08U tmp_u08 = *ino_b_u08;	*ino_b_u08 = *ino_a_u08;	*ino_a_u08 = tmp_u08;}
static FORCED_INLINE void cutil_swap_s16(INT16S *ino_a_s16, INT16S *ino_b_s16){	const INT16S tmp_s16 = *ino_b_s16;	*ino_b_s16 = *ino_a_s16;	*ino_a_s16 = tmp_s16;}
static FORCED_INLINE void cutil_swap_u16(INT16U *ino_a_u16, INT16U *ino_b_u16){	const INT16U tmp_u16 = *ino_b_u16;	*ino_b_u16 = *ino_a_u16;	*ino_a_u16 = tmp_u16;}
static FORCED_INLINE void cutil_swap_s32(INT32S *ino_a_s32, INT32S *ino_b_s32){	const INT32S tmp_s32 = *ino_b_s32;	*ino_b_s32 = *ino_a_s32;	*ino_a_s32 = tmp_s32;}
static FORCED_INLINE void cutil_swap_u32(INT32U *ino_a_u32, INT32U *ino_b_u32){	const INT32U tmp_u32 = *ino_b_u32;	*ino_b_u32 = *ino_a_u32;	*ino_a_u32 = tmp_u32;}
static FORCED_INLINE void cutil_swap_s64(INT64S *ino_a_s64, INT64S *ino_b_s64){	const INT64S tmp_s64 = *ino_b_s64;	*ino_b_s64 = *ino_a_s64;	*ino_a_s64 = tmp_s64;}
static FORCED_INLINE void cutil_swap_u64(INT64U *ino_a_u64, INT64U *ino_b_u64){	const INT64U tmp_u64 = *ino_b_u64;	*ino_b_u64 = *ino_a_u64;	*ino_a_u64 = tmp_u64;}
static FORCED_INLINE void cutil_swap_f32(FP32   *ino_a_f32, FP32   *ino_b_f32){	const FP32   tmp_f32 = *ino_b_f32;	*ino_b_f32 = *ino_a_f32;	*ino_a_f32 = tmp_f32;}
static FORCED_INLINE void cutil_swap_f64(FP64   *ino_a_f64, FP64   *ino_b_f64){	const FP64   tmp_f64 = *ino_b_f64;	*ino_b_f64 = *ino_a_f64;	*ino_a_f64 = tmp_f64;}

/*************************************/
/* User defined function - remainder */
/*************************************/

/*******************************************************************************
 * END OF FILE
 ******************************************************************************/
#endif
