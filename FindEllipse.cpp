#include "FindEllipse.h"
#include "FfindColor.h"
#include <fstream>
CFindEllipse::CFindEllipse()
{
    for(int m_t = 0; m_t<720; m_t ++)
    {       if (m_t > 360)
        {

            m_angl[m_t] = m_t-360;
        }
        else
        {
            m_angl[m_t] = m_t;
        }

        m_sin[m_t]=sin(m_t*CV_PI/180.0);
        m_cos[m_t]=cos(m_t*CV_PI/180.0);
    }
    m_sqrt_2 = sqrt(2);
}

CFindEllipse::~CFindEllipse()
{

}
void CFindEllipse::FindEllipse(CvPoint position, int radius, IplImage *image)
{



    float m_size = 0.8;


    double b_n[4] = {0,0,0,0};
    double t_n[4] = {0,0,0,0};

    int global_p[3] = {0,0,0};
    global_p[0] = position.x;
    global_p[1] = position.y;
    global_p[2] = radius;

    float Theta=0;
    int R=0;

    IplImage *temp_1 =  cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );
     IplImage *temp_2 =  cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );

    //ищем по цвету маркер(крест)


    int Hmin = 0;
    int Hmax = 20;

    int Smin = 10;
    int Smax = 255;

    int Vmin = 0;
    int Vmax = 250;
    //вторая полоска

    int Hmin_2 = 94;
    int Hmax_2 = 113;

    int Smin_2 = 69;
    int Smax_2 = 255;

    int Vmin_2 = 4;
    int Vmax_2 = 255;

//поиск креста по цвету
    CFindColor findcolor;

    findcolor.SetImage(image);

    findcolor.FindColorRangeHSV( Hmin,  Hmax,  Smin,  Smax,  Vmin,  Vmax);

   // cvCanny( findcolor.GetImage(), temp_1, 0, 10, 5 );
    cvCopy(findcolor.GetImage(), temp_1);


    findcolor.FindColorRangeHSV( Hmin_2,  Hmax_2,  Smin_2,  Smax_2,  Vmin_2,  Vmax_2);

     //cvCanny( findcolor.GetImage(), temp_2, 0, 10, 5 );
    cvCopy(findcolor.GetImage(), temp_2);
