/*******************************************************************************
 * @file        app_gen_debug_info.h
 * @brief        application source file for the generating debugging info.
 * @version        VERSION_APP_GEN_DEBUG_INFO
 * @warning        file fmt - unix, encoding fmt: ANSI
 * @instruct.    It is not allowed to change this file arbitrarily
 *                    without permission.
 *                If you have a good way to change to a better direction,
 *                    please contact me.
 * @author        Jin, Soonjong (soonjong.jin@gmail.com)
 * @date        revision history
 *                2017.01/07 - v0.1: files is created by Jin, Soonjong
 ******************************************************************************/

/*******************************************************************************
 * including header files
 ******************************************************************************/
/* application header file for the generating debugging info. */
#include "app_gen_debug_info.h"
/* common util functions */
#include "include/app_common_util.h"
/* opencv headers to load and store image for debugging */
#include "opencv/cv.h"
#include "opencv/cxcore.h"
#include "opencv/highgui.h"
/*******************************************************************************
 * including library files
 ******************************************************************************/
#if(APP_OS_PLATFORM_WIDOWS == APP_OS_PLATFORM)
#if (1 == _DEBUG)
#pragma comment(lib, "opencv/libraries/windows/x64/vc12/opencv_core2413d.lib")
#pragma comment(lib, "opencv/libraries/windows/x64/vc12/opencv_highgui2413d.lib")
#pragma comment(lib, "opencv/libraries/windows/x64/vc12/opencv_imgproc2413d.lib")
#elif (1 == _NDEBUG)
#pragma comment(lib, "opencv/libraries/windows/x64/vc12/opencv_core2413.lib")
#pragma comment(lib, "opencv/libraries/windows/x64/vc12/opencv_highgui2413.lib")
#pragma comment(lib, "opencv/libraries/windows/x64/vc12/opencv_imgproc2413.lib")
#endif
#endif
/*******************************************************************************
 * macros (file scope)
 ******************************************************************************/
#define CV_RELEASE(p_cv)	if(NULL != (p_cv)){\
								cvReleaseImage(&(p_cv));\
								(p_cv) = NULL;\
							}
/*******************************************************************************
 * function prototypes (file scope)
 ******************************************************************************/
static FORCED_INLINE void cvt_yuv_u08_to_rgb_u08(   INT08U *out_r_u08,
                                                    INT08U *out_g_u08,
                                                    INT08U *out_b_u08,
                                                    const INT08U inp_y_u08,
                                                    const INT08U inp_u_u08,
                                                    const INT08U inp_v_u08);
static FORCED_INLINE void cvt_rgb_u08_to_yuv_u08(   INT08U *out_y_u08,
                                                    INT08U *out_u_u08,
                                                    INT08U *out_v_u08,
                                                    const INT08U inp_r_u08,
                                                    const INT08U inp_g_u08,
                                                    const INT08U inp_b_u08);
static FORCED_INLINE void cvt_yuv_u16_to_rgb_u16(   INT16U *out_r_u16,
                                                    INT16U *out_g_u16,
                                                    INT16U *out_b_u16,
                                                    const INT16U inp_y_u16,
                                                    const INT16U inp_u_u16,
                                                    const INT16U inp_v_u16);
static FORCED_INLINE void cvt_rgb_u16_to_yuv_u16(   INT16U *out_y_u16,
                                                    INT16U *out_u_u16,
                                                    INT16U *out_v_u16,
                                                    const INT16U inp_r_u16,
                                                    const INT16U inp_g_u16,
                                                    const INT16U inp_b_u16);
static FORCED_INLINE void cvt_yuyv_u08_to_rgbrgb_u08(   INT08U *out_r0_u08,
														INT08U *out_g0_u08,
														INT08U *out_b0_u08,
														INT08U *out_r1_u08,
														INT08U *out_g1_u08,
														INT08U *out_b1_u08,
														const INT08U inp_y0_u08,
														const INT08U inp_u_u08,
														const INT08U inp_y1_u08,
														const INT08U inp_v_u08);
/*******************************************************************************
 * function lists
 ******************************************************************************/
static FORCED_INLINE void cvt_yuv_u08_to_rgb_u08(   INT08U *out_r_u08,
                                                    INT08U *out_g_u08,
                                                    INT08U *out_b_u08,
                                                    const INT08U inp_y_u08,
                                                    const INT08U inp_u_u08,
                                                    const INT08U inp_v_u08)
{
    /* refer to http://www.equasys.de/colorconversion.html */
/*const INT32S inp_y_s32 = (INT32S)(inp_y_u08) -  16; */
/*const INT32S inp_u_s32 = (INT32S)(inp_u_u08) - 128; */
/*const INT32S inp_v_s32 = (INT32S)(inp_v_u08) - 128; */
/*
/*const INT32S out_r_s32 = ((19071 * inp_y_s32) + (    0 * inp_u_s32) + (26149 * inp_v_s32)) / 16384; */
/*const INT32S out_g_s32 = ((19071 * inp_y_s32) - ( 6423 * inp_u_s32) - (13320 * inp_v_s32)) / 16384; */
/*const INT32S out_b_s32 = ((19071 * inp_y_s32) + (33047 * inp_u_s32) + (    0 * inp_v_s32)) / 16384; */
    const INT32S inp_y_s32 = ((INT32S)(inp_y_u08) -  16) * 19071;
    const INT32S inp_u_s32 =  (INT32S)(inp_u_u08) - 128;
    const INT32S inp_v_s32 =  (INT32S)(inp_v_u08) - 128;

    const INT32S out_r_s32 = (inp_y_s32 + (26149 * inp_v_s32)) / 16384;
    const INT32S out_g_s32 = (inp_y_s32 - ( 6423 * inp_u_s32) - (13320 * inp_v_s32)) / 16384;
    const INT32S out_b_s32 = (inp_y_s32 + (33047 * inp_u_s32)) / 16384;

    *out_r_u08 = cutil_sat_s32_to_u08(out_r_s32);
    *out_g_u08 = cutil_sat_s32_to_u08(out_g_s32);
    *out_b_u08 = cutil_sat_s32_to_u08(out_b_s32);
}

