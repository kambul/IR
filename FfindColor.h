#ifndef CFINDCOLOR_H
#define CFINDCOLOR_H
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>


class CFindColor
{
public:
    CFindColor(IplImage *image);
    void SetImage(IplImage *image);
    void GetImage();
    void FindColorRangeHSV(int Hmin, int Hmax, int Smin, int Smax, int Vmin, int Vmax);
    ~CFindColor();
private:
    IplImage *m_image;
    int Hmin, Hmax, Smin,Smax ,Vmin ,Vmax;   
    IplImage* frame=0;
    IplImage* h_range = 0;
    IplImage* s_range = 0;
    IplImage* v_range = 0;
    IplImage* hsv_and = 0;
    IplImage* hsv = 0;
    IplImage* h_plane = 0;
    IplImage* s_plane = 0;
    IplImage* v_plane = 0;


};

#endif // CFINDCOLOR_H
