#include "FindEllipse.h"

CFindEllipse::CFindEllipse()
{

}

CFindEllipse::~CFindEllipse()
{

}
/*
global_p[0] = Max_contr[0];
global_p[1] = Max_contr[1];
global_p[2] = Max_contr[2];

std::cout << "p0 " << global_p[0] <<  "p1 " << global_p[1] <<  "p2 " << global_p[2]<< "\n" ;
int a,b;
// std::cout << "p0-- " << cvRound( global_p[0]) <<  "p1-- " << cvRound( global_p[1]) <<  "p2-- " << cvRound( global_p[2]) ;
if ( //((cont % 10) == 0)&&
     (global_p[2]>0))

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
  ////  cvDestroyAllWindows();

    cvShowImage("bin",bin);

    cvResetImageROI(temp);
    //                          std::cout << "atan" << m_atan << "\n";
    // point = rand() % 10 + 1;

    phase = cvCreateImage(cvSize( global_p[2]*2, 360), IPL_DEPTH_16U, 1);
    cvZero(phase);




    double sigma = 2;
    double sigma_2 = sigma*2;
    ///
    ////// \brief cont
    unsigned int cont = 0;
    int max_b =0;
    double delta_x = sigma*2;
    double delta_y = 0;
    int point_x0 = 0;
    int point_y0 = 0;
    int end_point_x0 = 0;
    int end_point_y0 = 0;
    double sigma_xy = 0;

    ////     |
    ///// _1_|_3_
    ///   _4_|_2_
    ///      |

    gettimeofday(&tv0,0); //Получаем текущее время

    struct timeval tv_n = tv0 ;
    fout << tv0.tv_sec<< " "<< tv0.tv_usec << std::endl;



        for(int y = 0; y < bin->height; y ++)
        {
            if (cont>350) break;

            uchar* ptrG = (uchar*) (bin->imageData + y * bin->widthStep);
            uchar* ptr2 = (uchar*) (bin2->imageData + y * bin2->widthStep);

            for(int x=0; x < bin->width; x++)
            {

                double delta_x = sigma_2;
                double delta_y = 0;
                float sigma_xy = sigma_2;


                if ((ptrG[x]>0)&&(rand() % 5)==1) //1 из 15

                {
                    ptr2[x] = 0xFFFFFFFF;
                    cont++;// это пиксель контура?

                  /* while(1)//включить если надо рассматривать по одной точки
                    {
                        if (cvWaitKey(0) == 'e' )
                        {
                            cvDestroyAllWindows();
                            cvShowImage("phase",phase);
                            cvShowImage("bin2",bin2);
                            break;

                        }

                    }
                    */



/*
                    // рассмотрим все возможные окружности, которые могут
                    // проходить через эту точку
                    int cont_fi = 0;
                    for(int fi = 0; fi < phase -> height; fi++)

                    { //перебираем все возможные t-до радиус вектора
                        short* ptrP = (short*) (phase->imageData + fi * phase->widthStep);

                        for(int b = 0; b < phase->width; b ++)
                        {


                            if ((b==(phase->width -1))&&(max_b!=0))
                            {
                                ptrP[max_b] ++;
                                cont_fi ++;
                                max_b = 0;
                                delta_x = sigma_2;
                                delta_y = sigma;
                                if (cont_fi>180) break;
                            }

                           for(int t=0 ; t < phase -> height/2; t=t+5 )
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

                                 double sigma_xy =
                                        fabs
                                        (
                                            m_sqrt_2*
                                            (
                                                global_p[2]*m_cos[fi+45]*m_cos[t]
                                            + b*m_sin[fi+45]*m_sin[t]
                                            )
                                        - (bin->width/2-y) - (bin->width/2-x)

                                        );

                           // Если решение уравнения достаточно хорошее
                                 if (
                                       (sigma_x < sigma)
                                     &&
                                   (sigma_y < sigma)
                                 )
                                /*if (sigma_xy < delta_x)
                                {
                                    max_b = b;
                                    delta_x = sigma_xy;
                                }


                                    {
                                        max_b = b;
                                        //delta_x = (sigma_x) + (sigma_y) ;
                                        //if (delta_x < sigma)
                                        break;
                                       // delta_y =sigma_y- sigma;
                                        //break;

                                    }



                            }

                        }
                    }

                }
                //break;

            }
        }

*/