static FORCED_INLINE void cvt_yuyv_u08_to_rgbrgb_u08(   INT08U *out_r0_u08,
														INT08U *out_g0_u08,
														INT08U *out_b0_u08,
														INT08U *out_r1_u08,
														INT08U *out_g1_u08,
														INT08U *out_b1_u08,
														const INT08U inp_y0_u08,
														const INT08U inp_u_u08,
														const INT08U inp_y1_u08,
														const INT08U inp_v_u08)
{
    /* refer to http://www.equasys.de/colorconversion.html */
    const INT32S inp_y0_s32 = ((INT32S)(inp_y0_u08) -  16) * 19071;
    const INT32S inp_y1_s32 = ((INT32S)(inp_y1_u08) -  16) * 19071;
    const INT32S inp_u_s32  =  (INT32S)(inp_u_u08) - 128;
    const INT32S inp_v_s32  =  (INT32S)(inp_v_u08) - 128;
	const INT32S tmp_vr_s32 = (26149 * inp_v_s32);
	const INT32S tmp_vg_s32 = (13320 * inp_v_s32);
	const INT32S tmp_ug_s32 = ( 6423 * inp_u_s32);
	const INT32S tmp_ub_s32 = (33047 * inp_u_s32);

    const INT32S out_r0_s32 = (inp_y0_s32 + tmp_vr_s32) / 16384;
    const INT32S out_r1_s32 = (inp_y1_s32 + tmp_vr_s32) / 16384;
    const INT32S out_g0_s32 = (inp_y0_s32 - tmp_ug_s32 - tmp_vg_s32) / 16384;
    const INT32S out_g1_s32 = (inp_y1_s32 - tmp_ug_s32 - tmp_vg_s32) / 16384;
    const INT32S out_b0_s32 = (inp_y0_s32 + tmp_ub_s32) / 16384;
    const INT32S out_b1_s32 = (inp_y1_s32 + tmp_ub_s32) / 16384;

    *out_r0_u08 = cutil_sat_s32_to_u08(out_r0_s32);
    *out_g0_u08 = cutil_sat_s32_to_u08(out_g0_s32);
    *out_b0_u08 = cutil_sat_s32_to_u08(out_b0_s32);
    *out_r1_u08 = cutil_sat_s32_to_u08(out_r1_s32);
    *out_g1_u08 = cutil_sat_s32_to_u08(out_g1_s32);
    *out_b1_u08 = cutil_sat_s32_to_u08(out_b1_s32);
}

