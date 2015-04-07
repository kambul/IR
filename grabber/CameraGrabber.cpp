#include "grabber/CameraGrabber.h"
#include <pthread.h>
#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
bool CameraGrabber::m_stopFlag;
CvCapture* m_capture;




  void *CameraGrabber::grabberThradCycle(void*)
 {

      //cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 640);//1280);
      //cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 480);//960);


   //   while(!m_stopFlag)


     {

         //sleep(1000);///
         std::cout << "work\n";



         //opcv обработка
       //  callback->getFrame(m_CameraGrabberFrame);
     }

 }

void CameraGrabber::setResultCallback( ICameraGrabberResultCallback *callback )
{
   this->callback = callback;
}

void CameraGrabber::start()
{
  //   m_capture = cvCreateCameraCapture(CV_CAP_ANY); //cvCaptureFromCAM( 0 );
    //assert( m_capture );
    m_stopFlag = false;
    //IplImage* frame = 0;

//     frame = cvQueryFrame( m_capture );
  //   cvShowImage("frame",frame);

   pthread_create(&m_grabberThread, NULL,CameraGrabber::grabberThradCycle, NULL);


}

void CameraGrabber::stop()
{
    m_stopFlag = true;
}
