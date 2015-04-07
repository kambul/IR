#ifndef ITRANSMITTER_H
#define ITRANSMITTER_H
#include "algo/ISpherePositionResultCallback.h"

class ITransmitter :public ISpherePositionResultCallback
{
public:
   virtual void start() = 0;
   virtual void stop() = 0;
};

#endif