static FORCED_INLINE void cvt_yuv420_u08_to_rgbx4_u08(	INT08U *out_r0_u08,
														INT08U *out_g0_u08,
														INT08U *out_b0_u08,
														INT08U *out_r1_u08,
														INT08U *out_g1_u08,
														INT08U *out_b1_u08,
														INT08U *out_r2_u08,
														INT08U *out_g2_u08,
														INT08U *out_b2_u08,
														INT08U *out_r3_u08,
														INT08U *out_g3_u08,
														INT08U *out_b3_u08,
														const INT08U inp_y0_u08,
														const INT08U inp_y1_u08,
														const INT08U inp_y2_u08,
														const INT08U inp_y3_u08,
														const INT08U inp_u_u08,
														const INT08U inp_v_u08)
{
    /* refer to http://www.equasys.de/colorconversion.html */
    const INT32S inp_y0_s32 = ((INT32S)(inp_y0_u08) -  16) * 19071;
    const INT32S inp_y1_s32 = ((INT32S)(inp_y1_u08) -  16) * 19071;
    const INT32S inp_y2_s32 = ((INT32S)(inp_y2_u08) -  16) * 19071;
    const INT32S inp_y3_s32 = ((INT32S)(inp_y3_u08) -  16) * 19071;
    const INT32S inp_u_s32  =  (INT32S)(inp_u_u08) - 128;
    const INT32S inp_v_s32  =  (INT32S)(inp_v_u08) - 128;
	const INT32S tmp_vr_s32 = (26149 * inp_v_s32);
	const INT32S tmp_vg_s32 = (13320 * inp_v_s32);
	const INT32S tmp_ug_s32 = ( 6423 * inp_u_s32);
	const INT32S tmp_ub_s32 = (33047 * inp_u_s32);

    const INT32S out_r0_s32 = (inp_y0_s32 + tmp_vr_s32) / 16384;
    const INT32S out_r1_s32 = (inp_y1_s32 + tmp_vr_s32) / 16384;
    const INT32S out_r2_s32 = (inp_y2_s32 + tmp_vr_s32) / 16384;
    const INT32S out_r3_s32 = (inp_y3_s32 + tmp_vr_s32) / 16384;
    const INT32S out_g0_s32 = (inp_y0_s32 - tmp_ug_s32 - tmp_vg_s32) / 16384;
    const INT32S out_g1_s32 = (inp_y1_s32 - tmp_ug_s32 - tmp_vg_s32) / 16384;
    const INT32S out_g2_s32 = (inp_y2_s32 - tmp_ug_s32 - tmp_vg_s32) / 16384;
    const INT32S out_g3_s32 = (inp_y3_s32 - tmp_ug_s32 - tmp_vg_s32) / 16384;
    const INT32S out_b0_s32 = (inp_y0_s32 + tmp_ub_s32) / 16384;
    const INT32S out_b1_s32 = (inp_y1_s32 + tmp_ub_s32) / 16384;
    const INT32S out_b2_s32 = (inp_y2_s32 + tmp_ub_s32) / 16384;
    const INT32S out_b3_s32 = (inp_y3_s32 + tmp_ub_s32) / 16384;

    *out_r0_u08 = cutil_sat_s32_to_u08(out_r0_s32);
    *out_g0_u08 = cutil_sat_s32_to_u08(out_g0_s32);
    *out_b0_u08 = cutil_sat_s32_to_u08(out_b0_s32);
    *out_r1_u08 = cutil_sat_s32_to_u08(out_r1_s32);
    *out_g1_u08 = cutil_sat_s32_to_u08(out_g1_s32);
    *out_b1_u08 = cutil_sat_s32_to_u08(out_b1_s32);
    *out_r2_u08 = cutil_sat_s32_to_u08(out_r2_s32);
    *out_g2_u08 = cutil_sat_s32_to_u08(out_g2_s32);
    *out_b2_u08 = cutil_sat_s32_to_u08(out_b2_s32);
    *out_r3_u08 = cutil_sat_s32_to_u08(out_r3_s32);
    *out_g3_u08 = cutil_sat_s32_to_u08(out_g3_s32);
    *out_b3_u08 = cutil_sat_s32_to_u08(out_b3_s32);
}

static FORCED_INLINE void cvt_rgb_u08_to_yuv_u08(   INT08U *out_y_u08,
                                                    INT08U *out_u_u08,
                                                    INT08U *out_v_u08,
                                                    const INT08U inp_r_u08,
                                                    const INT08U inp_g_u08,
                                                    const INT08U inp_b_u08)
{
    /* refer to http://www.equasys.de/colorconversion.html */
    const INT32S inp_r_s32 = (INT32S)(inp_r_u08);
    const INT32S inp_g_s32 = (INT32S)(inp_g_u08);
    const INT32S inp_b_s32 = (INT32S)(inp_b_u08);

    const INT32S out_y_s32 =  16 + ((( 4211 * inp_r_s32) + (8258 * inp_g_s32) + (1606 * inp_b_s32)) / 16384);
    const INT32S out_u_s32 = 128 + (((-2425 * inp_r_s32) - (4768 * inp_g_s32) + (7193 * inp_b_s32)) / 16384);
    const INT32S out_v_s32 = 128 + ((( 7193 * inp_r_s32) - (6029 * inp_g_s32) - (1163 * inp_b_s32)) / 16384);

    *out_y_u08 = cutil_sat_s32_to_u08(out_y_s32);
    *out_u_u08 = cutil_sat_s32_to_u08(out_u_s32);
    *out_v_u08 = cutil_sat_s32_to_u08(out_v_s32);
}

static FORCED_INLINE void cvt_yuv_u16_to_rgb_u16(   INT16U *out_r_u16,
                                                    INT16U *out_g_u16,
                                                    INT16U *out_b_u16,
                                                    const INT16U inp_y_u16,
                                                    const INT16U inp_u_u16,
                                                    const INT16U inp_v_u16)
{
    /* refer to http://www.equasys.de/colorconversion.html */
    const INT32S inp_y_s32 = ((INT32S)(inp_y_u16) -  16) * 19071;
    const INT32S inp_u_s32 =  (INT32S)(inp_u_u16) - 128;
    const INT32S inp_v_s32 =  (INT32S)(inp_v_u16) - 128;

    const INT32S out_r_s32 = (inp_y_s32 + (26149 * inp_v_s32)) / 16384;
    const INT32S out_g_s32 = (inp_y_s32 - ( 6423 * inp_u_s32) - (13320 * inp_v_s32)) / 16384;
    const INT32S out_b_s32 = (inp_y_s32 + (33047 * inp_u_s32)) / 16384;

    *out_r_u16 = cutil_sat_s32_to_u16(out_r_s32);
    *out_g_u16 = cutil_sat_s32_to_u16(out_g_s32);
    *out_b_u16 = cutil_sat_s32_to_u16(out_b_s32);
}

