#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/SocketAddress.h"

using SocketAddress = Poco::Net::SocketAddress;
using ServerSocket = Poco::Net::ServerSocket;
using StreamSocket = Poco::Net::StreamSocket;

class Server {
private:
    SocketAddress* m_ipv4;
    ServerSocket* m_serverSocket;
    
public:
    Server();
    ~Server();
};

#endif // SERVER_HPP
