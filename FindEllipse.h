#ifndef CFINDELLIPSE_H
#define CFINDELLIPSE_H
#include <cv.h>
#include <highgui.h>



class CFindEllipse
{
public:
    CFindEllipse();
    void FindEllipse(CvPoint position, int radius);
    ~CFindEllipse();
};

#endif // FINDELLIPSE_H
