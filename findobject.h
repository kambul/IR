#ifndef CFINDOBJECT_H
#define CFINDOBJECT_H
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>


class CFindObject
{
public:
    CFindObject();
    bool FindObject(IplImage* image);

    CvPoint GetCenter();
    int GetRadius();

    ~CFindObject();
private:
    int m_radius;
    CvPoint m_xyPoint;
    int Max_contr[3] = {0,0,0};
    CvMemStorage* storagec = cvCreateMemStorage(0);
    CvSeq* contours=0, *seq=0;
};

#endif // CFINDOBJECT_H
