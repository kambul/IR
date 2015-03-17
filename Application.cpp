

void Application::init()
{
   BridgeTransmitter *bridgeTrasmitter = new BridgeTransmitter();
   bridgeTrasmitter->init( "10.218.35.143", 6667 );

   this.algo        = new SpherePositionAlgo();
   this.grabber     = new FrameGrabber();
   this.transmitter = bridgeTransmitter;
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
   grabber->setResultCallback( null );
   grabber->stop();
}

