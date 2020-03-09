#include "client.hpp"


#include <iostream>
#include <cassert>

Client::Client() noexcept
{
    m_ipv4 = new SocketAddress("127.0.0.1:8000");
    m_clientSocket = new StreamSocket(*m_ipv4);
    
    std::string s("Give me some information");
    m_buffer = s.c_str();
    m_clientSocket->sendBytes(m_buffer, sizeof(s));


    /* int k = m_clientSocket->receiveBytes(m_buffer,50);
    std::cout << "Buffer " << k << " " << (std::string)m_buffer << std::endl;*/
    
}

Client::~Client() noexcept
{
    assert(nullptr != m_clientSocket);
    m_clientSocket->close();
}
