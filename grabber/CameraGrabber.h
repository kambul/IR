#ifndef CAMERAGRABBER_H
#define CAMERAGRABBER_H
#include "grabber/ICameraGrabberResultCallback.h"
#include <pthread.h>



class CameraGrabber
{
public:
   void start();
   void stop();


   void setResultCallback(ICameraGrabberResultCallback *callback );
   static void *grabberThradCycle(void *);

private:
   ICameraGrabberResultCallback *callback;
   char* m_CameraGrabberFrame;
    pthread_t m_grabberThread;
    static bool m_stopFlag;

};

#endif