static FORCED_INLINE void cvt_rgb_u16_to_yuv_u16(   INT16U *out_y_u16,
                                                    INT16U *out_u_u16,
                                                    INT16U *out_v_u16,
                                                    const INT16U inp_r_u16,
                                                    const INT16U inp_g_u16,
                                                    const INT16U inp_b_u16)
{
    /* refer to http://www.equasys.de/colorconversion.html */
    const INT32S inp_r_s32 = (INT32S)(inp_r_u16);
    const INT32S inp_g_s32 = (INT32S)(inp_g_u16);
    const INT32S inp_b_s32 = (INT32S)(inp_b_u16);

    const INT32S out_y_s32 =  16 + ((( 4211 * inp_r_s32) + (8258 * inp_g_s32) + (1606 * inp_b_s32)) / 16384);
    const INT32S out_u_s32 = 128 + (((-2425 * inp_r_s32) - (4768 * inp_g_s32) + (7193 * inp_b_s32)) / 16384);
    const INT32S out_v_s32 = 128 + ((( 7193 * inp_r_s32) - (6029 * inp_g_s32) - (1163 * inp_b_s32)) / 16384);

    *out_y_u16 = cutil_sat_s32_to_u16(out_y_s32);
    *out_u_u16 = cutil_sat_s32_to_u16(out_u_s32);
    *out_v_u16 = cutil_sat_s32_to_u16(out_v_s32);
}

void app_cvt_yuv_u08_to_rgb_u08(INT08U *out_r_u08, INT08U *out_g_u08, INT08U *out_b_u08, const INT08U inp_y_u08, const INT08U inp_u_u08, const INT08U inp_v_u08)
{
    cvt_yuv_u08_to_rgb_u08(out_r_u08, out_g_u08, out_b_u08, inp_y_u08, inp_u_u08, inp_v_u08);
}

void app_cvt_rgb_u08_to_yuv_u08(INT08U *out_y_u08, INT08U *out_u_u08, INT08U *out_v_u08, const INT08U inp_r_u08, const INT08U inp_g_u08, const INT08U inp_b_u08)
{
    cvt_rgb_u08_to_yuv_u08(out_y_u08, out_u_u08, out_v_u08, inp_r_u08, inp_g_u08, inp_b_u08);
}

void app_cvt_yuv_u16_to_rgb_u16(INT16U *out_r_u16, INT16U *out_g_u16, INT16U *out_b_u16, const INT16U inp_y_u16, const INT16U inp_u_u16, const INT16U inp_v_u16)
{
    cvt_yuv_u16_to_rgb_u16(out_r_u16, out_g_u16, out_b_u16, inp_y_u16, inp_u_u16, inp_v_u16);
}

void app_cvt_rgb_u16_to_yuv_u16(INT16U *out_y_u16, INT16U *out_u_u16, INT16U *out_v_u16, const INT16U inp_r_u16, const INT16U inp_g_u16, const INT16U inp_b_u16)
{
    cvt_rgb_u16_to_yuv_u16(out_y_u16, out_u_u16, out_v_u16, inp_r_u16, inp_g_u16, inp_b_u16);
}


void app_dbg_img_save_yuv422_itrv_oyuyv(    const INT08U* RESTRICT p_inp_seq_u08,
                                            const INT32U sz_inp_wid_u32,
                                            const INT32U sz_inp_hei_u32,
                                            const char* p_inp_name)
{
	IplImage* p_cv_out = cvCreateImage(cvSize(sz_inp_wid_u32, sz_inp_hei_u32), IPL_DEPTH_8U, 3);
	INT08U* RESTRICT p_out_bgr_u08 = (INT08U* RESTRICT)&p_cv_out->imageData[0];

	INT32U pos_u32 = 0;
	
	INT08U inp_y0_u08 = 0, inp_y1_u08 = 0, inp_u_u08 = 0, inp_v_u08 = 0;
	INT08U out_r0_u08 = 0, out_g0_u08 = 0, out_b0_u08 = 0;
	INT08U out_r1_u08 = 0, out_g1_u08 = 0, out_b1_u08 = 0;
	
	for(pos_u32 = (sz_inp_hei_u32 * sz_inp_wid_u32 / 2) ; pos_u32 != 0 ; pos_u32--)
	{
		/* data load */
		inp_y0_u08 = *p_inp_seq_u08++;
		inp_u_u08  = *p_inp_seq_u08++;
		inp_y1_u08 = *p_inp_seq_u08++;
		inp_v_u08  = *p_inp_seq_u08++;
		/* convert yuyv to rgbrgb */
		cvt_yuyv_u08_to_rgbrgb_u08(&out_r0_u08, &out_g0_u08, &out_b0_u08, &out_r1_u08, &out_g1_u08, &out_b1_u08, inp_y0_u08, inp_u_u08, inp_y1_u08, inp_v_u08);
		/* data store */
		*p_out_bgr_u08++ = out_b0_u08;
		*p_out_bgr_u08++ = out_g0_u08;
		*p_out_bgr_u08++ = out_r0_u08;
		*p_out_bgr_u08++ = out_b1_u08;
		*p_out_bgr_u08++ = out_g1_u08;
		*p_out_bgr_u08++ = out_r1_u08;
	}
	cvSaveImage(p_inp_name, p_cv_out, 0); 
	
	CV_RELEASE(p_cv_out);
}

