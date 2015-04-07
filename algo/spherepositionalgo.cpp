#include "SpherePositionAlgo.h"
#include "algo/ISpherePositionResultCallback.h"

#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

CvCapture* m_cam;


void SpherePositionAlgo::setResultCallback( ISpherePositionResultCallback *callback )
{
    this->callback = callback;

}

void SpherePositionAlgo::setFormat( int width, int height )
{

}



 void SpherePositionAlgo::getFrame (char *frame)
{
     int Hmin = 29;
     int Hmax = 85;

     int Smin = 96;
     int Smax = 169;

     int Vmin = 50;
     int Vmax = 230;


    m_cam = cvCreateCameraCapture(0); //cvCaptureFromCAM( 0 );
    assert( m_cam );


   cvSetCaptureProperty(m_cam, CV_CAP_PROP_FRAME_WIDTH, 640);//1280);
   cvSetCaptureProperty(m_cam, CV_CAP_PROP_FRAME_HEIGHT, 480);//960);

   IplImage* image = 0;
   image = cvCreateImage( cvGetSize(cvQueryFrame( m_cam )), IPL_DEPTH_8U, 3 );
   printf( "[i] channels:  %d\n",        image->nChannels );
   printf( "[i] pixel depth: %d bits\n",   image->depth );
   printf( "[i] width:       %d pixels\n", image->width );
   printf( "[i] height:      %d pixels\n", image->height );
   printf( "[i] image size:  %d bytes\n",  image->imageSize );
   printf( "[i] width step:  %d bytes\n",  image->widthStep );

    while(1)
    {

    image = cvQueryFrame( m_cam );


    m_findcolor.SetImage(image);

    m_findcolor.FindColorRangeHSV( Hmin,  Hmax,  Smin,  Smax,  Vmin,  Vmax);

    m_findobject.FindObject(m_findcolor.GetImage());

    m_findellipse.FindEllipse(m_findobject.GetCenter(),m_findobject.GetRadius(), image);

    std::cout << "R = " << m_findobject.GetRadius() << "x y = "<< m_findobject.GetCenter().x << " " << m_findobject.GetCenter().y
              << std::endl;

   // cvShowImage("frame",image);
    SixData sixData;
    sixData.m_a1 = m_findobject.GetRadius();
    sixData.m_a2 = m_findobject.GetRadius();
    sixData.x = m_findobject.GetCenter().x;
    sixData.y = m_findobject.GetCenter().y;
    sixData.m_b1 = m_findellipse.m_sixdata.m_b1;
    sixData.m_b2 = m_findellipse.m_sixdata.m_b2;

    std::cout << "b1 " << sixData.m_b1 << " b2 "<< sixData.m_b2 << std::endl;

    SpherePositionAlgoResult result;

    result.data = sixData;
    result.success  = true;
    callback->getResult(result);


    }




    // Processing Frame

}

