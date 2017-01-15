/*******************************************************************************
 * @file		app_gen_debug_info.h
 * @brief		application header file for the generating debugging info.
 * @version		VERSION_APP_GEN_DEBUG_INFO
 * @warning		file fmt - unix, encoding fmt: ANSI
 * @instruct.	It is not allowed to change this file arbitrarily
 *					without permission.
 *				If you have a good way to change to a better direction,
 *					please contact me.
 * @author		Jin, Soonjong (soonjong.jin@gmail.com)
 * @date		revision history
 *				2017.01/07 - v0.1: files is created by Jin, Soonjong
 ******************************************************************************/
#ifndef _APP_DBG_IMG_H_
#define _APP_DBG_IMG_H_
/*******************************************************************************
 * including header files
 ******************************************************************************/
/* common definition for aplication */
#include "include/app_common_def.h"
/* common data type for application */
#include "include/app_common_data_type.h"
/* common parameter defintion for application */
#include "include/app_common_para_def.h"
/*******************************************************************************
 * global function prototypes
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/* conversion from yuv (8 bits) to rgb (8 bits) */
void app_cvt_yuv_u08_to_rgb_u08(    INT08U *out_r_u08, /* output r value in 8 bits */
                                    INT08U *out_g_u08, /* output g value in 8 bits */
                                    INT08U *out_b_u08, /* output b value in 8 bits */
                                    const INT08U inp_y_u08,  /* input y value in 8 bits */
                                    const INT08U inp_u_u08,  /* input u value in 8 bits */
                                    const INT08U inp_v_u08); /* input v value in 8 bits */

/* conversion from yuv (16 bits) to rgb (16 bits) */
void app_cvt_yuv_u16_to_rgb_u16(    INT16U *out_r_u16, /* output r value in 16 bits */
                                    INT16U *out_g_u16, /* output g value in 16 bits */
                                    INT16U *out_b_u16, /* output b value in 16 bits */
                                    const INT16U inp_y_u16,  /* input y value in 16 bits */
                                    const INT16U inp_u_u16,  /* input u value in 16 bits */
                                    const INT16U inp_v_u16); /* input v value in 16 bits */

/* conversion from rgb (8 bits) to yuv (8 bits) */
void app_cvt_rgb_u08_to_yuv_u08(    INT08U *out_y_u08, /* output y value in 8 bits */
                                    INT08U *out_u_u08, /* output u value in 8 bits */
                                    INT08U *out_v_u08, /* output v value in 8 bits */
                                    const INT08U inp_r_u08, /* input r value in 8 bits */
                                    const INT08U inp_g_u08, /* input g value in 8 bits */
                                    const INT08U inp_b_u08);/* input b value in 8 bits */

/* conversion from rgb (16 bits) to yuv (16 bits) */
void app_cvt_rgb_u16_to_yuv_u16(    INT16U *out_y_u16, /* output y value in 16 bits */
                                    INT16U *out_u_u16, /* output u value in 16 bits */
                                    INT16U *out_v_u16, /* output v value in 16 bits */
                                    const INT16U inp_r_u16,  /* input r value in 16 bits */
                                    const INT16U inp_g_u16,  /* input g value in 16 bits */
                                    const INT16U inp_b_u16); /* input b value in 16 bits */

/* save image: yuv 4:2:2 interleaved form with yuyv order */
void app_dbg_img_save_yuv422_itrv_oyuyv(    const INT08U* RESTRICT p_inp_seq_u08, /* input sequence yuyv */
                                            const INT32U sz_inp_wid_u32, /* input width size */
                                            const INT32U sz_inp_hei_u32, /* input height size */
                                            const char* p_inp_name); /* file name */

/* save image: yuv 4:2:2 interleaved form with uyvy order */
void app_dbg_img_save_yuv422_itrv_ouyvy(    const INT08U* RESTRICT p_inp_seq_u08, /* input sequence uyvy */
                                            const INT32U sz_inp_wid_u32, /* input width size */
                                            const INT32U sz_inp_hei_u32, /* input height size */
                                            const char* p_inp_name); /* file name */

/* save image: yuv 4:2:2 interleaved form with yvyu order */
void app_dbg_img_save_yuv422_itrv_oyvyu(    const INT08U* RESTRICT p_inp_seq_u08, /* input sequence yuyv */
                                            const INT32U sz_inp_wid_u32, /* input width size */
                                            const INT32U sz_inp_hei_u32, /* input height size */
                                            const char* p_inp_name); /* file name */