void app_dbg_img_save_yuv422_itrv_ouyvy(    const INT08U* RESTRICT p_inp_seq_u08,
                                            const INT32U sz_inp_wid_u32,
                                            const INT32U sz_inp_hei_u32,
                                            const char* p_inp_name)
{
	IplImage* p_cv_out = cvCreateImage(cvSize(sz_inp_wid_u32, sz_inp_hei_u32), IPL_DEPTH_8U, 3);
	INT08U* RESTRICT p_out_bgr_u08 = (INT08U* RESTRICT)&p_cv_out->imageData[0];

	INT32U pos_u32 = 0;
	
	INT08U inp_y0_u08 = 0, inp_y1_u08 = 0, inp_u_u08 = 0, inp_v_u08 = 0;
	INT08U out_r0_u08 = 0, out_g0_u08 = 0, out_b0_u08 = 0;
	INT08U out_r1_u08 = 0, out_g1_u08 = 0, out_b1_u08 = 0;
	
	for(pos_u32 = (sz_inp_hei_u32 * sz_inp_wid_u32 / 2) ; pos_u32 != 0 ; pos_u32--)
	{
		/* data load */
		inp_u_u08  = *p_inp_seq_u08++;
		inp_y0_u08 = *p_inp_seq_u08++;
		inp_v_u08  = *p_inp_seq_u08++;
		inp_y1_u08 = *p_inp_seq_u08++;
		/* convert yuyv to rgbrgb */
		cvt_yuyv_u08_to_rgbrgb_u08(&out_r0_u08, &out_g0_u08, &out_b0_u08, &out_r1_u08, &out_g1_u08, &out_b1_u08, inp_y0_u08, inp_u_u08, inp_y1_u08, inp_v_u08);
		/* data store */
		*p_out_bgr_u08++ = out_b0_u08;
		*p_out_bgr_u08++ = out_g0_u08;
		*p_out_bgr_u08++ = out_r0_u08;
		*p_out_bgr_u08++ = out_b1_u08;
		*p_out_bgr_u08++ = out_g1_u08;
		*p_out_bgr_u08++ = out_r1_u08;
	}
	cvSaveImage(p_inp_name, p_cv_out, 0); 
	
	CV_RELEASE(p_cv_out);
}

void app_dbg_img_save_yuv422_itrv_oyvyu(    const INT08U* RESTRICT p_inp_seq_u08,
                                            const INT32U sz_inp_wid_u32,
                                            const INT32U sz_inp_hei_u32,
                                            const char* p_inp_name)
{
	IplImage* p_cv_out = cvCreateImage(cvSize(sz_inp_wid_u32, sz_inp_hei_u32), IPL_DEPTH_8U, 3);
	INT08U* RESTRICT p_out_bgr_u08 = (INT08U* RESTRICT)&p_cv_out->imageData[0];

	INT32U pos_u32 = 0;
	
	INT08U inp_y0_u08 = 0, inp_y1_u08 = 0, inp_u_u08 = 0, inp_v_u08 = 0;
	INT08U out_r0_u08 = 0, out_g0_u08 = 0, out_b0_u08 = 0;
	INT08U out_r1_u08 = 0, out_g1_u08 = 0, out_b1_u08 = 0;
	
	for(pos_u32 = (sz_inp_hei_u32 * sz_inp_wid_u32 / 2) ; pos_u32 != 0 ; pos_u32--)
	{
		/* data load */
		inp_y0_u08 = *p_inp_seq_u08++;
		inp_v_u08  = *p_inp_seq_u08++;
		inp_y1_u08 = *p_inp_seq_u08++;
		inp_u_u08  = *p_inp_seq_u08++;
		/* convert yuyv to rgbrgb */
		cvt_yuyv_u08_to_rgbrgb_u08(&out_r0_u08, &out_g0_u08, &out_b0_u08, &out_r1_u08, &out_g1_u08, &out_b1_u08, inp_y0_u08, inp_u_u08, inp_y1_u08, inp_v_u08);
		/* data store */
		*p_out_bgr_u08++ = out_b0_u08;
		*p_out_bgr_u08++ = out_g0_u08;
		*p_out_bgr_u08++ = out_r0_u08;
		*p_out_bgr_u08++ = out_b1_u08;
		*p_out_bgr_u08++ = out_g1_u08;
		*p_out_bgr_u08++ = out_r1_u08;
	}
	cvSaveImage(p_inp_name, p_cv_out, 0); 
	
	CV_RELEASE(p_cv_out);
}

