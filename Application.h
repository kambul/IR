
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
}