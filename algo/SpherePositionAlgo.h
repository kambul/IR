#ifndef SPHEREPOSITIONALGO_H
#define SPHEREPOSITIONALGO_H

#include "grabber/ICameraGrabberResultCallback.h"
#include "algo/ISpherePositionResultCallback.h"
#include "algo/SixData.h"
#include "FfindColor.h"
#include "findobject.h"
#include "FindEllipse.h"


#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "algo/SixData.h"

class SpherePositionAlgo : public ICameraGrabberResultCallback
{
   public:

      void setFormat( int width, int height );
      virtual void getFrame ( char *frame ) ;
      void setResultCallback( ISpherePositionResultCallback *callback );
      SixData *m_sixdata;


   private:
      CFindObject m_findobject;
      CFindColor m_findcolor;
      CFindEllipse m_findellipse;

      ISpherePositionResultCallback *callback;


};

#endif
