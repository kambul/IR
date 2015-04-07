
#include "Application.h"
#include "transmitter/BridgeTransmitter.h"
#include "grabber/CameraGrabber.h"
#include "string.h"

void Application::init()
{
   string host = "192.168.1.104";
   BridgeTransmitter *bridgeTransmitter = new BridgeTransmitter();
   bridgeTransmitter->init( host, 6667 );

   this->algo        = new SpherePositionAlgo();
   this->grabber     = new CameraGrabber();
   this->transmitter = bridgeTransmitter;
}

void Application::start()
{
   grabber->setResultCallback( algo       );
   algo   ->setResultCallback( transmitter );


   transmitter->start();
   grabber    ->start();

   algo->getFrame("gg");
}

void Application::stop()
{
   //grabber->setResultCallback(  );
   grabber->stop();
}