void app_dbg_img_save_yuv422_itrv_ovyuy(    const INT08U* RESTRICT p_inp_seq_u08,
                                            const INT32U sz_inp_wid_u32,
                                            const INT32U sz_inp_hei_u32,
                                            const char* p_inp_name)
{
	IplImage* p_cv_out = cvCreateImage(cvSize(sz_inp_wid_u32, sz_inp_hei_u32), IPL_DEPTH_8U, 3);
	INT08U* RESTRICT p_out_bgr_u08 = (INT08U* RESTRICT)&p_cv_out->imageData[0];

	INT32U pos_u32 = 0;
	
	INT08U inp_y0_u08 = 0, inp_y1_u08 = 0, inp_u_u08 = 0, inp_v_u08 = 0;
	INT08U out_r0_u08 = 0, out_g0_u08 = 0, out_b0_u08 = 0;
	INT08U out_r1_u08 = 0, out_g1_u08 = 0, out_b1_u08 = 0;
	
	for(pos_u32 = (sz_inp_hei_u32 * sz_inp_wid_u32 / 2) ; pos_u32 != 0 ; pos_u32--)
	{
		/* data load */
		inp_v_u08  = *p_inp_seq_u08++;
		inp_y0_u08 = *p_inp_seq_u08++;
		inp_u_u08  = *p_inp_seq_u08++;
		inp_y1_u08 = *p_inp_seq_u08++;
		/* convert yuyv to rgbrgb */
		cvt_yuyv_u08_to_rgbrgb_u08(&out_r0_u08, &out_g0_u08, &out_b0_u08, &out_r1_u08, &out_g1_u08, &out_b1_u08, inp_y0_u08, inp_u_u08, inp_y1_u08, inp_v_u08);
		/* data store */
		*p_out_bgr_u08++ = out_b0_u08;
		*p_out_bgr_u08++ = out_g0_u08;
		*p_out_bgr_u08++ = out_r0_u08;
		*p_out_bgr_u08++ = out_b1_u08;
		*p_out_bgr_u08++ = out_g1_u08;
		*p_out_bgr_u08++ = out_r1_u08;
	}
	cvSaveImage(p_inp_name, p_cv_out, 0); 
	
	CV_RELEASE(p_cv_out);
}

void app_dbg_img_save_yuv422_plnr_oyuv(     const INT08U* RESTRICT p_inp_seq_y_u08,
                                            const INT08U* RESTRICT p_inp_seq_u_u08,
                                            const INT08U* RESTRICT p_inp_seq_v_u08,
                                            const INT32U sz_inp_wid_u32,
                                            const INT32U sz_inp_hei_u32,
                                            const char* p_inp_name)
{
	IplImage* p_cv_out = cvCreateImage(cvSize(sz_inp_wid_u32, sz_inp_hei_u32), IPL_DEPTH_8U, 3);
	INT08U* RESTRICT p_out_bgr_u08 = (INT08U* RESTRICT)&p_cv_out->imageData[0];

	INT32U pos_u32 = 0;
	
	INT08U inp_y0_u08 = 0, inp_y1_u08 = 0, inp_u_u08 = 0, inp_v_u08 = 0;
	INT08U out_r0_u08 = 0, out_g0_u08 = 0, out_b0_u08 = 0;
	INT08U out_r1_u08 = 0, out_g1_u08 = 0, out_b1_u08 = 0;
	
	for(pos_u32 = (sz_inp_hei_u32 * sz_inp_wid_u32 / 2) ; pos_u32 != 0 ; pos_u32--)
	{
		/* data load */
		inp_y0_u08 = *p_inp_seq_y_u08++;
		inp_u_u08  = *p_inp_seq_u_u08++;
		inp_y1_u08 = *p_inp_seq_y_u08++;
		inp_v_u08  = *p_inp_seq_v_u08++;
		/* convert yuyv to rgbrgb */
		cvt_yuyv_u08_to_rgbrgb_u08(&out_r0_u08, &out_g0_u08, &out_b0_u08, &out_r1_u08, &out_g1_u08, &out_b1_u08, inp_y0_u08, inp_u_u08, inp_y1_u08, inp_v_u08);
		/* data store */
		*p_out_bgr_u08++ = out_b0_u08;
		*p_out_bgr_u08++ = out_g0_u08;
		*p_out_bgr_u08++ = out_r0_u08;
		*p_out_bgr_u08++ = out_b1_u08;
		*p_out_bgr_u08++ = out_g1_u08;
		*p_out_bgr_u08++ = out_r1_u08;
	}
	cvSaveImage(p_inp_name, p_cv_out, 0); 
	
	CV_RELEASE(p_cv_out);
}


