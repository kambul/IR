#ifndef CAMERAGRABBER_H
#define CAMERAGRABBER_H
#include "grabber/ICameraGrabberResultCallback.h"

class CameraGrabber
{
public:
   void start();
   void stop();

   void setResultCallback( ICameraGrabberResultCallback callback );

private:
   ICameraGrabberResultCallback callback;

};

#endif
