#ifndef SPHEREPOSITIONALGO_H
#define SPHEREPOSITIONALGO_H

#include "grabber/ICameraGrabberResultCallback.h"
#include "algo/ISpherePositionResultCallback.h"
#include "algo/SixData.h"

class SpherePositionAlgo : public ICameraGrabberResultCallback
{
   public:
      void setFormat( int width, int height );
      virtual void getFrame( char *frame );
      void setResultCallback( SpherePositionResultCallback callback );

   private:
      SpherePositionResultCallback callback;

};

#endif
