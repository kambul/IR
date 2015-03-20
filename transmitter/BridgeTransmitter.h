#ifndef BRIDGETRANSMISTER_H
#define BRIDGETRANSMISTER_H

#include "transmitter/ITransmitter.h"


class BridgeTransmitter :public ITransmitter
{
public:
   void init(char*  domain, int port );

   void getResult( SpherePositionAlgoResult result );
   void start();
   void stop();

private:
   char* domain;
   int port;

};

#endif
