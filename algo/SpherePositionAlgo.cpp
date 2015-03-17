#include "SpherePositionAlgo.h"
#include "algo/ISpherePositionResultCallback.h"

void SpherePositionAlgo::setResultCallback( SpherePositionResultCallback callback )
{
   this->callback = callback;
}


void SpherePositionAlgo::getFrame( char *frame )
{

   // Processing Frame

   SixData sixData;

   // Fill SixData

   SpherePositionAlgoResult result;

   result.data = sixData;
   result.success  = true;

   callback.getResult(result);
}
