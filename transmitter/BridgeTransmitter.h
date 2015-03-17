#ifndef BRIDGETRANSMISTER_H
#define BRIDGETRANSMISTER_H

#include "transmitter/ITransmitter.h"

class BridgeTransmitter : ITransmitter
{
public:
   void init( string domain, int port );

   void getResult( SpherePositionAlgoResult result );

private:
   string domain;
   int port;

};

#endif
