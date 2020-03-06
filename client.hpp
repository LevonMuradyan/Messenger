#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/SocketStream.h"

using SocketAddress = Poco::Net::SocketAddress;
using StreamSocket = Poco::Net::StreamSocket;
using SocketStream = Poco::Net::SocketStream;
using SocketStreamBuf = Poco::Net::SocketStreamBuf;

class Client {
private:
     SocketAddress* m_ipv4;
     StreamSocket* m_clientSocket;
     SocketStreamBuf* m_stream;
public:
    Client();
    ~Client();    

};

#endif // CLIENT_HPP
