#ifndef APLICATION_H
#define APLICATION_H
#include "algo/SpherePositionAlgo.h"
#include "grabber/CameraGrabber.h"
#include "transmitter/ITransmitter.h"

class Application
{

public:
   void init();

   void start();
   void stop();


   SpherePositionAlgo *algo;
   CameraGrabber       *grabber;
   ITransmitter       *transmitter;
};

#endif
