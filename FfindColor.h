#ifndef CFINDCOLOR_H
#define CFINDCOLOR_H
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>


class CFindColor
{
public:
    CFindColor();
    void SetImage(IplImage *image);
    void GetImage();
    void FindColorRangeHSV(int Hmin, int Hmax, int Smin, int Smax, int Vmin, int Vmax);
    ~CFindColor();
private:
    IplImage *m_image;
    int Hmin, Hmax, Smin,Smax ,Vmin ,Vmax;


};

#endif // CFINDCOLOR_H
