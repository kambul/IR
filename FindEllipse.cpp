#include "FindEllipse.h"
#include "FfindColor.h"

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

    IplImage *temp =  cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );

    //ищем по цвету маркер(крест)


    int Hmin = 0;
    int Hmax = 255;

    int Smin = 0;
    int Smax = 255;

    int Vmin = 60;
    int Vmax = 255;

//поиск креста по цвету
    CFindColor findcolor;

    findcolor.SetImage(image);

    findcolor.FindColorRangeHSV( Hmin,  Hmax,  Smin,  Smax,  Vmin,  Vmax);

    cvCanny( findcolor.GetImage(), temp, 0, 10, 5 );
//

    int a = 0,b = 0;
    if ( (global_p[2]>0))

    {

        if  ( ( cvRound( global_p[2])*m_size ) > (temp->width - (cvRound( global_p[0]) +cvRound( global_p[2]))*m_size ) )
        {
            a = (temp->width - (cvRound( global_p[0]) + cvRound( global_p[2]) )*m_size);
        }
        else
        {
            a = cvRound( global_p[2]) *m_size;
        }


        if  (( cvRound( global_p[2])*m_size) > (temp->height - (cvRound( global_p[1]) + cvRound( global_p[2]) )*m_size) )
        {
            b = (temp->height - (cvRound( global_p[1]) + cvRound( global_p[2]))*m_size);

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
            ((global_p[2]>0)&&(temp->height>global_p[2]))
    {
        cvSetImageROI(temp, cvRect(
                          abs(cvRound( global_p[0]) - a),
                      abs(cvRound( global_p[1]) - b),
                2*abs(a),//abs( cvRound( global_p[0] ) - cvRound( global_p[2]) ),
                2*abs(b)//abs(cvRound( global_p[1] )-cvRound( global_p[2]))
                )
                );


        IplImage* bin = 0;
        IplImage* bin2 = 0;

        bin = cvCreateImage(cvGetSize(temp), IPL_DEPTH_8U, 1);
        bin2 = cvCreateImage(cvGetSize(bin), IPL_DEPTH_8U, 1);
        cvZero(bin2);

        cvCopy(temp,bin);


        cvShowImage("bin",bin);

        cvResetImageROI(temp);
        //                          std::cout << "atan" << m_atan << "\n";
        // point = rand() % 10 + 1;

        IplImage *phase = cvCreateImage(cvSize( global_p[2]*2, 360), IPL_DEPTH_16U, 1);
        cvZero(phase);




        double sigma = 2;
        ///
        ////// \brief cont
        unsigned int cont = 0;
        int max_b =0;


        //gettimeofday(&tv0,0); //Получаем текущее время

        //struct timeval tv_n = tv0 ;
        // fout << tv0.tv_sec<< " "<< tv0.tv_usec << std::endl;



        for(int y = 0; y < bin->height; y ++)
        {
            if (cont>300) break;

            uchar* ptrG = (uchar*) (bin->imageData + y * bin->widthStep);
            uchar* ptr2 = (uchar*) (bin2->imageData + y * bin2->widthStep);

            for(int x=0; x < bin->width; x++)
            {
                if ((ptrG[x]>0)&&(rand() % 10)==1) //1 из 15

                {
                    ptr2[x] = 0xFFFFFFFF;
                    cont++;// это пиксель контура?

                    // рассмотрим все возможные элипсы, которые могут
                    // проходить через эту точку
                    int cont_fi = 0;
                    for(int fi = 0; fi < phase -> height; fi++)

                    { //перебираем все возможные t-до радиус вектора
                       //  if (cont_fi>180) break;
                        short* ptrP = (short*) (phase->imageData + fi * phase->widthStep);
                        max_b = 0;
                        for(int b = 0; b < phase->width/2; b ++)
                        {


                           if ((b==(phase->width))&&(max_b!=0))
                            {
                                ptrP[max_b] ++;
                                max_b = 0;

                            }


                           // int fi_b = fi+180;
                            //if (fi_b>360) fi_b=fi-360;

                            for(int t = 0 ; t < phase -> height/2; t=t+5 )
                                // for(int  l = 0 ; l < phase -> height/2;l=l+5 )

                            {
                                //int t = m_angl[fi+l];
                                //t = angle(t);
                                // перебираем все возможные b
                                // переводим градусы в радианы
                                ///////1 var
                                // x' = a\cos (\phi )\cos (\omega t) + b\sin (\phi )\sin (\omega t)
                                // y' = - a\sin (\phi )\cos (\omega t) + b\cos (\phi )\sin (\omega t)




                                float sigma_x = fabs(
                                            global_p[2]*m_cos[fi]*m_cos[t]
                                        + b*m_sin[fi]*m_sin[t]
                                        - (bin->width/2-x));

                                float sigma_y = fabs(
                                            b*m_sin[t]*m_cos[fi]
                                            - global_p[2]*m_sin[fi]*m_cos[t]
                                        - (bin->width/2-y));

                                /*double sigma_xy =
                                        fabs
                                        (
                                            m_sqrt_2*
                                            (
                                                global_p[2]*m_cos[fi+45]*m_cos[t]
                                        + b*m_sin[fi+45]*m_sin[t]
                                        )
                                        - (bin->width/2-y) - (bin->width/2-x)

                                        );
*/
                                // Если решение уравнения достаточно хорошее
                                if (
                                        (sigma_x < sigma)
                                        &&
                                        (sigma_y < sigma)
                                    )


                                {
                                    max_b = b;
                                    cont_fi ++;
                                    break;
                                }



                            }

                        }
                    }

                }
                //break;

            }

        }
        //cvSaveImage("bin2.jpg",bin2);
        //cvShowImage("bin2",bin2);
        //pout << "cont "<< cont<< std::endl;

        //cvReleaseImage(&phase);
        //cvReleaseImage(&phaseImage);
        //cvReleaseImage(&bin);

        // Выбираем точку фазового пространства которая набрала наибольшее число попаданий
        unsigned int MaxPhaseValue = 1;
        R=0;
        Theta = 0;

        float tempr[360];

        double    minval, maxval;
        CvPoint    minloc, maxloc;

        cvMinMaxLoc(phase, &minval, &maxval, &minloc, &maxloc, 0);


        for(int a=0; a<phase->height; a++)
        {
            //перебираем все возможные углы наклона

            short* ptrP = (short*) (phase->imageData + a * phase->widthStep);

            MaxPhaseValue = 1;
            for(int b=0; b<phase->width; b++)/////исправить 5ку, н число от радиуса
            { // перебираем все возможные расстояния от начала координат
                if(ptrP[b]>MaxPhaseValue)
                {

                    MaxPhaseValue = ptrP[b];
                    tempr[a] = ptrP[b];
                }


            }

        }

        long int maxArg = 2;
        long int max_a = 0;
        MaxPhaseValue =1;

        for(int a=1; a<phase->height; a++)
        {

            int tangl = a+90;
            if (tangl>360) tangl=tangl-360;

            long int ttt = tempr[a] * tempr[tangl];

            if( ttt > maxArg)
            {
                maxArg = ttt;
                max_a = a;
            }
            //pout <<a<<" "<< ttt << std::endl;

        }

        max_b =0;

        long int max_b2 =0;

        long int tangl = max_a+90;

        if (tangl>360) tangl=tangl-360;


        unsigned int MaxPhaseValue1 =1;
        for(int a=1; a<phase->height; a++)
        { //перебираем все возможные углы наклона
            short* ptrP = (short*) (phase->imageData + a * phase->widthStep);
            for(int b=1; b<phase->width; b++)/////исправить 5ку, н число от радиуса
            { // перебираем все возможные расстояния от начала координат
                if(abs (a - max_a)<2)
                {

                    if (ptrP[ b]> MaxPhaseValue)
                    {
                        max_b=b;
                        MaxPhaseValue = ptrP[b];
                    }

                }

                if(abs(a - tangl)<2)
                {

                    if (ptrP[ b]> MaxPhaseValue1)
                    {
                        max_b2=b;
                        MaxPhaseValue1 = ptrP[b];
                    }

                }
                ptrP[ b] =(255/maxval)*ptrP[b];
                // tempr[a] = tempr[a]+ptrP[b];
            }
        }

        cvSaveImage("phase.jpg",phase);
        std ::cout << " maxval =" << maxval  << "b=" << max_b << "a" << global_p[2] << std::endl;

        Theta =max_a;
        R=max_b;
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

            cvSaveImage("bin2_n_xy1.jpg",bin2);

            // if  (Theta>180)  Theta = Theta-180;

            b_n[1] = R;
            t_n[1] = Theta;
            b_n[2] = max_b2;
            t_n[2] = tangl;

            m_sixdata.m_a1 = radius;
            m_sixdata.m_a2 = radius;
            m_sixdata.m_b1 = R;
            m_sixdata.m_b2 = max_b2;
            m_sixdata.m_angl1 = t_n[1];
            m_sixdata.m_angl2 = t_n[2];




            //  cvLine( rgb, cvPoint(global_p[0],global_p[1]),  cvPoint(global_p[0]+(R*cos((Theta+90)*CV_PI/180.0)),global_p[1]+fabs(R*sin((Theta+90)*CV_PI/180.0))), CV_RGB(0,255,0), 1, CV_AA, 0 );
            cvZero(phase);
            cvZero(bin2);
            //cvEllipse( rgb, cvPoint( 200, 200 ), cvSize( 150.0, 50.0 ), 135, 0, 360, cvScalar( 0, 255, 0 ), 1, 8 );
            //pout << "naklon1 = " << (R*cos((Theta+90)*CV_PI/180.0)) << " " << (R*sin((Theta+90)*CV_PI/180.0)) <<  " T " << Theta<< " R "<< R << "cont" << cont<< std::endl;
            if ( ((t_n[1] >45 ) && (t_n[1] <135))|| ((t_n[1] >225 ) && (t_n[1] <315)) )
            {
                cvEllipse(image, cvPoint( cvRound(position.x) , cvRound(position.y) ), cvSize(cvRound(radius),b_n[1]),- t_n[1], 0,  360, CV_RGB(255,0,0), 1, 8  );
            }

            if ( ((t_n[2] >45 ) && (t_n[2] <135))|| ((t_n[2] >225 ) && (t_n[2] <315)) )
            {
                cvEllipse(image, cvPoint( cvRound(position.x) , cvRound(position.y) ), cvSize(cvRound(radius),b_n[2]),- t_n[2], 0,  360, CV_RGB(255,0,0), 1, 8  );
            }

            if ( ((t_n[1] >315 ) || (t_n[1] <45))|| ((t_n[1] >135 ) && (t_n[1] <225)) )
            {
                cvEllipse(image, cvPoint( cvRound(position.x) , cvRound(position.y) ), cvSize(cvRound(radius),b_n[1]),- t_n[1], 0,  360, CV_RGB(0,255,0), 1, 8  );

            }
            if ( ((t_n[2] >315 ) || (t_n[2] <45))|| ((t_n[2] >135 ) && (t_n[2] <225)) )
            {
                cvEllipse(image, cvPoint( cvRound(position.x) , cvRound(position.y) ), cvSize(cvRound(radius),b_n[2]),- t_n[2], 0,  360, CV_RGB(0,255,0), 1, 8  );

            }


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




