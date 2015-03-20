
#include "Application.h"
#include "transmitter/BridgeTransmitter.h"
#include "grabber/CameraGrabber.h"
void Application::init()
{
   BridgeTransmitter *bridgeTransmitter = new BridgeTransmitter();
   bridgeTransmitter->init( "10.218.35.143", 6667 );

   this->algo        = new SpherePositionAlgo();
   this->grabber     = new CameraGrabber();
   this->transmitter = bridgeTransmitter;
}

void Application::start()
{
   grabber->setResultCallback( algo        );
   algo   ->setResultCallback( transmitter );

   transmitter->start();
   grabber    ->start();
}

void Application::stop()
{
   grabber->setResultCallback(  );
   grabber->stop();
}

