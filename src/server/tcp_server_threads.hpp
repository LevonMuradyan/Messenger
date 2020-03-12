/*
#include "Poco/Net/TCPServer.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/TCPServerConnectionFactory.h"
#include "server.hpp"


using SocketAddress = Poco::Net::SocketAddress;
using ServerSocket = Poco::Net::ServerSocket;
using TCPServer = Poco::Net::TCPServer;
using SocketAddress = Poco::Net::SocketAddress;

class tcp_server_threads {
    using std::cout;
    TCPServerConnectionFactory::Ptr m_factory;
    Server* m_server;
    TCPServer* m_server_threads;
public:
    tcp_server_threads(); noexcept
    tcp_server_threads(const &tcp_server_threads& other) = delete;
    ~tcp_server_threads();
    tcp_server_start(); noexcept
};
*/