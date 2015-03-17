#include "SpherePositionAlgo.h"

void SpherePositionAlgo::setResultCallback( SpherePositionCallback callback )
{
   this.callback = callback;
}


void SpherePositionAlgo::getFrame( char *frame )
{

   // Processing Frame

   SixData sixData;

   // Fill SixData

   SpherePositionAlgoResult result;

   result.sixData = sixData;
   result.sucess  = true;

   callback.getResult( result );
}
