#ifndef ITRANSMITTER_H
#define ITRANSMITTER_H
#include "algo/ISpherePositionResultCallback.h"
class ITransmitter :public SpherePositionResultCallback
{
public:
   virtual void start();
   virtual void stop();
};

#endif
