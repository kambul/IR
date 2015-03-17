#indef APLICATION_H
#define APLICATION_H

class Application
{

public:
   void init();

   void start();
   void stop();

private:
   SpherePositionAlgo *algo;
   FrameGrabber       *grabber;
   ITransmitter       *transmitter;
};

#endif
