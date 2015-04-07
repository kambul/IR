#ifndef CFINDCOLOR_H
#define CFINDCOLOR_H
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

class CFindColor
{
public:
    CFindColor();
    void SetImage(IplImage *img);
    IplImage*  GetImage();
    void FindColorRangeHSV(int Hmin, int Hmax, int Smin, int Smax, int Vmin, int Vmax);
    ~CFindColor();
private:
    IplImage *m_image = 0;
    int Hmin, Hmax, Smin,Smax ,Vmin ,Vmax;   
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
