#ifndef CDATAANALYSIS_H
#define CDATAANALYSIS_H
#include "algo/SpherePositionAlgoResult.h"

class SpherePositionResultCallback
{
public:
   virtual void getResult( SpherePositionAlgoResult result );
};

#endif