void app_dbg_img_save_yuv420_plnr_oyuv(     const INT08U* RESTRICT p_inp_seq_y_u08,
                                            const INT08U* RESTRICT p_inp_seq_u_u08,
                                            const INT08U* RESTRICT p_inp_seq_v_u08,
                                            const INT32U sz_inp_wid_u32,
                                            const INT32U sz_inp_hei_u32,
                                            const char* p_inp_name)
{
	const INT08U* RESTRICT p_inp_seq_y0_u08 = (const INT08U* RESTRICT)&p_inp_seq_y_u08[             0];
	const INT08U* RESTRICT p_inp_seq_y1_u08 = (const INT08U* RESTRICT)&p_inp_seq_y_u08[sz_inp_wid_u32];
	
	IplImage* p_cv_out = cvCreateImage(cvSize(sz_inp_wid_u32, sz_inp_hei_u32), IPL_DEPTH_8U, 3);
	INT08U* RESTRICT p_out_bgr_u08 = (INT08U* RESTRICT)&p_cv_out->imageData[0];

	INT32U pos_y_u32 = 0, pos_x_u32 = 0, pos_base_u32 = 0, pos_u32 = 0;
	
	INT08U inp_y0_u08 = 0, inp_y1_u08 = 0, inp_y2_u08 = 0, inp_y3_u08 = 0, inp_u_u08 = 0, inp_v_u08 = 0;
	INT08U out_r0_u08 = 0, out_g0_u08 = 0, out_b0_u08 = 0;
	INT08U out_r1_u08 = 0, out_g1_u08 = 0, out_b1_u08 = 0;
	INT08U out_r2_u08 = 0, out_g2_u08 = 0, out_b2_u08 = 0;
	INT08U out_r3_u08 = 0, out_g3_u08 = 0, out_b3_u08 = 0;

	for(pos_y_u32 = (sz_inp_hei_u32 / 2) ; pos_y_u32 != 0 ; pos_y_u32--)
	{
		for(pos_x_u32 = (sz_inp_wid_u32 / 2) ; pos_x_u32 != 0 ; pos_x_u32--)
		{
			/* data load */
			inp_y0_u08 = *p_inp_seq_y0_u08++;
			inp_y1_u08 = *p_inp_seq_y0_u08++;
			inp_y2_u08 = *p_inp_seq_y1_u08++;
			inp_y3_u08 = *p_inp_seq_y1_u08++;
			inp_u_u08  = *p_inp_seq_u_u08++;
			inp_v_u08  = *p_inp_seq_v_u08++;
			/* convert yuyv to rgbrgb */
			cvt_yuv420_u08_to_rgbx4_u08(	&out_r0_u08, &out_g0_u08, &out_b0_u08, &out_r1_u08, &out_g1_u08, &out_b1_u08, 
											&out_r2_u08, &out_g2_u08, &out_b2_u08, &out_r3_u08, &out_g3_u08, &out_b3_u08, 
											inp_y0_u08, inp_y1_u08, inp_y2_u08, inp_y3_u08, inp_u_u08, inp_v_u08);
			/* data store */
			*p_out_bgr_u08++ = out_b0_u08;
			*p_out_bgr_u08++ = out_g0_u08;
			*p_out_bgr_u08++ = out_r0_u08;
			*p_out_bgr_u08++ = out_b1_u08;
			*p_out_bgr_u08++ = out_g1_u08;
			*p_out_bgr_u08++ = out_r1_u08;
			*p_out_bgr_u08++ = out_b2_u08;
			*p_out_bgr_u08++ = out_g2_u08;
			*p_out_bgr_u08++ = out_r2_u08;
			*p_out_bgr_u08++ = out_b3_u08;
			*p_out_bgr_u08++ = out_g3_u08;
			*p_out_bgr_u08++ = out_r3_u08;
		}
		p_inp_seq_y0_u08 += sz_inp_wid_u32;
		p_inp_seq_y1_u08 += sz_inp_wid_u32;
	}
	cvSaveImage(p_inp_name, p_cv_out, 0); 
	
	CV_RELEASE(p_cv_out);
}

void app_dbg_img_save_yuv444_plnr_oyuv(     const INT08U* RESTRICT p_inp_seq_y_u08,
                                            const INT08U* RESTRICT p_inp_seq_u_u08,
                                            const INT08U* RESTRICT p_inp_seq_v_u08,
                                            const INT32U sz_inp_wid_u32,
                                            const INT32U sz_inp_hei_u32,
                                            const char* p_inp_name)
{
	IplImage* p_cv_out = cvCreateImage(cvSize(sz_inp_wid_u32, sz_inp_hei_u32), IPL_DEPTH_8U, 3);
	INT08U* RESTRICT p_out_bgr_u08 = (INT08U* RESTRICT)&p_cv_out->imageData[0];

	INT32U pos_u32 = 0;
	
	INT08U inp_y_u08 = 0, inp_u_u08 = 0, inp_v_u08 = 0;
	INT08U out_r_u08 = 0, out_g_u08 = 0, out_b_u08 = 0;
	
	for(pos_u32 = (sz_inp_hei_u32 * sz_inp_wid_u32) ; pos_u32 != 0 ; pos_u32--)
	{
		/* data load */
		inp_y_u08 = *p_inp_seq_y_u08++;
		inp_u_u08 = *p_inp_seq_u_u08++;
		inp_v_u08 = *p_inp_seq_v_u08++;
		/* convert yuv to rgb */
		cvt_yuv_u08_to_rgb_u08(&out_r_u08, &out_g_u08, &out_b_u08, inp_y_u08, inp_u_u08, inp_v_u08);
		/* data store */
		*p_out_bgr_u08++ = out_b_u08;
		*p_out_bgr_u08++ = out_g_u08;
		*p_out_bgr_u08++ = out_r_u08;
	}
	cvSaveImage(p_inp_name, p_cv_out, 0); 
	
	CV_RELEASE(p_cv_out);
}


