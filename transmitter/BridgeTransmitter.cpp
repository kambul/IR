#include "transmitter/BridgeTransmitter.h"

string down = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"10\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[-10, -10]}}";

string up = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"10\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[10, 10]}}";

string r = "{\"header\":{\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"15\",\"timestamp\" : \"1428419652361\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"vs\":[-5,5]}}";
string l = "{\"header\":{\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"15\",\"timestamp\" : \"1428419652361\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"vs\":[5,-5]}}";
//string r = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"10\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[10, -10]}}";
//string l = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"10\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[10, -10]}}";
string razl ="{\"header\":{\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"34\",\"timestamp\" : \"1428424966693\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_state\":1}}";
string slogit = "{\"header\":{\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"34\",\"timestamp\" : \"1428424966693\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_state\":0}}";
char *data_c = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"28\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[-10, 10]}}";

using namespace std;

void BridgeTransmitter::init(string domain, int port )
{
   this->domain = domain;
   this->port   = port;
}

void BridgeTransmitter::start()
{
 c.conn(domain , 6664);
}

void BridgeTransmitter::stop()
{
   // Terminate TCP/IP connection
}


void BridgeTransmitter::getResult( SpherePositionAlgoResult result )
{
     if (((result.data.y ) < 180) && (result.data.y !=0))
     {
     c.send_comm(l);
     }

     if (((result.data.y ) > 300) && (result.data.y !=0))
     {
     c.send_comm(r);
     }

     if (((result.data.x ) < 260) && (result.data.x !=0))
     {
     c.send_comm(down);
     }

     if (((result.data.x ) > 380) && (result.data.x !=0))
     {
     c.send_comm(up);
     }


     if ( ((result.data.m_angl1 >45 ) && (result.data.m_angl1  <90))|| ((result.data.m_angl1  >225 ) && (result.data.m_angl1  <269)) )
     {
         c.send_comm(razl);
     }

     if ( ((result.data.m_angl1 >45 ) && (result.data.m_angl1  <90))|| ((result.data.m_angl1  >225 ) && (result.data.m_angl1  <269)) )
     {
         c.send_comm(razl);
     }

     if ( (result.data.m_angl1  >0 ) && (result.data.m_angl1  <45) || ((result.data.m_angl1  >135 ) && (result.data.m_angl1  <225)) )
     {
       c.send_comm(slogit);
     }
     if ( (result.data.m_angl1  >0 ) && (result.data.m_angl1  <45) || ((result.data.m_angl1  >135 ) && (result.data.m_angl1  <225)) )
     {
        c.send_comm(slogit);
     }


     /*if (((result.data.m_b1 ) > 30) )
     {
     c.send_comm(razl);
     }

     if (((result.data.m_b1 ) < -30) )
     {
     c.send_comm(slogit);
     }
*/

}




