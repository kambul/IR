#include "transmitter/BridgeTransmitter.h"
#include <vector>

string down = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"10\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[-10, -10]}}";

string up = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"10\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[10, 10]}}";

string foward = "{\"header\":{\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"15\",\"timestamp\" : \"1428419652361\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"vs\":[-15,15]}}";
string back = "{\"header\":{\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"15\",\"timestamp\" : \"1428419652361\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"vs\":[15,-15]}}";
string g_neck[3][3][3][3];
//string r = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"10\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[10, -10]}}";
//string l = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"10\",\"timestamp\" : \"0\",\"correlationID\" : \"\",\"bodyType\" : \"map\"}, \"properties\": [],\"body\":{\"vs\":[10, -10]}}";
string razl ="{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"34\",\"timestamp\" : \"1428424966693\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_state\":1}}";
 void make()
 {
     g_neck[0][0][0][0] = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,0,0],\"speed\":[0,0,0,0]}}";
     g_neck[0][0][0][1] = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,0,1],\"speed\":[0,0,0,25]}}";
     g_neck[0][0][0][2] = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,0,-1],\"speed\":[0,0,0,25]}}";
     g_neck[0][0][1][0] = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,1,0],\"speed\":[0,0,25,0]}}";
     g_neck[0][0][2][0] = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,-1,0],\"speed\":[0,0,25,0]}}";
     g_neck[0][0][1][1] = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,1,1],\"speed\":[0,0,25,25]}}";
     g_neck[0][0][2][2] = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,-1,-1],\"speed\":[0,0,25,25]}}";
     g_neck[0][0][2][1] = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,-1,1],\"speed\":[0,0,25,25]}}";
     g_neck[0][0][2][0] = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,-1,0],\"speed\":[0,0,25,0]}}";
     g_neck[0][0][1][2] = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,1,-1],\"speed\":[0,0,25,25]}}";

 }
     string neck3_1 = "{\"header\": {\"destination\" : \"body\",\"expiration\" : \"0\",\"messageID\" : \"25\",\"timestamp\" : \"1430844326631\",\"correlationID\" : \"\",\"bodyType\" : \"map\"},\"properties\": [],\"body\":{\"neck_dir_controll\":[0,0,-1,0],\"speed\":[0,0,25,0]}}";


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
    make();

     if (((result.data.y ) < 100) && (result.data.y !=0))
     {
     c.send_comm(razl);
     }

     if (((result.data.y ) > 360) && (result.data.y !=0))
     {
     c.send_comm(slogit);

     }

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

     int neck[4] = {0,0,0,0};
     if ( ((result.data.m_angl1 % 90) < 80) && ((result.data.m_angl1 % 90) > 50) )
     {
         //c.send_comm(neck4);
         neck[3] = 2;
         std ::cout << "down" << std::endl;

     }
     if ( ((result.data.m_angl1 % 90) > 10) && ((result.data.m_angl1 % 90) < 40) )
     {
          //c.send_comm(neck4_1);
           neck[3] = 1;
           std ::cout << "up" << std::endl;
     }

     /*if ( ((result.data.m_angl1 % 90) > 0) && ((result.data.m_angl1 % 90) < 45) )
*/
     if(result.data.m_a1!=0)
     {
         float temp_res = (float) (result.data.m_b1) /(float)(result.data.m_a1) ;
         std::cout << "b1/R= "<< temp_res  << std::endl;

         if  ((temp_res > 0.4) && (temp_res < 0.69))
         {

            // c.send_comm(neck3);
              neck[2] = 1;
         }
         if  ((temp_res < -0.4) && (temp_res > -0.69))
         {

             //c.send_comm(neck3_1);
              neck[2] = 2;
         }
     }
     c.send_comm(g_neck[neck[0]][neck[1]][neck[2]][neck[3]]);



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




