
void BridgeTransmitter::init( string domain, int port )
{
   this.domain = domain;
   this.port   = port;
}

void BridgeTransmitter::start()
{
   // Set TCP\IP conntection to domain, port
}

void BridgeTransmitter::stop()
{
   // Terminate TCP/IP connection
}


void BridgeTransmitter::getResult( SpherePositionAlgoResult result )
{
   // сериализуем result.sixData
}