//

    int a = 0,b = 0;
    if ( (global_p[2]>0))

    {

        if  ( ( cvRound( global_p[2])*m_size ) > (image->width - (cvRound( global_p[0]) +cvRound( global_p[2]))*m_size ) )
        {
            a = (image->width - (cvRound( global_p[0]) + cvRound( global_p[2]) )*m_size);
        }
        else
        {
            a = cvRound( global_p[2]) *m_size;
        }


        if  (( cvRound( global_p[2])*m_size) > (image->height - (cvRound( global_p[1]) + cvRound( global_p[2]) )*m_size) )
        {
            b = (image->height - (cvRound( global_p[1]) + cvRound( global_p[2]))*m_size);

        }
        else
        {
            b = cvRound( global_p[2]) *m_size;

        }
        std::cout <<"a " << a << " b  " << b << "\n";

        // printf( "[i]a%f\n", a );
        //printf( "[i]b%f\n", b );

        // cvSetImageROI(temp, cvRect(cvRound( global_p[0]) - (cvRound( global_p[0]) - cvRound( global_p[2]))*2 ,cvRound( global_p[1]) - (cvRound( global_p[1]) - cvRound( global_p[2]))*2, a,b) );
        //cvRectangle( gray, pt, cvPoint( cvRound( p[2]) , cvRound( p[2]) ), CV_RGB(0xff,0,0) );
        // global_p[0] = 0;
        // global_p[1] = 0;
        //global_p[2] = 0;
    }

    //поиск элипса
    if
            ((global_p[2]>0)&&(image->height>global_p[2]))
    {
        cvSetImageROI(temp_1, cvRect(
                          abs(cvRound( global_p[0]) - a),
                      abs(cvRound( global_p[1]) - b),
                2*abs(a),//abs( cvRound( global_p[0] ) - cvRound( global_p[2]) ),
                2*abs(b)//abs(cvRound( global_p[1] )-cvRound( global_p[2]))
                )
                );
        cvSetImageROI(temp_2, cvRect(
                          abs(cvRound( global_p[0]) - a),
                      abs(cvRound( global_p[1]) - b),
                2*abs(a),//abs( cvRound( global_p[0] ) - cvRound( global_p[2]) ),
                2*abs(b)//abs(cvRound( global_p[1] )-cvRound( global_p[2]))
                )
                );




        IplImage* bin_1 = 0;
        IplImage* bin_2 = 0;

        IplImage* bin2_1 = 0;
        IplImage* bin2_2 = 0;

        bin_1 = cvCreateImage(cvGetSize(temp_1), IPL_DEPTH_8U, 1);
        bin_2 = cvCreateImage(cvGetSize(temp_2), IPL_DEPTH_8U, 1);

        bin2_1 = cvCreateImage(cvGetSize(bin_1), IPL_DEPTH_8U, 1);
        bin2_2 = cvCreateImage(cvGetSize(bin_1), IPL_DEPTH_8U, 1);


        cvZero(bin2_1);
        cvZero(bin2_2);

        cvCopy(temp_1,bin_1);
        cvCopy(temp_2,bin_2);



       // cvShowImage("bin",bin);

        cvResetImageROI(temp_1);
        cvResetImageROI(temp_2);
        //                          std::cout << "atan" << m_atan << "\n";
        // point = rand() % 10 + 1;

       // IplImage *phase = cvCreateImage(cvSize( global_p[2]*2, 360), IPL_DEPTH_16U, 1);

         IplImage *phase_1 = cvCreateImage(cvSize( global_p[2]*2, 360), IPL_DEPTH_16U, 1);
         IplImage *phase_2 = cvCreateImage(cvSize( global_p[2]*2, 360), IPL_DEPTH_16U, 1);

        cvZero(phase_1);
        cvZero(phase_2);
        int rad = global_p[2]*m_size;

         int size_rand = 1;

            int del_global = global_p[2] / 10 ;
            size_rand = (del_global - 6)*3;





        for(int y = 0; y < bin_1->height; y ++)
        {
            uchar* ptrG_1 = (uchar*) (bin_1->imageData + y * bin_1->widthStep);//первая метка
            uchar* ptrG_2 = (uchar*) (bin_2->imageData + y * bin_2->widthStep);//вторая метка
            for(int x=0; x < bin_1->width; x++)
            {
                if ( (x-rad)*(x-rad) + (y-rad)*(y-rad) - rad*rad > 1)
                {
                   ptrG_1[x] = 0;
                   ptrG_2[x] = 0;
                }
            }
        }





        double sigma = 2;
        ///
        ////// \brief cont
        unsigned int cont = 0;
        int max_b =0;


        //gettimeofday(&tv0,0); //Получаем текущее время

        //struct timeval tv_n = tv0 ;
        // fout << tv0.tv_sec<< " "<< tv0.tv_usec << std::endl;



        for(int y = 0; y < bin_1->height; y ++)
        {
            if (cont>200) break;
            uchar* ptrG_1 = (uchar*) (bin_1->imageData + y * bin_1->widthStep);//первая метка
            uchar* ptrG_2 = (uchar*) (bin_2->imageData + y * bin_2->widthStep);//вторая метка

            uchar* ptr2_1 = (uchar*) (bin2_1->imageData + y * bin2_1->widthStep);
            uchar* ptr2_2 = (uchar*) (bin2_2->imageData + y * bin2_2->widthStep);

            for(int x=0; x < bin_1->width; x++)
            {
                if ((ptrG_1[x]>0)&&((rand() % size_rand)==1)) //1 из 8 // это пиксель контура?
                {
                    ptr2_1[x] = 0xFFFFFFFF;
                    cont++;

                    // рассмотрим все возможные элипсы, которые могут
                    // проходить через эту точку
                    int cont_fi = 0;

                    for(int fi = 0; fi < phase_1 -> height; fi++)
                    {
                        //перебираем все возможные t-до радиус вектора
                       //  if (cont_fi>180) break;
                        short* ptrP_1 = (short*) (phase_1->imageData + fi * phase_1->widthStep);

                        int Zero_t = 0;
                        for(int b = 0; b < phase_1->width/2; b ++)
                        {

                            for(int t = Zero_t ; t < phase_1 -> height/2; t=t+4 )

                            {

                                ///////1 var
                                // x' = a\cos (\phi )\cos (\omega t) + b\sin (\phi )\sin (\omega t)
                                // y' = - a\sin (\phi )\cos (\omega t) + b\cos (\phi )\sin (\omega t)




                                float sigma_x = fabs(
                                            global_p[2]*m_cos[fi]*m_cos[t]
                                        + b*m_sin[fi]*m_sin[t]
                                        - (bin_1->width/2-x));

                                float sigma_y = fabs(
                                            b*m_sin[t]*m_cos[fi]
                                            - global_p[2]*m_sin[fi]*m_cos[t]
                                        - (bin_1->width/2-y));


                                // Если решение уравнения достаточно хорошее
                                if (
                                        (sigma_x < sigma)
                                        &&
                                        (sigma_y < sigma)
                                    )


                                {
                                    if(b-1 >0)
                                    {
                                    ptrP_1[abs(b-1)] = ptrP_1[abs(b-1)] + 1;
                                    }
                                    ptrP_1[b] = ptrP_1[b] + 3;

                                    if(b+1 <= phase_1->width/2)
                                    {
                                    ptrP_1[b+1] = ptrP_1[b+1] + 1;
                                    }
                                    else
                                    {
                                    }

                                    cont_fi ++;
                                    Zero_t = abs(t-8);//8 выбранно пока из отклонения 2шаgа

                                    break;

                                }



                            }

                        }
                    }

                }
                //break;
                ////////////////

                if ((ptrG_2[x]>0)&&((rand() % size_rand)==1)) //1 из 4 // это пиксель контура?
                {
                    ptr2_2[x] = 0xFFFFFFFF;
                    cont++;

                    // рассмотрим все возможные элипсы, которые могут
                    // проходить через эту точку
                    int cont_fi = 0;

                    for(int fi = 0; fi < phase_2 -> height; fi++)
                    {
                        //перебираем все возможные t-до радиус вектора
                       //  if (cont_fi>180) break;
                        short* ptrP_2 = (short*) (phase_2->imageData + fi * phase_2->widthStep);

                        int Zero_t = 0;
                        for(int b = 0; b < phase_2->width/2; b ++)
                        {

                            for(int t = Zero_t ; t < phase_2 -> height/2; t=t+4 )

                            {

                                ///////1 var
                                // x' = a\cos (\phi )\cos (\omega t) + b\sin (\phi )\sin (\omega t)
                                // y' = - a\sin (\phi )\cos (\omega t) + b\cos (\phi )\sin (\omega t)




                                float sigma_x = fabs(
                                            global_p[2]*m_cos[fi]*m_cos[t]
                                        + b*m_sin[fi]*m_sin[t]
                                        - (bin_2->width/2-x));

                                float sigma_y = fabs(
                                            b*m_sin[t]*m_cos[fi]
                                            - global_p[2]*m_sin[fi]*m_cos[t]
                                        - (bin_2->width/2-y));


                                // Если решение уравнения достаточно хорошее
                                if (
                                        (sigma_x < sigma)
                                        &&
                                        (sigma_y < sigma)
                                    )


                                {
                                    if(b-1 >0)
                                    {
                                    ptrP_2[abs(b-1)] = ptrP_2[abs(b-1)] + 1;
                                    }
                                    ptrP_2[b] = ptrP_2[b] + 3;

                                    if(b+1 <= phase_2->width/2)
                                    {
                                    ptrP_2[b+1] = ptrP_2[b+1] + 1;
                                    }
                                    else
                                    {
                                    }

                                    cont_fi ++;
                                    Zero_t = abs(t-8);//8 выбранно пока из отклонения 2шаgа

                                    break;

                                }



                            }

                        }
                    }

                }

            }

        }
        //cvSaveImage("bin2.jpg",bin2);
        //cvShowImage("bin2",bin2);
        //pout << "cont "<< cont<< std::endl;

        //cvReleaseImage(&phase);
        //cvReleaseImage(&phaseImage);
        //cvReleaseImage(&bin);

        // Выбираем точку фазового пространства которая набрала наибольшее число попаданий
        unsigned int MaxPhaseValue_1 = 1;
        unsigned int MaxPhaseValue_2 = 1;
        R=0;
        Theta = 0;

        float tempr_1[360];
        float tempr_2[360];

        double    minval, maxval;
        CvPoint    minloc, maxloc;

        cvMinMaxLoc(phase_1, &minval, &maxval, &minloc, &maxloc, 0);


        for(int a=0; a<phase_1->height; a++)
        {
            //перебираем все возможные углы наклона

            short* ptrP_1 = (short*) (phase_1->imageData + a * phase_1->widthStep);
            short* ptrP_2 = (short*) (phase_2->imageData + a * phase_2->widthStep);

            MaxPhaseValue_1 = 1;
            MaxPhaseValue_2 = 1;
            tempr_1[a] = 0;
            tempr_2[a] = 0;
            for(int b=0; b<phase_1->width; b++)/////исправить 5ку, н число от радиуса
            { // перебираем все возможные расстояния от начала координат и находим наибольшее число попаданий по b для данноgо f
                if(ptrP_1[b]>MaxPhaseValue_1)
                {
                    MaxPhaseValue_1 = ptrP_1[b];
                    tempr_1[a] =  MaxPhaseValue_1; ///////////1

                }

                if(ptrP_2[b]> MaxPhaseValue_2)
                {

                    MaxPhaseValue_2 = ptrP_2[b];
                    tempr_2[a] =  MaxPhaseValue_2;///////////2
                }


            }

        }

        long int maxArg = 2;
        long int max_a = 0;
        long int max_a2 = 0;
        MaxPhaseValue_1 =1;


        for(int a=0; a<phase_1->height; a++)
        {

            for (int delta = -3; delta < 3; delta ++)
            {
            int tangl = a+90+delta;
            if (tangl>360) tangl=tangl-360;
            if (tangl<0) tangl=360 + tangl;
            //std::cout <<" t1 ="<< a<<" " << tempr_1[a] << "  ";
            //std::cout <<" t2 ="<<a<< " " << tempr_2[a]<< std::endl;

            long int ttt_1 = tempr_1[a] * tempr_2[tangl];
            long int ttt_2 = tempr_2[a] * tempr_1[tangl];

            if( ttt_1 > maxArg)
            {
                if( ttt_1 > ttt_2)
                {
                maxArg = ttt_1;
                max_a = a;
                t_n[1] = a;
                t_n[2] = tangl;
                //max_a2 = 0;
                }
            }
            if( ttt_2 > maxArg)
            {
                if( ttt_2 > ttt_1)
                {
                    t_n[2] = a;
                    t_n[1] = tangl;
                maxArg = ttt_2;
                max_a = a;
               // max_a2 = a;
                }
            }
            }
            //pout <<a<<" "<< ttt << std::endl;

        }


        max_b =0;

        long int max_b2 =0;

        long int tangl = max_a+90;

        if (tangl>360) tangl=tangl-360;


        unsigned int MaxPhaseValue =1;
        unsigned int MaxPhaseValue1 =1;

        for(int a=1; a<phase_1->height; a++)

        { //перебираем все возможные углы наклона
            short* ptrP_1 = (short*) (phase_1->imageData + a * phase_1->widthStep);
            short* ptrP_2 = (short*) (phase_2->imageData + a * phase_2->widthStep);

            for(int b=1; b<phase_1->width/2; b++)/////исправить 5ку, н число от радиуса
            { // перебираем все возможные расстояния от начала координат
                if(abs (a - max_a)<=2)
                {

                    if (ptrP_1[b] > MaxPhaseValue)
                    {
                        max_b = b;
                        MaxPhaseValue = ptrP_1[b];

                    }

                    if (ptrP_2[b] > MaxPhaseValue1)
                    {
                        max_b2=b;
                        MaxPhaseValue1 = ptrP_2[b];


                    }

                }

                if(abs(a - tangl)<=2)
                {

                    if (ptrP_1[ b] > MaxPhaseValue)
                    {
                        max_b=b;
                        MaxPhaseValue = ptrP_1[b];

                    }
                    if (ptrP_2[ b] > MaxPhaseValue1)
                    {
                        max_b2 = b;
                        MaxPhaseValue1 = ptrP_2[b];

                    }

                }
                ptrP_1[ b] =(255/maxval)*ptrP_1[b];
                ptrP_2[ b] =(255/maxval)*ptrP_2[b];
                // tempr[a] = tempr[a]+ptrP[b];
            }
        }

        cvSaveImage("phase1.jpg",phase_1);
        cvSaveImage("phase2.jpg",phase_2);

        std ::cout << " maxph =" << MaxPhaseValue << "  " << MaxPhaseValue1 << "b=" << max_b << "a" << global_p[2] << "max b1 " << max_b << "max b2 " << max_b2 << "rand =" << size_rand<< std::endl;

        //Theta =max_a;
       // R=max_b;
        /*
        oid ellipse(Mat& img, const RotatedRect& box, const Scalar& color, int thickness=1, int lineType=8)

        C: void cvEllipse(CvArr* img, CvPoint center, CvSize axes, double angle, double start_angle, double end_angle, CvScalar color, int thickness=1, int line_type=8, int shift=0 )
        C: void cvEllipseBox(CvArr* img, CvBox2D box, CvScalar color, int thickness=1, int line_type=8, int shift=0 )
        Python: cv.EllipseBox(img, box, color, thickness=1, lineType=8, shift=0) → None
        Parameters:
        img – Image.
        center – Center of the ellipse.
        axes – Half of the size of the ellipse main axes.
        angle – Ellipse rotation angle in degrees.
        startAngle – Starting angle of the elliptic arc in degrees.
        endAngle – Ending angle of the elliptic arc in degrees.
        box – Alternative ellipse representation via RotatedRect or CvBox2D. This means that the function draws an ellipse inscribed in the rotated rectangle.
        color – Ellipse color.
        thickness – Thickness of the ellipse arc outline, if positive. Otherwise, this indicates that a filled ellipse sector is to be drawn.
        lineType – Type of the ellipse boundary. See the line() description.
        shift – Number of fractional bits in the coordinates of the center and values of axes.
        */

        if (cont > 45)
        {

            cvSaveImage("bin2_n_xy1.jpg",bin2_2);
            cvSaveImage("bin2_n_xy12.jpg",bin2_1);

            // if  (Theta>180)  Theta = Theta-180;

            b_n[1] = max_b;
            //t_n[1] = Theta;
            b_n[2] = max_b2;
            //t_n[2] = tangl;

            m_sixdata.m_a1 = radius;
            m_sixdata.m_a2 = radius;
            m_sixdata.m_b1 = max_b;
            m_sixdata.m_b2 = max_b2;
            m_sixdata.m_angl1 = t_n[1];
            m_sixdata.m_angl2 = t_n[2];
            if (maxArg <20)
            {
            m_sixdata.m_a1 = 0;
            m_sixdata.m_a2 = 0;
            m_sixdata.m_b1 = 0;
            m_sixdata.m_b2 = 0;
            m_sixdata.m_angl1 = 0;
            m_sixdata.m_angl2 = 0;
            }




            //  cvLine( rgb, cvPoint(global_p[0],global_p[1]),  cvPoint(global_p[0]+(R*cos((Theta+90)*CV_PI/180.0)),global_p[1]+fabs(R*sin((Theta+90)*CV_PI/180.0))), CV_RGB(0,255,0), 1, CV_AA, 0 );
            //cvZero(phase_1);
            //cvZero(bin2);
            //cvEllipse( rgb, cvPoint( 200, 200 ), cvSize( 150.0, 50.0 ), 135, 0, 360, cvScalar( 0, 255, 0 ), 1, 8 );
            //pout << "naklon1 = " << (R*cos((Theta+90)*CV_PI/180.0)) << " " << (R*sin((Theta+90)*CV_PI/180.0)) <<  " T " << Theta<< " R "<< R << "cont" << cont<< std::endl;

                cvEllipse(image, cvPoint( cvRound(position.x) , cvRound(position.y) ), cvSize(cvRound(radius),b_n[1]),- t_n[1], 0,  360, CV_RGB(255,0,0), 1, 8  );


                cvEllipse(image, cvPoint( cvRound(position.x) , cvRound(position.y) ), cvSize(cvRound(radius),b_n[2]),- t_n[2], 0,  360, CV_RGB(0,255,0), 1, 8  );



        }








        //pout << "///////////////////////////////////\n T =" ;
        //                cvShowImage("phase",bin2);

        //<< Theta << "B=" << R << "\n";
        // sleep(10);

        // IplImage* phaseImage = cvCreateImage( cvSize(phase->width*3, phase->height*3), IPL_DEPTH_8U, 1);

        //cvResize(phase, phaseImage);              // нормировка
        //double scaler = 0xFFFFFFFF/(float)MaxPhaseValue;
        /*  for(int y=0; y<phase->height; y++)
        {

            short* ptr = (short*) (phase->imageData + y * phase->widthStep);
            for(int x=0; x<phase->width; x++)
            {
                if (ptr[x] !=0)
                {
                     fout << "ptr x y=" << (int)  x << " " << y << " " << (int)  ptr[x] << " " << scaler <<  " " << (unsigned int)  MaxPhaseValue << "\n";
                }

                ptr[x]=  0xFFFFFFFF;//(float)MaxPhaseValue;
            }


        }
        */
        // cvNamedWindow( "phaseImage2", 1 );
         cvDestroyAllWindows();
         cvShowImage( "im", image);





    }


}




