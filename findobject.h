#ifndef CFINDOBJECT_H
#define CFINDOBJECT_H
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>


class CFindObject
{
public:
    CFindObject();
    bool FindObject(IplImage* image);
    ~CFindObject();
private:
    int m_radius;
    CvPoint m_xyPoint;
};

#endif // CFINDOBJECT_H