/* save image: yuv 4:2:2 interleaved form with vyuy order */
void app_dbg_img_save_yuv422_itrv_ovyuy(    const INT08U* RESTRICT p_inp_seq_u08, /* input sequence vyuy */
                                            const INT32U sz_inp_wid_u32, /* input width size */
                                            const INT32U sz_inp_hei_u32, /* input height size */
                                            const char* p_inp_name); /* file name */

/* save image: yuv 4:2:2 interleaved form with yuv order */
void app_dbg_img_save_yuv422_plnr_oyuv(     const INT08U* RESTRICT p_inp_seq_y_u08, /* input sequence y */
                                            const INT08U* RESTRICT p_inp_seq_u_u08, /* input sequence u */
                                            const INT08U* RESTRICT p_inp_seq_v_u08, /* input sequence v */
                                            const INT32U sz_inp_wid_u32, /* input width size */
                                            const INT32U sz_inp_hei_u32, /* input height size */
                                            const char* p_inp_name); /* file name */

/* save image: yuv 4:2:2 planar form with yuv order */
void app_dbg_img_save_yuv422_plnr_oyuv(     const INT08U* RESTRICT p_inp_seq_y_u08, /* input sequence y */
                                            const INT08U* RESTRICT p_inp_seq_u_u08, /* input sequence u */
                                            const INT08U* RESTRICT p_inp_seq_v_u08, /* input sequence v */
                                            const INT32U sz_inp_wid_u32, /* input width size */
                                            const INT32U sz_inp_hei_u32, /* input height size */
                                            const char* p_inp_name); /* file name */

/* save image: yuv 4:2:2 planar form with yuv order */
void app_dbg_img_save_yuv444_plnr_oyuv(     const INT08U* RESTRICT p_inp_seq_y_u08, /* input sequence y */
                                            const INT08U* RESTRICT p_inp_seq_u_u08, /* input sequence u */
                                            const INT08U* RESTRICT p_inp_seq_v_u08, /* input sequence v */
                                            const INT32U sz_inp_wid_u32, /* input width size */
                                            const INT32U sz_inp_hei_u32, /* input height size */
                                            const char* p_inp_name); /* file name */

/* save image: yuv 4:2:2 interleaved form with bgr order */
void app_dbg_img_save_rgb444_itrv_obgr(     const INT08U* RESTRICT p_inp_seq_u08, /* input sequence bgr */
                                            const INT32U sz_inp_wid_u32, /* input width size */
                                            const INT32U sz_inp_hei_u32, /* input height size */
                                            const char* p_inp_name); /* file name */

/* save image: yuv 4:2:2 planar form with bgr order */
void app_dbg_img_save_rgb444_plnr_obgr(     const INT08U* RESTRICT p_inp_seq_b_u08, /* input sequence b */
                                            const INT08U* RESTRICT p_inp_seq_g_u08, /* input sequence g */
                                            const INT08U* RESTRICT p_inp_seq_r_u08, /* input sequence r */
                                            const INT32U sz_inp_wid_u32, /* input width size */
                                            const INT32U sz_inp_hei_u32, /* input height size */
                                            const char* p_inp_name); /* file name */

/* save image: yuv 4:2:2 interleaved form with rgb order */
void app_dbg_img_save_rgb444_itrv_orgb(     const INT08U* RESTRICT p_inp_seq_u08, /* input sequence rgb */
                                            const INT32U sz_inp_wid_u32, /* input width size */
                                            const INT32U sz_inp_hei_u32, /* input height size */
                                            const char* p_inp_name); /* file name */

/* save image: yuv 4:2:2 planar form with rgb order */
void app_dbg_img_save_rgb444_plnr_orgb(     const INT08U* RESTRICT p_inp_seq_r_u08, /* input sequence r */
                                            const INT08U* RESTRICT p_inp_seq_g_u08, /* input sequence g */
                                            const INT08U* RESTRICT p_inp_seq_b_u08, /* input sequence b */
                                            const INT32U sz_inp_wid_u32, /* input width size */
                                            const INT32U sz_inp_hei_u32, /* input height size */
                                            const char* p_inp_name); /* file name */

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * END OF FILE
 ******************************************************************************/
#endif
