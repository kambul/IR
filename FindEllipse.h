#ifndef CFINDELLIPSE_H
#define CFINDELLIPSE_H
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "algo/SixData.h"



class CFindEllipse
{
public:

    CFindEllipse();
    void FindEllipse(CvPoint position, int radius, IplImage *image);
    ~CFindEllipse();
      SixData m_sixdata;
private:
    float m_sin[730];
    float m_cos[730];
    int m_angl[730];
    float m_sqrt_2;


};

#endif // FINDELLIPSE_H
