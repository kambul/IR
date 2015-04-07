#ifndef CDATAANALYSIS_H
#define CDATAANALYSIS_H
#include "algo/SpherePositionAlgoResult.h"

class ISpherePositionResultCallback
{
public:
   virtual void getResult( SpherePositionAlgoResult result ) = 0;
};

#endif