void app_dbg_img_save_rgb444_itrv_obgr(     const INT08U* RESTRICT p_inp_seq_u08,
                                            const INT32U sz_inp_wid_u32,
                                            const INT32U sz_inp_hei_u32,
                                            const char* p_inp_name)
{
	IplImage* p_cv_out = cvCreateImage(cvSize(sz_inp_wid_u32, sz_inp_hei_u32), IPL_DEPTH_8U, 3);
	INT08U* RESTRICT p_out_bgr_u08 = (INT08U* RESTRICT)&p_cv_out->imageData[0];
	
	memcpy(p_out_bgr_u08, p_inp_seq_u08, sizeof(INT08U) * sz_inp_wid_u32 * sz_inp_hei_u32 * 3);

	cvSaveImage(p_inp_name, p_cv_out, 0); 
	
	CV_RELEASE(p_cv_out);
}

void app_dbg_img_save_rgb444_plnr_obgr(     const INT08U* RESTRICT p_inp_seq_b_u08,
                                            const INT08U* RESTRICT p_inp_seq_g_u08,
                                            const INT08U* RESTRICT p_inp_seq_r_u08,
                                            const INT32U sz_inp_wid_u32,
                                            const INT32U sz_inp_hei_u32,
                                            const char* p_inp_name)
{
	IplImage* p_cv_out = cvCreateImage(cvSize(sz_inp_wid_u32, sz_inp_hei_u32), IPL_DEPTH_8U, 3);
	INT08U* RESTRICT p_out_bgr_u08 = (INT08U* RESTRICT)&p_cv_out->imageData[0];

	INT32U pos_u32 = 0;
	
	for(pos_u32 = (sz_inp_hei_u32 * sz_inp_wid_u32) ; pos_u32 != 0 ; pos_u32--)
	{
		/* data load & store */
		*p_out_bgr_u08++ = *p_inp_seq_b_u08++;
		*p_out_bgr_u08++ = *p_inp_seq_g_u08++;
		*p_out_bgr_u08++ = *p_inp_seq_r_u08++;
	}
	cvSaveImage(p_inp_name, p_cv_out, 0); 
	
	CV_RELEASE(p_cv_out);
}

void app_dbg_img_save_rgb444_itrv_orgb(     const INT08U* RESTRICT p_inp_seq_u08,
                                            const INT32U sz_inp_wid_u32,
                                            const INT32U sz_inp_hei_u32,
                                            const char* p_inp_name)
{
	IplImage* p_cv_out = cvCreateImage(cvSize(sz_inp_wid_u32, sz_inp_hei_u32), IPL_DEPTH_8U, 3);
	INT08U* RESTRICT p_out_bgr_u08 = (INT08U* RESTRICT)&p_cv_out->imageData[0];

	INT32U pos_u32 = 0;
	INT08U ino_r_u08 = 0, ino_g_u08 = 0, ino_b_u08 = 0;
	
	for(pos_u32 = (sz_inp_hei_u32 * sz_inp_wid_u32) ; pos_u32 != 0 ; pos_u32--)
	{
		/* data load */
		ino_r_u08 = *p_inp_seq_u08++;
		ino_g_u08 = *p_inp_seq_u08++;
		ino_b_u08 = *p_inp_seq_u08++;
		/* data store */
		*p_out_bgr_u08++ = ino_b_u08;
		*p_out_bgr_u08++ = ino_g_u08;
		*p_out_bgr_u08++ = ino_r_u08;
	}
	cvSaveImage(p_inp_name, p_cv_out, 0); 
	
	CV_RELEASE(p_cv_out);
}

void app_dbg_img_save_rgb444_plnr_orgb(     const INT08U* RESTRICT p_inp_seq_r_u08,
                                            const INT08U* RESTRICT p_inp_seq_g_u08,
                                            const INT08U* RESTRICT p_inp_seq_b_u08,
                                            const INT32U sz_inp_wid_u32,
                                            const INT32U sz_inp_hei_u32,
                                            const char* p_inp_name)
{
	IplImage* p_cv_out = cvCreateImage(cvSize(sz_inp_wid_u32, sz_inp_hei_u32), IPL_DEPTH_8U, 3);
	INT08U* RESTRICT p_out_bgr_u08 = (INT08U* RESTRICT)&p_cv_out->imageData[0];

	INT32U pos_u32 = 0;
	INT08U ino_r_u08 = 0, ino_g_u08 = 0, ino_b_u08 = 0;
	
	for(pos_u32 = (sz_inp_hei_u32 * sz_inp_wid_u32) ; pos_u32 != 0 ; pos_u32--)
	{
		/* data load */
		ino_r_u08 = *p_inp_seq_r_u08++;
		ino_g_u08 = *p_inp_seq_g_u08++;
		ino_b_u08 = *p_inp_seq_b_u08++;
		/* data store */
		*p_out_bgr_u08++ = ino_b_u08;
		*p_out_bgr_u08++ = ino_g_u08;
		*p_out_bgr_u08++ = ino_r_u08;
	}
	cvSaveImage(p_inp_name, p_cv_out, 0); 
	
	CV_RELEASE(p_cv_out);
}

/*******************************************************************************
 * END OF FILE
 ******************************************************************************/
 