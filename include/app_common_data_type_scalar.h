/*******************************************************************************
 :* @file		app_common_data_type_scalar.h
 * @brief		global common scalar data type definition for all applications
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
#ifndef _APP_COMMON_DATA_TYPE_SCALAR_H_
#define _APP_COMMON_DATA_TYPE_SCALAR_H_
/*******************************************************************************
 * global type definition
 ******************************************************************************/
#ifndef APP_COMMON_DATA_TYPE_SCALAR
#define APP_COMMON_DATA_TYPE_SCALAR
typedef unsigned char      INT08U;
typedef signed char        INT08S;
typedef unsigned short     INT16U;
typedef signed short       INT16S;
typedef unsigned int       INT32U;
typedef signed int         INT32S;
typedef unsigned long long INT64U;
typedef signed long long   INT64S;
typedef float              FP32;
typedef double             FP64;
/* - not allowed. (only use capital character for data type !
typedef unsigned char      int08u;
typedef signed char        int08s;
typedef unsigned short     int16u;
typedef signed short       int16s;
typedef unsigned int       int32u;
typedef signed int         int32s;
typedef unsigned long long int64u;
typedef signed long long   int64s;
typedef float              fp32;
typedef double             fp64;

typedef unsigned char      uint08_t;
typedef signed char        sint08_t;
typedef unsigned short     uint16_t;
typedef signed short       sint16_t;
typedef unsigned int       uint32_t;
typedef signed int         sint32_t;
typedef unsigned long long uint64_t;
typedef signed long long   sint64_t;
typedef float              float_t;
typedef double             double_t;
*/
#endif

/*******************************************************************************
 * END OF FILE
 ******************************************************************************/
#endif
