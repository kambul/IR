#include "findobject.h"

#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

CFindObject::CFindObject()
{
}

CFindObject::~CFindObject()
{

}

int CFindObject::GetRadius()
{
    return Max_contr[2];
}

CvPoint CFindObject::GetCenter()
{
    CvPoint point;
    point.x = Max_contr[0];
    point.y = Max_contr[1];

    return point;
}

bool CFindObject::FindObject(IplImage *image)
{
    Max_contr[0] = 0;
    Max_contr[1] = 0;
    Max_contr[2] = 0;

    IplImage *temp =  cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );

    cvCopy(image, temp);

            // находим контуры


    int radius = 1;
    IplConvKernel* Kern = cvCreateStructuringElementEx(radius*2+1, radius*2+1, 1, 1, CV_SHAPE_ELLIPSE);



     cvSmooth(image, image, CV_BLUR_NO_SCALE  , 5, 5);
     cvDilate(image, image, Kern, 4);
     //cvShowImage("gray",image);

            int contoursCont = cvFindContours( image, storagec, &contours, sizeof(CvContour), CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));


            if(!contours){
                   printf("[!] Error: cant find contours!\n");
            }
            printf("[i] contours: %d \n", contoursCont);


            // нарисуем контуры
          /*  for(seq = contours; seq!=0; seq = seq->h_next)
            {
                   cvDrawContours(temp, seq, CV_RGB(255,216,0), CV_RGB(0,0,250), 0, 1, 4); // рисуем контур

            }
            */
            //int cluster_count = MAX_CLUSTERS;
                            int sample_count = contoursCont;
                            //int i, j, k;
                            int k=0;
                            double maX = 0 ;
                            CvMat* points = cvCreateMat( sample_count, 1, CV_32FC2 );
                            CvMat* clusters = cvCreateMat( sample_count, 1, CV_32SC1 );

                            std::vector<CvPoint2D32f> m_center;
                            std::vector<float> m_radis;
                            std::vector<float> contr_sqr;
                            float sqr_max=0;

                            for(k=0, seq = contours; seq!=0; seq = seq->h_next, k++)
                            {
                                    CvPoint2D32f center = cvPoint2D32f(0, 0);
                                    float radius=0;
                                    // определяем окружность заключающую в себе контур
                                    cvMinEnclosingCircle(seq, &center, &radius);
                                    m_center.push_back(center);
                                    m_radis.push_back( radius);
                                    contr_sqr.push_back(0);
                            }


            // определяем точки контуров


                            for(int y=0; y<image->height; y++)
                            {
                                uchar* ptrP = ( uchar*) (image->imageData + y * (image->widthStep));

                                for(int x=0; x< image->width; x++)
                                {

                                    if( ptrP[x] >0)
                                    {




                                        for(k=0, seq = contours; seq!=0; seq = seq->h_next, k++)
                                        {
                                            int x0 = x - m_center[k].x;
                                            int y0 = y - m_center[k].y;
                                            if ( ( x0*x0 + y0*y0 - m_radis[k]*m_radis[k]) < 1)//проверяем лежит ли внутри круа
                                            {

                                                contr_sqr[k] ++;
                                            }

                                        }

                                    }


                                }
                            }


                            for(k=0, seq = contours; seq!=0; seq = seq->h_next, k++)
                            {
                                if ((m_radis[k] > image->height/8) && ( m_radis[k] > Max_contr[2])&&( m_radis[k]< image->height))
                                {

                                    if ((contr_sqr[k]/m_radis[k]/m_radis[k] / 3.14 >sqr_max)&&(contr_sqr[k]/m_radis[k]/m_radis[k] / 3.14 > 0.69 ))
                                    {
                                        Max_contr[0] = m_center[k].x;
                                        Max_contr[1] = m_center[k].y;
                                        Max_contr[2] = m_radis[k];
                                        sqr_max = contr_sqr[k]/m_radis[k]/m_radis[k] / 3.14 ; //отношение эксп к теор
                                       // cvCircle( image, cvPointFrom32f(center), radius, CV_RGB(255,255,255));//, CV_FILLED );
                                    }  // запихиваем в массив
                                }
                                cvCircle( temp, cvPoint(Max_contr[0], Max_contr[1]), Max_contr[2], CV_RGB(0,0,255));
                                cvDestroyAllWindows();

                            }
                             cvShowImage("temp",temp);

}
