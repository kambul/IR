#ifndef ITRANSMITTER_H
#define ITRANSMITTER_H
#include "algo/ISpherePositionResultCallback.h"
class ITransmitter : SpherePositionResultCallback
{
   virtual void start();
   virtual void stop();
};

#endif
