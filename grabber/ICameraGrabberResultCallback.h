
#ifndef ICAMERAGRABBERRESULTCALLBACK_H
#define ICAMERAGRABBERRESULTCALLBACK_H

#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>


class ICameraGrabberResultCallback
{
public:
   virtual void getFrame ( char *frame) = 0;

};

#endif


