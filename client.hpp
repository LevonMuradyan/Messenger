#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketAddress.h"

using SocketAddress = Poco::Net::SocketAddress;
using StreamSocket = Poco::Net::StreamSocket;

class Client {
private:
    SocketAddress* m_ipv4;
    StreamSocket* m_clientSocket;
    const char* m_buffer;
public:
    Client();
    ~Client();    

};

#endif // CLIENT_HPP
