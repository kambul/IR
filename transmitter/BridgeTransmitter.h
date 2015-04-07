#ifndef BRIDGETRANSMISTER_H
#define BRIDGETRANSMISTER_H

#include "transmitter/ITransmitter.h"
#include "TCP_client.h"
#include "string.h"




class BridgeTransmitter : public ITransmitter
{
public:
   void init(string  domain, int port );
   void getResult( SpherePositionAlgoResult result );
   virtual void start();
   virtual void stop();

private:
   string domain;
   int port;
   TCP_client c;

};

#endif
