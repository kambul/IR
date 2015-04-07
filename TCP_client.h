#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

/**
    C++ client example using sockets
*/
#include<iostream>    //cout
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<string>  //string
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include<netdb.h> //hostent

using namespace std;

/**
    TCP Client class
*/
class TCP_client
{
    public:
        TCP_client();
        virtual ~TCP_client();
        bool conn(string, int);
        bool send_data(string data);
        bool send_comm(string data);
        string receive(int);
    protected:
    private:
        int sock;
        std::string address;
        int port;
        struct sockaddr_in server;
};

#endif // TCP_CLIENT_H
