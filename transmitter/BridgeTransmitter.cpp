#include "transmitter/BridgeTransmitter.h"

string down = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"10\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[-10, -10]}}";

string up = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"10\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[10, 10]}}";

string foward = "{\"header\":{\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"15\",\"timestamp\" : \"1428419652361\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"vs\":[-15,15]}}";
string back = "{\"header\":{\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"15\",\"timestamp\" : \"1428419652361\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"vs\":[15,-15]}}";

//string r = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"10\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[10, -10]}}";
//string l = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"10\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[10, -10]}}";
string razl ="{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"34\",\"timestamp\" : \"1428424966693\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_state\":1}}";

string slogit ="{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"34\",\"timestamp\" : \"1428424966693\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_state\":0}}";
string neck4 = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,0,1],\"speed\":[0,0,0,25]}}";
string neck4_1 = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,0,-1],\"speed\":[0,0,0,25]}}";

string stopp =  "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"81\",\"timestamp\" : \"1430846172771\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"stop\":1}}";
// "{\"header\":{\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"34\",\"timestamp\" : \"1428424966693\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_state\":0}};

char *data_c = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"28\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[-10, 10]}}";

using namespace std;

void BridgeTransmitter::init(string domain, int port )
{
   this->domain = domain;
   this->port   = port;
}

void BridgeTransmitter::start()
{
 c.conn(domain , port);
}

void BridgeTransmitter::stop()
{
   // Terminate TCP/IP connection
}


void BridgeTransmitter::getResult( SpherePositionAlgoResult result )
{
/*
     if (((result.data.y ) < 120) && (result.data.y !=0))
     {
     c.send_comm(r);
     }

     if (((result.data.y ) > 360) && (result.data.y !=0))
     {
     c.send_comm(l);

     }
 */
     if (result.data.m_a1  > 120)
     {
     c.send_comm(foward);
     }

     if ((result.data.m_a1  <85) && (result.data.m_a1  > 10) )
     {
     c.send_comm(back);
     }


     if (((result.data.x ) < 100) && (result.data.x !=0))
     {
     c.send_comm(up);
     }

     if (((result.data.x ) > 500) && (result.data.x !=0))
     {
     c.send_comm(down);
     }

     // c.send_comm(up);
   // c.send_comm(stopp);


      //c.send_comm(slogit);
     c.send_comm(stopp);
     std ::cout << "\n" << "angl = " << result.data.m_angl1 % 90 << std::endl;

     if ( ((result.data.m_angl1 % 90) < 80) && ((result.data.m_angl1 % 90) > 50) )
     {
         c.send_comm(neck4);

         std ::cout << "down" << std::endl;

     }
     if ( ((result.data.m_angl1 % 90) > 10) && ((result.data.m_angl1 % 90) < 40) )
     {
          c.send_comm(neck4_1);

           std ::cout << "up" << std::endl;
     }

     /*if ( ((result.data.m_angl1 % 90) > 0) && ((result.data.m_angl1 % 90) < 45) )
     {
        if  ((result.data.m_b1 / result.data.m_a1) > 0.6)
        {
        std::cout << "b1/R= "<< (result.data.m_b1 / result.data.m_a1) << std::endl;
        c.send_comm(neck3);
        }
     }



/*
     if ( ((result.data.m_angl1 >50 ) && (result.data.m_angl1  <80))|| ((result.data.m_angl1  >225 ) && (result.data.m_angl1  <269)) )
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

*/
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




