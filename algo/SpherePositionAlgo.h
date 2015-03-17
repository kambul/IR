#ifndef SPHEREPOSITIONALGO_H
#define SPHEREPOSITIONALGO_H

#include "grabber/ICameraGrabberResultCallback.h"

class SpherePositionAlgo : public ICameraGrabberResultCallback
{
   public:
      void setFormat( int width, int height );
      void getFrame( char *frame );

      void setResultCallback( ISpherePositionCallback callback );

   private:
      SpherePositionResultCallback callback;
};

#endif
