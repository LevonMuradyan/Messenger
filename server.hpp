#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/SocketStream.h"
#define SIZE 50

using SocketAddress = Poco::Net::SocketAddress;
using ServerSocket = Poco::Net::ServerSocket;
using SocketStream = Poco::Net::SocketStream; 
using StreamSocket = Poco::Net::StreamSocket;
using SocketStreamBuf = Poco::Net::SocketStreamBuf; 
class Server {
private:
    SocketAddress* m_ipv4;
    ServerSocket* m_serverSocket;
    SocketStreamBuf* m_stream;
    char* m_buffer;
    
public:
    Server();
    ~Server();
};

#endif // SERVER_HPP
