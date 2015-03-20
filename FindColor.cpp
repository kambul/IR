#include "FfindColor.h"
#include <cv.h>
#include <highgui.h>

CFindColor::CFindColor(IplImage *image)
{
    h_plane = cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );
    s_plane = cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );
    v_plane = cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );
    h_range = cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );
    s_range = cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );
    v_range = cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );
    hsv_and = cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );
}

CFindColor::~CFindColor()
{

}

void CFindColor::FindColorRangeHSV(int Hmin, int Hmax, int Smin, int Smax, int Vmin, int Vmax)
{

cvCvtColor( m_image, hsv, CV_BGR2HSV );
cvCvtPixToPlane( hsv, h_plane, s_plane, v_plane, 0 );
cvInRangeS(v_plane, cvScalar(Vmin), cvScalar(Vmax), v_range);
cvInRangeS(s_plane, cvScalar(Smin), cvScalar(Smax), s_range);
cvInRangeS(h_plane, cvScalar(Hmin), cvScalar(Hmax), h_range);

}
